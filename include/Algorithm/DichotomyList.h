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
    /*����beta*/
    void Swap_Beta(std::vector<int>&nums,int left,int right);
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
private:
    /*����غϵ��߶�*/
    int TheMostCoincidentSegments_(std::vector<std::vector<int>>&line);
public:
    /*����غϵ��߶�*/
    void Test_TheMostCoincidentSegments();
private:
    /*����һ������������ nums ��ÿһ�β����У�
    ����Դ� nums ��ѡ�� ���� һ������������С�� ǡ�� һ�롣
    ��ע�⣬�ں�������������ԶԼ������������ִ�в�����
    ���㷵�ؽ� nums ����� ���� ����һ��� ���� ��������
    ʾ�� 1��
    ���룺nums = [5,19,8,1]
    �����3
    ���ͣ���ʼ nums �ĺ�Ϊ 5 + 19 + 8 + 1 = 33 ��
    �����ǽ�����ͼ�������һ���һ�ַ�����
    ѡ������ 19 ����СΪ 9.5 ��
    ѡ������ 9.5 ����СΪ 4.75 ��
    ѡ������ 8 ����СΪ 4 ��
    ��������Ϊ [5, 4.75, 4, 1] ����Ϊ 5 + 4.75 + 4 + 1 = 14.75 ��
    nums �ĺͼ�С�� 33 - 14.75 = 18.25 ��
    ��С�Ĳ��ֳ����˳�ʼ����͵�һ�룬18.25 >= 33/2 = 16.5 ��
    ������Ҫ 3 ������ʵ����ĿҪ�����Է��� 3 ��
    ����֤�����޷�ͨ������ 3 ������ʹ����ͼ�������һ�롣*/
    int LC2208_halveArray_(std::vector<int>& nums);
public:
    /*LeetCode 2208 ������ͼ�������ٲ�������*/
    void Test_LC2208_halveArray();
private:
    /*��ʹ�ñȽ϶��ж�����ֵ�е����ֵ*/
    int GetMax(int a,int b);
    /*ȡ��*/
    int flip(int sign);
    /*��λ,ȡ����*/
    int sign(int num);
public:
    /*��ʹ�ñȽ϶��ж�����ֵ�е����ֵ*/
    void Test_GetMax();
private:
    /*����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ�
    ��������Ԫ�ؾ��������Ρ�
    �ҳ�ֻ����һ�ε�������Ԫ�ء�����԰� ����˳�� ���ش𰸡�
    �������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨�ҽ�ʹ�ó�������ռ�����������⡣
    ʾ�� 1��
    ���룺nums = [1,2,1,3,2,5]
    �����[3,5]
    ���ͣ�[5, 3] Ҳ����Ч�Ĵ𰸡�
    ʾ�� 2��
    ���룺nums = [-1,0]
    �����[-1,0]
    ʾ�� 3��
    ���룺nums = [0,1]
    �����[1,0]*/
    std::vector<int>LC260_singleNumber(std::vector<int>&nums);
public:
    /*LeetCode 260 ֻ���������ε�����*/
    void Test_LC260_singleNumber();
private:
    /*�ж�һ�����Ƿ���2����*/
    bool isPowerOfTwo(int n);
public:
    /*�ж�һ�����Ƿ���2����*/
    void Test_isPowerOfTwo();
private:
    /*���ش��ڵ���n����С��2��ĳ�η�*/
    int near2power(int n);
public:
    /*���ش��ڵ���n����С��2��ĳ�η�*/
    void near2power();
private:
    /*�ߵ������� 32 λ�޷��������Ķ�����λ��*/
    uint32_t LC190_reverseBits(uint32_t n);
public:
    /*LeetCode 190 �ߵ�������λ*/
    void Test_LC190_reverseBits();
private:    
    /*λͼ�Ķ�����*/
    bool BitSetComp(std::vector<int>&nums,int MaxNum);
public:
    /*LeetCode 2166 ���λ��*/
    void Test_BitSetComp();
private:
    /*LeetCode 29 λ����*/
    void BitOperator_Cop(std::vector<int>num1,std::vector<int>num2);
public:
    /*λ���������*/
    void Test_BitOperator_Cop();
};