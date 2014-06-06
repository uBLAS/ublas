/*
 Benchmark class for uBlas
*/

#ifndef UBLASMARKS_H
#define UBLASMARKS_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "kernels/ublas/init/init.cpp"
#include "kernels/ublas/Custom.cpp"
#include "kernels/ublas/Daxpy.cpp"
#include "kernels/ublas/DmatDmatAdd.cpp"
#include "kernels/ublas/DmatDmatMult.cpp"
#include "kernels/ublas/DmatScalarMult.cpp"
#include "kernels/ublas/DmatVecMult.cpp"
#include "kernels/ublas/SmatSmatAdd.cpp"
#include "kernels/ublas/SmatSmatMult.cpp"
#include "kernels/ublas/SmatSvecMult.cpp"
#include "kernels/ublas/SmatVecMult.cpp"
#include "kernels/ublas/VecScalarMult.cpp"
#include "kernels/ublas/VecVecAdd.cpp"
#include "kernels/ublas/VecVecMult.cpp"
#include "kernels/ublas/CMajorDmDmmult.cpp"
#include "kernels/ublas/CMajorDmVmult.cpp"
#include "kernels/ublas/DotProduct.cpp"
#include "kernels/ublas/GEMV1.cpp"
#include "kernels/ublas/GEMV2.cpp"
#include "kernels/ublas/GER1.cpp"
#include "kernels/ublas/NestedProd.cpp"
#include "kernels/ublas/RMajorDmDmmult.cpp"
#include "kernels/ublas/RMajorDmVmult.cpp"
#include "kernels/ublas/Scale.cpp"
#include "kernels/ublas/SYMM1.cpp"
#include "kernels/ublas/SYMM1Rect.cpp"
#include "kernels/ublas/SYMM2.cpp"
#include "kernels/ublas/SYR.cpp"
#include "kernels/ublas/SYR2K.cpp"
#include "kernels/ublas/SYR2KRect.cpp"
#include "kernels/ublas/SYRK.cpp"
#include "kernels/ublas/SYRKRect.cpp"
#include "kernels/ublas/TRMV1.cpp"
#include "kernels/ublas/TRMV2.cpp"

namespace boost {
    
class Ublasmarks {
    
public:
    explicit inline Ublasmarks(size_t, size_t);
    
    /* Some utility functions */
    inline size_t GetSize() const;
    inline size_t GetSteps() const;
    inline size_t GetFlops() const;
    inline double GetuBlasResult() const;
    
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
    double uBlas_result;      // Benchmark result of the Boost uBLAS library.

};
    
#include "ublasmarks.hpp"
    
}

#endif