message("lf_logic.")
add_library(lf_logic INTERFACE)
target_link_libraries(lf_logic INTERFACE
    pugixml
    lorina
    kitty
    mockturtle
    libabc
    dl
    readline
    lf_utility
    lf_misc
    lf_arch
    hedals
    resubals
    mecals
    Circuit2Cnf
    ganak-static
)
target_include_directories(lf_logic SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})