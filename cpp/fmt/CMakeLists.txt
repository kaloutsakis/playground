add_executable(fmt)

target_sources(fmt 
    PRIVATE main.c
)

target_compile_options(fmt
    PRIVATE -std=c11
    PRIVATE -Wall
    PRIVATE -Wextra
)

target_compile_definitions(fmt
    PRIVATE __USE_XOPEN_EXTENDED
)