cmake_minimum_required(VERSION 3.14)
project(StructuralTestingLab CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE 
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(lab_tests
  Playlist.cpp
  Playlist_tests.cpp
)

target_link_libraries(lab_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(lab_tests)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(lab_tests PRIVATE --coverage)
    target_link_options(lab_tests PRIVATE --coverage)
endif()