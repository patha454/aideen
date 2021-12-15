cmake_minimum_required(VERSION 3.21)
cmake_policy(VERSION 3.21)

set(AIDEEN_TEST_EXECUTABLE "aideen_test")
set(AIDEEN_LINTER ${AIDEEN_TEST_EXECUTABLE}_lint)
set(AIDEEN_STYLER ${AIDEEN_TEST_EXECUTABLE}_style)

set(AIDEEN_DESCRIPTION "Force based closed loop control system.")

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

find_program(CLANG_TIDY clang-tidy)
find_program(CLANG_FORMAT clang-format)

project("aideen" VERSION ${AIDEEN_VERSION} DESCRIPTION ${AIDEEN_DESCRIPTION} LANGUAGES C)

configure_file(src/version.h.in src/version.h)

find_library(CBLAS_LIBRARY cblas REQUIRED)

add_executable(${AIDEEN_TEST_EXECUTABLE})

target_sources(${AIDEEN_TEST_EXECUTABLE}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/main.c
        ${PROJECT_SOURCE_DIR}/src/version.c
        ${CMAKE_BINARY_DIR}/src/version.h
)

target_link_libraries(${AIDEEN_TEST_EXECUTABLE} PRIVATE ${CBLAS_LIBRARY})

target_include_directories(${AIDEEN_TEST_EXECUTABLE} PUBLIC ${CMAKE_BINARY_DIR}/src)

if(NOT ${CLANG_TIDY} STREQUAL "CLANG_TIDY-NOTFOUND")
    add_custom_target( 
        ${AIDEEN_LINTER} 
        COMMAND ${CLANG_TIDY} --fix-errors ${PROJECT_SOURCE_DIR}/src/main.c -p ${CMAKE_BINARY_DIR}/. --config-file=${PROJECT_SOURCE_DIR}/.clang-tidy 
        COMMENT "Linting Aideen with Clang Tidy" 
        VERBATIM 
        USES_TERMINAL 
    ) 
    add_dependencies(${AIDEEN_TEST_EXECUTABLE} ${AIDEEN_LINTER}) 
endif() 
 
if(NOT ${CLANG_FORMAT} STREQUAL "CLANG_FORMAT-NOTFOUND")
    add_custom_target(
        ${AIDEEN_STYLER}
        COMMAND ${CLANG_FORMAT} ${PROJECT_SOURCE_DIR}/src/main.c -Werror -i --style=file
        COMMENT "Formating Aideen with Clang Format"
        VERBATIM
        USES_TERMINAL
    )
    add_dependencies(${AIDEEN_TEST_EXECUTABLE} ${AIDEEN_STYLER})
endif()
