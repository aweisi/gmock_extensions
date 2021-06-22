cmake_minimum_required(VERSION 3.16.0)

include_guard(GLOBAL)

set(CUR_FILE_DIR ${CMAKE_CURRENT_LIST_DIR})

macro(unittest_project)
  if(BUILD_TESTING)
    enable_testing()
    include(GoogleTest)
    if(NOT TARGET gmock)
          add_subdirectory(${CUR_FILE_DIR}/googletest gtest)
          set_target_properties(gtest gtest_main gmock_main PROPERTIES EXCLUDE_FROM_ALL ON
                                                                      EXCLUDE_FROM_DEFAULT_BUILD ON
                                                                      )
    endif()
    if(NOT TARGET gtest_main_extension)
          add_library(gtest_main_extension ${CUR_FILE_DIR}/extensions/gtest_main.cpp)
          target_link_libraries(gtest_main_extension PUBLIC gmock)
    endif()
  endif(BUILD_TESTING)
endmacro()

function(add_cxx_test)
  if(BUILD_TESTING)
    set(options  )
    set(oneValueArgs NAME)
    set(multiValueArgs FILES)
    cmake_parse_arguments(p "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    add_executable(${p_NAME} ${p_NAME}.cpp ${p_FILES})
    target_link_libraries(${p_NAME} PRIVATE gtest_main_extension)
    target_include_directories(${p_NAME} PRIVATE ${CUR_FILE_DIR}/extensions)

    gtest_discover_tests(${p_NAME}
                         EXTRA_ARGS --gtest_print_time=1 
                                   #--gtest_output=xml:Testing/Temporary/example_tests.xml
                         #TEST_PREFIX prefix
                         #TEST_SUFFIX suffix
    )
  endif(BUILD_TESTING)
endfunction()
