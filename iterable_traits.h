#ifndef CPP_INTERNAL_DETAILS_ITERABLE_TRAITS
#define CPP_INTERNAL_DETAILS_ITERABLE_TRAITS 1

#include <iterator>
#include <type_traits>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

namespace detail {
    // meta function for checking if the template argument is iterable or not
    // here iterable means the template argument can be applied std::begin() and std::end()
    template <class T, typename = void>
    struct is_iterable : std::false_type {};

    template <class T>
    struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())), decltype(std::end(std::declval<T>()))>> : std::true_type {};

    template <class T>
    constexpr bool is_iterable_v = is_iterable<T>::value;

    // meta function for checking if the template argument is std::vector<T>
    template <class T>
    struct is_vector : std::false_type {};

    template <class T>
    struct is_vector<std::vector<T>> : std::true_type {};

    template <class T>
    constexpr bool is_vector_v = is_vector<T>::value;

    // meta function for checking if the template argument is std::list<T>
    template <class T>
    struct is_list : std::false_type {};

    template <class T>
    struct is_list<std::list<T>> : std::true_type {};

    template <class T>
    constexpr bool is_list_v = is_list<T>::value;

    // meta function for checking if the template argument is std::forward_list<T>
    template <class T>
    struct is_forward_list : std::false_type {};

    template <class T>
    struct is_forward_list<std::forward_list<T>> : std::true_type {};

    template <class T>
    constexpr bool is_forward_list_v = is_forward_list<T>::value;

    // meta function for checking if the template argument is std::deque<T>
    template <class T>
    struct is_deque : std::false_type {};

    template <class T>
    struct is_deque<std::deque<T>> : std::true_type {};

    template <class T>
    constexpr bool is_deque_v = is_deque<T>::value;

    // meta function for checking if the template argument is std::set<T>
    template <class T>
    struct is_set : std::false_type {};

    template <class T>
    struct is_set<std::set<T>> : std::true_type {};

    template <class T>
    constexpr bool is_set_v = is_set<T>::value;

    // meta function for checking if the template argument is std::multiset<T>
    template <class T>
    struct is_multiset : std::false_type {};

    template <class T>
    struct is_multiset<std::multiset<T>> : std::true_type {};

    template <class T>
    constexpr bool is_multiset_v = is_multiset<T>::value;

    // meta function for checking if the template argument is std::unordered_set<T>
    template <class T>
    struct is_unordered_set : std::false_type {};

    template <class T>
    struct is_unordered_set<std::unordered_set<T>> : std::true_type {};

    template <class T>
    constexpr bool is_unordered_set_v = is_unordered_set<T>::value;

    // meta function for checking if the template argument is std::unordered_multiset<T>
    template <class T>
    struct is_unordered_multiset : std::false_type {};

    template <class T>
    struct is_unordered_multiset<std::unordered_multiset<T>> : std::true_type {};

    template <class T>
    constexpr bool is_unordered_multiset_v = is_unordered_multiset<T>::value;

    // meta function for checking if the template argument is std::map<K, V>
    template <class T>
    struct is_map : std::false_type {};

    template <class K, class V>
    struct is_map<std::map<K, V>> : std::true_type {};

    template <class T>
    constexpr bool is_map_v = is_map<T>::value;

    // meta function for checking if the template argument is std::multimap<K, V>
    template <class T>
    struct is_multimap : std::false_type {};

    template <class K, class V>
    struct is_multimap<std::multimap<K, V>> : std::true_type {};

    template <class T>
    constexpr bool is_multimap_v = is_multimap<T>::value;

    // meta function for checking if the template argument is std::unordered_map<K, V>
    template <class T>
    struct is_unordered_map : std::false_type {};

    template <class K, class V>
    struct is_unordered_map<std::unordered_map<K, V>> : std::true_type {};

    template <class T>
    constexpr bool is_unordered_map_v = is_unordered_map<T>::value;

    // meta function for checking if the template argument is std::unordered_multimap<K, V>
    template <class T>
    struct is_unordered_multimap : std::false_type {};

    template <class K, class V>
    struct is_unordered_multimap<std::unordered_multimap<K, V>> : std::true_type {};

    template <class T>
    constexpr bool is_unordered_multimap_v = is_unordered_multimap<T>::value;
}

#endif
