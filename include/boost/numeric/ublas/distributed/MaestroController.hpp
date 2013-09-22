/// @file MaestroController.hpp
#ifndef _BOOST_UBLAS_DISTRIBUTED_MAESTROCONTROLLER_HPP_
#define _BOOST_UBLAS_DISTRIBUTED_MAESTROCONTROLLER_HPP_

// To Avoid to many include ;)
namespace boost { namespace mpi {
	class communicator;
}}

namespace boost { namespace numeric { namespace ublas { namespace distributed {

/***************************************************************************//**
* @brief This namespace is used to initialize the client / server system of the
* distributed system calculates. It also assigns an ID to each Controller.
*/
namespace MaestroController
{
	void init( int argc, char** argv );
	void shutdown();
	boost::mpi::communicator* world();
	int nbComputer();
	bool isMaster();
	int getId();
}
}}}}// end namespace boost::numeric::ublas::distributed::MaestroController

#endif// _BOOST_UBLAS_DISTRIBUTED_MAESTROCONTROLLER_HPP_
