#pragma once
#include <limits.h>

#include <bitset>
#include <vector>

namespace Ricardo {
/*位图*/
class BitSet {
 public:
  std::vector<int> Set = {0};
  // 设置位图大小
  BitSet(uint32_t n = 1);
  // 添加数
  void BitSetAdd(int val);
  // 删除数
  void BitSetRemove(int val);
  // 有就删除，没有就添加
  void BitSetReverse(int val);
  // 检查val值是否存在
  bool BitSetContains(int val);
};
/// @brief bit位运算
class BitOperator {
 public:
  // 加法¨
  static int BitAdd(int a, int b);
  // 减法
  static int BitMinus(int a, int b);
  // 乘法¨
  static int BitMultiply(int a, int b);
  // 除法
  static int BitDived(int a, int b);
  static int BitDiv(int a, int b);

 private:
  static int BitNeg(int n);
};
}  // namespace Ricardo
