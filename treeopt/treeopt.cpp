/*
Tree optimizer prototype and test code.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
//#include <boost/utility/enable_if.hpp>
//#include <boost/mpl/less_equal.hpp>
//#include <boost/mpl/greater.hpp>
//#include <boost/mpl/comparison.hpp>

//using namespace boost;

typedef double value_type; // simplifying things with the templates

//Base class.
template <typename MatXpr>
class Matrix_Base {
  
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
template <size_t rows, size_t cols>
class Dense_Matrix : public Matrix_Base< Dense_Matrix<rows, cols> > {
    
public:
    
    // typedef type value_type;
    typedef typename std::vector< std::vector<value_type> > storage_type;
    typedef const Dense_Matrix& Nested;
    
    enum traits {
         RowsAtCompileTime = rows,
         ColsAtCompileTime = cols,
         op_cost = 0
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

//Represents the matrix sum.
template <typename MatrixL, typename MatrixR>
class Matrix_Sum : public Matrix_Base< Matrix_Sum<MatrixL, MatrixR> > {
    
public:
    
    //typedef typename MatrixL::value_type value_type;
    typedef const Matrix_Sum Nested; //these are needed for the tree optimizer object
    
    enum traits {
        RowsAtCompileTime = MatrixL::traits::RowsAtCompileTime, 
        ColsAtCompileTime = MatrixL::traits::ColsAtCompileTime,
        op_cost = RowsAtCompileTime * ColsAtCompileTime + MatrixL::traits::op_cost + MatrixR::traits::op_cost
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
        RowsAtCompileTime = MatrixL::traits::RowsAtCompileTime, 
        ColsAtCompileTime = MatrixL::traits::ColsAtCompileTime,
        op_cost = RowsAtCompileTime * ColsAtCompileTime + MatrixL::traits::op_cost + MatrixR::traits::op_cost
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
        RowsAtCompileTime = MatrixL::traits::RowsAtCompileTime, //assuming square matrices!
        ColsAtCompileTime = MatrixL::traits::ColsAtCompileTime,
        op_cost = RowsAtCompileTime * ColsAtCompileTime * (2 * RowsAtCompileTime - 1) + MatrixL::traits::op_cost + MatrixR::traits::op_cost
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
    typedef MatXpr NMatXpr;
    static MatXpr build(const MatXpr& mxpr) { return mxpr; }
};

// Tree optimizer for Dense_Matrix that copies by reference
template<size_t rows, size_t cols>
class Tree_Optimizer< Dense_Matrix<rows, cols> > {
public:

    typedef Dense_Matrix<rows, cols> NMatXpr;
    static const Dense_Matrix<rows, cols>& build(const Dense_Matrix<rows, cols>& mxpr) { return mxpr; }
};

// Needed to forward the optimizer to the children
template<typename A, typename B>
class Tree_Optimizer< Matrix_Sum<A, B> > {
public:

    typedef Matrix_Sum<A, B> MatXpr;
    typedef typename Tree_Optimizer<A>::NMatXpr NMatA;
    typedef typename Tree_Optimizer<B>::NMatXpr NMatB;
    typedef Matrix_Sum<NMatA, NMatB> NMatXpr;
    
    static NMatXpr build(const MatXpr& mxpr) { return Tree_Optimizer<A>::build(mxpr.matrixl) + Tree_Optimizer<B>::build(mxpr.matrixr); }
};

// catch A * B + C and builds C + A * B
template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Sum< Matrix_Product<A, B>, C> > {
public:

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

    typedef Matrix_Sum< Matrix_Sum<C, Matrix_Product<A,B> >, D> MatXpr;
    typedef typename Tree_Optimizer<C>::NMatXpr NMatC;
    typedef typename Tree_Optimizer<D>::NMatXpr NMatD;
    typedef Matrix_Sum< Matrix_Sum<NMatC, NMatD>, Matrix_Product<A,B> > NMatXpr;

    static NMatXpr build(const MatXpr& mxpr) { return Tree_Optimizer<C>::build(mxpr.matrixl.matrixl) + Tree_Optimizer<D>::build(mxpr.matrixr) + mxpr.matrixl.matrixr; }
};

int main(){

	Dense_Matrix<2, 2> a("a"), b("b"), c("c"), d("d");

    auto xpr = b * c + d + a + a * c;
    
    typedef __typeof(xpr) Xpr;
    
    std::cout << "init version:";
    std::cout << " " << xpr.name() << "\n";
    std::cout << xpr.op_cost << std::endl;

    auto xpr1 = Tree_Optimizer<Xpr>::build(xpr);
    typedef __typeof(xpr1) Xpr1;
    std::cout << std::endl << "optimized version 1:";
    std::cout << " " << xpr1.name() << std::endl;
    std::cout << xpr1.op_cost << std::endl;
   
    auto xpr2 = Tree_Optimizer<Xpr1>::build(xpr1);
    typedef __typeof(xpr2) Xpr2;
    std::cout << std::endl << "optimized version 2:";
    std::cout << " " << xpr2.name() << std::endl;
    std::cout << xpr2.op_cost << std::endl;

    auto xpr3 = Tree_Optimizer<Xpr2>::build(xpr2);
    typedef __typeof(xpr3) Xpr3;
    std::cout << std::endl << "optimized version 3:";
    std::cout << " " << xpr3.name() << std::endl;
    std::cout << xpr3.op_cost << std::endl;

	return 0;
}