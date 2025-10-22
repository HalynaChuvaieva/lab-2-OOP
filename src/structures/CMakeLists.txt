cmake_minimum_required(VERSION 3.16)
project(MyQtApp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "C:/Qt/6.9.3/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(MyQtApp main.cpp)
target_link_libraries(MyQtApp Qt6::Widgets)
