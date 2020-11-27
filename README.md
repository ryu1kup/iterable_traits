# iterable_traits

Simple header-only library providing iterable traits classes.

The following STL containers are interpreted as "itearble" types:

- `std::vector`
- `std::list`
- `std::forward_list`
- `std::deque`
- `std::set`
- `std::multiset`
- `std::unordered_set`
- `std::unordered_multiset`
- `std::map`
- `std::multimap`
- `std::unordered_map`
- `std::unordered_multimap`
- `std::array`

In addition, your original class, which is an STL compatible container, is also interpreted as "iterable".

## requirement

This library uses "detection idiom" with `std::void_t`, so you need to use C++17.

## installation

### integration with CMake

`iterable_traits` can be installed with `cmake`.

```
mkdir build
cd build
cmake ..
cmake --build . --target install
```

then add the following line in the CMakeLists.txt of your project.

```
find_package(iterable_traits REQUIRED)

add_executable(your_project your_project.cpp)

target_link_libraries(your_project iterable_traits::iterable_traits)
```

### manual installation

`iterable_traits.h` is a single file header-only library.
Simply place this file in your library path and you're ready to go.

## usage
```
#include "iterable_traits.h"
#include <vector>

int main(){
    std::vector<int> v {1, 2, 3, 4, 5};

    static_assert(iterable_traits::is_iterable<decltype(v)>::value);
    static_assert(iterable_traits::is_iterable_v<decltype(v)>);
    static_assert(iterable_traits::is_vector<decltype(v)>::value);
    static_assert(iterable_traits::is_vector_v<decltype(v)>);
}
```
