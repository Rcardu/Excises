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
private:
    Node*start;
    Node*end;
private:
    /*���������ͷ��� head ���뽫�䰴 ���� ���в����� ����������.*/
    Node*LCR077_SortList(Node*head);
    /*ʹ��ԭ�ز���������ݹ�*/
    Node*LCR077_SortList_Beta(Node*head);
    //����
    Node*ToMidList(Node*left,Node*right);
    //ȡ��
    Node*SandQ(Node*start,Node*right);
    //����
    Node*Merge(Node*start,Node*Mid);
    void Merge_Beat(Node*l1,Node*r1,Node*l2,Node*r2);
    //�Ҳ��������һ�����
    Node*FindEnd(Node*list,int step);
public:
    /*LCR 077 ��������*/
    void Test_LCR077_SortList();
};