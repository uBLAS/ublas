/*
 dense matric and vector multiplication kernel
*/

namespace boost {

double dmatvecmult(size_t N, size_t iterations = 1) {
    
    boost::numeric::ublas::matrix<double> a(N, N);
    boost::numeric::ublas::vector<double> b(N), c(N);
    
    minit(a.size1(), a);
    vinit(b.size(), b);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        boost::numeric::ublas::axpy_prod(a, b, c, false);
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    /*
     // check to see if nothing happened during rum to invalidate the times
     if(tmin*(1.0 + deviation*0.01) < tavg){
     std::cerr << "uBLAS kernel 'dmatvecmult': Time deviation too large!!!" << std::endl;
     }
     */
    return tavg;
    
}

}