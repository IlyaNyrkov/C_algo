build_test:
	mkdir build
	cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make ..

rebuild_test:
	cd test/cmake-build-debug && make

#data structures
# --gtest_filter=<test_suite>.<test_name> run specific test
# valgrind shows 245 allocs, 245 frees, 116,304 bytes, which allocates gtest even if there is no tests
test_dynamic_array_valgrind:
	valgrind -s ./test/cmake-build-debug/TEST_DYNAMIC_ARRAY

test_linked_list_valgrind:
	valgrind -s ./test/cmake-build-debug/TEST_LINKED_LIST

test_hash_table_valgrind:
	valgrind -s --leak-check=full ./test/cmake-build-debug/TEST_HASH_TABLE

test_bit_array_valgrind:
	valgrind -s --leak-check=full  ./test/cmake-build-debug/TEST_BIT_ARRAY


clean:
	rm -r cmake-build-debug