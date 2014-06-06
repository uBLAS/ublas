/*
 syr kernel
*/

namespace blaze {
    
double syr(size_t N, size_t iterations = 1){
    
    blaze::DynamicMatrix<value_type, blaze::rowMajor> A(N, N);
    blaze::DynamicVector<value_type, blaze::columnVector> a(N), b(N);
    value_type c = 3, d = 5;
    
    vinit(N, a);
    vinit(N, b);
    minit(N, A);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        A = c * a * trans(b) + c * b * trans(a) + A;
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if anything happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "blaze kernel 'syr': Time deviation too large! \n";
    }
    
    return tavg;
    
}

}