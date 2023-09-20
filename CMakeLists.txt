cmake_minimum_required(VERSION 3.26)
project(dub_dot_ito)

enable_testing()

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "core/*.h")
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "core/*.cpp")
file(GLOB_RECURSE TESTS RELATIVE ${CMAKE_SOURCE_DIR} "tests/*.cpp")

add_executable(dub_dot_ito
        ${HEADERS}
        ${SOURCES}
        main.cpp
)

add_executable(tests
        thirdparty/doctest.h
        ${HEADERS}
        ${SOURCES}
        ${TESTS}
)
target_compile_features(tests PRIVATE cxx_std_17)
set_target_properties(tests PROPERTIES LINKER_LANGUAGE CXX)