build_test:
	mkdir build
	cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make

test_dynamic_array_valgrind:
	valgrind ./test/cmake-build-debug/TEST_DYNAMIC_ARRAY

test_linked_list_valgrind:
	valgrind ./test/cmake-build-debug/TEST_LINKED_LIST

clear_test:
	rm -r build