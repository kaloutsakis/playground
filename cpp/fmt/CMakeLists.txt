add_executable(fmt)

target_sources(fmt 
    PRIVATE main.c
)

target_compile_definitions(fmt
    PRIVATE _GNU_SOURCE
    PRIVATE __NAME__="stelios"
    PRIVATE __SURNAME__="kaloutsakis"
)

target_compile_options(fmt
    PRIVATE -std=c11
    PRIVATE -Wall
    PRIVATE -Wextra
)

