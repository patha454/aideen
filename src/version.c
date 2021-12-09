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

#include "src/version.h"

/**
 * \def MAJOR BITSHIFT
 *
 * Bit shift distance to store and retrieve the major version field
 * from an AdVersion.
 */
#define MAJOR_BITSHIFT (2 * sizeof(AdVersionField) * 8)

/**
 * \def MINOR_BITSHIFT
 *
 * Bit shift distance to store and retrieve the minor version field
 * from an AdVersion.
 */
#define MINOR_BITSHIFT (sizeof(AdVersionField) * 8)

extern AdVersion
makeAdVersion(AdVersionField major, AdVersionField minor, AdVersionField patch)
{
  AdVersion version = 0;
  version = ((AdVersion)major) << MAJOR_BITSHIFT;
  version |= ((AdVersion)minor) << MINOR_BITSHIFT;
  version |= ((AdVersion)patch);
  return version;
}

extern AdVersionField
AdGetMajorVersion(AdVersion version)
{
  return (version >> MAJOR_BITSHIFT) & 0xffffu;
}

extern AdVersionField
AdGetMinorVersion(AdVersion version)
{
  return (version >> MINOR_BITSHIFT) & 0xffffu;
}

extern AdVersionField
AdGetPatchVersion(AdVersion version)
{
  return version & 0xffffu;
}