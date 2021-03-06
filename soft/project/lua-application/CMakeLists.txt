
find_package( Qt4 )
set( QT_USE_QTCORE True )
set( QT_USE_QTGUI  True )
if ( WIN32 )
    set( QT_USE_QTMAIN True )
endif ( WIN32 )
include( ${QT_USE_FILE} )

include_directories( "./src"
                      "${ROOT}/lib-qtluaex/src" 
                     "${ROOT}/3dparty-src/lua-5.1.5/src" 
                     "${ROOT}/3dparty-src/libqtlua-1.4/src" 
                     ${CMAKE_CURRENT_BINARY_DIR} )

file( GLOB src     "./src/*.cpp" )
file( GLOB headers "./src/*.h" )
file( GLOB ui      "./src/*.ui" )
file( GLOB qrc     "./src/*.qrc" )
message( INFO "SRC = ${src}" )
message( INFO "HEADERS = ${headers}" )

Qt4_WRAP_CPP( mocSrc ${headers} )
set( src ${src} ${mocSrc} )

QT4_WRAP_UI( uiSrc ${ui} )
set( src ${src} ${uiSrc} )

QT4_ADD_RESOURCES( qrcSrc ${qrc} )
set( src ${src} ${qrcSrc} )

add_executable( qtluaex-test ${src} )
target_link_libraries( qtluaex-test qtluaex ${QT_LIBRARIES} )
install( TARGETS qtluaex-test DESTINATION "." )