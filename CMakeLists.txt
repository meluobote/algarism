cmake_minimum_required(VERSION 3.15)
project(algarism)

set(CMAKE_CXX_STANDARD 11)

add_executable(algarism main.cpp)
add_executable(fibonacci dynamicPro/fibonacci.cpp)
add_executable(BestTaskDeploy dynamicPro/BestTaskDeploy.cpp)
add_executable(longestIncreasingSubSequence dynamicPro/longestIncreasingSubSequence.cpp)
add_executable(longestCommonSubSequence dynamicPro/longestCommonSubSequence.cpp)
add_executable(RodCutting dynamicPro/RodCutting.cpp)
add_executable(singleLinkedListHuiWenVertify LinkedList/singleLinkedListHuiWenVertify.cpp)
add_executable(yueSeFuHuan LinkedList/yueSeFuHuan.cpp)
add_executable(addSubMulDiv stack/addSubMulDiv.cpp)