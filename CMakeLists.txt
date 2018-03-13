cmake_minimum_required (VERSION 3.2) # If your CMake version is older, try modifying this line
project(BoyerMoore)

add_definitions(-std=c++1z -g)

########## Create libraries
add_library(RandomMatrixHashLib RandomMatrixHash.cpp)

########## Link GoogleTest
include_directories($ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/gtest/mybuild)

########## Sanity Checks
add_executable(RandomMatrixHashSanityTest RandomMatrixSanityCheck.cpp)
target_link_libraries(RandomMatrixHashSanityTest gtest)
target_link_libraries(RandomMatrixHashSanityTest pthread)
target_link_libraries(RandomMatrixHashSanityTest RandomMatrixHashLib)
