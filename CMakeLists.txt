cmake_minimum_required(VERSION 3.23)
project(P3)

set(CMAKE_CXX_STANDARD 17)

add_executable(P3 main.cpp
        city.h
        country.h
        cityGraph.h
        fetchData.h)
