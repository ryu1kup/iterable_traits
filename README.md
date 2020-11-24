# iterable_traits

simple header-only library providing iterable traits classes.

currently the following STL containers are supported:

- `std::vector`
- `std::list`
- `std::forward_list`
- `std::deque`
- `std::set`
- `std::multiset`
- `std::unordered_set`
- `std::unordered_multiset`

## installation

`iterable_traits.h` is a single file header-only library.
Simply place this file in your library path and you're ready to go.

## usage

```
#include "iterable_traits.h"
#include <vector>

int main(){
    std::vector<int> v {1, 2, 3, 4, 5};

    static_assert(detail::is_iterable<decltype(v)>::value);
    static_assert(detail::is_iterable_v<decltype(v)>);
    static_assert(detail::is_vector<decltype(v)>::value);
    static_assert(detail::is_vector_v<decltype(v)>);
}
```
