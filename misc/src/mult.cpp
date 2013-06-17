/** -*- c++ -*- \file mult.hpp \brief test simple matrix multiplication */

#include "mult.hpp"

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
 * @brief main
 * @param argc
 * @param argv
 * @return 0=success / 1=fail
 *
 */
int main( int argc, char** argv ) {

	//init time
	srand(time(NULL));

	//parameters declaration
	int n=M1S1, m=M2S2, k=M1M2, r=R;
	if( argc >= 4){
		n = atoi(argv[1]);
		m = atoi(argv[2]);
		k = atoi(argv[3]);
		if( argc == 5) r = atoi(argv[4]);
	}
	else if( argc>1 && argc<4 ) return 1;

	/* INT */
	//init m1 & m2 random values
	matrix<int> m1 (n,k);
	matrix<int> m2 (k,m);
	random_init(m1, r);
	random_init(m2, r);
	//print initial random matrice
	print_matrix("m1:", m1);
	print_matrix("m2:", m2);
	//matrix multiplication
	matrix<int> ret (m1.size1(), m2.size2());
	mult( m1, m2, ret );
	print_matrix("return:", ret);

	/* DOUBLE */
	//init m1 & m2 random values
	matrix<DBL> DBLm1 (n,k);
	matrix<DBL> DBLm2 (k,m);
	random_init(DBLm1, r);
	random_init(DBLm2, r);
	//print initial random matrice
	print_matrix("DBLm1:", DBLm1);
	print_matrix("DBLm2:", DBLm2);
	//matrix multiplication
	matrix<DBL> DBLret (DBLm1.size1(), DBLm2.size2());
	mult( DBLm1, DBLm2, DBLret );
	print_matrix("return:", DBLret);

	return 0;
}
