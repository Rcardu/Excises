#include"../unltle.h"
class List{
private:
    void CreatList(std::vector<int>nums);
public:
    void Test_CreatList();
private:
    /*给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
    k 是一个正整数，它的值小于或等于链表的长度。
    如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
    你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。*/
    Node*LC25_reverseKGroup(Node*head,int k);
public:
    /*LeetCode 25 k个一组反转链表*/
    void Test_LC25_reverseKGroup();
private:
    Node*start;
    Node*end;
private:
    /*给定链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表.*/
    Node*LCR077_SortList(Node*head);
    /*使用原地步长来代替递归*/
    Node*LCR077_SortList_Beta(Node*head);
    //二分
    Node*ToMidList(Node*left,Node*right);
    //取中
    Node*SandQ(Node*start,Node*right);
    //排序
    Node*Merge(Node*start,Node*Mid);
    void Merge_Beat(Node*l1,Node*r1,Node*l2,Node*r2);
    //找步长中最后一个结点
    Node*FindEnd(Node*list,int step);
public:
    /*LCR 077 链表排序*/
    void Test_LCR077_SortList();
};