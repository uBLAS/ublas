#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>
#include "MaestroController.hpp"
#include "SlaveController.hpp"
#include "Pipe.hpp"
#include "debug.h"

namespace MaestroController = boost::numeric::ublas::distributed::MaestroController;
namespace SlaveController	= boost::numeric::ublas::distributed::SlaveController;
namespace Pipe				= boost::numeric::ublas::distributed::details::Pipe;

namespace boost { namespace numeric { namespace ublas { namespace distributed {
namespace MaestroController {
	boost::mpi::environment*	m_env=0;//<!	Environment, defined by command line (mpirun -np <num_process> ./main)
	boost::mpi::communicator*	m_world=0;//!<	World
	int							m_idTag=1;//!<	Controller unique ID. Permit to generate UNIQUE ID for each Constroller.
}}}}}


/***************************************************************************//**
 * @brief Initialise environment and world attributes and enable Slave work beginning.
 * For the Master this function is non blockant. BUT for slave, this function will
 * never return. This function will call exit(0) at the end of each Worker/Slave.
 * @param[in] argc	The argc of main
 * @param[in] argv	The argv of main
 * @return[NONE]
 */
void MaestroController::init( int argc, char** argv )
{
	m_env = new mpi::environment(argc, argv);
	m_world = new mpi::communicator;

	//main process
	if( m_world->rank() == 0 )
		return;
	//other process:
	SlaveController::worker();
}


/***************************************************************************//**
 * @brief Stop all Slave/Worker.
 * @return[NONE]
 *
 * @warning This function will SEGFAULT if:
 * - MaestroController::init( int,char** ) hasn't been called.
 */
void MaestroController::shutdown()
{
	if( !m_world || !m_env )
		dgR("Please call MaestroController::init(...) before MaestroController::shutdown !",);

	if( m_world->rank() == 0 ){
		Pipe::MainChannel op(0,Pipe::LS_Exit);
		for(int i=1; i<m_world->size(); i++ )
		{
			m_world->send(i,0,op);
		}
	}
	m_env->finalized();// wait for all messages receipt (by each process)
	delete m_world;
	delete m_env;
}


/***************************************************************************//**
 * @brief Return the world.
 * @return The world. OR NULL/nullptr if error (see warning).
 *
 * @warning This function will return NULL/nullptr if:
 * - MaestroController::init( int,char** ) hasn't been called.
 * - MaestroController::shutdown() has been called.
 */
boost::mpi::communicator* MaestroController::world()
{
	if( !m_world )
		dgR0("Please call MaestroController::init(...) before MaestroController::world !");

	return m_world;
}


/***************************************************************************//**
 * @brief Return the number of computer aviable.
 * @return A value upper to 0. OR 0 if error (see warning).
 *
 * @warning This function will return NULL or SEGFAULT if :
 * - MaestroController::init( int,char** ) hasn't been called.
 * - MaestroController::shutdown() has been called.
 */
int MaestroController::nbComputer()
{
	if( !m_world )
		dgR0("Please call MaestroController::init(...) before MaestroController::nbComputer !");
	return m_world->size();
}


/***************************************************************************//**
 * @brief Permit to determite if this process/computer is a Master or a Slave.
 * @return TRUE for the main computer/process, FALSE for the others.
 *
 * @warning This function will RETURN FALSE or SEGFAULT if :
 * - MaestroController::init( int,char** ) hasn't been called.
 * - MaestroController::shutdown() has been called.
 */
bool MaestroController::isMaster()
{
	if( !m_world )
		dgR("Please call MaestroController::init(...) before MaestroController::isMaster !",false);
	return m_world->rank() == 0;
}


/***************************************************************************//**
 * @brief Permit to generate a UNIQUE ID for each Controller. This function is
 * THREAD-SAFE.
 * @return A UNIQUE value upper to 0.
 *
 * @note This function is a basic increment.
 */
int MaestroController::getId()
{
	int tmpTag = __atomic_fetch_add(&m_idTag,1,__ATOMIC_SEQ_CST);
	return tmpTag;
}
