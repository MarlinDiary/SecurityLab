cmake_minimum_required(VERSION 3.20)

project(SecurityLab C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

function(configure_lab_target target_name source_file)
    add_executable(${target_name} "${source_file}")

    set_target_properties(${target_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_BINARY_DIR}/bin"
    )

    if (CMAKE_STRIP AND NOT CMAKE_STRIP MATCHES "NOTFOUND")
        add_custom_command(TARGET ${target_name} POST_BUILD
            COMMAND "${CMAKE_STRIP}" "$<TARGET_FILE:${target_name}>"
            VERBATIM
        )
    endif()

    if (MSVC)
        target_compile_options(${target_name} PRIVATE /W4 /Od)
    else()
        target_compile_options(${target_name} PRIVATE -Wall -Wextra -pedantic -O0)
    endif()
endfunction()

configure_lab_target(notebook_lite "notebook lite/main.c")
configure_lab_target(notebook_pro "notebook pro/main.c")
target_sources(notebook_pro PRIVATE "notebook pro/noise_bank.c")
