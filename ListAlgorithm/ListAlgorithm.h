#include"../unltle.h"
class List{
private:
    void CreatList(std::vector<int>nums);
public:
    void Test_CreatList();
private:
    /*���������ͷ�ڵ� head ��ÿ k ���ڵ�һ����з�ת�����㷵���޸ĺ������
    k ��һ��������������ֵС�ڻ��������ĳ��ȡ�
    ����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��
    �㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʽ��нڵ㽻����*/
    Node*LC25_reverseKGroup(Node*head,int k);
public:
    /*LeetCode 25 k��һ�鷴ת����*/
    void Test_LC25_reverseKGroup();
};