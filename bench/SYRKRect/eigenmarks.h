/*
 Benchmark class for Eigen3
*/

#ifndef EIGENMARKS_H
#define EIGENMARKS_H

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include "kernels/eigen/init/init.cpp"
#include "kernels/eigen/Custom.cpp"
#include "kernels/eigen/Daxpy.cpp"
#include "kernels/eigen/DmatDmatAdd.cpp"
#include "kernels/eigen/DmatDmatMult.cpp"
#include "kernels/eigen/DmatScalarMult.cpp"
#include "kernels/eigen/DmatVecMult.cpp"
#include "kernels/eigen/SmatSmatAdd.cpp"
#include "kernels/eigen/SmatSmatMult.cpp"
#include "kernels/eigen/SmatSvecMult.cpp"
#include "kernels/eigen/SmatVecMult.cpp"
#include "kernels/eigen/VecScalarMult.cpp"
#include "kernels/eigen/VecVecAdd.cpp"
#include "kernels/eigen/VecVecMult.cpp"
#include "kernels/eigen/CMajorDmDmmult.cpp"
#include "kernels/eigen/CMajorDmVmult.cpp"
#include "kernels/eigen/DotProduct.cpp"
#include "kernels/eigen/GEMV1.cpp"
#include "kernels/eigen/GEMV2.cpp"
#include "kernels/eigen/GER1.cpp"
#include "kernels/eigen/NestedProd.cpp"
#include "kernels/eigen/RMajorDmDmmult.cpp"
#include "kernels/eigen/RMajorDmVmult.cpp"
#include "kernels/eigen/Scale.cpp"
#include "kernels/eigen/SYMM1.cpp"
#include "kernels/eigen/SYMM1Rect.cpp"
#include "kernels/eigen/SYMM2.cpp"
#include "kernels/eigen/SYR.cpp"
#include "kernels/eigen/SYR2K.cpp"
#include "kernels/eigen/SYR2KRect.cpp"
#include "kernels/eigen/SYRK.cpp"
#include "kernels/eigen/SYRKRect.cpp"
#include "kernels/eigen/TRMV1.cpp"
#include "kernels/eigen/TRMV2.cpp"

namespace eigen {
    
class Eigenmarks {
    
public:
    explicit inline Eigenmarks(size_t, size_t);
    
    /* Some utility functions */
    inline size_t GetSize() const;
    inline size_t GetSteps() const;
    inline size_t GetFlops() const;
    inline double GetEigenResult() const;
    
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
    double eigen_result;      // Benchmark result of the Eigen3 library.
    
};
    
#include "eigenmarks.hpp"

}

#endif