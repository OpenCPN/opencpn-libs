cmake_minimum_required(VERSION 3.5)

if (TARGET ocpn::sqlite)
  return()
endif ()

option(SQLITE_DISABLE_EXTENSIONS "Build SQLite with dynamic extension module support disabled" ON)
option(SQLITE_FORCE_BUNDLED "Force build of bundled SQLite source, without looking for system libraries" OFF)

add_library(_SQLITE INTERFACE)
add_library(ocpn::sqlite ALIAS _SQLITE)

if(NOT SQLITE_FORCE_BUNDLED)
  if(CMAKE_VERSION VERSION_LESS 3.14.0)
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR/cmake)
    find_package(Sqlite)
  else ()
    find_package(SQLite3)
  endif ()
endif()

if (NOT (SQLITE_FOUND OR SQLite3_FOUND) OR APPLE OR WIN32 OR QT_ANDROID)
  message(STATUS "Using bundled sqlite3 library.")
  add_library(
    SQLITE3 STATIC ${CMAKE_CURRENT_LIST_DIR}/src/sqlite3.c
                   ${CMAKE_CURRENT_LIST_DIR}/include/sqlite3.h
  )
  target_link_libraries(_SQLITE INTERFACE SQLITE3)
  target_include_directories(
    _SQLITE INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include
  )

  # We usually do not need extensions, and using them in a static library
  # possibly causes trouble with libdl linking order.
  if (UNIX AND NOT APPLE)
    if (SQLITE_DISABLE_EXTENSIONS)
      add_definitions(" -DSQLITE_OMIT_LOAD_EXTENSION")
    endif()
  endif (UNIX AND NOT APPLE)

else ()
  if( SQLite3_FOUND)
    set(SQLITE_INCLUDE_DIR ${SQLite3_INCLUDE_DIR})
    set(SQLITE_LIBRARIES ${SQLite3_LIBRARIES})
  endif()
  target_include_directories(_SQLITE INTERFACE ${SQLITE_INCLUDE_DIR})
  target_link_libraries(_SQLITE INTERFACE ${SQLITE_LIBRARIES})
  file(STRINGS "${SQLITE_INCLUDE_DIR}/sqlite3.h" SQLITE_VERSION_LINE
       REGEX "^[ \t]*#define[ \t]+SQLITE_VERSION_NUMBER[ \t]+[0-9]+.*$"
  )
  string(REGEX REPLACE
         "[ \t]*#define[ \t]+SQLITE_VERSION_NUMBER[ \t]+([0-9]+).*$"
         "\\1" SQLITE_VERSION ${SQLITE_VERSION_LINE}
  )
  message(STATUS "Using system SQLite library version ${SQLITE_VERSION}.")
  if (${SQLITE_VERSION} LESS "3019000")
    target_compile_definitions(_SQLITE INTERFACE -DSQLITE_USE_LEGACY_STRUCT)
  endif ()
endif ()
