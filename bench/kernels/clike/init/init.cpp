/*
 Utility functions
*/

inline void vinit(size_t N, double* data) {
    
    for(size_t i = 0; i < N; ++i){
        data[i] = udistribution(generator);
    }
    
}

inline void vinit(size_t N, double** data) {
    
    for(size_t i = 0; i < N; ++i){
        data[0][i] = udistribution(generator);
    }
    
}


inline void minit(size_t N, double** data) {
    
    for(size_t i = 0; i < N; ++i){
        for(size_t j = 0; j < N; ++j){
            data[i][j] = udistribution(generator);
        }
    }
    
}

inline void sminit(size_t N, tav::SparseMatrix<double>& data, double filling = 0.5) {
    
    size_t Nelements = N*filling;
    for(size_t i = 0; i < Nelements; ++i){
        for(size_t j = 0; j < Nelements; ++j){ 
            data(i, j) = udistribution(generator);
            data.Sync();
        }
    }
    
}