#include <iostream>
#include "tests.hpp"
#include "kernel_benchmarks.hpp"

using std::cout; using std::endl;

std::vector< perf > runTests(std::size_t N, std::size_t M, std::size_t L) 
{
    perf p;

    std::vector< perf > ps;

    if ( N >= 1 && M >= 1 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_1_1, N, M, L );
        p.N=1; p.M=1; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 1 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_1_2, N, M, L );
        p.N=1; p.M=1; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 1 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_1_4, N, M, L );
        p.N=1; p.M=1; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 1 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_1_8, N, M, L );
        p.N=1; p.M=1; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 1 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_1_16, N, M, L );
        p.N=1; p.M=1; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 1 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_1_32, N, M, L );
        p.N=1; p.M=1; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 1 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_1_64, N, M, L );
        p.N=1; p.M=1; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 1 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_1_128, N, M, L );
        p.N=1; p.M=1; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 1 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_1_256, N, M, L );
        p.N=1; p.M=1; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 2 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_2_1, N, M, L );
        p.N=1; p.M=2; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 2 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_2_2, N, M, L );
        p.N=1; p.M=2; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 2 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_2_4, N, M, L );
        p.N=1; p.M=2; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 2 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_2_8, N, M, L );
        p.N=1; p.M=2; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 2 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_2_16, N, M, L );
        p.N=1; p.M=2; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 2 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_2_32, N, M, L );
        p.N=1; p.M=2; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 2 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_2_64, N, M, L );
        p.N=1; p.M=2; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 2 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_2_128, N, M, L );
        p.N=1; p.M=2; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 2 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_2_256, N, M, L );
        p.N=1; p.M=2; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 4 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_4_1, N, M, L );
        p.N=1; p.M=4; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 4 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_4_2, N, M, L );
        p.N=1; p.M=4; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 4 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_4_4, N, M, L );
        p.N=1; p.M=4; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 4 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_4_8, N, M, L );
        p.N=1; p.M=4; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 4 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_4_16, N, M, L );
        p.N=1; p.M=4; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 4 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_4_32, N, M, L );
        p.N=1; p.M=4; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 4 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_4_64, N, M, L );
        p.N=1; p.M=4; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 4 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_4_128, N, M, L );
        p.N=1; p.M=4; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 4 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_4_256, N, M, L );
        p.N=1; p.M=4; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 8 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_8_1, N, M, L );
        p.N=1; p.M=8; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 8 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_8_2, N, M, L );
        p.N=1; p.M=8; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 8 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_8_4, N, M, L );
        p.N=1; p.M=8; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 8 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_8_8, N, M, L );
        p.N=1; p.M=8; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 8 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_8_16, N, M, L );
        p.N=1; p.M=8; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 8 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_8_32, N, M, L );
        p.N=1; p.M=8; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 8 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_8_64, N, M, L );
        p.N=1; p.M=8; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 8 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_8_128, N, M, L );
        p.N=1; p.M=8; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 8 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_8_256, N, M, L );
        p.N=1; p.M=8; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 16 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_16_1, N, M, L );
        p.N=1; p.M=16; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 16 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_16_2, N, M, L );
        p.N=1; p.M=16; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 16 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_16_4, N, M, L );
        p.N=1; p.M=16; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 16 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_16_8, N, M, L );
        p.N=1; p.M=16; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 16 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_16_16, N, M, L );
        p.N=1; p.M=16; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 16 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_16_32, N, M, L );
        p.N=1; p.M=16; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 16 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_16_64, N, M, L );
        p.N=1; p.M=16; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 16 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_16_128, N, M, L );
        p.N=1; p.M=16; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 16 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_16_256, N, M, L );
        p.N=1; p.M=16; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 32 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_32_1, N, M, L );
        p.N=1; p.M=32; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 32 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_32_2, N, M, L );
        p.N=1; p.M=32; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 32 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_32_4, N, M, L );
        p.N=1; p.M=32; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 32 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_32_8, N, M, L );
        p.N=1; p.M=32; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 32 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_32_16, N, M, L );
        p.N=1; p.M=32; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 32 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_32_32, N, M, L );
        p.N=1; p.M=32; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 32 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_32_64, N, M, L );
        p.N=1; p.M=32; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 32 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_32_128, N, M, L );
        p.N=1; p.M=32; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 32 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_32_256, N, M, L );
        p.N=1; p.M=32; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 64 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_64_1, N, M, L );
        p.N=1; p.M=64; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 64 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_64_2, N, M, L );
        p.N=1; p.M=64; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 64 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_64_4, N, M, L );
        p.N=1; p.M=64; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 64 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_64_8, N, M, L );
        p.N=1; p.M=64; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 64 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_64_16, N, M, L );
        p.N=1; p.M=64; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 64 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_64_32, N, M, L );
        p.N=1; p.M=64; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 64 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_64_64, N, M, L );
        p.N=1; p.M=64; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 64 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_64_128, N, M, L );
        p.N=1; p.M=64; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 64 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_64_256, N, M, L );
        p.N=1; p.M=64; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 128 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_128_1, N, M, L );
        p.N=1; p.M=128; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 128 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_128_2, N, M, L );
        p.N=1; p.M=128; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 128 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_128_4, N, M, L );
        p.N=1; p.M=128; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 128 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_128_8, N, M, L );
        p.N=1; p.M=128; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 128 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_128_16, N, M, L );
        p.N=1; p.M=128; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 128 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_128_32, N, M, L );
        p.N=1; p.M=128; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 128 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_128_64, N, M, L );
        p.N=1; p.M=128; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 128 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_128_128, N, M, L );
        p.N=1; p.M=128; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 128 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_128_256, N, M, L );
        p.N=1; p.M=128; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 256 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_256_1, N, M, L );
        p.N=1; p.M=256; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 256 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_256_2, N, M, L );
        p.N=1; p.M=256; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 256 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_256_4, N, M, L );
        p.N=1; p.M=256; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 256 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_256_8, N, M, L );
        p.N=1; p.M=256; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 256 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_256_16, N, M, L );
        p.N=1; p.M=256; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 256 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_256_32, N, M, L );
        p.N=1; p.M=256; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 256 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_256_64, N, M, L );
        p.N=1; p.M=256; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 256 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_256_128, N, M, L );
        p.N=1; p.M=256; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 1 && M >= 256 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult1_256_256, N, M, L );
        p.N=1; p.M=256; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 1 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_1_1, N, M, L );
        p.N=2; p.M=1; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 1 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_1_2, N, M, L );
        p.N=2; p.M=1; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 1 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_1_4, N, M, L );
        p.N=2; p.M=1; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 1 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_1_8, N, M, L );
        p.N=2; p.M=1; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 1 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_1_16, N, M, L );
        p.N=2; p.M=1; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 1 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_1_32, N, M, L );
        p.N=2; p.M=1; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 1 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_1_64, N, M, L );
        p.N=2; p.M=1; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 1 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_1_128, N, M, L );
        p.N=2; p.M=1; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 1 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_1_256, N, M, L );
        p.N=2; p.M=1; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 2 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_2_1, N, M, L );
        p.N=2; p.M=2; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 2 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_2_2, N, M, L );
        p.N=2; p.M=2; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 2 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_2_4, N, M, L );
        p.N=2; p.M=2; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 2 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_2_8, N, M, L );
        p.N=2; p.M=2; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 2 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_2_16, N, M, L );
        p.N=2; p.M=2; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 2 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_2_32, N, M, L );
        p.N=2; p.M=2; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 2 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_2_64, N, M, L );
        p.N=2; p.M=2; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 2 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_2_128, N, M, L );
        p.N=2; p.M=2; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 2 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_2_256, N, M, L );
        p.N=2; p.M=2; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 4 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_4_1, N, M, L );
        p.N=2; p.M=4; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 4 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_4_2, N, M, L );
        p.N=2; p.M=4; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 4 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_4_4, N, M, L );
        p.N=2; p.M=4; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 4 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_4_8, N, M, L );
        p.N=2; p.M=4; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 4 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_4_16, N, M, L );
        p.N=2; p.M=4; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 4 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_4_32, N, M, L );
        p.N=2; p.M=4; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 4 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_4_64, N, M, L );
        p.N=2; p.M=4; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 4 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_4_128, N, M, L );
        p.N=2; p.M=4; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 4 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_4_256, N, M, L );
        p.N=2; p.M=4; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 8 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_8_1, N, M, L );
        p.N=2; p.M=8; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 8 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_8_2, N, M, L );
        p.N=2; p.M=8; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 8 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_8_4, N, M, L );
        p.N=2; p.M=8; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 8 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_8_8, N, M, L );
        p.N=2; p.M=8; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 8 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_8_16, N, M, L );
        p.N=2; p.M=8; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 8 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_8_32, N, M, L );
        p.N=2; p.M=8; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 8 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_8_64, N, M, L );
        p.N=2; p.M=8; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 8 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_8_128, N, M, L );
        p.N=2; p.M=8; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 8 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_8_256, N, M, L );
        p.N=2; p.M=8; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 16 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_16_1, N, M, L );
        p.N=2; p.M=16; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 16 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_16_2, N, M, L );
        p.N=2; p.M=16; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 16 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_16_4, N, M, L );
        p.N=2; p.M=16; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 16 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_16_8, N, M, L );
        p.N=2; p.M=16; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 16 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_16_16, N, M, L );
        p.N=2; p.M=16; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 16 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_16_32, N, M, L );
        p.N=2; p.M=16; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 16 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_16_64, N, M, L );
        p.N=2; p.M=16; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 16 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_16_128, N, M, L );
        p.N=2; p.M=16; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 16 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_16_256, N, M, L );
        p.N=2; p.M=16; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 32 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_32_1, N, M, L );
        p.N=2; p.M=32; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 32 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_32_2, N, M, L );
        p.N=2; p.M=32; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 32 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_32_4, N, M, L );
        p.N=2; p.M=32; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 32 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_32_8, N, M, L );
        p.N=2; p.M=32; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 32 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_32_16, N, M, L );
        p.N=2; p.M=32; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 32 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_32_32, N, M, L );
        p.N=2; p.M=32; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 32 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_32_64, N, M, L );
        p.N=2; p.M=32; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 32 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_32_128, N, M, L );
        p.N=2; p.M=32; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 32 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_32_256, N, M, L );
        p.N=2; p.M=32; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 64 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_64_1, N, M, L );
        p.N=2; p.M=64; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 64 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_64_2, N, M, L );
        p.N=2; p.M=64; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 64 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_64_4, N, M, L );
        p.N=2; p.M=64; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 64 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_64_8, N, M, L );
        p.N=2; p.M=64; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 64 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_64_16, N, M, L );
        p.N=2; p.M=64; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 64 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_64_32, N, M, L );
        p.N=2; p.M=64; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 64 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_64_64, N, M, L );
        p.N=2; p.M=64; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 64 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_64_128, N, M, L );
        p.N=2; p.M=64; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 64 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_64_256, N, M, L );
        p.N=2; p.M=64; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 128 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_128_1, N, M, L );
        p.N=2; p.M=128; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 128 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_128_2, N, M, L );
        p.N=2; p.M=128; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 128 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_128_4, N, M, L );
        p.N=2; p.M=128; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 128 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_128_8, N, M, L );
        p.N=2; p.M=128; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 128 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_128_16, N, M, L );
        p.N=2; p.M=128; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 128 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_128_32, N, M, L );
        p.N=2; p.M=128; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 128 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_128_64, N, M, L );
        p.N=2; p.M=128; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 128 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_128_128, N, M, L );
        p.N=2; p.M=128; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 128 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_128_256, N, M, L );
        p.N=2; p.M=128; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 256 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_256_1, N, M, L );
        p.N=2; p.M=256; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 256 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_256_2, N, M, L );
        p.N=2; p.M=256; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 256 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_256_4, N, M, L );
        p.N=2; p.M=256; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 256 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_256_8, N, M, L );
        p.N=2; p.M=256; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 256 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_256_16, N, M, L );
        p.N=2; p.M=256; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 256 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_256_32, N, M, L );
        p.N=2; p.M=256; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 256 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_256_64, N, M, L );
        p.N=2; p.M=256; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 256 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_256_128, N, M, L );
        p.N=2; p.M=256; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 2 && M >= 256 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult2_256_256, N, M, L );
        p.N=2; p.M=256; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 1 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_1_1, N, M, L );
        p.N=4; p.M=1; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 1 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_1_2, N, M, L );
        p.N=4; p.M=1; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 1 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_1_4, N, M, L );
        p.N=4; p.M=1; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 1 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_1_8, N, M, L );
        p.N=4; p.M=1; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 1 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_1_16, N, M, L );
        p.N=4; p.M=1; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 1 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_1_32, N, M, L );
        p.N=4; p.M=1; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 1 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_1_64, N, M, L );
        p.N=4; p.M=1; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 1 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_1_128, N, M, L );
        p.N=4; p.M=1; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 1 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_1_256, N, M, L );
        p.N=4; p.M=1; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 2 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_2_1, N, M, L );
        p.N=4; p.M=2; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 2 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_2_2, N, M, L );
        p.N=4; p.M=2; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 2 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_2_4, N, M, L );
        p.N=4; p.M=2; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 2 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_2_8, N, M, L );
        p.N=4; p.M=2; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 2 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_2_16, N, M, L );
        p.N=4; p.M=2; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 2 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_2_32, N, M, L );
        p.N=4; p.M=2; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 2 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_2_64, N, M, L );
        p.N=4; p.M=2; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 2 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_2_128, N, M, L );
        p.N=4; p.M=2; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 2 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_2_256, N, M, L );
        p.N=4; p.M=2; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 4 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_4_1, N, M, L );
        p.N=4; p.M=4; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 4 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_4_2, N, M, L );
        p.N=4; p.M=4; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 4 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_4_4, N, M, L );
        p.N=4; p.M=4; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 4 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_4_8, N, M, L );
        p.N=4; p.M=4; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 4 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_4_16, N, M, L );
        p.N=4; p.M=4; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 4 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_4_32, N, M, L );
        p.N=4; p.M=4; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 4 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_4_64, N, M, L );
        p.N=4; p.M=4; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 4 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_4_128, N, M, L );
        p.N=4; p.M=4; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 4 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_4_256, N, M, L );
        p.N=4; p.M=4; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 8 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_8_1, N, M, L );
        p.N=4; p.M=8; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 8 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_8_2, N, M, L );
        p.N=4; p.M=8; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 8 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_8_4, N, M, L );
        p.N=4; p.M=8; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 8 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_8_8, N, M, L );
        p.N=4; p.M=8; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 8 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_8_16, N, M, L );
        p.N=4; p.M=8; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 8 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_8_32, N, M, L );
        p.N=4; p.M=8; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 8 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_8_64, N, M, L );
        p.N=4; p.M=8; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 8 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_8_128, N, M, L );
        p.N=4; p.M=8; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 8 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_8_256, N, M, L );
        p.N=4; p.M=8; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 16 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_16_1, N, M, L );
        p.N=4; p.M=16; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 16 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_16_2, N, M, L );
        p.N=4; p.M=16; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 16 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_16_4, N, M, L );
        p.N=4; p.M=16; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 16 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_16_8, N, M, L );
        p.N=4; p.M=16; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 16 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_16_16, N, M, L );
        p.N=4; p.M=16; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 16 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_16_32, N, M, L );
        p.N=4; p.M=16; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 16 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_16_64, N, M, L );
        p.N=4; p.M=16; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 16 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_16_128, N, M, L );
        p.N=4; p.M=16; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 16 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_16_256, N, M, L );
        p.N=4; p.M=16; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 32 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_32_1, N, M, L );
        p.N=4; p.M=32; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 32 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_32_2, N, M, L );
        p.N=4; p.M=32; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 32 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_32_4, N, M, L );
        p.N=4; p.M=32; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 32 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_32_8, N, M, L );
        p.N=4; p.M=32; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 32 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_32_16, N, M, L );
        p.N=4; p.M=32; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 32 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_32_32, N, M, L );
        p.N=4; p.M=32; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 32 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_32_64, N, M, L );
        p.N=4; p.M=32; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 32 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_32_128, N, M, L );
        p.N=4; p.M=32; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 32 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_32_256, N, M, L );
        p.N=4; p.M=32; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 64 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_64_1, N, M, L );
        p.N=4; p.M=64; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 64 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_64_2, N, M, L );
        p.N=4; p.M=64; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 64 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_64_4, N, M, L );
        p.N=4; p.M=64; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 64 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_64_8, N, M, L );
        p.N=4; p.M=64; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 64 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_64_16, N, M, L );
        p.N=4; p.M=64; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 64 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_64_32, N, M, L );
        p.N=4; p.M=64; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 64 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_64_64, N, M, L );
        p.N=4; p.M=64; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 64 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_64_128, N, M, L );
        p.N=4; p.M=64; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 64 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_64_256, N, M, L );
        p.N=4; p.M=64; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 128 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_128_1, N, M, L );
        p.N=4; p.M=128; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 128 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_128_2, N, M, L );
        p.N=4; p.M=128; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 128 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_128_4, N, M, L );
        p.N=4; p.M=128; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 128 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_128_8, N, M, L );
        p.N=4; p.M=128; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 128 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_128_16, N, M, L );
        p.N=4; p.M=128; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 128 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_128_32, N, M, L );
        p.N=4; p.M=128; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 128 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_128_64, N, M, L );
        p.N=4; p.M=128; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 128 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_128_128, N, M, L );
        p.N=4; p.M=128; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 128 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_128_256, N, M, L );
        p.N=4; p.M=128; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 256 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_256_1, N, M, L );
        p.N=4; p.M=256; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 256 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_256_2, N, M, L );
        p.N=4; p.M=256; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 256 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_256_4, N, M, L );
        p.N=4; p.M=256; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 256 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_256_8, N, M, L );
        p.N=4; p.M=256; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 256 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_256_16, N, M, L );
        p.N=4; p.M=256; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 256 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_256_32, N, M, L );
        p.N=4; p.M=256; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 256 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_256_64, N, M, L );
        p.N=4; p.M=256; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 256 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_256_128, N, M, L );
        p.N=4; p.M=256; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 4 && M >= 256 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult4_256_256, N, M, L );
        p.N=4; p.M=256; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 1 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_1_1, N, M, L );
        p.N=8; p.M=1; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 1 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_1_2, N, M, L );
        p.N=8; p.M=1; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 1 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_1_4, N, M, L );
        p.N=8; p.M=1; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 1 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_1_8, N, M, L );
        p.N=8; p.M=1; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 1 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_1_16, N, M, L );
        p.N=8; p.M=1; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 1 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_1_32, N, M, L );
        p.N=8; p.M=1; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 1 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_1_64, N, M, L );
        p.N=8; p.M=1; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 1 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_1_128, N, M, L );
        p.N=8; p.M=1; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 1 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_1_256, N, M, L );
        p.N=8; p.M=1; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 2 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_2_1, N, M, L );
        p.N=8; p.M=2; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 2 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_2_2, N, M, L );
        p.N=8; p.M=2; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 2 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_2_4, N, M, L );
        p.N=8; p.M=2; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 2 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_2_8, N, M, L );
        p.N=8; p.M=2; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 2 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_2_16, N, M, L );
        p.N=8; p.M=2; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 2 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_2_32, N, M, L );
        p.N=8; p.M=2; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 2 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_2_64, N, M, L );
        p.N=8; p.M=2; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 2 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_2_128, N, M, L );
        p.N=8; p.M=2; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 2 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_2_256, N, M, L );
        p.N=8; p.M=2; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 4 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_4_1, N, M, L );
        p.N=8; p.M=4; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 4 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_4_2, N, M, L );
        p.N=8; p.M=4; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 4 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_4_4, N, M, L );
        p.N=8; p.M=4; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 4 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_4_8, N, M, L );
        p.N=8; p.M=4; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 4 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_4_16, N, M, L );
        p.N=8; p.M=4; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 4 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_4_32, N, M, L );
        p.N=8; p.M=4; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 4 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_4_64, N, M, L );
        p.N=8; p.M=4; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 4 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_4_128, N, M, L );
        p.N=8; p.M=4; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 4 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_4_256, N, M, L );
        p.N=8; p.M=4; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 8 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_8_1, N, M, L );
        p.N=8; p.M=8; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 8 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_8_2, N, M, L );
        p.N=8; p.M=8; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 8 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_8_4, N, M, L );
        p.N=8; p.M=8; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 8 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_8_8, N, M, L );
        p.N=8; p.M=8; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 8 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_8_16, N, M, L );
        p.N=8; p.M=8; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 8 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_8_32, N, M, L );
        p.N=8; p.M=8; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 8 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_8_64, N, M, L );
        p.N=8; p.M=8; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 8 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_8_128, N, M, L );
        p.N=8; p.M=8; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 8 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_8_256, N, M, L );
        p.N=8; p.M=8; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 16 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_16_1, N, M, L );
        p.N=8; p.M=16; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 16 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_16_2, N, M, L );
        p.N=8; p.M=16; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 16 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_16_4, N, M, L );
        p.N=8; p.M=16; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 16 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_16_8, N, M, L );
        p.N=8; p.M=16; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 16 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_16_16, N, M, L );
        p.N=8; p.M=16; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 16 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_16_32, N, M, L );
        p.N=8; p.M=16; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 16 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_16_64, N, M, L );
        p.N=8; p.M=16; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 16 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_16_128, N, M, L );
        p.N=8; p.M=16; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 16 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_16_256, N, M, L );
        p.N=8; p.M=16; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 32 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_32_1, N, M, L );
        p.N=8; p.M=32; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 32 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_32_2, N, M, L );
        p.N=8; p.M=32; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 32 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_32_4, N, M, L );
        p.N=8; p.M=32; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 32 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_32_8, N, M, L );
        p.N=8; p.M=32; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 32 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_32_16, N, M, L );
        p.N=8; p.M=32; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 32 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_32_32, N, M, L );
        p.N=8; p.M=32; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 32 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_32_64, N, M, L );
        p.N=8; p.M=32; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 32 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_32_128, N, M, L );
        p.N=8; p.M=32; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 32 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_32_256, N, M, L );
        p.N=8; p.M=32; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 64 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_64_1, N, M, L );
        p.N=8; p.M=64; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 64 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_64_2, N, M, L );
        p.N=8; p.M=64; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 64 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_64_4, N, M, L );
        p.N=8; p.M=64; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 64 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_64_8, N, M, L );
        p.N=8; p.M=64; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 64 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_64_16, N, M, L );
        p.N=8; p.M=64; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 64 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_64_32, N, M, L );
        p.N=8; p.M=64; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 64 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_64_64, N, M, L );
        p.N=8; p.M=64; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 64 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_64_128, N, M, L );
        p.N=8; p.M=64; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 64 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_64_256, N, M, L );
        p.N=8; p.M=64; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 128 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_128_1, N, M, L );
        p.N=8; p.M=128; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 128 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_128_2, N, M, L );
        p.N=8; p.M=128; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 128 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_128_4, N, M, L );
        p.N=8; p.M=128; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 128 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_128_8, N, M, L );
        p.N=8; p.M=128; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 128 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_128_16, N, M, L );
        p.N=8; p.M=128; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 128 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_128_32, N, M, L );
        p.N=8; p.M=128; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 128 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_128_64, N, M, L );
        p.N=8; p.M=128; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 128 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_128_128, N, M, L );
        p.N=8; p.M=128; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 128 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_128_256, N, M, L );
        p.N=8; p.M=128; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 256 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_256_1, N, M, L );
        p.N=8; p.M=256; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 256 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_256_2, N, M, L );
        p.N=8; p.M=256; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 256 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_256_4, N, M, L );
        p.N=8; p.M=256; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 256 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_256_8, N, M, L );
        p.N=8; p.M=256; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 256 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_256_16, N, M, L );
        p.N=8; p.M=256; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 256 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_256_32, N, M, L );
        p.N=8; p.M=256; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 256 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_256_64, N, M, L );
        p.N=8; p.M=256; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 256 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_256_128, N, M, L );
        p.N=8; p.M=256; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 8 && M >= 256 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult8_256_256, N, M, L );
        p.N=8; p.M=256; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 1 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_1_1, N, M, L );
        p.N=16; p.M=1; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 1 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_1_2, N, M, L );
        p.N=16; p.M=1; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 1 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_1_4, N, M, L );
        p.N=16; p.M=1; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 1 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_1_8, N, M, L );
        p.N=16; p.M=1; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 1 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_1_16, N, M, L );
        p.N=16; p.M=1; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 1 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_1_32, N, M, L );
        p.N=16; p.M=1; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 1 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_1_64, N, M, L );
        p.N=16; p.M=1; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 1 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_1_128, N, M, L );
        p.N=16; p.M=1; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 1 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_1_256, N, M, L );
        p.N=16; p.M=1; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 2 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_2_1, N, M, L );
        p.N=16; p.M=2; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 2 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_2_2, N, M, L );
        p.N=16; p.M=2; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 2 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_2_4, N, M, L );
        p.N=16; p.M=2; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 2 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_2_8, N, M, L );
        p.N=16; p.M=2; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 2 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_2_16, N, M, L );
        p.N=16; p.M=2; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 2 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_2_32, N, M, L );
        p.N=16; p.M=2; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 2 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_2_64, N, M, L );
        p.N=16; p.M=2; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 2 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_2_128, N, M, L );
        p.N=16; p.M=2; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 2 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_2_256, N, M, L );
        p.N=16; p.M=2; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 4 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_4_1, N, M, L );
        p.N=16; p.M=4; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 4 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_4_2, N, M, L );
        p.N=16; p.M=4; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 4 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_4_4, N, M, L );
        p.N=16; p.M=4; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 4 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_4_8, N, M, L );
        p.N=16; p.M=4; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 4 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_4_16, N, M, L );
        p.N=16; p.M=4; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 4 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_4_32, N, M, L );
        p.N=16; p.M=4; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 4 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_4_64, N, M, L );
        p.N=16; p.M=4; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 4 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_4_128, N, M, L );
        p.N=16; p.M=4; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 4 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_4_256, N, M, L );
        p.N=16; p.M=4; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 8 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_8_1, N, M, L );
        p.N=16; p.M=8; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 8 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_8_2, N, M, L );
        p.N=16; p.M=8; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 8 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_8_4, N, M, L );
        p.N=16; p.M=8; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 8 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_8_8, N, M, L );
        p.N=16; p.M=8; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 8 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_8_16, N, M, L );
        p.N=16; p.M=8; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 8 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_8_32, N, M, L );
        p.N=16; p.M=8; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 8 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_8_64, N, M, L );
        p.N=16; p.M=8; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 8 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_8_128, N, M, L );
        p.N=16; p.M=8; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 8 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_8_256, N, M, L );
        p.N=16; p.M=8; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 16 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_16_1, N, M, L );
        p.N=16; p.M=16; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 16 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_16_2, N, M, L );
        p.N=16; p.M=16; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 16 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_16_4, N, M, L );
        p.N=16; p.M=16; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 16 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_16_8, N, M, L );
        p.N=16; p.M=16; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 16 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_16_16, N, M, L );
        p.N=16; p.M=16; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 16 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_16_32, N, M, L );
        p.N=16; p.M=16; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 16 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_16_64, N, M, L );
        p.N=16; p.M=16; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 16 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_16_128, N, M, L );
        p.N=16; p.M=16; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 16 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_16_256, N, M, L );
        p.N=16; p.M=16; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 32 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_32_1, N, M, L );
        p.N=16; p.M=32; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 32 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_32_2, N, M, L );
        p.N=16; p.M=32; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 32 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_32_4, N, M, L );
        p.N=16; p.M=32; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 32 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_32_8, N, M, L );
        p.N=16; p.M=32; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 32 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_32_16, N, M, L );
        p.N=16; p.M=32; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 32 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_32_32, N, M, L );
        p.N=16; p.M=32; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 32 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_32_64, N, M, L );
        p.N=16; p.M=32; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 32 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_32_128, N, M, L );
        p.N=16; p.M=32; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 32 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_32_256, N, M, L );
        p.N=16; p.M=32; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 64 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_64_1, N, M, L );
        p.N=16; p.M=64; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 64 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_64_2, N, M, L );
        p.N=16; p.M=64; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 64 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_64_4, N, M, L );
        p.N=16; p.M=64; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 64 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_64_8, N, M, L );
        p.N=16; p.M=64; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 64 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_64_16, N, M, L );
        p.N=16; p.M=64; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 64 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_64_32, N, M, L );
        p.N=16; p.M=64; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 64 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_64_64, N, M, L );
        p.N=16; p.M=64; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 64 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_64_128, N, M, L );
        p.N=16; p.M=64; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 64 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_64_256, N, M, L );
        p.N=16; p.M=64; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 128 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_128_1, N, M, L );
        p.N=16; p.M=128; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 128 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_128_2, N, M, L );
        p.N=16; p.M=128; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 128 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_128_4, N, M, L );
        p.N=16; p.M=128; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 128 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_128_8, N, M, L );
        p.N=16; p.M=128; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 128 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_128_16, N, M, L );
        p.N=16; p.M=128; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 128 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_128_32, N, M, L );
        p.N=16; p.M=128; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 128 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_128_64, N, M, L );
        p.N=16; p.M=128; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 128 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_128_128, N, M, L );
        p.N=16; p.M=128; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 128 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_128_256, N, M, L );
        p.N=16; p.M=128; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 256 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_256_1, N, M, L );
        p.N=16; p.M=256; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 256 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_256_2, N, M, L );
        p.N=16; p.M=256; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 256 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_256_4, N, M, L );
        p.N=16; p.M=256; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 256 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_256_8, N, M, L );
        p.N=16; p.M=256; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 256 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_256_16, N, M, L );
        p.N=16; p.M=256; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 256 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_256_32, N, M, L );
        p.N=16; p.M=256; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 256 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_256_64, N, M, L );
        p.N=16; p.M=256; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 256 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_256_128, N, M, L );
        p.N=16; p.M=256; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 16 && M >= 256 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult16_256_256, N, M, L );
        p.N=16; p.M=256; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 1 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_1_1, N, M, L );
        p.N=32; p.M=1; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 1 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_1_2, N, M, L );
        p.N=32; p.M=1; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 1 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_1_4, N, M, L );
        p.N=32; p.M=1; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 1 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_1_8, N, M, L );
        p.N=32; p.M=1; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 1 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_1_16, N, M, L );
        p.N=32; p.M=1; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 1 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_1_32, N, M, L );
        p.N=32; p.M=1; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 1 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_1_64, N, M, L );
        p.N=32; p.M=1; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 1 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_1_128, N, M, L );
        p.N=32; p.M=1; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 1 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_1_256, N, M, L );
        p.N=32; p.M=1; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 2 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_2_1, N, M, L );
        p.N=32; p.M=2; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 2 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_2_2, N, M, L );
        p.N=32; p.M=2; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 2 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_2_4, N, M, L );
        p.N=32; p.M=2; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 2 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_2_8, N, M, L );
        p.N=32; p.M=2; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 2 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_2_16, N, M, L );
        p.N=32; p.M=2; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 2 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_2_32, N, M, L );
        p.N=32; p.M=2; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 2 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_2_64, N, M, L );
        p.N=32; p.M=2; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 2 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_2_128, N, M, L );
        p.N=32; p.M=2; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 2 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_2_256, N, M, L );
        p.N=32; p.M=2; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 4 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_4_1, N, M, L );
        p.N=32; p.M=4; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 4 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_4_2, N, M, L );
        p.N=32; p.M=4; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 4 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_4_4, N, M, L );
        p.N=32; p.M=4; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 4 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_4_8, N, M, L );
        p.N=32; p.M=4; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 4 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_4_16, N, M, L );
        p.N=32; p.M=4; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 4 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_4_32, N, M, L );
        p.N=32; p.M=4; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 4 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_4_64, N, M, L );
        p.N=32; p.M=4; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 4 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_4_128, N, M, L );
        p.N=32; p.M=4; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 4 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_4_256, N, M, L );
        p.N=32; p.M=4; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 8 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_8_1, N, M, L );
        p.N=32; p.M=8; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 8 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_8_2, N, M, L );
        p.N=32; p.M=8; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 8 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_8_4, N, M, L );
        p.N=32; p.M=8; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 8 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_8_8, N, M, L );
        p.N=32; p.M=8; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 8 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_8_16, N, M, L );
        p.N=32; p.M=8; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 8 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_8_32, N, M, L );
        p.N=32; p.M=8; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 8 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_8_64, N, M, L );
        p.N=32; p.M=8; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 8 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_8_128, N, M, L );
        p.N=32; p.M=8; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 8 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_8_256, N, M, L );
        p.N=32; p.M=8; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 16 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_16_1, N, M, L );
        p.N=32; p.M=16; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 16 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_16_2, N, M, L );
        p.N=32; p.M=16; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 16 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_16_4, N, M, L );
        p.N=32; p.M=16; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 16 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_16_8, N, M, L );
        p.N=32; p.M=16; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 16 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_16_16, N, M, L );
        p.N=32; p.M=16; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 16 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_16_32, N, M, L );
        p.N=32; p.M=16; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 16 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_16_64, N, M, L );
        p.N=32; p.M=16; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 16 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_16_128, N, M, L );
        p.N=32; p.M=16; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 16 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_16_256, N, M, L );
        p.N=32; p.M=16; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 32 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_32_1, N, M, L );
        p.N=32; p.M=32; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 32 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_32_2, N, M, L );
        p.N=32; p.M=32; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 32 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_32_4, N, M, L );
        p.N=32; p.M=32; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 32 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_32_8, N, M, L );
        p.N=32; p.M=32; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 32 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_32_16, N, M, L );
        p.N=32; p.M=32; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 32 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_32_32, N, M, L );
        p.N=32; p.M=32; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 32 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_32_64, N, M, L );
        p.N=32; p.M=32; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 32 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_32_128, N, M, L );
        p.N=32; p.M=32; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 32 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_32_256, N, M, L );
        p.N=32; p.M=32; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 64 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_64_1, N, M, L );
        p.N=32; p.M=64; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 64 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_64_2, N, M, L );
        p.N=32; p.M=64; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 64 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_64_4, N, M, L );
        p.N=32; p.M=64; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 64 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_64_8, N, M, L );
        p.N=32; p.M=64; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 64 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_64_16, N, M, L );
        p.N=32; p.M=64; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 64 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_64_32, N, M, L );
        p.N=32; p.M=64; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 64 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_64_64, N, M, L );
        p.N=32; p.M=64; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 64 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_64_128, N, M, L );
        p.N=32; p.M=64; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 64 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_64_256, N, M, L );
        p.N=32; p.M=64; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 128 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_128_1, N, M, L );
        p.N=32; p.M=128; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 128 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_128_2, N, M, L );
        p.N=32; p.M=128; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 128 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_128_4, N, M, L );
        p.N=32; p.M=128; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 128 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_128_8, N, M, L );
        p.N=32; p.M=128; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 128 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_128_16, N, M, L );
        p.N=32; p.M=128; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 128 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_128_32, N, M, L );
        p.N=32; p.M=128; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 128 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_128_64, N, M, L );
        p.N=32; p.M=128; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 128 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_128_128, N, M, L );
        p.N=32; p.M=128; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 128 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_128_256, N, M, L );
        p.N=32; p.M=128; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 256 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_256_1, N, M, L );
        p.N=32; p.M=256; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 256 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_256_2, N, M, L );
        p.N=32; p.M=256; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 256 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_256_4, N, M, L );
        p.N=32; p.M=256; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 256 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_256_8, N, M, L );
        p.N=32; p.M=256; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 256 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_256_16, N, M, L );
        p.N=32; p.M=256; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 256 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_256_32, N, M, L );
        p.N=32; p.M=256; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 256 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_256_64, N, M, L );
        p.N=32; p.M=256; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 256 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_256_128, N, M, L );
        p.N=32; p.M=256; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 32 && M >= 256 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult32_256_256, N, M, L );
        p.N=32; p.M=256; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 1 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_1_1, N, M, L );
        p.N=64; p.M=1; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 1 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_1_2, N, M, L );
        p.N=64; p.M=1; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 1 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_1_4, N, M, L );
        p.N=64; p.M=1; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 1 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_1_8, N, M, L );
        p.N=64; p.M=1; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 1 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_1_16, N, M, L );
        p.N=64; p.M=1; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 1 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_1_32, N, M, L );
        p.N=64; p.M=1; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 1 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_1_64, N, M, L );
        p.N=64; p.M=1; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 1 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_1_128, N, M, L );
        p.N=64; p.M=1; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 1 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_1_256, N, M, L );
        p.N=64; p.M=1; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 2 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_2_1, N, M, L );
        p.N=64; p.M=2; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 2 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_2_2, N, M, L );
        p.N=64; p.M=2; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 2 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_2_4, N, M, L );
        p.N=64; p.M=2; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 2 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_2_8, N, M, L );
        p.N=64; p.M=2; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 2 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_2_16, N, M, L );
        p.N=64; p.M=2; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 2 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_2_32, N, M, L );
        p.N=64; p.M=2; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 2 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_2_64, N, M, L );
        p.N=64; p.M=2; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 2 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_2_128, N, M, L );
        p.N=64; p.M=2; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 2 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_2_256, N, M, L );
        p.N=64; p.M=2; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 4 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_4_1, N, M, L );
        p.N=64; p.M=4; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 4 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_4_2, N, M, L );
        p.N=64; p.M=4; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 4 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_4_4, N, M, L );
        p.N=64; p.M=4; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 4 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_4_8, N, M, L );
        p.N=64; p.M=4; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 4 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_4_16, N, M, L );
        p.N=64; p.M=4; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 4 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_4_32, N, M, L );
        p.N=64; p.M=4; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 4 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_4_64, N, M, L );
        p.N=64; p.M=4; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 4 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_4_128, N, M, L );
        p.N=64; p.M=4; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 4 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_4_256, N, M, L );
        p.N=64; p.M=4; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 8 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_8_1, N, M, L );
        p.N=64; p.M=8; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 8 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_8_2, N, M, L );
        p.N=64; p.M=8; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 8 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_8_4, N, M, L );
        p.N=64; p.M=8; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 8 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_8_8, N, M, L );
        p.N=64; p.M=8; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 8 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_8_16, N, M, L );
        p.N=64; p.M=8; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 8 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_8_32, N, M, L );
        p.N=64; p.M=8; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 8 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_8_64, N, M, L );
        p.N=64; p.M=8; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 8 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_8_128, N, M, L );
        p.N=64; p.M=8; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 8 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_8_256, N, M, L );
        p.N=64; p.M=8; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 16 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_16_1, N, M, L );
        p.N=64; p.M=16; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 16 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_16_2, N, M, L );
        p.N=64; p.M=16; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 16 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_16_4, N, M, L );
        p.N=64; p.M=16; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 16 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_16_8, N, M, L );
        p.N=64; p.M=16; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 16 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_16_16, N, M, L );
        p.N=64; p.M=16; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 16 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_16_32, N, M, L );
        p.N=64; p.M=16; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 16 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_16_64, N, M, L );
        p.N=64; p.M=16; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 16 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_16_128, N, M, L );
        p.N=64; p.M=16; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 16 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_16_256, N, M, L );
        p.N=64; p.M=16; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 32 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_32_1, N, M, L );
        p.N=64; p.M=32; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 32 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_32_2, N, M, L );
        p.N=64; p.M=32; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 32 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_32_4, N, M, L );
        p.N=64; p.M=32; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 32 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_32_8, N, M, L );
        p.N=64; p.M=32; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 32 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_32_16, N, M, L );
        p.N=64; p.M=32; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 32 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_32_32, N, M, L );
        p.N=64; p.M=32; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 32 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_32_64, N, M, L );
        p.N=64; p.M=32; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 32 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_32_128, N, M, L );
        p.N=64; p.M=32; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 32 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_32_256, N, M, L );
        p.N=64; p.M=32; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 64 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_64_1, N, M, L );
        p.N=64; p.M=64; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 64 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_64_2, N, M, L );
        p.N=64; p.M=64; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 64 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_64_4, N, M, L );
        p.N=64; p.M=64; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 64 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_64_8, N, M, L );
        p.N=64; p.M=64; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 64 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_64_16, N, M, L );
        p.N=64; p.M=64; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 64 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_64_32, N, M, L );
        p.N=64; p.M=64; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 64 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_64_64, N, M, L );
        p.N=64; p.M=64; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 64 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_64_128, N, M, L );
        p.N=64; p.M=64; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 64 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_64_256, N, M, L );
        p.N=64; p.M=64; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 128 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_128_1, N, M, L );
        p.N=64; p.M=128; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 128 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_128_2, N, M, L );
        p.N=64; p.M=128; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 128 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_128_4, N, M, L );
        p.N=64; p.M=128; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 128 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_128_8, N, M, L );
        p.N=64; p.M=128; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 128 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_128_16, N, M, L );
        p.N=64; p.M=128; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 128 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_128_32, N, M, L );
        p.N=64; p.M=128; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 128 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_128_64, N, M, L );
        p.N=64; p.M=128; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 128 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_128_128, N, M, L );
        p.N=64; p.M=128; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 128 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_128_256, N, M, L );
        p.N=64; p.M=128; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 256 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_256_1, N, M, L );
        p.N=64; p.M=256; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 256 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_256_2, N, M, L );
        p.N=64; p.M=256; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 256 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_256_4, N, M, L );
        p.N=64; p.M=256; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 256 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_256_8, N, M, L );
        p.N=64; p.M=256; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 256 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_256_16, N, M, L );
        p.N=64; p.M=256; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 256 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_256_32, N, M, L );
        p.N=64; p.M=256; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 256 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_256_64, N, M, L );
        p.N=64; p.M=256; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 256 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_256_128, N, M, L );
        p.N=64; p.M=256; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 64 && M >= 256 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult64_256_256, N, M, L );
        p.N=64; p.M=256; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 1 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_1_1, N, M, L );
        p.N=128; p.M=1; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 1 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_1_2, N, M, L );
        p.N=128; p.M=1; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 1 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_1_4, N, M, L );
        p.N=128; p.M=1; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 1 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_1_8, N, M, L );
        p.N=128; p.M=1; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 1 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_1_16, N, M, L );
        p.N=128; p.M=1; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 1 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_1_32, N, M, L );
        p.N=128; p.M=1; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 1 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_1_64, N, M, L );
        p.N=128; p.M=1; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 1 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_1_128, N, M, L );
        p.N=128; p.M=1; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 1 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_1_256, N, M, L );
        p.N=128; p.M=1; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 2 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_2_1, N, M, L );
        p.N=128; p.M=2; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 2 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_2_2, N, M, L );
        p.N=128; p.M=2; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 2 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_2_4, N, M, L );
        p.N=128; p.M=2; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 2 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_2_8, N, M, L );
        p.N=128; p.M=2; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 2 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_2_16, N, M, L );
        p.N=128; p.M=2; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 2 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_2_32, N, M, L );
        p.N=128; p.M=2; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 2 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_2_64, N, M, L );
        p.N=128; p.M=2; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 2 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_2_128, N, M, L );
        p.N=128; p.M=2; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 2 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_2_256, N, M, L );
        p.N=128; p.M=2; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 4 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_4_1, N, M, L );
        p.N=128; p.M=4; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 4 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_4_2, N, M, L );
        p.N=128; p.M=4; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 4 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_4_4, N, M, L );
        p.N=128; p.M=4; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 4 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_4_8, N, M, L );
        p.N=128; p.M=4; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 4 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_4_16, N, M, L );
        p.N=128; p.M=4; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 4 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_4_32, N, M, L );
        p.N=128; p.M=4; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 4 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_4_64, N, M, L );
        p.N=128; p.M=4; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 4 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_4_128, N, M, L );
        p.N=128; p.M=4; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 4 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_4_256, N, M, L );
        p.N=128; p.M=4; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 8 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_8_1, N, M, L );
        p.N=128; p.M=8; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 8 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_8_2, N, M, L );
        p.N=128; p.M=8; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 8 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_8_4, N, M, L );
        p.N=128; p.M=8; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 8 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_8_8, N, M, L );
        p.N=128; p.M=8; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 8 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_8_16, N, M, L );
        p.N=128; p.M=8; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 8 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_8_32, N, M, L );
        p.N=128; p.M=8; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 8 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_8_64, N, M, L );
        p.N=128; p.M=8; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 8 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_8_128, N, M, L );
        p.N=128; p.M=8; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 8 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_8_256, N, M, L );
        p.N=128; p.M=8; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 16 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_16_1, N, M, L );
        p.N=128; p.M=16; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 16 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_16_2, N, M, L );
        p.N=128; p.M=16; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 16 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_16_4, N, M, L );
        p.N=128; p.M=16; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 16 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_16_8, N, M, L );
        p.N=128; p.M=16; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 16 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_16_16, N, M, L );
        p.N=128; p.M=16; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 16 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_16_32, N, M, L );
        p.N=128; p.M=16; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 16 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_16_64, N, M, L );
        p.N=128; p.M=16; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 16 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_16_128, N, M, L );
        p.N=128; p.M=16; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 16 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_16_256, N, M, L );
        p.N=128; p.M=16; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 32 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_32_1, N, M, L );
        p.N=128; p.M=32; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 32 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_32_2, N, M, L );
        p.N=128; p.M=32; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 32 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_32_4, N, M, L );
        p.N=128; p.M=32; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 32 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_32_8, N, M, L );
        p.N=128; p.M=32; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 32 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_32_16, N, M, L );
        p.N=128; p.M=32; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 32 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_32_32, N, M, L );
        p.N=128; p.M=32; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 32 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_32_64, N, M, L );
        p.N=128; p.M=32; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 32 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_32_128, N, M, L );
        p.N=128; p.M=32; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 32 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_32_256, N, M, L );
        p.N=128; p.M=32; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 64 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_64_1, N, M, L );
        p.N=128; p.M=64; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 64 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_64_2, N, M, L );
        p.N=128; p.M=64; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 64 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_64_4, N, M, L );
        p.N=128; p.M=64; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 64 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_64_8, N, M, L );
        p.N=128; p.M=64; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 64 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_64_16, N, M, L );
        p.N=128; p.M=64; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 64 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_64_32, N, M, L );
        p.N=128; p.M=64; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 64 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_64_64, N, M, L );
        p.N=128; p.M=64; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 64 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_64_128, N, M, L );
        p.N=128; p.M=64; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 64 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_64_256, N, M, L );
        p.N=128; p.M=64; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 128 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_128_1, N, M, L );
        p.N=128; p.M=128; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 128 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_128_2, N, M, L );
        p.N=128; p.M=128; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 128 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_128_4, N, M, L );
        p.N=128; p.M=128; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 128 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_128_8, N, M, L );
        p.N=128; p.M=128; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 128 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_128_16, N, M, L );
        p.N=128; p.M=128; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 128 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_128_32, N, M, L );
        p.N=128; p.M=128; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 128 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_128_64, N, M, L );
        p.N=128; p.M=128; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 128 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_128_128, N, M, L );
        p.N=128; p.M=128; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 128 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_128_256, N, M, L );
        p.N=128; p.M=128; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 256 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_256_1, N, M, L );
        p.N=128; p.M=256; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 256 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_256_2, N, M, L );
        p.N=128; p.M=256; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 256 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_256_4, N, M, L );
        p.N=128; p.M=256; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 256 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_256_8, N, M, L );
        p.N=128; p.M=256; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 256 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_256_16, N, M, L );
        p.N=128; p.M=256; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 256 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_256_32, N, M, L );
        p.N=128; p.M=256; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 256 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_256_64, N, M, L );
        p.N=128; p.M=256; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 256 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_256_128, N, M, L );
        p.N=128; p.M=256; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 128 && M >= 256 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult128_256_256, N, M, L );
        p.N=128; p.M=256; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 1 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_1_1, N, M, L );
        p.N=256; p.M=1; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 1 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_1_2, N, M, L );
        p.N=256; p.M=1; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 1 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_1_4, N, M, L );
        p.N=256; p.M=1; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 1 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_1_8, N, M, L );
        p.N=256; p.M=1; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 1 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_1_16, N, M, L );
        p.N=256; p.M=1; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 1 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_1_32, N, M, L );
        p.N=256; p.M=1; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 1 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_1_64, N, M, L );
        p.N=256; p.M=1; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 1 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_1_128, N, M, L );
        p.N=256; p.M=1; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 1 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_1_256, N, M, L );
        p.N=256; p.M=1; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 2 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_2_1, N, M, L );
        p.N=256; p.M=2; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 2 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_2_2, N, M, L );
        p.N=256; p.M=2; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 2 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_2_4, N, M, L );
        p.N=256; p.M=2; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 2 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_2_8, N, M, L );
        p.N=256; p.M=2; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 2 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_2_16, N, M, L );
        p.N=256; p.M=2; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 2 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_2_32, N, M, L );
        p.N=256; p.M=2; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 2 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_2_64, N, M, L );
        p.N=256; p.M=2; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 2 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_2_128, N, M, L );
        p.N=256; p.M=2; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 2 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_2_256, N, M, L );
        p.N=256; p.M=2; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 4 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_4_1, N, M, L );
        p.N=256; p.M=4; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 4 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_4_2, N, M, L );
        p.N=256; p.M=4; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 4 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_4_4, N, M, L );
        p.N=256; p.M=4; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 4 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_4_8, N, M, L );
        p.N=256; p.M=4; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 4 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_4_16, N, M, L );
        p.N=256; p.M=4; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 4 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_4_32, N, M, L );
        p.N=256; p.M=4; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 4 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_4_64, N, M, L );
        p.N=256; p.M=4; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 4 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_4_128, N, M, L );
        p.N=256; p.M=4; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 4 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_4_256, N, M, L );
        p.N=256; p.M=4; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 8 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_8_1, N, M, L );
        p.N=256; p.M=8; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 8 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_8_2, N, M, L );
        p.N=256; p.M=8; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 8 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_8_4, N, M, L );
        p.N=256; p.M=8; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 8 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_8_8, N, M, L );
        p.N=256; p.M=8; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 8 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_8_16, N, M, L );
        p.N=256; p.M=8; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 8 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_8_32, N, M, L );
        p.N=256; p.M=8; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 8 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_8_64, N, M, L );
        p.N=256; p.M=8; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 8 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_8_128, N, M, L );
        p.N=256; p.M=8; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 8 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_8_256, N, M, L );
        p.N=256; p.M=8; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 16 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_16_1, N, M, L );
        p.N=256; p.M=16; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 16 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_16_2, N, M, L );
        p.N=256; p.M=16; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 16 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_16_4, N, M, L );
        p.N=256; p.M=16; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 16 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_16_8, N, M, L );
        p.N=256; p.M=16; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 16 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_16_16, N, M, L );
        p.N=256; p.M=16; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 16 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_16_32, N, M, L );
        p.N=256; p.M=16; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 16 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_16_64, N, M, L );
        p.N=256; p.M=16; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 16 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_16_128, N, M, L );
        p.N=256; p.M=16; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 16 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_16_256, N, M, L );
        p.N=256; p.M=16; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 32 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_32_1, N, M, L );
        p.N=256; p.M=32; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 32 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_32_2, N, M, L );
        p.N=256; p.M=32; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 32 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_32_4, N, M, L );
        p.N=256; p.M=32; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 32 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_32_8, N, M, L );
        p.N=256; p.M=32; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 32 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_32_16, N, M, L );
        p.N=256; p.M=32; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 32 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_32_32, N, M, L );
        p.N=256; p.M=32; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 32 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_32_64, N, M, L );
        p.N=256; p.M=32; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 32 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_32_128, N, M, L );
        p.N=256; p.M=32; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 32 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_32_256, N, M, L );
        p.N=256; p.M=32; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 64 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_64_1, N, M, L );
        p.N=256; p.M=64; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 64 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_64_2, N, M, L );
        p.N=256; p.M=64; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 64 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_64_4, N, M, L );
        p.N=256; p.M=64; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 64 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_64_8, N, M, L );
        p.N=256; p.M=64; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 64 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_64_16, N, M, L );
        p.N=256; p.M=64; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 64 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_64_32, N, M, L );
        p.N=256; p.M=64; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 64 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_64_64, N, M, L );
        p.N=256; p.M=64; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 64 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_64_128, N, M, L );
        p.N=256; p.M=64; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 64 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_64_256, N, M, L );
        p.N=256; p.M=64; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 128 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_128_1, N, M, L );
        p.N=256; p.M=128; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 128 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_128_2, N, M, L );
        p.N=256; p.M=128; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 128 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_128_4, N, M, L );
        p.N=256; p.M=128; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 128 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_128_8, N, M, L );
        p.N=256; p.M=128; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 128 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_128_16, N, M, L );
        p.N=256; p.M=128; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 128 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_128_32, N, M, L );
        p.N=256; p.M=128; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 128 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_128_64, N, M, L );
        p.N=256; p.M=128; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 128 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_128_128, N, M, L );
        p.N=256; p.M=128; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 128 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_128_256, N, M, L );
        p.N=256; p.M=128; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 256 && L >= 1 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_256_1, N, M, L );
        p.N=256; p.M=256; p.L=1;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 256 && L >= 2 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_256_2, N, M, L );
        p.N=256; p.M=256; p.L=2;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 256 && L >= 4 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_256_4, N, M, L );
        p.N=256; p.M=256; p.L=4;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 256 && L >= 8 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_256_8, N, M, L );
        p.N=256; p.M=256; p.L=8;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 256 && L >= 16 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_256_16, N, M, L );
        p.N=256; p.M=256; p.L=16;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 256 && L >= 32 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_256_32, N, M, L );
        p.N=256; p.M=256; p.L=32;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 256 && L >= 64 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_256_64, N, M, L );
        p.N=256; p.M=256; p.L=64;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 256 && L >= 128 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_256_128, N, M, L );
        p.N=256; p.M=256; p.L=128;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    if ( N >= 256 && M >= 256 && L >= 256 )
    {
        p.mflops = runTest<ublas_matrix_type>( mult256_256_256, N, M, L );
        p.N=256; p.M=256; p.L=256;
        ps.push_back( p );
        cout << N << ", " << M << ", " << L << ", " << p.N << ", " << p.M << ", " << p.L << ", " << p.mflops << std::endl;
    }

    return ps;
}
