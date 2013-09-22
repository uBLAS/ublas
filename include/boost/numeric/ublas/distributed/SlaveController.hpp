#ifndef _BOOST_UBLAS_DISTRIBUTED_SLAVECONTROLLER_HPP_
#define _BOOST_UBLAS_DISTRIBUTED_SLAVECONTROLLER_HPP_

#include "Pipe.hpp"

namespace Pipe = boost::numeric::ublas::distributed::details::Pipe;

namespace boost { namespace numeric { namespace ublas { namespace distributed {
/***************************************************************************//**
* @brief This namespace will be executed on Slave servers. It will waiting for
* a work. Then it will calculate and return the result to the master.
*
* @code
* // Basic usage:
* SlaveController::worker();
* @endcode
*
* @note Never call SlaveController::executeCalc if you don't know what you do !
*/
namespace SlaveController
{
	void worker();
	void executeCalc( Pipe::DataOp& dc, int tag );
}
}}}}// end namespace boost::numeric::ublas::distributed::SlaveController

#endif// _BOOST_UBLAS_DISTRIBUTED_SLAVECONTROLLER_HPP_
