opencpn-libs README
===================

This is a set of libraries used by OpenCPN plugins, managed as a git submodule.
It provides a standardized way to share common functionality across plugins
while maintaining version control and consistency.

Overview
--------

The repository contains several types of libraries:

1. API Libraries (api-16, api-17, api-18):
   - Core interfaces for plugin-OpenCPN communication
   - Different versions support various OpenCPN releases
   - Plugins should use the latest API version compatible with their minimum supported OpenCPN version
2. Utility Libraries:
   - Data Processing: jsoncpp, json-schema-validator, pugixml, tinyxml
   - Compression: bzip2, lz4, zlib
   - Navigation: nmea0183, n2kparser
   - Graphics: wxsvg, opencpn-glu
   - Network: curl, wxcurl
   - And more specialized libraries for specific functionality

Adding the submodule
--------------------

    $ git submodule add https://github.com/OpenCPN/opencpn-libs.git
    $ git commit -m "Adding opencpn-libs submodule"

Updating to latest status
-------------------------

    $ git submodule update --remote --merge opencpn-libs
    $ git add opencpn-libs
    $ git commit -m "Updating opencpn-libs to latest version."

Using it
--------

All libraries exports a link target named like ocpn::lz4. To find the exact
name, check the file CMakeLists.txt which is available in the top directory
of each library. Look for a line like `add_library(ocpn::lz4 ALIAS _LZ4)`.

A library is typically used like

    add_subdirectory("${CMAKE_SOURCE_DIR}/opencpn-libs/lz4")
    target_link_libraries(${PACKAGE_NAME} ocpn::lz4)

Note:  the name _target_link_libraries_ is somewhat misleading. It is not
just about linkage, running it means importing all sorts of include paths,
compile constants and libraries required when using the library.

Removing the submodule
----------------------

Normally not required, but if:

    $ git submodule deinit -f opencpn-libs
    $ git rm --cached opencpn-libs
    $ rm -rf .git/modules/opencpn-libs
    $ rm -rf opencpn-libs
    $ git config -f .gitmodules --remove-section submodule.opencpn-libs
    $ git add .gitmodules
    $ git commit -m "Remove opencpn-libs submodule."

More: https://stackoverflow.com/questions/1260748

Updating libraries
------------------

Libraries in opencpn-libs can if necessary be updated locally. The basic
flow is

    - `cd opencpn-libs/some-lib`
    - Edit some-file
    - `git commit -am "Why I changed this file"`
    - `cd ../..`
    - `git add opencpn-libs`
    - `git commit -m "Adding local change to opencpn-libs"`

The commit will be part of the submodule, not the main repo. If the need of
such a change is deemed necessary, please make a PR against
https://github.com/OpenCPN/opencpn-libs/ so it can be integrated in the main
set of plugins.
