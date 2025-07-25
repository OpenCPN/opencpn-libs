#
# Include API header and, on win32, link import libs. Set API_VERSION  and
# API_OCPN_MIN_VERSION
#
cmake_minimum_required(VERSION 3.5)

if (TARGET ocpn::api)
  return ()
endif ()

set(API_VERSION "1.21" PARENT_SCOPE)
set(API_OCPN_MIN_VERSION "5.11.0" PARENT_SCOPE)

add_library(OCPN_API_WX32 INTERFACE)
add_library(ocpn::api_wx32 ALIAS OCPN_API_WX32)
add_library(ocpn::api ALIAS OCPN_API_WX32)
target_include_directories(
  OCPN_API_WX32
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}"
)
if (WIN32 AND MSVC)
  target_link_libraries(
    OCPN_API_WX32
      INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/msvc-wx32/opencpn.lib"
  )
  # Assuming unicode build, required for mingw headers
  target_compile_definitions(OCPN_API_WX32 INTERFACE -DUNICODE)
endif ()
