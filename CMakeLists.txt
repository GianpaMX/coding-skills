cmake_minimum_required(VERSION 3.27)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(CodingSkills)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(DataStructures)
add_subdirectory(app)
