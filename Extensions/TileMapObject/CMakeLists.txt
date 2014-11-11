cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0015 NEW)

project(TileMapObject)

#Sanity checks and options
IF ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  	message( "CMAKE_BUILD_TYPE is empty, assuming build type is Release" )
	set(CMAKE_BUILD_TYPE Release)
ENDIF()
if(CMAKE_COMPILER_IS_GNUCXX)
	IF ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    	set(CMAKE_EXE_LINKER_FLAGS "-s")  ## Strip binary
    ENDIF()
endif()
if(EMSCRIPTEN) #When compiling for the web, ensure we get no warning when using our own external libraries.
	SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} --bind -Wno-warn-absolute-paths" )
ENDIF()

#Common directories:
###
set(GD_base_dir ${CMAKE_CURRENT_SOURCE_DIR}/../..)
set(GDCORE_include_dir ${GD_base_dir}/Core)
set(GDCORE_lib_dir ${GD_base_dir}/Binaries/Output/${CMAKE_BUILD_TYPE}_${CMAKE_SYSTEM_NAME})
set(GDCpp_include_dir ${GD_base_dir}/GDCpp)
set(GDCpp_lib_dir ${GD_base_dir}/Binaries/Output/${CMAKE_BUILD_TYPE}_${CMAKE_SYSTEM_NAME})
set(GDCpp_Runtime_lib_dir ${GD_base_dir}/Binaries/Output/${CMAKE_BUILD_TYPE}_${CMAKE_SYSTEM_NAME}/CppPlatform/Runtime)
set(boost_include_dir ${GD_base_dir}/ExtLibs/boost)
set(sfml_include_dir ${GD_base_dir}/ExtLibs/SFML/include)
IF(WIN32)
	IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
		set(sfml_lib_dir ${GD_base_dir}/ExtLibs/SFML/build-mingw-debug/lib)
	ELSE()
		set(sfml_lib_dir ${GD_base_dir}/ExtLibs/SFML/build-mingw-release/lib)
	ENDIF()
ELSE()
	set(sfml_lib_dir ${GD_base_dir}/ExtLibs/SFML/build-linux/lib)
ENDIF()
IF(WIN32) #Special case for wxWidgets on Windows
	set(wxwidgets_include_dir ${GD_base_dir}/ExtLibs/wxwidgets/include)
	IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
		set(wxwidgets_include_dir ${wxwidgets_include_dir} ${GD_base_dir}/ExtLibs/wxwidgets/lib/gcc_dll/mswud)
	ELSE()
		set(wxwidgets_include_dir ${wxwidgets_include_dir} ${GD_base_dir}/ExtLibs/wxwidgets/lib/gcc_dll/mswu)
	ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)
	set(wxwidgets_lib_dir ${GD_base_dir}/ExtLibs/wxwidgets/lib/gcc_dll)
ENDIF(WIN32)

#Dependencies on external libraries:
###
include_directories(${boost_include_dir})
include_directories(${sfml_include_dir})
include_directories(${GDCORE_include_dir})
include_directories(${GDCpp_include_dir})
IF(WIN32) #Special case for wxWidgets on Windows
	include_directories(${wxwidgets_include_dir})
ELSEIF (NOT EMSCRIPTEN)
	find_package(wxWidgets COMPONENTS core base ribbon webview stc aui propgrid richtext html xrc REQUIRED)
	include( "${wxWidgets_USE_FILE}" )
	find_package(PkgConfig REQUIRED)
	pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
	include_directories(${GTK3_INCLUDE_DIRS})
	link_directories(${GTK3_LIBRARY_DIRS})
ENDIF(WIN32)
IF(NOT TARGET GDCore) #Ensure that the build will work even when GDCore is not in the target list.
link_directories(${GDCORE_lib_dir})
ENDIF()
IF(NOT TARGET GDCpp) #Ensure that the build will work even when GDC++ is not in the target list.
link_directories(${GDCpp_lib_dir})
ENDIF()
IF(NOT TARGET GDCpp_Runtime)
	add_library(GDCpp_Runtime SHARED IMPORTED)
	IF(WIN32)
		set_property(TARGET GDCpp_Runtime PROPERTY IMPORTED_LOCATION ${GDCpp_Runtime_lib_dir}/GDCpp.dll)
	 	set_property(TARGET GDCpp_Runtime PROPERTY IMPORTED_IMPLIB ${GDCpp_Runtime_lib_dir}/libGDCpp.dll.a)
	ELSE()
		set_property(TARGET GDCpp_Runtime PROPERTY IMPORTED_LOCATION ${GDCpp_Runtime_lib_dir}/libGDCpp.so)
	 	#set_property(TARGET GDCpp_Runtime PROPERTY IMPORTED_IMPLIB ${GDCpp_Runtime_lib_dir}/libGDCpp.so.a)
	ENDIF(WIN32)
ENDIF()

#Defines
###
set(TileMapObject_extra_definitions "${TileMapObject_extra_definitions} GD_IDE_ONLY=1;")
IF (EMSCRIPTEN) #When compiling for the web, we do not want any GUI related feature.
	add_definitions( -DGD_NO_WX_GUI )
	add_definitions( -DEMSCRIPTEN )
ENDIF()
IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
	add_definitions( -DDEBUG )
	IF(WIN32)
		add_definitions( __WXDEBUG__ )
	ENDIF(WIN32)
ELSEIF ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
	add_definitions( -DRELEASE )
	add_definitions( -DBOOST_DISABLE_ASSERTS )
ELSE()
	add_definitions( -DDEV )
	add_definitions( -DBOOST_DISABLE_ASSERTS )
ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)

IF(WIN32)
	add_definitions( -DWINDOWS )
	add_definitions( "-DGD_CORE_API=__declspec(dllimport)" )
	add_definitions( "-DGD_API=__declspec(dllimport)" )
	add_definitions( "-DGD_EXTENSION_API=__declspec(dllexport)" )

	add_definitions( -D__GNUWIN32__ )
	add_definitions( -D__WXMSW__ )
	add_definitions( -DwxUSE_UNICODE=1 )
	add_definitions( -DWXUSINGDLL )
ELSE()
	add_definitions( -DLINUX )
	add_definitions( -DGD_API= )
	add_definitions( -DGD_CORE_API= )
	add_definitions( -DGD_EXTENSION_API= )
	add_definitions(${GTK3_CFLAGS_OTHER})
ENDIF(WIN32)


#The targets
###
include_directories(.)
set(source_files
	Extension.cpp
	TileMapObject.cpp
	RuntimeTileMapObject.cpp
	TileMapTools.cpp
	TileMapProxies.cpp
	TileMap.cpp
	TileSet.cpp
	)

set(gdide_source_files
	TileMapObjectEditor.cpp
	TileMapObjectEditorCommands.cpp
	TileSetConfigurationEditor.cpp
	TileMapConfigurationEditor.cpp
	TileEditor.cpp
	TileSetPanel.cpp
	TileMapPanel.cpp
	TileMapDialogs.cpp
	TileMapDialogs.xrc
	TileMapDialogs_wxsmith_bitmaps.cpp)

add_library(TileMapObject SHARED ${source_files} ${gdide_source_files})
set_target_properties(TileMapObject PROPERTIES COMPILE_DEFINITIONS "${TileMapObject_extra_definitions}")
set_target_properties(TileMapObject PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${GD_base_dir}/Binaries/Output/${CMAKE_BUILD_TYPE}_${CMAKE_SYSTEM_NAME}/CppPlatform/Extensions")
set_target_properties(TileMapObject PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${GD_base_dir}/Binaries/Output/${CMAKE_BUILD_TYPE}_${CMAKE_SYSTEM_NAME}/CppPlatform/Extensions")
set_target_properties(TileMapObject PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${GD_base_dir}/Binaries/Output/${CMAKE_BUILD_TYPE}_${CMAKE_SYSTEM_NAME}/CppPlatform/Extensions")
set_target_properties(TileMapObject PROPERTIES PREFIX "")
IF(NOT EMSCRIPTEN)
	add_library(TileMapObject_Runtime SHARED ${source_files})
	set_target_properties(TileMapObject_Runtime PROPERTIES COMPILE_DEFINITIONS "${TileMapObject_Runtime_extra_definitions}")
	set_target_properties(TileMapObject_Runtime PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${GD_base_dir}/Binaries/Output/${CMAKE_BUILD_TYPE}_${CMAKE_SYSTEM_NAME}/CppPlatform/Extensions/Runtime")
	set_target_properties(TileMapObject_Runtime PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${GD_base_dir}/Binaries/Output/${CMAKE_BUILD_TYPE}_${CMAKE_SYSTEM_NAME}/CppPlatform/Extensions/Runtime")
	set_target_properties(TileMapObject_Runtime PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${GD_base_dir}/Binaries/Output/${CMAKE_BUILD_TYPE}_${CMAKE_SYSTEM_NAME}/CppPlatform/Extensions/Runtime")
	set_target_properties(TileMapObject_Runtime PROPERTIES RUNTIME_OUTPUT_NAME "TileMapObject")
	set_target_properties(TileMapObject_Runtime PROPERTIES LIBRARY_OUTPUT_NAME "TileMapObject")
	set_target_properties(TileMapObject_Runtime PROPERTIES ARCHIVE_OUTPUT_NAME "TileMapObject")
	set_target_properties(TileMapObject_Runtime PROPERTIES PREFIX "")
ENDIF()
IF(WIN32)
	set_target_properties(TileMapObject PROPERTIES SUFFIX ".xgdwe")
	set_target_properties(TileMapObject_Runtime PROPERTIES SUFFIX ".xgdw")
ELSEIF(EMSCRIPTEN)
	set_target_properties(TileMapObject PROPERTIES SUFFIX ".bc")
ELSE()
	set_target_properties(TileMapObject PROPERTIES SUFFIX ".xgdle")
	set_target_properties(TileMapObject_Runtime PROPERTIES SUFFIX ".xgdl")
ENDIF(WIN32)

#Linker files for the IDE extension
###
IF(EMSCRIPTEN)
	#Nothing.
ELSE()
	target_link_libraries(TileMapObject GDCore)
	target_link_libraries(TileMapObject GDCpp)
	IF(WIN32)
		target_link_libraries(TileMapObject ${sfml_lib_dir}/libsfml-audio.a ${sfml_lib_dir}/libsfml-graphics.a ${sfml_lib_dir}/libsfml-window.a ${sfml_lib_dir}/libsfml-network.a ${sfml_lib_dir}/libsfml-system.a)
		IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
			target_link_libraries(TileMapObject ${wxwidgets_lib_dir}/libwxmsw29ud_xrc.a ${wxwidgets_lib_dir}/libwxmsw29ud_stc.a ${wxwidgets_lib_dir}/libwxmsw29ud_richtext.a ${wxwidgets_lib_dir}/libwxmsw29ud_propgrid.a ${wxwidgets_lib_dir}/libwxmsw29ud_ribbon.a ${wxwidgets_lib_dir}/libwxmsw29ud_aui.a ${wxwidgets_lib_dir}/libwxmsw29ud_adv.a ${wxwidgets_lib_dir}/libwxmsw29ud_html.a ${wxwidgets_lib_dir}/libwxmsw29ud_core.a ${wxwidgets_lib_dir}/libwxbase29ud_xml.a ${wxwidgets_lib_dir}/libwxbase29ud_net.a ${wxwidgets_lib_dir}/libwxexpatd.a ${wxwidgets_lib_dir}/libwxbase29ud.a ${wxwidgets_lib_dir}/libwxpngd.a ${wxwidgets_lib_dir}/libwxjpegd.a ${wxwidgets_lib_dir}/libwxzlibd.a ${wxwidgets_lib_dir}/libwxtiffd.a)
		ELSE()
			target_link_libraries(TileMapObject ${wxwidgets_lib_dir}/libwxmsw29u_xrc.a ${wxwidgets_lib_dir}/libwxmsw29u_stc.a ${wxwidgets_lib_dir}/libwxmsw29u_richtext.a ${wxwidgets_lib_dir}/libwxmsw29u_propgrid.a ${wxwidgets_lib_dir}/libwxmsw29u_ribbon.a ${wxwidgets_lib_dir}/libwxmsw29u_aui.a ${wxwidgets_lib_dir}/libwxmsw29u_adv.a ${wxwidgets_lib_dir}/libwxmsw29u_html.a ${wxwidgets_lib_dir}/libwxmsw29u_core.a ${wxwidgets_lib_dir}/libwxbase29u_xml.a ${wxwidgets_lib_dir}/libwxbase29u_net.a ${wxwidgets_lib_dir}/libwxexpat.a ${wxwidgets_lib_dir}/libwxbase29u.a ${wxwidgets_lib_dir}/libwxpng.a ${wxwidgets_lib_dir}/libwxjpeg.a ${wxwidgets_lib_dir}/libwxzlib.a ${wxwidgets_lib_dir}/libwxtiff.a)
		ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)

		target_link_libraries(TileMapObject ws2_32 user32 opengl32 glu32)
	ELSE()
		target_link_libraries(TileMapObject ${sfml_lib_dir}/libsfml-audio.so ${sfml_lib_dir}/libsfml-graphics.so ${sfml_lib_dir}/libsfml-window.so ${sfml_lib_dir}/libsfml-network.so ${sfml_lib_dir}/libsfml-system.so)
		target_link_libraries(TileMapObject ${wxWidgets_LIBRARIES})
		target_link_libraries(TileMapObject ${GTK3_LIBRARIES})
	ENDIF(WIN32)
ENDIF()

#Linker files for the GD C++ Runtime extension
###
IF(EMSCRIPTEN)
	#Nothing.
ELSE()
	target_link_libraries(TileMapObject_Runtime GDCpp_Runtime)
	IF(WIN32)
		target_link_libraries(TileMapObject_Runtime ${sfml_lib_dir}/libsfml-audio.a ${sfml_lib_dir}/libsfml-graphics.a ${sfml_lib_dir}/libsfml-window.a ${sfml_lib_dir}/libsfml-network.a ${sfml_lib_dir}/libsfml-system.a)
		target_link_libraries(TileMapObject_Runtime ws2_32 user32 opengl32 glu32)
	ELSE()
		target_link_libraries(TileMapObject_Runtime ${sfml_lib_dir}/libsfml-audio.so ${sfml_lib_dir}/libsfml-graphics.so ${sfml_lib_dir}/libsfml-window.so ${sfml_lib_dir}/libsfml-network.so ${sfml_lib_dir}/libsfml-system.so)
	ENDIF(WIN32)
ENDIF()