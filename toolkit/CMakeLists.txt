######################################################################
# compile yosys with Makefile
######################################################################
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/yosys/Makefile)
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/yosys is missing!")
endif()
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/yosys/lib/yosys/libyosys.so
    COMMAND ${CMAKE_COMMAND} -E env make -j ${CMAKE_JOB_POOLS_MAXIMUM} config-gcc ENABLE_LIBYOSYS=1
    COMMAND ${CMAKE_COMMAND} -E env make -j ${CMAKE_JOB_POOLS_MAXIMUM} install ENABLE_LIBYOSYS=1 PREFIX=${CMAKE_CURRENT_BINARY_DIR}/yosys/
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/yosys
    COMMENT "Compiling Yosys with Makefile for Ninja"
    VERBATIM
)
add_custom_target(yosys_target ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/yosys/lib/yosys/libyosys.so
    COMMENT "Building Yosys Target"
)
# link the libyosys.so
add_library(libyosys INTERFACE)
target_compile_definitions(libyosys INTERFACE _YOSYS_)
set_target_properties(libyosys PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/yosys"
    INTERFACE_LINK_LIBRARIES "${CMAKE_CURRENT_BINARY_DIR}/yosys/lib/yosys/libyosys.so"
)

######################################################################
# compile abc with CMakeLists.txt
######################################################################
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/abc/CMakeLists.txt)
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/abc is missing!")
endif()
set(ABC_USE_NAMESPACE "babc")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/abc EXCLUDE_FROM_ALL)

######################################################################
# compile espresso with CMakeLists.txt
######################################################################
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/espresso/CMakeLists.txt)
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/espresso is missing!")
endif()
add_subdirectory(espresso ${CMAKE_BINARY_DIR}/toolkit/espresso )

######################################################################
# compile HEDALS with CMakeLists.txt
######################################################################
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/HEDALS/CMakeLists.txt)
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/HEDALS is missing!")
endif()
add_subdirectory(HEDALS ${CMAKE_BINARY_DIR}/toolkit/HEDALS )

######################################################################
# compile AppResub with CMakeLists.txt
######################################################################
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/ResubALS/CMakeLists.txt)
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/ResubALS is missing!")
endif()
add_subdirectory(ResubALS ${CMAKE_BINARY_DIR}/toolkit/ResubALS )

######################################################################
# compile MECALS with CMakeLists.txt
######################################################################
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/MECALS/CMakeLists.txt)
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/MECALS is missing!")
endif()
add_subdirectory(MECALS ${CMAKE_BINARY_DIR}/toolkit/MECALS )

######################################################################
# compile VACSEM with CMakeLists.txt
######################################################################
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/VACSEM/CMakeLists.txt)
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/VACSEM is missing!")
endif()
add_subdirectory(VACSEM ${CMAKE_BINARY_DIR}/toolkit/VACSEM )

######################################################################
# compile ALFANS with CMakeLists.txt
######################################################################
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/ALFANS/CMakeLists.txt)
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/ALFANS is missing!")
endif()
add_subdirectory(ALFANS ${CMAKE_BINARY_DIR}/toolkit/ALFANS )

######################################################################
# compile mockturtle with CMakeLists.txt
######################################################################
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/mockturtle/CMakeLists.txt)
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/mockturtle is missing!")
endif()
add_subdirectory(mockturtle)

######################################################################
# compile iEDA with CMakeLists.txt
######################################################################
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/iEDA/CMakeLists.txt)
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/iEDA is missing!")
endif()
add_subdirectory(iEDA ${CMAKE_BINARY_DIR}/toolkit/iEDA)
