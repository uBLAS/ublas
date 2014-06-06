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
#include <fstream>
#include "utilities.cpp"
#include "ublasmarks.h"
#include "blazemarks.h"
#include "eigenmarks.h"
#include "mtlmarks.h"
#include "cmarks.h"

template <typename lib>
void EstimateFlops(size_t N, lib& name) {
    name.SetFlops( 2*N ); //flop complexity for daxpy
}

int main(int argc, char **argv){ 
    
    std::string ckernel = "daxpy";
    size_t N = 10, Nmax = 1000000, Ninc = 500;
    size_t steps = 3;
    std::ofstream outfile;

    outfile.open("clike.dat");
    for(size_t NN = N; NN <= Nmax; NN += Ninc){

        clike::Cmarks cmarks(NN, steps);
        EstimateFlops(NN, cmarks);
        cmarks.VecVecRun(ckernel);
        
        outfile << NN << " " << cmarks.GetFlops() / (cmarks.GetClikeResult() * 1E6) << std::endl;

    }
    outfile.close();
    
    outfile.open("blaze.dat");
    for(size_t NN = N; NN <= Nmax; NN += Ninc){
        
        blaze::Blazemarks blazemarks(NN, steps);
        EstimateFlops(NN, blazemarks);
        blazemarks.VecVecRun(ckernel);
        
        outfile << NN << " " << blazemarks.GetFlops() / (blazemarks.GetBlazeResult() * 1E6) << std::endl;

    }
    outfile.close();
    
    outfile.open("ublas.dat");
    for(size_t NN = N; NN <= Nmax; NN += Ninc){
        
        boost::Ublasmarks ublasmarks(NN, steps);
        EstimateFlops(NN, ublasmarks);
        ublasmarks.VecVecRun(ckernel);
        
        outfile << NN << " " << ublasmarks.GetFlops() / (ublasmarks.GetuBlasResult() * 1E6) << std::endl;
        
    }
    outfile.close();
    
    outfile.open("eigen.dat");
    for(size_t NN = N; NN <= Nmax; NN += Ninc){
        
        eigen::Eigenmarks eigenmarks(NN, steps);
        EstimateFlops(NN, eigenmarks);
        eigenmarks.VecVecRun(ckernel);
        
        outfile << NN << " " << eigenmarks.GetFlops() / (eigenmarks.GetEigenResult() * 1E6) << std::endl;

    }
    outfile.close();
    
    outfile.open("mtl.dat");
    for(size_t NN = N; NN <= Nmax; NN += Ninc){
        
        mtl::MTLmarks mtlmarks(NN, steps);
        EstimateFlops(NN, mtlmarks);
        mtlmarks.VecVecRun(ckernel);
        
        outfile << NN << " " << mtlmarks.GetFlops() / (mtlmarks.GetMTLResult() * 1E6) << std::endl;

    }
    outfile.close();

    return 0;
}