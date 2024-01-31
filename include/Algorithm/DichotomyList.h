#include "../unltle.h"

namespace Ricardo {
class DichotomyList {
 private:
  int LC162_findPeakElement_(std::vector<int>& nums);

 public:
  void Test_LC162_findPeakElement();

 private:
  void QuickSort_(std::vector<int>& nums);
  void QuickSort_Switch1(std::vector<int>& nums, int left, int right);
  void QuickSort_Switch2(std::vector<int>& nums, int left, int right);
  void Swap(std::vector<int>& nums, int left, int right);
  void Swap_Beta(std::vector<int>& nums, int left, int right);
  int QuickSort_BFS_1(std::vector<int>& nums, int left, int right);
  int QuickSort_BFS_2(std::vector<int>& nums, int left, int right);
  int QuickSort_BFS_3(std::vector<int>& nums, int left, int right);
  int SelectMidNum_(int left, int right, int mid, std::vector<int>& nums);

 public:
  void Test_QuickSort();

 private:
  void Sortingalgorithms_(std::vector<int>& nums);

 public:
  void Test_Sortingalgorithms();

 private:
  void Merge_Sort_(std::vector<int>& nums);
  void merge_Sort_Sell_(std::vector<int>& nums, int left, int right);
  void Merge_(std::vector<int>& nums, int left, int mid, int right);

 public:
  void Test_Merge_Sort();

 private:
  std::vector<int> SortArray_(std::vector<int>& nums);
  void BuildMaxHeap_(std::vector<int>& nums, int n);
  void adjustHeap_(std::vector<int>& nums, int i, int n);

 public:
  void Test_SortArray();

 private:
  std::vector<int> HearArrySort_(std::vector<int>& nums);

 public:
  void Test_HearArrySort_();

 private:
  int TheMostCoincidentSegments_(std::vector<std::vector<int>>& line);

 public:
  void Test_TheMostCoincidentSegments();

 private:
  int LC2208_halveArray_(std::vector<int>& nums);

 public:
  void Test_LC2208_halveArray();

 private:
  int GetMax(int a, int b);
  int flip(int sign);
  int sign(int num);

 public:
  void Test_GetMax();

 private:
  std::vector<int> LC260_singleNumber(std::vector<int>& nums);

 public:
  void Test_LC260_singleNumber();

 private:
  bool isPowerOfTwo(int n);

 public:
  void Test_isPowerOfTwo();

 private:
  int near2power(int n);

 public:
  void near2power();

 private:
  uint32_t LC190_reverseBits(uint32_t n);

 public:
  void Test_LC190_reverseBits();

 private:
  bool BitSetComp(std::vector<int>& nums, int MaxNum);

 public:
  void Test_BitSetComp();

 private:
  void BitOperator_Cop(std::vector<int> num1, std::vector<int> num2);

 public:
  void Test_BitOperator_Cop();
};
}  // namespace Ricardo
