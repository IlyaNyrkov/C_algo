#include "gtest/gtest.h"
extern "C" {
    #include "bit_array.h"
}

TEST(bit_array, create_bit_array) {
    bit_array* b_array = create_bit_array(10);
    free_bit_array(b_array);
    ASSERT_TRUE(1);
}