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

#ifndef TREE_OPTIMIZER_HPP
#define TREE_OPTIMIZER_HPP

#include <boost/numeric/ublas/expression_types.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>
#include <boost/numeric/ublas/functional.hpp>

namespace boost { namespace numeric { namespace ublas {
    
    /*
        Start with the tree optimizer classes.
    */
    
    // These are some convenience typedefs to simply the construction of partial specializations in the tree optimizer classes.
    // Otherwise things get confusing very quickly!
    template <typename A, typename B>
    using dmatrix_sum = matrix_matrix_binary<A, B, dmatdmatsum<A, B>>;
    template <typename A, typename B>
    using dmatrix_difference = matrix_matrix_binary<A, B, dmatdmatsub<A, B>>;
    template <typename A, typename B>
    using dmatrix_product = general_product<A, B, dmatdmatprod<A, B>>;

    // Default tree optimizer that copies the expression by value
    template <typename A>
    class tree_optimizer {
        
    public:
        typedef A ReturnType;
        
        enum {
            treechanges = 0,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const A& mxpr) {
            return mxpr;
        }
        
    };
    
    // Tree optimizer for matrix that copies by reference
    // T the type of object stored in the matrix (like double, float, complex, etc...)
    // L the storage organization. It can be either row_major or column_major. Default is row_major
    // A the type of Storage array. Default is \c unbounded_array
    template <typename T, typename L, typename A>
    class tree_optimizer< matrix<T, L, A> > {
        
    public:
        typedef matrix<T, L, A> ReturnType;
        
        enum {
            treechanges = 0,
        };
        
        static BOOST_UBLAS_INLINE
        const ReturnType& build(const matrix<T, L, A>& mxpr) {
            return mxpr;
        }
        
    };
    
    // Tree optimizer for static_matrix that copies by reference
    // T the type of object stored in the matrix (like double, float, complex, etc...)
    // M the number of rows
    // N the number of columns
    // L the storage organization. It can be either row_major or column_major. Default is row_major
    template <typename T, std::size_t M, std::size_t N, typename L>
    class tree_optimizer< static_matrix<T, M, N, L> > {
        
    public:
        typedef static_matrix<T, M, N, L> ReturnType;
        
        enum {
            treechanges = 0,
        };
        
        static BOOST_UBLAS_INLINE
        const ReturnType& build(const static_matrix<T, M, N, L>& mxpr) {
            return mxpr;
        }
        
    };
    
    // Needed to forward the optimizer to the children
    template <typename A, typename B>
    class tree_optimizer< dmatrix_sum<A, B> > {
        
    private:
        typedef dmatrix_sum<A, B> MatXpr;
        typedef typename tree_optimizer<A>::ReturnType New_A;
        typedef typename tree_optimizer<B>::ReturnType New_B;
        
    public:
        typedef dmatrix_sum<New_A, New_B> ReturnType;
        
        enum {
            treechanges = tree_optimizer<A>::treechanges || tree_optimizer<B>::treechanges,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return tree_optimizer<A>::build( mxpr.expression1() ) + tree_optimizer<B>::build( mxpr.expression2() );
        }
        
    };
    
    // Needed to forward the optimizer to the children
    template <typename A, typename B>
    class tree_optimizer< dmatrix_difference<A, B> > {
        
    private:
        typedef dmatrix_difference<A, B> MatXpr;
        typedef typename tree_optimizer<A>::ReturnType New_A;
        typedef typename tree_optimizer<B>::ReturnType New_B;
        
    public:
        typedef dmatrix_difference<New_A, New_B> ReturnType;
        
        enum {
            treechanges = tree_optimizer<A>::treechanges || tree_optimizer<B>::treechanges,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return tree_optimizer<A>::build( mxpr.expression1() ) - tree_optimizer<B>::build( mxpr.expression2() );
        }
        
    };
    
    // Needed to forward the optimizer to the children
    template <typename A, typename B>
    class tree_optimizer< dmatrix_product<A, B> > {
        
    private:
        typedef dmatrix_product<A, B> MatXpr;
        typedef typename tree_optimizer<A>::ReturnType New_A;
        typedef typename tree_optimizer<B>::ReturnType New_B;
        
    public:
        typedef dmatrix_product<New_A, New_B> ReturnType;
        
        enum {
            treechanges = tree_optimizer<A>::treechanges || tree_optimizer<B>::treechanges,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return tree_optimizer<A>::build( mxpr.expression1() ) * tree_optimizer<B>::build( mxpr.expression2() );
        }
        
    };

    // catch A * B + C and builds C + A * B
    template <typename A, typename B, typename C>
    class tree_optimizer< dmatrix_sum< dmatrix_product<A, B>, C> > {
        
    private:
        typedef dmatrix_sum <dmatrix_product<A, B>, C> MatXpr;
        typedef typename tree_optimizer<C>::ReturnType New_C;
        
    public:
        typedef dmatrix_sum <New_C, dmatrix_product<A, B>> ReturnType;
        
        enum {
            treechanges = 1,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return tree_optimizer<C>::build( mxpr.expression2() ) + mxpr.expression1();
        }
        
    };
    
    // catch C + A * B + D and builds (C + D) + (A * B)
    template <typename A, typename B, typename C, typename D>
    class tree_optimizer< dmatrix_sum< dmatrix_sum< C, dmatrix_product<A, B> >, D > > {
        
    private:
        typedef dmatrix_sum< dmatrix_sum< C, dmatrix_product<A, B> >, D > MatXpr;
        typedef typename tree_optimizer<C>::ReturnType New_C;
        typedef typename tree_optimizer<D>::ReturnType New_D;
        
    public:
        typedef dmatrix_sum< dmatrix_sum< New_C, New_D>, dmatrix_product<A, B> > ReturnType;
        
        enum {
            treechanges = 1,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return tree_optimizer<C>::build( mxpr.expression1().expression1() ) + tree_optimizer<D>::build( mxpr.expression2() ) + mxpr.expression1().expression2();
        }
        
    };

    // catch C + (A * B) + (D * E) and builds C + (A * B) + (D * E)
    template <typename A, typename B, typename C, typename D, typename E>
    class tree_optimizer< dmatrix_sum< dmatrix_sum< C, dmatrix_product<A, B> >, dmatrix_product<D, E> > > {
        
    private:
        typedef dmatrix_sum< dmatrix_sum< C, dmatrix_product<A, B> >, dmatrix_product<D, E> > MatXpr;
        typedef typename tree_optimizer<C>::ReturnType New_C;
        
    public:
        typedef dmatrix_sum< dmatrix_sum< New_C, dmatrix_product<A, B> >, dmatrix_product<D, E> > ReturnType;
        
        enum {
            treechanges = tree_optimizer<A>::treechanges || tree_optimizer<B>::treechanges
            || tree_optimizer<C>::treechanges || tree_optimizer<D>::treechanges
            || tree_optimizer<E>::treechanges,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return tree_optimizer<C>::build(mxpr.expression1().expression1()) + mxpr.expression1().expression2() + mxpr.expression2();
        }
        
    };
    
    // catch C + (A * B) - (D * E) and builds C + (A * B) - (D * E)
    template <typename A, typename B, typename C, typename D, typename E>
    class tree_optimizer< dmatrix_difference< dmatrix_sum<C, dmatrix_product<A, B> >, dmatrix_product<D, E> > > {
        
    private:
        typedef dmatrix_difference< dmatrix_sum<C, dmatrix_product<A, B> >, dmatrix_product<D, E> > MatXpr;
        typedef typename tree_optimizer<C>::ReturnType New_C;
        
    public:
        typedef dmatrix_difference< dmatrix_sum<New_C, dmatrix_product<A, B> >, dmatrix_product<D, E> > ReturnType;
        
        enum {
            treechanges = tree_optimizer<A>::treechanges || tree_optimizer<B>::treechanges
            || tree_optimizer<C>::treechanges || tree_optimizer<D>::treechanges
            || tree_optimizer<E>::treechanges,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return tree_optimizer<C>::build(mxpr.expression1().expression1()) + mxpr.expression1().expression2() - mxpr.expression2();
        }
        
    };
    
    // catch (A * B) + C + D and builds (C + D) + (A * B)
    template <typename A, typename B, typename C, typename D>
    class tree_optimizer< dmatrix_sum< dmatrix_sum< dmatrix_product<A, B>, C>, D> > {
        
    private:
        typedef dmatrix_sum< dmatrix_sum< dmatrix_product<A, B>, C>, D> MatXpr;
        typedef typename tree_optimizer<C>::ReturnType New_C;
        typedef typename tree_optimizer<D>::ReturnType New_D;
        
    public:
        typedef dmatrix_sum<dmatrix_sum<New_C, New_D>, dmatrix_product<A, B> > ReturnType;
        
        enum {
            treechanges = 1,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return tree_optimizer<C>::build(mxpr.expression1().expression2()) + tree_optimizer<D>::build(mxpr.expression2()) + tree_optimizer<dmatrix_product<A, B>>::build(mxpr.expression1().expression1());
        }
    };
    
    // catch A * B - C and builds -C + A * B
    template <typename A, typename B, typename C>
    class tree_optimizer< dmatrix_difference< dmatrix_product<A, B>, C> > {
        
    private:
        typedef dmatrix_difference<dmatrix_product<A, B>, C> MatXpr;
        typedef typename tree_optimizer<C>::ReturnType New_C;
        
    public:
        typedef dmatrix_sum<New_C, dmatrix_product<A, B> > ReturnType;
        
        enum {
            treechanges = 1,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return tree_optimizer<C>::build( (mxpr.expression2() *= C::value_type(-1)) ) + mxpr.expression1();
        }
        
    };
    
    // catch C + A * B - D and builds (C - D) + (A * B)
    template <typename A, typename B, typename C, typename D>
    class tree_optimizer< dmatrix_difference< dmatrix_sum<C, dmatrix_product<A, B> >, D> > {
        
    private:
        typedef dmatrix_difference< dmatrix_sum<C, dmatrix_product<A, B> >, D> MatXpr;
        typedef typename tree_optimizer<C>::ReturnType New_C;
        typedef typename tree_optimizer<D>::ReturnType New_D;
        
    public:
        typedef dmatrix_sum< dmatrix_difference<New_C, New_D>, dmatrix_product<A, B> > ReturnType;
        
        enum {
            treechanges = 1,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return (tree_optimizer<C>::build(mxpr.expression1().expression1()) - tree_optimizer<D>::build(mxpr.expression2())) + mxpr.expression1().expression2();
        }
        
    };
    
    // catch C - A * B + D and builds (C + D) - (A * B)
    template <typename A, typename B, typename C, typename D>
    class tree_optimizer< dmatrix_sum< dmatrix_difference<C, dmatrix_product<A, B> >, D> > {
        
    private:
        typedef dmatrix_sum< dmatrix_difference<C, dmatrix_product<A, B> >, D> MatXpr;
        typedef typename tree_optimizer<C>::ReturnType New_C;
        typedef typename tree_optimizer<D>::ReturnType New_D;
        
    public:
        typedef dmatrix_difference< dmatrix_sum<New_C, New_D>, dmatrix_product<A, B> > ReturnType;
        
        enum {
            treechanges = 1,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return tree_optimizer<C>::build(mxpr.expression1().expression1()) + tree_optimizer<D>::build(mxpr.expression2()) - mxpr.expression1().expression2();
        }
        
    };

    // catch (A * B) * C and builds A * (B * C)
    template <typename A, typename B, typename C>
    class tree_optimizer< dmatrix_product< dmatrix_product<A, B>, C> > {
        
    private:
        typedef dmatrix_product< dmatrix_product<A, B>, C> MatXpr;
        typedef typename tree_optimizer<C>::ReturnType New_C;
        
    public:
        typedef dmatrix_product< A, dmatrix_product<B, New_C> > ReturnType;
        
        enum {
            treechanges = 1,
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return tree_optimizer<A>::build(mxpr.expression1().expression1()) * (tree_optimizer<B>::build(mxpr.expression1().expression2()) * tree_optimizer<C>::build(mxpr.expression2()));
        }
        
    };
    
    // catch (A * B) + (C * D) and builds (A * B) + (C * D)
    template <typename A, typename B, typename C, typename D>
    class tree_optimizer< dmatrix_sum< dmatrix_product<A, B>, dmatrix_product<C, D> > > {
        
    private:
        typedef dmatrix_sum< dmatrix_product<A, B>, dmatrix_product<C, D> > MatXpr;
        typedef typename tree_optimizer<A>::ReturnType New_A;
        typedef typename tree_optimizer<B>::ReturnType New_B;
        typedef typename tree_optimizer<C>::ReturnType New_C;
        typedef typename tree_optimizer<D>::ReturnType New_D;
        
    public:
        typedef dmatrix_sum< dmatrix_product<New_A, New_B>, dmatrix_product<New_C, New_D> > ReturnType;
        
        enum {
            treechanges = 0
        };
        
        static BOOST_UBLAS_INLINE
        ReturnType build(const MatXpr& mxpr) {
            return tree_optimizer<dmatrix_product<A, B>>::build(mxpr.expression1()) + tree_optimizer<dmatrix_product<C, D>>::build(mxpr.expression2());
        }
        
    };
    
    /*
        This is used for the construction of the type vector used for the tree optimizer and Optimize class
    */
    
    // base case
    template<typename MatXpr, typename BaseXpr>
    struct expression_types<0, MatXpr, BaseXpr> : mpl::vector< BaseXpr > {};
    
    template<size_t N, typename MatXpr, typename BaseXpr>
    struct expression_types :
    mpl::eval_if<
    mpl::and_<
    mpl::equal_to< mpl::size_t< tree_optimizer<MatXpr>::treechanges >, mpl::size_t<1> >,
    mpl::not_< typename boost::is_same<MatXpr, typename tree_optimizer<MatXpr>::ReturnType >::type > >,
    mpl::push_back< typename expression_types< N - 1, typename tree_optimizer<MatXpr>::ReturnType, BaseXpr >::type,
    typename tree_optimizer< typename mpl::back< typename expression_types< N - 1, typename tree_optimizer<MatXpr>::ReturnType, BaseXpr >::type >::type >::ReturnType >,
    typename expression_types< 0, typename tree_optimizer<MatXpr>::ReturnType, BaseXpr >::type > {};
    
    namespace impl {
        
        template <typename F, typename L>
        struct exit : boost::mpl::equal_to< typename boost::mpl::distance<F, L>::type, boost::mpl::int_<0> > { };
        
        template <typename F, typename L, bool exit, typename ...Args>
        struct to_variadic {
            typedef typename boost::mpl::deref<F>::type front_;
            typedef typename boost::mpl::next<F>::type next_;
            typedef typename impl::exit<next_, L>::type exit_;
            typedef typename to_variadic<next_, L, exit_::value, front_, Args...>::type type;
        };
        
        template <typename F, typename L, typename ...Args>
        struct to_variadic<F, L, true, Args...> {
            typedef Optimize<Args...> type; //To be used in conjunction with the Optimize class
        };
        
        template <typename Seq>
        struct seq_traits{
            typedef typename boost::mpl::begin<Seq>::type first_;
            typedef typename boost::mpl::end<Seq>::type last_;
            typedef typename impl::exit<first_, last_>::type exit_;
        };
        
    }//impl
    
    template <typename Seq>
    struct to_variadic {
        typedef typename boost::mpl::reverse<Seq>::type reversed_;
        typedef typename impl::to_variadic<
        typename impl::seq_traits<reversed_>::first_,
        typename impl::seq_traits<reversed_>::last_,
        impl::seq_traits<Seq>::exit_::value >::type type;
    };

    
    // this class is used to generate the loop of the static build functions in the tree optimizer
    // contains a nested static for loop contruct to unroll the loop to the exact size needed as determined
    // by the size of an mpl::vector of expression types
    template <typename xpr1, typename... Arguments>
    class Optimize {
        
    private:
        static const int size = sizeof... (Arguments);
        
        typedef typename mpl::vector< xpr1, Arguments... >::type expressions;
        
        template <size_t index>
        struct fn {
            
            typename mpl::at_c<expressions, index + 1>::type operator() (const typename mpl::at_c<expressions, index>::type& matxpr) const {
                return tree_optimizer<typename mpl::at_c<expressions, index>::type>::build(matxpr);
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
    
    public:
        template <size_t s = size>
        static typename boost::enable_if<mpl::greater< mpl::size_t<s>, mpl::size_t<0> >, typename mpl::at_c<expressions, size>::type >::type optimize(const xpr1& matxpr) {
            return static_for<0, size, size>()(fn<0>(), matxpr);
        }
        
        template <size_t s = size>
        static typename boost::enable_if<mpl::equal_to< mpl::size_t<s>, mpl::size_t<0> >, xpr1>::type optimize(const xpr1& matxpr) {
            return matxpr;
        }
        
    };
    
    /*
        Define both assignment and evaluator classes. This is where an efficient evaluation of the optimized expression takes place.
    */
    
    //--------------------
    // Dense Evaluators
    //--------------------
    
    template <typename T> class evaluator;
    
    // Default evaluator assuming the expression is it's own evaluator
    template <typename T, std::size_t M, std::size_t N, typename L>
    class evaluator< static_matrix<T, M, N, L> > {
        
    public:
        typedef T value_type;
        typedef typename static_matrix<T, M, N, L>::size_type size_type;
        typedef evaluator eval_type;
        
        BOOST_UBLAS_INLINE
        evaluator(const static_matrix<T, M, N, L>& e) : matxpr(e) { }
        
        BOOST_UBLAS_INLINE
        value_type operator() (size_type i, size_type j) const { return matxpr(i, j); }
        
        BOOST_UBLAS_INLINE
        value_type& operator() (size_type i, size_type j) { return const_cast<static_matrix<T, M, N, L>&> (matxpr)(i, j); }
        
        const static_matrix<T, M, N, L>& matxpr;
        
    };
    
    // Default evaluator assuming the expression is it's own evaluator
    template <typename T, typename L, typename A>
    class evaluator< matrix<T, L, A> > {
        
    public:
        typedef T value_type;
        typedef typename matrix<T, L, A>::size_type size_type;
        typedef evaluator eval_type;
        
        BOOST_UBLAS_INLINE
        evaluator(const matrix<T, L, A>& e) : matxpr(e) { }
      
        BOOST_UBLAS_INLINE
        value_type operator() (size_type i, size_type j) const { return matxpr(i, j); }
        
        BOOST_UBLAS_INLINE
        value_type& operator() (size_type i, size_type j) { return const_cast<matrix<T, L, A>&> (matxpr)(i, j); }
        
        const matrix<T, L, A>& matxpr;
        
    };
    
    // evaluator of A + B
    template <typename A, typename B>
    class evaluator< dmatrix_sum<A, B> > {
    
    public:
        typedef typename dmatrix_sum<A, B>::value_type value_type;
        typedef typename dmatrix_sum<A, B>::size_type size_type;
        typedef typename dmatrix_sum<A, B>::functor_type functor_type;
        typedef evaluator eval_type;
        
        BOOST_UBLAS_INLINE
        evaluator(const dmatrix_sum<A, B>& plus) : matrixl( plus.expression1() ), matrixr( plus.expression2() ) { }
        
        BOOST_UBLAS_INLINE
        const value_type operator() (size_type i, size_type j) const { return functor_type::apply(matrixl, matrixr, i, j); }
        
        typename evaluator<A>::eval_type matrixl;
        typename evaluator<B>::eval_type matrixr;
        
    };
    
    // evaluator of A - B
    template <typename A, typename B>
    class evaluator< dmatrix_difference<A, B> > {
        
    public:
        typedef typename dmatrix_difference<A, B>::value_type value_type;
        typedef typename dmatrix_difference<A, B>::size_type size_type;
        typedef typename dmatrix_difference<A, B>::functor_type functor_type;
        typedef evaluator eval_type;
        
        BOOST_UBLAS_INLINE
        evaluator(const dmatrix_difference<A, B>& difference) : matrixl( difference.expression1() ), matrixr( difference.expression2() ) { }
        
        BOOST_UBLAS_INLINE
        const value_type operator() (size_type i, size_type j) const { return functor_type::apply(matrixl, matrixr, i, j); }
        
        typename evaluator<A>::eval_type matrixl;
        typename evaluator<B>::eval_type matrixr;
        
    };
    
    // Matrix product evaluator, products are complex and must be evaluated into a temporary
    // unless the evaluator is by passed by specializations of Assignment<>
    // evaluator of A * B
    template <typename A, typename B>
    class evaluator< dmatrix_product<A, B> > {
        
    public:
        typedef typename dmatrix_product<A, B>::value_type value_type;
        typedef typename dmatrix_product<A, B>::size_type size_type;
        typedef typename dmatrix_product<A, B>::functor_type functor_type;
        typedef evaluator eval_type;
        
        BOOST_UBLAS_INLINE
        evaluator(const dmatrix_product<A, B>& product) : result(value_type(0)) {
            product_add_impl(result, product); // evaluate to a temporary!
        }
        
        BOOST_UBLAS_INLINE
        const value_type operator() (size_type i, size_type j) const { return result(i, j); }
        
        static_matrix<value_type, A::ColsAtCompileTime, B::RowsAtCompileTime> result;
        typename evaluator<A>::eval_type matrixl;
        typename evaluator<B>::eval_type matrixr;
        
    };
    
    /// performs dest += a * b;
    /// A general implementation must be available outside the evaluator because it is needed by both
    /// evaluator<Product> and Assignment<..., Product<...> > for in-place product evaluation
    template <typename Dest, typename A, typename B>
    void product_add_impl(Dest& dest, const dmatrix_product<A, B>& product) {
        
        typedef typename dmatrix_product<A, B>::functor_type functor_type;
        
        evaluator<A> lhs(product.expression1());
        evaluator<B> rhs(product.expression2());
        
        for(std::size_t i = 0; i < dest.size1(); ++i) {
            for(std::size_t j = 0; j < dest.size2(); ++j) {
                dest(i, j) += functor_type::apply(lhs.matxpr, rhs.matxpr, i, j);
            }
        }
    };
    
    /// performs dest -= a * b;
    /// A general implementation must be available outisde the evaluator because it is needed by both
    /// evaluator<Product> and Assignment<..., Product<...> > for in-place product evaluation
    template <typename Dest, typename A, typename B>
    void product_sub_impl(Dest& dest, const dmatrix_product<A, B>& product) {
        
        typedef typename dmatrix_product<A, B>::functor_type functor_type;
        
        evaluator<A> lhs(product.expression1());
        evaluator<B> rhs(product.expression2());
        
        for(std::size_t i = 0; i < dest.size1(); ++i) {
            for(std::size_t j = 0; j < dest.size2(); ++j) {
                dest(i, j) -= functor_type::apply(lhs.matrixl, rhs.matrixr, i, j);
            }
        }
    };
    
    //-------------------
    // --- Assignment ---
    //-------------------
    
    template < typename A, typename B, typename Op>
    class assignment;
    
    // Generic assignment loop for dense evaluators.
    template <typename A, typename B, typename Op>
    void dense_assignment_loop(A& a, const B& b, const Op& op) {
        typename evaluator<A>::eval_type ea(a);
        typename evaluator<B>::eval_type eb(b);
        
        for(std::size_t i = 0; i < a.size1(); ++i) {
            for(std::size_t j = 0; j < a.size2(); ++j) {
                op.apply(ea(i, j), eb(i, j));
            }
        }
    }
    
    template <typename Dest, typename Src, typename Func>
    void assign(Dest& dest, const Src& src, const Func& func) {
        assignment<Dest, Src, Func>::run(dest, src, func);
    }
    
    template <typename A, typename B, typename Op>
    class assignment {
        
    public:
        static void run(A& a, const B& b, const Op& op) {
            dense_assignment_loop(a, b, op);
        }
        
    };
 
    // specialization for a = b * c
    template <typename A, typename ProdLhs, typename ProdRhs>
    class assignment<A, dmatrix_product<ProdLhs, ProdRhs>, scalar_assign<typename ProdLhs::value_type, typename ProdRhs::value_type> > {
        
    private:
        typedef typename A::value_type value_type;
        
    public:
        static void run(A& a, const dmatrix_product<ProdLhs, ProdRhs>& b, const scalar_assign<typename ProdLhs::value_type, typename ProdRhs::value_type>&) {
            // This is going to use += so we need to zero out the matrix a
            for(std::size_t i = 0; i < a.size1(); ++i) {
                for(std::size_t j = 0; j < a.size2(); ++j) {
                    a(i, j) = value_type(0);
                }
            }
            
            product_add_impl(a, b);
        }
    };
    
    // specialization for a += b * c
    template <typename A, typename ProdLhs, typename ProdRhs>
    class assignment<A, dmatrix_product<ProdLhs, ProdRhs>, scalar_plus_assign<typename ProdLhs::value_type, typename ProdRhs::value_type> > {
        
    public:
        static void run(A& a, const dmatrix_product<ProdLhs, ProdRhs>& b, const scalar_plus_assign<typename ProdLhs::value_type, typename ProdRhs::value_type>& ) {
            product_add_impl(a, b);
        }
        
    };
    
    // specialization for a -= b * c
    template<typename A, typename ProdLhs, typename ProdRhs>
    struct assignment< A, dmatrix_product<ProdLhs, ProdRhs>, scalar_minus_assign<typename ProdLhs::value_type, typename ProdRhs::value_type> > {
        
    public:
        static void run(A& a, const dmatrix_product<ProdLhs, ProdRhs>& b, const scalar_minus_assign<typename ProdLhs::value_type, typename ProdRhs::value_type>& ) {
            product_sub_impl(a, b);
        }
        
    };
    
    // specialization for a = d + b * c
    template<typename A, typename D, typename ProdLhs, typename ProdRhs, typename Op>
    struct assignment<A, dmatrix_sum<D, dmatrix_product<ProdLhs, ProdRhs> >, Op> {
        
    public:
        static void run(A& a, const dmatrix_sum<D, dmatrix_product<ProdLhs,ProdRhs> >& b, const Op& op) {
            assignment<A, D, Op>::run(a, b.expression1(), op);
            assignment<A, dmatrix_product<ProdLhs, ProdRhs>, scalar_plus_assign<typename ProdLhs::value_type, typename ProdRhs::value_type> >::run(a, b.expression2(),
            scalar_plus_assign<typename ProdLhs::value_type, typename ProdRhs::value_type>() );
        }
        
    };
    
    // specialization for a = d - b * c
    template<typename A, typename B, typename ProdLhs, typename ProdRhs, typename Op>
    struct assignment<A, dmatrix_difference<B, dmatrix_product<ProdLhs, ProdRhs> >, Op> {
        
    public:
        static void run(A& a, const dmatrix_difference<B, dmatrix_product<ProdLhs, ProdRhs> >& b, const Op& op) {
            assignment<A, B, Op>::run(a, b.expression1(), op);
            assignment<A, dmatrix_product<ProdLhs, ProdRhs>, scalar_minus_assign<typename ProdLhs::value_type, typename ProdRhs::value_type> >::run(a, b.expression2(),
            scalar_minus_assign<typename ProdLhs::value_type, typename ProdRhs::value_type>() );
        }
        
    };



} } }
#endif // TREE_OPTIMIZER_HPP
