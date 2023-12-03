cmake_minimum_required(VERSION 3.26)
project(P3)

set(CMAKE_CXX_STANDARD 17)
##find_package(Qt5Widgets REQUIRED)
##set(CMAKE_PREFIX_PATH "C:/Qt/Tools/mingw1120_64")
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

add_executable(P3 main.cpp
        city.h
        roadtrip.h
        cityGraph.h
        fetchData.h
        disjointSet.h

        )
#target_link_libraries(P3 Qt5::Widgets)
