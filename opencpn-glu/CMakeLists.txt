cmake_minimum_required(VERSION 3.5)

project(old_glu)

message(FATAL_ERROR [=[
Inclusion of the opencpn-libs/opencpn-glu subdirectory has been disabled.
Any statements like "add_subdirectory opencpn-libs/opencpn-glu" should
hence be removed.

If the plugin already includes  opencpn-libs/plugin_dc no more action
needs to be taken.

Otherwise, the inclusion of opencpn-libs/opencpn-glu can be replaced by

    add_subdirectory(opencpn-libs/plugin_dc)
    target_link_libraries(SOME_PLUGIN_TARGET PRIVATE ocpn::plugin-dc)

]=])
