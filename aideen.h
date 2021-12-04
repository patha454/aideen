/**
 * `aideen.h` defines the initial public API to Aideen.
 *
 * \author H Paterson.
 * \copyright BSL-1.0.
 */


#include <stdint.h>

/**
 * \typedef AdInstance
 *
 * `AdInstance` is a handle to an instance of Aideen. The `AdInstance` handle
 * is used to store all state for a physics system under consideration by
 * Aideen.
 *
 * Aideen instances are completely independent. A project can declear and use
 * as many Aideen instances as required at once.
 */
typedef struct AdInstance* AdInstance;

/**
 * \typedef AdVersion
 *
 * `AdVersion` identifies the version of an Aideen library build.
 */
typedef uint64_t AdVersion;

AdVersion makeAdVersion(uint16_t major, uint16_t minor, uint16_t patch);

uint16_t AdGetMajorVersion(AdVersion version);

uint16_t AdGetMinorVersion(AdVersion version);

uint16_t AdGetPatchVersion(AdVersion version);