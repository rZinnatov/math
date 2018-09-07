cmake_minimum_required(VERSION 2.6)
project(math)

set(CMAKE_C_COMPILER "${COMPILER}gcc")
set(CMAKE_CXX_COMPILER "${COMPILER}g++")

add_subdirectory(Combinatorics)
add_subdirectory(ZZTest)

add_executable(math
    main.cpp
)

target_link_libraries(math
    zz-test
    zz-math-combinatorics
)

set_target_properties(math
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
)