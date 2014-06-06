/*
 Dense vector and dense vector addition kernel
*/

namespace clike {

double vecvecadd(size_t N, size_t iterations = 1){
    
    value_type* a = new value_type[N];
    value_type* b = new value_type[N];
    value_type* c = new value_type[N];
    
    vinit(N, a);
    vinit(N, b);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();        
        for(size_t i = 0; i < N; ++i){
            c[i] = a[i] + b[i];
        }
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    delete [] a;
    delete [] b;
    delete [] c;
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if nothing happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "clike kernel 'vecvecadd': Time deviation too large! \n";
    }
    
    return tavg;
    
}

}