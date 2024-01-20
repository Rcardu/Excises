cmake_minimum_required(VERSION 3.20)
project(Alrgorithm)

#设置头文件搜索路径
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/include/Algorithm)
#设置可执行程序输出路径
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#设置库文件输出路径
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

#库名
set(ALG alg)
set(MALG malg)
#可执行程序名
set(NAME_BINARYTREE binaryTree)


#递归子目录
#add_subdirectory(Algorithm)
add_subdirectory(Basefile)
add_subdirectory(Test)

