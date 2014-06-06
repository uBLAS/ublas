/*
 trmv2 kernel
*/

namespace boost {
    
double trmv2(size_t N, size_t iterations = 1){
    
    boost::numeric::ublas::matrix<value_type, boost::numeric::ublas::row_major> A(N, N);
    boost::numeric::ublas::vector<value_type> a(N), b(N);
    
    vinit(a.size(), a);
    minit(A.size1(), A);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        a = prod(trans(A), a);
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }

    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if nothing happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "boost kernel 'trmv2': Time deviation too large! \n";
    }
    
    return tavg;
}

}