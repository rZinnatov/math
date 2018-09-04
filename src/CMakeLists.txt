cmake_minimum_required(VERSION 2.6)
project(math)

add_subdirectory(Combinatorics)

add_executable(math
    main.cpp
)

target_link_libraries(math
    zz-math-combinatorics
)

set_target_properties(math
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
)