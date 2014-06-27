/*
    Simple aligned array class.
    Borrows heavily from the existing uBlas library to emulate the implementation.
*/

#ifndef ALIGNED_ARRAY_H
#define ALIGNED_ARRAY_H

#include <algorithm>
#include <boost/align/aligned_allocator.hpp>
//#include <boost/numeric/ublas/exception.hpp>
//#include <boost/numeric/ublas/traits.hpp>
//#include <boost/numeric/ublas/detail/iterator.hpp>
#include "alignment_trait.hpp"


// Base class for Storage Arrays - see the Barton Nackman trick
template<class E>
class storage_array { };

// Aligned array - with boost aligned_allocator
template<typename T, std::size_t N, size_t Alignment = alignment_trait<T>::value >
class aligned_array : public storage_array< aligned_array<T, N, Alignment> > {
    
    typedef aligned_array<T, N, Alignment> self_type;
public:
    typedef boost::alignment::aligned_allocator<T, Alignment> allocator_type;
    typedef typename allocator_type::size_type size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef T value_type;
    typedef const T &const_reference;
    typedef T &reference;
    typedef const T *const_pointer;
    typedef T *pointer;
    typedef const_pointer const_iterator;
    typedef pointer iterator;
    
    // Construction and destruction
    inline explicit aligned_array() : alloc_ (allocator_type()), size_ (N) {
        if(size_) {
            data_ = alloc_.allocate (size_);
        }
        else {
            data_ = nullptr;
        }
    }
    inline aligned_array(const value_type& init) : alloc_ (allocator_type()), size_ (N)  {
        data_ = alloc_.allocate (size_);
        std::fill(begin(), end(), init) ;
    }
    inline aligned_array(const aligned_array& c) : alloc_ (c.alloc_), size_ (c.size_)  {
        data_ = alloc_.allocate(size_);
        std::copy(c.begin(), c.end(), begin());
    }
    inline ~aligned_array() {
        alloc_.deallocate(data_, size_);
    }
    
    inline void clear() const {
        for(auto& i : data_ ) {
            i = 0;
        }
    }
    
    inline size_type size() const {
        return size_;
    }
    
    // Element access
    inline const_reference operator[] (size_type i) const {
        return data_ [i];
    }
    inline reference operator[] (size_type i) {
        return data_ [i];
    }
    
    // Assignment
    inline aligned_array& operator=(const aligned_array& a) {
        if(this != &a) {
            std::copy(a.data_, a.data_ + a.size_, data_);
        }
        return *this;
    }
    inline aligned_array& assign_temporary (aligned_array& a) {
        *this = a;
        return *this;
    }
    
    // Swapping
    inline void swap(aligned_array &a) {
        if (this != &a) {
            std::swap_ranges (data_, data_ + (std::max) (size_, a.size_), a.data_); //?
        }
    }
    inline friend void swap(aligned_array &a1, aligned_array &a2) {
        a1.swap (a2);
    }
    
    // Iterators
    inline const_iterator begin() const {
        return data_;
    }
    inline const_iterator end() const {
        return data_ + size_;
    }
    
    inline iterator begin() {
        return data_;
    }
    inline iterator end() {
        return data_ + size_;
    }
    
    // Reverse iterators
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    
    inline const_reverse_iterator rbegin() const {
        return const_reverse_iterator (end ());
    }
    inline const_reverse_iterator rend() const {
        return const_reverse_iterator (begin ());
    }
    inline reverse_iterator rbegin() {
        return reverse_iterator (end ());
    }
    inline reverse_iterator rend() {
        return reverse_iterator (begin ());
    }
    
private:
    
    allocator_type alloc_;
    size_type size_;
    pointer data_;
    
};

#endif
