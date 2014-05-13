/*
 Basic benchmark setup for UBlas and GSoC 2014.
 By: Mark Lingle
 Date: 5/6/14
 
 Libraries included:
 1. http://www.boost.org/doc/libs/1_55_0b1/libs/numeric/ublas/doc/index.htm
 2. https://code.google.com/p/blaze-lib/
 3. http://eigen.tuxfamily.org/index.php?title=Main_Page
 4. http://www.osl.iu.edu/research/mtl/
*/


#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include "utilities.cpp"
#include "ublasmarks.h"
#include "blazemarks.h"
#include "eigenmarks.h"
#include "mtlmarks.h"
#include "cmarks.h"

template <typename lib>
void EstimateFlops(size_t N, lib& name) {
    double filling = 0.25;
    
    name.SetFlops( N*(2*N*filling - 1) ); //flop complexity for sparse matrix and dense vector multiplication
}

int main(int argc, char **argv){ //need to check namespaces and functions in classes!
    
    std::string ckernel = "smatvecmult";
    size_t N = 10;
    size_t steps = 1;
    std::cout << "Using compute kernel " << ckernel << std::endl << std::endl;

    for( ; N <= 100000; N *= 10){
        
        std::cout << "SIZE " << N << std::endl << std::endl;

        clike::Cmarks cmarks(N, steps);
        EstimateFlops(N, cmarks);
        cmarks.SmatVecRun(ckernel);
        std::cout << "cmarks " << cmarks.GetClikeResult() << " s " << std::endl;
        std::cout << "cmarks " << (cmarks.GetFlops() * steps) / (cmarks.GetClikeResult() * 1E6) << " MFLOPS " << std::endl << std::endl;

        blaze::Blazemarks blazemarks(N, steps);
        EstimateFlops(N, blazemarks);
        blazemarks.SmatVecRun(ckernel);
        std::cout << "blazemarks " << blazemarks.GetBlazeResult() << " s " << std::endl;
        std::cout << "blazemarks " << (blazemarks.GetFlops() * steps) / (blazemarks.GetBlazeResult() * 1E6) << " MFLOPS " << std::endl << std::endl;
 
        boost::Ublasmarks ublasmarks(N, steps);
        EstimateFlops(N, ublasmarks);
        ublasmarks.SmatVecRun(ckernel);
        std::cout << "ublasmarks " << ublasmarks.GetuBlasResult() << " s " << std::endl;
        std::cout << "ublasmarks " << (ublasmarks.GetFlops() * steps) / (ublasmarks.GetuBlasResult() * 1E6) << " MFLOPS " << std::endl << std::endl;

        eigen::Eigenmarks eigenmarks(N, steps);
        EstimateFlops(N, eigenmarks);
        eigenmarks.SmatVecRun(ckernel);
        std::cout << "eigenmarks " << eigenmarks.GetEigenResult() << " s " << std::endl;
        std::cout << "eigenmarks " << (eigenmarks.GetFlops() * steps) / (eigenmarks.GetEigenResult() * 1E6) << " MFLOPS " << std::endl << std::endl;

        mtl::MTLmarks mtlmarks(N, steps);
        EstimateFlops(N, mtlmarks);
        mtlmarks.SmatVecRun(ckernel);
        std::cout << "mtlmarks " << mtlmarks.GetMTLResult() << " s " << std::endl;
        std::cout << "mtlmarks " << (mtlmarks.GetFlops() * steps) / (mtlmarks.GetMTLResult() * 1E6) << " MFLOPS " << std::endl << std::endl;

    }

    return 0;
}