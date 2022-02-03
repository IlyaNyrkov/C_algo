#include "gtest/gtest.h"

extern "C" {
    #include "linked_list.h"
}

TEST(int_linked_list, creating_list){
    linked_list* list = create_int_linked_list(10);
    ASSERT_EQ(list->data, 10);
    free_linked_list(list);
}

TEST(int_linked_list, push_back) {
    linked_list* list = create_int_linked_list(0);
    linked_list* iter = list;
    for (int i = 1; i < 10; ++i) {
        iter = push_back_lin_lst(i, iter);
    }
    linked_list* iter2 = list;
    for (int i = 0; i < 10; ++i) {
        ASSERT_EQ(iter2->data, i);
        iter2 = iter2->next;
    }
    free_linked_list(list);
}

TEST(int_linked_list, push_front_lin_lst) {
    linked_list* list = create_int_linked_list(0);
    linked_list* iter = list;
    for (int i = 1; i < 10; ++i) {
        iter = push_front_lin_lst(i, iter);
    }
    linked_list* iter2 = iter;
    for (int i = 9; i >=0; --i) {
        ASSERT_EQ(iter2->data, i);
        iter2 = iter2->next;
    }
    free_linked_list(iter);
}

void value_to_square(int *data) {
    *data = (*data) * (*data);
}

void print_int(int *data) {
    printf("%d ", *data);
}

TEST(int_linked_list, traverse_print) {
    linked_list* list = create_int_linked_list(0);
    linked_list* iter = list;
    for (int i = 1; i < 10; ++i) {
        iter = push_back_lin_lst(i, iter);
    }
    traverse_lin_lst(list, print_int);
    traverse_lin_lst(list, value_to_square);
    printf("\n");
    traverse_lin_lst(list, print_int);
    free_linked_list(list);
}