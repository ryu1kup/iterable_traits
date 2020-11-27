cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(iterable_traits
    LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "A header-only iterable traits library"
    )

add_library(iterable_traits INTERFACE)
add_library(iterable_traits::iterable_traits ALIAS iterable_traits)

target_compile_features(iterable_traits INTERFACE cxx_std_17)

target_include_directories(iterable_traits INTERFACE
    $<BUILD_INTERFACE: ${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    )


install(TARGETS iterable_traits
    EXPORT iterable_traits-config
    )

install(EXPORT iterable_traits-config
    NAMESPACE iterable_traits::
    DESTINATION lib/cmake/iterable_traits
    )

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include
    )
