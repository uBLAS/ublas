/*
 cmajordmvmult kernel
*/

namespace mtl {
    
double cmajordmvmult(size_t N, size_t iterations = 1){

    typedef mtl::tag::col_major col_major;
    typedef mtl::mat::parameters<col_major> parameters;
    typedef mtl::dense2D<value_type, parameters> dense2D;
    typedef mtl::dense_vector<value_type> dense_vector;
    
    dense2D A(N, N);
    dense_vector b(N), c(N);
    
    minit(N, A);
    vinit(N, b);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        c = A * b;
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
 
    // check to see if nothing happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "mtl kernel 'cmajordmvmult': Time deviation too large! \n";
    }

    return tavg;
    
}

}