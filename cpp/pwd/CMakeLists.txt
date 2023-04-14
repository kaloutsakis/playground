add_executable(pwd)

target_sources(pwd 
    PRIVATE main.cpp
)

target_compile_options(pwd
    PRIVATE -std=c++14
)