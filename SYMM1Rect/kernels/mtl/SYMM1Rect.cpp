/*
 symm1rect kernel
*/

namespace mtl {
    
double symm1rect(size_t N, size_t iterations = 1){

    typedef mtl::tag::row_major row_major;
    typedef mtl::mat::parameters<row_major> parameters;
    typedef mtl::dense2D<value_type, parameters> dense2D;
    typedef mtl::dense_vector<value_type> dense_vector;
    
    dense2D A(N, 1.5*N), B(N, 1.5*N), C(N, N);
    value_type c = 3;
    
    rminit(N, 1.5*N, A);
    rminit(N, 1.5*N, B);
    minit(N, C);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        C = c * A * trans(B) + c * C;
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if nothing happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "mtl kernel 'symm1rect': Time deviation too large! \n";
    }

    return tavg;
    
}

}