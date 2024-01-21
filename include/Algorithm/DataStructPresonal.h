#include"../unltle.h"
//利用哈希表的操作将哈希表添加一个功能
//SetAll在O（1）时间内修改表内的内容为输入的内容
class SetAllS{
private:
    //时间戳
    int time_cnts_;
    //SetAll时间戳与值
    int time_setall_;
    int value_setall_;
    //哈希表(key,(value,time))；
    std::unordered_map<int,std::pair<int,int>>map_;
    //SetAll是否已被设置过
    bool bool_setall_;
public:
    SetAllS():time_cnts_(0),time_setall_(0),value_setall_(0),bool_setall_(false){;}
public:
    void Put(int key,int value);
    int Get(int key);
    bool Constainkey(int key);
    void SetAll(int value);
public:
    void UsSetAllS();
};
//LRU缓存
struct DouList{
    int key;
    int val;
    DouList*next;
    DouList*prev;
    DouList():key(0),val(0),next(nullptr),prev(nullptr){;}
    DouList(int key,int val):key(key),val(val),next(nullptr),prev(nullptr){;}
    DouList(DouList*next,DouList*prev,int key,int val):next(next),prev(prev),key(key),val(val){;}
};
class LRU{
private:
    DouList*head_;
    DouList*tail_;
    std::unordered_map<int,DouList*>map_;
    int capacity_;
    int size;
public:
    LRU(int capacity);
    ~LRU();
public:
    void Put(int key,int value);
    int Get(int key);
private:
    //插入当前结点
    void Insert(DouList*node);
    //删除最后一个结点
    DouList* Rmove();
    //删除当前结点
    void RemoveThis(DouList*node);
public:
    void Test_LRU();
};
//插入、删除和随机获取元素O(1)
class RandomizedSet{
private:
    std::vector<int>nums_;
    std::unordered_map<int,int>map_;
    int size_;
public:
    RandomizedSet():size_(0){;}
public:
    bool insert(int val);
    bool remove(int val);
    int getRandom();
    void Swap(int l,int r);
public:
    void Test_RandomizedSet();

};
//插入、删除和随机获取元素O(1)元素可重复插入
class RandomizedCollection{
private:
    std::vector<int>nums_;
    std::unordered_map<int,std::unordered_set<int>>map_;
    int size_;
public:
    RandomizedCollection():size_(0){;}
    ~RandomizedCollection(){;}
public:
    bool insert(int val);
    bool remove(int val);
    int getRandom();
    void Swap(int l,int r);
public:
    void Test_RandomizedCollection();
};
//数据流的中位数
class MedianFinder{
private:
    std::priority_queue<int,std::vector<int>,std::less<int>>Max_;
    std::priority_queue<int,std::vector<int>,std::greater<int>>Min_;
    int size_max_;
    int size_min_;
public:
    MedianFinder():size_max_(0),size_min_(0){;}
public:
    void addNum(int num);
    double findMedian();
public:
    void Test_MedianFinder();
};
//最大频率栈
class FreqStack{
    std::vector<std::vector<int>>list_;
    std::unordered_map<int,int>map_;
    int size_;
public:
    FreqStack():size_(0){;}
public:
    void push(int val);
    int pop();
public:
    void Test_FreqStack();
};
//全O(1)数据结构
struct AllNode{
    int times;
    std::unordered_set<std::string>words;
    AllNode*next;
    AllNode*prev;
    AllNode():times(0),next(nullptr),prev(nullptr){;}
    AllNode(int times):times(times),next(nullptr),prev(nullptr){;}
};
class AllOne{
private:
    std::unordered_map<std::string,AllNode*>map_;
    AllNode*head_;
    AllNode*tail_;
public:
    AllOne();
    ~AllOne();
public:
    void inc(std::string key);
    void dec(std::string key);
    std::string getMaxKey();
    std::string getMinKey();
private:
    //添加这个桶在这里
    void addthis(AllNode*ptr,AllNode*node);
    //删除这个桶
    void remove(AllNode*node);
public:
    void Test_AllOne();
};


