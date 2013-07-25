/// @file controller.hpp Definition for the distributed system controller
#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_

/// @brief (debug) print error
#define dg( msg ) {std::cout <<"[file " << __FILE__ <<", line "<< __LINE__ << "] " << msg << std::endl; fflush(stdout);}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>
#include <boost/mpi.hpp>
#include <boost/serialization/string.hpp>
#include <boost/scoped_ptr.hpp>

namespace ublas = boost::numeric::ublas;
namespace mpi = boost::mpi;
using namespace ublas;
using namespace mpi;


/***************************************************************************//**
 * @brief The op class
 */
class Op {
public:
	/// @enum owns the different needed operations : +, -, /, *, =.
	typedef enum { op_plus, op_minus, op_mult, op_div, op_exit } e_op;

	double	m_d1;
	double	m_d2;
	e_op	m_o;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		(void)version;
		ar & m_d1;
		ar & m_d2;
		ar & m_o;
	}

	Op(){}
	Op(double p_d1, double p_d2, e_op p_o){
		m_d1 = p_d1;
		m_d2 = p_d2;
		m_o = p_o;
	}
};

/***************************************************************************//**
 * @brief The ControllerReturn class
 */
class ControllerReturn{
public:
	//used to set return value after a mpi evaluation in operator=
	virtual void setData( std::vector<double> data ) = 0;
};

/***************************************************************************//**
 * @brief The calcul class
 */
class Calcul{
public:
	std::vector<Op>		m_calcul;//!< list of simple operations
	ControllerReturn*	m_returnPoint;//!< pointer to the return value
///@todo	Calcul*		m_chain;//<! would enabled multi calcul (t4=t1+t2+t3)
///@todo	bool		m_isWaitingFor;//!< true if the final value depends on an other simple operation
									   //ex: t3=t1+t2; t4=t2+t3;
	inline uint size() const { return m_calcul.size(); }
};

/***************************************************************************//**
 * @brief The mpi_controller class
 */
class Controller {
private:
	std::vector<Calcul*>	m_task;//!< list of calcul to treat
	Calcul*					m_noReturnPointCalcul;//!< (one!)Calcul, which has no return point
	mpi::environment*		m_env;//<! environment, defined by command line (mpirun -np <num_process> ./main)
	mpi::communicator*		m_world;//!< world
	static boost::scoped_ptr<Controller>	m_inst;//<! singleton controller (smart pointer)

private:
	Controller(){}
	Controller( int argc, char** argv ){
		m_env = new mpi::environment(argc,argv);
		m_world = new mpi::communicator();
		m_noReturnPointCalcul = nullptr;
	}
public:
	~Controller(){}

	/***********************************************************************//**
	 * @brief shutdown - stop all process and delete each 'new' instances.
	 * @return[NONE]
	 */
	static void shutdown()
	{
		if( m_inst.get()==0 )
			return;
		if( m_inst->m_world->rank() == 0 ){
			Op op(0,0,Op::op_exit);
			for(int i=1; i<m_inst->m_world->size(); i++ ){
				m_inst->m_world->send(i,0,op);
			}
		}
		m_inst->m_env->finalized();// wait for all messages receipt (by each process)
		delete m_inst->m_world;
		delete m_inst->m_env;
	}

	/***********************************************************************//**
	 * @brief init - enable controller initialization and start passive waiting for each process (except master process)
	 * @param argc
	 * @param argv
	 * @return[NONE]
	 */
	static void init( int argc, char** argv )
	{
		m_inst.reset(new Controller(argc, argv));
		//main process
		if( m_inst->m_world->rank() == 0 )
			return;
		//other process:
		Op op;
		do{
			m_inst->m_world->recv(0,0,op);
			//dg("recv" << op.m_o);
			dg("d1: "<< op.m_d1 << " d2: " << op.m_d2 <<" op: " << op.m_o);
			switch (op.m_o){
				case op.op_exit :dg("EXIT "<<m_inst->m_world->rank()); shutdown(); exit(0);
				case op.op_plus : m_inst->m_world->send(0,0,op.m_d1+op.m_d2);
					break;
				case op.op_minus : m_inst->m_world->send(0,0,op.m_d1-op.m_d2);
					break;
				case op.op_mult : m_inst->m_world->send(0,0,op.m_d1*op.m_d2);
					break;
				case op.op_div : if( op.m_d2==0 ){
						dg("invalid parameter: second parameter can't be equal to 0");
						exit(1);
					}
					m_inst->m_world->send(0,0,op.m_d1/op.m_d2);
					break;
				default : dg("invalid operator: '" << op.m_o <<"' is not an implemented operator.");
			}
		} while(true);
	}

	/***********************************************************************//**
	 * @brief isMaster
	 * @return bool - true for the main process, false for the others.
	 */
	static bool isMaster()
	{
		return m_inst->m_world->rank() == 0;
	}

	/***********************************************************************//**
	 * @brief flush - treat all operations
	 * @return[NONE]
	 */
	static void flush()
	{
		// send todo operations
		for(uint j=0; j<m_inst->m_task.size(); j++ ){
			uint k=0;
			while( k<m_inst->m_task[j]->size() )
				for(int i=1; i<m_inst->m_world->size() && k<m_inst->m_task[j]->size(); i++){
					m_inst->m_world->send(i,0,m_inst->m_task[j]->m_calcul[k]);
					k++;
				}
		}

		// wait for return value
		std::vector<double> result[m_inst->m_task.size()];
		double tmp_value;
		for(uint j=0; j<m_inst->m_task.size(); j++ ){
			uint k=0;
			while( k<m_inst->m_task[j]->size() )
			{
				for(int i=1; i<m_inst->m_world->size() && k<m_inst->m_task[j]->size(); i++){
					m_inst->m_world->recv(i,0,tmp_value);
					result[j].push_back(tmp_value);
					k++;
				}
			}
			//save results
			m_inst->m_task[j]->m_returnPoint->setData( result[j] );
			delete m_inst->m_task[j];
		}

		// clear list of todo operations
		m_inst->m_task.clear();

	}

	/***********************************************************************//**
	 * @brief fetch - enable to save operation without execute them before the flush function call
	 * @param c	calcul to do, which the return value is unknown
	 * @return[NONE]
	 */
	static void fetch( Calcul* c )
	{
		m_inst->m_noReturnPointCalcul = c;
	}

	/***********************************************************************//**
	 * @brief assoc - associate the calcul with the value (pointer) where the result must be returned.
	 * @param r	pointer to the value where the result must be returned
	 * @return[bool] - true if the calcul need an operation result before the result affectation (ex: t3=t1+t2; first calcul t1+t2 before affect t3)
	 *				 - false if the operation is a simple affectation (ex: t2=t1; or t2=1.0;)
	 * @warning only used by operator=
	 */
	static bool assoc( ControllerReturn* r )
	{
		//simple affectation
		if( m_inst->m_noReturnPointCalcul == 0 )
			return false;
		//affectation which first need a calculation
		m_inst->m_noReturnPointCalcul->m_returnPoint = r;
		m_inst->m_task.push_back(m_inst->m_noReturnPointCalcul);
		m_inst->m_noReturnPointCalcul = 0;
		return true;
	}
};


boost::scoped_ptr<Controller> Controller::m_inst(nullptr);

#endif //_CONTROLLER_HPP_
