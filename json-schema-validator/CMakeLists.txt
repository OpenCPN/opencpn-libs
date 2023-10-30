# ~~~
# ---------------------------------------------------------------------------
# Author:      Sean D'Epagnier
# Copyright:   2015
# License:     GPLv3+
# ---------------------------------------------------------------------------
# ~~~
cmake_minimum_required(VERSION 3.5.0)

if (TARGET ocpn::json-schema-validator)
  return()
endif ()

set(SAVE_CMLOC_JSON-SCHEMA-VALIDATOR ${CMLOC})
set(CMLOC "CMakeLists_json-schema-validator: ")

if (NOT CMAKE_MODULE_PATH)
  set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake)
endif ()

set(SRC_JSONSCHEMAVALIDATOR json-schema-draft7.json.cpp json-uri.cpp
                            json-validator.cpp
)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(JSON-SCHEMA-VALIDATOR STATIC ${SRC_JSONSCHEMAVALIDATOR})
add_library(ocpn::json-schema-validator ALIAS JSON-SCHEMA-VALIDATOR)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  set_property(
    TARGET JSON-SCHEMA-VALIDATOR
    PROPERTY COMPILE_FLAGS "-fvisibility=hidden -Wno-unused-but-set-variable"
  )
endif ()

target_include_directories(
  JSON-SCHEMA-VALIDATOR PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
target_include_directories(
  JSON-SCHEMA-VALIDATOR PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/nlohmann
)

set(CMLOC ${SAVE_CMLOC_JSONCPP})
