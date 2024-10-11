cmake_minimum_required(VERSION 3.15...3.30)

project(
  AMerchantsQuest 
  VERSION 1.0.0
  DESCRIPTION "My Logic Formulation and Introductory Programming (CCIPROG1) machine program project." 
  LANGUAGES C CXX)

set(HEADER_DIR "../include")
set(CC_FLAGS "-Wall" "-Wextra" "-Wpedantic")
set(C_STD "c_std_99")
set(CXX_STD "cxx_std_14")

add_subdirectory(src)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

include(CTest)

enable_testing()

add_subdirectory(tests)
