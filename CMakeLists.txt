cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_FLAGS "-pthread -Wall -std=c++14 -pedantic ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "-fsanitize=address,undefined -D_GLIBCXX_DEBUG ${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_COVERAGE "-g --coverage")
set(LINK_FLAGS "-pthread ${LINK_FLAGS}")

include_directories(.)
add_subdirectory(gtest)

add_executable(test
        tests.cpp
        gtest/gtest_main.cc
        gtest/gtest-all.cc
        gtest/gtest.h
        counted.h
        counted.cpp)


