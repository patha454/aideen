cmake_minimum_required(VERSION 3.21)
cmake_policy(VERSION 3.21)

set(AIDEEN_MAJOR_VERSION "0" CACHE STRING "Major version of this Aideen build.")
set(AIDEEN_MINOR_VERSION "0" CACHE STRING "Minor version of this Aideen build.")
set(AIDEEN_PATCH_VERSION "0" CACHE STRING "Patch version of this Aideen build.")
set(
    AIDEEN_VERSION
    "${AIDEEN_MAJOR_VERSION}.${AIDEEN_MINOR_VERSION}.${AIDEEN_PATCH_VERSION}"
)
set(AIDEEN_TEST_EXECUTABLE "aideen_test")

set(AIDEEN_DESCRIPTION "Force based closed loop control system.")

project("aideen" VERSION ${AIDEEN_VERSION} DESCRIPTION ${AIDEEN_DESCRIPTION} LANGUAGES C)

find_library(CBLAS_LIBRARY cblas REQUIRED)

add_executable(${AIDEEN_TEST_EXECUTABLE} main.c)
target_link_libraries(${AIDEEN_TEST_EXECUTABLE} PRIVATE ${CBLAS_LIBRARY})