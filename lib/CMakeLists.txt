include_directories(
    .
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}
)

set( LIBSOURCES
    ${PROJECT_SOURCE_DIR}/src/logger.cpp
    ${PROJECT_SOURCE_DIR}/src/streamlogger.cpp
    ${PROJECT_SOURCE_DIR}/src/consolelogger.cpp
    ${PROJECT_SOURCE_DIR}/src/sysloglogger.cpp
    ${PROJECT_SOURCE_DIR}/src/filelogger.cpp
    ${PROJECT_SOURCE_DIR}/src/filerotatelogger.cpp
    ${PROJECT_SOURCE_DIR}/src/basicformatter.cpp
    ${PROJECT_SOURCE_DIR}/src/patternformatter.cpp
    ${PROJECT_SOURCE_DIR}/src/jsonformatter.cpp
    ${PROJECT_SOURCE_DIR}/src/utility.cpp
    ${PROJECT_SOURCE_DIR}/src/exception.cpp
)

add_library( liblogcpp SHARED ${LIBSOURCES} )

set_target_properties( liblogcpp PROPERTIES
  COMPILE_FLAGS  "-fPIC -Wall -ggdb -pthread -O2 -std=c++11"
  VERSION "${PACKAGE_MINOR}.${PACKAGE_PATCH}"
  SOVERSION "${PACKAGE_MAJOR}"
  OUTPUT_NAME logcpp
)

target_link_libraries( liblogcpp )

install( TARGETS liblogcpp LIBRARY DESTINATION usr/lib )
