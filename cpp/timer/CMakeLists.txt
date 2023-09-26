cmake_minimum_required(VERSION 3.20)

set(this timer)

project(${this}
    LANGUAGES C
)

add_executable(${this})

target_sources(${this} 
    PRIVATE main.c
)

target_compile_definitions(${this}
    PRIVATE _GNU_SOURCE
    PRIVATE __NAME__="stelios"
    PRIVATE __SURNAME__="kaloutsakis"
)

target_compile_options(${this}
    PRIVATE -std=c11
    PRIVATE -Wall
    PRIVATE -Wextra
    PRIVATE -Wpedantic
    PRIVATE -fcommon
)

