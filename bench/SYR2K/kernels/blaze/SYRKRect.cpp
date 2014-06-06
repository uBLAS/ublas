/*
 syrkrect kernel
*/

namespace blaze {
    
double syrkrect(size_t N, size_t iterations = 1){
    
    blaze::DynamicMatrix<value_type, blaze::rowMajor> A(N, 1.5*N), C(N, N);
    
    rminit(N, 1.5*N, A);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        C = A * trans(A);
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if anything happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "blaze kernel 'syrkrect': Time deviation too large! \n";
    }
    
    return tavg;
    
}

}