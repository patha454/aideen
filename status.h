/**
 * \file status.h
 *
 * `status.h` declares status codes used by Aideen.
 *
 * \author H Paterson, 2021.
 * \copyright BSL-1.0.
 */

/**
 * \typedef AdStatus
 *
 * `AdStatus` represents the success (or cause of failure)
 * for an Aideen operation.
 */
typedef enum AdStatus {
    /** Completed normally. */
    AD_SUCCESS = 0,

    /** Unexpected error. */
    AD_PANIC = 1,

    AD_OUT_OF_MEMORY = 2,
} AdStatus;