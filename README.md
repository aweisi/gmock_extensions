# gmock_extensions
support mocking free functions without boilerplate code

# build and run tests
- generate project/make files  
`cmake -DBUILD_TESTING=1 –DCMAKE_BUILD_TYPE=Release -S <path/to/test> -B <path/to/build>`  
- build  
`cmake –-build <./path/to/build> --config Release`  
- run tests  
`cmake -E chdir <./path/to/build> ctest –C Release`  

example:  
- `cmake -DBUILD_TESTING=1 -DCMAKE_BUILD_TYPE=Release -S ./examples -B ./build`  
- `cmake --build ./build --config Release`  
- `cmake -E chdir ./build ctest –C Release`  
# examples
examples/example_tests.cpp contains many examples

# integration

gmockExtensions.cmake provide a two cmake functions 1st `add_cxx_test` which create a cmake target  

include `gmock_extensions.cpp` in the test for usage.
  
example:  
`add_cxx_test(NAME extension_tests FILES <files under test>)`  
  
and the 2nd function is `unittest_project()` which has to be called once in main CMakeLists.txt.  
examples/CMakeLists.txt

# platforms
- windows (MSVC, GCC)
- linux (GCC, clang)