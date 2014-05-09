/*
 Utility functions
*/

inline void vinit(size_t N, blaze::DynamicVector<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        data[i] = distribution(generator);
    }
    
}

inline void minit(size_t N, blaze::DynamicMatrix<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        for(size_t j = 0; j < N; ++j){
            data(i, j) = distribution(generator);
        }
    }
    
}

inline void sminit(size_t N, blaze::CompressedMatrix<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        for(size_t j = 0; j < N; ++j){
            data(i, j) = distribution(generator);
        }
    }
    
}

inline void svinit(size_t N, blaze::CompressedVector<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        data[i] = distribution(generator);
    }
    
}
