add_library(zz-math-combinatorics
    Combinatorics.cpp
    TestCombinatorics.cpp
)

include_directories(${CMAKE_SOURCE_DIR})

target_link_libraries(zz-math-combinatorics
    zz-test
)