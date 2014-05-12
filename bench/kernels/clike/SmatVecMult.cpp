/*
 spare matrix and sparse vector multiplication kernel
*/

namespace clike {
    
double smatvecmult(size_t N, size_t iterations = 1) {
    
    tav::SparseMatrix<double> a(N);
    a.type = 0;
    double** b = new double*[1];
    double** c = new double*[1];
    
    b[0] = new double[N];
    c[0] = new double[N];
    
    sminit(N, a);
    vinit(N, b);
    vinit(N, c);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        a.TimesMatrix(b, c, 1);
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    delete [] b[0];
    delete [] c[0];
    delete [] b;
    delete [] c;
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if nothing happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "clike kernel 'smatvecmult': Time deviation too large!!!" << std::endl;
    }
    
    return tavg;
    
}

}