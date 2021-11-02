opencpn-libs README
===================


This is an experimental set of libraries aimed to be used in 
opencpn plugins as a git submodule.

Adding the submodule
--------------------

    $ git submodule add https://github.com/leamas/opencpn-libs.git
    $ git commit -m "Adding opencpn-libs submodule"


Updating to latest status
-------------------------

    $ cd opencpn-libs
    $ git pull origin main
    $ cd ..
    $ git commit -m "Updating libraries"


Using it
--------

All libraries exports a link target named like ocpn::lz4. To find the exact
name, check the file CMakeLists which is available in the top directory of 
each library. Look for a line like `add_library(ocpn::sqlite ALIAS _SQLITE)`.

A library is typically used like

    add_subdirectory("libs/jsoncpp")
    target_link_libraries(${PACKAGE_NAME} ocpn::jsoncpp)

Note:  the name _target_link_libraries_ is somewhat misleading. It is not
just about linkage, running it means importing all sorts of include paths,
compile constants and libraries required when using the library.


Removing the submodule.
-----------------------

This should normally not be required, but if:

    $ git submodule deinit opencpn-libs
    $ git rm --cached opencpn-libs
    $ git rm .gitmodules
    $ git commit -m "Remove opencpn-libs submodule."


Updating libraries
------------------

The recommended way is to update https://github.com/leamas/opencpn-libs/,
possibly by making a PR. However libraries in opencpn-libs can if necessary
be updated locally.  The basic flow is

    - `cd opencpn-libs/some-lib`
    - Edit some-file
    - `git commit -am "Why I changed this file"`

The commit will be part of the submodule, not the main repo. Details are TBD.
