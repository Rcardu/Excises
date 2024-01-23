
set(SRC 
  AmountData.cpp 
  AndCheckTheSet.cpp
  ArithmeticProgression.cpp
  DataStructPresonal.cpp
  )
include_directories(${HEAD_PATH})
set(LIBRARY_OUTPUT_PATH ${LIB_PATH})
add_library(${ALG} STATIC ${SRC})
