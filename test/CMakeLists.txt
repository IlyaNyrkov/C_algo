cmake_minimum_required(VERSION 3.18)
project(Test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "-pthread  -Wall -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "-pthread -Wall -Werror -Wpedantic -fprofile-arcs -ftest-coverage")

set(INT_LINKED_LIST
        ../linked_list/int_linked_list.c
        ../linked_list/int_linked_list.h
        ../linked_list/int_linked_list_test.cpp
        )

set(INT_DYNAMIC_ARRAY
        ../dynamic_array/int_dynamic_array.c
        ../dynamic_array/int_dynamic_array.h
        ../dynamic_array/int_dynamic_array_test.cpp)

add_executable(TEST_ALGORITHMS
        main.cpp
        ${INT_LINKED_LIST}
        ${INT_DYNAMIC_ARRAY}
        ${GTEST_LIBRARIES}
        )

enable_testing()
find_package(GTest REQUIRED)
include_directories(&{GTEST_INCLUDE_DIR})
message(${GTEST_LIBRARIES})

target_link_libraries(TEST_ALGORITHMS ${GTEST_LIBRARIES})