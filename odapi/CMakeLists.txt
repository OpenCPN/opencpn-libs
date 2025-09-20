# ~~~
# Summary:      ODAPI headers library cmake setup
# License:      GPLv3+
# Copyright (c) 2023 Dave Register
#
# ~~~

cmake_minimum_required(VERSION 3.10)

set(VERSION_MAJOR "1")
set(VERSION_MINOR "2")
set(VERSION_PATCH "0")
set(VERSION_TWEAK "0")
set(VERSION_DATE "20/09/2025") # DD/MM/YYYY format

if (TARGET ocpn::odapi)
  return ()
endif ()


add_library(OCPN_ODAPI INTERFACE)
add_library(ocpn::odapi ALIAS OCPN_ODAPI)
target_include_directories(
  OCPN_ODAPI INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}"
)

