#ifndef MATRIX_MULTIPLY_HPP
#define MATRIX_MULTIPLY_HPP
#include <omp.h>
#include <boost/numeric/ublas/matrix.hpp>

namespace ublas = boost::numeric::ublas;

template <class Matrix_Type1, class Matrix_Type2>
void pack(Matrix_Type1 &M, const Matrix_Type2 &L,std::size_t i0, std::size_t j0, std::size_t h, std::size_t w ) {

    //  if (M.size1()!=h && M.size2()!=w) M.resize(h, w);

    for (std::size_t m = 0,i=i0; m!=h; i++, m++ )
        for (std::size_t n=0, j=j0; n!=w; j++, n++ ) {
            M(m,n) = L(i,j);
        }
}

template <class Matrix_Type1, class Matrix_Type2>
void pack(Matrix_Type1 &M, const Matrix_Type2 &L,std::size_t i0=0, std::size_t j0=0 ) {
    pack(M, L, i0, j0, L.size1(), L.size2());
}

template <class Matrix_Type1, class Matrix_Type2>
void trans(Matrix_Type1 &M, const Matrix_Type2 &L,std::size_t i0, std::size_t j0, std::size_t h, std::size_t w ) {

    //  if (M.size1()!=w && M.size2()!=h) M.resize(w, h);


    for (std::size_t m = 0,i=i0; m!=h; i++, m++ )
        for (std::size_t n=0, j=j0; n!=w; j++, n++ ) {
            M(m,n) = L(j,i);
        }
}

template <class Matrix_Type1, class Matrix_Type2>
void trans(Matrix_Type1 &M, const Matrix_Type2 &L,std::size_t i0=0, std::size_t j0=0 ) {
    trans(M, L, i0, j0, L.size1(), L.size2());
}

template <class Matrix_Type1, class Matrix_Type2>
void unpack(Matrix_Type1 &M, const Matrix_Type2 &L, std::size_t i0, std::size_t j0) {

    for (std::size_t m=0, i=i0; m!=L.size1(); m++, i++)
        for (std::size_t n=0,j=j0; n!=L.size2(); n++, j++)
            M(i,j) = L(m,n);
}

template <class Matrix_Type1, class Matrix_Type2>
inline void unpack_add(Matrix_Type1 &M, const Matrix_Type2 &L, std::size_t i0, std::size_t j0) {

    for (std::size_t m=0, i=i0; m!=L.size1(); m++, i++)
        for (std::size_t n=0,j=j0; n!=L.size2(); n++, j++)
            M(i,j) = L(m,n);
}


template <class Matrix_Type, class T>
void fill(Matrix_Type &M, T val=T()) {
    typedef typename Matrix_Type::size_type size_type;
    for (size_type i=0; i!=M.size1(); i++)
        for (size_type j=0; j!=M.size2(); j++)
            M(i,j) = val;
}

template < class MatrixType1, class MatrixType2, class MatrixType3>
void mult_nasos( MatrixType1 & A, MatrixType2& B, MatrixType3&C, std::size_t N, std::size_t M, std::size_t L )
{
    typedef typename MatrixType1::value_type value_type;

    ublas::matrix<value_type> Al( N, M);
    ublas::matrix<value_type> Bl( M, L);
    ublas::matrix<value_type> Cl( N, L);


    fill(C, 0.0); // This will bring C into the cache

    std::size_t i, j, k, ii, jj, kk;
    //  #pragma omp parallel for private(i, j, k, ii, jj, kk, Al, Bl, Cl) shared(A,B,C)
    for ( i = 0; i < A.size1(); i+=N) {
        for ( j=0; j < A.size2(); j+=L) {
            fill(Cl, 0.0);
            for (k=0; k < B.size2(); k += M) {
                pack(Al, A, i, k, N, M);
                pack(Bl, B, k, j, M, L);
                for (ii = 0; ii < N; ii++) {
                    for (kk = 0; kk != M; kk++) {
                        for ( jj = 0; jj < L; jj++) {
                            Cl(ii, jj) += Al(ii, kk) * Bl (kk,jj);

                        }
                    }
                }
            }
            unpack(C,Cl,i,j); // unpack Ci into C at position (i,j)
        }
    }


}

template < std::size_t N, std::size_t M, std::size_t L, class M1, class M2, class M3>
inline void multiply_add(const M1 &Al, const M2 &Bl, M3 &Cl)
{
    for ( std::size_t ii = 0; ii < N; ii++)
    {
        for ( std::size_t kk = 0; kk != M; kk++)
        {
            for ( std::size_t jj = 0; jj < L; jj++)
            {
                Cl(ii, jj) += Al(ii, kk) * Bl (kk,jj);
            }
        }
    }
}



template < std::size_t N, std::size_t M, std::size_t L, class MatrixType1, class MatrixType2, class MatrixType3>
void mat_mult( MatrixType1 & A, MatrixType2& B, MatrixType3&C )
{
    typedef typename MatrixType1::value_type value_type;

    typedef ublas::fixed_matrix<value_type, N, L> matNxL;
    typedef ublas::fixed_matrix<value_type, N, M> matNxM;
    typedef ublas::fixed_matrix<value_type, M, L> matMxL;

    for ( std::size_t i = 0; i < A.size1(); i+=N)
    {
#pragma omp parallel for
        for ( std::size_t j=0; j < B.size2(); j+=L)
        {
            matNxL Cl;
            fill(Cl, 0.0);
            for ( std::size_t k=0; k < B.size1(); k += M)
            {
                matNxM Al;
                pack(Al, A, i, k, N, M);

                matMxL Bl;
                pack(Bl, B, k, j, M, L);

                for ( std::size_t ii = 0; ii < N; ii++)
                {
                    for ( std::size_t kk = 0; kk != M; kk++)
                    {
                        for ( std::size_t jj = 0; jj < L; jj++)
                        {
                            Cl(ii, jj) += Al(ii, kk) * Bl (kk,jj);
                        }
                    }
                }

            }
            unpack( C, Cl, i, j); // unpack Ci into C at position (i,j)
        }
    }
}


#endif // MATRIX_MULTIPLY_HPP
