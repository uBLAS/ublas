
#ifndef STATIC_MATRIX_H
#define STATIC_MATRIX_H

#include <boost/numeric/ublas/functional.hpp>

template<class T, std::size_t M, std::size_t N, class L = boost::numeric::ublas::row_major>
class static_matrix : public Matrix_Container, public Matrix_Expression< static_matrix<T, M, N, L> > {
    
    typedef T *pointer;
    typedef L layout_type;
    typedef aligned_array<T, M * N> A;
    typedef static_matrix<T, M, N, L> self_type;
public:
    typedef typename A::size_type size_type;
    typedef typename A::difference_type difference_type;
    typedef T value_type;
    typedef const T& const_reference;
    typedef T& reference;
    typedef A array_type;
    typedef self_type matrix_temporary_type;
    typedef boost::numeric::ublas::dense_tag storage_category;
    typedef typename L::orientation_category orientation_category;
    
    // Construction and destruction
    
    /// Default dense matrix constructor. Make a dense matrix of size (M, N)
    inline static_matrix() : Matrix_Expression<self_type>(),
    size1_ (M), size2_ (N), data_ (layout_type::storage_size (M, N)) { }
    
    inline static_matrix(const value_type& init) : Matrix_Expression<self_type> (),
    size1_ (M), size2_ (N), data_ (layout_type::storage_size (M, N), init) { }
    
    inline static_matrix (const array_type& data) : Matrix_Expression<self_type> (),
    size1_ (M), size2_ (N), data_ (data) { }

    inline static_matrix (const static_matrix& m) : Matrix_Expression<self_type> (),
    size1_ (m.size1_), size2_ (m.size2_), data_ (m.data_) { }
 
    template<class MatExpr>
    inline static_matrix (const Matrix_Expression<MatExpr>& matexpr) : Matrix_Expression<self_type> (),
    size1_ (matexpr().size1()), size2_ (matexpr().size2 ()), data_(layout_type::storage_size (size1_, size2_)) {
        operator=(matexpr);
    }
    
    // Return the number of rows of the matrix
    inline size_type size1() const {
        return size1_;
    }
    inline size_type rows() const {
        return size1_;
    }
    
    // Return the number of colums of the matrix
    inline size_type size2() const {
        return size2_;
    }
    inline size_type cols() const {
        return size2_;
    }
    
    // Storage accessors
    inline const array_type& data() const {
        return data_;
    }
    inline array_type& data() {
        return data_;
    }
    
    // Element access
    inline const_reference operator()(size_type i, size_type j) const {
        return data()[layout_type::element(i, size1_, j, size2_)];
    }
    
    inline reference at_element(size_type i, size_type j) {
        return data()[layout_type::element(i, size1_, j, size2_)];
    }
    
    inline reference operator()(size_type i, size_type j) {
        return at_element(i, j);
    }
    
    // Element assignment
    inline reference insert_element(size_type i, size_type j, const_reference t) {
        return (at_element (i, j) = t);
    }
    
    // Erase the element
    inline void erase_element(size_type i, size_type j) {
        at_element(i, j) = value_type(0);
    }
    
    inline void clear() {
        std::fill(data().begin(), data().end(), value_type(0));
    }

    template<class MatExpr>
    inline static_matrix& operator = (const MatExpr& rmatexpr) {
        for(size_t i = 0; i < size1(); ++i){
            for(size_t j = 0; j < size2(); ++j){
                data_[i][j] = rmatexpr(i, j);
            }
        }
        
        return *this;
    }
    
private:
    size_type size1_;
    size_type size2_;
    array_type data_;
    
};

template <class T, std::size_t M>
using static_vector = static_matrix<T, M, 1>;

#endif