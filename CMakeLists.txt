cmake_minimum_required(VERSION 3.6)
project(NVG_REMOTE)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(cmake/TargetArch.cmake)
target_architecture(TARGET_ARCH)

message("Building for ${TARGET_ARCH}")


#set(CMAKE_FIND_DEBUG_MODE true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

find_package(SDL2 REQUIRED)
find_package(EGL REQUIRED)
find_package(OpenGLES2 REQUIRED)

# # Add STB libs
# add_library(stb_image INTERFACE)
# add_library(stb_ds INTERFACE)
# add_library(stb_rect_pack INTERFACE)
# #add_library(stb_image_write INTERFACE)
# #add_library(stb_image_resize INTERFACE)
# target_include_directories(stb_image INTERFACE thirdparty/stb)
# target_include_directories(stb_ds INTERFACE thirdparty/stb)
# target_include_directories(stb_rect_pack INTERFACE thirdparty/stb)
# #target_include_directories(stb_image_write INTERFACE thirdparty/stb)
# #target_include_directories(stb_image_resize INTERFACE thirdparty/stb)

# # Add jsmn
# add_library(jsmn INTERFACE)
# target_include_directories(jsmn INTERFACE thirdparty/jsmn)

# # Add Wren
# file(GLOB_RECURSE wren_sources thirdparty/wren/src/*.c)
# file(GLOB_RECURSE wren_headers thirdparty/wren/src/*.h)

# add_library(wren STATIC ${wren_sources} ${wren_headers})
# target_include_directories(wren PRIVATE thirdparty/wren/src/vm thirdparty/wren/src/optional)
# target_include_directories(wren PUBLIC thirdparty/wren/src/include)
# target_link_libraries(wren m)

# if (CMAKE_BUILD_TYPE STREQUAL "Debug")
#   target_compile_definitions(wren PRIVATE DEBUG)
# endif()

# # Add zip
# add_subdirectory(thirdparty/zip)

# Add Nanovg
file(GLOB_RECURSE nanovg_sources thirdparty/nanovg/src/*.c)
file(GLOB_RECURSE nanovg_headers thirdparty/nanovg/src/*.h)
add_library(nanovg STATIC ${nanovg_sources} ${nanovg_headers})
target_include_directories(nanovg PUBLIC thirdparty/nanovg/src)

# The main program
add_executable(client src/nvgr_common.h src/client.c src/nvgr_client.c src/nvgr_client.h)
add_executable(server src/nvgr_common.h src/server.c src/nvgr_server.c src/nvgr_server.h) 
target_include_directories(server PUBLIC thirdparty/nanovg/src)
#target_include_directories(superstation PRIVATE include)
target_link_libraries(client PRIVATE EGL::EGL OpenGLES2::OpenGLES2 SDL2::Main nanovg m)
target_link_libraries(server PRIVATE m)