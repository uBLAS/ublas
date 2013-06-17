/** -*- c++ -*- \file mult.hpp \brief simple matrix multiplication */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector_expression.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>

#define M1S1 4
#define M2S2 3
#define M1M2 2
#define R 10


namespace ublas = boost::numeric::ublas;
using namespace ublas;

/***************************************************************************//**
 * @brief matrix multiplication
 * @param m1
 * @param m2
 * @param ret	- result matrix
 * @return[NONE]
 *
 */
template < class T >
void mult (const matrix<T>& m1, const matrix<T>& m2, matrix<T>& ret){
	size_t i, j, k;
	for( i=0; i<m1.size1(); i++ )
		for( j=0; j<m2.size2(); j++ ) {
			ret(i,j) = 0;
			for( k=0; k<m1.size2(); k++ )
				ret(i,j) += m1(i,k)*m2(k,j);
		}
}

