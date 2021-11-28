/**
 * \file matrix.c
 *
 * `matrix.c` implements the core matrix representation
 * used by Aideen.
 *
 * \see matrix.h for detailed documentation comments.
 *
 * \author H Paterson, 2021.
 * \copyright BSL-1.0.
 */

#include "matrix.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "cblas/cblas.h"

struct AdMatrix {
    /** Rows in the matrix. */
    AdMatrixDimension xSize;

    /** Columns in the matrix. */
    AdMatrixDimension ySize;

    /** Row-major matrix data. */
    double* payload;
};

AdStatus
AdMatrixAlloc(AdMatrix* const result, AdMatrixDimension x, AdMatrixDimension y, const double* const data) {
    assert(result != NULL);
    assert(data != NULL);
    assert(x != 0);
    assert(y != 0);
    AdMatrix matrix = NULL;
    size_t payloadLength = x * y * sizeof(matrix->payload);
    matrix = malloc(sizeof *matrix);
    if (matrix == NULL) {
        AdMatrixFree(matrix);
        return AD_OUT_OF_MEMORY;
    }
    matrix->payload = malloc(payloadLength);
    if (matrix->payload == NULL) {
        AdMatrixFree(matrix);
        return AD_OUT_OF_MEMORY;
    }
    matrix->xSize = x;
    matrix->ySize = y;
    memcpy(matrix->payload, data, payloadLength);
    *result = matrix;
    return AD_SUCCESS;
}

void
AdMatrixFree(AdMatrix const matrix) {
    if (matrix && matrix->payload) {
        free(matrix->payload);
    }
    if (matrix) {
        matrix->xSize = 0;
        matrix->ySize = 0;
        matrix->payload = NULL;
        free(matrix);
    }
}

AdStatus
AdMatrixCopy(AdMatrix const original, AdMatrix* result) {
    assert(result != NULL);
    assert(original != NULL);
    AdMatrix copy = malloc(sizeof *copy);
    if (copy == NULL) {
        AdMatrixFree(copy);
        return AD_OUT_OF_MEMORY;
    }
    size_t payloadLength = original->xSize * original->ySize * sizeof(copy->payload);
    copy->payload = malloc(payloadLength);
    if (copy->payload == NULL) {
        AdMatrixFree(copy);
        return AD_OUT_OF_MEMORY;
    }
    copy->xSize = original->xSize;
    copy->ySize = original->ySize;
    memcpy(copy->payload, original->payload, payloadLength);
    *result = copy;
    return AD_SUCCESS;
}


double AdDotProduct(AdMatrix a, AdMatrix b) {
    assert(a != NULL);
    assert(b != NULL);
    assert(a->ySize == 1);
    assert(b->ySize == 1);
    assert(a->xSize == b->xSize);
    return cblas_ddot(a->xSize, a->payload, a->ySize, b->payload, b->ySize);
}

