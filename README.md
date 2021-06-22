[![CMake](https://github.com/aweisi/gmock_extensions/actions/workflows/cmake.yml/badge.svg)](https://github.com/aweisi/gmock_extensions/actions/workflows/cmake.yml)

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

gmockExtensions.cmake provide two cmake functions 1st `add_cxx_test` which create a cmake target  
example:  
`add_cxx_test(NAME extension_tests FILES <files under test>)`  
  
and the 2nd function is `unittest_project()` which has to be called once in main CMakeLists.txt.  
examples/CMakeLists.txt

for usage in test cases include `gmock_extensions.hpp`.

# provided macros
free functions:
   - MOCK_FUNCTION  
        | position | name             |details
        |---       |---               |---
        | 1st      | ReturnType       | int or (std::pair<int,bool>) optional parentheses if type contains comma
        | 2nd      | FunctionName     | myFunctionName
        | 3rd      | Arguments        | (int, char *, uint16_t t) require parentheses
        | 4th      | Specs [OPTIONAL] | (noexcept) require parentheses if present
   - MOCK_FUNCTION_OVERLOAD
        | position | name             |details
        |---       |---               |---
        | 1st      | overloadId       | integer used as reference for particulare overload
        | 2nd      | ReturnType       | int or (std::pair<int,bool>) optional parentheses if type contains comma
        | 3rd      | FunctionName     | myFunctionName
        | 4th      | Arguments        | (int, char *, uint16_t t) require parentheses
        | 5th      | Specs [OPTIONAL] | (noexcept) require parentheses if present
 member function:
   - MOCK_CLASS_CTOR
   - MOCK_CLASS_DTOR
   - MOCK_CLASS_METHOD
   - MOCK_CLASS_METHOD_OVERLOAD
# platforms
- windows (MSVC, GCC)
- linux (GCC, clang)
