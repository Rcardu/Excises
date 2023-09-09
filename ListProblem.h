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
    //���ͷ���
    Node*Head(){return head_;}
    //�����һ�����
    Node*Next(Node*node){return node->next;}
    //���������
    int Size(){return size_;}
    //�ҵ����һ�����
    Node*FindListLast(){
        Node*ptr=head_;
        while(ptr->next)ptr=ptr->next;
        return ptr;
    }
    //�ҵ���ǰ�ڵ��ǰһ�����
    Node*FindThisNode_front(Node*node){
        Node*ptr=head_;
        while(ptr->next!=node){
            ptr=ptr->next;
        }
        return ptr;
    }
    //��ӽ�㵽β��
    void AddListNode(int val){
        Node*ptr=FindListLast();
        ptr->next=new Node(val);
        size_++;
    }
    //��ӵ���ǰ������
    void AddListNode(int val,Node*node){
        Node*ptr=node->next;
        node->next=new Node(val);
        node->next->next=ptr;
        size_++;
    }
    //��������ӵ�β��������
    void AddListNode(std::vector<int>nums){
        Node*ptr=FindListLast();
        for(int num:nums){
            ptr->next=new Node(num);
            ptr=ptr->next;
            size_++;
        }
    }
    //��������ӵ���ǰ������
    void AddListNode(std::vector<int>nums,Node*node){
        Node*ptr=node->next;
        //��¼������ǰһ�����
        Node*cur;
        for(int num:nums){
            node->next=new Node(num);
            cur=node;
            node=node->next;
            size_++;
        }
        cur->next=ptr;
    }
    //ɾ�����һ�����
    Node* RemoveLastNode(){
        //���ҵ����һ������ǰһ�����
        Node*ptr=FindThisNode_front(FindListLast());
        Node*cur=ptr->next;
        ptr->next=cur->next;
        return cur;
    }
    //ɾ����ǰ���
    Node* RemoveThisNode(Node*node){
        Node*ptr=FindThisNode_front(node);
        Node*cur=ptr->next;
        ptr->next=cur->next;
        return cur;
    }
    //ɾ�����н��
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
    //��������ʽ����
    ListNode():size_(0){
        head_=new Node();
        std::cout<<"��ͨ����"<<std::endl;
    }
    //����ת��Ϊ����
    ListNode(std::vector<int>nums):size_(0),head_(nullptr){
        head_=new Node();
        AddListNode(nums);
        std::cout<<"���鹹��"<<std::endl;
    }
    ~ListNode(){
        RemoveNode_All();
        delete head_;
        head_=nullptr;
        std::cout<<"�������"<<std::endl;
    }
    //��������
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
        std::cout<<"��������"<<std::endl;
    }
public:
    //��ӡ����
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


