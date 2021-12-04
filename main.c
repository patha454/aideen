#include <stdio.h>
#include "aideen.h"

void main(void) {
    AdInstance instance;
    AdVersion version = makeAdVersion(15, 0x8f, 255);
    printf("Aideen version %d.%d.%d\n", AdGetMajorVersion(version), AdGetMinorVersion(version), AdGetPatchVersion(version));
}
