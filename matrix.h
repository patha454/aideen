/**
 * \file matrix.h
 *
 * `matrix.h` declares the interface to Aideen's core
 * matrix representation.
 *
 * \author H Paterson, 2021.
 * \copyright BSL-1.0.
 */

#ifndef ADMATRIX_H_
#define ADMATRIX_H_

#include "status.h"

/** \typedef AdMatrixDimension Dimension of a matrix. */
typedef unsigned short AdMatrixDimension;

/**
 * \typedef AdMatrix is a handle to the core matrix type in Aideen.
 * 
 * Aideen matrices are hidden behind a handle to limit the risk of
 * potentially slow copies being performed accientally.
 */
typedef struct AdMatrix* AdMatrix;

/**
 * \brief Allocate and initalise a new matrix.
 *
 * Aideen copies the source matrix into the the `AdMatrix`, rather than storing
 * a pointer. Aideen can guarantee the consistency of the data by doing this
 * deep copy, ensuring the data is not being written to while Aideen uses it.
 *
 * \param result Location to store a handle to the new matrix.
 * \param x Rows in the new array.
 * \param y Columns in the new array.
 * \param data Row major numbers to copy into the matrix.
 */
AdStatus AdMatrixAlloc(AdMatrix* const result, AdMatrixDimension x, AdMatrixDimension y, const double* const data);

/**
 * \brief Deallocate an Aideen matrix.
 *
 * `AdMatrixFree` deallocates an Aideen matrix, and invalidates its internal
 * state (in case of dangling references to the matrix).
 *
 * \param result The matrix to free.
 */
void AdMatrixFree(AdMatrix const matrix);

/**
 * \brief Allocate and create a deep copy of an Aideen matrix.
 *
 * \param original The matrix to copy.
 * \param result Location to store a handle to the new copy.
 * \return `AD_SUCCESS` or an error code.
 */
AdStatus AdMatrixCopy(AdMatrix const original, AdMatrix* result);

/**
 * \brief Compute the dot product of two vectors.
 *
 * `AdDotProduct` computes the dot product d = A * Transpose(B).
 *
 * `AdDotProduct` only works on vectors - special cases of `AdMatrix`s with
 * exactly one row. Assertions will fail with matrixes that are not vectors.
 *
 * /return The dot product d = A * Transpose(B)
 */
double AdDotProduct(AdMatrix const a, AdMatrix const b);

#endif
