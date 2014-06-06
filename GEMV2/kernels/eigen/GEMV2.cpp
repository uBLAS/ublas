/*
 gemv2 kernel
*/

namespace eigen {
    
double gemv2(size_t N, size_t iterations = 1){
    
    Eigen::Matrix<value_type, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> A(N, N);
    Eigen::Matrix<value_type, Eigen::Dynamic, 1> a(N), b(N);
    value_type c = 3, d = 5;
    
    vinit(a.rows(), a);
    vinit(b.rows(), b);
    minit(A.rows(), A);

    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        b = c * A.transpose() * a + d * b;
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if nothing happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "eigen kernel 'gemv2': Time deviation too large! \n";
    }
    
    return tavg;
    
}

}