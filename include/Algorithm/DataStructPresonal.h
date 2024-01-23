#include "RandomNum.h"
#include "unltle.h"

namespace Ricardo {
class SetAllS {
 private:
  int time_cnts_;
  int time_setall_;
  int value_setall_;
  std::unordered_map<int, std::pair<int, int>> map_;
  bool bool_setall_;

 public:
  SetAllS()
      : time_cnts_(0), time_setall_(0), value_setall_(0), bool_setall_(false) {
    ;
  }

 public:
  void Put(int key, int value);
  int Get(int key);
  bool Constainkey(int key);
  void SetAll(int value);

 public:
  void UsSetAllS();
};
struct DouList {
  int key;
  int val;
  DouList* next;
  DouList* prev;
  DouList() : key(0), val(0), next(nullptr), prev(nullptr) { ; }
  DouList(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {
    ;
  }
  DouList(DouList* next, DouList* prev, int key, int val)
      : next(next), prev(prev), key(key), val(val) {
    ;
  }
};
class LRU {
 private:
  DouList* head_;
  DouList* tail_;
  std::unordered_map<int, DouList*> map_;
  int capacity_;
  int size;

 public:
  LRU(int capacity);
  ~LRU();

 public:
  void Put(int key, int value);
  int Get(int key);

 private:
  void Insert(DouList* node);
  DouList* Rmove();
  void RemoveThis(DouList* node);

 public:
  void Test_LRU();
};
class RandomizedSet {
 private:
  std::vector<int> nums_;
  std::unordered_map<int, int> map_;
  int size_;

 public:
  RandomizedSet() : size_(0) { ; }

 public:
  bool insert(int val);
  bool remove(int val);
  int getRandom();
  void Swap(int l, int r);

 public:
  void Test_RandomizedSet();
};
class RandomizedCollection {
 private:
  std::vector<int> nums_;
  std::unordered_map<int, std::unordered_set<int>> map_;
  int size_;

 public:
  RandomizedCollection() : size_(0) { ; }
  ~RandomizedCollection() { ; }

 public:
  bool insert(int val);
  bool remove(int val);
  int getRandom();
  void Swap(int l, int r);

 public:
  void Test_RandomizedCollection();
};
class MedianFinder {
 private:
  std::priority_queue<int, std::vector<int>, std::less<int>> Max_;
  std::priority_queue<int, std::vector<int>, std::greater<int>> Min_;
  int size_max_;
  int size_min_;

 public:
  MedianFinder() : size_max_(0), size_min_(0) { ; }

 public:
  void addNum(int num);
  double findMedian();

 public:
  void Test_MedianFinder();
};
class FreqStack {
  std::vector<std::vector<int>> list_;
  std::unordered_map<int, int> map_;
  int size_;

 public:
  FreqStack() : size_(0) { ; }

 public:
  void push(int val);
  int pop();

 public:
  void Test_FreqStack();
};
struct AllNode {
  int times;
  std::unordered_set<std::string> words;
  AllNode* next;
  AllNode* prev;
  AllNode() : times(0), next(nullptr), prev(nullptr) { ; }
  AllNode(int times) : times(times), next(nullptr), prev(nullptr) { ; }
};
class AllOne {
 private:
  std::unordered_map<std::string, AllNode*> map_;
  AllNode* head_;
  AllNode* tail_;

 public:
  AllOne();
  ~AllOne();

 public:
  void inc(std::string key);
  void dec(std::string key);
  std::string getMaxKey();
  std::string getMinKey();

 private:
  void addthis(AllNode* ptr, AllNode* node);
  void remove(AllNode* node);

 public:
  void Test_AllOne();
};
}  // namespace Ricardo
