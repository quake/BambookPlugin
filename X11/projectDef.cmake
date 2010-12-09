#/**********************************************************\ 
# Auto-generated X11 project definition file for the
# Bambook Plugin project
#\**********************************************************/

# X11 template platform definition CMake file
# Included from ../CMakeLists.txt


SET(CORE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/")
INCLUDE_DIRECTORIES(${CORE_PATH}/bambook-sdk/include)
SET(PLUGIN_INTERNAL_DEPS ${PLUGIN_INTERNAL_DEPS} ${CORE_PATH}/bambook-sdk/lib/libBambookCore.so)


# remember that the current source dir is the project root; this file is in ${PLATFORM_NAME}/
file (GLOB PLATFORM RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${PLATFORM_NAME}/[^.]*.cpp
    ${PLATFORM_NAME}/[^.]*.h
    ${PLATFORM_NAME}/[^.]*.cmake
    )

SOURCE_GROUP(${PLATFORM_NAME} FILES ${PLATFORM})

# use this to add preprocessor definitions
add_definitions(
)

set (SOURCES
    ${SOURCES}
    ${PLATFORM}
    )

add_x11_plugin(${PROJNAME} SOURCES)

# add library dependencies here; leave ${PLUGIN_INTERNAL_DEPS} there unless you know what you're doing!
target_link_libraries(${PROJNAME}
    ${PLUGIN_INTERNAL_DEPS}
    )
