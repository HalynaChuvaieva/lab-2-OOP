cmake_minimum_required(VERSION 3.16)
project(QtDataStructuresVisualizer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.3/mingw_64/lib/cmake" CACHE PATH "Qt path")
find_package(Qt6 COMPONENTS Widgets REQUIRED)
add_executable(QtDataStructuresVisualizer
src/main.cpp
src/MainWindow.h
src/MainWindow.cpp
src/VisualizationWidget.h
src/VisualizationWidget.cpp
src/Controller.h
src/Controller.cpp

src/structures/LinkedList.h
src/structures/LinkedList.cpp
src/structures/Queue.h
src/structures/Stack.h
src/structures/BST.h

src/StateManager.h
src/StateManager.cpp
)
target_link_libraries(QtDataStructuresVisualizer PRIVATE Qt6::Widgets)