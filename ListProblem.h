#pragma once
#include<vector>
#include<iostream>
struct Node{
    int val;
    Node*next;
    Node():val(0),next(nullptr){};
    Node(int x):val(x),next(nullptr){};
    Node(int x,Node*next):val(x),next(next){};
};
class ListNode{
private:
    int size_;
    Node*head_;
public:
    //获得头结点
    Node*Head(){return head_;}
    //获得下一个结点
    Node*Next(Node*node){return node->next;}
    //获得链表长度
    int Size(){return size_;}
    //找到最后一个结点
    Node*FindListLast(){
        Node*ptr=head_;
        while(ptr->next)ptr=ptr->next;
        return ptr;
    }
    //找到当前节点的前一个结点
    Node*FindThisNode_front(Node*node){
        Node*ptr=head_;
        while(ptr->next!=node){
            ptr=ptr->next;
        }
        return ptr;
    }
    //添加结点到尾部
    void AddListNode(int val){
        Node*ptr=FindListLast();
        ptr->next=new Node(val);
        size_++;
    }
    //添加到当前结点后面
    void AddListNode(int val,Node*node){
        Node*ptr=node->next;
        node->next=new Node(val);
        node->next->next=ptr;
        size_++;
    }
    //将数组添加到尾部结点后面
    void AddListNode(std::vector<int>nums){
        Node*ptr=FindListLast();
        for(int num:nums){
            ptr->next=new Node(num);
            ptr=ptr->next;
            size_++;
        }
    }
    //将数组添加到当前结点后面
    void AddListNode(std::vector<int>nums,Node*node){
        Node*ptr=node->next;
        //记录插入后的前一个结点
        Node*cur;
        for(int num:nums){
            node->next=new Node(num);
            cur=node;
            node=node->next;
            size_++;
        }
        cur->next=ptr;
    }
    //删除最后一个结点
    Node* RemoveLastNode(){
        //先找到最后一个结点的前一个结点
        Node*ptr=FindThisNode_front(FindListLast());
        Node*cur=ptr->next;
        ptr->next=cur->next;
        return cur;
    }
    //删除当前结点
    Node* RemoveThisNode(Node*node){
        Node*ptr=FindThisNode_front(node);
        Node*cur=ptr->next;
        ptr->next=cur->next;
        return cur;
    }
    //删除所有结点
    void RemoveNode_All(){
        Node*ptr=head_->next;
        while(ptr){
            Node*cur=RemoveThisNode(ptr);
            ptr=ptr->next;
            delete cur;
            cur=nullptr;
        }
    }
public:
    //正常插入式链表
    ListNode():size_(0){
        head_=new Node();
        std::cout<<"普通构造"<<std::endl;
    }
    //数组转化为链表
    ListNode(std::vector<int>nums):size_(0),head_(nullptr){
        head_=new Node();
        AddListNode(nums);
        std::cout<<"数组构造"<<std::endl;
    }
    ~ListNode(){
        RemoveNode_All();
        delete head_;
        head_=nullptr;
        std::cout<<"析构完成"<<std::endl;
    }
    //拷贝构造
    ListNode(const ListNode&head){
        Node*ptr=head.head_;
        head_=new Node();
        Node*cur=this->head_;
        while(ptr->next){
            cur->next=new Node(ptr->next->val);
            cur=cur->next;
            ptr=ptr->next;
            this->size_++;
        }
        std::cout<<"拷贝构造"<<std::endl;
    }
public:
    //打印链表
    void List_Print(){
        Node*ptr=head_->next;
        while(ptr->next){
            std::cout<<ptr->val<<" -> ";
            ptr=ptr->next;
        }
        std::cout<<ptr->val<<std::endl;
    }
    void List_Print(ListNode head){
        Node*ptr=head.head_->next;
        while(ptr->next){
            std::cout<<ptr->val<<" -> ";
            ptr=ptr->next;
        }
        std::cout<<ptr->val<<std::endl;
    }
};


