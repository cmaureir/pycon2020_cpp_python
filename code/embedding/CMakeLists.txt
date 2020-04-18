cmake_minimum_required(VERSION 3.1)

project(Embedding VERSION 1.0 LANGUAGES CXX)
add_executable(main main.cpp)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(main ${PYTHON_LIBRARIES})
