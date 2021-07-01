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

# API and Macros
## free functions:
   - MOCK_FUNCTION  
        | position | name             |details
        |:---      |:---              |:---
        | 1st      | ReturnType       | int or (std::pair<int,bool>) optional parentheses if type contains comma
        | 2nd      | FunctionName     | myFunctionName
        | 3rd      | Arguments        | (int, char *, uint16_t t) require parentheses
        | 4th      | Specs [OPTIONAL] | (noexcept) require parentheses if present

     **Generate** the type `[FunctionName]_MOCK_TYPE` with the following static member functions:  
     - `[FunctionName]_MOCK_TYPE::create()` create naggy mock object
     - `[FunctionName]_MOCK_TYPE::createNice()` create nice mock object
     - `[FunctionName]_MOCK_TYPE::createStrict()` create strict mock object
   - MOCK_FUNCTION_OVERLOAD
        | position | name             |details
        |:---      |:---              |---
        | 1st      | overloadId       | integer used as reference for particulare overload
        | 2nd      | ReturnType       | int optional parentheses if type contains comma e.g.: or (std::pair<int,bool>)
        | 3rd      | FunctionName     | myFunctionName
        | 4th      | Arguments        | (int, char *, uint16_t t) require parentheses
        | 5th      | Specs [OPTIONAL] | (noexcept) require parentheses if present

     **Generate** the type `[FunctionName]_MOCK_TYPE[overloadId]` with the following static member functions:  
     - `[FunctionName]_MOCK_TYPE[overloadId]::create()` create naggy mock object
     - `[FunctionName]_MOCK_TYPE[overloadId]::createNice()` create nice mock object
     - `[FunctionName]_MOCK_TYPE[overloadId]::createStrict()` create strict mock object
## member function:
   - MOCK_CLASS_CTOR
   - MOCK_CLASS_DTOR
   - MOCK_CLASS_METHOD
   - MOCK_CLASS_METHOD_OVERLOAD

# integration
## cmake
gmockExtensions.cmake provide two cmake functions 1st `add_cxx_test` which create a cmake target  
example:  
`add_cxx_test(NAME extension_tests FILES <files under test>)`  
  
and the 2nd function is `unittest_project()` which has to be called once in main CMakeLists.txt.  
examples/CMakeLists.txt

## usage
```C++
// content of file external_api.h
extern "C"
{
    void external_fct( int );
}
```
```C++
// content of file unit_under_test.h
extern "C"
{
    void uut_fct( int a0 );
}
```
```C++
// content of file unit_under_test.c
#include "unit_under_test.h"
#include "external_api.h"
void uut_fct( int a0 )
{
     external_fct(a0);
}
```
```C++
// content of file test_1stTest.cpp
#include "gmock_extensions.hpp"
#include "unit_under_test.h"
#include "external_api.h"

// mock the external function using the macro MOCK_FUNCTION
// generate the type external_fct_MOCK_TYPE
MOCK_FUNCTION(void, external_fct, (int));

// create test
TEST( C_FUNCTIONS, simple_c_fct )
{
     // create desired mock type (naggy, strict or nice)
     auto  & naggyMockObj  = external_fct_MOCK_TYPE::Create( );
     // set expectation on the mock object
     EXPECT_CALL( naggyMockObj,  external_fct( 1 ) );
     // perform the test
     uut_fct(1);
}
```
for more examples see `examples/example_tests.cpp` contains many examples
# platforms
- windows (MSVC, GCC)
- linux (GCC, clang)
