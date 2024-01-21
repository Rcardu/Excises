#include"ListAlgorithm.h"
using namespace std;
/// @brief 创建链表测试
/// @param nums 
void List::CreatList(vector<int>nums){
        ListNode list1;
        list1.AddListNode(nums);
        list1.List_Print();
        ListNode list2(nums);
        list1.List_Print(list2);
        list2.AddListNode(12,list2.Next(list2.Next(list2.Head())));
        list2.List_Print();
        cout<<list1.Size()<<endl;
        cout<<list2.Size()<<endl;
        Cleanup cle;
        list1.AddListNode(cle.RandVector(4,-20,30,10));
        list2.List_Print(list1);
        cout<<list1.Size()<<endl;
        
}
void List::Test_CreatList(){
    Cleanup cle;
    vector<int>nums=cle.RandVector(10,-10,10,10);
    CreatList(nums);
}

/// @brief LeetCode 25 k个一组反转链表
/// @param head 
/// @param k 
/// @return 
Node*List::LC25_reverseKGroup(Node*head,int k){
    if(head==nullptr)return NULL;
    Node*ptr=head;
    for(int i=0;i<k;i++){
        if(ptr)ptr=ptr->next;
        else return head;
    }
    ptr=nullptr;
    //cur就成为了当前组的尾部
    Node*cur=head;
    for(int i=0;i<k;i++){
        Node*tep=head->next;
        head->next=ptr;
        ptr=head;//ptr遍历结束后成为了当前组的头部
        head=tep;//head遍历结束后成为了下一组的头部
    }
    cur->next=LC25_reverseKGroup(head,k);
    return ptr;
}
void List::Test_LC25_reverseKGroup(){
    Cleanup cle;
    vector<int>lists=cle.RandVector(10,-20,55,10);
    int k=cle.RandNum(1,lists.size()/2-1,100);
    ListNode l1(lists);
    l1.List_Print();
    l1.Head()->next=LC25_reverseKGroup(l1.Head()->next,k);
    cout<<k<<endl;
    l1.List_Print();
}

/// @brief LCR 077 链表排序
/// @param head 
/// @return 
Node*List::LCR077_SortList(Node*head){
    return ToMidList(head,nullptr);
}
Node*List::ToMidList(Node*left,Node*right){
    if(left->next==right)return left;
    Node*mid=SandQ(left,right);
    Node*Nhead=mid->next;
    mid->next=nullptr;
    return Merge(ToMidList(left,mid->next),ToMidList(Nhead,right));

}
Node*List::SandQ(Node*start,Node*right){
    Node*q=start,*s=start;
    while(q->next&&q->next->next){
        q=q->next->next;
        s=s->next;
    }
    return s;
}
Node*List::Merge(Node*start,Node*Mid){
    Node*head;
    Node*s1;
    Node*e1,*e2;
    if(start->val<Mid->val){
        head=start;
        s1=head;
        e1=s1->next;
        e2=Mid;
    }else{
        head=Mid;
        s1=head;
        e1=s1->next;
        e2=start;
    }
    while(e1||e2){
        if(e1==nullptr){
            s1->next=e2;
            break;
        }else if(e2==nullptr)break;
        else if(e2->val<e1->val){
            Node*temp=e1;
            s1->next=e2;
            e1=e2;
            e2=temp;
        }
        s1=e1;
        e1=e1->next;
    }
    return head;
}

Node*List::LCR077_SortList_Beta(Node*head){
    int n=0;
    Node*cur=head;
    while(cur){
        n++;
        cur=cur->next;
    }
    //l1...r1 每组左边部分
    //l2...r2 每组右边部分
    //next 下一组的开头
    //lastTeamEnd 就是上一组的结尾
    Node*l1,*r1,*l2,*r2,*next,*lastTeamEnd;
    for(int step=1;step<n;step<<=1){//开区间
        //每一个步长的第一步特殊处理
        //关系到整个链表的头部结点
        l1=head;
        r1=FindEnd(l1,step);
        l2=r1->next;
        r2=FindEnd(l2,step);
        next=r2->next;
        //将两组的尾部赋空
        r1->next=nullptr;
        r2->next=nullptr;
        //开始排序
        Merge_Beat(l1,r1,l2,r2);
        //使每个步长的第一组的头步成为整个链表的头部
        head=start;
        //记录排序后的尾部
        lastTeamEnd=end;
        //处理其他组
        while(next){
            l1=next;
            r1=FindEnd(l1,step);
            l2=r1->next;
            //如果最后面分不出一组直接退出本轮步长
            if(l2==nullptr){
                lastTeamEnd->next=l1;
                break;
            }
            r2=FindEnd(l2,step);
            next=r2->next;
            r1->next=nullptr;
            r2->next=nullptr;
            Merge_Beat(l1,r1,l2,r2);
            lastTeamEnd->next=start;
            lastTeamEnd=end;
        }
    }
    return head;
}
Node*List::FindEnd(Node*list,int step){
    while(list->next&&--step)list=list->next;
    return list;
}
void List::Merge_Beat(Node*l1,Node*r1,Node*l2,Node*r2){
    Node*pre;
    if(l1->val<l2->val){
        start=l1;
        pre=l1;
        l1=l1->next;
    }else{
        start=l2;
        pre=l2;
        l2=l2->next;
    }
    while(l1&&l2){
        if(l1->val<l2->val){
            pre->next=l1;
            pre=l1;
            l1=l1->next;
        }else{
            pre->next=l2;
            pre=l2;
            l2=l2->next;
        }
    }
    if(!l1){
        pre->next=l2;
        end=r2;
    }else{
        pre->next=l1;
        end=r1;
    }
}
void List::Test_LCR077_SortList(){
    vector<int>nums={-1,5,3,4,0};
    ListNode list1(nums);
    list1.Head()->next=LCR077_SortList_Beta(list1.Head()->next);
    list1.List_Print();
}
int main(int argc,char*argv[]){
    chrono::_V2::system_clock::time_point start=chrono::system_clock::now();

    List ls;
    ls.Test_LCR077_SortList();

    chrono::_V2::system_clock::time_point end=chrono::system_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(end-start);
    cout<<"共花费："<<duration.count()<<" ms "<<endl;

    while(getchar()!='\n')continue;
    getchar();
    return 0;
}
