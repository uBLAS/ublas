/*
    syr2krect kernel
*/

namespace boost {
    
double syr2krect(size_t N, size_t iterations = 1){
    
    boost::numeric::ublas::matrix<value_type, boost::numeric::ublas::row_major> A(N, 1.5*N), B(N, 1.5*N), C(N, N);
    value_type c = 3, b = 5;
    
    rminit(N, 1.5*N, A);
    rminit(N, 1.5*N, B);
    minit(N, C);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        //C = c * prod(B, trans(A)) + c * prod(A, trans(B)) + b * C;
        C *= b;
        C += c * prod(A, trans(B));
        C += c * prod(B, trans(A));
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }

    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if nothing happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "boost kernel 'syr2krect': Time deviation too large! \n";
    }
    
    return tavg;
}

}