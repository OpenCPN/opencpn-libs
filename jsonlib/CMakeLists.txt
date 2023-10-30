# ~~~
# ---------------------------------------------------------------------------
# Author:      Sean D'Epagnier
# Copyright:   2015
# License:     GPLv3+
# ---------------------------------------------------------------------------
# ~~~
cmake_minimum_required(VERSION 3.5.0)

if (TARGET ocpn::jsonlib)
  return()
endif ()

set(SAVE_CMLOC_JSONLIB ${CMLOC})
set(CMLOC "CMakeLists_jsonlib: ")

if (NOT CMAKE_MODULE_PATH)
  set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake)
endif ()

set(SRC_JSON src/json_reader.cpp src/json_value.cpp src/json_writer.cpp)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(JSONLIB STATIC ${SRC_JSON})
add_library(ocpn::jsonlib ALIAS JSONLIB)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  set_property(
    TARGET JSONLIB 
    PROPERTY COMPILE_FLAGS "-fvisibility=hidden -Wno-unused-but-set-variable"
  )
endif ()

target_include_directories(JSONLIB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(JSONLIB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(JSONLIB PRIVATE ${wxWidgets_INCLUDE_DIRS})

set(CMLOC ${SAVE_CMLOC_JSONLIB})
