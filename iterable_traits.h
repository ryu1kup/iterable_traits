#ifndef CPP_ITERABLE_TRAITS_H
#define CPP_ITERABLE_TRAITS_H 1

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
#include <array>

namespace iterable {
    // meta function for checking if the template argument is iterable or not
    template <class T, typename = void>
    struct is_iterable : std::false_type {};

    template <class T>
    struct is_iterable<
        T,
        std::void_t<decltype(std::begin(std::declval<T&>()) != std::end(std::declval<T&>())),
                    decltype(++std::begin(std::declval<T&>())),
                    decltype(*std::begin(std::declval<T&>()))>> : std::true_type {};

    template <class T> struct is_iterable<const T> : public is_iterable<T> {};
    template <class T> struct is_iterable<volatile const T> : public is_iterable<T> {};
    template <class T> struct is_iterable<volatile T> : public is_iterable<T> {};

    template <class T>
    constexpr bool is_iterable_v = is_iterable<T>::value;

    // meta function for checking if the template argument is std::vector<T>
    template <class T>
    struct is_vector : std::false_type {};

    template <class T>
    struct is_vector<std::vector<T>> : std::true_type {};

    template <class T> struct is_vector<const T> : public is_vector<T> {};
    template <class T> struct is_vector<volatile const T> : public is_vector<T> {};
    template <class T> struct is_vector<volatile T> : public is_vector<T> {};

    template <class T>
    constexpr bool is_vector_v = is_vector<T>::value;

    // meta function for checking if the template argument is std::list<T>
    template <class T>
    struct is_list : std::false_type {};

    template <class T>
    struct is_list<std::list<T>> : std::true_type {};

    template <class T> struct is_list<const T> : public is_list<T> {};
    template <class T> struct is_list<volatile const T> : public is_list<T> {};
    template <class T> struct is_list<volatile T> : public is_list<T> {};

    template <class T>
    constexpr bool is_list_v = is_list<T>::value;

    // meta function for checking if the template argument is std::forward_list<T>
    template <class T>
    struct is_forward_list : std::false_type {};

    template <class T>
    struct is_forward_list<std::forward_list<T>> : std::true_type {};

    template <class T> struct is_forward_list<const T> : public is_forward_list<T> {};
    template <class T> struct is_forward_list<volatile const T> : public is_forward_list<T> {};
    template <class T> struct is_forward_list<volatile T> : public is_forward_list<T> {};

    template <class T>
    constexpr bool is_forward_list_v = is_forward_list<T>::value;

    // meta function for checking if the template argument is std::deque<T>
    template <class T>
    struct is_deque : std::false_type {};

    template <class T>
    struct is_deque<std::deque<T>> : std::true_type {};

    template <class T> struct is_deque<const T> : public is_deque<T> {};
    template <class T> struct is_deque<volatile const T> : public is_deque<T> {};
    template <class T> struct is_deque<volatile T> : public is_deque<T> {};

    template <class T>
    constexpr bool is_deque_v = is_deque<T>::value;

    // meta function for checking if the template argument is std::set<T>
    template <class T>
    struct is_set : std::false_type {};

    template <class T>
    struct is_set<std::set<T>> : std::true_type {};

    template <class T> struct is_set<const T> : public is_set<T> {};
    template <class T> struct is_set<volatile const T> : public is_set<T> {};
    template <class T> struct is_set<volatile T> : public is_set<T> {};

    template <class T>
    constexpr bool is_set_v = is_set<T>::value;

    // meta function for checking if the template argument is std::multiset<T>
    template <class T>
    struct is_multiset : std::false_type {};

    template <class T>
    struct is_multiset<std::multiset<T>> : std::true_type {};

    template <class T> struct is_multiset<const T> : public is_multiset<T> {};
    template <class T> struct is_multiset<volatile const T> : public is_multiset<T> {};
    template <class T> struct is_multiset<volatile T> : public is_multiset<T> {};

    template <class T>
    constexpr bool is_multiset_v = is_multiset<T>::value;

    // meta function for checking if the template argument is std::unordered_set<T>
    template <class T>
    struct is_unordered_set : std::false_type {};

    template <class T>
    struct is_unordered_set<std::unordered_set<T>> : std::true_type {};

    template <class T> struct is_unordered_set<const T> : public is_unordered_set<T> {};
    template <class T> struct is_unordered_set<volatile const T> : public is_unordered_set<T> {};
    template <class T> struct is_unordered_set<volatile T> : public is_unordered_set<T> {};

    template <class T>
    constexpr bool is_unordered_set_v = is_unordered_set<T>::value;

    // meta function for checking if the template argument is std::unordered_multiset<T>
    template <class T>
    struct is_unordered_multiset : std::false_type {};

    template <class T>
    struct is_unordered_multiset<std::unordered_multiset<T>> : std::true_type {};

    template <class T> struct is_unordered_multiset<const T> : public is_unordered_multiset<T> {};
    template <class T> struct is_unordered_multiset<volatile const T> : public is_unordered_multiset<T> {};
    template <class T> struct is_unordered_multiset<volatile T> : public is_unordered_multiset<T> {};

    template <class T>
    constexpr bool is_unordered_multiset_v = is_unordered_multiset<T>::value;

    // meta function for checking if the template argument is std::map<K, V>
    template <class T>
    struct is_map : std::false_type {};

    template <class K, class V>
    struct is_map<std::map<K, V>> : std::true_type {};

    template <class T> struct is_map<const T> : public is_map<T> {};
    template <class T> struct is_map<volatile const T> : public is_map<T> {};
    template <class T> struct is_map<volatile T> : public is_map<T> {};

    template <class T>
    constexpr bool is_map_v = is_map<T>::value;

    // meta function for checking if the template argument is std::multimap<K, V>
    template <class T>
    struct is_multimap : std::false_type {};

    template <class K, class V>
    struct is_multimap<std::multimap<K, V>> : std::true_type {};

    template <class T> struct is_multimap<const T> : public is_multimap<T> {};
    template <class T> struct is_multimap<volatile const T> : public is_multimap<T> {};
    template <class T> struct is_multimap<volatile T> : public is_multimap<T> {};

    template <class T>
    constexpr bool is_multimap_v = is_multimap<T>::value;

    // meta function for checking if the template argument is std::unordered_map<K, V>
    template <class T>
    struct is_unordered_map : std::false_type {};

    template <class K, class V>
    struct is_unordered_map<std::unordered_map<K, V>> : std::true_type {};

    template <class T> struct is_unordered_map<const T> : public is_unordered_map<T> {};
    template <class T> struct is_unordered_map<volatile const T> : public is_unordered_map<T> {};
    template <class T> struct is_unordered_map<volatile T> : public is_unordered_map<T> {};

    template <class T>
    constexpr bool is_unordered_map_v = is_unordered_map<T>::value;

    // meta function for checking if the template argument is std::unordered_multimap<K, V>
    template <class T>
    struct is_unordered_multimap : std::false_type {};

    template <class K, class V>
    struct is_unordered_multimap<std::unordered_multimap<K, V>> : std::true_type {};

    template <class T> struct is_unordered_multimap<const T> : public is_unordered_multimap<T> {};
    template <class T> struct is_unordered_multimap<volatile const T> : public is_unordered_multimap<T> {};
    template <class T> struct is_unordered_multimap<volatile T> : public is_unordered_multimap<T> {};

    template <class T>
    constexpr bool is_unordered_multimap_v = is_unordered_multimap<T>::value;

    // meta function for checking if the template argument is std::array<T, N>
    template <class T>
    struct is_array : std::false_type {};

    template <class T,  std::size_t N>
    struct is_array<std::array<T, N>> : std::true_type {};

    template <class T> struct is_array<const T> : public is_array<T> {};
    template <class T> struct is_array<volatile const T> : public is_array<T> {};
    template <class T> struct is_array<volatile T> : public is_array<T> {};

    template <class T>
    constexpr bool is_array_v = is_array<T>::value;
}

#endif
