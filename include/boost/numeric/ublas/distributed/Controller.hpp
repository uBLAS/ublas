/// @file controller.hpp Definition for the distributed system controller
#ifndef _BOOST_UBLAS_DISTRIBUTED_CONTROLLER_HPP_
#define _BOOST_UBLAS_DISTRIBUTED_CONTROLLER_HPP_

#include "Pipe.hpp"
#include <vector>
#include <initializer_list>

namespace Pipe = boost::numeric::ublas::distributed::details::Pipe;
namespace ctr = std;// For vector : boost::container OR std

namespace boost { namespace numeric { namespace ublas { namespace distributed {

/***************************************************************************//**
 * @brief This class must be inherited to allow the return data.
 */
class ControllerReturn
{
	public:
		// Used to set return value after a mpi evaluation in operator=
		virtual void setData( const ctr::vector<Pipe::DataSerialized>& data, Pipe::t_Operation op ) = 0;
};


/***************************************************************************//**
 * @brief This class contains a list of calculations to perform.
 */
class Calcul
{
	public:
		ctr::vector<Pipe::DataOp>	m_calcul;//!< List of simple operations
		ControllerReturn*			m_returnPoint;//!< Pointer to the function who will treat return value.
	///@todo	Calcul*				m_chain;//<! would enabled multi calcul (t4=t1+t2+t3)
	///@todo	bool				m_isWaitingFor;//!< true if the final value depends on an other simple operation
										   //ex: t3=t1+t2; t4=t2+t3;
		inline uint size() const { return m_calcul.size(); }
};


/***************************************************************************//**
 * @brief This class allows you to manage:
 *	- A cache of operations to be performed,
 *	- Sends data to the slaves
 *	- Receive results and presentation of results to the classes concerned.
 */
class Controller
{
	private:
		ctr::vector<Calcul*>	m_task;//!< List of calcul to treat
		Calcul*					m_calculatedUnderConstruction;//!< (one!)Calcul, which has no return point
		int						m_idTag;//!< UNIQUE ID for communication. This is his Tag on the network.
		ctr::vector<int>		m_ranksList;//!< Lists of computer (=rank) assigned to this Controller. If empty => All computers are concerned.

	public:
		Controller();

		/*******************************************************************//**
		 * @brief Constructor with a list of computer(=rank) to use.
		 * @param[in] ranksList		A list of computer to use.
		 * @return[NONE]
		 */
		inline Controller( const ctr::vector<int>& _ranksList ){init(_ranksList);}

		/*******************************************************************//**
		 * @brief Constructor with a list of computer(=rank) to use.
		 * @param[in] ranksList		A list of computer to use.
		 * @return[NONE]
		 *
		 * @note This can be used like this Controller({4,2,6,9})
		 */
		inline Controller( ctr::vector<int> _ranksList ){init(_ranksList);}
		inline Controller( std::initializer_list<int> _ranksList ){init(_ranksList);}

		~Controller();
		void flush();
		void fetch( Calcul* c );
		bool assoc( ControllerReturn* r );

	private:
		void init( const ctr::vector<int>& ranksList );
};

}}}}// end namespace boost::numeric::ublas::distributed
#endif// _BOOST_UBLAS_DISTRIBUTED_CONTROLLER_HPP_
