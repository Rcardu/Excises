#include"../unltle.h"

class DichotomyList{
private:
    /*峰值元素是指其值严格大于左右相邻值的元素。
    给你一个整数数组 nums，找到峰值元素并返回其索引。
    数组可能包含多个峰值，在这种情况下，
    返回 任何一个峰值 所在位置即可。
    你可以假设 nums[-1] = nums[n] = -∞ 。
    你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
    示例 1：
    输入：nums = [1,2,3,1]
    输出：2
    解释：3 是峰值元素，你的函数应该返回其索引 2。
    示例 2：
    输入：nums = [1,2,1,3,5,6,4]
    输出：1 或 5 
    解释：你的函数可以返回索引 1，其峰值元素为 2；
    或者返回索引 5， 其峰值元素为 6。*/
    int LC162_findPeakElement_(std::vector<int>&nums);
public:
    /*LeetCode 162 寻找峰值*/
    void Test_LC162_findPeakElement();
private:
    /*快速排序*/
    void QuickSort_(std::vector<int>&nums);
    /*递归1*/
    void QuickSort_Switch1(std::vector<int>&nums,int left,int right);
    /*递归2 尾递归优化*/
    void QuickSort_Switch2(std::vector<int>&nums,int left,int right);
    /*交换*/
    void Swap(std::vector<int>&nums,int left,int right);
    /*交换beta*/
    void Swap_Beta(std::vector<int>&nums,int left,int right);
    /*快排递归1*/
    int QuickSort_BFS_1(std::vector<int>&nums,int left,int right);
    /*快排递归2 索引交换*/
    int QuickSort_BFS_2(std::vector<int>&nums,int left,int right);
    /*快排递归3 右索引交换*/
    int QuickSort_BFS_3(std::vector<int>&nums,int left,int right);
    /*选取中位基准数*/
    int SelectMidNum_(int left,int right,int mid,std::vector<int>&nums);
    /*二分寻找*/
public:
    void Test_QuickSort();
private:
    /*冒泡排序*/
    void Sortingalgorithms_(std::vector<int>&nums);
public:
    void Test_Sortingalgorithms();
private: 
    /*归并排序*/
    void Merge_Sort_(std::vector<int>&nums);
    /*归并*/
    void merge_Sort_Sell_(std::vector<int>&nums,int left,int right);
    /*排序*/
    void Merge_(std::vector<int>&nums,int left,int mid,int right);
public:
    /*归并排序*/
    void Test_Merge_Sort();
private:
    /*堆排序*/
    std::vector<int>SortArray_(std::vector<int>&nums);
    /*建堆*/
    void BuildMaxHeap_(std::vector<int>&nums,int n);
    /*排堆*/
    void adjustHeap_(std::vector<int>&nums,int i,int n);
public:
    void Test_SortArray();
private:
    /*希尔排序*/
    std::vector<int>HearArrySort_(std::vector<int>&nums);
public:
    /*希尔排序*/
    void Test_HearArrySort_();
private:
    /*最多重合的线段*/
    int TheMostCoincidentSegments_(std::vector<std::vector<int>>&line);
public:
    /*最多重合的线段*/
    void Test_TheMostCoincidentSegments();
private:
    /*给你一个正整数数组 nums 。每一次操作中，
    你可以从 nums 中选择 任意 一个数并将它减小到 恰好 一半。
    （注意，在后续操作中你可以对减半过的数继续执行操作）
    请你返回将 nums 数组和 至少 减少一半的 最少 操作数。
    示例 1：
    输入：nums = [5,19,8,1]
    输出：3
    解释：初始 nums 的和为 5 + 19 + 8 + 1 = 33 。
    以下是将数组和减少至少一半的一种方法：
    选择数字 19 并减小为 9.5 。
    选择数字 9.5 并减小为 4.75 。
    选择数字 8 并减小为 4 。
    最终数组为 [5, 4.75, 4, 1] ，和为 5 + 4.75 + 4 + 1 = 14.75 。
    nums 的和减小了 33 - 14.75 = 18.25 ，
    减小的部分超过了初始数组和的一半，18.25 >= 33/2 = 16.5 。
    我们需要 3 个操作实现题目要求，所以返回 3 。
    可以证明，无法通过少于 3 个操作使数组和减少至少一半。*/
    int LC2208_halveArray_(std::vector<int>& nums);
public:
    /*LeetCode 2208 将数组和减半的最少操作次数*/
    void Test_LC2208_halveArray();
private:
    /*不使用比较而判断两个值中的最大值*/
    int GetMax(int a,int b);
    /*取反*/
    int flip(int sign);
    /*移位,取符号*/
    int sign(int num);
public:
    /*不使用比较而判断两个值中的最大值*/
    void Test_GetMax();
private:
    /*给你一个整数数组 nums，其中恰好有两个元素只出现一次，
    其余所有元素均出现两次。
    找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
    你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
    示例 1：
    输入：nums = [1,2,1,3,2,5]
    输出：[3,5]
    解释：[5, 3] 也是有效的答案。
    示例 2：
    输入：nums = [-1,0]
    输出：[-1,0]
    示例 3：
    输入：nums = [0,1]
    输出：[1,0]*/
    std::vector<int>LC260_singleNumber(std::vector<int>&nums);
public:
    /*LeetCode 260 只出现奇数次的数字*/
    void Test_LC260_singleNumber();
private:
    /*判断一个数是否是2的幂*/
    bool isPowerOfTwo(int n);
public:
    /*判断一个数是否是2的幂*/
    void Test_isPowerOfTwo();
private:
    /*返回大于等于n的最小的2的某次方*/
    int near2power(int n);
public:
    /*返回大于等于n的最小的2的某次方*/
    void near2power();
private:
    /*颠倒给定的 32 位无符号整数的二进制位。*/
    uint32_t LC190_reverseBits(uint32_t n);
public:
    /*LeetCode 190 颠倒二进制位*/
    void Test_LC190_reverseBits();
private:    
    /*位图的对数器*/
    bool BitSetComp(std::vector<int>&nums,int MaxNum);
public:
    /*LeetCode 2166 设计位集*/
    void Test_BitSetComp();
private:
    /*LeetCode 29 位运算*/
    void BitOperator_Cop(std::vector<int>num1,std::vector<int>num2);
public:
    /*位运算对数器*/
    void Test_BitOperator_Cop();
};