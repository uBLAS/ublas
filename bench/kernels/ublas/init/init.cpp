/*
 Utility functions
*/

inline void vinit(size_t N, boost::numeric::ublas::vector<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        data(i) = distribution(generator);
    }
    
}

inline void minit(size_t N, boost::numeric::ublas::matrix<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        for(size_t j = 0; j < N; ++j){
            data(i, j) = distribution(generator);
        }
    }
    
}

inline void sminit(size_t N, boost::numeric::ublas::compressed_matrix<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        for(size_t j = 0; j < N; ++j){
            data(i, j) = distribution(generator);
        }
    }
    
}

inline void svinit(size_t N, boost::numeric::ublas::compressed_vector<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        data(i) = distribution(generator);
    }
    
}

