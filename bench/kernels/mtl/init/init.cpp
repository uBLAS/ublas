/*
 Utility functions
*/

inline void vinit(size_t N, mtl::dense_vector<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        data[i] = udistribution(generator);
    }
    
}

inline void minit(size_t N, mtl::dense2D<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        for(size_t j = 0; j < N; ++j){
            data[i][j] = udistribution(generator);
        }
    }
    
}

inline void sminit(size_t N, mtl::compressed2D<double>& data, double filling = 0.5) {
    
    // Matrices are not initialized by default
    data = 0.0;
    
    // Create inserter for matrix m
    mtl::mat::inserter< mtl::compressed2D<double> > ins(data);
    
    size_t Nelements = N*filling;
    for(size_t i = 0; i < Nelements; ++i){
        for(size_t j = 0; j < Nelements; ++j){
            ins[i][j] << udistribution(generator);
        }
    }
    
}

inline void sminit_Snormal(size_t N, mtl::compressed2D<double>& data, double filling = 0.5) { //default half filled
    
    data = 0.0;
    mtl::mat::inserter< mtl::compressed2D<double> > ins(data);
    
    size_t Nelements = N*filling;
    for(size_t i = 0; i < Nelements; ++i){
        for(size_t j = 0; j < Nelements; ++j){
            double num = udistribution(generator);
            ins[i][j] << num;
            ins[j][i] << num;
        }
    }
    
}