#include "aideen.h"
#include <assert.h>

struct AdInstance {
    AdVersion version;
};

AdVersion makeAdVersion(uint16_t major, uint16_t minor, uint16_t patch) {
    AdVersion version = 0;
    version = ((AdVersion) major) << 32;
    version |= ((AdVersion) minor) << 16;
    version |= ((AdVersion) patch);
    return version;
}

uint16_t AdGetMajorVersion(AdVersion version) {
    return (version >> 32) & 0xffffu;
}

uint16_t AdGetMinorVersion(AdVersion version) {
    return (version >> 16) & 0xffffu;
}

uint16_t AdGetPatchVersion(AdVersion version) {
    return version & 0xffffu;
}