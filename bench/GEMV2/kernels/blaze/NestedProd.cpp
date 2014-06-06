/*
 nestedprod kernel
*/

namespace blaze {
    
double nestedprod(size_t N, size_t iterations = 1){
    
    blaze::DynamicMatrix<value_type, blaze::rowMajor> A(N, N), B(N, N), C(N, N), D(N, N), E(N, N), F(N, N);
    
    minit(N, B);
    minit(N, C);
    minit(N, D);
    minit(N, E);
    minit(N, F);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        A = B * C * D * E * F;
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if anything happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "blaze kernel 'nestedprod': Time deviation too large! \n";
    }
    
    return tavg;
    
}

}