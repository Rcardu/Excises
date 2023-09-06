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
};