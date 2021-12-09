cmake_minimum_required(VERSION 3.21)
cmake_policy(VERSION 3.21)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

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

configure_file(version.h.in version.h)

find_library(CBLAS_LIBRARY cblas REQUIRED)

add_executable(${AIDEEN_TEST_EXECUTABLE} main.c version.c)

target_link_libraries(${AIDEEN_TEST_EXECUTABLE} PRIVATE ${CBLAS_LIBRARY})

target_include_directories(${AIDEEN_TEST_EXECUTABLE} PUBLIC ${PROJECT_BINARY_DIR})
