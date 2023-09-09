#include"ListAlgorithm.h"
using namespace std;

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


Node*List::LC25_reverseKGroup(Node*head,int k){
    unordered_map<Node*,Node*>map;
    for(auto m:map){
        
    }
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

int main(int argc,char*argv[]){
    chrono::_V2::system_clock::time_point start=chrono::system_clock::now();

    List ls;
    ls.Test_LC25_reverseKGroup();

    chrono::_V2::system_clock::time_point end=chrono::system_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(end-start);
    cout<<"共花费："<<duration.count()<<" ms "<<endl;

    while(getchar()!='\n')continue;
    getchar();
    return 0;
}
