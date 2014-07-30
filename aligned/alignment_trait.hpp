
#ifndef BOOST_NUMERIC_UBLAS_TRAITS_ALIGNMENTTRAIT_HPP_
#define BOOST_NUMERIC_UBLAS_TRAITS_ALIGNMENTTRAIT_HPP_

#include <boost/type_traits/alignment_of.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>

namespace boost { namespace numeric { namespace ublas {
    
#define UBLAS_USE_VECTORIZATION 1 // vectorization is the default option

#if UBLAS_USE_VECTORIZATION && defined(__SSSE3__)
#define UBLAS_HAS_SSE3 1
#else
#define UBLAS_HAS_SSE3 0
#endif
    
#if UBLAS_USE_VECTORIZATION && ( defined(__SSE4_1__) || defined(__SSE4_2__) )
#define UBLAS_HAS_SSE4 1
#else
#define UBLAS_HAS_SSE4 0
#endif

#if UBLAS_USE_VECTORIZATION && ( defined(__AVX__) || defined(__AVX2__) )
#define UBLAS_HAS_AVX 1
#else
#define UBLAS_HAS_AVX 0
#endif

template <bool Select, typename T1, typename T2>
struct select_type {
    typedef T1 type;
};

template <typename T1, typename T2>
struct select_type<false, T1, T2> {
    typedef T2 type;
};

template <typename T>
struct is_numeric {
    enum { value = 0 };
};

template <>
struct is_numeric<int> {
    enum { value = 1 };
};

template <>
struct is_numeric<long int> {
    enum { value = 1 };
};

template <>
struct is_numeric<long long int> {
    enum { value = 1 };
};

template <>
struct is_numeric<float> {
    enum { value = 1 };
};

template <>
struct is_numeric<double> {
    enum { value = 1 };
};

template <typename T>
struct is_vectorizable {
    enum {
        value = ( UBLAS_HAS_SSE3  && ( is_numeric<T>::value ) ) ||
        ( UBLAS_HAS_SSE4  && ( is_numeric<T>::value ) ) ||
        ( UBLAS_HAS_AVX && ( is_numeric<T>::value ) )
    };
    typedef typename select_type<value, boost::true_type, boost::false_type>::type  type;
};

template <typename T>
struct num_traits {
    
    enum {
        IsNumeric = is_numeric<T>::value,
        IsVectorizable = is_vectorizable<T>::value,
        ReadCost = 1, // setting the default single machine instruction cost to 1 for all types
        MultCost = 1,
        AddCost = 1,
    };
    
};

template <typename T>
struct alignment_trait {
#if UBLAS_HAS_AVX
    enum { value = is_vectorizable<T>::value ? 32UL : boost::alignment_of<T>::value };
#elif UBLAS_HAS_SSE
    enum { value = is_vectorizable<T>::value ? 16UL : boost::alignment_of<T>::value };
#else
    enum { value = alignment_of<T>::value };
#endif
    
};

template <>
struct alignment_trait<float> {
#if UBLAS_HAS_AVX
    enum { value = 32UL };
#elif UBLAS_HAS_SSE
    enum { value = 16UL };
#else
    enum { value = boost::alignment_of<float>::value };
#endif
    
};

template <>
struct alignment_trait<double> {
#if UBLAS_HAS_AVX
    enum { value = 32UL };
#elif UBLAS_HAS_SSE
    enum { value = 16UL };
#else
    enum { value = boost::alignment_of<double>::value };
#endif
};

    
} } } // Namespace boost::numeric::ublas

#endif
