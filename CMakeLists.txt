cmake_minimum_required(VERSION 3.20)
project(Alrgorithm)

set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/include/Algorithm)
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(ALG alg)
set(MALG malg)

set(NAME_BINARYTREE binaryTree)
set(NAME_BIT bitset)
set(NAME_LIST listnode)
set(NAME_RAND random)
set(NAME_AMT amount)


add_subdirectory(Algorithm)
add_subdirectory(Basefile)
add_subdirectory(test)

