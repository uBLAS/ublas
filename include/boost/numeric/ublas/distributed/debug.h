#ifndef _BOOST_UBLAS_DISTRIBUTED_DEBUG_H
#define _BOOST_UBLAS_DISTRIBUTED_DEBUG_H

#include <iostream>
/// @brief (debug) Print error.
#define dg( msg ) {std::cout <<"[file " << __FILE__ <<", line "<< __LINE__ << "] " << msg << std::endl; fflush(stdout);}
/// @brief Print error AND return {ret}
#define dgR( msg, ret ) {std::cout <<"[file " << __FILE__ <<", line "<< __LINE__ << "] " << msg << std::endl; fflush(stdout); return ret;}
/// @brief Print error AND return 0;
#define dgR0( msg ) {std::cout <<"[file " << __FILE__ <<", line "<< __LINE__ << "] " << msg << std::endl; fflush(stdout); return 0;}

#endif// _BOOST_UBLAS_DISTRIBUTED_DEBUG_H
