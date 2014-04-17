#ifndef MATRIX_PRODUCT_BENCH_HPP
#define MATRIX_PRODUCT_BENCH_HPP

#include <boost/numeric/ublas/assignment.hpp>
#include <boost/numeric/ublas/experimental/fast_matrix_multiplication.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <chrono>
#include <iomanip>
#include <time.h>
#include <stdlib.h> // for rand
#include <vector>
#include <string>
#include <functional>
#include <typeinfo>
#include <map>
#include <eigen3/Eigen/Eigen>


namespace ublas = boost::numeric::ublas;

using std::cout;    using std::cerr;   using std::endl; using std::setw;


// Measuring time
std::chrono::high_resolution_clock::time_point tic()
{
    using namespace std::chrono;
    return std::chrono::high_resolution_clock::now();
}

double toc( std::chrono::high_resolution_clock::time_point start)
{
    using namespace std::chrono;
    return duration_cast< duration<double> >( tic() - start ).count() ;
}



template <class T, int R, int C>
void randomFill( Eigen::Matrix<T, R, C> &m)
{
    typedef std::size_t   size_type;

    for ( size_type i = 0; i != m.rows(); i++ )
    {
        for ( size_type j = 0; j != m.cols(); j++ )
        {
            m( i, j ) = 10.0 * rand() /RAND_MAX;
        }
    }
}

template <class MatrixType>
void randomFill( MatrixType &m)
{
    typedef typename MatrixType::size_type   size_type;

    for ( size_type i = 0; i != m.size1(); i++ )
    {
        for ( size_type j = 0; j != m.size1(); j++ )
        {
            m( i, j ) = 10.0 * rand() /RAND_MAX;
        }
    }
}

double mflops(std::size_t size, double duration) {
    return (size*size*size)/(duration)/1000000.0;
}

typedef  double                     value_type;
typedef ublas::matrix< value_type > ublas_matrix_type;
typedef Eigen::Matrix<value_type, Eigen::Dynamic, Eigen::Dynamic> eigen_matrix_type;
typedef ublas_matrix_type::size_type      size_type;

typedef std::vector< std::size_t > test_sizes;
typedef std::vector< std::string  > test_names;
typedef std::vector< std::vector<double> > test_performances;

template <class MatrixType, class F>
void runTest(test_sizes &sizes, test_names &names, test_performances &performances, std::string name, F f) {

    cout << "Runing: " << name << endl;

    names.push_back( name );
    std::vector<double> performance;

    auto start = tic();
    for ( test_sizes::size_type i = 0; i < sizes.size(); i++ )
    {
        auto s = sizes[ i ];

        MatrixType A( s, s ), B(s, s), C( s, s );
        randomFill( A );
        randomFill( B );

        double duration = 0;

        std::size_t count = 0;

        start = tic();

        while( duration < 0.5 )
        {
            f(A, B, C);
            //noalias(C) = ublas::prod(A, B);
            duration = toc( start );
            count++;
        }

        performance.push_back(  mflops( s, duration/count ) );
        cout << s << ", " << mflops( s, duration/count ) << endl;
    }

    performances.push_back( performance );

}

void printResults( test_sizes sizes , test_names names, test_performances performances)
{
    cout << "Results in Mflops" << endl;

    cout << setw(6) << "Size";

    for ( std::size_t i = 0; i < names.size(); i++)
    {
        cout << setw(20) << names[ i ];
    }

    cout << endl;

    for ( std::size_t i = 0; i< sizes.size(); i++)
    {
        cout << setw( 6 ) << sizes[ i ];
        for (std::size_t j = 0; j < performances.size(); j++)
        {
            cout << setw(20) << performances[j][i];
        }
        cout << endl;
    }
}

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
void mult_nasos2( MatrixType1 & A, MatrixType2& B, MatrixType3&C )
{
    typedef typename MatrixType1::value_type value_type;

    for ( std::size_t i = 0; i < A.size1(); i+=N)
    {
#pragma omp parallel for
        for ( std::size_t j=0; j < A.size2(); j+=L)
        {
            ublas::fixed_matrix<value_type, N, L> Cl;
            fill(Cl, 0.0);
            for ( std::size_t k=0; k < B.size2(); k += M)
            {
                ublas::fixed_matrix<value_type, N, M> Al;
                pack(Al, A, i, k, N, M);

                ublas::fixed_matrix<value_type, M, L> Bl;
                pack(Bl, B, k, j, M, L);

                //multiply_add<N, M, L>( Al, Bl, Cl);

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



template <class AE>
typename AE::value_type mean_square(const ublas::matrix_expression<AE> &me) {
    using namespace ublas;
    typename AE::value_type s(0);
    typename AE::size_type i, j;
    for (i=0; i!= me().size1(); i++) {
        for (j=0; j!= me().size2(); j++) {
          s+= scalar_traits<typename AE::value_type>::type_abs(me()(i,j));
        }
    }
    return s/me().size1()*me().size2();
}

template < class M1, class M2 >
bool compare( const boost::numeric::ublas::matrix_expression<M1> & m1,
              const boost::numeric::ublas::matrix_expression<M2> & m2 ) {
  size_t size1 = (std::min)(m1().size1(), m2().size1());
  size_t size2 = (std::min)(m1().size2(), m2().size2());
  for (size_t i=0; i < size1; ++i) {
    for (size_t j=0; j < size2; ++j) {
      if ( fabs( m1()(i,j) - m2()(i,j)) > 1e-6 )
      {
          cout << m1()(i,j) << ", " << m2()(i,j) << endl;
          return false;
      }
    }
  }
  return true;
}


#endif // MATRIX_PRODUCT_BENCH_HPP
