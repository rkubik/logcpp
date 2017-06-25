cmake_minimum_required( VERSION 2.8 )

project( logcpp )

set( CMAKE_INSTALL_PREFIX "/" )
SET( CMAKE_CXX_FLAGS "-std=c++11 -Wall -ggdb" )

set( PACKAGE_MAJOR 0 )
set( PACKAGE_MINOR 1 )
set( PACKAGE_PATCH 0 )

message( "MAJOR: ${PACKAGE_MAJOR}" )
message( "MINOR: ${PACKAGE_MINOR}" )
message( "PATCH: ${PACKAGE_PATCH}" )

add_subdirectory( include )
add_subdirectory( lib )
add_subdirectory( examples )