cmake_minimum_required(VERSION 3.18)
project(C_Algo C)

set(CMAKE_C_STANDARD 11)

set(INT_LINKED_LIST
        linked_list/int_linked_list.c
        linked_list/int_linked_list.h
        )

add_executable(C_Algo main.c ${INT_LINKED_LIST})
