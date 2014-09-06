
# Set CMake
cmake_minimum_required ( VERSION 2.8 )

# Adding modules
set ( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake_modules" )

# Projct
project ( qI2Pd )



# Check compiler type
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()

# Default build is Debug
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

# Definitions
add_definitions ( "-std=c++11 -Wall" )


# Dependencies
find_package ( Threads REQUIRED )

find_package ( CryptoPP REQUIRED )

find_package ( Qt5 COMPONENTS "Core" "Network" REQUIRED )

# Sources

include_directories ( ${CMAKE_CURRENT_SOURCE_DIR}/core )
include_directories ( ${CMAKE_CURRENT_SOURCE_DIR}/crypto )
include_directories ( ${CMAKE_CURRENT_SOURCE_DIR}/net )
include_directories ( ${CMAKE_CURRENT_SOURCE_DIR}/streaming )




