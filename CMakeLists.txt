cmake_minimum_required(VERSION 3.27)
project(recipes)

set(CMAKE_CXX_STANDARD 17)

add_executable(recipes main.cpp src/ingredient.cpp src/nutritional_information.cpp src/recipe.cpp
        src/unit.cpp
        include/unit.hpp
        include/review.cpp
        include/review.hpp)