/*
 Utility functions
*/

inline void vinit(size_t N, Eigen::VectorXd& data) {

    for(size_t i = 0; i < N; ++i){
        data(i) = distribution(generator);
    }
    
}

inline void minit(size_t N, Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>& data) {
    
    for(size_t i = 0; i < N; ++i){
        for(size_t j = 0; j < N; ++j){
            data(i, j) = distribution(generator);
        }
    }
    
}

inline void sminit(size_t N, Eigen::SparseMatrix<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        for(size_t j = 0; j < N; ++j){
            data.insert(i, j) = distribution(generator);
        }
    }
    data.makeCompressed();
    
}

inline void svinit(size_t N, Eigen::SparseVector<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        data.insert(i) = distribution(generator);
    }
    
}
