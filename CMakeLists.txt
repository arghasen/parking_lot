cmake_minimum_required(VERSION 3.22)
project(parking_lot)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.10.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_GetProperties(googletest)
if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif ()

add_executable(parking_lot src/main.cpp)
enable_testing()

add_executable(
        parking_lot_test
        test/parking_lot.t.cpp
)
target_link_libraries(
        parking_lot_test
        gtest_main
        gmock
)
target_include_directories(parking_lot_test PRIVATE src)

include(GoogleTest)
gtest_discover_tests(parking_lot_test)