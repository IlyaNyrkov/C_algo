build_test:
	mkdir build
	cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make

rebuild_test:
	cd build && make

test_dynamic_array_valgrind:
	valgrind -s ./test/cmake-build-debug/TEST_DYNAMIC_ARRAY

test_linked_list_valgrind:
	valgrind -s ./test/cmake-build-debug/TEST_LINKED_LIST

clean:
	rm -r build