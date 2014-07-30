
#ifndef STATIC_MATRIX_H
#define STATIC_MATRIX_H

#include <boost/numeric/ublas/functional.hpp>

template<class T, std::size_t M, std::size_t N, class L>
class static_matrix : public matrix_expression< static_matrix<T, M, N, L> > {
    
private:
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
    typedef const matrix_reference<const self_type> const_closure_type;
    typedef matrix_reference<self_type> closure_type;
    typedef vector<T, A> vector_temporary_type;
    typedef self_type matrix_temporary_type;
    typedef dense_tag storage_category;
    typedef const static_matrix& nested_type;
    
    typedef typename L::orientation_category orientation_category;
    
    using matrix_expression< static_matrix<T, M, N, L> >::operator=;
    using matrix_expression< static_matrix<T, M, N, L> >::operator+=;
    using matrix_expression< static_matrix<T, M, N, L> >::operator-=;
    
    // Construction and destruction
    
    /// Default dense matrix constructor. Make a dense matrix of size (M, N)
    BOOST_UBLAS_INLINE
    static_matrix () :
    size1_ (M), size2_ (N), data_ ( value_type(0) ) { }
    
    /** Dense matrix constructor with defined size and initial value for all the matrix elements
     * \param size1 number of rows
     * \param size2 number of columns
     * \param init initial value assigned to all elements
     */
    static_matrix (const value_type& init) :
    size1_ (M), size2_ (N), data_ ( value_type(init) ) { }
    
    /** Dense matrix constructor with defined size and an initial data array
     * \param size1 number of rows
     * \param size2 number of columns
     * \param data array to copy into the matrix. Must have the same dimension as the matrix
     */
    BOOST_UBLAS_INLINE
    static_matrix (const array_type& data) :
    size1_ (M), size2_ (N), data_ (data) { }
    
    /** Copy-constructor of a dense matrix
     * \param m is a dense matrix
     */
    BOOST_UBLAS_INLINE
    static_matrix (const static_matrix& m) :
    size1_ (m.size1_), size2_ (m.size2_), data_ (m.data_) { }
    
    /** Copy-constructor of a dense matrix from a matrix expression
     * \param e is a matrix expression
     */
    template <typename E>
    BOOST_UBLAS_INLINE
    static_matrix (const matrix_expression<E>& e) :
    size1_ (e().size1()), size2_ (e().size2()), data_ (value_type(0)) {
        matrix_assign<scalar_assign> (*this, e);
    }
    
    // Accessors
    /** Return the number of rows of the matrix
     * You can also use the free size<>() function in operation/size.hpp as size<1>(m) where m is a matrix
     */
    BOOST_UBLAS_INLINE
    size_type size1 () const {
        return size1_;
    }
    BOOST_UBLAS_INLINE
    size_type rows () const {
        return size1_;
    }
    
    /** Return the number of colums of the matrix
     * You can also use the free size<>() function in operation/size.hpp as size<2>(m) where m is a matrix
     */
    BOOST_UBLAS_INLINE
    size_type size2 () const {
        return size2_;
    }
    BOOST_UBLAS_INLINE
    size_type cols () const {
        return size2_;
    }
    
    // Storage accessors
    /** Return a constant reference to the internal storage of a dense matrix, i.e. the raw data
     * It's type depends on the type used by the matrix to store its data
     */
    BOOST_UBLAS_INLINE
    const array_type& data () const {
        return data_;
    }
    /** Return a reference to the internal storage of a dense matrix, i.e. the raw data
     * It's type depends on the type used by the matrix to store its data
     */
    BOOST_UBLAS_INLINE
    array_type& data () {
        return data_;
    }
    
    // Element access
    
    /** Access a matrix element. Here we return a const reference
     * \param i the first coordinate of the element. By default it's the row
     * \param j the second coordinate of the element. By default it's the column
     * \return a const reference to the element
     */
    BOOST_UBLAS_INLINE
    const_reference operator () (size_type i, size_type j) const {
        return data () [layout_type::element (i, size1_, j, size2_)];
    }
    
    /** Access a matrix element. Here we return a reference
     * \param i the first coordinate of the element. By default it's the row
     * \param j the second coordinate of the element. By default it's the column
     * \return a reference to the element
     */
    BOOST_UBLAS_INLINE
    reference at_element (size_type i, size_type j) {
        return data () [layout_type::element (i, size1_, j, size2_)];
    }
    
    /** Access a matrix element. Here we return a reference
     * \param i the first coordinate of the element. By default it's the row
     * \param j the second coordinate of the element. By default it's the column
     * \return a reference to the element
     */
    BOOST_UBLAS_INLINE
    reference operator () (size_type i, size_type j) {
        return at_element (i, j);
    }
    
    // Element assignment
    
    /** Change the value of a matrix element. Return back a reference to it
     * \param i the first coordinate of the element. By default it's the row
     * \param j the second coordinate of the element. By default it's the column
     * \param t the new value of the element
     * \return a reference to the newly changed element
     */
    BOOST_UBLAS_INLINE
    reference insert_element (size_type i, size_type j, const_reference t) {
        return (at_element (i, j) = t);
    }
    
    /** Erase the element
     * For most types (int, double, etc...) it means setting 0 (zero) the element at zero in fact.
     * For user-defined types, it could be another value if you decided it. Your type in that case must
     * contain a default null value.
     * \param i the first coordinate of the element. By default it's the row
     * \param j the second coordinate of the element. By default it's the column
     */
    void erase_element (size_type i, size_type j) {
        at_element (i, j) = value_type/*zero*/();
    }
    
    // Zeroing
    /** Erase all elements in the matrix
     * For most types (int, double, etc...) it means writing 0 (zero) everywhere.
     * For user-defined types, it could be another value if you decided it. Your type in that case must
     * contain a default null value.
     */
    BOOST_UBLAS_INLINE
    void clear () {
        std::fill (data ().begin (), data ().end (), value_type/*zero*/());
    }
    
    // Swapping
    BOOST_UBLAS_INLINE
    void swap (static_matrix& m) {
        if(this != &m) {
            std::swap (size1_, m.size1_); //static_matrix!
            std::swap (size2_, m.size2_);
            data ().swap (m.data ());
        }
    }
    BOOST_UBLAS_INLINE
    friend void swap (static_matrix& m1, static_matrix& m2) {
        m1.swap (m2);
    }
    
    // Iterator types
private:
    // Use the storage array iterator
    typedef typename A::const_iterator const_subiterator_type;
    typedef typename A::iterator subiterator_type;
    
public:
#ifdef BOOST_UBLAS_USE_INDEXED_ITERATOR
    typedef indexed_iterator1<self_type, dense_random_access_iterator_tag> iterator1;
    typedef indexed_iterator2<self_type, dense_random_access_iterator_tag> iterator2;
    typedef indexed_const_iterator1<self_type, dense_random_access_iterator_tag> const_iterator1;
    typedef indexed_const_iterator2<self_type, dense_random_access_iterator_tag> const_iterator2;
#else
    class const_iterator1;
    class iterator1;
    class const_iterator2;
    class iterator2;
#endif
    typedef reverse_iterator_base1<const_iterator1> const_reverse_iterator1;
    typedef reverse_iterator_base1<iterator1> reverse_iterator1;
    typedef reverse_iterator_base2<const_iterator2> const_reverse_iterator2;
    typedef reverse_iterator_base2<iterator2> reverse_iterator2;
    
    // Element lookup
    BOOST_UBLAS_INLINE
    const_iterator1 find1 (int /* rank */, size_type i, size_type j) const {
#ifdef BOOST_UBLAS_USE_INDEXED_ITERATOR
        return const_iterator1 (*this, i, j);
#else
        return const_iterator1 (*this, data ().begin () + layout_type::address (i, size1_, j, size2_));
#endif
    }
    BOOST_UBLAS_INLINE
    iterator1 find1 (int /* rank */, size_type i, size_type j) {
#ifdef BOOST_UBLAS_USE_INDEXED_ITERATOR
        return iterator1 (*this, i, j);
#else
        return iterator1 (*this, data ().begin () + layout_type::address (i, size1_, j, size2_));
#endif
    }
    BOOST_UBLAS_INLINE
    const_iterator2 find2 (int /* rank */, size_type i, size_type j) const {
#ifdef BOOST_UBLAS_USE_INDEXED_ITERATOR
        return const_iterator2 (*this, i, j);
#else
        return const_iterator2 (*this, data ().begin () + layout_type::address (i, size1_, j, size2_));
#endif
    }
    BOOST_UBLAS_INLINE
    iterator2 find2 (int /* rank */, size_type i, size_type j) {
#ifdef BOOST_UBLAS_USE_INDEXED_ITERATOR
        return iterator2 (*this, i, j);
#else
        return iterator2 (*this, data ().begin () + layout_type::address (i, size1_, j, size2_));
#endif
    }
    
    
#ifndef BOOST_UBLAS_USE_INDEXED_ITERATOR
    class const_iterator1:
    public container_const_reference<static_matrix>,
    public random_access_iterator_base<dense_random_access_iterator_tag,
    const_iterator1, value_type> {
    public:
        typedef typename static_matrix::value_type value_type;
        typedef typename static_matrix::difference_type difference_type;
        typedef typename static_matrix::const_reference reference;
        typedef const typename static_matrix::pointer pointer;
        
        typedef const_iterator2 dual_iterator_type;
        typedef const_reverse_iterator2 dual_reverse_iterator_type;
        
        // Construction and destruction
        BOOST_UBLAS_INLINE
        const_iterator1 ():
        container_const_reference<self_type> (), it_ () {}
        BOOST_UBLAS_INLINE
        const_iterator1 (const self_type &m, const const_subiterator_type &it):
        container_const_reference<self_type> (m), it_ (it) {}
        BOOST_UBLAS_INLINE
        const_iterator1 (const iterator1 &it):
        container_const_reference<self_type> (it ()), it_ (it.it_) {}
        
        // Arithmetic
        BOOST_UBLAS_INLINE
        const_iterator1 &operator ++ () {
            layout_type::increment_i (it_, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        const_iterator1 &operator -- () {
            layout_type::decrement_i (it_, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        const_iterator1 &operator += (difference_type n) {
            layout_type::increment_i (it_, n, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        const_iterator1 &operator -= (difference_type n) {
            layout_type::decrement_i (it_, n, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        difference_type operator - (const const_iterator1 &it) const {
            BOOST_UBLAS_CHECK (&(*this) () == &it (), external_logic ());
            return layout_type::distance_i (it_ - it.it_, (*this) ().size1 (), (*this) ().size2 ());
        }
        
        // Dereference
        BOOST_UBLAS_INLINE
        const_reference operator * () const {
            BOOST_UBLAS_CHECK (index1 () < (*this) ().size1 (), bad_index ());
            BOOST_UBLAS_CHECK (index2 () < (*this) ().size2 (), bad_index ());
            return *it_;
        }
        BOOST_UBLAS_INLINE
        const_reference operator [] (difference_type n) const {
            return *(*this + n);
        }
        
#ifndef BOOST_UBLAS_NO_NESTED_CLASS_RELATION
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        const_iterator2 begin () const {
            const self_type &m = (*this) ();
            return m.find2 (1, index1 (), 0);
        }
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        const_iterator2 end () const {
            const self_type &m = (*this) ();
            return m.find2 (1, index1 (), m.size2 ());
        }
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        const_reverse_iterator2 rbegin () const {
            return const_reverse_iterator2 (end ());
        }
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        const_reverse_iterator2 rend () const {
            return const_reverse_iterator2 (begin ());
        }
#endif
        
        // Indices
        BOOST_UBLAS_INLINE
        size_type index1 () const {
            const self_type &m = (*this) ();
            return layout_type::index_i (it_ - m.begin1 ().it_, m.size1 (), m.size2 ());
        }
        BOOST_UBLAS_INLINE
        size_type index2 () const {
            const self_type &m = (*this) ();
            return layout_type::index_j (it_ - m.begin1 ().it_, m.size1 (), m.size2 ());
        }
        
        // Assignment
        BOOST_UBLAS_INLINE
        const_iterator1 &operator = (const const_iterator1 &it) {
            container_const_reference<self_type>::assign (&it ());
            it_ = it.it_;
            return *this;
        }
        
        // Comparison
        BOOST_UBLAS_INLINE
        bool operator == (const const_iterator1 &it) const {
            BOOST_UBLAS_CHECK (&(*this) () == &it (), external_logic ());
            return it_ == it.it_;
        }
        BOOST_UBLAS_INLINE
        bool operator < (const const_iterator1 &it) const {
            BOOST_UBLAS_CHECK (&(*this) () == &it (), external_logic ());
            return it_ < it.it_;
        }
        
    private:
        const_subiterator_type it_;
        
        friend class iterator1;
    };
#endif
    
    BOOST_UBLAS_INLINE
    const_iterator1 begin1 () const {
        return find1 (0, 0, 0);
    }
    BOOST_UBLAS_INLINE
    const_iterator1 end1 () const {
        return find1 (0, size1_, 0);
    }
    
#ifndef BOOST_UBLAS_USE_INDEXED_ITERATOR
    class iterator1:
    public container_reference<static_matrix>,
    public random_access_iterator_base<dense_random_access_iterator_tag,
    iterator1, value_type> {
    public:
        typedef typename static_matrix::value_type value_type;
        typedef typename static_matrix::difference_type difference_type;
        typedef typename static_matrix::reference reference;
        typedef typename static_matrix::pointer pointer;
        
        typedef iterator2 dual_iterator_type;
        typedef reverse_iterator2 dual_reverse_iterator_type;
        
        // Construction and destruction
        BOOST_UBLAS_INLINE
        iterator1 ():
        container_reference<self_type> (), it_ () {}
        BOOST_UBLAS_INLINE
        iterator1 (self_type &m, const subiterator_type &it):
        container_reference<self_type> (m), it_ (it) {}
        
        // Arithmetic
        BOOST_UBLAS_INLINE
        iterator1 &operator ++ () {
            layout_type::increment_i (it_, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        iterator1 &operator -- () {
            layout_type::decrement_i (it_, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        iterator1 &operator += (difference_type n) {
            layout_type::increment_i (it_, n, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        iterator1 &operator -= (difference_type n) {
            layout_type::decrement_i (it_, n, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        difference_type operator - (const iterator1 &it) const {
            BOOST_UBLAS_CHECK (&(*this) () == &it (), external_logic ());
            return layout_type::distance_i (it_ - it.it_, (*this) ().size1 (), (*this) ().size2 ());
        }
        
        // Dereference
        BOOST_UBLAS_INLINE
        reference operator * () const {
            BOOST_UBLAS_CHECK (index1 () < (*this) ().size1 (), bad_index ());
            BOOST_UBLAS_CHECK (index2 () < (*this) ().size2 (), bad_index ());
            return *it_;
        }
        BOOST_UBLAS_INLINE
        reference operator [] (difference_type n) const {
            return *(*this + n);
        }
        
#ifndef BOOST_UBLAS_NO_NESTED_CLASS_RELATION
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        iterator2 begin () const {
            self_type &m = (*this) ();
            return m.find2 (1, index1 (), 0);
        }
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        iterator2 end () const {
            self_type &m = (*this) ();
            return m.find2 (1, index1 (), m.size2 ());
        }
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        reverse_iterator2 rbegin () const {
            return reverse_iterator2 (end ());
        }
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        reverse_iterator2 rend () const {
            return reverse_iterator2 (begin ());
        }
#endif
        
        // Indices
        BOOST_UBLAS_INLINE
        size_type index1 () const {
            self_type &m = (*this) ();
            return layout_type::index_i (it_ - m.begin1 ().it_, m.size1 (), m.size2 ());
        }
        BOOST_UBLAS_INLINE
        size_type index2 () const {
            self_type &m = (*this) ();
            return layout_type::index_j (it_ - m.begin1 ().it_, m.size1 (), m.size2 ());
        }
        
        // Assignment
        BOOST_UBLAS_INLINE
        iterator1 &operator = (const iterator1 &it) {
            container_reference<self_type>::assign (&it ());
            it_ = it.it_;
            return *this;
        }
        
        // Comparison
        BOOST_UBLAS_INLINE
        bool operator == (const iterator1 &it) const {
            BOOST_UBLAS_CHECK (&(*this) () == &it (), external_logic ());
            return it_ == it.it_;
        }
        BOOST_UBLAS_INLINE
        bool operator < (const iterator1 &it) const {
            BOOST_UBLAS_CHECK (&(*this) () == &it (), external_logic ());
            return it_ < it.it_;
        }
        
    private:
        subiterator_type it_;
        
        friend class const_iterator1;
    };
#endif
    
    BOOST_UBLAS_INLINE
    iterator1 begin1 () {
        return find1 (0, 0, 0);
    }
    BOOST_UBLAS_INLINE
    iterator1 end1 () {
        return find1 (0, size1_, 0);
    }
    
#ifndef BOOST_UBLAS_USE_INDEXED_ITERATOR
    class const_iterator2:
    public container_const_reference<static_matrix>,
    public random_access_iterator_base<dense_random_access_iterator_tag,
    const_iterator2, value_type> {
    public:
        typedef typename static_matrix::value_type value_type;
        typedef typename static_matrix::difference_type difference_type;
        typedef typename static_matrix::const_reference reference;
        typedef const typename static_matrix::pointer pointer;
        
        typedef const_iterator1 dual_iterator_type;
        typedef const_reverse_iterator1 dual_reverse_iterator_type;
        
        // Construction and destruction
        BOOST_UBLAS_INLINE
        const_iterator2 ():
        container_const_reference<self_type> (), it_ () {}
        BOOST_UBLAS_INLINE
        const_iterator2 (const self_type &m, const const_subiterator_type &it):
        container_const_reference<self_type> (m), it_ (it) {}
        BOOST_UBLAS_INLINE
        const_iterator2 (const iterator2 &it):
        container_const_reference<self_type> (it ()), it_ (it.it_) {}
        
        // Arithmetic
        BOOST_UBLAS_INLINE
        const_iterator2 &operator ++ () {
            layout_type::increment_j (it_, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        const_iterator2 &operator -- () {
            layout_type::decrement_j (it_, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        const_iterator2 &operator += (difference_type n) {
            layout_type::increment_j (it_, n, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        const_iterator2 &operator -= (difference_type n) {
            layout_type::decrement_j (it_, n, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        difference_type operator - (const const_iterator2 &it) const {
            BOOST_UBLAS_CHECK (&(*this) () == &it (), external_logic ());
            return layout_type::distance_j (it_ - it.it_, (*this) ().size1 (), (*this) ().size2 ());
        }
        
        // Dereference
        BOOST_UBLAS_INLINE
        const_reference operator * () const {
            BOOST_UBLAS_CHECK (index1 () < (*this) ().size1 (), bad_index ());
            BOOST_UBLAS_CHECK (index2 () < (*this) ().size2 (), bad_index ());
            return *it_;
        }
        BOOST_UBLAS_INLINE
        const_reference operator [] (difference_type n) const {
            return *(*this + n);
        }
        
#ifndef BOOST_UBLAS_NO_NESTED_CLASS_RELATION
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        const_iterator1 begin () const {
            const self_type &m = (*this) ();
            return m.find1 (1, 0, index2 ());
        }
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        const_iterator1 end () const {
            const self_type &m = (*this) ();
            return m.find1 (1, m.size1 (), index2 ());
        }
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        const_reverse_iterator1 rbegin () const {
            return const_reverse_iterator1 (end ());
        }
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        const_reverse_iterator1 rend () const {
            return const_reverse_iterator1 (begin ());
        }
#endif
        
        // Indices
        BOOST_UBLAS_INLINE
        size_type index1 () const {
            const self_type &m = (*this) ();
            return layout_type::index_i (it_ - m.begin2 ().it_, m.size1 (), m.size2 ());
        }
        BOOST_UBLAS_INLINE
        size_type index2 () const {
            const self_type &m = (*this) ();
            return layout_type::index_j (it_ - m.begin2 ().it_, m.size1 (), m.size2 ());
        }
        
        // Assignment
        BOOST_UBLAS_INLINE
        const_iterator2 &operator = (const const_iterator2 &it) {
            container_const_reference<self_type>::assign (&it ());
            it_ = it.it_;
            return *this;
        }
        
        // Comparison
        BOOST_UBLAS_INLINE
        bool operator == (const const_iterator2 &it) const {
            BOOST_UBLAS_CHECK (&(*this) () == &it (), external_logic ());
            return it_ == it.it_;
        }
        BOOST_UBLAS_INLINE
        bool operator < (const const_iterator2 &it) const {
            BOOST_UBLAS_CHECK (&(*this) () == &it (), external_logic ());
            return it_ < it.it_;
        }
        
    private:
        const_subiterator_type it_;
        
        friend class iterator2;
    };
#endif
    
    BOOST_UBLAS_INLINE
    const_iterator2 begin2 () const {
        return find2 (0, 0, 0);
    }
    BOOST_UBLAS_INLINE
    const_iterator2 end2 () const {
        return find2 (0, 0, size2_);
    }
    
#ifndef BOOST_UBLAS_USE_INDEXED_ITERATOR
    class iterator2:
    public container_reference<static_matrix>,
    public random_access_iterator_base<dense_random_access_iterator_tag,
    iterator2, value_type> {
    public:
        typedef typename static_matrix::value_type value_type;
        typedef typename static_matrix::difference_type difference_type;
        typedef typename static_matrix::reference reference;
        typedef typename static_matrix::pointer pointer;
        
        typedef iterator1 dual_iterator_type;
        typedef reverse_iterator1 dual_reverse_iterator_type;
        
        // Construction and destruction
        BOOST_UBLAS_INLINE
        iterator2 ():
        container_reference<self_type> (), it_ () {}
        BOOST_UBLAS_INLINE
        iterator2 (self_type &m, const subiterator_type &it):
        container_reference<self_type> (m), it_ (it) {}
        
        // Arithmetic
        BOOST_UBLAS_INLINE
        iterator2 &operator ++ () {
            layout_type::increment_j (it_, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        iterator2 &operator -- () {
            layout_type::decrement_j (it_, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        iterator2 &operator += (difference_type n) {
            layout_type::increment_j (it_, n, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        iterator2 &operator -= (difference_type n) {
            layout_type::decrement_j (it_, n, (*this) ().size1 (), (*this) ().size2 ());
            return *this;
        }
        BOOST_UBLAS_INLINE
        difference_type operator - (const iterator2 &it) const {
            BOOST_UBLAS_CHECK (&(*this) () == &it (), external_logic ());
            return layout_type::distance_j (it_ - it.it_, (*this) ().size1 (), (*this) ().size2 ());
        }
        
        // Dereference
        BOOST_UBLAS_INLINE
        reference operator * () const {
            BOOST_UBLAS_CHECK (index1 () < (*this) ().size1 (), bad_index ());
            BOOST_UBLAS_CHECK (index2 () < (*this) ().size2 (), bad_index ());
            return *it_;
        }
        BOOST_UBLAS_INLINE
        reference operator [] (difference_type n) const {
            return *(*this + n);
        }
        
#ifndef BOOST_UBLAS_NO_NESTED_CLASS_RELATION
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        iterator1 begin () const {
            self_type &m = (*this) ();
            return m.find1 (1, 0, index2 ());
        }
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        iterator1 end () const {
            self_type &m = (*this) ();
            return m.find1 (1, m.size1 (), index2 ());
        }
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        reverse_iterator1 rbegin () const {
            return reverse_iterator1 (end ());
        }
        BOOST_UBLAS_INLINE
#ifdef BOOST_UBLAS_MSVC_NESTED_CLASS_RELATION
        typename self_type::
#endif
        reverse_iterator1 rend () const {
            return reverse_iterator1 (begin ());
        }
#endif
        
        // Indices
        BOOST_UBLAS_INLINE
        size_type index1 () const {
            self_type &m = (*this) ();
            return layout_type::index_i (it_ - m.begin2 ().it_, m.size1 (), m.size2 ());
        }
        BOOST_UBLAS_INLINE
        size_type index2 () const {
            self_type &m = (*this) ();
            return layout_type::index_j (it_ - m.begin2 ().it_, m.size1 (), m.size2 ());
        }
        
        // Assignment
        BOOST_UBLAS_INLINE
        iterator2 &operator = (const iterator2 &it) {
            container_reference<self_type>::assign (&it ());
            it_ = it.it_;
            return *this;
        }
        
        // Comparison
        BOOST_UBLAS_INLINE
        bool operator == (const iterator2 &it) const {
            BOOST_UBLAS_CHECK (&(*this) () == &it (), external_logic ());
            return it_ == it.it_;
        }
        BOOST_UBLAS_INLINE
        bool operator < (const iterator2 &it) const {
            BOOST_UBLAS_CHECK (&(*this) () == &it (), external_logic ());
            return it_ < it.it_;
        }
        
    private:
        subiterator_type it_;
        
        friend class const_iterator2;
    };
#endif
    
    BOOST_UBLAS_INLINE
    iterator2 begin2 () {
        return find2 (0, 0, 0);
    }
    BOOST_UBLAS_INLINE
    iterator2 end2 () {
        return find2 (0, 0, size2_);
    }
    
    // Reverse iterators
    
    BOOST_UBLAS_INLINE
    const_reverse_iterator1 rbegin1 () const {
        return const_reverse_iterator1 (end1 ());
    }
    BOOST_UBLAS_INLINE
    const_reverse_iterator1 rend1 () const {
        return const_reverse_iterator1 (begin1 ());
    }
    
    BOOST_UBLAS_INLINE
    reverse_iterator1 rbegin1 () {
        return reverse_iterator1 (end1 ());
    }
    BOOST_UBLAS_INLINE
    reverse_iterator1 rend1 () {
        return reverse_iterator1 (begin1 ());
    }
    
    BOOST_UBLAS_INLINE
    const_reverse_iterator2 rbegin2 () const {
        return const_reverse_iterator2 (end2 ());
    }
    BOOST_UBLAS_INLINE
    const_reverse_iterator2 rend2 () const {
        return const_reverse_iterator2 (begin2 ());
    }
    
    BOOST_UBLAS_INLINE
    reverse_iterator2 rbegin2 () {
        return reverse_iterator2 (end2 ());
    }
    BOOST_UBLAS_INLINE
    reverse_iterator2 rend2 () {
        return reverse_iterator2 (begin2 ());
    }
    
private:
    size_type size1_;
    size_type size2_;
    array_type data_;
};

template <class T, std::size_t M>
using static_vector = static_matrix<T, M, 1>;

template<class T, class L, class A>
using dynamic_matrix = matrix<T, L>;

#endif