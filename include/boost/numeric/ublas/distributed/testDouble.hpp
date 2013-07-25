#ifndef _BOOST_UBLAS_DISTRIBUTED_TESTDOUBLE_
#define _BOOST_UBLAS_DISTRIBUTED_TESTDOUBLE_

#include "controller.hpp"

namespace boost { namespace numeric { namespace ublas { namespace distributed {

class TestDouble : public ControllerReturn
{
	public:
		double m_d;

		explicit TestDouble(double p_td){
			if( p_td == 0.0 )
				Controller::assoc(this);
			m_d = p_td;
		}
		TestDouble operator+( const TestDouble& p_td ) const
		{
			if( Controller::isMaster() ){
				// Ici le fetch et le découpage
				Calcul* c = new Calcul();
				c->m_calcul.push_back(Op(m_d,p_td.m_d,Op::op_plus));
				Controller::fetch(c);
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
				return ;
			}
			//simple affectation
			m_d = p_td.m_d;
		}

		void setData( std::vector<double> data )
		{
			m_d = data[0];
		}
};


}}}}

#endif //_BOOST_UBLAS_DISTRIBUTED_TESTDOUBLE_
