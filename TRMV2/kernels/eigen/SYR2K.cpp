/*
 syr2k kernel
*/

namespace eigen {
    
double syr2k(size_t N, size_t iterations = 1){
    
    Eigen::Matrix<value_type, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> A(N, N), B(N, N), C(N, N);
    value_type c = 3, d = 5;
    
    minit(N, A);
    minit(N, B);
    minit(N, C);

    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        C = c * B * A.transpose() + c * A * B.transpose() + d * C;
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);

    // check to see if nothing happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "eigen kernel 'syr2k': Time deviation too large! \n";
    }
   
    return tavg;
    
}

}