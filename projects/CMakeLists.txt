cmake_minimum_required(VERSION 3.2...3.27.5)

project(multi_proj_2023)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(bubble_sort)
add_subdirectory(bubble_sort_mf)
add_subdirectory(selection_sort)
add_subdirectory(obuchaika)
add_subdirectory(unit_test_example)
add_subdirectory(scl)

set(CMAKE_SUPPRESS_REGENERATION true)
