/*
 spare matrix and sparse vector multiplication kernel
*/


namespace eigen {
    
double smatvecmult(size_t N, size_t iterations = 1) {
    
    Eigen::SparseMatrix<double> a(N, N);
    Eigen::VectorXd b(N), c(N);
    
    sminit(a.rows(), a);
    vinit(b.rows(), b);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        c = a * b;
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if nothing happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "eigen kernel 'smatvecmult': Time deviation too large!!!" << std::endl;
    }
    
    return tavg;
    
}

}