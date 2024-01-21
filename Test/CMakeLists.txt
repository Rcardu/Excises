include_directories(${HEAD_PATH})
set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})
link_directories(${LIB_PATH})

#link_libraries(${NAME_BINARYTREE} ${MALG})
add_executable(${NAME_BINARYTREE} BinaryTree_t.cc)
add_executable(${NAME_BIT} BitSet_t.cc)
add_executable(${NAME_LIST} ListProblem_t.cc)
add_executable(${NAME_RAND} RandNum_t.cc)

target_link_libraries(${NAME_BINARYTREE} ${MALG})
target_link_libraries(${NAME_BIT} ${MALG})
target_link_libraries(${NAME_LIST} ${MALG})
target_link_libraries(${NAME_RAND} ${MALG})
