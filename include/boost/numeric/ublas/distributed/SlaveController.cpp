#include <boost/mpi/communicator.hpp>
#include <boost/mpi/nonblocking.hpp>
#include <boost/mpi/request.hpp>
#include <vector>
#include "SlaveController.hpp"
#include "Pipe.hpp"
#include "MaestroController.hpp"
#include "debug.h"

namespace distributed = boost::numeric::ublas::distributed;
namespace SlaveController = distributed::SlaveController;
namespace ctr = std;// For vector : boost::container OR std

namespace boost { namespace numeric { namespace ublas { namespace distributed {
namespace SlaveController
{
	boost::mpi::communicator*			m_world=0;
	ctr::vector<boost::mpi::request>	m_request;//!< List of recv request
}}}}}


/***************************************************************************//**
* @brief Will listen to the main channel (0) and can be dedicated to other channels.
* For each received packets on channels other than 0, the function
* SlaveController::executeCalc will be called.
* @return[NONE]
*/
void SlaveController::worker()
{
	Pipe::DataOp dc;
	Pipe::MainChannel mc;
	boost::mpi::status st;
	m_world = MaestroController::world();

	// We listen the main Pipe
	st = m_world->irecv(0,0,mc).wait();
	do{
		if( st.tag() == 0 ){
			switch( mc.toListen )
			{
				case Pipe::LS_unListen:// UnListen Signal
					// TODO: erase listener in m_request.
					/*for( int i=0; i<m_tagsList.size(); i++ )
					{
						if( m_tagsList.at(i) == mc.tag )
							m_tagsList.erase(m_tagsList.begin()+i);
					}*/
					break;

				case Pipe::LS_Listen:// Listen signal
					m_request.push_back(m_world->irecv(0, mc.tag, dc));
					break;

				case Pipe::LS_Exit:// Exit signal
					MaestroController::shutdown();
					exit(0);
					break;

				default:
					break;
			}
			// We listen again the main Channel
			m_request.push_back(m_world->irecv(0,0,mc));
		}else{
			//dg("Slave is going to work");
			executeCalc(dc, st.tag());
			m_request.push_back(m_world->irecv(0,st.tag(),dc));
		}

		// We wait a reply / work
		{
			auto pair = boost::mpi::wait_any(m_request.begin(),m_request.end());
			st = pair.first;
			// Remove the old request
			m_request.erase(pair.second);
			//dg("Slave Recv on tag " << st.tag());
		}
	} while(true);
}


/***************************************************************************//**
* @brief Enable addition between two datas (which can be double, matrix, etc...)
* @param[in,out] a
* @param[in] b
* @return return Null in impossible case (example: matrix-double addition)
* else it returns the calculation result
*/
Pipe::DataSerialized* plus( Pipe::DataSerialized& a, const Pipe::DataSerialized& b )
{
	if( a.dt == Pipe::DT_Matrix ){
		if( b.dt == Pipe::DT_Matrix ){
			for( unsigned int i=0; i<a.tab.size(); i++ )
				a.tab[i] += b.tab[i];
		}else if( b.dt == Pipe::DT_Double ){
			dgR0("Bad dt for b: Matrix and Double can't be add");
		}else{
			dgR0("Bad dt for b");
		}
	}else if( a.dt == Pipe::DT_Double ){
		if( b.dt == Pipe::DT_Matrix ){
			dgR0("Bad dt for b: Matrix and Double can't be add");
		}else if( b.dt == Pipe::DT_Double ){
			a.tab[0] += b.tab[0];
		}else{
			dgR0("Bad dt for b");
		}
	}else{
		dgR0("Bad dt for a");
	}
	return &a;
}


/***************************************************************************//**
* @brief Enable substraction between two datas (which can be double, matrix, etc...)
* @param[in,out] a
* @param[in] b
* @return return Null in impossible case (example: matrix-double substraction)
* else it returns the calculation result
*/
Pipe::DataSerialized* minus( Pipe::DataSerialized& a, const Pipe::DataSerialized& b )
{
	if( a.dt == Pipe::DT_Matrix ){
		if( b.dt == Pipe::DT_Matrix ){
			for( unsigned int i=0; i<a.tab.size(); i++ )
				a.tab[i] -= b.tab[i];
		}else if( b.dt == Pipe::DT_Double ){
			dgR0("Bad dt for b: Matrix and Double can't be subtract");
		}else{
			dgR0("Bad dt for b");
		}
	}else if( a.dt == Pipe::DT_Double ){
		if( b.dt == Pipe::DT_Matrix ){
			dgR0("Bad dt for b: Matrix and Double can't be subtract");
		}else if( b.dt == Pipe::DT_Double ){
			a.tab[0] -= b.tab[0];
		}else{
			dgR0("Bad dt for b");
		}
	}else{
		dgR0("Bad dt for a");
	}
	return &a;
}


/***************************************************************************//**
* @brief Enable division between two datas (which can be double, matrix, etc...)
* @param[in,out] a
* @param[in,out] b
* @return return Null in impossible case (example: n/0)
* else it returns the calculation result
*/
Pipe::DataSerialized* div( Pipe::DataSerialized& a, Pipe::DataSerialized& b )
{
	if( a.dt == Pipe::DT_Matrix ){
		if( b.dt == Pipe::DT_Matrix ){
			/**TODO**/
			dgR0("TODO");
		}else if( b.dt == Pipe::DT_Double ){
			for( unsigned int i=0; i<a.tab.size(); i++ ){
				if( b.tab[0] == 0 )
					dgR0("You can't divide by zero !!");
				a.tab[i] /= b.tab[0];
			}
		}else{
			dgR0("Bad dt for b");
		}
		return &a;
	}else if( a.dt == Pipe::DT_Double ){
		if( b.dt == Pipe::DT_Matrix ){
			dgR0("Bad dt for b: Double can't be divided by a Matrix");
		}else if( b.dt == Pipe::DT_Double ){
			if( b.tab[0] == 0 )
				dgR0("You can't divide by zero !!");
			b.tab[0] /= a.tab[0];
		}else{
			dgR0("Bad dt for b");
		}
		return &b;
	}else{
		dgR0("Bad dt for a");
	}
	dg("Impossible case...");
	return 0;
}


/***************************************************************************//**
* @brief Enable multiplication between two datas (which can be double, matrix, etc...)
* @param[in,out] a
* @param[in,out] b
* @return return Null in impossible case else it returns the calculation result
*/
Pipe::DataSerialized* mult( Pipe::DataSerialized& a, Pipe::DataSerialized& b )
{
	if( a.dt == Pipe::DT_Matrix ){
		if( b.dt == Pipe::DT_Matrix ){
			/**TODO**/
			dgR0("TODO");
		}else if( b.dt == Pipe::DT_Double ){
			for( unsigned int i=0; i<a.tab.size(); i++ )
				a.tab[i] *= b.tab[0];
		}else{
			dgR0("Bad dt for b");
		}
		return &a;
	}else if( a.dt == Pipe::DT_Double ){
		if( b.dt == Pipe::DT_Matrix ){
			for( unsigned int i=0; i<b.tab.size(); i++ )
				b.tab[i] *= a.tab[0];
		}else if( b.dt == Pipe::DT_Double ){
			b.tab[0] *= a.tab[0];
		}else{
			dgR0("Bad dt for b");
		}
		return &b;
	}else{
		dgR0("Bad dt for a");
	}
	dg("Impossible case...");
	return 0;
}


/***************************************************************************//**
 * @brief Choose the correct calculation depending on the given operation
 * @param[in,out] dc		data to treat (a or b will be changed)
 * @param[in] tag			channel to use for the respons
 * @return[NONE]
 */
void SlaveController::executeCalc( Pipe::DataOp& dc, int tag )
{
	Pipe::DataSerialized* reply = 0;
	switch( dc.op )
	{
		case Pipe::OP_Plus:
			reply = plus(dc.a,dc.b);
			break;
		case Pipe::OP_Minus:
			reply = minus(dc.a,dc.b);
			break;
		case Pipe::OP_Mult:
			reply = mult(dc.a,dc.b);
			break;
		case Pipe::OP_Div:
			reply = div(dc.a,dc.b);
			break;
		default:
			dg("Invalid operator: '" << dc.op <<"' is not an implemented operator.");
			return;
	}
	if( reply )
		m_world->isend(0,tag,*reply);
}
