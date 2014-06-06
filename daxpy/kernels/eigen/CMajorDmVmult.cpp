/*
 cmajordmvmult kernel
*/

namespace eigen {
    
double cmajordmvmult(size_t N, size_t iterations = 1){
    
    Eigen::Matrix<value_type, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor> A(N, N);
    Eigen::Matrix<value_type, Eigen::Dynamic, 1> b(N), c(N);
    
    minit(N, A);
    vinit(N, b);

    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        c.noalias() = A * b;
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
  
    // check to see if nothing happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "eigen kernel 'cmajordmvmult': Time deviation too large! \n";
    }
   
    return tavg;
    
}

}