/*
 Benchmark class for C style kernels
*/

#ifndef CMARKS_H
#define CMARKS_H

#include "kernels/clike/init/init.cpp"
#include "kernels/clike/Custom.cpp"
#include "kernels/clike/Daxpy.cpp"
#include "kernels/clike/DmatDmatAdd.cpp"
#include "kernels/clike/DmatDmatMult.cpp"
#include "kernels/clike/DmatVecMult.cpp"
#include "kernels/clike/VecVecAdd.cpp"
#include "kernels/clike/VecVecMult.cpp"

namespace clike {
    
class Cmarks {
    
public:
    explicit inline Cmarks(size_t, size_t);
    
    /* Some utility functions */
    inline size_t GetSize() const;
    inline size_t GetSteps() const;
    inline size_t GetFlops() const;
    inline double GetClikeResult() const;
    
    inline void SetSize(size_t);
    inline void SetSteps(size_t);
    inline void EstimateFlops(size_t);
    
    /* Benchmark functions for the various types */
    void DmatDmatRun(std::string);
    void DmatVecRun(std::string);
    void VecVecRun(std::string);
    
private:
    size_t size;
    size_t steps;
    size_t flops;
    double clike_result;      // Benchmark result of the C-like implementation.
    
};

#include "cmarks.hpp"
    
}

#endif