cmake_minimum_required(VERSION 2.8.4)
project(lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_executable(lab1 main.cpp Liczba_dwojkowa.cpp)
add_executable(lab2 main2.cpp okrag.cpp punkt.cpp)