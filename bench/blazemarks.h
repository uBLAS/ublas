/*
    Benchmark class for Blaze-lib
*/

#ifndef BLAZEMARKS_H
#define BLAZEMARKS_H

#include <blaze/Math.h>
#include "kernels/blaze/init/init.cpp"
#include "kernels/blaze/Custom.cpp"
#include "kernels/blaze/Daxpy.cpp"
#include "kernels/blaze/DmatDmatAdd.cpp"
#include "kernels/blaze/DmatDmatMult.cpp"
#include "kernels/blaze/DmatMscalarAdd.cpp"
#include "kernels/blaze/DmatScalarMult.cpp"
#include "kernels/blaze/DmatVecMult.cpp"
#include "kernels/blaze/Saxpy.cpp"
#include "kernels/blaze/SmatSmatAdd.cpp"
#include "kernels/blaze/SmatSmatMult.cpp"
#include "kernels/blaze/SmatSvecMult.cpp"
#include "kernels/blaze/VecVscalarAdd.cpp"
#include "kernels/blaze/VecScalarMult.cpp"
#include "kernels/blaze/VecVecAdd.cpp"
#include "kernels/blaze/VecVecMult.cpp"

namespace blaze {
    
class Blazemarks {

public:
    explicit inline Blazemarks(size_t, size_t);
    
    /* Some utility functions */
    inline size_t GetSize() const;
    inline size_t GetSteps() const;
    inline size_t GetFlops() const;
    inline double GetBlazeResult() const;
    
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
    double blaze_result;      // Benchmark result of the Blaze library.
    
};
    
#include "blazemarks.hpp"
    
}

#endif