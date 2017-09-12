cmake_minimum_required(VERSION 2.8.9)
project(Bench)

#	Adding compiler optimizations

#SET(CMAKE_C_COMPILER /usr/bin/clang)
#SET(CMAKE_CXX_COMPILER /usr/bin/clang++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 --std=c++14 -DNDEBUG")

#	Adding includes

include_directories(
		#"../ext/boost_1_64_0"
	"/usr/local/benchmark/include"
	"../contrib/OpenBLAS/"
)

#	Linking libraries

link_directories(
	"../contrib/OpenBLAS"
	"/usr/local/lib"
)
link_libraries(
	"benchmark"
	"pthread"
	"openblas"
)

#	Adding sources

file(GLOB_RECURSE SOURCES "../src/*.cpp")

add_executable(prog_source ${SOURCES})
