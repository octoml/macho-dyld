cmake_minimum_required(VERSION 3.2)

project(macho-loader C CXX)
set(CMAKE_CXX_STANDARD 11)

set(TARGET macho_dyld)

add_definitions(-DUNSIGN_TOLERANT=1)

FILE(GLOB SRC src/*.cpp)
FILE(GLOB HDR include/*.h src/*.h)

add_library(${TARGET} SHARED ${SRC} ${HDR})

target_include_directories(${TARGET} PUBLIC "include")
