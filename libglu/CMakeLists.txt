cmake_minimum_required(VERSION 3.5)

project(old_glu)

message(FATAL_ERROR [=[
Inclusion of the opencpn-libs/opencpn-glu subdirectory has been disabled.
Any statements like "add_subdirectory opencpn-libs/opencpn-glu" should
hence be removed.

The glu library is provided by the new plugin_dc library which usually
is included using

    add_subdirectory(opencpn-libs/plugin_dc)
    target_link_libraries(SOME_PLUGIN_TARGET PRIVATE ocpn::plugin-dc)

]=])
