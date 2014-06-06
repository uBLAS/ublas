/*
 Utility functions
*/

namespace blaze {
    
    template <typename vector_type>
    inline void vinit(size_t N, vector_type& data) {
        
        for(size_t i = 0; i < N; ++i){
            data[i] = udistribution(generator);
        }
        
    }
    
    template <typename matrix_type>
    inline void minit(size_t N, matrix_type& data) {
        
        for(size_t i = 0; i < N; ++i){
            for(size_t j = 0; j < N; ++j){
                data(i, j) = udistribution(generator);
            }
        }
        
    }
    
    template <typename matrix_type>
    inline void rminit(size_t N1, size_t N2, matrix_type& data) {
        
        for(size_t i = 0; i < N1; ++i){
            for(size_t j = 0; j < N2; ++j){
                data(i, j) = udistribution(generator);
            }
        }
        
    }
    
    template <typename sparse_matrix_type>
    inline void sminit(size_t N, sparse_matrix_type& data, double filling = 0.25) {
        
        size_t Nelements = N*filling;
        for(size_t i = 0; i < Nelements; ++i){
            for(size_t j = 0; j < Nelements; ++j){
                data(i, j) = udistribution(generator);
            }
        }
        
    }
    
    template <typename sparse_vector_type>
    inline void svinit(size_t N, sparse_vector_type& data) {
        
        for(size_t i = 0; i < N; ++i){
            data[i] = udistribution(generator);
        }
        
    }
    
}