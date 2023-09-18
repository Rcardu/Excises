#include"../unltle.h"
/// @brief 前缀树a-z
struct PrefixNode{
    //有多少个字符串路过此结点
    int pass;
    //有多少个字符串以此结点结尾
    int end;
    std::vector<PrefixNode*>child;
    PrefixNode():pass(0),end(0){child.resize(26,nullptr);}
};
class Trie{
private:
    PrefixNode*root_;
    std::unordered_map<std::string,int>map_;
public:
    Trie(){
        root_=new PrefixNode();
    }
    ~Trie(){
        for(auto&m:map_){
            if(map_[m.first]==0)continue;
            int times=m.second;
            for(int i=0;i<times;i++)Delete(m.first);
        }
        map_.clear();
        delete root_;
        root_=nullptr;
    }
public:
    //插入单词
    void Insert(std::string word);
    //查找单词word出现了几次
    int Search(std::string word);
    //查找以prefix为前缀的字符串的个数
    int PrefixNumber(std::string prefix);
    //从前缀树中移除word,之前插入过，删除掉一次,如果没有插入过什么都不做
    void Delete(std::string word);
private:
    void remove_(PrefixNode*ptr,std::string word,int i);
public:
    void Test_Trie();
};

/// @brief 前缀树哈希表
struct PrefixHashNode{
    int pass;
    int end;
    std::unordered_map<int,PrefixHashNode*>child;
    PrefixHashNode():pass(0),end(0){;}
};
class TrieHash{
private:
    PrefixHashNode*root_;
    std::unordered_map<std::string,int>map_;
public:
    TrieHash(){
        root_=new PrefixHashNode();
    }
    ~TrieHash(){
        for(auto&m:map_){
            if(map_[m.first]==0)continue;
            int times=m.second;
            for(int i=0;i<times;i++)Delete(m.first);
        }
        map_.clear();
        delete root_;
        root_=nullptr;
    }
public:
    //插入单词
    void Insert(std::string word);
    //查找单词word出现了几次
    int Search(std::string word);
    //查找以prefix为前缀的字符串的个数
    int PrefixNumber(std::string prefix);
    //从前缀树中移除word,之前插入过，删除掉一次,如果没有插入过什么都不做
    void Delete(std::string word);
private:
    void remove_(PrefixHashNode*ptr,std::string word,int i);
public:
    void Test_TrieHash();
};

/// @brief 前缀树的静态数组实现
class StaticTrie{
private:
    //数据量
    static const int MAXN=150001;
    std::vector<std::vector<int>>tree;
    std::vector<int>end;
    std::vector<int>pass;
    int cnt;
public:
    StaticTrie():cnt(1){
        tree=std::vector<std::vector<int>>(MAXN,std::vector<int>(26,0));
        end=std::vector<int>(MAXN,0);
        pass=std::vector<int>(MAXN,0);
    }
    void build(){cnt=1;}
    void Insert(std::string word);
    int Search(std::string word);
    int PrefixNumber(std::string prefix);
    void Delete(std::string word);
public:
    //清除数组的空间
    void clear();
public:
    void Test_StaticTrie();
};
