/*
Tree optimizer prototype and test code.
Based on code gathered from myself, ublas, blaze, eigen.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <boost/type_traits.hpp>

using namespace boost;

typedef double value_type; // simplifying things with the templates

// this is for the type_traits
class Base_Base { };

template< bool Select    // Compile time selection
, typename T1    // Type to be selected if Select=true
, typename T2 >  // Type to be selected if Select=false
struct SelectType {
public:
    typedef T1  Type;
};

template< typename T1    // Type not to be selected
, typename T2 >  // Type to be selected
struct SelectType<false, T1, T2>{
public:
    typedef T2  Type;
};

template< typename T >
struct IsExpressionHelper {
    
    enum { value = is_base_of<Base_Base, T>::value && !is_base_of<T, Base_Base>::value };
    typedef typename SelectType<value, true_type, false_type>::Type  Type;
    
};

template< typename T >
struct is_expression : public IsExpressionHelper<T>::Type {
public:
    
    enum { value = IsExpressionHelper<T>::value };
    typedef typename IsExpressionHelper<T>::Type  Type;
    
};

template< typename T >
struct IsTemporaryHelper{
    enum { value = !is_reference<T>::value && !is_floating_point<T>::value && !is_expression<T>::value };
    typedef typename SelectType<value, true_type, false_type>::Type  Type;
};

template< typename T >
struct is_temporary : public IsTemporaryHelper<T>::Type {
public:
    enum { value = IsTemporaryHelper<T>::value };
    typedef typename IsTemporaryHelper<T>::Type  Type;
};

template< typename T >
struct RequiresEvaluationHelper {
    enum { value = !is_reference<typename T::Nested>::value };
    typedef typename SelectType<value, true_type, false_type>::Type  Type;
};

template< typename T >
struct requires_evaluation : public RequiresEvaluationHelper<T>::Type
{
public:
    enum { value = RequiresEvaluationHelper<T>::value };
    typedef typename RequiresEvaluationHelper<T>::Type  Type;
};


//Base class.
template <typename MatXpr>
class Matrix_Base : public Base_Base {
  
public:

	Matrix_Base() {}
	~Matrix_Base() {}
/*
	//some useful operators and functions for this template pattern
	value_type operator()(size_t i, size_t j) const {
  		return static_cast<const MatXpr&>(*this)(i, j); 
  	}

    size_t size1() const { return (*this).size1(); }
    
    size_t size2() const { return (*this).size2(); }
*/
  	operator MatXpr&() {
  		return static_cast<MatXpr&>(*this);
  	}

  	operator const MatXpr&() const {
  		return static_cast<const MatXpr&>(*this); 
  	}

};

//Dense matrix class that extends the base class
template <size_t rows = 2, size_t cols = 2>
class Dense_Matrix : public Matrix_Base< Dense_Matrix<rows, cols> > {
    
public:
    
    // typedef type value_type;
    typedef typename std::vector< std::vector<value_type> > storage_type;
    typedef const Dense_Matrix& Nested;
    
    enum traits {
        RowsAtCompileTimeL = rows, //yeah this is dumb but I don't have time to worry about a proper traits class right now
        ColsAtCompileTimeL = cols,
        RowsAtCompileTimeR = rows,
        ColsAtCompileTimeR = cols,
        op_cost = 0,
        temp_test = false
    };
    
    Dense_Matrix(const std::string& name) : m_name(name) {
        std::vector<value_type> row(cols);
        data.resize(rows, row);
        rand_init();
        std::cout << "- Create matrix " << m_name << std::endl;
    }

    template <typename MatXpr>
    Dense_Matrix(const Matrix_Base<MatXpr>& mexpr) : m_name(mexpr.m_name) { // Construct from a matrix_expression
        for(size_t i = 0; i < mexpr.size1(); ++i) {
            for(size_t j = 0; j < mexpr.size2(); ++j){
                data[i][j] = mexpr(i,j);
            }
        }
    }

    ~Dense_Matrix() {}
    
    std::string name() const { return m_name; } //just the name
    
    constexpr size_t size1() const { return rows; }
    
    constexpr size_t size2() const { return cols; }
    
    const value_type& operator()(size_t i, size_t j) const {
        return data[i][j];
    }
    
    value_type& operator()(size_t i, size_t j) {
        return data[i][j];
    }
    
    template <typename T>
    Dense_Matrix& operator=(const T& right){
        for(size_t i = 0; i < size1(); ++i){
            for(size_t j = 0; j < size1(); ++j){
                data[i][j] = right(i, j);
            }
        }
        return *this;
    }
    
    void rand_init() {
        srand(time(NULL)); //we're going to randomly generate the matrices
        for(size_t i = 0; i < size1(); ++i){
            for(size_t j = 0; j < size2(); ++j){
                data[i][j] = rand() % 100;
            }
        }
    } 

private:
    std::string m_name;
    storage_type data;
    
};

typedef Dense_Matrix<4, 1> Vector4d;
typedef Dense_Matrix<4, 4> Matrix4d;

//Represents the matrix sum.
template <typename MatrixL, typename MatrixR >
class Matrix_Sum : public Matrix_Base< Matrix_Sum<MatrixL, MatrixR> > {
    
public:
    
    //typedef typename MatrixL::value_type value_type;
    typedef const Matrix_Sum Nested; //these are needed for the tree optimizer object

    enum traits {
        RowsAtCompileTimeL = MatrixL::traits::RowsAtCompileTimeL,
        ColsAtCompileTimeL = MatrixL::traits::ColsAtCompileTimeL,
        RowsAtCompileTimeR = MatrixR::traits::RowsAtCompileTimeR,
        ColsAtCompileTimeR = MatrixR::traits::ColsAtCompileTimeR,
        op_cost = RowsAtCompileTimeL * ColsAtCompileTimeL, //sizes must be compatible
        temp_test = !is_temporary<MatrixL>::value && !is_temporary<MatrixR>::value
    };
 
    Matrix_Sum(const Matrix_Base<MatrixL>& ml, const Matrix_Base<MatrixR>& mr) : matrixl(ml), matrixr(mr) {}
    
    ~Matrix_Sum() {}
    
	std::string name() const { return std::string("(") + matrixl.name() + " + " + matrixr.name() + ")"; }
	
    value_type operator()(size_t i, size_t j) const {
      	return matrixl(i, j) + matrixr(i, j);
    }
    
    typename MatrixL::Nested matrixl;
    typename MatrixR::Nested matrixr;
    
};


//Represents the matrix difference.
template <typename MatrixL, typename MatrixR>
class Matrix_Difference : public Matrix_Base< Matrix_Difference<MatrixL, MatrixR> > {
    
public:
    
    //typedef typename MatrixL::value_type value_type;
    typedef const Matrix_Difference Nested; //these are needed for the tree optimizer object
 
    enum traits {
        RowsAtCompileTimeL = MatrixL::traits::RowsAtCompileTimeL,
        ColsAtCompileTimeL = MatrixL::traits::ColsAtCompileTimeL,
        RowsAtCompileTimeR = MatrixR::traits::RowsAtCompileTimeR,
        ColsAtCompileTimeR = MatrixR::traits::ColsAtCompileTimeR,
        op_cost = RowsAtCompileTimeL * ColsAtCompileTimeL, //sizes must be compatible
        temp_test = !is_temporary<MatrixL>::value && !is_temporary<MatrixR>::value
    };
 
	Matrix_Difference(const Matrix_Base<MatrixL>& ml, const Matrix_Base<MatrixR>& mr) : matrixl(ml), matrixr(mr) {}
    
	~Matrix_Difference() {}
    
	std::string name() const { return std::string("(") + matrixl.name() + " + " + matrixr.name() + ")"; }
    
    value_type operator()(size_t i, size_t j) const {
      	return matrixl(i, j) - matrixr(i, j);
    }
    
    typename MatrixL::Nested matrixl;
    typename MatrixR::Nested matrixr;

};

//represents a matrix product
template <typename MatrixL, typename MatrixR>
class Matrix_Product : public Matrix_Base< Matrix_Product<MatrixL, MatrixR> > {
    
public:
    
    //typedef typename MatrixL::value_type value_type;
    typedef const Matrix_Product Nested;
 
    enum traits {
        RowsAtCompileTimeL = MatrixL::traits::RowsAtCompileTimeL,
        ColsAtCompileTimeL = MatrixL::traits::ColsAtCompileTimeL,
        RowsAtCompileTimeR = MatrixR::traits::RowsAtCompileTimeR,
        ColsAtCompileTimeR = MatrixR::traits::ColsAtCompileTimeR,
        op_cost = RowsAtCompileTimeL * ColsAtCompileTimeR * (2 * ColsAtCompileTimeL - 1),
        temp_test = !is_temporary<MatrixL>::value && !is_temporary<MatrixR>::value
    };
 
	Matrix_Product(const Matrix_Base<MatrixL>& ml, const Matrix_Base<MatrixR>& mr) : matrixl(ml), matrixr(mr) {}

	~Matrix_Product() {}

	std::string name() const { return std::string("(") + matrixl.name() + " * " + matrixr.name() + ")"; }

	// TO DO: implement the multiplication!
    
    typename MatrixL::Nested matrixl;
	typename MatrixR::Nested matrixr;
 
};

//useful operator overloads
template <typename MatrixL, typename MatrixR>
Matrix_Sum<MatrixL, MatrixR> operator+(const Matrix_Base<MatrixL>& ml, const Matrix_Base<MatrixR>& mr){
	return Matrix_Sum<MatrixL, MatrixR> (ml, mr);
}

template <typename MatrixL, typename MatrixR>
Matrix_Difference<MatrixL, MatrixR> operator-(const Matrix_Base<MatrixL>& ml, const Matrix_Base<MatrixR>& mr){
	return Matrix_Sum<MatrixL, MatrixR> (ml, mr);
}

template <typename MatrixL, typename MatrixR>
Matrix_Product<MatrixL, MatrixR> operator*(const Matrix_Base<MatrixL>& ml, const Matrix_Base<MatrixR>& mr){
	return Matrix_Product<MatrixL, MatrixR> (ml, mr);
} 


// Default tree optimizer that copies the expression by value
template<typename MatXpr>
class Tree_Optimizer {
public:
    
    enum {
        treechanges = 0
    };
    
    typedef MatXpr NMatXpr;
    
    static MatXpr build(const MatXpr& mxpr) { return mxpr; }
};

// Tree optimizer for Dense_Matrix that copies by reference
template<size_t rows, size_t cols>
class Tree_Optimizer< Dense_Matrix<rows, cols> > {
public:
    
    enum {
        treechanges = 0
    };
    
    typedef Dense_Matrix<rows, cols> NMatXpr;
    static const Dense_Matrix<rows, cols>& build(const Dense_Matrix<rows, cols>& mxpr) { return mxpr; }
};

// Needed to forward the optimizer to the children
template<typename A, typename B>
class Tree_Optimizer< Matrix_Sum<A, B> > {
public:
    
    enum {
        treechanges = 0,
        reA = requires_evaluation<A>::value,
        reB = requires_evaluation<B>::value,
        rvA = is_rvalue_reference<A>::value,
        rvB = is_rvalue_reference<B>::value
    };
    
    typedef Matrix_Sum<A, B> MatXpr;
    typedef typename Tree_Optimizer<A>::NMatXpr NMatA;
    typedef typename Tree_Optimizer<B>::NMatXpr NMatB;
    typedef Matrix_Sum<NMatA, NMatB> NMatXpr;
    
    static NMatXpr build(const MatXpr& mxpr) {
        return Tree_Optimizer<A>::build(mxpr.matrixl) + Tree_Optimizer<B>::build(mxpr.matrixr);
    }
};

// Needed to forward the optimizer to the children
template<typename A, typename B>
class Tree_Optimizer< Matrix_Product<A, B> > {
public:
    
    enum {
        treechanges = 0,
        reA = requires_evaluation<A>::value,
        reB = requires_evaluation<B>::value,
        rvA = is_rvalue_reference<A>::value,
        rvB = is_rvalue_reference<B>::value
    };
    
    typedef Matrix_Product<A, B> MatXpr;
    typedef typename Tree_Optimizer<A>::NMatXpr NMatA;
    typedef typename Tree_Optimizer<B>::NMatXpr NMatB;
    typedef Matrix_Product<NMatA, NMatB> NMatXpr;
    
    static NMatXpr build(const MatXpr& mxpr) {
        return Tree_Optimizer<A>::build(mxpr.matrixl) * Tree_Optimizer<B>::build(mxpr.matrixr);
    }
};

// catch A * B + C and builds C + A * B
template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Sum< Matrix_Product<A, B>, C> > {
public:
    
    enum {
        treechanges = 1,
        reA = requires_evaluation<A>::value,
        reB = requires_evaluation<B>::value,
        reC = requires_evaluation<C>::value,
        rvA = is_rvalue_reference<A>::value,
        rvB = is_rvalue_reference<B>::value,
        rvC = is_rvalue_reference<C>::value,
    };
    
    typedef Matrix_Sum<Matrix_Product<A, B>, C> MatXpr;
    typedef typename Tree_Optimizer<C>::NMatXpr NMatC;
    typedef Matrix_Sum<NMatC, Matrix_Product<A, B> > NMatXpr;
    
    static NMatXpr build(const MatXpr& mxpr) {
        return Tree_Optimizer<C>::build(mxpr.matrixr) + mxpr.matrixl;
    }
  
};

// catch C + A * B + D and builds (C + D) + (A * B)
template<typename A, typename B, typename C, typename D>
class Tree_Optimizer< Matrix_Sum< Matrix_Sum<C, Matrix_Product<A, B> >, D> > {
public:
    
    enum {
        treechanges = 1,
        reA = requires_evaluation<A>::value,
        reB = requires_evaluation<B>::value,
        reC = requires_evaluation<C>::value,
        reD = requires_evaluation<D>::value,
        rvA = is_rvalue_reference<A>::value,
        rvB = is_rvalue_reference<B>::value,
        rvC = is_rvalue_reference<C>::value,
        rvD = is_rvalue_reference<D>::value
    };
    
    typedef Matrix_Sum< Matrix_Sum<C, Matrix_Product<A,B> >, D> MatXpr;
    typedef typename Tree_Optimizer<C>::NMatXpr NMatC;
    typedef typename Tree_Optimizer<D>::NMatXpr NMatD;
    typedef Matrix_Sum< Matrix_Sum<NMatC, NMatD>, Matrix_Product<A,B> > NMatXpr;

    static NMatXpr build(const MatXpr& mxpr) {
        return Tree_Optimizer<C>::build(mxpr.matrixl.matrixl) + Tree_Optimizer<D>::build(mxpr.matrixr) + mxpr.matrixl.matrixr;
    }
};

// catch (A * B) + (C + D) and builds (C + D) + (A * B)
template<typename A, typename B, typename C, typename D>
class Tree_Optimizer< Matrix_Sum< Matrix_Product<A, B>, Matrix_Sum<C, D> > > {
public:
    
    enum {
        treechanges = 1,
        reA = requires_evaluation<A>::value,
        reB = requires_evaluation<B>::value,
        reC = requires_evaluation<C>::value,
        reD = requires_evaluation<D>::value,
        rvA = is_rvalue_reference<A>::value,
        rvB = is_rvalue_reference<B>::value,
        rvC = is_rvalue_reference<C>::value,
        rvD = is_rvalue_reference<D>::value
    };
    
    typedef Matrix_Sum< Matrix_Product<A, B>, Matrix_Sum<C, D> > MatXpr;
    typedef typename Tree_Optimizer<C>::NMatXpr NMatC;
    typedef typename Tree_Optimizer<D>::NMatXpr NMatD;
    typedef Matrix_Sum< Matrix_Sum<NMatC, NMatD>, Matrix_Product<A,B> > NMatXpr;
    
    static NMatXpr build(const MatXpr& mxpr) {
        return Tree_Optimizer<Matrix_Sum<C, D>>::build(mxpr.matrixr) + Tree_Optimizer<Matrix_Product<A, B>>::build(mxpr.matrixl);
    }
};

// catch (A * B) * C and builds
// A * (B * C) if C is a vector
// (A * B) * C if C is a matrix
template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Product< Matrix_Product<A, B>, C> > {
public:
    
    enum {
        treechanges = 1,
        reA = requires_evaluation<A>::value,
        reB = requires_evaluation<B>::value,
        reC = requires_evaluation<C>::value,
        rvA = is_rvalue_reference<A>::value,
        rvB = is_rvalue_reference<B>::value,
        rvC = is_rvalue_reference<C>::value
    };
    
    typedef Matrix_Product< Matrix_Product<A, B>, C> MatXpr;
    typedef typename Tree_Optimizer<C>::NMatXpr NMatC;
    typedef Matrix_Product< A, Matrix_Product<B, C> > NMatXpr;
    typedef Matrix_Product<B, C> NPMatXpr;

    template <typename c = C> //only way to get enable_if to work with member functions (ugh) return type is Matrix_Product< A, Matrix_Product<B, C> >
    static typename boost::enable_if<boost::is_same<c, Vector4d>, NMatXpr>::type build(const MatXpr& mxpr) {
        return Tree_Optimizer<A>::build(mxpr.matrixl.matrixl) * Tree_Optimizer<NPMatXpr>::build(NPMatXpr(mxpr.matrixl.matrixr, mxpr.matrixr));
    }
    
    template <typename c = C> //only way to get enable_if to work with member functions (ugh) return type is Matrix_Product< Matrix_Product<A, B>, C>
    static typename boost::enable_if<boost::is_same<c, Matrix4d>, MatXpr>::type build(const MatXpr& mxpr) {
        return Tree_Optimizer<Matrix_Product<A, B>>::build(mxpr.matrixl) * Tree_Optimizer<C>::build(mxpr.matrixr);
    }
 
};


int main(){

	Matrix4d A("A"), B("B"), C("C"), D("D");
    Vector4d a("a"), b("b"), c("c"), d("d");
    std::cout << "\n";
    
    auto xpr = A * B + C;

    typedef __typeof(xpr) Xpr;
    
    std::cout << "init version:";
    std::cout << " " << xpr.name() << "\n";
    std::cout << "cost " << xpr.op_cost << std::endl;

    auto xpr1 = Tree_Optimizer<Xpr>::build(xpr); std::cout << " tt1 " << Tree_Optimizer<Xpr>::tt1 << " tt2 " << Tree_Optimizer<Xpr>::tt2 << " \n \n";
    typedef __typeof(xpr1) Xpr1;
    std::cout << std::endl << "optimized version 1:";
    std::cout << " " << xpr1.name() << std::endl;
    std::cout << "cost " << xpr1.op_cost << std::endl;
//    std::cout << "change " << Tree_Optimizer<Xpr>::treechanges << std::endl << std::endl;

/*
    auto xpr2 = Tree_Optimizer<Xpr1>::build(xpr1);
    typedef __typeof(xpr2) Xpr2;
    std::cout << std::endl << "optimized version 2:";
    std::cout << " " << xpr2.name() << std::endl;
    std::cout << "cost " << xpr2.op_cost << std::endl;
 //   std::cout << "change " << Tree_Optimizer<Xpr1>::treechanges << std::endl << std::endl;

    auto xpr3 = Tree_Optimizer<Xpr2>::build(xpr2);
    typedef __typeof(xpr3) Xpr3;
    std::cout << std::endl << "optimized version 3:";
    std::cout << " " << xpr3.name() << std::endl;
    std::cout << "cost " << xpr3.op_cost << std::endl;
    std::cout << "change " << Tree_Optimizer<Xpr2>::treechanges << std::endl << std::endl;

*/
	return 0;
}