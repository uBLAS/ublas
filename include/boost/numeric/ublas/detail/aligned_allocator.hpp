//
// Copyright (c) 2013
// Sathyam M Vellal
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1.0.txt or copy at
// http://www.boost.org/LICENSE_1.0.txt)
//
// The author gratefully acknowledges the support of
// David Bellot and Nasos Iliopoulos in producing this work
//

#ifndef ALIGNED_ALLOCATOR_H
#define ALIGNED_ALLOCATOR_H

#include <boost/numeric/ublas/traits.hpp>

namespace boost { namespace numeric { 
	
	/** \brief main namespace of uBLAS.
     *
     * Use this namespace for all operations with uBLAS. It can also be abbreviated with
     * \code namespace ublas = boost::numeric::ublas; \endcode
     *
     * A common practice is to bring this namespace into the current scope with
     * \code using namespace boost::numeric::ublas; \endcode.
	 */
	namespace ublas {

	// TEMPORARY ONLY - Till std::align is implemented by compilers
	void *align (std::size_t alignment, std::size_t size, void*& ptr, std::size_t& space) {
        std::size_t pointer = reinterpret_cast<std::size_t> (ptr); // Make sure that it is size_t
        std::size_t aligned = (pointer + alignment - 1)& - alignment; // move to to an aligned location
        std::size_t aligned_space = space - (aligned - pointer); // Find the new space
        if (aligned_space < size) {
        	return nullptr; // If we don't have enough space we can't align
        }
        space = aligned_space; // Everything is good; return the pointer and store the new space.
        ptr = reinterpret_cast<void*> (aligned);
        return ptr;
	}

	/** \brief An Aligned Allocator with specified alignment.
	 *
	 * This allocator guarantees memory allocation of blocks aligned to 
	 * specified byte boundaries, conforming to the standard allocator interface. 
	 * The specified alignment is a power of 2.
	 *
	 * \tparam T the type of the object used by the allocator for memory allocation
	 * \tparam Alignment the required alignment specification (in bytes)
	 */
	template <typename T, std::size_t Alignment>
	class aligned_allocator {
	public:
		typedef T value_type;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;

	public:

		/** \brief Default Constructor
		 *
		 * Empty for a stateless allocator 
		 */
		BOOST_UBLAS_INLINE
		aligned_allocator () {}

		/** \brief Copy Constructor
		 *
		 * Empty for a stateless allocator 
		 */
		BOOST_UBLAS_INLINE
		aligned_allocator (const aligned_allocator& a) {}

		//TODO: Replace align with std::align 
		/** \brief Allocate memory
		 *
		 * Part of the standard allocator interface.
		 * Allocate memory sufficient to hold 'n' objects of type T.
		 * Further this allocation function guarantees memory allocation with alignment at Alignment-byte boundary
		 * 
		 * \param n number of objects of type T to allocate memory for
		 * \param hint ignored
		 * \return pointer of an aligned memory location
		 */
		BOOST_UBLAS_INLINE
		pointer allocate (size_type n, const_pointer hint = 0) {

			const size_type value_size = sizeof (T); // size of the value_type 
			const size_type diff_type_size = sizeof (difference_type); // size of the difference type; needed later
			const size_type block_size = n * value_size + Alignment; // minimum size required to guarantee alignment
			const size_type alloc_size = diff_type_size + block_size; // size to be allocated
			size_type space = block_size; // required by std::align

			void* ptr_full_block = ::operator new (alloc_size); // allocate alloc_size amount of memory 
			void* ptr_block = reinterpret_cast<void*> 
				(reinterpret_cast<size_type> (ptr_full_block) + diff_type_size); // skip difference type size units of memory (needed to store offset)
			void* ptr_aligned_block = align (Alignment, n * sizeof (value_type), ptr_block, space); // now perform alignment with the rest

			difference_type* ptr_diff = reinterpret_cast<difference_type*> 
				(reinterpret_cast<size_type> (ptr_aligned_block) - sizeof (difference_type));
			*ptr_diff = static_cast<difference_type> (block_size - space); // store offset before the start of the aligned_block

			return static_cast<pointer> (ptr_aligned_block);
		}

		/** \brief Deallocate memory
		 *
		 * Part of the standard allocator interface.
		 * Deallocate a block of memory previously allocated by aligned_allocator::allocate() function.
		 * Note: Do not try to deallocate pointers other than those allocated by aligned_allocator::allocate(). The behaviour is undefined otherwise.
		 *
		 * \param ptr_aligned_block pointer to the aligned memory block which needs to be deallocated
		 * \param size_type n ignored
		 */
		BOOST_UBLAS_INLINE
		void deallocate (pointer ptr_aligned_block, size_type n) {
			const size_type diff_type_size = sizeof (difference_type);
			void* ptr_block = reinterpret_cast<void*> 
				(reinterpret_cast<size_type> (ptr_aligned_block) - diff_type_size); // trace back to retrieve offset
			difference_type offset = *(reinterpret_cast<difference_type*> (ptr_block)); // get the offset of type difference_type
			::operator delete (reinterpret_cast<void*> 
				(reinterpret_cast<difference_type> (ptr_block) - offset)); // move back offset bytes and delete from there
		}

		/** \brief Determine maximum size that can be allocated
		 *
		 * Part of the standard allocator interface.
		 * Determine the maximum number of objects that can be allocated
		 * \return The maximum size or the number of objects that can be allocated. 
		 */
		BOOST_UBLAS_INLINE 
		size_type max_size () {
			return static_cast<size_type> (-1) / sizeof (T);
		}

		/** brief Determine address of object
		 *
		 * Part of the standard allocator interface. 
		 * Determine the address given the reference to an object
		 *
		 * \param r reference to the object whose address needs to be determined
		 * \return pointer to the location containing the object
		 */
		BOOST_UBLAS_INLINE
		pointer address (reference r) {
			return &r;
		}

		/** \brief Construct object of type T
		 *
		 * Part of the standard allocator interface. 
		 * This function constructs an object of type T at a given location 'p'.
		 * Uses placement new mechanism and constructs the object's properties from the reference r
		 *
		 * \param p pointer to the location where the new object needs to be constructed
		 * \param r reference to an object from which the new object will be constructed from
		 */
		BOOST_UBLAS_INLINE
		void construct (pointer p, reference r) {
			new (p) value_type (r);
		}

		/** \brief Destructor for an object of type T
		 *
		 * Part of the standard allocator interface. 
		 * Destroys the object pointed to by a pointer given as its argument.
		 * Directly calls the destructor
		 *
		 * \param p pointer to the object which needs to destroyed.
		 */
		BOOST_UBLAS_INLINE
		void destroy (pointer p) {
			p->~value_type ();
		}
		
		/** \brief The rebind class
		 *
		 * Part of the standard allocator interface. 
		 * An inner class of the allocator to rebind a new allocator type from the current allocator
		 *
		 * \tparam U New type to rebind to
		 */
		template <typename U>
		class rebind {
		public:
			typedef aligned_allocator<U, Alignment> other;
		};

		/** \brief overloaded equality operator
		 *
		 * Part of the standard allocator interface. 
		 * Returns true always for stateless allocators
		 *
		 * \param a A reference to another aligned_allocator
		 * \return boolean value, indicating equality
		 */
		BOOST_UBLAS_INLINE
		bool operator == (const_reference a) {
			return true;
		}

		/** \brief overloaded inequality operator
		 *
		 * Part of the standard allocator interface. 
		 * Performs the opposite of operator == () 
		 *
		 * \param a A reference to another aligned_allocator
		 * \return boolean value, indicating inequality
		 */
		BOOST_UBLAS_INLINE
		bool operator != (const_reference a) {
			return ! operator == (a);
		}

	private:

		// Allocators are non-assignable
		BOOST_UBLAS_INLINE
		aligned_allocator<value_type, Alignment> &operator = (const_reference a) {}
	};

}}}

#endif
