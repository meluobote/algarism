cmake_minimum_required(VERSION 3.15)
project(algarism)

set(CMAKE_CXX_STANDARD 11)

add_executable(algarism main.cpp sort.cpp sort.h dynamicPro/CutRod.cpp dynamicPro/CutRod.h)
add_executable(fibonacci dynamicPro/fibonacci.cpp)
add_executable(BestTaskDeploy dynamicPro/BestTaskDeploy.cpp)
add_executable(singleLinkedListHuiWenVertify LinkedList/singleLinkedListHuiWenVertify.cpp)
add_executable(longestCommonSubSequence dynamicPro/longestCommonSubSequence.cpp)
add_executable(longestIncreasingSubSequence dynamicPro/longestIncreasingSubSequence.cpp)