cmake_minimum_required(VERSION 3.23)
project(P3)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp
        city.h
        country.h
        cityGraph.h
        fetchData.h)
add_executable(P3 ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(P3 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)


