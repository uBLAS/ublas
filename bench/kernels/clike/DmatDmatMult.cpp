/*
 dense matrix and dense matrix multiplication kernel
*/

namespace clike {

double dmatdmatmult(size_t N, size_t iterations = 1) {
    
    double** a = new double*[N];
    double** b = new double*[N];
    double** c = new double*[N];
    
    for(size_t i = 0; i < N; ++i){
        a[i] = new double[N];
        b[i] = new double[N];
        c[i] = new double[N];
    }
    
    minit(N, a);
    minit(N, b);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        for(size_t i = 0; i < N; ++i) {
            for(size_t j = 0; j < N; ++j) {
                
                double sum = 0;
                for(size_t inner = 0; inner < N; ++inner) {
                    sum += a[i][inner] * b[inner][j];
                }
                
                c[i][j] = sum;
            }
        }
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    for(size_t i = 0; i < N; ++i){
        delete [] a[i];
        delete [] b[i];
        delete [] c[i];
    }
    
    delete [] a;
    delete [] b;
    delete [] c;
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
 /*
    // check to see if nothing happened during rum to invalidate the times
    if(tmin*(1.0 + deviation*0.01) < tavg){
        std::cerr << "uBLAS kernel 'dmatdmatmult': Time deviation too large!!!" << std::endl;
    }
*/
    return tavg;
    
}

}