cmake_minimum_required(VERSION 3.20)

set(THIS_PROJECT_NAME        "CPP")
set(THIS_PROJECT_VERSION     "0.0.1")
set(THIS_PROJECT_LANGUAGES   "CXX" "C")
set(THIS_PROJECT_DESCRIPTION "Curated list of C++ projects")

project(${THIS_PROJECT_NAME}
    VERSION     ${THIS_PROJECT_VERSION}
    DESCRIPTION ${THIS_PROJECT_DESCRIPTION}
    LANGUAGES   ${THIS_PROJECT_LANGUAGES}
)

add_subdirectory(pwd)
add_subdirectory(fmt)
add_subdirectory(timer)