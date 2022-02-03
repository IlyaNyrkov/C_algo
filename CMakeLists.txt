cmake_minimum_required(VERSION 3.18)
project(C_Algo C)

set(CMAKE_C_STANDARD 11)

set(INT_LINKED_LIST
        data_structures/linked_list/linked_list.c
        data_structures/linked_list/linked_list.h
        )

add_executable(C_Algo main.c ${INT_LINKED_LIST})
