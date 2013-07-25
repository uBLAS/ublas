/** -*- c++ -*- \file mult.hpp \brief test simple matrix multiplication */

#include "simple_mult.hpp"
#include "strassen_mult.hpp"

typedef double DBL;
using namespace std;

template< class T >
void print_matrix( const char* name, matrix<T>& m ) {
	size_t i, j;
	cout << "\n" << name << endl;
	for( i=0; i<m.size1(); i++ ) {
		cout << "( " ;
		for( j=0; j<m.size2(); j++ ) {
			cout << m(i,j) << " ";
		}
		cout << ")" << endl;
	}
}

/***************************************************************************//**
 * @brief random_init
 * @param m
 * @param r	- random interval between 0 and r+1
 * @return[NONE]
 *
 */
template< class T >
void random_init( matrix<T>& m, int r ) {
	size_t i, j;
	for( i=0; i<m.size1(); i++ ) {
		cout << endl;
		for( j=0; j<m.size2(); j++ ) {
			m(i,j) = (T)( rand() % (r+1) );
		}
	}
}

/***************************************************************************//**
 * @brief matrix multiplication
 * @param argc
 * @param argv
 * @return 0=success / 1=fail
 *
 */
template <class T>
void mult( int n, int m, int k, int r, T type) {
	//init m1 & m2 random values
	matrix<T> m1 (n,k);
	matrix<T> m2 (k,m);
	random_init(m1, r);
	random_init(m2, r);

	//print initial random matrice
	print_matrix("m1:", m1);
	print_matrix("m2:", m2);

	//matrix multiplication
	cout << "\n------------------------------\nSimple multiplication :" << endl;
	matrix<T> simple_ret (m1.size1(), m2.size2());
	simple_mult( m1, m2, simple_ret );
	print_matrix("return:", simple_ret);

	cout << "\n------------------------------\nStrassen multiplication :" << endl;
	matrix<T> strassen_ret (m1.size1(), m2.size2());
	strassen_mult( m1, m2, strassen_ret );
	print_matrix("return:", strassen_ret);

}
