cmake_minimum_required(VERSION 3.10)

project(RPC_Server)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_CXX_FLAGS -pthread)

set(CXX_FLAGS
-g
-DCHECK_PTHREAD_RETURN_VALUE
-Wall
-Wextra
-Wconversion
-Wno-unused-cast
-Woverloaded-virtual
-Wpointer-arith
-Wshadow
-WWrite-strings
)

set(CMAKE_CXX_COMPILER "g++")

include_directories("/home/lucky7/build/debug-install-cpp11/include")
link_directories("/home/lucky7/build/debug-install-cpp11/lib")
link_libraries(libmuduo_base.a libmuduo_net.a)

set(SRCFILE main.cpp server.cpp)
add_executable(demo ${SRCFILE})
