/// @file vector.hpp Definition for the distributed class vector
#ifndef _BOOST_UBLAS_DISTRIBUTED_VECTOR_
#define _BOOST_UBLAS_DISTRIBUTED_VECTOR_

#include "Controller.hpp"

namespace boost { namespace numeric { namespace ublas { namespace distributed {

template< class T, class PoT>
//template< class T, class PoT, class A> //A pour le type du vecteur (actuellement std::vector)
class vector : public ControllerReturn
{/*
	typedef std::vector stdvec;

	public:
		stdvec m_vec;

		//.. uint nbRow;
		//.. uint nbCol;
		//.. double matrix[100]; => double* matrix;

		explicit TestDouble(double p_td){
			if( p_td == 0.0 )
				Controller::assoc(this);
			m_d = p_td;
		}
		TestDouble operator+( const TestDouble& p_td ) const
		{
			if( Controller::isMaster() ){
				// Ici le fetch et le découpage
				/// @todo voir si le calcul ne necessite pas un autre calcul avant (ex: t3 avant de connaitre t4) -> voir l.40
				Calcul* c = new Calcul();
				c->m_calcul.push_back(Op(m_d,p_td.m_d,Op::op_plus));
				//.. c.m_calcul.push_back(Op(0.0,0.1,op_plus));
				//.. c.m_calcul.push_back(Op(0.0,0.1,op_plus));
				//.. c.m_calcul.push_back(Op(0.0,0.1,op_plus));
				Controller::fetch(c);

				//.. Note pour Matrix class:
				//.. Matrix ret;
				//.. ret.nbRow = ...;
				//.. ret.nbCol = ...;
				//.. ret.matrix = NULL;
				return TestDouble(0.0);
			}else{
				return TestDouble(p_td.m_d+this->m_d);
			}
		}

		void operator=( const TestDouble& p_td )
		{
			dg("pass operator=");
			//affectation which first need a calculation
			if( Controller::assoc(this) ){
				//.. Soit dd une Matrix class
				//.. alors:
				//.. this.nbRow = dd.nbRow;
				//.. this.nbCol = dd.nbCol;
				//.. this.matrix = NULL;
				return ;
			}
			//simple affectation
			m_d = p_td.m_d;
		}

		void operator=( TestDouble p_td )
		{
			dg("pass2 operator=");
			//affectation which first need a calculation
			if( Controller::assoc(this) ){
				//.. Soit dd une Matrix class
				//.. alors:
				//.. this.nbRow = dd.nbRow;
				//.. this.nbCol = dd.nbCol;
				//.. this.matrix = NULL;
				return ;
			}
			//simple affectation
			m_d = p_td.m_d;
		}

		void setData( std::vector<double> data )
		{
			m_d = data[0];
			//.. réassembler les morceau de la matrix resultat
			//.. Matrix class exemple:
			//.. for i=0; .. i++ => d[i] = matrix[i];
		}*/
};

}}}}

#endif

