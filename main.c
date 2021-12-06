#include <stdio.h>
#include "version.h"

void main(void) {
    AdVersion version = AD_VERSION;
    printf("Aideen version %d.%d.%d\n", AdGetMajorVersion(version), AdGetMinorVersion(version), AdGetPatchVersion(version));
}
