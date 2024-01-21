#include "BitSet.h"

namespace Ricardo {

BitSet::BitSet(uint32_t n) { Set.resize((n + 32 - 1) / 32); }
void BitSet::BitSetAdd(int val) { Set[val / 32] |= 1 << (val % 32); }
void BitSet::BitSetRemove(int val) { Set[val / 32] &= ~(1 << (val % 32)); }
void BitSet::BitSetReverse(int val) { Set[val / 32] ^= 1 << (val % 32); }
bool BitSet::BitSetContains(int val) {
  return (Set[val / 32] >> (val % 32) & 1) == 1;
}

int BitOperator::BitAdd(int a, int b) {
  int ans = a;
  /**
   *  a = 9, b=8
   *  a = 1001
   *  b = 1000
   *  ans = a^b = 0001
   *  b = (a&b)<<1 = 1000<<1 = 10000
   *
   *  a = 00001
   *  b = 10000
   *  ans = 10001
   *  b = 00000
   */
  while (b) {
    // ans: a与b的无进位相加
    ans = a ^ b;
    // b成为a与b相加的进位信息
    b = (a & b) << 1;
    a = ans;
  }
  return ans;
}
int BitAdd(int a, int b) {
  int ans = a;
  while (b) {
    ans = a ^ b;
    b = (a & b) << 1;
    a = ans;
  }
  return ans;
}
/*
 * a = 15, b = 12
 * a = 1111, BitNeg(b) = 0100
 *
 */
int BitOperator::BitMinus(int a, int b) { return BitAdd(a, BitNeg(b)); }
/*
 *  n = 12
 *  n = 000...1100
 *  ~n = 111...0011
 *  return (111...0100)
 */
int BitOperator::BitNeg(int n) { return BitAdd(~n, (int)1); }
// 乘法
int BitOperator::BitMultiply(int a, int b) {
  int x = a > 0 ? a : BitNeg(a);
  int y = b > 0 ? b : BitNeg(b);
  uint64_t ans = 0;
  while (y != 0) {
    if ((y & 1) != 0) {
      ans = BitAdd(ans, x);
    }
    x <<= 1;
    y >>= 1;
  }
  ans >= INT_MAX ? INT_MAX : ans;
  return a > 0 ^ b > 0 ? BitNeg((int)ans) : (int)ans;
}

// 除法
int BitOperator::BitDived(int a, int b) {
  // a和b都是整数最小值，相除为1
  if (a == INT_MIN && b == INT_MIN) return 1;
  // a和b都不是整数最小，正常相除
  if (a != INT_MIN && b != INT_MIN) return BitDiv(a, b);
  // b是整数最小，无论a是多少，结果都是0
  if (b == INT_MIN) return 0;
  // a是整数最小但b是-1
  if (b == BitNeg(1)) return INT_MAX;
  // a是整数最小，b不是整数最小也不是-1
  a = BitAdd(a, b > 0 ? b : BitNeg(b));
  int ans = BitDiv(a, b);
  int offset = b > 0 ? BitNeg(1) : 1;
  return BitAdd(ans, offset);
}
int BitOperator::BitDiv(int a, int b) {
  int x = a < 0 ? BitNeg(a) : a;
  int y = b < 0 ? BitNeg(b) : b;
  int ans = 0;
  for (int i = 30; i >= 0; i = BitMinus(i, 1)) {
    if ((x >> i) >= y) {
      ans |= 1 << i;
      x = BitMinus(x, (y << i));
    }
  }
  return a < 0 ^ b < 0 ? BitNeg(ans) : ans;
}

}  // namespace Ricardo
