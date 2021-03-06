cmake_minimum_required(VERSION 3.15)
project(algarism)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
add_executable(DFSandBFS graph/DFSandBFS.cpp graph/Graph.cpp)
add_executable(eightQueen backTracking/eightQueen.cpp)
add_executable(binarySearch sortAndFind/binarySearch.cpp)
add_executable(binaryTree tree/binaryTree.cpp)
add_executable(O_n2 sortAndFind/O_n2.cpp)
add_executable(O_n sortAndFind/O_n.cpp)
add_executable(O_lgn sortAndFind/O_lgn.cpp)
add_executable(fibonacci dynamicPro/fibonacci.cpp)
add_executable(BestTaskDeploy dynamicPro/BestTaskDeploy.cpp)
add_executable(longestIncreasingSubSequence dynamicPro/longestIncreasingSubSequence.cpp)
add_executable(bag01 dynamicPro/bag01.cpp)
add_executable(backTrackBag01 backTracking/bag01.cpp)
add_executable(longestCommonSubSequence dynamicPro/longestCommonSubSequence.cpp)
add_executable(yangHuiSanJiao dynamicPro/yangHuiSanJiao.cpp)
add_executable(RodCutting dynamicPro/RodCutting.cpp)
add_executable(singleLinkedListHuiWenVertify LinkedList/singleLinkedListHuiWenVertify.cpp)
add_executable(yueSeFuHuan LinkedList/yueSeFuHuan.cpp)
add_executable(addSubMulDiv dataStruct/addSubMulDiv.cpp sortAndFind/O_lgn.cpp)
add_executable(pile dataStruct/pile.cpp)
add_executable(coinsForChange dynamicPro/coinsForChange.cpp)
add_executable(EditDistance dynamicPro/EditDistance.cpp)
add_executable(MatricsMultiply dynamicPro/MatricsMultiply.cpp)