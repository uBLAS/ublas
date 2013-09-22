#ifndef _BOOST_UBLAS_DISTRIBUTED_MATRIX_
#define _BOOST_UBLAS_DISTRIBUTED_MATRIX_

#include "Controller.hpp"
#include "Pipe.hpp"
#include "debug.h"
#include <boost/numeric/ublas/matrix.hpp>

namespace boost { namespace numeric { namespace ublas { namespace distributed {

namespace Pipe = details::Pipe;
namespace ublas = boost::numeric::ublas;

/***************************************************************************//**
 * @brief Distributed matrix (inherite ublas::matrix)
 *
 * @note Must be used with the distributed technology !
 */
template <class T, class L = ublas::row_major, class A = ublas::unbounded_array<T> >
class matrix : public ublas::matrix<T,L,A>, public ControllerReturn
{
	private:
		Controller*			m_controller;//!< The Controller used for calculating distributed
		bool				m_hasCorrectValue;//!< Has the matrix a proper value ?

	public:
		typedef typename ublas::matrix<T,L,A>::size_type size_type_t;
		typedef typename ublas::matrix<T,L,A>::value_type value_type_t;
		typedef A array_type_t;

	public:
		explicit matrix( Controller* c )
		{
			m_hasCorrectValue = false;
			m_controller = c;
		}

		explicit matrix( size_type_t size1, size_type_t size2, Controller* c )
			: ublas::matrix<T,L,A>(size1, size2), m_controller(c){}

		explicit matrix( size_type_t size1, size_type_t size2, const value_type_t& init, Controller* c )
			: ublas::matrix<T,L,A>(size1, size2, init), m_controller(c){}

		explicit matrix( size_type_t size1, size_type_t size2, const array_type_t& data, Controller* c )
			: ublas::matrix<T,L,A>(size1, size2, data), m_controller(c){}

		explicit matrix( const ublas::matrix<T,L,A> &m, Controller* c)
			: ublas::matrix<T,L,A>(m), m_controller(c) {}

		template<class AE>
		explicit matrix( const ublas::matrix_expression<AE>& ae, Controller* c)
			: ublas::matrix<T,L,A>(ae), m_controller(c) {}


		/*******************************************************************//**
		 * @brief Enable calcul distribution for a matrix-matrix addition
		 * @param[in] m		The matrix used in the addition
		 * @return A fake matrix: m_hasCorrectValue is set to false. This value
		 * will be changed when setData will be called.
		 */
		matrix operator+( const matrix& m ) const
		{
			if( (this->size1() != m.size1()) || (this->size2() != m.size2()) )
			{
				dg("you can not add two matrix with different sizes");
				exit(__LINE__);
			}
			// matrix to blocks
			Calcul* c = new Calcul();
			Pipe::DataOp op;
			op.op = Pipe::OP_Plus;
			op.a.dt = Pipe::DT_Matrix;
			op.b.dt = Pipe::DT_Matrix;
			for ( size_type_t i=0; i<this->size1(); i++ ){
				op.a.tab = ctr::vector<double>(this->size2(),0);
				op.b.tab = ctr::vector<double>(this->size2(),0);
				for( size_type_t j=0; j<this->size2(); j++ ){
					op.a.tab[j] = const_cast<matrix*>(this)->at_element(i,j);
					op.b.tab[j] = const_cast<matrix&>(m).at_element(i,j);
				}
				op.a.packet_id = i;
				op.b.packet_id = i;
				c->m_calcul.push_back(op);
				op.a.tab.clear();
				op.b.tab.clear();
			}
			const_cast<matrix&>(m).m_controller->fetch(c);
			return matrix(m.size1(),m.size2(),m.m_controller);
		}


		/*******************************************************************//**
		 * @brief Enable calcul distribution for a matrix-matrix substraction
		 * @param[in] m		The matrix used in the substraction.
		 * @return A fake matrix: m_hasCorrectValue is set to false. This value
		 * will be changed when setData will be called.
		 */
		matrix operator-( const matrix& m ) const
		{
			if( (this->size1() != m.size1()) || (this->size2() != m.size2()) )
			{
				dg("you can not add two matrix with different sizes");
				exit(__LINE__);
			}
			// matrix to blocks
			Calcul* c = new Calcul();
			Pipe::DataOp op;
			op.op = Pipe::OP_Minus;
			op.a.dt = Pipe::DT_Matrix;
			op.b.dt = Pipe::DT_Matrix;
			for ( size_type_t i=0; i<this->size1(); i++ ){
				op.a.tab = ctr::vector<double>(this->size2(),0);
				op.b.tab = ctr::vector<double>(this->size2(),0);
				for( size_type_t j=0; j<this->size2(); j++ ){
					op.a.tab[j] = const_cast<matrix*>(this)->at_element(i,j);
					op.b.tab[j] = const_cast<matrix&>(m).at_element(i,j);
				}
				op.a.packet_id = i;
				op.b.packet_id = i;
				c->m_calcul.push_back(op);
				op.a.tab.clear();
				op.b.tab.clear();
			}
			const_cast<matrix&>(m).m_controller->fetch(c);
			return matrix(m.size1(),m.size2(),m.m_controller);
		}


		/*******************************************************************//**
		 * @brief Enable calcul distribution for a matrix-double multiplication
		 * @param[in] d		The value to multiply to this matrix.
		 * @return A fake matrix: m_hasCorrectValue is set to false. This value
		 * will be changed when setData will be called.
		 */
		inline matrix operator*( double d ) const
		{
			return const_cast<matrix*>(this)->op_on_dbl(d, Pipe::OP_Mult);
		}


		/*******************************************************************//**
		 * @brief Enable calcul distribution for a matrix-int multiplication
		 * @param[in] d		The value to multiply to this matrix.
		 * @return A fake matrix: m_hasCorrectValue is set to false. This value
		 * will be changed when setData will be called.
		 */
		inline matrix operator*( int d ) const
		{
			return const_cast<matrix*>(this)->op_on_dbl(d, Pipe::OP_Mult);
		}


		/*******************************************************************//**
		 * @brief Enable calcul distribution for a matrix-double division
		 * @param[in] d		The value to divide to this matrix.
		 * @return A fake matrix: m_hasCorrectValue is set to false. This value
		 * will be changed when setData will be called.
		 */
		inline matrix operator/( double d ) const
		{
			return const_cast<matrix*>(this)->op_on_dbl(d, Pipe::OP_Div);
		}


		/*******************************************************************//**
		 * @brief Enable calcul distribution for a matrix-int division
		 * @param[in] d		The value to divide to this matrix.
		 * @return A fake matrix: m_hasCorrectValue is set to false. This value
		 * will be changed when setData will be called.
		 */
		inline matrix operator/( int d ) const
		{
			return const_cast<matrix*>(this)->op_on_dbl(d, Pipe::OP_Div);
		}


		/*******************************************************************//**
		 * @brief Operation with a double
		 * @param[in] d		The value associated with the operation
		 * @param[in] _op	The operation to use: Matrix {_op} {d}
		 * @return A fake matrix: m_hasCorrectValue is set to false. This value
		 * will be changed when setData will be called.
		 */
		matrix op_on_dbl( double d, Pipe::t_Operation _op )
		{
			// matrix to blocks
			Calcul* c = new Calcul();
			Pipe::DataOp op;
			op.op = _op;
			op.a.dt = Pipe::DT_Matrix;
			op.b.dt = Pipe::DT_Double;
			op.b=Pipe::DataSerialized(d);
			for ( size_type_t i=0; i<this->size1(); i++ ){
				op.a.tab = ctr::vector<double>(this->size2(),0);
				for( size_type_t j=0; j<this->size2(); j++ ){
					op.a.tab[j] = const_cast<matrix*>(this)->at_element(i,j);
				}
				op.a.packet_id = i;
				c->m_calcul.push_back(op);
				op.a.tab.clear();
			}
			m_controller->fetch(c);
			return matrix(this->size1(),this->size2(),m_controller);
		}


		/*******************************************************************//**
		 * @brief Enable simple affectation or make the calculation before the
		 * affectation.
		 * @param[in] m		The matrix to copy
		 * @return If it is not a simple affectation, it returns a fake matrix:
		 * m_hasCorrectValue is set to false. This value will be changed when
		 * setData will be called.
		 * If it is a simple affectation, it returns this matrix, a good matrix.
		 */
		matrix& operator=( const matrix& m )
		{
			// Affectation which first need a calculation
			if( !m.m_hasCorrectValue && m.m_controller->assoc(this) ){
				m_controller = m.m_controller;
				m_hasCorrectValue = false;
				return (*this);
			}
			// Simple affectation
			ublas::matrix<T,L,A>::operator =(m);
			return (*this);
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
			switch( op )
			{
				case Pipe::OP_Plus:
					for( unsigned int i=0; i<data.size(); i++ )
						for( size_type_t j=0; j<this->size2(); j++ )
							this->at_element(data.at(i).packet_id ,j) = data.at(i).tab[j];
					break;
				case Pipe::OP_Minus:
					for( unsigned int i=0; i<data.size(); i++ )
						for( size_type_t j=0; j<this->size2(); j++ )
							this->at_element(data.at(i).packet_id ,j) = data.at(i).tab[j];
					break;
				case Pipe::OP_Mult:
					for( unsigned int i=0; i<data.size(); i++ )
						for( size_type_t j=0; j<this->size2(); j++ )
							this->at_element(data.at(i).packet_id ,j) = data.at(i).tab[j];
					break;
				case Pipe::OP_Div:
					for( unsigned int i=0; i<data.size(); i++ )
						for( size_type_t j=0; j<this->size2(); j++ )
							this->at_element(data.at(i).packet_id ,j) = data.at(i).tab[j];
					break;
			}
			m_hasCorrectValue = true;
		}
};


}}}}// end namespace boost::numeric::ublas::distributed

#endif //_BOOST_UBLAS_DISTRIBUTED_MATRIX_
