/*
 dense matrix and vector multiplication kernel
*/

namespace clike {
    
double dmatvecmult(size_t N, size_t iterations = 1) {
    
    value_type** a = new value_type*[N];
    value_type* b = new value_type[N];
    value_type* c = new value_type[N];
    
    for(size_t i = 0; i < N; ++i){
        a[i] = new value_type[N];
    }

    minit(N, a);
    vinit(N, b);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        for(size_t i = 0; i < N; ++i) {
            double sum = 0;
            for(size_t j = 0; j < N; ++j) {
                sum += a[i][j] * b[j];
            }
            c[i] = sum;
        }
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    for(size_t i = 0; i < N; ++i){
        delete [] a[i];
    }
    
    delete [] a;
    delete [] b;
    delete [] c;
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if anything happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "clike kernel 'dmatvecmult': Time deviation too large! \n";
    }
    
    return tavg;
    
}

}