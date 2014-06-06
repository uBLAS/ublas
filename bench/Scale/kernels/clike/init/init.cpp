/*
 Utility functions
*/

namespace clike {
    
    inline void vinit(size_t N, value_type* data) {
        
        for(size_t i = 0; i < N; ++i){
            data[i] = udistribution(generator);
        }
        
    }
    
    inline void vinit(size_t N, value_type** data) {
        
        for(size_t i = 0; i < N; ++i){
            data[0][i] = udistribution(generator);
        }
        
    }
    
    inline void minit(size_t N, value_type** data) {
        
        for(size_t i = 0; i < N; ++i){
            for(size_t j = 0; j < N; ++j){
                data[i][j] = udistribution(generator);
            }
        }
        
    }
    
}