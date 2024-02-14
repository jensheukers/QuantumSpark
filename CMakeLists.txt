cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_SUPPRESS_REGENERATION true) 
SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
SET (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH:NO")
SET (CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /SAFESEH:NO")

#------------------------------------------------------
#	Create new project
#------------------------------------------------------
project (QuantumSpark)

# Get Headers
file (GLOB ENGINE_HEADERS "engine/*.h" "engine/components/*.h" "engine/graphics/*h" "engine/math/*.h")

#------------------------------------------------------
#	Include directories
#------------------------------------------------------
include_directories(
	${CMAKE_SOURCE_DIR}/thirdparty/glfw/include
	${CMAKE_SOURCE_DIR}/thirdparty/glew/include
	${CMAKE_SOURCE_DIR}/thirdparty/freetype/include
	${CMAKE_SOURCE_DIR}/thirdparty/freetype/win32
	${CMAKE_SOURCE_DIR}/engine
)

link_directories (
	${CMAKE_SOURCE_DIR}/thirdparty/glfw/lib-vc2022 
	${CMAKE_SOURCE_DIR}/thirdparty/glew/lib/Release/Win32
	${CMAKE_SOURCE_DIR}/thirdparty/freetype/win32 
)

set ( ALL_LIBS
	opengl32.lib
	glfw3.lib 
	glfw3_mt.lib 
	glfw3dll.lib  
	glew32.lib 
	glew32s.lib
	freetype.lib	
)

#------------------------------------------------------
#	Add engine as library
#------------------------------------------------------
add_library(Engine
	engine/core.cpp
	engine/core.h
	engine/debug.h
	engine/debug.cpp
	engine/entity.h
	engine/entity.cpp
	engine/scene.h
	engine/scene.cpp
	engine/scenemanager.h
	engine/scenemanager.cpp
	
	engine/utilities.h
	
	engine/components/component.cpp
	engine/components/component.h
	
	engine/graphics/renderer.cpp
	engine/graphics/renderer.h

	engine/math/math.h
	engine/math/vector3.h
)

add_custom_command(TARGET Engine POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E make_directory
						$<TARGET_FILE_DIR:Engine>/shaders)

add_custom_command(TARGET Engine POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E copy_directory
						${CMAKE_SOURCE_DIR}/engine/shaders $<TARGET_FILE_DIR:Engine>/shaders)

add_custom_command(TARGET Engine POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E make_directory
						$<TARGET_FILE_DIR:Engine>/fonts)

add_custom_command(TARGET Engine POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E copy_directory
						${CMAKE_SOURCE_DIR}/engine/fonts $<TARGET_FILE_DIR:Engine>/fonts)
					
add_custom_command(TARGET Engine POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E copy
						${CMAKE_SOURCE_DIR}/thirdparty/glfw/lib-vc2022/glfw3.dll $<TARGET_FILE_DIR:Engine>)

add_custom_command(TARGET Engine POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E copy
						${CMAKE_SOURCE_DIR}/thirdparty/glew/bin/Release/Win32/glew32.dll $<TARGET_FILE_DIR:Engine>)

add_custom_command(TARGET Engine POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E copy
						${CMAKE_SOURCE_DIR}/thirdparty/freetype/win32/freetype.dll $<TARGET_FILE_DIR:Engine>)						
						
#------------------------------------------------------
#	GAME
#------------------------------------------------------
add_executable( Game
	game/main.cpp
)

target_link_libraries(Game
	Engine
	${ALL_LIBS}
)

target_include_directories( Game PUBLIC
	${CMAKE_SOURCE_DIR}/game
)

add_custom_command(TARGET Game POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E make_directory
						$<TARGET_FILE_DIR:Game>/res)

add_custom_command(TARGET Game POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E copy_directory
						${CMAKE_SOURCE_DIR}/game/res $<TARGET_FILE_DIR:Game>/res)