#
#  OpenCPN  wrapper for the marnav library at
#  https://github.com/mariokonrad/marnav
#
#  Exports transitive link target ocpn::marnav
#
#  Copyright (c) 2023 Alec Leamas
#
#  License: BSD with Advertising, see
#      https://fedoraproject.org/wiki/Licensing:BSD#3ClauseBSD for details

cmake_minimum_required(VERSION 3.5)

set(mnav_repo https://github.com/mariokonrad/marnav.git)
# set(mnav_tag v0.14.0)   ## Does not build on gcc12/Bookworm
set(mnav_tag c4ae147)

add_library(_ocpn_marnav_if INTERFACE)
add_library(ocpn::marnav ALIAS _ocpn_marnav_if)

if (EXISTS /app/bin)
  # Flatpak build, marnav built as a extension module
  #
  add_library(_mnav_lib STATIC IMPORTED)
  file(GLOB _mnav_path /app/extensions/*/lib/libmarnav.a)
  set_property(TARGET _mnav_lib PROPERTY IMPORTED_LOCATION ${_mnav_path})

  add_library(_mnav_io_lib STATIC IMPORTED)
  file(GLOB _mnav_io_path /app/extensions/*/lib/libmarnav-io.a)
  set_property(TARGET _mnav_io_lib PROPERTY IMPORTED_LOCATION ${_mnav_io_path})

  target_link_libraries(_ocpn_marnav_if INTERFACE _mnav_lib _mnav_io_lib)

  string(TOLOWER  ${PACKAGE_NAME} _lc_pkg_name)
  set(mnav_incl_path /app/extensions/${_lc_pkg_name}/include)
  target_include_directories(_ocpn_marnav_if INTERFACE  ${mnav_incl_path})
else ()
  # Download sources and get the source directory
  #
  include(FetchContent)
  FetchContent_Declare(marnav GIT_REPOSITORY ${mnav_repo} GIT_TAG ${mnav_tag})
  FetchContent_Populate(marnav)
  FetchContent_GetProperties(marnav SOURCE_DIR marnav_src_dir)

  # Set up build options and build.
  #
  set(BUILD_SHARED_LIBS FALSE CACHE BOOL "Build shared libs" FORCE)
  set(ENABLE_TESTS FALSE CACHE BOOL "Enable tests" FORCE)
  set(ENABLE_TOOLS FALSE CACHE BOOL "Build tools" FORCE)
  set(ENABLE_EXAMPLES FALSE CACHE BOOL "Build examples" FORCE)
  add_subdirectory(${marnav_src_dir} marnav_bld)
  
  # Link available libraries
  #
  target_link_libraries(_ocpn_marnav_if INTERFACE marnav::marnav)
  if (TARGET marnav::marnav-io)
    target_link_libraries(_ocpn_marnav_if INTERFACE marnav::marnav-io)
  endif ()
endif ()
