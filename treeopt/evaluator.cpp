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


// #include "alignment_trait.hpp"

using namespace boost;

typedef double value_type; // simplifying things with the templates

//-----------------------
// forward declarations
//-----------------------
template <typename MatXpr>
class Matrix_Expression;

template <size_t rows, size_t cols>
class Dense_Matrix;

template <typename MatrixL, typename MatrixR>
class Matrix_Sum;

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

template <typename xpr1, typename... Arguments>
class Optimize;

template<typename Dest, typename Src, typename Func>
void assign(Dest& dest, const Src& src, const Func& func);
//--------------------------
// end foward declarations
//--------------------------

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
    Matrix_Product<MatXpr, Other> operator*(const Matrix_Expression<Other>& other) const {
        return Matrix_Product<MatXpr, Other> (matxpr(), other.matxpr());
    }

    template<typename Other> MatXpr& operator=(const Matrix_Expression<Other>& other) {
        assign(matxpr(), Tree_Optimizer<Other>::build(other.matxpr()).matxpr(), assign_default<value_type>());
       // assign(matxpr(), other.matxpr(), assign_default<value_type>());
        return matxpr();
    }
    
    template<typename Other> MatXpr& operator+=(const Matrix_Expression<Other>& other) {
        assign(matxpr(), other.matxpr(), assign_add<value_type>());
        return matxpr();
    }
    
};

//Dense matrix class that extends the base class
template <size_t Rows, size_t Cols>
class Dense_Matrix : public Matrix_Expression< Dense_Matrix<Rows, Cols> > {
    
public:
    
    typedef typename std::vector< std::vector<value_type> > storage_type;
    using Matrix_Expression< Dense_Matrix<Rows, Cols> >::operator=;
    
    enum traits {
        RowsAtCompileTime = Rows,
        ColsAtCompileTime = Cols,
    };

    Dense_Matrix(const std::string& name) : m_name(name), _rows(Rows), _cols(Cols) {
        std::vector<value_type> row(_cols);
        _data.resize(_rows, row);
        if(_rows == 1 || _cols == 1){
            std::cout << "- Create vector " << m_name << std::endl;
        }
        else { std::cout << "- Create matrix " << m_name << std::endl; }
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
    };
 
    explicit Matrix_Sum(const Matrix_Expression<MatrixL>& ml, const Matrix_Expression<MatrixR>& mr) : matrixl(ml), matrixr(mr) {}
    
    std::string name() const { return std::string("(") + matrixl.name() + " + " + matrixr.name() + ")"; }

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
    };
 
    explicit Matrix_Product(const Matrix_Expression<MatrixL>& ml, const Matrix_Expression<MatrixR>& mr) : matrixl(ml), matrixr(mr) {}
    
    std::string name() const { return std::string("(") + matrixl.name() + " * " + matrixr.name() + ")"; }
    
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

// evaluator of A + B
template<typename A, typename B>
struct evaluator<Matrix_Sum<A, B>> {
    
    typedef evaluator type;
    evaluator(const Matrix_Sum<A, B>& plus) : matrixl(plus.matrixl), matrixr(plus.matrixr) {}
    inline const value_type operator()(size_t i, size_t j) const { return matrixl(i, j) + matrixr(i, j); }
    typename evaluator<A>::type matrixl;
    typename evaluator<B>::type matrixr;
    
    std::string name() const { return std::string("(") + matrixl.name() + " + " + matrixr.name() + ")"; }
    
};

/// low level product implementation (c += a*b) - like blas's gemm
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

// special product evaluator (in Eigen it is currently equivalent to blas_traits)
template <typename MatXpr>
struct product_evaluator {
    product_evaluator(const MatXpr& x) : m_mat("product_arg_temporary_of_\"" + x.name() + "\"") {
        m_mat = x;
    }
    std::string name() const { return m_mat.m_name; }
    MatXpr m_mat;
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

/// Matrix product evaluator, products are complex and must be evaluated into a temporary
/// unless the evaluator is by-passed by specializations of Assignment<>
template <typename A, typename B>
struct evaluator< Matrix_Product<A, B> > : evaluator<Dense_Matrix<Matrix_Product<A, B>::traits::RowsAtCompileTime, Matrix_Product<A, B>::traits::ColsAtCompileTime>> {
    
    typedef evaluator<Dense_Matrix<Matrix_Product<A, B>::traits::RowsAtCompileTime, Matrix_Product<A, B>::traits::ColsAtCompileTime>> Base;
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
struct evaluator<Eval_To_Temp<A>> : evaluator<Dense_Matrix<A::traits::RowsAtCompileTime, A::traits::ColsAtCompileTime>> {
  
    typedef evaluator<Dense_Matrix<A::traits::RowsAtCompileTime, A::traits::ColsAtCompileTime>> Base;
    typedef evaluator type;
    evaluator(const Eval_To_Temp<A>& a) : Base(mresult), mresult(std::string("temp_of_\"") + a.matrixl.name() + "\"") {
        mresult/*.noalias()*/ = a.matrixl;
    }
    Dense_Matrix<A::traits::RowsAtCompileTime, A::traits::ColsAtCompileTime> mresult;
};

// Generic assignment loop for dense evaluators.
// In Eigen it is split in many more variants to deal with unrolling and vectorization
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



//-------------------
// --- Assignment ---
//-------------------

template<typename Dest, typename Src, typename Func>
void assign(Dest& dest, const Src& src, const Func& func) {
    Assignment<Dest, Src, Func>::run(dest, src, func);
}


template<typename A, typename B, typename Op>
struct Assignment {
    static void run(A& a, const B& b, const Op& op) { std::cout << "1 " << std::endl;
        dense_assignment_loop(a, b, op);
    }
};

// specialization for a = b * c (dense)
template<typename A, typename ProdLhs, typename ProdRhs>
struct Assignment<A, Matrix_Product<ProdLhs, ProdRhs>, assign_default<value_type>> {
    static void run(A& a, const Matrix_Product<ProdLhs, ProdRhs>& b, const assign_default<value_type>& ) { std::cout << "2 " << std::endl;
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
struct Assignment<A, Matrix_Product<ProdLhs,ProdRhs>, assign_add<value_type>> {
    static void run(A& a, const Matrix_Product<ProdLhs, ProdRhs>& b, const assign_add<value_type>& ) { std::cout << "3 " << std::endl;
        product_impl(a, b);
    }
};

// specialization for a = d + b * c (dense)
template<typename A, typename D, typename ProdLhs, typename ProdRhs, typename Op>
struct Assignment<A, Matrix_Sum<D, Matrix_Product<ProdLhs, ProdRhs> >, Op> {
    static void run(A& a, const Matrix_Sum<D, Matrix_Product<ProdLhs,ProdRhs> >& b, const Op& op) { std::cout << "4 " << std::endl;
        Assignment<A, D, Op>::run(a, b.matrixl, op);
        Assignment<A, Matrix_Product<ProdLhs, ProdRhs>, assign_add<value_type> >::run(a, b.matrixr, assign_add<value_type>() );
    }
};


// Default tree optimizer that copies the expression by value
template<typename MatXpr>
class Tree_Optimizer {
public:
    /*
    enum {
        Cost = MatXpr::costs::Op_Cost
    };
    */
    typedef MatXpr ReturnType;
    
    static ReturnType build(const MatXpr& mxpr) {
        return mxpr;
    }
};

// Tree optimizer for Dense_Matrix that copies by reference
template<size_t rows, size_t cols>
class Tree_Optimizer< Dense_Matrix<rows, cols> > {
public:
    /*
    enum {
        Cost = Dense_Matrix<rows, cols>::costs::Op_Cost
    };
    */
    typedef Dense_Matrix<rows, cols> ReturnType;
    
    static const ReturnType& build(const Dense_Matrix<rows, cols>& mxpr) { return mxpr; }
    
};

// Needed to forward the optimizer to the children
template<typename A, typename B>
class Tree_Optimizer< Matrix_Sum<A, B> > {
public:
    /*
    enum {
        Cost = Matrix_Sum<A, B>::costs::Op_Cost
    };
    */
    typedef Matrix_Sum<A, B> MatXpr;
    typedef typename Tree_Optimizer<A>::ReturnType NMatA;
    typedef typename Tree_Optimizer<B>::ReturnType NMatB;
    typedef Matrix_Sum<NMatB, NMatA> NMatXpr;
    typedef Matrix_Sum<NMatA, NMatB> ReturnType;
    /*
    typedef typename mpl::if_< typename mpl::less< mpl::size_t< NMatXpr::Op_Cost >,
    mpl::size_t< MatXpr::Op_Cost > >::type,
    NMatXpr, MatXpr >::type ReturnType;
    */
    static ReturnType build(const MatXpr& mxpr) {
        return Tree_Optimizer<A>::build(mxpr.matrixl) + Tree_Optimizer<B>::build(mxpr.matrixr);
    }
    
};

// catch A * B + C and builds C + A * B
template<typename A, typename B, typename C>
class Tree_Optimizer< Matrix_Sum< Matrix_Product<A, B>, C> > {
public:
    /*
    enum {
        Cost = Matrix_Sum< Matrix_Product<A, B>, C>::costs::Op_Cost
    };
    */
    typedef Matrix_Sum<Matrix_Product<A, B>, C> MatXpr;
    typedef typename Tree_Optimizer<C>::ReturnType NMatC;
    typedef Matrix_Sum<NMatC, Matrix_Product<A, B> > NMatXpr;
    typedef Matrix_Sum<NMatC, Matrix_Product<A, B> > ReturnType;
    /*
    typedef typename mpl::if_< typename mpl::less< mpl::size_t< NMatXpr::Op_Cost >,
    mpl::size_t< MatXpr::Op_Cost > >::type,
    NMatXpr, MatXpr >::type ReturnType;
    */
    static ReturnType build(const MatXpr& mxpr) {
        return Tree_Optimizer<C>::build(mxpr.matrixr) + mxpr.matrixl;
    }
  
};

template<size_t, typename, typename> struct expression_types;

template<typename i, typename MatXpr>
struct expression_types<0, i, MatXpr> : mpl::vector< MatXpr > {};

template<size_t N, typename i, typename MatXpr>
struct expression_types :
mpl::push_back< typename expression_types< N - 1, typename mpl::next<i>::type, MatXpr >::type,
typename Tree_Optimizer< typename mpl::back< typename expression_types< N - 1, typename mpl::next<i>::type, MatXpr >::type>::type >::ReturnType > {};

struct print {
    template<typename T>
    void operator()(boost::mpl::identity<T>){
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
    std::cout << "\n";
    
    typedef expression_types< 5, mpl::size_t<0>, decltype(A * B + C) >::type sequence;
    std::cout << "sequence size = " << mpl::size<sequence>::value << "\n";
    boost::mpl::for_each<sequence, boost::mpl::make_identity<> > (print());
    std::cout << "\n\n";
  
    auto xpr = A * B + C;
    typedef to_variadic< sequence >::type tree_optimizer;
    auto result = tree_optimizer::optimize(xpr);
    std::cout << "result? " << typeid(result).name() << "\n";
    
 	return 0;
}