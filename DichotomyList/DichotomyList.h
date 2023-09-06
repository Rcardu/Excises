#include"../unltle.h"

class DichotomyList{
private:
    /*��ֵԪ����ָ��ֵ�ϸ������������ֵ��Ԫ�ء�
    ����һ���������� nums���ҵ���ֵԪ�ز�������������
    ������ܰ��������ֵ������������£�
    ���� �κ�һ����ֵ ����λ�ü��ɡ�
    ����Լ��� nums[-1] = nums[n] = -�� ��
    �����ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨����������⡣
    ʾ�� 1��
    ���룺nums = [1,2,3,1]
    �����2
    ���ͣ�3 �Ƿ�ֵԪ�أ���ĺ���Ӧ�÷��������� 2��
    ʾ�� 2��
    ���룺nums = [1,2,1,3,5,6,4]
    �����1 �� 5 
    ���ͣ���ĺ������Է������� 1�����ֵԪ��Ϊ 2��
    ���߷������� 5�� ���ֵԪ��Ϊ 6��*/
    int LC162_findPeakElement_(std::vector<int>&nums);
public:
    /*LeetCode 162 Ѱ�ҷ�ֵ*/
    void Test_LC162_findPeakElement();
private:
    /*��������*/
    void QuickSort_(std::vector<int>&nums);
    /*�ݹ�1*/
    void QuickSort_Switch1(std::vector<int>&nums,int left,int right);
    /*�ݹ�2 β�ݹ��Ż�*/
    void QuickSort_Switch2(std::vector<int>&nums,int left,int right);
    /*����*/
    void Swap(std::vector<int>&nums,int left,int right);
    /*���ŵݹ�1*/
    int QuickSort_BFS_1(std::vector<int>&nums,int left,int right);
    /*���ŵݹ�2 ��������*/
    int QuickSort_BFS_2(std::vector<int>&nums,int left,int right);
    /*���ŵݹ�3 ����������*/
    int QuickSort_BFS_3(std::vector<int>&nums,int left,int right);
    /*ѡȡ��λ��׼��*/
    int SelectMidNum_(int left,int right,int mid,std::vector<int>&nums);
    /*����Ѱ��*/
public:
    void Test_QuickSort();
private:
    /*ð������*/
    void Sortingalgorithms_(std::vector<int>&nums);
public:
    void Test_Sortingalgorithms();
private: 
    /*�鲢����*/
    void Merge_Sort_(std::vector<int>&nums);
    /*�鲢*/
    void merge_Sort_Sell_(std::vector<int>&nums,int left,int right);
    /*����*/
    void Merge_(std::vector<int>&nums,int left,int mid,int right);
public:
    /*�鲢����*/
    void Test_Merge_Sort();
private:
    /*������*/
    std::vector<int>SortArray_(std::vector<int>&nums);
    /*����*/
    void BuildMaxHeap_(std::vector<int>&nums,int n);
    /*�Ŷ�*/
    void adjustHeap_(std::vector<int>&nums,int i,int n);
public:
    void Test_SortArray();
private:
    /*ϣ������*/
    std::vector<int>HearArrySort_(std::vector<int>&nums);
public:
    /*ϣ������*/
    void Test_HearArrySort_();
};