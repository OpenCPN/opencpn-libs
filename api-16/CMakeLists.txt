# ~~~
# Summary:      Api headers library cmake setup
# License:      GPLv3+
# Copyright (c) 2021 Alec Leamas
#
# Include API header and, on win32, link import libs. Set API_VERSION  and
# API_OCPN_MIN_VERSION
# ~~~

cmake_minimum_required(VERSION 3.1)

if (TARGET ocpn::api)
  return ()
endif ()

set(API_VERSION "1.16" PARENT_SCOPE)
set(API_OCPN_MIN_VERSION "5.0.0" PARENT_SCOPE)

add_library(OCPN_API_WX32 INTERFACE)
add_library(ocpn::api_wx32 ALIAS OCPN_API_WX32)
target_include_directories(
  OCPN_API_WX32 INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}"
)
if (WIN32 AND MSVC)
  target_link_libraries(
    OCPN_API_WX32
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/msvc-wx32/opencpn.lib"
  )
  # Assuming unicode build, required for mingw headers
  target_compile_definitions(OCPN_API_WX32 INTERFACE -DUNICODE)
endif ()

add_library(OCPN_API INTERFACE)
add_library(ocpn::api ALIAS OCPN_API)
target_include_directories(
  OCPN_API INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}"
)
if (WIN32 AND MSVC)
  target_link_libraries(
    OCPN_API
      INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/msvc/opencpn.lib"
  )
  target_compile_definitions(OCPN_API INTERFACE -DUNICODE)
elseif(WIN32 AND MINGW) 
  target_link_libraries(
    OCPN_API INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/mingw/libopencpn.dll.a")
endif ()

