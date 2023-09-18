#include"PrefixTree.h"
using namespace std;

/// @brief 前缀树a-z
/// @param word 
void Trie::Insert(string word){
    map_[word]++;
    PrefixNode*node=root_;
    node->pass++;
    for(int i=0,path;i<word.size();i++){
        path=word[i]-'a';
        if(node->child[path]==nullptr)node->child[path]=new PrefixNode();
        node=node->child[path];
        node->pass++;
    }
    node->end++;
}
int Trie::Search(string word){
    PrefixNode*node=root_;
    for(int i=0,path;i<word.size();i++){
        path=word[i]-'a';
        if(node->child[path]==nullptr)return 0;
        node=node->child[path];
    }
    return node->end;
}
int Trie::PrefixNumber(string prefix){
    PrefixNode*node=root_;
    for(int i=0,path;i<prefix.size();i++){
        path=prefix[i]-'a';
        if(node->child[path]==nullptr)return 0;
        node=node->child[path];
    }
    return node->pass;
}
void Trie::Delete(string word){
    if(Search(word)>0){
        PrefixNode*node=root_;
        node->pass--;
        for(int i=0,path;i<word.size();i++){
            path=word[i]-'a';
            if(--node->child[path]->pass==0){
                remove_(node->child[path],word,i);
                node->child[path]=nullptr;
                map_[word]--;
                return ;
            }
            node=node->child[path];
        }
        node->end--;
        map_[word]--;
    }
}
void Trie::remove_(PrefixNode*ptr,string word,int i){
    for(int j=i,path;j<word.size()-1;j++){
        path=word[j+1]-'a';
        PrefixNode*cur=ptr->child[path];
        delete ptr;
        ptr=cur;
        cur=nullptr;
    }
    delete ptr;
    ptr=nullptr;
}
void Trie::Test_Trie(){
    Insert("abc");
    Insert("abc");
    Insert("acc");
    Insert("ac");
    Insert("acd");
    Insert("abcdef");
    cout<<Search("abc")<<endl;
    cout<<PrefixNumber("ac")<<endl;
    Delete("abcdef");
}

/// @brief 前缀树哈希表实现
/// @param word 
void TrieHash::Insert(string word){
    map_[word]++;
    PrefixHashNode*node=root_;
    node->pass++;
    for(int i=0,path;i<word.size();i++){
        path=word[i]-'\0';
        if(!node->child.count(path))node->child[path]=new PrefixHashNode();
        node=node->child[path];
        node->pass++;
    }
    node->end++;
}
int TrieHash::Search(string word){
    PrefixHashNode*node=root_;
    for(int i=0,path;i<word.size();i++){
        path=word[i]-'\0';
        if(!node->child.count(path))return 0;
        node=node->child[path];
    }
    return node->end;
}
int TrieHash::PrefixNumber(string prefix){
    PrefixHashNode*node=root_;
    for(int i=0,path;i<prefix.size();i++){
        path=prefix[i]-'\0';
        if(!node->child.count(path))return 0;
        node=node->child[path];
    }
    return node->pass;
}
void TrieHash::Delete(string word){
    if(Search(word)>0){
        PrefixHashNode*node=root_;
        node->pass--;
        for(int i=0,path;i<word.size();i++){
            path=word[i]-'\0';
            if(--node->child[path]->pass==0){
                remove_(node->child[path],word,i);
                node->child[path]=nullptr;
                map_[word]--;
                return ;
            }
            node=node->child[path];
        }
        node->end--;
        map_[word]--;
    }
}
void TrieHash::remove_(PrefixHashNode*ptr,string word,int i){
    for(int j=i,path;j<word.size()-1;j++){
        path=word[j+1]-'\0';
        PrefixHashNode*cur=ptr->child[path];
        delete ptr;
        ptr=cur;
        cur=nullptr;
    }
    delete ptr;
    ptr=nullptr;
}
void TrieHash::Test_TrieHash(){
    Insert("abc");
    Insert("abc");
    Insert("acc");
    Insert("ac");
    Insert("acd");
    Insert("abcdef");
    cout<<Search("abc")<<endl;
    cout<<PrefixNumber("ac")<<endl;
    Delete("abcdef");
}

/// @brief 前缀树的静态数组实现
/// @param word 
void StaticTrie::Insert(string word){
    int cur=1;
    pass[cur]++;
    for(int i=0,path;i<word.size();i++){
        path=word[i]-'a';
        if(tree[cur][path]==0){
            tree[cur][path]=++cnt;
        }
        cur=tree[cur][path];
        pass[cur]++;
    }
    end[cur]++;
}
int StaticTrie::Search(string word){
    int cur=1;
    for(int i=0,path;i<word.size();i++){
        path=word[i]-'a';
        if(tree[cur][path]==0)return 0;
        cur=tree[cur][path];
    }
    return end[cur];
}
int StaticTrie::PrefixNumber(string prefix){
    int cur=1;
    for(int i=0,path;i<prefix.size();i++){
        path=prefix[i]-'a';
        if(tree[cur][path]==0)return 0;
        cur=tree[cur][path];
    }
    return pass[cur];
}
void StaticTrie::Delete(string word){
    if(Search(word)>0){
        int cur=1;
        for(int i=0,path;i<word.size();i++){
            path=word[i]-'a';
            if(--pass[tree[cur][path]]==0){
                tree[cur][path]=0;
                return;
            }
            cur=tree[cur][path];
        }
        end[cur]--;
    }
}
void StaticTrie::clear(){
    for(int i=0;i<=cnt;i++){
        for(int j=0;j<26;j++)tree[i][j]=0;
        pass[i]=0;
        end[i]=0;
    }
}
void StaticTrie::Test_StaticTrie(){
    Insert("apple");
    cout<<Search("apple")<<endl;
    cout<<Search("app")<<endl;
    cout<<PrefixNumber("app")<<endl;
    Insert("app");
    cout<<Search("app")<<endl;
}

int main(int argc,char*argv[]){
    auto start=chrono::system_clock::now();
    StaticTrie tr;
    tr.Test_StaticTrie();
    //getchar();
    //char ch='a';

    //getchar();
    //Trie t;
    //t.Test_Trie();

    auto end=chrono::system_clock::now();
    cout<<"运行时长为："<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" ms "<<endl;
    while(getchar()!='\n')continue;
    getchar();
    return 0;
}
