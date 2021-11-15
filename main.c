#include <stdio.h>
#include "cblas/cblas.h"

void main(void) {
    float vecA[] = {1, 2, 3};
    float vecB[] = {3, 1, 2};
    float dot = cblas_sdot(3, vecA, 1, vecB, 1);
    printf("Dot product: %f\n", dot);
}
