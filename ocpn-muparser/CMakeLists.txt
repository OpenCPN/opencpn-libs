# OpenCPN wrapper for muparser:
#
# Exports: muparser::muparser link object


cmake_minimum_required (VERSION 3.1.0)
project(ocpn_muparser)

set(ENABLE_SAMPLES OFF CACHE BOOL "Enable samples build" FORCE)
set(ENABLE_OPENMP OFF CACHE BOOL "Use OpenMP multithreading" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libs" FORCE)

add_subdirectory(muparser EXCLUDE_FROM_ALL)

add_library(muparser_if INTERFACE)
add_library(muparser::muparser ALIAS muparser_if)
target_link_libraries(muparser_if INTERFACE muparser)
target_include_directories(muparser_if INTERFACE ${MUPARSER_SRC}/include)
