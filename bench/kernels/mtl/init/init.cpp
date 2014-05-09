/*
 Utility functions
*/

inline void vinit(size_t N, mtl::dense_vector<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        data[i] = distribution(generator);
    }
    
}

inline void minit(size_t N, mtl::dense2D<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        for(size_t j = 0; j < N; ++j){
            data[i][j] = distribution(generator);
        }
    }
    
}

inline void sminit(size_t N, mtl::compressed2D<double>& data) {
    
    // Matrices are not initialized by default
    data = 0.0;
    
    // Create inserter for matrix m
    mtl::mat::inserter< mtl::compressed2D<double> > ins(data);
    
    for(size_t i = 0; i < N; ++i){
        for(size_t j = 0; j < N; ++j){
            ins[i][j] << distribution(generator);
        }
    }
    
}
