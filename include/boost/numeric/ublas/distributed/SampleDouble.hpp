#ifndef _BOOST_UBLAS_DISTRIBUTED_TESTDOUBLE_
#define _BOOST_UBLAS_DISTRIBUTED_TESTDOUBLE_

#include "Controller.hpp"
#include "Pipe.hpp"
#include "debug.h"

namespace boost { namespace numeric { namespace ublas { namespace distributed {

namespace Pipe = details::Pipe;

/***************************************************************************//**
 * @brief This is a basic class example : how create a class which can use
 * this distributed method.
 */
class SampleDouble : public ControllerReturn
{
	public:
		double		m_d;//!<				Main value
		Controller*	m_controller;//!<		Controller used in computation
		bool		m_hasCorrectValue;//!<	Is m_d a correct value ? (Correct means well instantiated)


		explicit SampleDouble( Controller* c )
		{
			if( c->assoc(this) )
			m_d = 0.0;
			m_hasCorrectValue = false;
			m_controller = c;
		}
		explicit SampleDouble( double p_td, Controller* c )
		{
			m_hasCorrectValue = true;
			m_d = p_td;
			m_controller = c;
		}


		/*******************************************************************//**
		 * @brief enable operation + between two SampleDouble
		 * @param[in] p_td
		 * @return A fake SampleDouble: m_hasCorrectValue is set to false. This value
		 * will be changed when setData will be called.
		 */
		SampleDouble operator+( const SampleDouble& p_td ) const
		{
			Calcul* c = new Calcul();
			c->m_calcul.push_back(Pipe::DataOp(Pipe::DataSerialized(m_d),Pipe::DataSerialized(p_td.m_d),Pipe::OP_Plus));
			p_td.m_controller->fetch(c);
			return SampleDouble(p_td.m_controller);
		}


		/*******************************************************************//**
		 * @brief Enable simple affectation or make the calculation before the
		 * affectation.
		 * @param[in] p_td		The SampleDouble to copy
		 * @return[NONE]
		 */
		void operator=( const SampleDouble& p_td )
		{
			// Affectation which first need a calculation
			if( !p_td.m_hasCorrectValue && p_td.m_controller->assoc(this) ){
				m_controller = p_td.m_controller;
				return ;
			}
			// Simple affectation
			m_d = p_td.m_d;
		}


		/*******************************************************************//**
		 * @brief Enable simple affectation or make the calculation before the
		 * affectation.
		 * @param[in] p_td		The SampleDouble to copy
		 * @return[NONE]
		 */
		void operator=( SampleDouble p_td )
		{
			// Affectation which first need a calculation
			if( p_td.m_controller->assoc(this) ){
				m_controller = p_td.m_controller;
				return ;
			}
			//simple affectation
			m_d = p_td.m_d;
		}


		/*******************************************************************//**
		 * @brief Enable the result copying. the result copying is based on the
		 * data distribution, which is done before sending the data to the
		 * SlaveControllers.
		 * @param[in] data		The result datas.
		 * @param[in] op		The operation which was used.
		 * @return[NONE]
		 */
		void setData( const ctr::vector<Pipe::DataSerialized>& data, Pipe::t_Operation op )
		{
			(void) op;
			m_d = data.at(0).tab.at(0);
			m_hasCorrectValue = true;
		}
};


}}}}// end namespace boost::numeric::ublas::distributed

#endif //_BOOST_UBLAS_DISTRIBUTED_TESTDOUBLE_
