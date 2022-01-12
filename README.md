# Some algorithms and datastructures implemented in C language and tested with Google testing framework
![](https://img.shields.io/badge/Code-C-informational?style=flat&logo=c&logoColor=white&color=2bbc8a)
![](https://img.shields.io/badge/Code-C++-informational?style=flat&logo=cplusplus&logoColor=white&color=2bbc8a)
![](https://img.shields.io/badge/Testing-Gtest-informational?style=flat&logo=textpattern&logoColor=white&color=2bbc8a)
![](https://img.shields.io/badge/Tools-CMake-informational?style=flat&logo=cmake&logoColor=white&color=2bbc8a)
# How to build and and run
You will need cmake, make, gcc, gtest, valgrind.
To build all test executables
```makefile
make build_test
```
To rebuild tes
```makefile
make rebuild_test
```
Clean build folder
```makefile
make clean
```
### Run tests with valgrind

run tests for dynamic array data structure
```makefile
make test_dynamic_array_valgrind
```
run tests for linked list data structure
```makefile
make test_linked_list_valgrind
```