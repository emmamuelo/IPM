
file( GLOB src     "./src/*.cpp" )
file( GLOB headers "./src/*.h" )
include_directories( "./src" 
                     "../lib-app-binder/src" 
                     ${BOOST_INC_PATH} 
                     ${ROOT}/3dparty-bin/vlc-2.0.1/sdk/include
                     ${CMAKE_CURRENT_BINARY_DIR} )

Qt4_WRAP_CPP( mocSrc ${headers} )
set( src ${src} ${mocSrc} )

QT4_WRAP_UI( uiSrc ${ui} )
set( src ${src} ${uiSrc} )

QT4_ADD_RESOURCES( qrc "./src/images.qrc" )
set( src ${src} ${qrc} )

add_library( application STATIC ${src} )
find_library( libvlc NAMES libvlc PATHS "${ROOT}/3dparty-bin/vlc-2.0.1/sdk/lib" )
target_link_libraries( application ${QT_LIBRARIES} binder ${libvlc} )
install( DIRECTORY ${ROOT}/3dparty-bin/vlc-2.0.1/ DESTINATION "./" )

