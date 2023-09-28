cmake_minimum_required(VERSION 3.26)
project(dub_dot_ito)

enable_testing()

set(CMAKE_CXX_STANDARD 17)

option(cli "compile the command line interface")
option(gui "compile the gui interface")

if(cli)
    add_definitions(-DCLI_ENABLED)

    file(GLOB_RECURSE CLI_HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "cli/*.h")
    file(GLOB_RECURSE CLI_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "cli/*.cpp")
    add_executable(dub_dot_ito
        ${CLI_HEADERS}
        ${CLI_SOURCES}
    )
elseif (gui)
    add_definitions(-DGUI_ENABLED)

    # todo gui
    add_executable(dub_dot_ito)
endif ()

# region core
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "core/*.h")
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "core/*.cpp")

target_sources(dub_dot_ito
        PUBLIC ${HEADERS}
        PUBLIC ${SOURCES}
        PUBLIC main.cpp
)

# endregion core

# region tests
file(GLOB_RECURSE TESTS RELATIVE ${CMAKE_SOURCE_DIR} "tests/*.cpp")
add_executable(tests
        thirdparty/doctest.h
        ${HEADERS}
        ${SOURCES}
        ${TESTS}
)
# endregion tests
target_compile_features(tests PRIVATE cxx_std_17)
set_target_properties(tests PROPERTIES LINKER_LANGUAGE CXX)