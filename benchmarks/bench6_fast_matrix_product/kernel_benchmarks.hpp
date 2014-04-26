#ifndef KERNEL_BENCHMARKS_HPP
#define KERNEL_BENCHMARKS_HPP

#include <chrono>

// Measuring time
inline std::chrono::high_resolution_clock::time_point tic()
{
    using namespace std::chrono;
    return std::chrono::high_resolution_clock::now();
}

inline double toc( std::chrono::high_resolution_clock::time_point start)
{
    using namespace std::chrono;
    return duration_cast< duration<double> >( tic() - start ).count() ;
}

template <class MatrixType>
void randomFill( MatrixType &m)
{
    typedef typename MatrixType::size_type   size_type;

    for ( size_type i = 0; i != m.size1(); i++ )
    {
        for ( size_type j = 0; j != m.size2(); j++ )
        {
            m( i, j ) = 10.0 * rand() /RAND_MAX;
        }
    }
}

inline double mflops( std::size_t n, std::size_t m, std::size_t l, double duration )
{
    return n*l*(2*m-1)/(duration)/1000000.0;
}

template < class MatrixType, class F >
std::size_t runTest( F f, std::size_t N, std::size_t M, std::size_t L) {

    MatrixType A( N, M ), B(M, L), C( N,  L );
    randomFill( A );
    randomFill( B );

    double duration = 0;

    std::size_t count = 0;

    auto start = tic();

    while( duration < 0.5 )
    {
        f(A, B, C);
        duration = toc( start );
        count++;
    }

    auto p =  mflops( N, M, L, duration/count );

    return (std::size_t) p;
}


#endif // KERNEL_BENCHMARKS_HPP
