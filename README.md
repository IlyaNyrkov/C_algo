# Some algorithms and data structures implemented in C language and tested with Google testing framework
![](https://img.shields.io/badge/Code-C-informational?style=flat&logo=c&logoColor=white&color=2bbc8a)
![](https://img.shields.io/badge/Code-C++-informational?style=flat&logo=cplusplus&logoColor=white&color=2bbc8a)
![](https://img.shields.io/badge/Testing-Gtest-informational?style=flat&logo=textpattern&logoColor=white&color=2bbc8a)
![](https://img.shields.io/badge/Tools-CMake-informational?style=flat&logo=cmake&logoColor=white&color=2bbc8a)

# Links to files for each algorithm/data structure
## data structures
**<a href="https://github.com/IlyaNyrkov/C_algo/tree/master/data_structures/dynamic_array">Dynamic array</a>** </br>
**<a href="https://github.com/IlyaNyrkov/C_algo/tree/master/data_structures/linked_list">Linked list</a>** </br>
**<a href="https://github.com/IlyaNyrkov/C_algo/tree/master/data_structures/hash_table">Hash table</a>** </br>
**<a href="https://github.com/IlyaNyrkov/C_algo/tree/master/data_structures/bit_array">Bit array</a>** </br>
**<a href="https://github.com/IlyaNyrkov/C_algo/tree/master/data_structures/bloom_filter">Bloom filter</a>** </br>


# How to build and and run
You will need cmake, make, gcc, gtest, valgrind.
To build all test executables
```makefile
make build_test
```
To rebuild test
```makefile
make rebuild_test
```
Clean build folder
```makefile
make clean
```
### Run tests with valgrind 

run tests for data structure
```makefile
make test_<data_struct_name>_valgrind
```