#include "Controller.hpp"
#include "MaestroController.hpp"
#include "debug.h"
#include <boost/mpi/communicator.hpp>
#include <stdlib.h>

namespace MaestroController = boost::numeric::ublas::distributed::MaestroController;
using namespace boost::numeric::ublas::distributed;

/***************************************************************************//**
 * @brief Constructor.
 * @return[NONE]
 */
Controller::Controller()
{
	m_calculatedUnderConstruction = nullptr;
	m_idTag = MaestroController::getId();

	Pipe::MainChannel op(m_idTag,Pipe::LS_Listen);
	for( int i=1; i<MaestroController::nbComputer(); i++ )
		MaestroController::world()->send(i,0,op);
}


/***************************************************************************//**
 * @brief Constructor with a list of computer(=rank) to use.
 * @param[in] ranksList		A list of computer to use.
 * @return[NONE]
 */
void Controller::init( const ctr::vector<int>& ranksList )
{
	m_calculatedUnderConstruction = nullptr;
	m_idTag = MaestroController::getId();
	m_ranksList = ranksList;

	Pipe::MainChannel op(m_idTag,Pipe::LS_Listen);
	for( unsigned int i=0; i<ranksList.size(); i++ )
	{
		if( ranksList.at(i) <= 0 || ranksList.at(i) >= MaestroController::nbComputer() ){
			dg("Computer/rank n°" << ranksList.at(i) << " not found !\n0 is reserved to the master and you have "<<(MaestroController::nbComputer()-1)<<" MAX computer/rank.");
			exit(__LINE__);
		}
		MaestroController::world()->send(ranksList.at(i),0,op);
	}
}


/***************************************************************************//**
 * @brief Destructor.
 * @return[NONE]
 */
Controller::~Controller()
{
	Pipe::MainChannel op(m_idTag,Pipe::LS_unListen);
	if( m_ranksList.size() ){
		for( unsigned int i=0; i<m_ranksList.size(); i++ )
			MaestroController::world()->send(m_ranksList.at(i),0,op);
	}else{
		for( int i=0; i<MaestroController::nbComputer(); i++ )
			MaestroController::world()->send(i,0,op);
	}
}


/***************************************************************************//**
 * @brief flush - treat all operations
 * @return[NONE]
 */
void Controller::flush()
{
	// send todo operations
	for( unsigned int j=0; j<m_task.size(); j++ )
	{
		unsigned int k=0;
		while( k<m_task[j]->size() )
		{
			if( m_ranksList.size() ){
				for( unsigned int i=0; i<m_ranksList.size() && k<m_task[j]->size(); i++)
				{
					MaestroController::world()->send(m_ranksList.at(i),m_idTag,m_task[j]->m_calcul[k]);
					k++;
				}
			}else{
				for( int i=1; i<MaestroController::nbComputer() && k<m_task[j]->size(); i++)
				{
					MaestroController::world()->send(i,m_idTag,m_task[j]->m_calcul[k]);
					k++;
				}
			}
		}
	}

	// wait for return value
	ctr::vector<Pipe::DataSerialized> result[m_task.size()];
	Pipe::DataSerialized tmp_value;
	for( unsigned int j=0; j<m_task.size(); j++ )
	{
		unsigned int k=0;
		while( k<m_task[j]->size() )
		{
			if( m_ranksList.size() ){
				for( unsigned int i=0; i<m_ranksList.size() && k<m_task[j]->size(); i++)
				{
					MaestroController::world()->recv(m_ranksList.at(i),m_idTag,tmp_value);
					result[j].push_back(tmp_value);
					k++;
				}
			}else{
				for( int i=1; i<MaestroController::nbComputer() && k<m_task[j]->size(); i++)
				{
					MaestroController::world()->recv(i,m_idTag,tmp_value);
					result[j].push_back(tmp_value);
					k++;
				}
			}
		}
		//save results
		m_task[j]->m_returnPoint->setData( result[j], m_task[j]->m_calcul.at(0).op );
		delete m_task[j];
	}

	// clear list of todo operations
	m_task.clear();
}


/***************************************************************************//**
 * @brief Save a operation who has no return point. This operation will be execute
 * on a slave.
 * @param[in] c		Calcul to do, which the return value is unknown
 * @return[NONE]
 */
void Controller::fetch( Calcul* c )
{
	m_calculatedUnderConstruction = c;
}


/***************************************************************************//**
 * @brief Associate a calculates with a return point.
 * @param[in] r		The class who contain a setData. This class will be called when
 * results will be aviable.
 * @return TRUE if associated. FALSE other
 */
bool Controller::assoc( ControllerReturn* r )
{
	// Simple affectation
	if( m_calculatedUnderConstruction == 0 )
		return false;

	// Affectation which first need a calculation
	m_calculatedUnderConstruction->m_returnPoint = r;
	m_task.push_back(m_calculatedUnderConstruction);
	m_calculatedUnderConstruction = 0;
	return true;
}
