build_test:
	mkdir build
	cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make ..

rebuild_test:
	cd test/cmake-build-debug && make

#data structures
test_dynamic_array_valgrind:
	valgrind -s ./test/cmake-build-debug/TEST_DYNAMIC_ARRAY

test_linked_list_valgrind:
	valgrind -s ./test/cmake-build-debug/TEST_LINKED_LIST

test_hash_table_valgrind:
	valgrind -s ./test/cmake-build-debug/TEST_HASH_TABLE

clean:
	rm -r build