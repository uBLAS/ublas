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

int main(int argc, char **argv){
    
    std::string ckernel = "dmatdmatmult";
    size_t N = 1000;
    size_t steps = 10;
    std::cout << "Using compute kernel " << ckernel << std::endl;

    clike::Cmarks cmarks(N, steps);
    cmarks.DmatDmatRun(ckernel);
    std::cout << "cmarks " << cmarks.GetClikeResult() << std::endl;

    blaze::Blazemarks blazemarks(N, steps);
    blazemarks.DmatDmatRun(ckernel);
    std::cout << "blazemarks " << blazemarks.GetBlazeResult() << std::endl;
    
    boost::Ublasmarks ublasmarks(N, steps);
    ublasmarks.DmatDmatRun(ckernel);
    std::cout << "ublasmarks " << ublasmarks.GetuBlasResult() << std::endl;
    
    eigen::Eigenmarks eigenmarks(N, steps);
    eigenmarks.DmatDmatRun(ckernel);
    std::cout << "eigenmarks " << eigenmarks.GetEigenResult() << std::endl;

    mtl::MTLmarks mtlmarks(N, steps);
    mtlmarks.DmatDmatRun(ckernel);
    std::cout << "mtlmarks " << mtlmarks.GetMTLResult() << std::endl;


    return 0;
}