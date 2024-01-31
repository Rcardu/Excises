#include "DichotomyList.h"
using namespace std;

namespace Ricardo {
int DichotomyList::LC162_findPeakElement_(vector<int>& nums) {
  int n = nums.size();
  if (n == 1) return nums[0];
  int l = 0;
  int r = n - 1;
  if (nums[l] > nums[l + 1]) return l;
  if (nums[r] > nums[r - 1]) return r;
  while (l < r) {
    int mid = l + ((r - l) >> 1);
    if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
      l = mid;
    else if (nums[mid] < nums[mid - 1] && nums[mid] > nums[mid + 1])
      r = mid;
    else if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1])
      r = mid;
    else
      return mid;
  }
  return l;
}
void DichotomyList::Test_LC162_findPeakElement() {
  vector<int> nums = {1, 2, 1, 2, 1};
  cout << LC162_findPeakElement_(nums) << endl;
}

void DichotomyList::QuickSort_(vector<int>& nums) {
  QuickSort_Switch2(nums, 0, nums.size() - 1);
}
void DichotomyList::QuickSort_Switch1(vector<int>& nums, int left, int right) {
  if (left >= right) return;
  int pivot = QuickSort_BFS_1(nums, left, right);
  QuickSort_Switch1(nums, left, pivot - 1);
  QuickSort_Switch1(nums, pivot + 1, right);
}
void DichotomyList::QuickSort_Switch2(vector<int>& nums, int left, int right) {
  while (left < right) {
    int pivot = QuickSort_BFS_1(nums, left, right);
    if (pivot - left < right - pivot) {
      QuickSort_Switch2(nums, left, pivot - 1);
      left = pivot + 1;
    } else {
      QuickSort_Switch2(nums, pivot + 1, right);
      right = pivot - 1;
    }
  }
}
int DichotomyList::QuickSort_BFS_1(vector<int>& nums, int left, int right) {
  int mid = SelectMidNum_(left, right, left + ((right - left) / 2), nums);
  swap(nums[left], nums[mid]);
  int i = left, j = right;
  while (i < j) {
    while (i < j && nums[left] <= nums[j]) j--;
    while (i < j && nums[left] >= nums[i]) i++;
    swap(nums[i], nums[j]);
  }
  swap(nums[i], nums[left]);
  return i;
}
int DichotomyList::QuickSort_BFS_2(vector<int>& nums, int left, int right) {
  int mid = SelectMidNum_(left, right, left + ((right - left) >> 1), nums);
  int pivod = nums[mid];
  int a = left, xi = 0;
  for (int i = left; i <= right; i++) {
    if (nums[i] <= pivod) {
      Swap(nums, i, a);
      if (nums[a] == pivod) xi = a;
      a++;
    }
  }
  Swap(nums, a - 1, xi);
  return a - 1;
}
int DichotomyList::QuickSort_BFS_3(vector<int>& nums, int left, int right) {
  int mid = SelectMidNum_(left, right, left + ((right - left) >> 1), nums);
  int pivod = nums[mid];
  Swap(nums, right, mid);
  int i = left - 1;
  int j;
  for (j = left; j <= right - 1; j++) {
    if (nums[j] <= pivod) {
      i++;
      Swap(nums, i, j);
    }
  }
  Swap(nums, i + 1, right);
  return i + 1;
}
void DichotomyList::Swap(vector<int>& nums, int left, int right) {
  int temp = nums[left];
  nums[left] = nums[right];
  nums[right] = temp;
}
void DichotomyList::Swap_Beta(vector<int>& nums, int left, int right) {
  if (left ^ right == 0) return;
  // 相同内存的数字异或结果会保持为0;
  nums[left] = nums[left] ^ nums[right];
  nums[right] = nums[right] ^ nums[left];  //(a^b)^b=a^(b^b)=a^0=a
  nums[left] = nums[left] ^ nums[right];   //(a^b)^a=(a^a)^b=0^b=b
}
int DichotomyList::SelectMidNum_(int left, int right, int mid,
                                 vector<int>& nums) {
  if (nums[left] < nums[mid] ^ nums[left] < nums[right])
    return left;
  else if (nums[mid] <= nums[left] ^ nums[mid] < nums[right])
    return mid;
  else
    return right;
}
void DichotomyList::Test_QuickSort() {
  Cleanup cle;
  for (int i = 0; i < 1; i++) {
    vector<int> nums = cle.RandVector(10, -10, 10, i);
    vector<int> num1 = nums;
    vector<int> num2 = nums;
    cout << "原数组为：" << endl;
    Swap_Beta(nums, 3, 3);
  }
}

void DichotomyList::Sortingalgorithms_(vector<int>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] > nums[j]) Swap(nums, i, j);
    }
  }
}

void DichotomyList::Merge_Sort_(vector<int>& nums) {
  merge_Sort_Sell_(nums, 0, nums.size() - 1);
}
void DichotomyList::merge_Sort_Sell_(vector<int>& nums, int left, int right) {
  if (left >= right) return;
  int mid = left + ((right - left) >> 1);
  merge_Sort_Sell_(nums, left, mid);
  merge_Sort_Sell_(nums, mid + 1, right);
  Merge_(nums, left, mid, right);
}
void DichotomyList::Merge_(vector<int>& nums, int left, int mid, int right) {
  vector<int> temp(nums.begin() + left, nums.begin() + right + 1);
  for (int l_be = left - left, r_be = mid - left + 1, i = left; i <= right;
       i++) {
    if (l_be > mid - left)
      nums[i] = temp[r_be++];
    else if (r_be > right - left)
      nums[i] = temp[l_be++];
    else if (temp[l_be] < temp[r_be])
      nums[i] = temp[l_be++];
    else
      nums[i] = temp[r_be++];
  }
}
void DichotomyList::Test_Merge_Sort() {
  Cleanup cle;
  for (int i = 0; i < 1; i++) {
    // vector<int>nums={};
    vector<int> nums = cle.RandVector(50000, 2, 2, i);
    vector<int> num1 = nums;
    vector<int> num2 = nums;
    // cle.Print(nums);
    Merge_Sort_(num1);
    // cle.Print(num1);
    // Sortingalgorithms_(num2);
    // cle.Print(num2);
    // if(cle.LogarithmicAxis(num1,num2))cout<<"True!"<<endl;
    // else cout<<"False!"<<endl;
  }
}

vector<int> DichotomyList::SortArray_(vector<int>& nums) {
  int n = nums.size();
  if (n < 1) return nums;
  BuildMaxHeap_(nums, n);
  while (n) {
    Swap(nums, 0, n - 1);
    n--;
    adjustHeap_(nums, 0, n);
  }
  return nums;
}
void DichotomyList::BuildMaxHeap_(vector<int>& nums, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    adjustHeap_(nums, i, n);
  }
}
void DichotomyList::adjustHeap_(vector<int>& nums, int i, int n) {
  int Maxindex = i;
  int left = 2 * i + 1;
  int right = 2 * (i + 1);
  if (left < n && nums[left] > nums[Maxindex]) Maxindex = left;
  if (right < n && nums[right] > nums[Maxindex] && nums[right] > nums[left])
    Maxindex = right;
  if (i != Maxindex) {
    Swap(nums, i, Maxindex);
    adjustHeap_(nums, Maxindex, n);
  }
}
void DichotomyList::Test_SortArray() {
  Cleanup cle;
  for (int i = 0; i < 1; i++) {
    vector<int> nums = cle.RandVector(1, 2, 2, i);
    vector<int> num1 = nums;
    vector<int> num2 = nums;
    // cle.Print(nums);
    SortArray_(num1);
    cle.Print(num1);
    // Sortingalgorithms_(num2);
    // cle.Print(num2);
    // if(cle.LogarithmicAxis(num1,num2))cout<<"True!"<<endl;
    // else cout<<"False!"<<endl;
  }
}

/// @brief 希尔排序
/// @param nums
/// @return
vector<int> DichotomyList::HearArrySort_(vector<int>& nums) {
  // 设置希尔增量
  int n = nums.size();
  int digit = n / 2;
  int currValue;
  while (digit) {
    for (int i = digit; i < n; i++) {
      // 待排序的数
      currValue = nums[i];
      // 可能要插入的位置
      int index = i - digit;
      while (index >= 0 && nums[index] > currValue) {
        // 就将index位置的数插入到当前增量下的位置
        nums[index + digit] = nums[index];
        index -= digit;
      }
      nums[index + digit] = currValue;
    }
    digit /= 2;
  }
  return nums;
}
void DichotomyList::Test_HearArrySort_() {
  Random<int> cle;
  for (int i = 0; i < 10; i++) {
    vector<int> nums = cle.RandVector(50000, 2, 2, i);
    vector<int> num1 = nums;
    vector<int> num2 = nums;
    // cle.Print(nums);
    HearArrySort_(num1);
    // cle.Print(num1);
    // Sortingalgorithms_(num2);
    // cle.Print(num2);
    // if(cle.LogarithmicAxis(num1,num2))cout<<"True!"<<endl;
    // else cout<<"False!"<<endl;
  }
}

/// @brief 最多重合的线段
/// @param n1
/// @param n2
/// @return
bool cmp(vector<int>& n1, vector<int>& n2) { return n1[0] < n2[0]; }
int DichotomyList::TheMostCoincidentSegments_(vector<vector<int>>& line) {
  int ans = 0;
  sort(line.begin(), line.end(), cmp);
  priority_queue<int, vector<int>, greater<int>> q;
  for (vector<int> l : line) {
    while (!q.empty() && q.top() <= l[0]) {
      q.pop();
    }
    q.push(l[1]);
    ans = max(ans, (int)q.size());
  }
  return ans;
}
void DichotomyList::Test_TheMostCoincidentSegments() {
  // vector<vector<int>>nums={{2,6},{3,7},{5,9},{1,5},{2,4},{1,3}};
  // cout<<TheMostCoincidentSegments_(nums)<<endl;
  Cleanup cle;
  vector<vector<int>> nums;
  for (int i = 0; i < 5000; i++) {
    nums.push_back(cle.RandVectorDifferent(2, -100, 100, i));
    if (nums[i][0] > nums[i][1]) Swap(nums[i], 0, 1);
    // cle.Print(nums[i]);
  }
  cout << TheMostCoincidentSegments_(nums) << endl;
}

/// @brief LeetCode 2208 将数组和减半的最少操作次数
/// @param nums
/// @return
int DichotomyList::LC2208_halveArray_(std::vector<int>& nums) {
  priority_queue<double, vector<double>, less<double>> que;
  double sum = 0;
  for (int n : nums) {
    que.push((double)n);
    sum += n;
  }
  double beg_sum = sum / 2;
  int ans = 0;
  while (!que.empty() && sum >= beg_sum) {
    sum -= que.top() / 2;
    que.push(que.top() / 2);
    que.pop();
    ans++;
    if (sum == beg_sum) break;
  }
  return ans;
}
void DichotomyList::Test_LC2208_halveArray() {
  // vector<int>nums={5,19,8,1};
  // LC2208_halveArray_(nums);
  Cleanup cle;
  for (int i = 0; i < 10; i++) {
    vector<int> nums = cle.RandVector(10, 0, 20, i);
    cle.Print(nums);
    cout << LC2208_halveArray_(nums) << endl;
  }
}

/// @brief 不使用比较而判断两个值中的最大值
/// @param a
/// @param b
/// @return
int DichotomyList::GetMax(int a, int b) {
  int c = a - b;
  int sa = sign(a);
  int sb = sign(b);
  int sc = sign(c);
  // 判断a与b的符号是否一样
  int diffAB = sa ^ sb;
  // 一样的话
  int sameAB = flip(diffAB);
  // 如果符号不一样且a是非负的或者符号一样且c是非负的都返回a为最大值
  int returnA = diffAB * sa + sameAB * sc;
  // 反之返回b
  int returnB = flip(returnA);

  return a * returnA + b * returnB;
}
int DichotomyList::flip(int sign) { return sign ^ 1; }
int DichotomyList::sign(int num) { return flip((num >> 31) & 1); }
void DichotomyList::Test_GetMax() {
  Cleanup cle;
  for (int i = 0; i < 10; i++) {
    vector<int> nums = cle.RandVectorDifferent(2, -100, 100, i);
    cle.Print(nums);
    cout << GetMax(nums[0], nums[1]) << endl;
  }
}

/// @brief LeetCode 260 只出现奇数次的数字
/// @param nums
/// @return
vector<int> DichotomyList::LC260_singleNumber(vector<int>& nums) {
  int eor1 = 0, eor2 = 0;
  for (int n : nums) eor1 ^= n;
  // 此时eor就是两个出现奇数次的数的异或值
  // 所以eor最右侧的1必为两个数中的一个的1
  int DataOne = eor1 & (-eor1);
  // 通过与操作将数组中的数分为最右侧右这个1的与没有的
  for (int n : nums) {
    if ((n & DataOne) == 0) {  // 如果这个数没有这个1
      eor2 ^= n;  // 找出这部分出现奇数次的数
    }
  }
  return {eor2, eor1 ^ eor2};
}
void DichotomyList::Test_LC260_singleNumber() {
  vector<int> nums = {1, 2, 1, 3, 2, 5};
  vector<int> ans = LC260_singleNumber(nums);
  cout << ans[0] << " " << ans[1] << endl;
}

/// @brief 判断一个数是否是2的幂
/// @param n
/// @return
bool DichotomyList::isPowerOfTwo(int n) { return n > 0 && n == (n & -n); }
void DichotomyList::Test_isPowerOfTwo() {
  Cleanup cle;
  vector<int> nums = cle.RandVector(10, 0, 50000, 10);
  for (int i = 0; i < 10; i++) {
    cout << nums[i] << endl;
    if (isPowerOfTwo(nums[i]))
      cout << "True!";
    else
      cout << "False!";
  }
}

/// @brief 返回大于等于n的最小的2的某次方
/// @param n
/// @return
int DichotomyList::near2power(int n) {
  if (n < 0) return 0;
  n--;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  return n + 1;
}
void DichotomyList::near2power() {
  Cleanup cle;
  vector<int> nums = cle.RandVector(20, 0, 996, 10);
  for (int i : nums) {
    cout << i << " " << near2power(i) << endl;
  }
}

/// @brief LeetCode 190 颠倒二进制位
/// @param n
/// @return
uint32_t DichotomyList::LC190_reverseBits(uint32_t n) {
  // 1010 1010=0xaa
  // 0101 0101=0x55
  n = ((n & 0xaaaaaaaa) >> 1 | (n & 0x55555555) << 1);
  // 1100 1100=0xcc
  // 0011 0011=0x33
  n = ((n & 0xcccccccc) >> 2 | (n & 0x33333333) << 2);
  // 11110000 11110000=0xf0f0
  // 00001111 00001111=0x0f0f
  n = ((n & 0xf0f0f0f0) >> 4 | (n & 0x0f0f0f0f) << 4);
  // 11111111 00000000=0xff00
  // 00000000 11111111=0x00ff
  n = ((n & 0xff00ff00) >> 8 | (n & 0x00ff00ff) << 8);
  n = (n >> 16) | (n << 16);
  return n;
}
void DichotomyList::Test_LC190_reverseBits() {
  Cleanup cle;
  vector<int> nums = cle.RandVector(10, 0, 100, 10);
  for (int i = 0; i < 10; i++) {
    uint32_t num = (uint32_t)nums[i];
    cout << (bitset<sizeof(num) * 8>)num << endl;
    cout << (bitset<sizeof(num) * 8>)LC190_reverseBits(num) << endl;
  }
}

/// @brief 位图对数器
/// @param nums
/// @param MaxNum
/// @return
bool DichotomyList::BitSetComp(vector<int>& nums, int MaxNum) {
  bool flag = true;
  BitSet bit(MaxNum);
  unordered_map<int, int> map;
  Cleanup cle;
  vector<double> decied = cle.RandVector(10000, (double)0, (double)1, 10);
  cout << "调用阶段开始" << endl;
  for (int i = 0; i < decied.size(); i++) {
    if (decied[i] < 0.333) {
      map[nums[i]]++;
      bit.BitSetAdd(nums[i]);
    } else if (decied[i] < 0.666) {
      map.erase(nums[i]);
      bit.BitSetRemove(nums[i]);
    } else {
      if (map.count(nums[i]))
        map.erase(nums[i]);
      else
        map[nums[i]]++;
      bit.BitSetReverse(nums[i]);
    }
  }
  cout << "调用阶段结束" << endl;
  cout << "验证阶段开始" << endl;
  for (int i = 0; i < MaxNum; i++) {
    if (bit.BitSetContains(i) != map.count(i)) {
      cout << "出错了" << endl;
      flag = false;
    }
  }
  cout << "验证结束！" << endl;
  return true;
}
void DichotomyList::Test_BitSetComp() {
  Cleanup cle;
  vector<int> nums = cle.RandVector(10000, 0, 1000, 10);
  if (BitSetComp(nums, 1000))
    cout << "True" << endl;
  else
    cout << "False!" << endl;
}

/// @brief 位运算对数器
/// @param num1
/// @param num2
void DichotomyList::BitOperator_Cop(vector<int> num1, vector<int> num2) {
  vector<int> ans1(num1.size());
  vector<int> ans2(num2.size());
  Cleanup cle;
  vector<double> decied = cle.RandVector(100000, 0.0, 1.0, 10);
  BitOperator Bpr;
  cout << "开始调用" << endl;
  for (int i = 0; i < 100000; i++) {
    if (decied[i] < 0.25) {
      ans1[i] = Bpr.BitAdd(num1[i], num2[i]);
      ans2[i] = num1[i] + num2[i];
    } else if (decied[i] < 0.5) {
      ans1[i] = Bpr.BitMinus(num1[i], num2[i]);
      ans2[i] = num1[i] - num2[i];
    } else if (decied[i] < 0.75) {
      ans1[i] = Bpr.BitMultiply(num1[i], num2[i]);
      ans2[i] = num1[i] * num2[i];
    } else {
      if (num2[i] == 0) continue;
      ans1[i] = Bpr.BitDived(num1[i], num2[i]);
      ans2[i] = num1[i] / num2[i];
    }
  }
  cout << "调用阶段结束" << endl;
  cout << "开始测试" << endl;
  for (int i = 0; i < ans1.size(); i++) {
    if (ans1[i] != ans2[i]) cout << "答案错误!" << endl;
  }
  cout << "测试结束" << endl;
}
void DichotomyList::Test_BitOperator_Cop() {
  Cleanup cle;
  vector<int> num1 = cle.RandVector(100000, -100000, 100000, 10);
  vector<int> num2 = cle.RandVector(100000, -999999, 999999, 100);
  BitOperator_Cop(num1, num2);
}

int main(int argc, char* argv[]) {
  chrono::_V2::system_clock::time_point start = chrono::system_clock::now();

  DichotomyList dic;
  dic.Test_BitOperator_Cop();

  chrono::_V2::system_clock::time_point end = chrono::system_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  cout << "共花费：" << duration.count() << " ms " << endl;

  while (getchar() != '\n') continue;
  getchar();
  return 0;
}
}  // namespace Ricardo
