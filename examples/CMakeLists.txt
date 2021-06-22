cmake_minimum_required(VERSION 3.16)

include(${CMAKE_CURRENT_LIST_DIR}/../gmockExtensions.cmake)

project(example_tests_projects)

unittest_project()

add_cxx_test(NAME example_tests)
