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
#include "kernels/eigen/DmatMscalarAdd.cpp"
#include "kernels/eigen/DmatScalarMult.cpp"
#include "kernels/eigen/DmatVecMult.cpp"
#include "kernels/eigen/Saxpy.cpp"
#include "kernels/eigen/SmatSmatAdd.cpp"
#include "kernels/eigen/SmatSmatMult.cpp"
#include "kernels/eigen/SmatSvecMult.cpp"
#include "kernels/eigen/VecVscalarAdd.cpp"
#include "kernels/eigen/VecScalarMult.cpp"
#include "kernels/eigen/VecVecAdd.cpp"
#include "kernels/eigen/VecVecMult.cpp"

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
    double eigen_result;      // Benchmark result of the Eigen3 library.
    
};
    
#include "eigenmarks.hpp"

}

#endif