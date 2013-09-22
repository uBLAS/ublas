#include "SampleDouble.hpp"
#include "Controller.hpp"
#include "MaestroController.hpp"
#include "debug.h"
#include "matrix.hpp"
#include <iostream>
#include <omp.h>

using namespace boost::numeric::ublas::distributed;


void print( matrix<double>& m )
{
	for( unsigned int i=0,j=0; i<m.size1(); i++ )
	{
		for( j=0; j<m.size2(); j++ )
			std::cout << m.at_element(i,j);
		std::cout << "\n";
	}
}


int main( int argc, char** argv )
{
	MaestroController::init(argc, argv);

	Controller* c1 = new Controller({1});
	Controller* c2 = new Controller();

	/***********************************************************************//**
	 * @brief SampleDouble - basic example to use the distributed method
	 */
	SampleDouble t1(20.0,c1);
	SampleDouble t2(-2.0,c1);
	SampleDouble t3 = t1+t2;
	c1->flush();
	std::cout << "------------------\nSampleDouble - basic example to use the distributed method\n";
	std::cout << t1.m_d << " + " << t2.m_d << " = " << t3.m_d;

	/***********************************************************************//**
	 * @brief boost::numeric::ublas::distributed::matrix
	 */
	matrix<double> m1(4,4,4,c1);
	matrix<double> m2(4,4,1,c1);
	for( int i=0,j=0; i<4; i++ )
		for( j=0; j<4; j++ )
			m2.at_element(i,j) = j+1;
	matrix<double> m3(4,4,0,c1);
	matrix<double> m4(4,4,0,c1);
	matrix<double> m5(4,4,0,c2);
	matrix<double> m6(4,4,0,c2);
	// Matrix-matrix multiplication/division are not yet available
	m3 = m1-m2;
	m4 = m1*2;
	m5 = m1+m2;
	m6 = m1/2;
	// We flush in thread
	#pragma omp for
	for( int i=0; i<2; i++ ){
		if( i==0 ){
			c1->flush();
		}
		if( i==1 ){
			c2->flush();
		}
	}
	//print
	std::cout << "\n------------------\nboost::numeric::ublas::distributed::matrix\n";
	std::cout << "M1\n";
	print(m1);
	std::cout << "M2\n";
	print(m2);
	std::cout << "M3=m1-m2\n";
	print(m3);
	std::cout << "M4=m1*2\n";
	print(m4);
	std::cout << "M5=m1+m2\n";
	print(m5);
	std::cout << "M6=m1/2\n";
	print(m6);
	std::cout << "------------------\n";

	MaestroController::shutdown();
	return 0;
}
