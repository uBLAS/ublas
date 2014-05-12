/*
 Utility functions
*/

inline void vinit(size_t N, blaze::DynamicVector<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        data[i] = udistribution(generator);
    }
    
}

inline void minit(size_t N, blaze::DynamicMatrix<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        for(size_t j = 0; j < N; ++j){
            data(i, j) = udistribution(generator);
        }
    }
    
}

inline void sminit(size_t N, blaze::CompressedMatrix<double>& data, double filling = 0.5) {
    
    size_t Nelements = N*filling;
    for(size_t i = 0; i < Nelements; ++i){
        for(size_t j = 0; j < Nelements; ++j){
            data(i, j) = udistribution(generator);
        }
    }
    
}

inline void svinit(size_t N, blaze::CompressedVector<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        data[i] = udistribution(generator);
    }
    
}

inline void sminit_Snormal(size_t N, blaze::CompressedMatrix<double>& data, double filling = 0.5) { //default half filled
    
    size_t Nelements = N*filling;
    for(size_t i = 0; i < Nelements; ++i){
        for(size_t j = 0; j < Nelements; ++j){
            data(i, j) = ndistribution(generator);
            data(j, i) = data(i, j);
        }
    }
    
}