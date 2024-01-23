#pragma once
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace Ricardo {
/*随机数生成*/
template <class T>
class Random {
 private:
  void _Swap(int s1, int s2, std::vector<T>& arr) {
    int temp = arr[s1];
    arr[s1] = arr[s2];
    arr[s2] = temp;
  }

 public:
  // 生成随机数组
  std::vector<T> RandVector(int len, T range1, T range2, int times) {
    std::random_device r;
    std::vector<T> arr(len);
    std::default_random_engine e(r());
    if (typeid(T) == typeid(int)) {
      std::uniform_int_distribution<int> u(range1, range2);
      e.seed(time(0) + times);
      for (int i = 0; i < len; i++) {
        arr[i] = u(e);
      }

    } else {
      std::uniform_real_distribution<double> u(range1, range2);
      e.seed(time(0) + times);
      for (int i = 0; i < len; i++) {
        arr[i] = u(e);
      }
    }
    if (len == 1) return arr;
    _Swap(0, RandNum(1, arr.size() - 1, times), arr);
    return arr;
  }
  std::vector<T> RandVectorDifferent(int len, T range1, T range2, int times) {
    if (len > range2 - range1 + 1) {
      std::cerr << "范围不符合" << std::endl;
      return {};
    }
    std::vector<T> arr(len);
    std::default_random_engine e;
    if (typeid(T) == typeid(int)) {
      std::uniform_int_distribution<int> u(range1, range2);
      std::unordered_set<T> set;
      e.seed(time(0) + times);
      int n = u(e);
      for (int i = 0; i < len; i++) {
        T num = u(e);
        if (set.count(num)) {
          i--;
          continue;
        }
        arr[i] = num;
        set.insert(num);
      }

    } else {
      std::uniform_real_distribution<double> u(range1, range2);
      std::unordered_set<T> set;
      e.seed(time(0) + times);
      int n = u(e);
      for (int i = 0; i < len; i++) {
        T num = u(e);
        if (set.count(num)) {
          i--;
          continue;
        }
        arr[i] = num;
        set.insert(num);
      }
    }
    if (len == 1) return arr;
    _Swap(0, RandNum(1, arr.size() - 1, times), arr);

    return arr;
  }
  // 单随机数生成
  T RandNum(T range1, T range2, int times) {
    std::default_random_engine e;
    if (typeid(T) == typeid(int)) {
      std::uniform_int_distribution<int> u(range1, range2);
      e.seed(time(0) + times);
      return u(e);
    } else {
      std::uniform_real_distribution<double> u(range1, range2);
      e.seed(time(0) + times);
      return u(e);
    }
  }
  // 随机字符串生成
  std::string RandStringa(int len, T range1, T range2, int times) {
    std::default_random_engine e;
    std::uniform_int_distribution<char> u(range1, range2);
    e.seed(time(0) + times);
    std::string s;
    for (int i = 0; i < len; i++) {
      s += u(e);
    }
    return s;
  }
  // 随机字符串生成大写
  std::string RandStringA(int len, T range1, T range2, int times) {
    std::default_random_engine e;
    std::uniform_int_distribution<char> u(range1, range2);
    e.seed(time(0) + times);
    std::string s;
    for (int i = 0; i < len; i++) {
      s += u(e);
    }
    return s;
  }
  // 两个数组是否相等
  bool Is_SameVec(std::vector<T>& nums1, std::vector<T>& nums2) {
    if (nums1.size() != nums2.size()) {
      std::cerr << "错误" << std::endl;
      return false;
    }
    for (int i = 0; i < nums1.size(); i++) {
      if (nums1[i] != nums2[i]) return false;
    }
    return true;
  }

  friend bool operator==(const std::vector<T>& a, const std::vector<T>& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++)
      if (a[i] != b[i]) return false;
    return true;
  }
  friend bool operator!=(const std::vector<T>& a, const std::vector<T>& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++)
      if (a[i] == b[i]) return false;
    return true;
  }
  friend bool operator==(const std::vector<std::vector<T>>& a,
                         const std::vector<std::vector<T>>& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) return false;
    }
    return true;
  }
  friend bool operator!=(const std::vector<std::vector<T>>& a,
                         const std::vector<std::vector<T>>& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == b[i]) return false;
    }
    return true;
  }
};
template <class T>
std::string toString(const std::vector<T>& arr) {
  std::stringstream ss;
  for (T a : arr) ss << std::to_string(a) << " ";
  ss << std::endl;
  return ss.str();
}
}  // namespace Ricardo
