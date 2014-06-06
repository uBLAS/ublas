/*
 Dense vector and dense vector addition kernel
*/

namespace eigen {
    
double vecvecadd(size_t N, size_t iterations = 1){
    
    Eigen::VectorXd a(N), b(N), c(N);
    
    vinit(a.rows(), a);
    vinit(b.rows(), b);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();        
        c = a + b;
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if nothing happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "eigen kernel 'vecvecadd': Time deviation too large! \n";
    }
    
    return tavg;
    
}

}