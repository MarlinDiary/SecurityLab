cmake_minimum_required(VERSION 3.20)

project(SecurityLab C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(notebook_lite "notebook lite/main.c")

set_target_properties(notebook_lite PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_BINARY_DIR}/bin"
)

if (CMAKE_STRIP AND NOT CMAKE_STRIP MATCHES "NOTFOUND")
    add_custom_command(TARGET notebook_lite POST_BUILD
        COMMAND "${CMAKE_STRIP}" "$<TARGET_FILE:notebook_lite>"
        VERBATIM
    )
endif()

if (MSVC)
    target_compile_options(notebook_lite PRIVATE /W4 /Od)
else()
    target_compile_options(notebook_lite PRIVATE -Wall -Wextra -pedantic -O0)
endif()
