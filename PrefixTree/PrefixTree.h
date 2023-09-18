#include"../unltle.h"
/// @brief ǰ׺��a-z
struct PrefixNode{
    //�ж��ٸ��ַ���·���˽��
    int pass;
    //�ж��ٸ��ַ����Դ˽���β
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
    //���뵥��
    void Insert(std::string word);
    //���ҵ���word�����˼���
    int Search(std::string word);
    //������prefixΪǰ׺���ַ����ĸ���
    int PrefixNumber(std::string prefix);
    //��ǰ׺�����Ƴ�word,֮ǰ�������ɾ����һ��,���û�в����ʲô������
    void Delete(std::string word);
private:
    void remove_(PrefixNode*ptr,std::string word,int i);
public:
    void Test_Trie();
};

/// @brief ǰ׺����ϣ��
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
    //���뵥��
    void Insert(std::string word);
    //���ҵ���word�����˼���
    int Search(std::string word);
    //������prefixΪǰ׺���ַ����ĸ���
    int PrefixNumber(std::string prefix);
    //��ǰ׺�����Ƴ�word,֮ǰ�������ɾ����һ��,���û�в����ʲô������
    void Delete(std::string word);
private:
    void remove_(PrefixHashNode*ptr,std::string word,int i);
public:
    void Test_TrieHash();
};

/// @brief ǰ׺���ľ�̬����ʵ��
class StaticTrie{
private:
    //������
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
    //�������Ŀռ�
    void clear();
public:
    void Test_StaticTrie();
};
