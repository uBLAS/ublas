/*
Tree optimizer prototype and test code.
Based on code gathered from myself, ublas, blaze, eigen.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#include <type_traits>
#include <boost/type_traits.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/replace_if.hpp>
#include <boost/mpl/greater.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/while.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/divides.hpp>
#include <boost/mpl/front.hpp>

/*#include "align.hpp"
#include "alignment_trait.hpp"
#include "aligned_array.hpp"*/

using namespace boost;

typedef double value_type; // simplifying things with the templates

// forward declarations
template <typename MatXpr>
class Matrix_Base;

template <typename MatXpr>
class Matrix_Expression;

template <size_t rows, size_t cols>
class Dense_Matrix;

template <typename MatrixL, typename MatrixR >
class Matrix_Sum;

template <typename MatrixL, typename MatrixR >
class Matrix_Difference;

template <typename MatrixL, typename MatrixR >
class Matrix_Product;

template<typename MatXpr>
class Tree_Optimizer;

template<size_t rows, size_t cols>
class Tree_Optimizer< Dense_Matrix<rows, cols> >;

template<typename A, typename B>
class Tree_Optimizer< Matrix_Sum<A, B> >;

template<typename A, typename B>
class Tree_Optimizer< Matrix_Product<A, B> >;

template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Sum< Matrix_Product<A, B>, C> >;

template<typename A, typename B, typename C, typename D>
class Tree_Optimizer< Matrix_Sum< Matrix_Sum<C, Matrix_Product<A, B> >, D> >;

template<typename A, typename B, typename C, typename D>
class Tree_Optimizer< Matrix_Sum< Matrix_Sum< Matrix_Product<A, B>, C>, D> >;

template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Product< Matrix_Product<A, B>, C> >;
// end foward declarations

// #include "static_matrix.hpp"

// this is for the type_traits
class Mat_Base { };
class Matrix_Container { };

template <bool Select, typename T1, typename T2>
struct select_type {
    typedef T1 type;
};

template <typename T1, typename T2>
struct select_type<false, T1, T2> {
    typedef T2 type;
};

template< typename T >
struct is_matrix_expression {
public:
    enum { value = is_base_of<Mat_Base, T>::value && !is_base_of<T, Mat_Base>::value };
    typedef typename select_type<value, true_type, false_type>::type  type;
};

template< typename T >
struct is_matrix_container {
public:
    enum { value = is_base_of<Matrix_Container, T>::value && !is_base_of<T, Matrix_Container>::value };
    typedef typename select_type<value, true_type, false_type>::type  type;
};

template< typename T >
struct is_temporary {
public:
    enum { value = !is_reference<T>::value && !is_floating_point<T>::value && !is_matrix_expression<T>::value };
    typedef typename select_type<value, true_type, false_type>::type  type;
};

template< typename T >
struct requires_evaluation {
public:
    enum { value = !is_reference<typename T::Nested>::value };
    typedef typename select_type<value, true_type, false_type>::type  type;
};

template <typename MatXpr>
class Matrix_Expression : public Mat_Base {
  
public:

	Matrix_Expression() {}
	~Matrix_Expression() {}

  	operator MatXpr&() {
  		return static_cast<MatXpr&>(*this);
  	}

  	operator const MatXpr&() const {
  		return static_cast<const MatXpr&>(*this); 
  	}

};

//Dense matrix class that extends the base class
template <size_t rows, size_t cols>
class Dense_Matrix : public Matrix_Container, public Matrix_Expression< Dense_Matrix<rows, cols> > {
    
public:
    
    // typedef type value_type;
    typedef typename std::vector< std::vector<value_type> > storage_type;
    typedef const Dense_Matrix& Nested;
    
    enum traits {
        RowsAtCompileTime = rows,
        ColsAtCompileTime = cols,
    };
    
    enum costs {
        Op_Cost_Total = 0,
    };
    
    Dense_Matrix(const std::string& name) : m_name(name), _rows(rows), _cols(cols) {
        std::vector<value_type> row(cols);
        _data.resize(rows, row);
        rand_init();
        std::cout << "- Create matrix " << m_name << std::endl;
    }

    Dense_Matrix(const Dense_Matrix<rows, cols>& mexpr) : _rows(rows), _cols(cols) { //sizes must be compatible
        for(size_t i = 0; i < mexpr.size1(); ++i) {
            for(size_t j = 0; j < mexpr.size2(); ++j){
                _data[i][j] = mexpr(i,j);
            }
        }
        
    }

    ~Dense_Matrix() {}
    
    inline std::string name() const { return m_name; } //just the name
    
    constexpr inline size_t size1() const { return _rows; }
    
    constexpr inline size_t size2() const { return _cols; }
    
    inline const value_type& operator()(size_t i, size_t j) const {
        return _data[i][j];
    }
    
    inline value_type& operator()(size_t i, size_t j) {
        return _data[i][j];
    }
    
    template <typename T>
    Dense_Matrix& operator=(const T& right){
        
        for(size_t i = 0; i < size1(); ++i){
            for(size_t j = 0; j < size2(); ++j){
                _data[i][j] = right(i, j);
            }
        }
        
        return *this;
    }
    
    void rand_init() {
        srand(time(NULL)); // randomly generate the matrices
        for(size_t i = 0; i < size1(); ++i){
            for(size_t j = 0; j < size2(); ++j){
                _data[i][j] = rand() % 100;
            }
        }
    } 

private:
    std::string m_name;
    size_t _rows, _cols;
    storage_type _data;
    
};

typedef Dense_Matrix<4, 1> Vector4d;
typedef Dense_Matrix<4, 4> Matrix4d;

//Represents the matrix sum.
template <typename MatrixL, typename MatrixR >
class Matrix_Sum : public Matrix_Expression< Matrix_Sum<MatrixL, MatrixR> > {
    
public:
    
    //typedef typename MatrixL::value_type value_type;
    typedef const Matrix_Sum Nested; //these are needed for the tree optimizer object

    enum traits {
        // sizes of the matrices on each side of operation
        RowsAtCompileTimeL = MatrixL::traits::RowsAtCompileTime,
        ColsAtCompileTimeL = MatrixL::traits::ColsAtCompileTime,
        RowsAtCompileTimeR = MatrixR::traits::RowsAtCompileTime,
        ColsAtCompileTimeR = MatrixR::traits::ColsAtCompileTime,
        // this is the resulting size of the expression, matrix sum operation so sizes are compatible
        RowsAtCompileTime = RowsAtCompileTimeL,
        ColsAtCompileTime = ColsAtCompileTimeL,
        IsContainerL = is_matrix_container<MatrixL>::value || !requires_evaluation<MatrixL>::value, // container or doesn't require evaluation
        IsContainerR = is_matrix_container<MatrixR>::value || !requires_evaluation<MatrixR>::value,

    };
    
    enum costs {
        Temp_Cost = 1,
        Op_CostL = IsContainerL == 1 ? 0 : MatrixL::costs::Op_Cost_Total,
        Op_CostR = IsContainerR == 1 ? Temp_Cost : MatrixR::costs::Op_Cost_Total, //because we're doing like A*B+C instead of C+A*B we incur a temporary cost
        Op_Cost = RowsAtCompileTime * ColsAtCompileTime,
        Op_Cost_Total = Op_Cost + Op_CostL + Op_CostR,
    };
 
    Matrix_Sum(const Matrix_Expression<MatrixL>& ml, const Matrix_Expression<MatrixR>& mr) : matrixl(ml), matrixr(mr), m_name(name()) {}
    
    ~Matrix_Sum() {}
    
	std::string name() const { return std::string("(") + matrixl.name() + " + " + matrixr.name() + ")"; }
	
    inline value_type operator()(size_t i, size_t j) const {
      	return matrixl(i, j) + matrixr(i, j);
    }
    
    typename MatrixL::Nested matrixl;
    typename MatrixR::Nested matrixr;
    
private:
    std::string m_name;
    
};


//Represents the matrix difference.
template <typename MatrixL, typename MatrixR>
class Matrix_Difference : public Matrix_Expression< Matrix_Difference<MatrixL, MatrixR> > {
    
public:
    
    //typedef typename MatrixL::value_type value_type;
    typedef const Matrix_Difference Nested; //these are needed for the tree optimizer object
 
    enum traits {
        // sizes of the matrices on each side of operation
        RowsAtCompileTimeL = MatrixL::traits::RowsAtCompileTime,
        ColsAtCompileTimeL = MatrixL::traits::ColsAtCompileTime,
        RowsAtCompileTimeR = MatrixR::traits::RowsAtCompileTime,
        ColsAtCompileTimeR = MatrixR::traits::ColsAtCompileTime,
        // this is the resulting size of the expression, matrix difference operation so sizes are compatible
        RowsAtCompileTime = RowsAtCompileTimeL,
        ColsAtCompileTime = ColsAtCompileTimeL,
        IsContainerL = is_matrix_container<MatrixL>::value || !requires_evaluation<MatrixL>::value, // container or doesn't require evaluation
        IsContainerR = is_matrix_container<MatrixR>::value || !requires_evaluation<MatrixR>::value,
    };
    
    enum costs {
        Temp_Cost = 1,
        Op_CostL = IsContainerL == 1 ? 0 : MatrixL::costs::Op_Cost_Total,
        Op_CostR = IsContainerR == 1 ? Temp_Cost : MatrixR::costs::Op_Cost_Total, //because we're doing like A*B-C instead of C-A*B we incur a temporary cost
        Op_Cost = RowsAtCompileTime * ColsAtCompileTime,
        Op_Cost_Total = Op_Cost + Op_CostL + Op_CostR,
    };
 
	Matrix_Difference(const Matrix_Expression<MatrixL>& ml, const Matrix_Expression<MatrixR>& mr) : matrixl(ml), matrixr(mr) {}
    
	~Matrix_Difference() {}
    
	std::string name() const { return std::string("(") + matrixl.name() + " + " + matrixr.name() + ")"; }
    
    inline value_type operator()(size_t i, size_t j) const {
      	return matrixl(i, j) - matrixr(i, j);
    }
    
    typename MatrixL::Nested matrixl;
    typename MatrixR::Nested matrixr;

};

//represents a matrix product
template <typename MatrixL, typename MatrixR>
class Matrix_Product : public Matrix_Expression< Matrix_Product<MatrixL, MatrixR> > {
    
public:
    
    //typedef typename MatrixL::value_type value_type;
    typedef const Matrix_Product Nested;
 
    enum traits {
        // sizes of the matrices on each side of operation
        RowsAtCompileTimeL = MatrixL::traits::RowsAtCompileTime,
        ColsAtCompileTimeL = MatrixL::traits::ColsAtCompileTime,
        RowsAtCompileTimeR = MatrixR::traits::RowsAtCompileTime,
        ColsAtCompileTimeR = MatrixR::traits::ColsAtCompileTime,
        // this is the resulting size of the expression, matrix product operation (m x n)*(n x p) ~ (m x p)
        RowsAtCompileTime = RowsAtCompileTimeL,
        ColsAtCompileTime = ColsAtCompileTimeR,
        IsContainerL = is_matrix_container<MatrixL>::value || !requires_evaluation<MatrixL>::value, // container or doesn't require evaluation
        IsContainerR = is_matrix_container<MatrixR>::value || !requires_evaluation<MatrixR>::value,

    };
    
    enum costs {
        Temp_Cost = 1,
        Op_CostL = IsContainerL == 1 ? 0 : MatrixL::costs::Op_Cost_Total,
        Op_CostR = IsContainerR == 1 ? Temp_Cost : MatrixR::costs::Op_Cost_Total, //because we're doing like A*B+C instead of C+A*B we incur a temporary cost
        Op_Cost = RowsAtCompileTimeL * ColsAtCompileTimeR * (2 * ColsAtCompileTimeL - 1),
        Op_Cost_Total = Op_Cost + Op_CostL + Op_CostR,
    };
 
	Matrix_Product(const Matrix_Expression<MatrixL>& ml, const Matrix_Expression<MatrixR>& mr) : matrixl(ml), matrixr(mr) {}

	~Matrix_Product() {}

	std::string name() const { return std::string("(") + matrixl.name() + " * " + matrixr.name() + ")"; }

	inline value_type operator()(size_t i, size_t j) const {
        
        value_type tmp = 0;
        const size_t end = ( ( matrixl.size2() - 1 ) & size_t(-2) ) + 1;
        
        tmp = matrixl(i, 0) * matrixr(0, j);
        for(size_t k = 1; k < end; k += 2) {
            tmp += matrixl(i, k) * matrixr(k, j);
            tmp += matrixl(i, k + 1) * matrixr(k + 1, j);
        }
        if(end < matrixl.size2()) {
            tmp += matrixl(i, end) * matrixr(end, j);
        }
        
        return tmp;
    }

    
    typename MatrixL::Nested matrixl;
	typename MatrixR::Nested matrixr;
 
};

//useful operator overloads
template <typename MatrixL, typename MatrixR>
Matrix_Sum<MatrixL, MatrixR> operator+(const Matrix_Expression<MatrixL>& ml, const Matrix_Expression<MatrixR>& mr){
	return Matrix_Sum<MatrixL, MatrixR> (ml, mr);
}

template <typename MatrixL, typename MatrixR>
Matrix_Difference<MatrixL, MatrixR> operator-(const Matrix_Expression<MatrixL>& ml, const Matrix_Expression<MatrixR>& mr){
	return Matrix_Sum<MatrixL, MatrixR> (ml, mr);
}

template <typename MatrixL, typename MatrixR>
Matrix_Product<MatrixL, MatrixR> operator*(const Matrix_Expression<MatrixL>& ml, const Matrix_Expression<MatrixR>& mr){
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
    
    static NMatXpr build(const MatXpr& mxpr) {
        return mxpr;
    }
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
        treechanges = Tree_Optimizer<A>::treechanges || Tree_Optimizer<B>::treechanges,
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
        treechanges = Tree_Optimizer<A>::treechanges || Tree_Optimizer<B>::treechanges,
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
        treechanges = 1
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
    };
    
    typedef Matrix_Sum< Matrix_Sum<C, Matrix_Product<A,B> >, D> MatXpr;
    typedef typename Tree_Optimizer<C>::NMatXpr NMatC;
    typedef typename Tree_Optimizer<D>::NMatXpr NMatD;
    typedef Matrix_Sum< Matrix_Sum<NMatC, NMatD>, Matrix_Product<A,B> > NMatXpr;

    static NMatXpr build(const MatXpr& mxpr) {
        return Tree_Optimizer<C>::build(mxpr.matrixl.matrixl) + Tree_Optimizer<D>::build(mxpr.matrixr) + mxpr.matrixl.matrixr;
    }
};


// catch (A * B) + C + D and builds (C + D) + (A * B)
template<typename A, typename B, typename C, typename D>
class Tree_Optimizer< Matrix_Sum< Matrix_Sum< Matrix_Product<A, B>, C>, D> > {
public:
    
    enum {
        treechanges = 1,
    };
    
    typedef Matrix_Sum< Matrix_Sum< Matrix_Product<A, B>, C>, D> MatXpr;
    typedef typename Tree_Optimizer<C>::NMatXpr NMatC;
    typedef typename Tree_Optimizer<D>::NMatXpr NMatD;
    typedef Matrix_Sum<Matrix_Sum<NMatC, NMatD>, Matrix_Product<A,B> > NMatXpr;
    
    static NMatXpr build(const MatXpr& mxpr) {
        return Tree_Optimizer<C>::build(mxpr.matrixl.matrixr) + Tree_Optimizer<D>::build(mxpr.matrixr) + Tree_Optimizer<Matrix_Product<A, B>>::build(mxpr.matrixl.matrixl);
    }
};

// catch A * B + C * D and builds A * B + C * D
template<typename A, typename B, typename C, typename D>
class Tree_Optimizer< Matrix_Sum< Matrix_Product<A, B>, Matrix_Product<C, D> > > {
public:
    
    enum {
        treechanges = 0
    };
    
    typedef Matrix_Sum< Matrix_Product<A, B>, Matrix_Product<C, D> > MatXpr;
    typedef Matrix_Sum< Matrix_Product<A, B>, Matrix_Product<C, D> > NMatXpr;
    
    static NMatXpr build(const MatXpr& mxpr) {
        return mxpr;
    }
    
};


// catch (A * B) * C and builds
// A * (B * C) if C is a vector
// (A * B) * C if C is a matrix
// might be useful for vectorization?
template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Product< Matrix_Product<A, B>, C> > {
public:
    
    enum {
        treechanges = 1,
    };
    
    typedef Matrix_Product< Matrix_Product<A, B>, C> MatXpr;
    typedef typename Tree_Optimizer<C>::NMatXpr NMatC;
    typedef Matrix_Product< A, Matrix_Product<B, C> > NMatXpr;

    template <typename c = C> //only way to get enable_if to work with member functions (ugh) return type is Matrix_Product< A, Matrix_Product<B, C> >
    static typename boost::enable_if<boost::is_same<c, Vector4d>, NMatXpr>::type build(const MatXpr& mxpr) {
        return Tree_Optimizer<A>::build(mxpr.matrixl.matrixl) * (Tree_Optimizer<B>::build(mxpr.matrixl.matrixr) * Tree_Optimizer<C>::build(mxpr.matrixr)); //using () to build the new order of operations
    }
    
    template <typename c = C> //only way to get enable_if to work with member functions (ugh) return type is Matrix_Product< Matrix_Product<A, B>, C>
    static typename boost::enable_if<boost::is_same<c, Matrix4d>, MatXpr>::type build(const MatXpr& mxpr) {
        return Tree_Optimizer<Matrix_Product<A, B>>::build(mxpr.matrixl) * Tree_Optimizer<C>::build(mxpr.matrixr);
    }
 
};

/*
template <typename totalsize, typename poolsize>
struct curry {
    struct if_ops {
        
        template <typename maxelement>
        struct if_ {
            typedef mpl::times< totalsize , maxelement > part0;
            typedef mpl::times< part0 , mpl::int_< 3 > > part1;
            typedef typename mpl::greater< part1, poolsize>::type type;
        };
        
        template <typename maxelement>
        struct then_ : mpl::divides < maxelement, mpl::int_< 2 > > { };
        
    };
    
    template <typename maxelement>
    struct loop : mpl::while_ < maxelement, if_ops> { };
    
};

void test(void) {
    typedef mpl::int_< 144 > totalsize_t;
    typedef mpl::int_< 140000 > poolsize_t;
    typedef mpl::int_< 1024 > maxelement_t;
    typedef curry<totalsize_t, poolsize_t>::loop<maxelement_t>::type actual;
    int const totalsize_v = totalsize_t::value;
    int const poolsize_v = poolsize_t::value;
    int maxelement_v = maxelement_t::value;
    while( totalsize_v * maxelement_v * 3 > poolsize_v )
        maxelement_v >>= 1;
    
    std::cout<<"actual result= " << actual::value << "\n";
    std::cout<<"expected result= " << maxelement_v << "\n";
}
*/
/*
template
< class State //nullary metafunction returning current state.
, class IfOps //contains nested unary metafunctions, if_, then_.
>
struct while_
: mpl::eval_if < typename IfOps::template if_<typename State::type>::type , while_ < typename IfOps::template then_<typename State::type> , IfOps >, State >
{ };
*/
/*
template<
typename C
, typename F1
, typename F2
>
struct eval_if
{
    typedef unspecified type;
};
*/
/*
template
< class State //nullary metafunction returning current state.
, class IfOps //contains nested unary metafunctions, if_, then_.
>
struct while_
: mpl::eval_if < typename IfOps::if_::type, while_ < typename IfOps::if_, IfOps >, typename IfOps::then_::type >
{ };

template <typename MatXpr>
struct Op {
    
    struct if_ops {
        
        typedef typename  NMatXpr;
        
        struct if_ {
            typedef mpl::bool_< Tree_Optimizer<typename mpl::end<types>::type>::treechanges > treechange;
            typedef typename Tree_Optimizer<typename mpl::end<types>::type>::NMatXpr NMatXpr;
            typedef typename is_same<treechange, true_type>::type type;
        };
        
        struct then_ {
            typedef typename if_::NMatXpr type;
        };
        
    };
    
    struct loop : while_ < typename is_same< mpl::bool_< Tree_Optimizer<MatXpr>::treechanges >, true_type>::type, if_ops> {

    };
    
}; */

struct Optimizer {
    
    template <typename MatExpr>
    auto operator() (MatExpr& matexpr) -> decltype(Tree_Optimizer<MatExpr>::build(matexpr)) {
        return Tree_Optimizer<MatExpr>::build(matexpr);
    }
    
};

int main(){

	Matrix4d A("A"), B("B"), C("C"), D("D");
    Vector4d a("a"), b("b"), c("c"), d("d");
    std::cout << "\n";
 
    auto xpr = A * B + C;
    
    std::cout << "init version:";
    std::cout << " " << xpr.name() << "\n";
    std::cout << "cost " << xpr.Op_Cost_Total << "\n";
    
    typedef decltype(xpr) Xpr;
/*
    typedef mpl::if_< mpl::less< mpl::size_t< decltype(Tree_Optimizer<Xpr>::build(xpr))::Op_Cost_Total >, mpl::size_t< Xpr::Op_Cost_Total > >::type, decltype(Tree_Optimizer<Xpr>::build(xpr)), Xpr>::type type;
    type xpr1 = Opt(xpr);
    std::cout << "cost smaller? " << Xpr::Op_Cost_Total << " " << type::Op_Cost_Total << std::endl;
*/
    
    typedef mpl::vector< decltype(xpr) > types;
    typedef mpl::front<types>::type t;
    typedef mpl::push_front<types, decltype(Tree_Optimizer<t>::build(xpr)) >::type types1;
    typedef mpl::front<types1>::type t1;
    typedef mpl::push_front<types1, decltype(Tree_Optimizer<t1>::build( Tree_Optimizer<t>::build(xpr) ) ) >::type types2;
    typedef mpl::front<types2>::type t2;
    typedef mpl::push_front<types2, decltype( Tree_Optimizer<t2>::build( Tree_Optimizer<t1>::build( Tree_Optimizer<t>::build(xpr) ) ) ) >::type types3;
    typedef mpl::front<types3>::type t3;
    typedef mpl::push_front<types3, decltype(Tree_Optimizer<t3>::build( Tree_Optimizer<t2>::build( Tree_Optimizer<t1>::build( Tree_Optimizer<t>::build(xpr) ) ) )) >::type types4;
    typedef mpl::front<types4>::type t4;
    std::cout << mpl::size<types4>::value << std::endl << std::endl;
    
    t1 xpr1 = Tree_Optimizer<t>::build(xpr);
    t2 xpr2 = Tree_Optimizer<t1>::build(xpr1);
    t3 xpr3 = Tree_Optimizer<t2>::build(xpr2);
    t4 xpr4 = Tree_Optimizer<t3>::build(xpr3);
    std::cout << std::endl << "optimized version 1:";
    std::cout << " " << xpr4.name() << "\n";
    std::cout << "cost " << xpr4.Op_Cost_Total << "\n";
    
    /*
    std::cout << "init version:";
    std::cout << " " << xpr.name() << "\n";
    std::cout << "cost " << xpr.Op_Cost_Total << "\n";
    
    Tree_Optimizer<Xpr>::NMatXpr xpr1 = Tree_Optimizer<Xpr>::build(xpr);
    typedef decltype(xpr1) Xpr1;
    std::cout << std::endl << "optimized version 1:";
    std::cout << " " << xpr1.name() << std::endl;
    std::cout << "cost " << xpr1.Op_Cost_Total << std::endl;
    std::cout << "change " << Tree_Optimizer<Xpr>::treechanges << std::endl << std::endl;

    Tree_Optimizer<Xpr1>::NMatXpr xpr2 = Tree_Optimizer<Xpr1>::build(xpr1);
    typedef decltype(xpr2) Xpr2;
    std::cout << std::endl << "optimized version 2:";
    std::cout << " " << xpr2.name() << std::endl;
    std::cout << "cost " << xpr2.Op_Cost_Total << std::endl;
    std::cout << "change " << Tree_Optimizer<Xpr1>::treechanges << std::endl << std::endl;

    Tree_Optimizer<Xpr2>::NMatXpr xpr3 = Tree_Optimizer<Xpr2>::build(xpr2);
    typedef decltype(xpr3) Xpr3;
    std::cout << std::endl << "optimized version 3:";
    std::cout << " " << xpr3.name() << std::endl;
    std::cout << "cost " << xpr3.Op_Cost_Total << std::endl;
    std::cout << "change " << Tree_Optimizer<Xpr2>::treechanges << std::endl << std::endl;
*/
	return 0;
}