include_directories(
    .
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_BINARY_DIR}
)

set( BASIC_SOURCES ${PROJECT_SOURCE_DIR}/examples/basic.cpp )
add_executable( basic ${BASIC_SOURCES} )
target_link_libraries( basic liblogcpp )

set( DAEMON_SOURCES ${PROJECT_SOURCE_DIR}/examples/daemon.cpp )
add_executable( daemon ${DAEMON_SOURCES} )
target_link_libraries( daemon liblogcpp )

set( EXTRA_CONTEXT_SOURCES ${PROJECT_SOURCE_DIR}/examples/extra_context.cpp )
add_executable( extra_context ${EXTRA_CONTEXT_SOURCES} )
target_link_libraries( extra_context liblogcpp )