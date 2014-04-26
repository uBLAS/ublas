#include "fast_mult.hpp"


void nasos_mult4( const ublas_matrix_type &A, const ublas_matrix_type &B, ublas_matrix_type &C)
{
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
    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 256 && B.size1() >= 256)
    {
        // 50314 Mflops
        // 16744448 floating operations
        mat_mult<128, 256, 256, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 128 && B.size1() >= 128)
    {
        // 45152 Mflops
        // 2088960 floating operations
        mat_mult<64, 128, 128, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 256 && A.size2() >= 128 && B.size1() >= 64)
    {
        // 44783 Mflops
        // 4177920 floating operations
        mat_mult<256, 128, 64, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 128 && B.size1() >= 64)
    {
        // 44227 Mflops
        // 2088960 floating operations
        mat_mult<128, 128, 64, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 32 && A.size2() >= 256 && B.size1() >= 128)
    {
        // 44171 Mflops
        // 2093056 floating operations
        mat_mult<32, 256, 128, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 256 && B.size1() >= 32)
    {
        // 42854 Mflops
        // 2093056 floating operations
        mat_mult<128, 256, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 64 && B.size1() >= 256)
    {
        // 42686 Mflops
        // 2080768 floating operations
        mat_mult<64, 64, 256, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 32 && A.size2() >= 64 && B.size1() >= 32)
    {
        // 41226 Mflops
        // 130048 floating operations
        mat_mult<32, 64, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 128 && B.size1() >= 128)
    {
        // 39694 Mflops
        // 2088960 floating operations
        mat_mult<64, 128, 128, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 128 && A.size2() >= 64 && B.size1() >= 256)
    {
        // 39254 Mflops
        // 4161536 floating operations
        mat_mult<128, 64, 256, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 256 && A.size2() >= 64 && B.size1() >= 128)
    {
        // 38793 Mflops
        // 4161536 floating operations
        mat_mult<256, 64, 128, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 32 && A.size2() >= 128 && B.size1() >= 16)
    {
        // 38413 Mflops
        // 130560 floating operations
        mat_mult<32, 128, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 256 && A.size2() >= 256 && B.size1() >= 32)
    {
        // 37053 Mflops
        // 4186112 floating operations
        mat_mult<256, 256, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 32 && B.size1() >= 32)
    {
        // 35834 Mflops
        // 129024 floating operations
        mat_mult<64, 32, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 16 && A.size2() >= 64 && B.size1() >= 32)
    {
        // 35724 Mflops
        // 65024 floating operations
        mat_mult<16, 64, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 128 && A.size2() >= 128 && B.size1() >= 64)
    {
        // 35083 Mflops
        // 2088960 floating operations
        mat_mult<128, 128, 64, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 32 && A.size2() >= 64 && B.size1() >= 32)
    {
        // 34829 Mflops
        // 130048 floating operations
        mat_mult<32, 64, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 32 && A.size2() >= 64 && B.size1() >= 16)
    {
        // 34511 Mflops
        // 65024 floating operations
        mat_mult<32, 64, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 16 && A.size2() >= 128 && B.size1() >= 16)
    {
        // 33962 Mflops
        // 65280 floating operations
        mat_mult<16, 128, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 32 && B.size1() >= 32)
    {
        // 32777 Mflops
        // 129024 floating operations
        mat_mult<64, 32, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 32 && A.size2() >= 32 && B.size1() >= 32)
    {
        // 32591 Mflops
        // 64512 floating operations
        mat_mult<32, 32, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 16 && A.size2() >= 64 && B.size1() >= 32)
    {
        // 29538 Mflops
        // 65024 floating operations
        mat_mult<16, 64, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 64 && A.size2() >= 256 && B.size1() >= 128)
    {
        // 29523 Mflops
        // 4186112 floating operations
        mat_mult<64, 256, 128, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 32 && B.size1() >= 16)
    {
        // 29505 Mflops
        // 64512 floating operations
        mat_mult<64, 32, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 64 && B.size1() >= 16)
    {
        // 29088 Mflops
        // 130048 floating operations
        mat_mult<64, 64, 16, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 128 && A.size2() >= 256 && B.size1() >= 64)
    {
        // 28530 Mflops
        // 4186112 floating operations
        mat_mult<128, 256, 64, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 64 && A.size2() >= 128 && B.size1() >= 128)
    {
        // 28086 Mflops
        // 2088960 floating operations
        mat_mult<64, 128, 128, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 256 && A.size2() >= 64 && B.size1() >= 256)
    {
        // 27778 Mflops
        // 8323072 floating operations
        mat_mult<256, 64, 256, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 32 && A.size2() >= 64 && B.size1() >= 16)
    {
        // 27557 Mflops
        // 65024 floating operations
        mat_mult<32, 64, 16, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 64 && A.size2() >= 256 && B.size1() >= 64)
    {
        // 27449 Mflops
        // 2093056 floating operations
        mat_mult<64, 256, 64, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 16 && A.size2() >= 128 && B.size1() >= 16)
    {
        // 27422 Mflops
        // 65280 floating operations
        mat_mult<16, 128, 16, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 32 && A.size2() >= 32 && B.size1() >= 16)
    {
        // 27306 Mflops
        // 32256 floating operations
        mat_mult<32, 32, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 128 && A.size2() >= 128 && B.size1() >= 64)
    {
        // 27135 Mflops
        // 2088960 floating operations
        mat_mult<128, 128, 64, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 512 && A.size2() >= 64 && B.size1() >= 128)
    {
        // 27092 Mflops
        // 8323072 floating operations
        mat_mult<512, 64, 128, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 64 && B.size1() >= 32)
    {
        // 26712 Mflops
        // 130048 floating operations
        mat_mult<32, 64, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 32 && B.size1() >= 16)
    {
        // 24966 Mflops
        // 64512 floating operations
        mat_mult<64, 32, 16, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 16 && A.size2() >= 32 && B.size1() >= 32)
    {
        // 24830 Mflops
        // 32256 floating operations
        mat_mult<16, 32, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 128 && A.size2() >= 16 && B.size1() >= 32)
    {
        // 24814 Mflops
        // 126976 floating operations
        mat_mult<128, 16, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 32 && A.size2() >= 16 && B.size1() >= 32)
    {
        // 23789 Mflops
        // 31744 floating operations
        mat_mult<32, 16, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 16 && A.size2() >= 64 && B.size1() >= 32)
    {
        // 23398 Mflops
        // 65024 floating operations
        mat_mult<16, 64, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 16 && B.size1() >= 16)
    {
        // 23051 Mflops
        // 63488 floating operations
        mat_mult<128, 16, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 16 && B.size1() >= 16)
    {
        // 21860 Mflops
        // 31744 floating operations
        mat_mult<64, 16, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 64 && B.size1() >= 16)
    {
        // 21661 Mflops
        // 65024 floating operations
        mat_mult<32, 64, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 8 && A.size2() >= 128 && B.size1() >= 16)
    {
        // 21536 Mflops
        // 32640 floating operations
        mat_mult<8, 128, 16, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 16 && B.size1() >= 32)
    {
        // 21512 Mflops
        // 63488 floating operations
        mat_mult<64, 16, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 32 && B.size1() >= 32)
    {
        // 21481 Mflops
        // 64512 floating operations
        mat_mult<32, 32, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 32 && A.size2() >= 16 && B.size1() >= 32)
    {
        // 19953 Mflops
        // 31744 floating operations
        mat_mult<32, 16, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 64 && A.size2() >= 32 && B.size1() >= 16)
    {
        // 19524 Mflops
        // 64512 floating operations
        mat_mult<64, 32, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 128 && A.size2() >= 16 && B.size1() >= 16)
    {
        // 19487 Mflops
        // 63488 floating operations
        mat_mult<128, 16, 16, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 16 && A.size2() >= 32 && B.size1() >= 32)
    {
        // 19349 Mflops
        // 32256 floating operations
        mat_mult<16, 32, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 32 && B.size1() >= 16)
    {
        // 17848 Mflops
        // 32256 floating operations
        mat_mult<32, 32, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 8 && A.size2() >= 64 && B.size1() >= 32)
    {
        // 17155 Mflops
        // 32512 floating operations
        mat_mult<8, 64, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 256 && A.size2() >= 8 && B.size1() >= 16)
    {
        // 16778 Mflops
        // 61440 floating operations
        mat_mult<256, 8, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 8 && B.size1() >= 32)
    {
        // 16645 Mflops
        // 61440 floating operations
        mat_mult<128, 8, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 8 && A.size2() >= 128 && B.size1() >= 16)
    {
        // 16069 Mflops
        // 32640 floating operations
        mat_mult<8, 128, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 8 && A.size2() >= 16 && B.size1() >= 32)
    {
        // 15864 Mflops
        // 7936 floating operations
        mat_mult<8, 16, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 8 && B.size1() >= 32)
    {
        // 15747 Mflops
        // 30720 floating operations
        mat_mult<64, 8, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 128 && A.size2() >= 16 && B.size1() >= 16)
    {
        // 15568 Mflops
        // 63488 floating operations
        mat_mult<128, 16, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 64 && A.size2() >= 256 && B.size1() >= 128)
    {
        // 15177 Mflops
        // 4186112 floating operations
        mat_mult<64, 256, 128, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 16 && B.size1() >= 32)
    {
        // 15032 Mflops
        // 31744 floating operations
        mat_mult<32, 16, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 64 && A.size2() >= 128 && B.size1() >= 256)
    {
        // 14956 Mflops
        // 4177920 floating operations
        mat_mult<64, 128, 256, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 16 && A.size2() >= 8 && B.size1() >= 256)
    {
        // 14945 Mflops
        // 61440 floating operations
        mat_mult<16, 8, 256, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 32 && A.size2() >= 64 && B.size1() >= 32)
    {
        // 14736 Mflops
        // 130048 floating operations
        mat_mult<32, 64, 32, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 8 && A.size2() >= 64 && B.size1() >= 16)
    {
        // 14686 Mflops
        // 16256 floating operations
        mat_mult<8, 64, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 64 && A.size2() >= 16 && B.size1() >= 16)
    {
        // 14542 Mflops
        // 31744 floating operations
        mat_mult<64, 16, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 14134 Mflops
        // 130560 floating operations
        mat_mult<128, 128, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 13995 Mflops
        // 65280 floating operations
        mat_mult<64, 128, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 8 && B.size1() >= 32)
    {
        // 13869 Mflops
        // 30720 floating operations
        mat_mult<64, 8, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 8 && B.size1() >= 16)
    {
        // 13850 Mflops
        // 15360 floating operations
        mat_mult<64, 8, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 8 && A.size2() >= 8 && B.size1() >= 256)
    {
        // 13766 Mflops
        // 30720 floating operations
        mat_mult<8, 8, 256, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 32 && A.size2() >= 64 && B.size1() >= 8)
    {
        // 13716 Mflops
        // 32512 floating operations
        mat_mult<32, 64, 8, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 32 && B.size1() >= 8)
    {
        // 13581 Mflops
        // 64512 floating operations
        mat_mult<128, 32, 8, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 32 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 12979 Mflops
        // 32640 floating operations
        mat_mult<32, 128, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 16 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 12941 Mflops
        // 32704 floating operations
        mat_mult<16, 256, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 128 && A.size2() >= 8 && B.size1() >= 16)
    {
        // 12917 Mflops
        // 30720 floating operations
        mat_mult<128, 8, 16, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 32 && B.size1() >= 8)
    {
        // 12902 Mflops
        // 32256 floating operations
        mat_mult<64, 32, 8, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 8 && A.size2() >= 16 && B.size1() >= 32)
    {
        // 12882 Mflops
        // 7936 floating operations
        mat_mult<8, 16, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 32 && A.size2() >= 8 && B.size1() >= 32)
    {
        // 12872 Mflops
        // 15360 floating operations
        mat_mult<32, 8, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 256 && A.size2() >= 32 && B.size1() >= 4)
    {
        // 12872 Mflops
        // 64512 floating operations
        mat_mult<256, 32, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 2 && A.size2() >= 128 && B.size1() >= 16)
    {
        // 12835 Mflops
        // 8160 floating operations
        mat_mult<2, 128, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 64 && B.size1() >= 4)
    {
        // 12801 Mflops
        // 65024 floating operations
        mat_mult<128, 64, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 8 && A.size2() >= 256 && B.size1() >= 8)
    {
        // 12541 Mflops
        // 32704 floating operations
        mat_mult<8, 256, 8, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 16 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 12307 Mflops
        // 16320 floating operations
        mat_mult<16, 128, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 32 && A.size2() >= 32 && B.size1() >= 8)
    {
        // 12161 Mflops
        // 16128 floating operations
        mat_mult<32, 32, 8, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 32 && B.size1() >= 4)
    {
        // 12030 Mflops
        // 32256 floating operations
        mat_mult<128, 32, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 64 && B.size1() >= 4)
    {
        // 11974 Mflops
        // 32512 floating operations
        mat_mult<64, 64, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 8 && A.size2() >= 8 && B.size1() >= 128)
    {
        // 11951 Mflops
        // 15360 floating operations
        mat_mult<8, 8, 128, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 16 && A.size2() >= 128 && B.size1() >= 16)
    {
        // 11852 Mflops
        // 65280 floating operations
        mat_mult<16, 128, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 8 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 11680 Mflops
        // 16352 floating operations
        mat_mult<8, 256, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 64 && A.size2() >= 32 && B.size1() >= 16)
    {
        // 11673 Mflops
        // 64512 floating operations
        mat_mult<64, 32, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 32 && B.size1() >= 4)
    {
        // 11605 Mflops
        // 16128 floating operations
        mat_mult<64, 32, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 32 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 11600 Mflops
        // 65408 floating operations
        mat_mult<32, 256, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 128 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 11186 Mflops
        // 130560 floating operations
        mat_mult<128, 128, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 16 && B.size1() >= 8)
    {
        // 11034 Mflops
        // 31744 floating operations
        mat_mult<128, 16, 8, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 16 && A.size2() >= 64 && B.size1() >= 16)
    {
        // 10990 Mflops
        // 32512 floating operations
        mat_mult<16, 64, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 32 && A.size2() >= 32 && B.size1() >= 16)
    {
        // 10955 Mflops
        // 32256 floating operations
        mat_mult<32, 32, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 10939 Mflops
        // 65280 floating operations
        mat_mult<64, 128, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 16 && A.size2() >= 128 && B.size1() >= 8)
    {
        // 10863 Mflops
        // 32640 floating operations
        mat_mult<16, 128, 8, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 128 && A.size2() >= 64 && B.size1() >= 4)
    {
        // 10652 Mflops
        // 65024 floating operations
        mat_mult<128, 64, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 32 && B.size1() >= 8)
    {
        // 10565 Mflops
        // 32256 floating operations
        mat_mult<64, 32, 8, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 8 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 10553 Mflops
        // 8160 floating operations
        mat_mult<8, 128, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 8 && A.size2() >= 8 && B.size1() >= 128)
    {
        // 10547 Mflops
        // 15360 floating operations
        mat_mult<8, 8, 128, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 32 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 10333 Mflops
        // 32640 floating operations
        mat_mult<32, 128, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 2 && A.size2() >= 32 && B.size1() >= 32)
    {
        // 10289 Mflops
        // 4032 floating operations
        mat_mult<2, 32, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 16 && B.size1() >= 8)
    {
        // 10289 Mflops
        // 15872 floating operations
        mat_mult<64, 16, 8, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 128 && A.size2() >= 8 && B.size1() >= 16)
    {
        // 10172 Mflops
        // 30720 floating operations
        mat_mult<128, 8, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 16 && A.size2() >= 8 && B.size1() >= 32)
    {
        // 10092 Mflops
        // 7680 floating operations
        mat_mult<16, 8, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 64 && B.size1() >= 4)
    {
        // 9929 Mflops
        // 32512 floating operations
        mat_mult<64, 64, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 16 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 9815 Mflops
        // 16320 floating operations
        mat_mult<16, 128, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 16 && A.size2() >= 4 && B.size1() >= 512)
    {
        // 9801 Mflops
        // 57344 floating operations
        mat_mult<16, 4, 512, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 8 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 9778 Mflops
        // 16352 floating operations
        mat_mult<8, 256, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 4 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 9758 Mflops
        // 8176 floating operations
        mat_mult<4, 256, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 32 && A.size2() >= 32 && B.size1() >= 8)
    {
        // 9736 Mflops
        // 16128 floating operations
        mat_mult<32, 32, 8, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 8 && A.size2() >= 64 && B.size1() >= 16)
    {
        // 9661 Mflops
        // 16256 floating operations
        mat_mult<8, 64, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 32 && B.size1() >= 4)
    {
        // 9641 Mflops
        // 16128 floating operations
        mat_mult<64, 32, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 8 && A.size2() >= 128 && B.size1() >= 8)
    {
        // 9635 Mflops
        // 16320 floating operations
        mat_mult<8, 128, 8, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 32 && A.size2() >= 64 && B.size1() >= 4)
    {
        // 9559 Mflops
        // 16256 floating operations
        mat_mult<32, 64, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 8 && B.size1() >= 32)
    {
        // 9492 Mflops
        // 15360 floating operations
        mat_mult<32, 8, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 256 && A.size2() >= 16 && B.size1() >= 4)
    {
        // 9457 Mflops
        // 31744 floating operations
        mat_mult<256, 16, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 4 && B.size1() >= 32)
    {
        // 9448 Mflops
        // 28672 floating operations
        mat_mult<128, 4, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 64 && A.size2() >= 8 && B.size1() >= 16)
    {
        // 9347 Mflops
        // 15360 floating operations
        mat_mult<64, 8, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 4 && A.size2() >= 16 && B.size1() >= 32)
    {
        // 9075 Mflops
        // 3968 floating operations
        mat_mult<4, 16, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 16 && A.size2() >= 4 && B.size1() >= 256)
    {
        // 9031 Mflops
        // 28672 floating operations
        mat_mult<16, 4, 256, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 64 && A.size2() >= 16 && B.size1() >= 16)
    {
        // 8965 Mflops
        // 31744 floating operations
        mat_mult<64, 16, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 32 && A.size2() >= 16 && B.size1() >= 32)
    {
        // 8964 Mflops
        // 31744 floating operations
        mat_mult<32, 16, 32, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 16 && B.size1() >= 4)
    {
        // 8928 Mflops
        // 15872 floating operations
        mat_mult<128, 16, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 16 && B.size1() >= 8)
    {
        // 8716 Mflops
        // 15872 floating operations
        mat_mult<64, 16, 8, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 16 && A.size2() >= 8 && B.size1() >= 256)
    {
        // 8660 Mflops
        // 61440 floating operations
        mat_mult<16, 8, 256, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 4 && B.size1() >= 32)
    {
        // 8637 Mflops
        // 14336 floating operations
        mat_mult<64, 4, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 4 && A.size2() >= 8 && B.size1() >= 128)
    {
        // 8414 Mflops
        // 7680 floating operations
        mat_mult<4, 8, 128, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 32 && A.size2() >= 16 && B.size1() >= 16)
    {
        // 8408 Mflops
        // 15872 floating operations
        mat_mult<32, 16, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 16 && A.size2() >= 16 && B.size1() >= 32)
    {
        // 8307 Mflops
        // 15872 floating operations
        mat_mult<16, 16, 32, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 64 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 8304 Mflops
        // 65280 floating operations
        mat_mult<64, 128, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 8288 Mflops
        // 65408 floating operations
        mat_mult<32, 256, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 8 && A.size2() >= 4 && B.size1() >= 256)
    {
        // 8138 Mflops
        // 14336 floating operations
        mat_mult<8, 4, 256, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 16 && A.size2() >= 128 && B.size1() >= 8)
    {
        // 8117 Mflops
        // 32640 floating operations
        mat_mult<16, 128, 8, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 4 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 8096 Mflops
        // 8176 floating operations
        mat_mult<4, 256, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 16 && B.size1() >= 4)
    {
        // 8050 Mflops
        // 7936 floating operations
        mat_mult<64, 16, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 16 && A.size2() >= 4 && B.size1() >= 256)
    {
        // 8029 Mflops
        // 28672 floating operations
        mat_mult<16, 4, 256, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 16 && A.size2() >= 8 && B.size1() >= 32)
    {
        // 7938 Mflops
        // 7680 floating operations
        mat_mult<16, 8, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 128 && A.size2() >= 64 && B.size1() >= 4)
    {
        // 7935 Mflops
        // 65024 floating operations
        mat_mult<128, 64, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 8 && A.size2() >= 8 && B.size1() >= 256)
    {
        // 7902 Mflops
        // 30720 floating operations
        mat_mult<8, 8, 256, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 256 && A.size2() >= 16 && B.size1() >= 4)
    {
        // 7860 Mflops
        // 31744 floating operations
        mat_mult<256, 16, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 4 && B.size1() >= 32)
    {
        // 7848 Mflops
        // 14336 floating operations
        mat_mult<64, 4, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 64 && A.size2() >= 32 && B.size1() >= 4)
    {
        // 7779 Mflops
        // 16128 floating operations
        mat_mult<64, 32, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 128 && A.size2() >= 4 && B.size1() >= 16)
    {
        // 7644 Mflops
        // 14336 floating operations
        mat_mult<128, 4, 16, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 32 && B.size1() >= 8)
    {
        // 7561 Mflops
        // 16128 floating operations
        mat_mult<32, 32, 8, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 64 && B.size1() >= 4)
    {
        // 7540 Mflops
        // 16256 floating operations
        mat_mult<32, 64, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 128 && A.size2() >= 16 && B.size1() >= 4)
    {
        // 7448 Mflops
        // 15872 floating operations
        mat_mult<128, 16, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 16 && A.size2() >= 64 && B.size1() >= 8)
    {
        // 7421 Mflops
        // 16256 floating operations
        mat_mult<16, 64, 8, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 4 && A.size2() >= 4 && B.size1() >= 256)
    {
        // 7418 Mflops
        // 7168 floating operations
        mat_mult<4, 4, 256, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 4 && A.size2() >= 16 && B.size1() >= 64)
    {
        // 7370 Mflops
        // 7936 floating operations
        mat_mult<4, 16, 64, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 16 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 7314 Mflops
        // 16320 floating operations
        mat_mult<16, 128, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 4 && A.size2() >= 32 && B.size1() >= 32)
    {
        // 7311 Mflops
        // 8064 floating operations
        mat_mult<4, 32, 32, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 16 && A.size2() >= 4 && B.size1() >= 128)
    {
        // 7307 Mflops
        // 14336 floating operations
        mat_mult<16, 4, 128, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 2 && A.size2() >= 128 && B.size1() >= 16)
    {
        // 7218 Mflops
        // 8160 floating operations
        mat_mult<2, 128, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 8 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 7108 Mflops
        // 16352 floating operations
        mat_mult<8, 256, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 4 && A.size2() >= 64 && B.size1() >= 16)
    {
        // 7028 Mflops
        // 8128 floating operations
        mat_mult<4, 64, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 2 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 6999 Mflops
        // 4088 floating operations
        mat_mult<2, 256, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 32 && B.size1() >= 4)
    {
        // 6957 Mflops
        // 8064 floating operations
        mat_mult<32, 32, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 32 && A.size2() >= 4 && B.size1() >= 32)
    {
        // 6940 Mflops
        // 7168 floating operations
        mat_mult<32, 4, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 4 && A.size2() >= 16 && B.size1() >= 32)
    {
        // 6915 Mflops
        // 3968 floating operations
        mat_mult<4, 16, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 8 && A.size2() >= 8 && B.size1() >= 64)
    {
        // 6827 Mflops
        // 7680 floating operations
        mat_mult<8, 8, 64, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 2 && A.size2() >= 8 && B.size1() >= 128)
    {
        // 6775 Mflops
        // 3840 floating operations
        mat_mult<2, 8, 128, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 16 && B.size1() >= 4)
    {
        // 6707 Mflops
        // 7936 floating operations
        mat_mult<64, 16, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 8 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 6642 Mflops
        // 8160 floating operations
        mat_mult<8, 128, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 16 && A.size2() >= 4 && B.size1() >= 64)
    {
        // 6598 Mflops
        // 7168 floating operations
        mat_mult<16, 4, 64, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 64 && A.size2() >= 8 && B.size1() >= 16)
    {
        // 6595 Mflops
        // 15360 floating operations
        mat_mult<64, 8, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 128 && A.size2() >= 16 && B.size1() >= 4)
    {
        // 6474 Mflops
        // 15872 floating operations
        mat_mult<128, 16, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 2 && A.size2() >= 32 && B.size1() >= 32)
    {
        // 6419 Mflops
        // 4032 floating operations
        mat_mult<2, 32, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 4 && A.size2() >= 4 && B.size1() >= 256)
    {
        // 6392 Mflops
        // 7168 floating operations
        mat_mult<4, 4, 256, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 256 && A.size2() >= 8 && B.size1() >= 4)
    {
        // 6101 Mflops
        // 15360 floating operations
        mat_mult<256, 8, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 32 && A.size2() >= 8 && B.size1() >= 16)
    {
        // 6098 Mflops
        // 7680 floating operations
        mat_mult<32, 8, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 64 && A.size2() >= 16 && B.size1() >= 4)
    {
        // 5971 Mflops
        // 7936 floating operations
        mat_mult<64, 16, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 2 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 5882 Mflops
        // 4088 floating operations
        mat_mult<2, 256, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 4 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 5882 Mflops
        // 8176 floating operations
        mat_mult<4, 256, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 2 && A.size2() >= 16 && B.size1() >= 128)
    {
        // 5829 Mflops
        // 7936 floating operations
        mat_mult<2, 16, 128, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 128 && A.size2() >= 4 && B.size1() >= 16)
    {
        // 5762 Mflops
        // 14336 floating operations
        mat_mult<128, 4, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 2 && A.size2() >= 4 && B.size1() >= 256)
    {
        // 5758 Mflops
        // 3584 floating operations
        mat_mult<2, 4, 256, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 64 && A.size2() >= 4 && B.size1() >= 32)
    {
        // 5666 Mflops
        // 14336 floating operations
        mat_mult<64, 4, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 4 && B.size1() >= 32)
    {
        // 5274 Mflops
        // 7168 floating operations
        mat_mult<32, 4, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 16 && A.size2() >= 4 && B.size1() >= 256)
    {
        // 5188 Mflops
        // 28672 floating operations
        mat_mult<16, 4, 256, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 2 && A.size2() >= 4 && B.size1() >= 256)
    {
        // 5076 Mflops
        // 3584 floating operations
        mat_mult<2, 4, 256, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 8 && A.size2() >= 4 && B.size1() >= 256)
    {
        // 5021 Mflops
        // 14336 floating operations
        mat_mult<8, 4, 256, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 16 && A.size2() >= 4 && B.size1() >= 128)
    {
        // 4988 Mflops
        // 14336 floating operations
        mat_mult<16, 4, 128, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 2 && A.size2() >= 32 && B.size1() >= 32)
    {
        // 4879 Mflops
        // 4032 floating operations
        mat_mult<2, 32, 32, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 2 && A.size2() >= 8 && B.size1() >= 128)
    {
        // 4852 Mflops
        // 3840 floating operations
        mat_mult<2, 8, 128, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 256 && A.size2() >= 2 && B.size1() >= 16)
    {
        // 4681 Mflops
        // 12288 floating operations
        mat_mult<256, 2, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 32 && A.size2() >= 2 && B.size1() >= 256)
    {
        // 4607 Mflops
        // 24576 floating operations
        mat_mult<32, 2, 256, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 2 && A.size2() >= 64 && B.size1() >= 16)
    {
        // 4559 Mflops
        // 4064 floating operations
        mat_mult<2, 64, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 16 && A.size2() >= 4 && B.size1() >= 64)
    {
        // 4532 Mflops
        // 7168 floating operations
        mat_mult<16, 4, 64, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 16 && A.size2() >= 2 && B.size1() >= 256)
    {
        // 4523 Mflops
        // 12288 floating operations
        mat_mult<16, 2, 256, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 32 && A.size2() >= 8 && B.size1() >= 8)
    {
        // 4521 Mflops
        // 3840 floating operations
        mat_mult<32, 8, 8, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 4 && A.size2() >= 4 && B.size1() >= 256)
    {
        // 4482 Mflops
        // 7168 floating operations
        mat_mult<4, 4, 256, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 2 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 4391 Mflops
        // 4088 floating operations
        mat_mult<2, 256, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 8 && A.size2() >= 2 && B.size1() >= 256)
    {
        // 4337 Mflops
        // 6144 floating operations
        mat_mult<8, 2, 256, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 128 && A.size2() >= 8 && B.size1() >= 4)
    {
        // 4333 Mflops
        // 7680 floating operations
        mat_mult<128, 8, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 32 && A.size2() >= 32 && B.size1() >= 4)
    {
        // 4319 Mflops
        // 8064 floating operations
        mat_mult<32, 32, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 16 && A.size2() >= 64 && B.size1() >= 8)
    {
        // 4252 Mflops
        // 16256 floating operations
        mat_mult<16, 64, 8, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 128 && A.size2() >= 4 && B.size1() >= 16)
    {
        // 4194 Mflops
        // 14336 floating operations
        mat_mult<128, 4, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 16 && A.size2() >= 4 && B.size1() >= 32)
    {
        // 4180 Mflops
        // 3584 floating operations
        mat_mult<16, 4, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 16 && A.size2() >= 32 && B.size1() >= 8)
    {
        // 4132 Mflops
        // 8064 floating operations
        mat_mult<16, 32, 8, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 2 && B.size1() >= 16)
    {
        // 4078 Mflops
        // 6144 floating operations
        mat_mult<128, 2, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 8 && A.size2() >= 256 && B.size1() >= 4)
    {
        // 4029 Mflops
        // 16352 floating operations
        mat_mult<8, 256, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 128 && A.size2() >= 2 && B.size1() >= 32)
    {
        // 3993 Mflops
        // 12288 floating operations
        mat_mult<128, 2, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 8 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 3920 Mflops
        // 8160 floating operations
        mat_mult<8, 128, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 16 && A.size2() >= 64 && B.size1() >= 4)
    {
        // 3917 Mflops
        // 8128 floating operations
        mat_mult<16, 64, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 4 && B.size1() >= 8)
    {
        // 3911 Mflops
        // 7168 floating operations
        mat_mult<128, 4, 8, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 128 && A.size2() >= 16 && B.size1() >= 4)
    {
        // 3908 Mflops
        // 15872 floating operations
        mat_mult<128, 16, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 16 && A.size2() >= 32 && B.size1() >= 4)
    {
        // 3816 Mflops
        // 4032 floating operations
        mat_mult<16, 32, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 512 && A.size2() >= 4 && B.size1() >= 4)
    {
        // 3743 Mflops
        // 14336 floating operations
        mat_mult<512, 4, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 64 && A.size2() >= 2 && B.size1() >= 32)
    {
        // 3732 Mflops
        // 6144 floating operations
        mat_mult<64, 2, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 64 && A.size2() >= 2 && B.size1() >= 16)
    {
        // 3707 Mflops
        // 3072 floating operations
        mat_mult<64, 2, 16, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 32 && A.size2() >= 2 && B.size1() >= 64)
    {
        // 3673 Mflops
        // 6144 floating operations
        mat_mult<32, 2, 64, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 2 && A.size2() >= 16 && B.size1() >= 32)
    {
        // 3649 Mflops
        // 1984 floating operations
        mat_mult<2, 16, 32, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 64 && A.size2() >= 16 && B.size1() >= 4)
    {
        // 3648 Mflops
        // 7936 floating operations
        mat_mult<64, 16, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 2 && A.size2() >= 4 && B.size1() >= 256)
    {
        // 3636 Mflops
        // 3584 floating operations
        mat_mult<2, 4, 256, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 4 && A.size2() >= 2 && B.size1() >= 512)
    {
        // 3598 Mflops
        // 6144 floating operations
        mat_mult<4, 2, 512, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 32 && A.size2() >= 4 && B.size1() >= 16)
    {
        // 3475 Mflops
        // 3584 floating operations
        mat_mult<32, 4, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 4 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 3464 Mflops
        // 4080 floating operations
        mat_mult<4, 128, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 8 && A.size2() >= 2 && B.size1() >= 128)
    {
        // 3357 Mflops
        // 3072 floating operations
        mat_mult<8, 2, 128, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 32 && A.size2() >= 2 && B.size1() >= 32)
    {
        // 3315 Mflops
        // 3072 floating operations
        mat_mult<32, 2, 32, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 4 && A.size2() >= 8 && B.size1() >= 32)
    {
        // 3314 Mflops
        // 1920 floating operations
        mat_mult<4, 8, 32, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 32 && A.size2() >= 16 && B.size1() >= 4)
    {
        // 3306 Mflops
        // 3968 floating operations
        mat_mult<32, 16, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 4 && A.size2() >= 2 && B.size1() >= 256)
    {
        // 3304 Mflops
        // 3072 floating operations
        mat_mult<4, 2, 256, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 256 && A.size2() >= 4 && B.size1() >= 4)
    {
        // 3279 Mflops
        // 7168 floating operations
        mat_mult<256, 4, 4, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 3 && A.size1() >= 128 && A.size2() >= 2 && B.size1() >= 16)
    {
        // 3260 Mflops
        // 6144 floating operations
        mat_mult<128, 2, 16, 3>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 256 && A.size2() >= 4 && B.size1() >= 4)
    {
        // 3234 Mflops
        // 7168 floating operations
        mat_mult<256, 4, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 16 && A.size2() >= 2 && B.size1() >= 32)
    {
        // 3109 Mflops
        // 1536 floating operations
        mat_mult<16, 2, 32, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 8 && B.size1() >= 4)
    {
        // 2978 Mflops
        // 1920 floating operations
        mat_mult<32, 8, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 128 && A.size2() >= 2 && B.size1() >= 16)
    {
        // 2935 Mflops
        // 6144 floating operations
        mat_mult<128, 2, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 2 && A.size2() >= 8 && B.size1() >= 64)
    {
        // 2796 Mflops
        // 1920 floating operations
        mat_mult<2, 8, 64, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 16 && A.size2() >= 16 && B.size1() >= 4)
    {
        // 2770 Mflops
        // 1984 floating operations
        mat_mult<16, 16, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 64 && A.size2() >= 8 && B.size1() >= 4)
    {
        // 2694 Mflops
        // 3840 floating operations
        mat_mult<64, 8, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 4 && A.size2() >= 4 && B.size1() >= 256)
    {
        // 2624 Mflops
        // 7168 floating operations
        mat_mult<4, 4, 256, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 64 && A.size2() >= 2 && B.size1() >= 16)
    {
        // 2612 Mflops
        // 3072 floating operations
        mat_mult<64, 2, 16, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 8 && A.size2() >= 2 && B.size1() >= 256)
    {
        // 2603 Mflops
        // 6144 floating operations
        mat_mult<8, 2, 256, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 4 && A.size2() >= 2 && B.size1() >= 512)
    {
        // 2570 Mflops
        // 6144 floating operations
        mat_mult<4, 2, 512, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 4 && A.size2() >= 4 && B.size1() >= 128)
    {
        // 2547 Mflops
        // 3584 floating operations
        mat_mult<4, 4, 128, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 2 && A.size2() >= 128 && B.size1() >= 4)
    {
        // 2522 Mflops
        // 2040 floating operations
        mat_mult<2, 128, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 16 && A.size2() >= 2 && B.size1() >= 64)
    {
        // 2455 Mflops
        // 3072 floating operations
        mat_mult<16, 2, 64, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 32 && A.size2() >= 2 && B.size1() >= 32)
    {
        // 2381 Mflops
        // 3072 floating operations
        mat_mult<32, 2, 32, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 64 && A.size2() >= 4 && B.size1() >= 4)
    {
        // 2374 Mflops
        // 1792 floating operations
        mat_mult<64, 4, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 4 && A.size2() >= 4 && B.size1() >= 64)
    {
        // 2360 Mflops
        // 1792 floating operations
        mat_mult<4, 4, 64, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 4 && A.size2() >= 2 && B.size1() >= 256)
    {
        // 2325 Mflops
        // 3072 floating operations
        mat_mult<4, 2, 256, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 2 && A.size2() >= 4 && B.size1() >= 128)
    {
        // 2161 Mflops
        // 1792 floating operations
        mat_mult<2, 4, 128, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 64 && A.size2() >= 2 && B.size1() >= 16)
    {
        // 2091 Mflops
        // 3072 floating operations
        mat_mult<64, 2, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 32 && A.size2() >= 8 && B.size1() >= 4)
    {
        // 2076 Mflops
        // 1920 floating operations
        mat_mult<32, 8, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 8 && A.size2() >= 2 && B.size1() >= 64)
    {
        // 2059 Mflops
        // 1536 floating operations
        mat_mult<8, 2, 64, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 64 && A.size2() >= 4 && B.size1() >= 4)
    {
        // 2018 Mflops
        // 1792 floating operations
        mat_mult<64, 4, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 32 && A.size2() >= 2 && B.size1() >= 16)
    {
        // 1892 Mflops
        // 1536 floating operations
        mat_mult<32, 2, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 2 && A.size1() >= 256 && A.size2() >= 2 && B.size1() >= 4)
    {
        // 1822 Mflops
        // 3072 floating operations
        mat_mult<256, 2, 4, 2>(A, B, C);
        return;
    }

    if ( num_threads >= 4 && A.size1() >= 128 && A.size2() >= 2 && B.size1() >= 4)
    {
        // 1680 Mflops
        // 1536 floating operations
        mat_mult<128, 2, 4, 0>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 16 && A.size2() >= 2 && B.size1() >= 16)
    {
        // 1465 Mflops
        // 768 floating operations
        mat_mult<16, 2, 16, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 4 && A.size2() >= 2 && B.size1() >= 256)
    {
        // 1398 Mflops
        // 3072 floating operations
        mat_mult<4, 2, 256, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 8 && A.size2() >= 2 && B.size1() >= 64)
    {
        // 1393 Mflops
        // 1536 floating operations
        mat_mult<8, 2, 64, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 4 && A.size2() >= 2 && B.size1() >= 128)
    {
        // 1281 Mflops
        // 1536 floating operations
        mat_mult<4, 2, 128, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 128 && A.size2() >= 2 && B.size1() >= 4)
    {
        // 1260 Mflops
        // 1536 floating operations
        mat_mult<128, 2, 4, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 2 && A.size2() >= 2 && B.size1() >= 256)
    {
        // 1249 Mflops
        // 1536 floating operations
        mat_mult<2, 2, 256, 1>(A, B, C);
        return;
    }

    if ( num_threads >= 1 && A.size1() >= 64 && A.size2() >= 2 && B.size1() >= 4)
    {
        // 1200 Mflops
        // 768 floating operations
        mat_mult<64, 2, 4, 1>(A, B, C);
        return;
    }

    mat_mult<4,4,4,1>(A,B,C);


}
