/*
 Benchmark class for MTL
*/

#ifndef MTLMARKS_H
#define MTLMARKS_H

#include <boost/numeric/mtl/mtl.hpp>
#include "kernels/mtl/init/init.cpp"
#include "kernels/mtl/Custom.cpp"
#include "kernels/mtl/Daxpy.cpp"
#include "kernels/mtl/DmatDmatAdd.cpp"
#include "kernels/mtl/DmatDmatMult.cpp"
#include "kernels/mtl/DmatScalarMult.cpp"
#include "kernels/mtl/DmatVecMult.cpp"
#include "kernels/mtl/SmatSmatAdd.cpp"
#include "kernels/mtl/SmatSmatMult.cpp"
#include "kernels/mtl/SmatSvecMult.cpp"
#include "kernels/mtl/VecScalarMult.cpp"
#include "kernels/mtl/VecVecAdd.cpp"
#include "kernels/mtl/VecVecMult.cpp"

namespace mtl {
    
class MTLmarks {
    
public:
    explicit inline MTLmarks(size_t, size_t);
    
    /* Some utility functions */
    inline size_t GetSize() const;
    inline size_t GetSteps() const;
    inline size_t GetFlops() const;
    inline double GetMTLResult() const;
    
    inline void SetSize(size_t);
    inline void SetSteps(size_t);
    inline void EstimateFlops(size_t);
    
    /* Benchmark functions for the various types */
    void DmatScalarRun(std::string);
    void VecScalarRun(std::string);
    void DmatDmatRun(std::string);
    void DmatVecRun(std::string);
    void SmatSmatRun(std::string);
    void SmatSvecRun(std::string);
    void VecVecRun(std::string);
    
private:
    size_t size;
    size_t steps;
    size_t flops;
    double mtl_result;      // Benchmark result of the MTL implementation.
    
};
    
#include "mtlmarks.hpp"

}

#endif