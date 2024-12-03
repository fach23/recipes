cmake_minimum_required(VERSION 3.31.0)
project(recipes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(recipes ${SOURCES})

target_include_directories(recipes PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)