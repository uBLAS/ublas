//
//  Copyright (c) 2010 Athanasios Iliopoulos
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#define BOOST_ULBAS_CPP_GE_2011 // TODO: REMOVE THIS
#ifdef BOOST_ULBAS_CPP_GE_2011

#include "matrix_product_bench.hpp"
#include "fast_mult.hpp"
#include <functional>
#include <fstream>
#include <ios>


inline void eigenmultiply(const eigen_matrix_type &A, const eigen_matrix_type &B, eigen_matrix_type &C )
{
    C = A * B;
}

inline void ublas_legacy_multiply( const ublas_matrix_type &A, const ublas_matrix_type &B, ublas_matrix_type &C)
{
    if (A.size1()<=1024)
        noalias(C) = ublas::prod(A, B);
}

inline void ublas_fast_multiply( const ublas_matrix_type &A, const ublas_matrix_type &B, ublas_matrix_type &C)
{
    ublas::fast_matrix_multiply (C, A, B, true);
}

inline void nasos_mult( const ublas_matrix_type &A, const ublas_matrix_type &B, ublas_matrix_type &C)
{
    mult_nasos (A, B, C, 256, 16, 128);
}

inline void nasos_mult_v( const ublas_matrix_type &A, const ublas_matrix_type &B, ublas_matrix_type &C, size_t N, size_t M, size_t L)
{
    mult_nasos (A, B, C, N, M, L); // 256, 16, 128
}

inline void nasos_mult2( const ublas_matrix_type &A, const ublas_matrix_type &B, ublas_matrix_type &C)
{
    // Good choices:
    // 256 16 128
    // 256 32 128
    // 128 16 64
    // 128 16 128
    // 64 32 32

#if  1
#ifdef _OPENMP
    std::size_t num_threads;
#pragma omp parallel
    {
#pragma omp master
        {
            num_threads = omp_get_num_threads();
        }
    }
#else
    const std::size_t num_threads = 1;
#endif

    if ( num_threads == 1)
    {
        if ( A.size1() < 128 )
        {
            mult_nasos2<NNN/4,MMM/2,LLL/4> (A, B, C);
        } else if ( A.size1() < 256 )
        {
            mult_nasos2<NNN/2,MMM/2,LLL/2> (A, B, C);
        } else
        {
            mult_nasos2<NNN,MMM,LLL> (A, B, C);
        }
    } else
    {
        if ( A.size1() < 128 )
        {
            mult_nasos2<NNN/4,MMM,LLL/4> (A, B, C);
        } else if (A.size1() < 256)
        {
            mult_nasos2<NNN/2,MMM/2,LLL/4> (A, B, C);
        } else if ( A.size2() < 512 )
        {
            mult_nasos2<NNN/2,MMM/2,LLL/2> (A, B, C);
        } else  {
            mult_nasos2<NNN,MMM,LLL> (A, B, C);
        }
    }
# else
    mult_nasos2<NNN,MMM,LLL> (A, B, C);
#endif
}


inline void nasos_mult3( const ublas_matrix_type &A, const ublas_matrix_type &B, ublas_matrix_type &C)
{
    mult_nasos2<NNN,MMM,LLL> (A, B, C);
}


int main() {

    srand (time(NULL));

    cout << "uBLAS Matrix multiplication benchmakrs" << endl;
    cout << NNN << ", " << MMM << ", " << LLL << endl;

#ifdef _OPENMP
    cout << "using openmp" << endl;
#endif

    test_sizes sizes;
    test_names names;
    test_performances performances;

    /*sizes.push_back( 4 );
    sizes.push_back( 8 );
    sizes.push_back( 32 );
     sizes.push_back( 64 );
     sizes.push_back( 128 );*/
     sizes.push_back( 256 );
    for ( std::size_t i = 512; i<=2048; i+=512)
    {
        sizes.push_back( i );
    }

    ublas_matrix_type A(512,512),B(512,512),C(512,512), C2(512,512);

    randomFill( A );
    randomFill( B );
    noalias(C) = ublas::prod( A, B);

    nasos_mult2( A, B, C2 );

    cout << compare( C2, C ) << endl;
    cout << C( 233, 122) << ", " << C2( 233, 122) << endl;

    //runTest( sizes, names, performances, "ublas::prod" , ublas_legacy_multiply );
    runTest<eigen_matrix_type>( sizes, names, performances, "eigen3" , eigenmultiply );
    // runTest<ublas_matrix_type>( sizes, names, performances, "ublas::fast_prod" , ublas_fast_multiply );
    //runTest<ublas_matrix_type>( sizes, names, performances, "mult_nasos" , nasos_mult );
    runTest<ublas_matrix_type>( sizes, names, performances, "mult_nasos2" , nasos_mult3 );
    runTest<ublas_matrix_type>( sizes, names, performances, "mult_nasos4" , nasos_mult4 );

    //runStaticTest<NNN, MMM, LLL, ublas_matrix_type>( performances, "Static test NXMXL", nasos_mult3);

    double med = 0;
    auto last = performances.size()-1;
    for (std::size_t i=0; i!=performances[last].size(); i++)
    {
        med += performances[last][i];
    }

    med /= performances[last].size();

    std::size_t num_threads;
#pragma omp parallel
    {
#pragma omp master
        {
            num_threads = omp_get_num_threads();
        }
    }

//    std::ofstream ofile;
//    ofile.open ("res.txt", std::ios::app);
//    ofile << num_threads << ", " << NNN << ", " << MMM << ", " << num_threads*LLL << ", " << med << endl;
//    ofile.close();

    printResults( sizes, names, performances);

    return 0;
}

#else // !BOOST_ULBAS_CPP_GE_2011

#include <iostream>

using std::cout;    using std::cerr;   using std::endl;
int main() {

    cerr << "This benchmark needs C++11 support to compile." << endl;

    return 0;
}

#endif // BOOST_ULBAS_CPP_GE_2011
