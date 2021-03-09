cmake_minimum_required(VERSION 3.8)

set(CMAKE_TOOLCHAIN_FILE "common/demos/cmake/config-pc-gcc.cmake")
set(CMAKE_BUILD_TYPE     "Release")

project(test)

find_package(demos REQUIRED)

add_executable(test
	src/main.cpp
)

target_link_libraries(test
	PRIVATE
	demos::kernel
)

setup_target(test)
