//
// Copyright (c) 2013
// Nasos Iliopoulos, Sathyam M Vellal
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1.0.txt or copy at
// http://www.boost.org/LICENSE_1.0.txt)
//
// The authors gratefully acknowledges the support of
// David Bellot and Nasos Iliopoulos in producing this work
//

#include <boost/numeric/ublas/operation.hpp>

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

	namespace fast_matrix_multiplication {
		
		/** \brief Fill matrix with value
		 *
		 * A helper function for fast matrix multiplication.
		 * Fills the given matrix with a given value
		 *
		 * \param M Matrix to be filled 
		 * \param val value to be filled in the matrix
		 */
		template <typename MatrixType>
		void fill (MatrixType &M, const typename MatrixType::value_type val)
		{
			typedef typename MatrixType::size_type size_type;

			for (size_type i = 0; i < M.size1 (); ++ i) {
				for (size_type j = 0; j < M.size2 (); ++j) {
					M(i, j) = val + 0;
				}
			}
		}

		/** \brief Pack a matrix into another
		 *
		 * A helper function for fast matrix multiplication.
		 * Packs a part of the matrix of 'y' (a submatrix) of 'size1' rows and 'size2' columns
		 * starting from row i0 and column j0 into the matrix 'x'.
		 * The matrix 'x' is required to have at least size1 rows and size2 columns.
		 *
		 * \param x Matrix to which packing is done.
		 * \param y Matrix whose submatrix is packed.
		 */
		template <typename MatrixType1, typename MatrixType2>
		void pack (MatrixType1& x,
			const MatrixType2& y,
			typename MatrixType1::size_type i0,
			typename MatrixType1::size_type j0,
			typename MatrixType1::size_type size1, 
			typename MatrixType1::size_type size2)
		{
			typedef typename MatrixType1::size_type size_type;
			size_type m, n, i, j;

			for (m = 0, i = i0; m < size1; ++ m, ++ i) {
				for (n = 0, j = j0; n < size2; ++ n, ++ j) {
					x(m, n) = y(i, j) + 0;
				}
			}
		}

		/** \brief Unpack a matrix add corresponding elements to another matrix
		 *
		 * A helper function for fast matrix multiplication.
		 * Unpacks the matrix 'y' of 'size1' rows and 'size2' columns onto 'x' 
		 * from row 'i0' and column 'j0' of 'x'.
		 * The matrix 'x' is required to have at least 'i0+size1' rows and 'j0+size2' columns
		 *
		 * \param x Matrix onto which unpacking is done.
		 * \param y Matrix which is unpacked.
		 */
		template <typename MatrixType1, typename MatrixType2>
		void unpack_add (MatrixType1& x,
			const MatrixType2& y,
			typename MatrixType1::size_type i0,
			typename MatrixType1::size_type j0,
			typename MatrixType1::size_type size1, 
			typename MatrixType1::size_type size2)
		{
			typedef typename MatrixType1::size_type size_type;
			size_type m, n, i, j;

			for (i = i0, m = 0; m < size1; ++ i, ++ m) {
				for (j = j0, n = 0; n < size2; ++ j, ++ n) {
					x(i, j) += y(m, n);
				}
			}
		}
#if 0
		template <typename MatrixType1, typename MatrixType2, typename MatrixType3>
		void multiply (MatrixType3 &C, const MatrixType2 &A, const MatrixType1 &B)
		{
			typedef typename MatrixType1::size_type size_type;
			size_type i, j, k;

			TIMEPOINT(t1);
			for (k = 0; k < CSIZE; ++ k) {
				for (i = 0; i < CSIZE; ++ i) {
					for (j = 0; j < CSIZE; ++ j) {
						C(i, j) += A(i, k) * B(k, j);
					}
				}
			}
			DURATION(t1);
		}
#endif
	}

	//TODO: a better condition for using fast matrix-matrix multiplication
	/** \brief A fast matrix multiplication implementation
	 *
	 * The core implementation of the fast matrix-matrix multiplication.
	 * Assumption: The matrices A and B can be multiplied 
	 *             (meaning the columns of A is equal to the rows of B) 
	 * 
	 * \param C Matrix of size MxN (result matrix)
	 * \param A Matrix of size MxK (first matrix)
	 * \param B Matrix of size KxN (second matrix)
	 */
	template <typename MatrixType1, typename MatrixType2, typename MatrixType3>
	void fast_matrix_multiply (MatrixType3 &C, const MatrixType2 &A, const MatrixType1 &B, bool init = true)
	{
		namespace ublas = boost::numeric::ublas;
		typedef typename MatrixType1::size_type size_type;
		typedef typename MatrixType1::value_type value_type;
		const value_type zero = value_type (); // store zero value (used frequently later)
		const std::size_t Alignment = 16; // Alignment of 16 bytes required to have vectorization when compiled

		if (init) {
			fast_matrix_multiplication::fill (C, zero); // Clear the result matrix
		}
		const size_type Z = C.size1 (); // Number of columns of A (aka K)
		const size_type Y = C.size2 (); // Number of rows of C (aka M)
		const size_type X = A.size2 (); // Number of columns of C (aka N)

		// Condition to use to fast matrix-matrix multiplication
		if (X >= 256 || Y >= 256 || Z >= 256) {

			const std::size_t M = 64;
			const std::size_t N = 256;
			const std::size_t K = 64;

			const std::size_t ZModK = Z % K; // Required later to use only part of the packed matrix 
			const std::size_t YModN = Y % N; // 	when the size of the packed block is less than
			const std::size_t XModM = X % M; // 	the size of the packed matrix

			// c_matrix_aligned - An c-array implementation of a matrix 
			// 	which also guarantees alignment of the c-array within.
			ublas::c_matrix_aligned<value_type, M, K, Alignment> Al;
			ublas::c_matrix_aligned<value_type, K, N, Alignment> Bl;
			// ublas::c_matrix_aligned<value_type, M, N, Alignment> Cl;

			// Loop variables
			size_type i, j, k, ii, jj, kk, MM = M, NN = N, KK = K;

			// using OpenMP
#pragma omp parallel private(i, j, k, ii, jj, kk) shared(A, B, C, Al, Bl)
			{
			#pragma omp for
			for (k = 0; k < Z; k += K) {
				KK = (k + K) > Z ? ZModK : K; // number of columns of A or rows of B of the block to be packed
				for (i = 0; i < X; i += M) {
					MM = (i + M) > X ? XModM : M; // number of rows A of the block to be packed
					fast_matrix_multiplication::pack (Al, A, k, i, KK, MM); // pack a block of A into Al
					for (j = 0; j < Y; j += N) {
						NN = (j + N) > Y ? YModN : N; // number of columns of B of the block to be packed
						fast_matrix_multiplication::pack (Bl, B, i, j, MM, NN); // pack a block of B into Bl
						ublas::c_matrix_aligned<value_type, K, N, Alignment> Cl;
						// Multiply the packed matrices
						for (kk = 0; kk < KK; ++ kk) {
							for (ii = 0; ii < MM; ++ ii) {
								for (jj = 0; jj < NN; ++ jj) {
									Cl(kk, jj) += Al(kk, ii) * Bl(ii, jj);
								}
							}
						}
						// unpack the result matrix Cl, and add to C
						fast_matrix_multiplication::unpack_add(C, Cl, k, j, KK, NN);
					}
				}
			}
			}
		} else {
			// Matrix size small to apply the , a normal multiplication is sufficient
			prod(A, B, C);
		}
	}	

}}}
