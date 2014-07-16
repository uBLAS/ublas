/*
Tree optimizer prototype and test code.
Based on code gathered from myself, ublas, blaze, eigen.
*/

#include <algorithm>
#include <iostream>
#include <typeinfo>
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
#include <boost/mpl/less_equal.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/replace_if.hpp>
#include <boost/mpl/greater.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/while.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/divides.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/reverse.hpp>
#include <boost/fusion/container/list.hpp>
#include <boost/fusion/include/list.hpp>
#include <boost/fusion/container/list/list_fwd.hpp>
#include <boost/fusion/include/list_fwd.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/container/vector/vector_fwd.hpp>
#include <boost/fusion/include/vector_fwd.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/include/at.hpp>
#include <boost/fusion/algorithm/transformation/push_back.hpp>
#include <boost/fusion/include/push_back.hpp>
#include <boost/fusion/iterator/next.hpp>
#include <boost/fusion/sequence/intrinsic/at_c.hpp>
#include <boost/fusion/include/at_c.hpp>
#include <boost/fusion/algorithm/auxiliary/copy.hpp>
#include <boost/fusion/include/copy.hpp>
#include <boost/fusion/algorithm/transformation/push_back.hpp>
#include <boost/fusion/include/push_back.hpp>
#include <boost/fusion/algorithm/auxiliary/copy.hpp>
#include <boost/fusion/include/copy.hpp>
#include <boost/fusion/algorithm/transformation/clear.hpp>
#include <boost/fusion/include/clear.hpp>

#include "alignment_trait.hpp"

using namespace boost;

typedef double value_type; // simplifying things with the templates

//-----------------------
// forward declarations
//-----------------------
template <typename MatXpr>
class Matrix_Expression;

template <size_t rows, size_t cols>
class Dense_Matrix;

template <typename MatXpr>
class Scalar_Multiple;

template <typename MatrixL, typename MatrixR>
class Matrix_Sum;

template <typename MatrixL, typename MatrixR>
class Matrix_Difference;

template <typename MatrixL, typename MatrixR>
class Matrix_Product;

template<typename T> struct evaluator;

template< typename A, typename B, typename Op>
struct Assignment;

template<typename MatXpr>
class Tree_Optimizer;

template<size_t rows, size_t cols>
class Tree_Optimizer< Dense_Matrix<rows, cols> >;

template<typename A, typename B>
class Tree_Optimizer< Matrix_Sum<A, B> >;

template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Sum< Matrix_Product<A, B>, C> >;

template<typename A, typename B>
class Tree_Optimizer< Matrix_Product<A, B> >;

template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Sum< Matrix_Product<A, B>, C> >;

template<typename A, typename B, typename C, typename D>
class Tree_Optimizer< Matrix_Sum< Matrix_Sum<C, Matrix_Product<A, B> >, D> >;

template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Difference< Matrix_Product<A, B>, C> >;

template<typename A, typename B, typename C, typename D>
class Tree_Optimizer< Matrix_Difference< Matrix_Sum<C, Matrix_Product<A, B> >, D> >;

template<typename A, typename B, typename C, typename D>
class Tree_Optimizer< Matrix_Sum< Matrix_Difference<C, Matrix_Product<A, B> >, D> >;

template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Product< Matrix_Product<A, B>, C> >;

template <typename xpr1, typename... Arguments>
class Optimize;

template<typename Dest, typename Src, typename Func>
void assign(Dest& dest, const Src& src, const Func& func);

class Matrix_Container { };
//--------------------------
// end foward declarations
//--------------------------

//--------------------------------
// Some useful type traits stuff
//--------------------------------
template <typename T>
struct is_matrix_expression {
public:
    enum { value = is_base_of<Matrix_Expression<T>, T>::value && !is_base_of<T, Matrix_Expression<T>>::value };
    typedef typename select_type<value, true_type, false_type>::type  type;
};

template <typename T>
struct is_matrix_container {
public:
    enum { value = is_base_of<Matrix_Container, T>::value && !is_base_of<T, Matrix_Container>::value };
    typedef typename select_type<value, true_type, false_type>::type  type;
};

template <typename T>
struct is_temporary {
public:
    enum { value = !is_reference<T>::value && !is_floating_point<T>::value && !is_matrix_expression<T>::value };
    typedef typename select_type<value, true_type, false_type>::type  type;
};

template <typename T>
struct requires_evaluation {
public:
    enum { value = !is_reference<typename T::Nested>::value };
    typedef typename select_type<value, true_type, false_type>::type  type;
};

//--------------------------------
// End useful type traits stuff
//--------------------------------

//--------------------------
// Functors for assignments
//--------------------------
template<typename Scalar>
struct assign_default {
    void assign(Scalar& a, const Scalar& b) const { a = b; }
    std::string name() const { return " = "; }
};

template<typename Scalar> struct assign_add {
    void assign(Scalar& a, const Scalar& b) const { a += b; }
    std::string name() const { return " += "; }
};

template<typename Scalar> struct assign_subtract {
    void assign(Scalar& a, const Scalar& b) const { a -= b; }
    std::string name() const { return " -= "; }
};

template<typename Scalar> struct assign_mult {
    void assign(Scalar& a, const Scalar& b) const { a *= b; }
    std::string name() const { return " *= "; }
};


template <typename MatXpr>
class Matrix_Expression {
  
public:
    
    const MatXpr& matxpr() const { return static_cast<const MatXpr&>(*this); }
    
    MatXpr& matxpr() { return static_cast<MatXpr&>(*this); }
    
  	operator MatXpr&() { return static_cast<MatXpr&>(*this); }

  	operator const MatXpr&() const { return static_cast<const MatXpr&>(*this); }
 
    template <typename Other>
    Matrix_Sum<MatXpr, Other> operator+(const Matrix_Expression<Other>& other) const {
        return Matrix_Sum<MatXpr, Other> (matxpr(), other.matxpr());
    }
    
    template <typename Other>
    Matrix_Difference<MatXpr, Other> operator-(const Matrix_Expression<Other>& other) const {
        return Matrix_Difference<MatXpr, Other> (matxpr(), other.matxpr());
    }
    
    template <typename Other>
    Matrix_Product<MatXpr, Other> operator*(const Matrix_Expression<Other>& other) const {
        return Matrix_Product<MatXpr, Other> (matxpr(), other.matxpr());
    }
    
    Scalar_Multiple<MatXpr> operator*(value_type c) {
        assign(matxpr(), c, assign_mult<value_type>());
        return Scalar_Multiple<MatXpr> (matxpr());
    }
    
    template<typename Other> MatXpr& operator=(const Matrix_Expression<Other>& other) {
        assign(matxpr(), other.matxpr(), assign_default<value_type>());
        return matxpr();
    }
    
    template<typename Other> MatXpr& operator+=(const Matrix_Expression<Other>& other) {
        assign(matxpr(), other.matxpr(), assign_add<value_type>());
        return matxpr();
    }
    
    template<typename Other> MatXpr& operator-=(const Matrix_Expression<Other>& other) {
        assign(matxpr(), other.matxpr(), assign_subtract<value_type>());
        return matxpr();
    }
    
    MatXpr& operator*=(value_type c) {
        assign(matxpr(), c, assign_mult<value_type>());
        return matxpr();
    }
    
    void transpose_in_place() {
        for(size_t i = 0; i < matxpr().rows() - 2; ++i){
            for(size_t j = i + 1; j < matxpr().rows(); ++j){
                std::swap( matxpr()(j, i), matxpr()(i, j) );
            }
        }
    }
    
};

//Dense matrix class that extends the base class
template <size_t Rows, size_t Cols>
class Dense_Matrix : public Matrix_Container, public Matrix_Expression< Dense_Matrix<Rows, Cols> > {
    
public:
    
    typedef typename std::vector< std::vector<value_type> > storage_type;
    using Matrix_Expression< Dense_Matrix<Rows, Cols> >::operator=;
    
    enum traits {
        RowsAtCompileTime = Rows,
        ColsAtCompileTime = Cols,
        SizeAtCompileTime = Rows * Cols,
        
        IsVectorizable = num_traits<value_type>::IsVectorizable,
    };
    
    enum costs {
        ReadCost = num_traits<value_type>::ReadCost * traits::SizeAtCompileTime, // because it's just an matrix we only have a read cost associated with this expression
        AddCost = 0,
        MultCost = 0,
        Op_Cost = ReadCost,
    };

    inline Dense_Matrix(const std::string& name) : m_name(name), _rows(Rows), _cols(Cols) {
        std::vector<value_type> row(_cols);
        _data.resize(_rows, row);
        if(_rows == 1 || _cols == 1){
            std::cout << "- Create vector " << m_name << std::endl;
        }
        else { std::cout << "- Create matrix " << m_name << std::endl; }
    }
    
    inline Dense_Matrix(value_type c) : _rows(Rows), _cols(Cols) { // initializer constructor
        std::vector<value_type> row(_cols, c);
        _data.resize(_rows, row);
    }
    
    inline std::string name() const { return m_name; } //just the name
    
    constexpr inline size_t rows() const { return _rows; }
    
    constexpr inline size_t cols() const { return _cols; }
    
    inline const value_type& operator()(size_t i, size_t j) const { return _data[i][j]; }
    
    inline value_type& operator()(size_t i, size_t j) { return _data[i][j]; }
    
    typedef const Dense_Matrix& Nested;
    std::string m_name;
    size_t _rows, _cols;
    storage_type _data;
    
};

typedef Dense_Matrix<4, 1> Vector4d;
typedef Dense_Matrix<4, 4> Matrix4d;

template <typename MatXpr>
class Scalar_Multiple : public Matrix_Expression< Scalar_Multiple<MatXpr> > {
    
public:
    
    typedef const Scalar_Multiple Nested; //these are needed for the tree optimizer object
    
    enum traits {
        // this is the size of the expression
        RowsAtCompileTime = MatXpr::traits::RowsAtCompileTime,
        ColsAtCompileTime = MatXpr::traits::ColsAtCompileTime,
        SizeAtCompileTime = RowsAtCompileTime * ColsAtCompileTime,
    };
    
    enum costs {
        // cost associated with this expression
        ReadCost = num_traits<value_type>::ReadCost * traits::SizeAtCompileTime,
        AddCost = 0,
        MultCost = 0,
        
        Op_Cost = 0,
    };
    
    explicit inline Scalar_Multiple(const Matrix_Expression<MatXpr>& mat) : matrix(mat) { }
    
    inline std::string name() const { return std::string("(scalar multiple of ") + matrix.name() + ")"; }
    
    typename MatXpr::Nested& matrix;
    
};

template <typename MatXpr>
class Transpose : public Matrix_Expression< Scalar_Multiple<MatXpr> > {
    
public:
    
    typedef const Transpose Nested; //these are needed for the tree optimizer object
    
    enum traits {
        // this is the size of the expression
        RowsAtCompileTime = MatXpr::traits::ColsAtCompileTime,
        ColsAtCompileTime = MatXpr::traits::RowsAtCompileTime,
        SizeAtCompileTime = RowsAtCompileTime * ColsAtCompileTime,
    };
    
    enum costs {
        // cost associated with this expression
        ReadCost = num_traits<value_type>::ReadCost * traits::SizeAtCompileTime,
        AddCost = 0,
        MultCost = 0,
        
        Op_Cost = 0,
    };
    
    explicit inline Transpose(const Matrix_Expression<MatXpr>& mat) : matrix(mat) { }
    
    inline std::string name() const { return std::string("(Transpose of ") + matrix.name() + ")"; }
    
    constexpr inline size_t rows() const { return matrix.rows(); }
    
    constexpr inline size_t cols() const { return matrix.cols(); }
    
    typename MatXpr::Nested matrix;
    
};


//Represents the matrix sum.
template <typename MatrixL, typename MatrixR>
class Matrix_Sum : public Matrix_Expression< Matrix_Sum<MatrixL, MatrixR> > {
    
public:
    
    //typedef typename MatrixL::value_type value_type;
    typedef const Matrix_Sum Nested; //these are needed for the tree optimizer object

    enum traits {
        // this is the resulting size of the expression, matrix sum operation so sizes are compatible
        RowsAtCompileTime = MatrixL::traits::RowsAtCompileTime,
        ColsAtCompileTime = MatrixL::traits::ColsAtCompileTime,
        SizeAtCompileTime = RowsAtCompileTime * ColsAtCompileTime,
        
        // container or doesn't require evaluation
        IsContainerL = is_matrix_container<MatrixL>::value || !requires_evaluation<MatrixL>::value,
        IsContainerR = is_matrix_container<MatrixR>::value || !requires_evaluation<MatrixR>::value,
        
        // vectorization available
        IsVectorizable = MatrixL::traits::IsVectorizable,
    };
    
    enum costs {
        // cost associated with this expression
        ReadCost = num_traits<value_type>::ReadCost * traits::SizeAtCompileTime,
        AddCost = num_traits<value_type>::AddCost * SizeAtCompileTime,
        MultCost = 0, // not a multiply expression
        
        // total nested cost associated with MatrixL
        Op_CostL = MatrixL::costs::Op_Cost,
        // total nested cost associated with MatrixL
        Op_CostR = MatrixR::costs::Op_Cost,
        
        // if MatrixR can be moved to the left side and then moved don't include the cost (Ultimately just ReadCost).
        Op_Cost = IsContainerR == 1 ? Op_CostL + AddCost + Op_CostR : Op_CostR + AddCost,
    };
 
    explicit inline Matrix_Sum(const Matrix_Expression<MatrixL>& ml, const Matrix_Expression<MatrixR>& mr) : matrixl(ml), matrixr(mr) {}
    
    inline std::string name() const { return std::string("(") + matrixl.name() + " + " + matrixr.name() + ")"; }

    typename MatrixL::Nested matrixl;
    typename MatrixR::Nested matrixr;
    
};

//Represents the matrix difference.
template <typename MatrixL, typename MatrixR>
class Matrix_Difference : public Matrix_Expression< Matrix_Difference<MatrixL, MatrixR> > {
    
public:
    
    //typedef typename MatrixL::value_type value_type;
    typedef const Matrix_Difference Nested; //these are needed for the tree optimizer object
    
    enum traits {
        // this is the resulting size of the expression, matrix sum operation so sizes are compatible
        RowsAtCompileTime = MatrixL::traits::RowsAtCompileTime,
        ColsAtCompileTime = MatrixL::traits::ColsAtCompileTime,
        SizeAtCompileTime = RowsAtCompileTime * ColsAtCompileTime,
        
        // container or doesn't require evaluation
        IsContainerL = is_matrix_container<MatrixL>::value || !requires_evaluation<MatrixL>::value,
        IsContainerR = is_matrix_container<MatrixR>::value || !requires_evaluation<MatrixR>::value,
        
        // vectorization available
        IsVectorizable = MatrixL::traits::IsVectorizable,
    };
    
    enum costs {
        // cost associated with this expression
        ReadCost = num_traits<value_type>::ReadCost * traits::SizeAtCompileTime,
        AddCost = num_traits<value_type>::AddCost * SizeAtCompileTime,
        MultCost = 0, // not a multiply expression
        
        // total nested cost associated with MatrixL
        Op_CostL = MatrixL::costs::Op_Cost,
        // total nested cost associated with MatrixL
        Op_CostR = MatrixR::costs::Op_Cost,
        
        // if MatrixR can be moved to the left side and then moved don't include the cost (Ultimately just ReadCost).
        Op_Cost = IsContainerR == 1 ? Op_CostL + AddCost + Op_CostR : Op_CostR + AddCost,
    };
    
	explicit inline Matrix_Difference(const Matrix_Expression<MatrixL>& ml, const Matrix_Expression<MatrixR>& mr) : matrixl(ml), matrixr(mr) {}
    
	~Matrix_Difference() {}
    
	inline std::string name() const { return std::string("(") + matrixl.name() + " - " + matrixr.name() + ")"; }
    
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
        // this is the resulting size of the expression, matrix product operation (m x n)*(n x p) ~ (m x p)
        RowsAtCompileTime = MatrixL::traits::RowsAtCompileTime,
        ColsAtCompileTime = MatrixR::traits::ColsAtCompileTime,
        SizeAtCompileTime = RowsAtCompileTime * ColsAtCompileTime,
        
        // vectorization available
        IsVectorizable = MatrixL::traits::IsVectorizable,
        
        // Used for (A * B) * C - > A * (B * C)
        IsProductL = is_same<MatrixL, Matrix_Product<Matrix4d, Matrix4d>>::value,
    };
    
    enum costs {
        // cost associated with this expression
        ReadCost = num_traits<value_type>::ReadCost * traits::SizeAtCompileTime,
        AddCost = 0, // not a multiply expression
        MultCost = num_traits<value_type>::MultCost * SizeAtCompileTime,
        
        // total nested cost associated with MatrixL
        Op_CostL = MatrixL::costs::Op_Cost,
        // total nested cost associated with MatrixL
        Op_CostR = MatrixR::costs::Op_Cost,
        
        // Multiplication is non-commutative so the cost should represent this
        Op_Cost = IsProductL == 1 ? Op_CostL + Op_CostR + MultCost + 1 : Op_CostL + Op_CostR + MultCost,
    };
 
    explicit inline Matrix_Product(const Matrix_Expression<MatrixL>& ml, const Matrix_Expression<MatrixR>& mr) : matrixl(ml), matrixr(mr) {}
    
    inline std::string name() const { return std::string("(") + matrixl.name() + " * " + matrixr.name() + ")"; }
    
    typename MatrixL::Nested matrixl;
	typename MatrixR::Nested matrixr;
 
};

// Expression of explicit evaluation to a temporary
template<typename MatXpr>
class Eval_To_Temp : public Matrix_Expression< Eval_To_Temp<MatXpr> > {
    
public:
    typedef Eval_To_Temp Nested;
    
    Eval_To_Temp(const MatXpr& mat) : matxpr(mat) {}
    size_t rows() const { return matxpr.rows(); }
    size_t cols() const { return matxpr.cols(); }
    
    std::string name() const { return std::string("eval(") + matxpr.name() + ")"; }
    
    const MatXpr& matxpr;
    
};

//--------------------
// Dense Evaluators
//--------------------

// Default evaluator assuming the expression is it's own evaluator
template <size_t rows, size_t cols>
struct evaluator< Dense_Matrix<rows, cols> > {

    typedef evaluator type;
    evaluator(const Dense_Matrix<rows, cols>& x) : matxpr(x) {/*std::cout << __LINE__ << "\n";*/}
    std::string name() const { return matxpr.name(); }
    inline value_type operator()(size_t i, size_t j) const { return matxpr(i, j); }
    inline value_type& operator()(size_t i, size_t j) { return const_cast<Dense_Matrix<rows, cols>&>(matxpr)(i, j); }
    
    const Dense_Matrix<rows, cols>& matxpr;
    
};

// evaluator of A * constant
template<typename A>
struct evaluator< Scalar_Multiple<A> > {
    
    typedef evaluator type;
    evaluator(const Scalar_Multiple<A>& xpr) : matrix(xpr.matrix) {}
    inline const value_type operator()(size_t i, size_t j) const { return matrix(i, j); }
    typename evaluator<A>::type matrix;
    
    std::string name() const { return std::string("(") + matrix.name() + ")"; }
    
};

// evaluator of A + B
template<typename A, typename B>
struct evaluator< Matrix_Sum<A, B> > {
    
    typedef evaluator type;
    evaluator(const Matrix_Sum<A, B>& plus) : matrixl(plus.matrixl), matrixr(plus.matrixr) {}
    inline const value_type operator()(size_t i, size_t j) const { return matrixl(i, j) + matrixr(i, j); }
    typename evaluator<A>::type matrixl;
    typename evaluator<B>::type matrixr;
    
    std::string name() const { return std::string("(") + matrixl.name() + " + " + matrixr.name() + ")"; }
    
};

// evaluator of A - B
template<typename A, typename B>
struct evaluator< Matrix_Difference<A, B> > {
    
    typedef evaluator type;
    evaluator(const Matrix_Difference<A, B>& difference) : matrixl(difference.matrixl), matrixr(difference.matrixr) {}
    inline const value_type operator()(size_t i, size_t j) const { return matrixl(i, j) - matrixr(i, j); }
    typename evaluator<A>::type matrixl;
    typename evaluator<B>::type matrixr;
    
    std::string name() const { return std::string("(") + matrixl.name() + " - " + matrixr.name() + ")"; }
    
};

/// low level product implementation (c += a*b)
template<typename Dest, typename A, typename B>
void product_impl_low_level(Dest& c, const A& a, const B& b) {
    
    for(size_t i = 0; i < c.rows(); ++i){
        for(size_t j = 0; j < c.cols(); ++j){
            value_type tmp = 0;
            const size_t end = ( ( a.cols() - 1 ) & size_t(-2) ) + 1;
            
            tmp = a(i, 0) * b(0, j);
            for(size_t k = 1; k < end; k += 2) {
                tmp += a(i, k) * b(k, j);
                tmp += a(i, k + 1) * b(k + 1, j);
            }
            if(end < a.cols()) {
                tmp += a(i, end) * b(end, j);
            }
            
            c(i, j) += tmp;
        }
    }
}

/// low level product implementation (c -= a*b)
template<typename Dest, typename A, typename B>
void product_sub_impl_low_level(Dest& c, const A& a, const B& b) {
    
    for(size_t i = 0; i < c.rows(); ++i){
        for(size_t j = 0; j < c.cols(); ++j){
            value_type tmp = 0;
            const size_t end = ( ( a.cols() - 1 ) & size_t(-2) ) + 1;
            
            tmp = a(i, 0) * b(0, j);
            for(size_t k = 1; k < end; k += 2) {
                tmp += a(i, k) * b(k, j);
                tmp += a(i, k + 1) * b(k + 1, j);
            }
            if(end < a.cols()) {
                tmp += a(i, end) * b(end, j);
            }
            
            c(i, j) -= tmp;
        }
    }
}


// special product evaluator (in Eigen it is currently equivalent to blas_traits)
template <typename MatXpr>
struct product_evaluator {
    product_evaluator(const MatXpr& x) : m_mat("product_arg_temporary_of_\"" + x.name() + "\"") {
        m_mat = x;
    }
    std::string name() const { return m_mat.m_name; }
    Dense_Matrix<MatXpr::RowsAtCompileTime, MatXpr::ColsAtCompileTime> m_mat;
};

template <size_t rows, size_t cols>
struct product_evaluator<Dense_Matrix<rows, cols>> {
    product_evaluator(const Dense_Matrix<rows, cols>& x) : m_mat(x) {}
    std::string name() const { return m_mat.m_name; }
    const Dense_Matrix<rows, cols>& m_mat;
};

/// performs dest += a * b;
/// A general implementation must be available outisde the evaluator because it is needed by both
/// evaluator<Product> and Assignment<..., Product<...> > for in-place product evaluation
template <typename Dest, typename A, typename B>
void product_impl(Dest& dest, const Matrix_Product<A, B>& prod) {
    product_evaluator<A> lhs(prod.matrixl);
    product_evaluator<B> rhs(prod.matrixr);
    std::cout << "- performs: " << dest.m_name << " += " << lhs.name() << " * " << rhs.name() + " in place\n";
    product_impl_low_level(dest, lhs.m_mat, rhs.m_mat);
};

/// performs dest -= a * b;
/// A general implementation must be available outisde the evaluator because it is needed by both
/// evaluator<Product> and Assignment<..., Product<...> > for in-place product evaluation
template <typename Dest, typename A, typename B>
void product_subtract_impl(Dest& dest, const Matrix_Product<A, B>& prod) {
    product_evaluator<A> lhs(prod.matrixl);
    product_evaluator<B> rhs(prod.matrixr);
    std::cout << "- performs: " << dest.m_name << " -= " << lhs.name() << " * " << rhs.name() + " in place\n";
    product_sub_impl_low_level(dest, lhs.m_mat, rhs.m_mat);
};

/// Matrix product evaluator, products are complex and must be evaluated into a temporary
/// unless the evaluator is by-passed by specializations of Assignment<>
template <typename A, typename B>
struct evaluator< Matrix_Product<A, B> > : evaluator< Dense_Matrix<Matrix_Product<A, B>::traits::RowsAtCompileTime, Matrix_Product<A, B>::traits::ColsAtCompileTime> > {
    
    typedef evaluator< Dense_Matrix<Matrix_Product<A, B>::traits::RowsAtCompileTime, Matrix_Product<A, B>::traits::ColsAtCompileTime> > Base;
    typedef evaluator type;
    
    evaluator(const Matrix_Product<A, B>& prod) : Base(mresult), mresult(std::string("product_res_of_\"") + prod.name() + "\"") {
        for(size_t i = 0; i < mresult.rows(); ++i){
            for(size_t j = 0; j < mresult.cols(); ++j){
                mresult(i, j) = value_type(0);
            }
        }
        
        product_impl(mresult, prod);
    }
    
    Dense_Matrix<A::traits::RowsAtCompileTime, B::traits::ColsAtCompileTime> mresult;
    
};

template <typename A>
struct evaluator<Eval_To_Temp<A>> : evaluator< Dense_Matrix<A::traits::RowsAtCompileTime, A::traits::ColsAtCompileTime> > {
  
    typedef evaluator<Dense_Matrix<A::traits::RowsAtCompileTime, A::traits::ColsAtCompileTime>> Base;
    typedef evaluator type;
    evaluator(const Eval_To_Temp<A>& a) : Base(mresult), mresult(std::string("temp_of_\"") + a.matrixl.name() + "\"") {
        mresult/*.noalias()*/ = a.matrixl;
    }
    Dense_Matrix<A::traits::RowsAtCompileTime, A::traits::ColsAtCompileTime> mresult;
};

// Generic assignment loop for dense evaluators.
template <typename A, typename B, typename Op>
void dense_assignment_loop(A& a, const B& b, const Op& op) {
    typename evaluator<A>::type ea(a);
    typename evaluator<B>::type eb(b);
    std::cout << "- dense assignment: " << a.name()  << op.name() << b.name()  << "\n";
    std::cout << "                as: " << ea.name() << op.name() << eb.name() << "\n";
    for(size_t i = 0; i < a.rows(); ++i){
        for(size_t j = 0; j < a.cols(); ++j){
            op.assign(ea(i, j), eb(i, j));
        }
    }
}

// self assignment loop for dense evaluators. Use for operations with constants
template <typename A, typename B, typename Op>
void self_assignment_loop(A& a, const B& b, const Op& op) {
    typename evaluator<A>::type ea(a);
    std::cout << "- self assignment: " << a.name()  << op.name() << b << "\n";
    std::cout << "                as: " << ea.name() << op.name() << b << "\n";
    for(size_t i = 0; i < a.rows(); ++i){
        for(size_t j = 0; j < a.cols(); ++j){
            op.assign(ea(i, j), b);
        }
    }
}

//-------------------
// --- Assignment ---
//-------------------

template<typename Dest, typename Src, typename Func>
void assign(Dest& dest, const Src& src, const Func& func) {
    Assignment<Dest, Src, Func>::run(dest, src, func);
}

template<typename A, typename B, typename Op>
struct Assignment {
    static void run(A& a, const B& b, const Op& op) {
        dense_assignment_loop(a, b, op);
    }
};

template<typename A>
struct Assignment<A, value_type, assign_mult<value_type>> {
    static void run(A& a, value_type b, const assign_mult<value_type>& op) {
        self_assignment_loop(a, b, op);
    }
};

// specialization for a = b * c (dense)
template<typename A, typename ProdLhs, typename ProdRhs>
struct Assignment<A, Matrix_Product<ProdLhs, ProdRhs>, assign_default<value_type>> {
    
    static void run(A& a, const Matrix_Product<ProdLhs, ProdRhs>& b, const assign_default<value_type>& ) {
        for(size_t i = 0; i < a.rows(); ++i){
            for(size_t j = 0; j < a.cols(); ++j){
                a(i, j) = value_type(0);
            }
        }
        
        product_impl(a, b);

    }
};

// specialization for a += b * c (dense)
template<typename A, typename ProdLhs, typename ProdRhs>
struct Assignment<A, Matrix_Product<ProdLhs, ProdRhs>, assign_add<value_type>> {
    static void run(A& a, const Matrix_Product<ProdLhs, ProdRhs>& b, const assign_add<value_type>& ) {
        product_impl(a, b);
    }
};

// specialization for a -= b * c (dense)
template<typename A, typename ProdLhs, typename ProdRhs>
struct Assignment< A, Matrix_Product<ProdLhs, ProdRhs>, assign_subtract<value_type> > {
    static void run(A& a, const Matrix_Product<ProdLhs, ProdRhs>& b, const assign_subtract<value_type>& ) {
        product_subtract_impl(a, b);
    }
};

// specialization for a = d + b * c (dense)
template<typename A, typename D, typename ProdLhs, typename ProdRhs, typename Op>
struct Assignment<A, Matrix_Sum<D, Matrix_Product<ProdLhs, ProdRhs> >, Op> {
    static void run(A& a, const Matrix_Sum<D, Matrix_Product<ProdLhs,ProdRhs> >& b, const Op& op) {
        Assignment<A, D, Op>::run(a, b.matrixl, op);
        Assignment<A, Matrix_Product<ProdLhs, ProdRhs>, assign_add<value_type> >::run(a, b.matrixr, assign_add<value_type>() );
    }
};

// specialization for a = d - b * c (dense)
template<typename A, typename D, typename ProdLhs, typename ProdRhs, typename Op>
struct Assignment<A, Matrix_Difference<D, Matrix_Product<ProdLhs, ProdRhs> >, Op> {
    static void run(A& a, const Matrix_Sum<D, Matrix_Product<ProdLhs,ProdRhs> >& b, const Op& op) {
        Assignment<A, D, Op>::run(a, b.matrixl, op);
        Assignment<A, Matrix_Product<ProdLhs, ProdRhs>, assign_subtract<value_type> >::run(a, b.matrixr, assign_subtract<value_type>() );
    }
};


// Default tree optimizer that copies the expression by value
template<typename MatXpr>
class Tree_Optimizer {
public:
    
    typedef MatXpr ReturnType;
    
    static ReturnType build(const MatXpr& mxpr) {
        return mxpr;
    }
};

// Tree optimizer for Dense_Matrix that copies by reference
template<size_t rows, size_t cols>
class Tree_Optimizer< Dense_Matrix<rows, cols> > {
public:
    
    typedef Dense_Matrix<rows, cols> ReturnType;
    
    static const ReturnType& build(const Dense_Matrix<rows, cols>& mxpr) { return mxpr; }
    
};

// Needed to forward the optimizer to the children
template<typename A, typename B>
class Tree_Optimizer< Matrix_Sum<A, B> > {
public:
    
    typedef Matrix_Sum<A, B> MatXpr;
    typedef typename Tree_Optimizer<A>::ReturnType NMatA;
    typedef typename Tree_Optimizer<B>::ReturnType NMatB;
    typedef Matrix_Sum<NMatA, NMatB> ReturnType;
    
    static ReturnType build(const MatXpr& mxpr) {
        return Tree_Optimizer<A>::build(mxpr.matrixl) + Tree_Optimizer<B>::build(mxpr.matrixr);
    }
    
};

// Needed to forward the optimizer to the children
template<typename A, typename B>
class Tree_Optimizer< Matrix_Difference<A, B> > {
public:
    
    typedef Matrix_Difference<A, B> MatXpr;
    typedef typename Tree_Optimizer<A>::ReturnType NMatA;
    typedef typename Tree_Optimizer<B>::ReturnType NMatB;
    typedef Matrix_Difference<NMatA, NMatB> ReturnType;
    
    static ReturnType build(const MatXpr& mxpr) {
        return Tree_Optimizer<A>::build(mxpr.matrixl) - Tree_Optimizer<B>::build(mxpr.matrixr);
    }
};

// Needed to forward the optimizer to the children
template<typename A, typename B>
class Tree_Optimizer< Matrix_Product<A, B> > {
public:
    
    typedef Matrix_Product<A, B> MatXpr;
    typedef typename Tree_Optimizer<A>::ReturnType NMatA;
    typedef typename Tree_Optimizer<B>::ReturnType NMatB;
    typedef Matrix_Product<NMatA, NMatB> ReturnType;
    
    static ReturnType build(const MatXpr& mxpr) {
        return Tree_Optimizer<A>::build(mxpr.matrixl) * Tree_Optimizer<B>::build(mxpr.matrixr);
    }
    
};


// catch A * B + C and builds C + A * B
template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Sum< Matrix_Product<A, B>, C> > {
public:
    
    typedef Matrix_Sum<Matrix_Product<A, B>, C> MatXpr;
    typedef typename Tree_Optimizer<C>::ReturnType NMatC;
    typedef Matrix_Sum<NMatC, Matrix_Product<A, B> > ReturnType;
    
    static ReturnType build(const MatXpr& mxpr) {
        return Tree_Optimizer<C>::build(mxpr.matrixr) + mxpr.matrixl;
    }
  
};

// catch C + A * B + D and builds (C + D) + (A * B)
template<typename A, typename B, typename C, typename D>
class Tree_Optimizer< Matrix_Sum< Matrix_Sum<C, Matrix_Product<A, B> >, D> > {
public:
    
    typedef Matrix_Sum< Matrix_Sum<C, Matrix_Product<A,B> >, D> MatXpr;
    typedef typename Tree_Optimizer<C>::ReturnType NMatC;
    typedef typename Tree_Optimizer<D>::ReturnType NMatD;
    typedef Matrix_Sum< Matrix_Sum<NMatC, NMatD>, Matrix_Product<A, B> > ReturnType;
  
    static ReturnType build(const MatXpr& mxpr) {
        return Tree_Optimizer<C>::build(mxpr.matrixl.matrixl) + Tree_Optimizer<D>::build(mxpr.matrixr) + mxpr.matrixl.matrixr;
    }
    
};

// catch A * B - C and builds -C + A * B
template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Difference< Matrix_Product<A, B>, C> > {
public:
    
    typedef Matrix_Difference<Matrix_Product<A, B>, C> MatXpr;
    typedef typename Tree_Optimizer<C>::ReturnType NMatC;
    typedef Matrix_Sum<NMatC, Matrix_Product<A, B> > ReturnType;
   
    static ReturnType build(const MatXpr& mxpr) {
        return Tree_Optimizer<C>::build( (mxpr.matrixr *= value_type(-1)) ) + mxpr.matrixl;
    }
    
};

// catch C + A * B - D and builds (C - D) + (A * B)
template<typename A, typename B, typename C, typename D>
class Tree_Optimizer< Matrix_Difference< Matrix_Sum<C, Matrix_Product<A, B> >, D> > {
public:
    
    typedef Matrix_Difference< Matrix_Sum<C, Matrix_Product<A,B> >, D> MatXpr;
    typedef typename Tree_Optimizer<C>::ReturnType NMatC;
    typedef typename Tree_Optimizer<D>::ReturnType NMatD;
    typedef Matrix_Sum< Matrix_Difference<NMatC, NMatD>, Matrix_Product<A, B> > ReturnType;
    
    static ReturnType build(const MatXpr& mxpr) {
        return (Tree_Optimizer<C>::build(mxpr.matrixl.matrixl) - Tree_Optimizer<D>::build(mxpr.matrixr)) + mxpr.matrixl.matrixr;
    }
    
};

// catch C - A * B + D and builds (C + D) - (A * B)
template<typename A, typename B, typename C, typename D>
class Tree_Optimizer< Matrix_Sum< Matrix_Difference<C, Matrix_Product<A, B> >, D> > {
public:
    
    typedef Matrix_Sum< Matrix_Difference<C, Matrix_Product<A, B> >, D> MatXpr;
    typedef typename Tree_Optimizer<C>::ReturnType NMatC;
    typedef typename Tree_Optimizer<D>::ReturnType NMatD;
    typedef Matrix_Difference< Matrix_Sum<NMatC, NMatD>, Matrix_Product<A, B> > ReturnType;
    
    static ReturnType build(const MatXpr& mxpr) {
        return Tree_Optimizer<C>::build(mxpr.matrixl.matrixl) + Tree_Optimizer<D>::build(mxpr.matrixr) - mxpr.matrixl.matrixr;
    }
    
};

// catch (A * B) * C and builds
// A * (B * C) if C is a vector
template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Product< Matrix_Product<A, B>, C> > {
public:

    typedef Matrix_Product< Matrix_Product<A, B>, C> MatXpr;
    typedef typename Tree_Optimizer<C>::ReturnType NMatC;
    typedef Matrix_Product< A, Matrix_Product<B, C> > ReturnType;
    
    static ReturnType build(const MatXpr& mxpr) {
        return Tree_Optimizer<A>::build(mxpr.matrixl.matrixl) * (Tree_Optimizer<B>::build(mxpr.matrixl.matrixr) * Tree_Optimizer<C>::build(mxpr.matrixr));
    }
    
};



template<size_t, typename, typename> struct expression_types1;

template<typename MatXpr, typename BaseXpr>
struct expression_types1<0, MatXpr, BaseXpr> : mpl::vector< BaseXpr > {};

template<size_t N, typename MatXpr, typename BaseXpr>
struct expression_types1 :
mpl::eval_if<
mpl::less< mpl::size_t< Tree_Optimizer<MatXpr>::ReturnType::Op_Cost >,
mpl::size_t< MatXpr::Op_Cost > > ,
mpl::push_back< typename expression_types1< N - 1, typename Tree_Optimizer<MatXpr>::ReturnType, BaseXpr >::type,
typename Tree_Optimizer< typename mpl::back< typename expression_types1< N - 1, typename Tree_Optimizer<MatXpr>::ReturnType, BaseXpr >::type >::type >::ReturnType >,
typename expression_types1< 0, typename Tree_Optimizer<MatXpr>::ReturnType, BaseXpr >::type > {};

template<size_t, typename> struct expression_types2;

template<typename MatXpr>
struct expression_types2<0, MatXpr> : mpl::vector< MatXpr > {};

template<size_t N, typename MatXpr>
struct expression_types2 :
mpl::push_back< typename expression_types2< N - 1, MatXpr >::type,
typename Tree_Optimizer< typename mpl::back< typename expression_types2< N - 1, MatXpr >::type >::type >::ReturnType > {};


template<size_t, typename, typename> struct expression_types;

template<typename i, typename MatXpr>
struct expression_types<0, i, MatXpr> : mpl::vector< MatXpr > {};

template<size_t N, typename i, typename MatXpr>
struct expression_types :
mpl::push_back< typename expression_types< N - 1, typename mpl::next<i>::type, MatXpr >::type,
typename Tree_Optimizer< typename mpl::back< typename expression_types< N - 1, typename mpl::next<i>::type, MatXpr >::type>::type >::ReturnType > {};


struct print {
    template<typename T>
    void operator()(mpl::identity<T>){
        std::cout << typeid(T).name() << "\n";
    }
};

template <typename xpr1, typename... Arguments>
class Optimize {
    
public:
    static const int size = sizeof... (Arguments);
    
    typedef typename mpl::vector< xpr1, Arguments... >::type expressions;
    
    template <size_t index>
    struct fn {
        
        typename mpl::at_c<expressions, index + 1>::type operator() (const typename mpl::at_c<expressions, index>::type& matxpr) const {
            return Tree_Optimizer<typename mpl::at_c<expressions, index>::type>::build(matxpr);
        }
        
    };
    
    template <size_t First, size_t Last, size_t Difference>
    struct static_for {
        template <typename Fn, typename MatXpr>
        typename mpl::at_c<expressions, size>::type operator()(Fn const& func, const MatXpr& xpr) const {
            auto nxpr = func(xpr);
            return static_for<First + 1, Last, Difference - 1>()(fn<First + 1>(), nxpr);
        }
    };
    
    template <size_t First, size_t Last>
    struct static_for<First, Last, 1> {
        template <typename Fn, typename MatXpr>
        auto operator()(Fn const& func, const MatXpr& xpr) -> decltype(func(xpr)) {
            return func(xpr);
        }
    };
    
    static typename mpl::at_c<expressions, size>::type optimize(const xpr1& matxpr) {
        return static_for<0, size, size>()(fn<0>(), matxpr);
    }
    
};

namespace impl {
    
    template <typename F, typename L>
    struct exit : boost::mpl::equal_to<
    typename boost::mpl::distance<F, L>::type,
    boost::mpl::int_<0> > {};
    
    template <typename F, typename L, bool exit, typename ...Args>
    struct to_variadic {
        typedef typename boost::mpl::deref<F>::type front_;
        typedef typename boost::mpl::next<F>::type next_;
        typedef typename impl::exit<next_, L>::type exit_;
        typedef typename to_variadic<next_, L,
        exit_::value, front_, Args...>::type type;
    };
    
    template <typename F, typename L, typename ...Args>
    struct to_variadic<F, L, true, Args...>{
        typedef Optimize<Args...> type;
    };
    
    template <typename Seq>
    struct seq_traits{
        typedef typename boost::mpl::begin<Seq>::type first_;
        typedef typename boost::mpl::end<Seq>::type last_;
        typedef typename impl::exit<first_, last_>::type exit_;
    };
    
}//impl

template<typename Seq>
struct to_variadic{
    typedef typename boost::mpl::reverse<
    Seq>::type reversed_;
    typedef typename impl::to_variadic<
    typename impl::seq_traits<reversed_>::first_,
    typename impl::seq_traits<reversed_>::last_,
    impl::seq_traits<Seq>::exit_::value
    >::type type;
};



int main(){
    
	Matrix4d A("A"), B("B"), C("C"), D("D");
    Vector4d a("a"), b("b"), c("c"), d("d");
    std::cout << "\n";

    std::cout << "D = A * B + C; \n";
    D = A * B + C;
    std::cout << "\n";
    
    std::cout << "D = C + A * B; \n";
    D = C + A * B;
    std::cout << "\n\n";
    
    auto xpr = A * B + C;
    std::cout << "before name: " << xpr.name() << "\n";
    typedef expression_types2< 5, decltype(xpr) >::type sequence;
    std::cout << "sequence size = " << mpl::size<sequence>::value << "\n";
    boost::mpl::for_each<sequence, boost::mpl::make_identity<> > (print());
    std::cout << "\n\n";
    
    typedef to_variadic< sequence >::type tree_optimizer;
    auto result = tree_optimizer::optimize(xpr);
    std::cout << "after name: " << result.name() << "\n";
    std::cout << "result? " << typeid(result).name() << "\n";

    std::cout << "\n\n";
    auto xpr2 = A * B + C;
    std::cout << "before name: " << xpr2.name() << "\n";
    typedef expression_types1< 5, decltype(xpr2), decltype(xpr2) >::type test;
    std::cout << "test size = " << mpl::size<test>::value << "\n";
    boost::mpl::for_each<test, boost::mpl::make_identity<> > (print());
    std::cout << "\n\n";
    
    typedef to_variadic< test >::type tree_optimizer2;
    auto result2 = tree_optimizer2::optimize(xpr2);
    std::cout << "after name: " << result2.name() << "\n";
    std::cout << "result? " << typeid(result2).name() << "\n";

    std::cout << "\n" << "Is the cost minimized? " << "\n";
    std::cout << (A * B + C).name() << " -> " << (C + A * B).name() << "\n\n";
    std::cout << decltype(A * B + C)::Op_Cost << " " << decltype(C + A * B)::Op_Cost << "\n\n";

    auto xpr3 = A * B + C + D;
    std::cout << "before name: " << xpr3.name() << "\n";
    typedef expression_types2< 5, decltype(xpr3) >::type sequence2;
    std::cout << "sequence size = " << mpl::size<sequence2>::value << "\n";
    boost::mpl::for_each<sequence2, boost::mpl::make_identity<> > (print());
    std::cout << "\n\n";
    
    typedef to_variadic< sequence2 >::type tree_optimizer3;
    auto result3 = tree_optimizer3::optimize(xpr3);
    std::cout << "after name: " << result3.name() << "\n";
    std::cout << "result? " << typeid(result3).name() << "\n";

    std::cout << "\n\n";
    auto xpr4 = A * B + C + D;
    std::cout << "before name: " << xpr4.name() << "\n";
    typedef expression_types1< 5, decltype(xpr4), decltype(xpr4) >::type test2;
    std::cout << "test size = " << mpl::size<test2>::value << "\n";
    boost::mpl::for_each<test2, boost::mpl::make_identity<> > (print());
    std::cout << "\n\n";
    
    typedef to_variadic< test2 >::type tree_optimizer4;
    auto result4 = tree_optimizer4::optimize(xpr4);
    std::cout << "after name: " << result4.name() << "\n";
    std::cout << "result? " << typeid(result4).name() << "\n";

    std::cout << "\n" << "Is the cost minimized? " << "\n";
    std::cout << (A * B + C + D).name() << " -> " << (D + A * B + C).name() << " -> " << (C + D + A * B).name() << "\n\n";
    std::cout << decltype(A * B + C + D)::Op_Cost << " " << decltype(D + A * B + C)::Op_Cost << " " << decltype(C + D + A * B)::Op_Cost << "\n\n";

    auto xpr5 = A * B + C - D;
    std::cout << "before name: " << xpr5.name() << "\n";
    Tree_Optimizer<decltype(xpr5)>::ReturnType result5 = Tree_Optimizer<decltype(xpr5)>::build(xpr5);
    std::cout << "after name: " << result5.name() << "\n";
    
    std::cout << "\n" << "Is the cost minimized? " << "\n";
    std::cout << decltype(A * B + C - D)::Op_Cost << " " << decltype(C + A * B - D)::Op_Cost << " " << decltype(C - D + A * B)::Op_Cost << "\n\n";

    std::cout << "D = A * B * C; \n";
    D = A * B * C;
    std::cout << "\n";
    
    std::cout << "D = A * (B * C); \n";
    D = A * (B * C);
    std::cout << "\n\n";

    auto xpr6 = A * B * C;
    std::cout << "before name: " << xpr6.name() << "\n";
    Tree_Optimizer<decltype(xpr6)>::ReturnType result6 = Tree_Optimizer<decltype(xpr6)>::build(xpr6);
    std::cout << "after name: " << result6.name() << "\n";
    std::cout << "\n" << "Is the cost minimized? " << "\n";
    std::cout << decltype(A * B * C)::Op_Cost << " " << decltype(A * (B * C))::Op_Cost << "\n\n";
    
    std::cout << "before name: " << xpr6.name() << "\n";
    typedef expression_types1< 5, decltype(xpr6), decltype(xpr6) >::type test4;
    std::cout << "test size = " << mpl::size<test4>::value << "\n";
    boost::mpl::for_each<test4, boost::mpl::make_identity<> > (print());
    std::cout << "\n\n";
    
    typedef to_variadic< test4 >::type tree_optimizer5;
    auto result7 = tree_optimizer5::optimize(xpr6);
    std::cout << "after name: " << result7.name() << "\n";
    std::cout << "result? " << typeid(result7).name() << "\n\n";
 
    B = A * -1.0;
    A *= -1.0;
    A.transpose_in_place();
    
    std::cout << "\n\n";
    std::cout << "Testing a complicated expression.. \n";
    auto mxpr = A * B + C - D + A * C + D - A + A;
    
    typedef decltype(mxpr) Xpr;
    std::cout << "init version:";
    std::cout << " " << mxpr.name() << "\n";
    std::cout << "cost " << mxpr.Op_Cost << "\n";
    
    Tree_Optimizer<Xpr>::ReturnType mxpr1 = Tree_Optimizer<Xpr>::build(mxpr);
    typedef decltype(mxpr1) Xpr1;
    std::cout << std::endl << "optimized version 1:";
    std::cout << " " << mxpr1.name() << std::endl;
    std::cout << "cost " << mxpr1.Op_Cost << std::endl;
    
    Tree_Optimizer<Xpr1>::ReturnType mxpr2 = Tree_Optimizer<Xpr1>::build(mxpr1);
    typedef decltype(mxpr2) Xpr2;
    std::cout << std::endl << "optimized version 2:";
    std::cout << " " << mxpr2.name() << std::endl;
    std::cout << "cost " << mxpr2.Op_Cost << std::endl;
    
    Tree_Optimizer<Xpr2>::ReturnType mxpr3 = Tree_Optimizer<Xpr2>::build(mxpr2);
    typedef decltype(mxpr3) Xpr3;
    std::cout << std::endl << "optimized version 3:";
    std::cout << " " << mxpr3.name() << std::endl;
    std::cout << "cost " << mxpr3.Op_Cost << std::endl;

 	return 0;
}