/*
 Utility functions
*/

inline void vinit(size_t N, Eigen::VectorXd& data) {

    for(size_t i = 0; i < N; ++i){
        data(i) = udistribution(generator);
    }
    
}

inline void minit(size_t N, Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>& data) {
    
    for(size_t i = 0; i < N; ++i){
        for(size_t j = 0; j < N; ++j){
            data(i, j) = udistribution(generator);
        }
    }
    
}

inline void sminit(size_t N, Eigen::SparseMatrix<double>& data, double filling = 0.25) {
    
    size_t Nelements = N*filling;
    for(size_t i = 0; i < Nelements; ++i){
        for(size_t j = 0; j < Nelements; ++j){
            data.insert(i, j) = udistribution(generator);
        }
    }
    data.makeCompressed();
    
}

inline void svinit(size_t N, Eigen::SparseVector<double>& data) {
    
    for(size_t i = 0; i < N; ++i){
        data.insert(i) = udistribution(generator);
    }
    
}

inline void sminit_Snormal(size_t N, Eigen::SparseMatrix<double>& data, double filling = 0.25) { 
    
    size_t Nelements = N*filling;
    for(size_t i = 0; i < Nelements; ++i){
        for(size_t j = 0; j < Nelements; ++j){
            double num = udistribution(generator);
            data.insert(i, j) = num;
            data.insert(j, i) = num;
        }
    }
    data.makeCompressed();
    
}