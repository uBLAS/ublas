/*
 dense matrix and scalar matrix addition kernel
*/

namespace blaze {
    
double dmatmscalaradd(size_t N, size_t iterations = 1) {
    
    blaze::DynamicMatrix<double> a(N, N), b(N, N);
    double c = 3;
    
    minit(a.rows(), a);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        a = b + blaze::DynamicMatrix<double>(N, N, c);
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if anything happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "blaze kernel 'dmatmscalaradd': Time deviation too large!!!" << std::endl;
    }
    
    return tavg;
    
}

}