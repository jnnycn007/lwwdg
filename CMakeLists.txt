cmake_minimum_required(VERSION 3.22)

# Setup project
project(LwLibPROJECT)

if(NOT PROJECT_IS_TOP_LEVEL)
    add_subdirectory(lwwdg)
else()
    enable_testing()
    add_executable(${CMAKE_PROJECT_NAME})
    target_sources(${CMAKE_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/dev/main.c
        ${CMAKE_CURRENT_LIST_DIR}/examples/example_win32.c
        ${CMAKE_CURRENT_LIST_DIR}/tests/test.c
    )
    target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/dev
    )

    # Add subdir with lwwdg and link to project
    set(LWWDG_OPTS_FILE ${CMAKE_CURRENT_LIST_DIR}/dev/lwwdg_opts.h)
    add_subdirectory(lwwdg)
    target_link_libraries(${CMAKE_PROJECT_NAME} lwwdg)

    # Add compile options to the library, which will propagate options to executable through public link
    target_compile_definitions(lwwdg PUBLIC WIN32 _DEBUG CONSOLE LWWDG_DEV)
    target_compile_options(lwwdg PUBLIC -Wall -Wextra -Wpedantic)

    # Add test
    add_test(NAME Test COMMAND $<TARGET_FILE:${CMAKE_PROJECT_NAME}>)
endif()
