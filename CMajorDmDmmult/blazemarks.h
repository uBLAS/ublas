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
#include "kernels/blaze/DmatScalarMult.cpp"
#include "kernels/blaze/DmatVecMult.cpp"
#include "kernels/blaze/SmatSmatAdd.cpp"
#include "kernels/blaze/SmatSmatMult.cpp"
#include "kernels/blaze/SmatSvecMult.cpp"
#include "kernels/blaze/SmatVecMult.cpp"
#include "kernels/blaze/VecScalarMult.cpp"
#include "kernels/blaze/VecVecAdd.cpp"
#include "kernels/blaze/VecVecMult.cpp"
#include "kernels/blaze/CMajorDmDmmult.cpp"
#include "kernels/blaze/CMajorDmVmult.cpp"
#include "kernels/blaze/DotProduct.cpp"
#include "kernels/blaze/GEMV1.cpp"
#include "kernels/blaze/GEMV2.cpp"
#include "kernels/blaze/GER1.cpp"
#include "kernels/blaze/NestedProd.cpp"
#include "kernels/blaze/RMajorDmDmmult.cpp"
#include "kernels/blaze/RMajorDmVmult.cpp"
#include "kernels/blaze/Scale.cpp"
#include "kernels/blaze/SYMM1.cpp"
#include "kernels/blaze/SYMM1Rect.cpp"
#include "kernels/blaze/SYMM2.cpp"
#include "kernels/blaze/SYR.cpp"
#include "kernels/blaze/SYR2K.cpp"
#include "kernels/blaze/SYR2KRect.cpp"
#include "kernels/blaze/SYRK.cpp"
#include "kernels/blaze/SYRKRect.cpp"
#include "kernels/blaze/TRMV1.cpp"
#include "kernels/blaze/TRMV2.cpp"

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
    inline void SetFlops(size_t);
    
    /* Benchmark functions for the various types */
    void DmatScalarRun(std::string);
    void VecScalarRun(std::string);
    void DmatDmatRun(std::string);
    void DmatVecRun(std::string);
    void SmatSmatRun(std::string);
    void SmatSvecRun(std::string);
    void SmatVecRun(std::string);
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