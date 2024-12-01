cmake_minimum_required(VERSION 3.31.0)
project(recipes)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

add_executable(recipes main.cpp src/ingredients/ingredient.cpp src/nutritional_information.cpp src/recipe_manager.cpp src/recipe.cpp src/review.cpp src/unit.cpp)