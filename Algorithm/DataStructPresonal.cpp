#include"DataStructPresonal.h"
using namespace std;
/// @brief 哈希表的SetAll功能
/// @param key 
/// @param value 
void SetAllS::Put(int key,int value){
    pair<int,int>p;
    p.first=value;
    p.second=time_cnts_++;
    map_[key]=p;
}
int SetAllS::Get(int key){
    if(bool_setall_==false)return map_[key].first;
    if(time_setall_>map_[key].second)return map_[key].first;
    else return value_setall_;
}
bool SetAllS::Constainkey(int key){
    return map_.count(key);
}
void SetAllS::SetAll(int value){
    value_setall_=value;
    time_setall_=time_cnts_++;
}
void SetAllS::UsSetAllS(){
    Cleanup cle;
    vector<int>key=cle.RandVector(10,0,7,10);
    vector<int>value=cle.RandVector(10,-33,16,51);
    vector<double>priced=cle.RandVector(10,0.0,1.0,73);
    cle.Print(key);
    cle.Print(value);
    for(int i=0;i<10;i++){
        if(priced[i]<0.25){
            Put(key[i],value[i]);
            cout<<"Put!"<<endl;
        }else if(priced[i]<0.5){
            cout<<"Get("<<key[i]<<","<<Get(key[i])<<")"<<endl;

        }else if(priced[i]<0.75){
            if(Constainkey(key[i]))cout<<"True!"<<endl;
            else cout<<"false!"<<endl;
        }else{
            SetAll(value[i]);
            cout<<"SetAll!"<<endl;
        }
    }
}

/// @brief LRU缓存
/// @param capacity 
LRU::LRU(int capacity):capacity_(capacity){
    head_=new DouList();
    tail_=new DouList();
    head_->next=tail_;
    tail_->prev=head_;

}
void LRU::Put(int key,int value){
    if(map_.count(key)){
        map_[key]->val=value;
        map_[key]->key=key;
        RemoveThis(map_[key]);
        Insert(map_[key]);
    }
    else{
        if(capacity_>size){
            DouList*ptr=new DouList(key,value);
            Insert(ptr);
            map_[key]=ptr;
            size++;
        }else{
            DouList*node=Rmove();
            map_.erase(node->key);
            delete node;
            DouList*ptr=new DouList(key,value);
            Insert(ptr);
            map_[key]=ptr;
        }
    }
}
int LRU::Get(int key){
    if(map_.count(key)){
        RemoveThis(map_[key]);
        Insert(map_[key]);
        return map_[key]->val;
    }
    else return -1;
}
void LRU::Insert(DouList*node){
    node->next=head_->next;
    head_->next->prev=node;
    head_->next=node;
    node->prev=head_;
}
DouList*LRU::Rmove(){
    DouList*ptr=tail_->prev;
    ptr->prev->next=tail_;
    tail_->prev=ptr->prev;
    return ptr;
}
void LRU::RemoveThis(DouList*node){
    node->next->prev=node->prev;
    node->prev->next=node->next;
}
LRU::~LRU(){
    while(size--){
        DouList*ptr=Rmove();
        delete ptr;
        ptr=nullptr;
    }
    delete head_;
    delete tail_;
}
void LRU::Test_LRU(){
    Put(2,1);
    Put(1,1);
    Put(2,3);
    Put(4,1);
    cout<<Get(1)<<endl;
    cout<<Get(2)<<endl;
}

/// @brief 插入、删除和随机获取元素O(1)
/// @param val 
/// @return 
bool RandomizedSet::insert(int val){
    if(map_.count(val))return false;
    nums_.push_back(val);
    size_++;
    map_[val]=size_-1;
    return true;
}
bool RandomizedSet::remove(int val){
    if(!map_.count(val))return false;
    int index=map_[val];
    Swap(index,size_-1);
    int num=nums_[size_-1];
    nums_.pop_back();
    map_.erase(num);
    if(index==size_-1){
        size_--;
        return true;
    }
    map_[nums_[index]]=index;
    size_--;
    return true;
}
int RandomizedSet::getRandom(){
    std::default_random_engine e;
    std::uniform_int_distribution<int>u(0,size_-1);
    e.seed(time(0));
    return nums_[u(e)];
}
void RandomizedSet::Swap(int l,int r){
    int temp=nums_[l];
    nums_[l]=nums_[r];
    nums_[r]=temp;
}
void RandomizedSet::Test_RandomizedSet(){
    
    remove(0);
    remove(0);
    insert(0);
    getRandom();
    remove(0);
    insert(0);

}
/// @brief 插入、删除和随机获取元素O(1)元素可重复插入
/// @param val 
/// @return 
bool RandomizedCollection::insert(int val){
    bool flag=true;
    if(map_.count(val))flag=false;
    nums_.push_back(val);
    size_++;
    map_[val].insert(size_-1);
    return flag;
}
bool RandomizedCollection::remove(int val){
    if(!map_.count(val))return false;
    auto index=*map_[val].begin();
    Swap(index,size_-1);
    int num=nums_.back();
    //删除map中的元素，以及修改交换后的map中的元素
    if(nums_[index]==num){
        map_[nums_[index]].erase(size_-1);
    }else{
        map_[nums_[index]].insert(index);
        map_[nums_[index]].erase(size_-1);
        map_[num].erase(index);
    }

    if(map_[num].empty()){
        map_.erase(num);
    }
    nums_.pop_back();
    size_--;
    return true;
}
int RandomizedCollection::getRandom(){
    int indexRandom=rand()%size_;
    return nums_[indexRandom];
}
void RandomizedCollection::Swap(int l,int r){
    int temp=nums_[l];
    nums_[l]=nums_[r];
    nums_[r]=temp;
}
void RandomizedCollection::Test_RandomizedCollection(){
    insert(9);
    insert(9);
    insert(1);
    insert(1);
    insert(2);
    insert(1);

    remove(2);
    remove(1);
    remove(1);

    insert(9);
    remove(1);
    getRandom();
}

/// @brief 数据流的中位数
/// @param num 
void MedianFinder::addNum(int num){
    if(size_max_==0&&size_min_==0){
        Max_.push(num);
        size_max_++;
    }
    else if(num<Max_.top()){
        Max_.push(num);
        size_max_++;
    }
    else{
        Min_.push(num);
        size_min_++;
    }
    if(abs(size_min_-size_max_)>1){
        if(size_max_>size_min_){
            int n=Max_.top();
            Max_.pop();
            Min_.push(n);
            size_max_--;
            size_min_++;
        }else{
            int n=Min_.top();
            Min_.pop();
            Max_.push(n);
            size_max_++;
            size_min_--;
        }
    }
}
double MedianFinder::findMedian(){
    if((size_max_+size_min_)%2==1){
        if(size_max_>size_min_)return (double)Max_.top();
        else return (double)Min_.top();
    }else{
        return ((double)(Max_.top()+Min_.top()))/2;
    }
}
void MedianFinder::Test_MedianFinder(){
    addNum(1);
    addNum(2);
    cout<<findMedian()<<endl;
    addNum(3);
    cout<<findMedian()<<endl;
}

/// @brief 最大频率栈
/// @param val 
void FreqStack::push(int val){
    if(map_[val]==size_){
        vector<int>nums;
        nums.push_back(val);
        list_.push_back(nums);
        size_++;
        map_[val]++;
    }else{
        list_[map_[val]].push_back(val);
        map_[val]++;
    }
}
int FreqStack::pop(){
    int num=list_[size_-1].back();
    list_[size_-1].pop_back();
    map_[num]--;
    if(list_[size_-1].size()==0){
        list_.pop_back();
        size_--;
    }
    return num;
}
void FreqStack::Test_FreqStack(){
    push(5);
    push(7);
    push(5);
    push(7);
    push(4);
    push(5);
    pop();
    pop();
    pop();
    pop();
}


AllOne::AllOne(){
    head_=new AllNode(0);
    tail_=new AllNode(INT_MAX);
    head_->next=tail_;
    tail_->prev=head_;
}
void AllOne::inc(string key){
    if(!map_.count(key)){
        //第一次出现
        AllNode*ptr=head_->next;
        if(ptr->times==1){
            //已经有1这个桶了
            ptr->words.insert(key);
            map_[key]=ptr;
        }else{
            //还没有1这个桶
            AllNode*node=new AllNode(1);
            node->words.insert(key);
            map_[key]=node;
            addthis(head_,node);
        }
    }else{
        //第n次出现
        AllNode*ptr=map_[key];
        if(ptr->next->times==ptr->times+1){
            //已经有n这个桶了
            ptr->next->words.insert(key);
            map_[key]=ptr->next;
            ptr->words.erase(key);
            if(ptr->words.empty()){
                remove(ptr);
                delete ptr;
            }
        }else{
            AllNode*node=new AllNode(ptr->times+1);
            addthis(ptr,node);
            map_[key]=node;
            node->words.insert(key);
            ptr->words.erase(key);
            if(ptr->words.empty()){
                remove(ptr);
                delete ptr;
            }
        }
    }
}
void AllOne::dec(string key){
    if(!map_.count(key))return;
    AllNode*ptr=map_[key];
    if(ptr->times==1){
        ptr->words.erase(key);
        map_.erase(key);
        if(ptr->words.empty()){
            remove(ptr);
            delete ptr;
        }
    }else{
        if(ptr->prev->times==ptr->times-1){
            ptr->prev->words.insert(key);
            ptr->words.erase(key);
            map_[key]=ptr->prev;
            if(ptr->words.empty()){
                remove(ptr);
                delete ptr;
            }
        }else{
            AllNode*node=new AllNode(ptr->times-1);
            addthis(ptr->prev,node);
            map_[key]=node;
            node->words.insert(key);
            ptr->words.erase(key);
            if(ptr->words.empty()){
                remove(ptr);
                delete ptr;
            }
        }
    }
}
string AllOne::getMaxKey(){
    return *tail_->prev->words.begin();
}
string AllOne::getMinKey(){
    return *head_->prev->words.begin();
}
void AllOne::addthis(AllNode*ptr,AllNode*node){
    ptr->next->prev=node;
    node->next=ptr->next;
    ptr->next=node;
    node->prev=ptr;
}
void AllOne::remove(AllNode*node){
    node->next->prev=node->prev;
    node->prev->next=node->next;
}
AllOne::~AllOne(){
    map_.clear();
    AllNode*ptr=head_->next;
    while(ptr!=tail_){
        AllNode*cur=ptr->next;
        ptr->words.clear();
        remove(ptr);
        delete ptr;
        ptr=cur;
    }
    delete head_;
    delete tail_;
    head_=nullptr;
    tail_=nullptr;
}
void AllOne::Test_AllOne(){
    inc("a");
    inc("b");
    inc("b");
    inc("c");
    inc("c");
    inc("c");
    dec("b");
    dec("b");
    cout<<getMaxKey()<<endl;
    dec("a");
    cout<<getMaxKey()<<endl;
    cout<<getMaxKey()<<endl;

}



int main(int argc,char*argv[]){
    chrono::system_clock::time_point start=chrono::system_clock::now();

    AllOne al;
    al.Test_AllOne();

    //FreqStack fa;
    //fa.Test_FreqStack();



    //MedianFinder me;
    //me.Test_MedianFinder();

    //RandomizedCollection ra;
    //ra.Test_RandomizedCollection();

    //getchar();
    //RandomizedSet set;
    //set.Test_RandomizedSet();


    //getchar();
    //LRU l(2);
    //l.Test_LRU();

    //SetAllS set;
    //set.UsSetAllS();

    chrono::system_clock::time_point end=chrono::system_clock::now();
    auto  duration=chrono::duration_cast<chrono::milliseconds>(end-start);
    cout<<"共花费: "<<duration.count()<<" ms "<<endl;


    while(getchar()!='\n')continue;
    getchar();
    return 0;
}