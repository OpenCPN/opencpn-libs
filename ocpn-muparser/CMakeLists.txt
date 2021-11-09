# OpenCPN wrapper for muparser:
#
# Exports: muparser::muparser link object


cmake_minimum_required (VERSION 3.1.0)
project(ocpn_muparser)

set(ENABLE_SAMPLES OFF)
set(ENABLE_OPENMP OFF)
set(BUILD_SHARED_LIBS OFF)

add_subdirectory(muparser)

add_library(muparser_if INTERFACE)
add_library(muparser:muparser ALIAS muparser_if)
target_link_libraries(muparser_if INTERFACE muparser)
target_include_directories(muparser_if INTERFACE ${MUPARSER_SRC}/include)
