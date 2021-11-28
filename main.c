#include <stdio.h>
#include "cblas/cblas.h"
#include "matrix.h"

double stateData[] = {1, 2, 3, 3, 1, 4, 0};
double targeData[] = {4, 4, 4, 4, 4, 4, 0};

void main(void) {
    AdMatrix state;
    AdMatrix target;
    printf("%d\n", AdMatrixAlloc(&state, 7, 1, stateData));
    printf("%d\n", AdMatrixAlloc(&target, 7, 1, targeData));
    printf("Dot: %g\n", AdDotProduct(state, target));
}
