/**
 * \file version.c
 *
 * Functions used to manipulation Aideen version information.
 *
 * \see Detailed documentation comments are available in version.h. 
 * 
 * \author H Paterson, 2021.
 * \copyright BSL-1.0.
 */

#include "version.h"

extern AdVersion makeAdVersion(AdVersionField major, AdVersionField minor, AdVersionField patch) {
    AdVersion version = 0;
    version = ((AdVersion) major) << 32;
    version |= ((AdVersion) minor) << 16;
    version |= ((AdVersion) patch);
    return version;
}

extern AdVersionField AdGetMajorVersion(AdVersion version) {
    return (version >> 32) & 0xffffu;
}

extern AdVersionField AdGetMinorVersion(AdVersion version) {
    return (version >> 16) & 0xffffu;
}

extern AdVersionField AdGetPatchVersion(AdVersion version) {
    return version & 0xffffu;
}