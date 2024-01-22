#include <iostream>

#include "BitSet.h"

void test_bit() {
  uint32_t a = 11;
  uint32_t b = 17;
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "加法  " << Ricardo::BitOperator::BitAdd(a, b) << std::endl;
  std::cout << "减法  " << Ricardo::BitOperator::BitMinus(a, b) << std::endl;
  std::cout << "乘法  " << Ricardo::BitOperator::BitMultiply(a, b) << std::endl;
  std::cout << "除法  " << Ricardo::BitOperator::BitDived(a, b) << std::endl;
}

int main(int argc, char** argv) {
  test_bit();
  return 0;
}
