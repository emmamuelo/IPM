
cmake_minimum_required( VERSION 2.8 )

# ��������������� ������� ����������, ����� 
# �� ����� ���� Microsoft Redistributable 
# �������������.
#set(CMAKE_USER_MAKE_RULES_OVERRIDE
#    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/c_flag_overrides.cmake)
#set(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX
#    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/cxx_flag_overrides.cmake)

project( "project" )
set( INSTALL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/app" CACHE PATH "Path to install to" )
set( CMAKE_INSTALL_PREFIX ${INSTALL_PATH} )
set( ROOT ${CMAKE_CURRENT_SOURCE_DIR} )
if ( WIN32 )
    include( "./config-win32.cmake" )
elseif ( UNIX )
    include( "./config-unix.cmake" )
endif ( WIN32 )

add_subdirectory( "./3dparty-src/lua-5.1.5" )
add_subdirectory( "./3dparty-src/luabind" )
add_subdirectory( "./3dparty-src/ftdi" )
add_subdirectory( "./3dparty-src/libqtlua-1.4" )
add_subdirectory( "./application" )
add_subdirectory( "./lib-application" )
add_subdirectory( "./lib-qtluaex" )
add_subdirectory( "./lua-application" ) # For testing lib-qtluaex project
add_subdirectory( "./remote" )
