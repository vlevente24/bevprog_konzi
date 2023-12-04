cmake_minimum_required(VERSION 3.26)
project(bevprog_konzi)

set(CMAKE_CXX_STANDARD 17)

add_executable(bevprog_konzi main.cpp)
add_executable(bevprog_konzi_feladat bevprog_2122_v1.cpp)
add_executable(beugro0k beugro_2122_kincstar.cpp)
add_executable(beugro1k beugro_2122_1_kincstar.cpp)
add_executable(beugro2k beugro_2122_2_kincstar.cpp)

add_executable(beugro0 beugro_2122.cpp)
add_executable(beugro1 beugro_2122_1.cpp)
add_executable(beugro2 beugro_2122_2.cpp)
