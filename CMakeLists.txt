cmake_minimum_required(VERSION 3.18)

project(PathFinder)

find_package(Threads REQUIRED)

file(GLOB_RECURSE source_files CONFIGURE_DEPENDS
    src/*.cpp
    src/*.h
    src/*.hpp
    src/*.cxx
    src/*.hxx
    src/*.cc
    src/*.hh
)
add_library(PathFinder ${source_files})

target_compile_features(PathFinder PUBLIC cxx_std_17)
target_include_directories(PathFinder PUBLIC src)
target_compile_definitions(PathFinder PUBLIC "PROJECT_DIR_PATH=\"${CMAKE_SOURCE_DIR}\"")

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(PathFinder PUBLIC /W3 /MP /permissive-)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(PathFinder PUBLIC -Wall -fpermissive)
else()
    target_compile_options(PathFinder PUBLIC -Wall)
endif()

target_link_libraries(PathFinder PUBLIC Threads::Threads)

file(GLOB_RECURSE app_files CONFIGURE_DEPENDS
    app/*.cpp
    app/*.h
    app/*.hpp
    app/*.cxx
    app/*.hxx
    app/*.cc
    app/*.hh
)
add_executable(PathFinderApp ${app_files})

target_link_libraries(PathFinderApp PRIVATE PathFinder)
set_target_properties(PathFinderApp PROPERTIES RUNTIME_OUTPUT_NAME "PathFinder")
