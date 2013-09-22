#ifndef _BOOST_UBLAS_DISTRIBUTED_PIPE_HPP_
#define _BOOST_UBLAS_DISTRIBUTED_PIPE_HPP_

#include <boost/serialization/access.hpp>
//#include <boost/container/vector.hpp>// Has no serialize
#include <boost/serialization/vector.hpp>
#include <vector>
namespace ctr = std;

namespace boost { namespace numeric { namespace ublas { namespace distributed { namespace details {
namespace Pipe
{
	/***********************************************************************//**
	 * @brief Instructions for @see MainChannel::toListen
	 */
	typedef enum {
		LS_unListen = 0,//!< UnListen a tag
		LS_Listen = 1,//!< Listen a tag
		LS_Exit = 2//!< Exit the loop
	} t_ListenStatus;


	/***********************************************************************//**
	 * @brief This struct is used in order to communicate in the channel (tag) 0.
	 * This channel is used to say: "Listen tag n°42" Or "UnListen tag n°69"
	 */
	struct MainChannel
	{
		int		tag;//!< Tag to listen/unlisten
		char	toListen;//!< (cf t_ListenStatus) If 0 =>unlisten the tag {tag}, if 1 =>listen the tag {tag}, if 2 =>exit
						 //!< We use a char and not a t_ListenStatus for the size. (enum=>4o, char 1o)

		inline MainChannel(): tag(0), toListen(LS_Listen) {}
		inline MainChannel( int pTag, char pToListen ): tag(pTag), toListen(pToListen) {}

		// Serialize
		friend class boost::serialization::access;
		template<class Archive>
		void serialize( Archive& ar, const unsigned int version )
		{
			(void)version;
			ar & tag;
			ar & toListen;
		}
	};


	/**
	 * @brief Type of data
	 */
	typedef enum {
		DT_Matrix,
		DT_Vector,
		DT_Double
	} t_DataType;


	/**
	 * @brief Action on data
	 */
	typedef enum {
		OP_Plus,OP_Minus,OP_Mult,OP_Div
	} t_Operation;


	/***********************************************************************//**
	 * @brief This struct is a basic container for Matrix,Vector,...
	 * This struct is used on the network.
	 */
	struct DataSerialized {
		t_DataType			dt;//!< Data type for data_tab / data_int
		int					packet_id;//!< ID of the packet
		ctr::vector<double>	tab;//!< Array of Data

		// Basic constructor
		inline DataSerialized() : dt(DT_Double) {packet_id=0;}
		inline DataSerialized( double _dbl ) : dt(DT_Double) {tab.push_back(_dbl); packet_id=0;}
		inline DataSerialized( ctr::vector<double>& _tab ) : dt(DT_Matrix) {tab=_tab; packet_id=0;}
		inline DataSerialized( const DataSerialized& ds ){
			dt = ds.dt;
			packet_id = ds.packet_id;
			tab = ds.tab;
		}
		inline void operator=( const DataSerialized& ds ){
			dt = ds.dt;
			packet_id = ds.packet_id;
			tab = ds.tab;
		}

		// Serialize
		friend class boost::serialization::access;
		template<class Archive>
		void serialize( Archive& ar, const unsigned int version )
		{
			(void)version;
			ar & dt;
			ar & packet_id;
			ar & tab;
		}
	};


	/***********************************************************************//**
	 * @brief This struct is a basic container for operation between Matrix,Vector,...
	 * This struct is used on the network.
	 *
	 * a {op} b ---> a + b, a/b, ...
	 */
	struct DataOp
	{
		DataSerialized		a;//!< Data for a
		DataSerialized		b;//!< Data for b
		t_Operation			op;//!< Operation to use on a and b

		// Basic constructor
		inline DataOp():op(OP_Plus){}
		inline DataOp( const DataSerialized& _a, const DataSerialized& _b, t_Operation _op ):op(_op){a=_a; b=_b;}

		// Serialize
		friend class boost::serialization::access;
		template<class Archive>
		void serialize( Archive& ar, const unsigned int version )
		{
			(void)version;
			ar & a;
			ar & b;
			ar & op;
		}
	};
}
}}}}}

#endif// _BOOST_UBLAS_DISTRIBUTED_PIPE_HPP_
