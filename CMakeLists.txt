#
# CMake seems right here :)
#

# Set CMake 
cmake_minimum_required ( VERSION 2.8 )

# Adding modules
set ( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules" )

# Projct
project ( qI2Pd )


add_subdirectory ( "src" )


# Default build is Debug
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

add_definitions ( "-std=c++11 -Wall" )

find_package ( Threads REQUIRED )

find_package ( Boost COMPONENTS system filesystem regex program_options REQUIRED )

find_package ( CryptoPP REQUIRED )

find_package ( Qt5 REQUIRED )



