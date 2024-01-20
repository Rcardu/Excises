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

/// @brief 累加和为给定值的最长子数组长度
/// @param nums 
/// @param aim 
/// @return 
int Prefix::LongestSubarraySumEqualsAim_(vector<int>nums,int aim){
    unordered_map<int,int>map;
    //0这个前缀和在一个数字也没有的时候就存在了
    map[0]=-1;
    int sum=0;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(map.count(sum-aim))ans=max(ans,i-map[sum-aim]);
        if(!map.count(sum))map[sum]=i;
    }
    //累加和等于aim的最大长度
    
    return ans;
}
void Prefix::Test_LongestSubarraySumEqualsAim(){
    vector<int>nums={2, 0, 3, -5, 2, -1};
    cout<<LongestSubarraySumEqualsAim_(nums,0)<<endl;
}

/// @brief LeetCode 60 和为k的子数组
/// @param nums 
/// @param k 
/// @return 
int Prefix::LC560_subarraySum_(std::vector<int>&nums,int k){
    unordered_map<int,int>map;
    map[0]=1;
    int sum=0;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        ans+=map[sum-k];
        map[sum]++;
    }
    return ans;
}
void Prefix::Test_LC560_subarraySum(){
    vector<int>nums={-1,-1,1};
    cout<<LC560_subarraySum_(nums,0)<<endl;
}

/// @brief LeetCode 1124 表现良好的最长时间段
/// @param hours 
/// @return 
int Prefix::LC1124_longestWPI_(vector<int>hours){
    unordered_map<int,int>map;
    map[0]=-1;
    int sum=0;
    int ans=0;
    for(int i=0;i<hours.size();i++){
        sum+=hours[i]>8?1:-1;
        if(sum>0)ans=i+1;
        else{
            if(map.count(sum-1))ans=max(ans,i-map[sum-1]);
        }
        if(!map.count(sum))map[sum]=i;
    }
    return ans;
}
void Prefix::Test_LC1124_longestWPI(){
    vector<int>nums;
    LC1124_longestWPI_(nums);
}

/// @brief LeetCode 1590 可以被p整除的最小要删掉的子数组的长度
/// @param nums 
/// @param p 
/// @return 
int Prefix::LC1590_minSubarray_(vector<int>&nums,int p){
    int mod=0;
    for(int num:nums)mod=(mod+num)%p;
    if(mod==0)return 0;
    unordered_map<int,int>map;
    map[0]=-1;
    int ans=INT_MAX;
    for(int i=0,cur=0,find;i<nums.size();i++){
        cur=(cur+nums[i])%p;
        //find=cur>=mod?cur-mod:(cur+p-mod);
        find=(cur+p-mod)%p;
        if(map.count(find))ans=min(ans,i-map[find]);
        map[cur]=i;
    }
    return ans==nums.size()?-1:ans;
}
void Prefix::Test_LC1590_minSubarray(){
    vector<int>nums;
    LC1590_minSubarray_(nums,2);
}


int Prefix::LC1371_findTheLongestSubstring_(string s){
    //用-2表示这个状态之前没出现过
    vector<int>map(32,-2);
    //0:00000
    //天然是偶数状态
    map[0]=-1;
    int ans=0;
    for(int i=0,status=0;i<s.size();i++){
        //status:0....i字符上，aeiou的奇偶性
        //s[i]=当前字符
        //case 1:当前字符不是元音字符
        //case 2:当前字符是元音
        int m=LC1371_findTheLongestSubstring_move_(s[i]);
        if(m!=-1){
            status^=1<<m;
        }
        if(map[status]!=-2)ans=max(ans,i-map[status]);
        else map[status]=i;
    }
    return ans;
}
int Prefix::LC1371_findTheLongestSubstring_move_(char a){
    switch(a){
        case 'a':return 0;
        case 'e':return 1;
        case 'i':return 2;
        case 'o':return 3;
        case 'u':return 4;
        default:return -1;
    }
}
void Prefix::Test_LC1371_findTheLongestSubstring(){
    string s;
    LC1371_findTheLongestSubstring_(s);
}

/// @brief 接头密钥
namespace CountConsistenKeys{
    extern vector<vector<int>>tree;
    extern vector<int>pass;
    extern vector<int>end;
    extern int cnt;


    void build(){cnt=1;}
    void Insert(string word){
        int cur=1;
        pass[cur]++;
        for(int i=0,path;i<word.size();i++){
            path=Path(word[i]);
            if(tree[cur][path]==0)tree[cur][path]=++cnt;
            cur=tree[cur][path];
            pass[cur]++;
        }
        end[cur]++;
    }
    int Serach(string word){
        int cur=1;
        for(int i=0,path;i<word.size();i++){
            path=Path(word[i]);
            if(tree[cur][path]==0)return 0;
            cur=tree[cur][path];
        }
        return end[cur];
    }
    int PrefixNumber(string prefix){
        int cur=1;
        for(int i=0,path;i<prefix.size();i++){
            path=Path(prefix[i]);
            if(tree[cur][path]==0)return 0;
            cur=tree[cur][path];
        }
        return pass[cur];
    }
    int Path(char ch){
        if(ch-'#'==0)return 10;
        else if(ch-'-'==0)return 11;
        else return ch-'0';
    }
    void remove(string word){
        if(Serach(word)<1)return;
        int cur=1;
        pass[cur]--;
        for(int i=0,path;i<word.size();i++){
            path=Path(word[i]);
            if(--pass[tree[cur][path]]==0){
                tree[cur][path]=0;
                return;
            }
            cur=tree[cur][path];
        }
        end[cur]--;
    }
    void Clear(){
        for(int i=0;i<=cnt;i++){
            for(int j=0;j<tree[i].size();i++)tree[i][j]=0;
            pass[i]=0;
            end[i]=0;
        }
    }

    vector<int> countConsistenKeys(vector<vector<int>>b,vector<vector<int>>a){
        for(int i=0;i<b.size();i++){
            string str;
            for(int j=1;j<b[i].size();j++)str+=to_string(b[i][j]-b[i][j-1])+"#";
            Insert(str);
        }
        vector<int>ans(a.size());
        for(int i=0;i<a.size();i++){
            string str;
            for(int j=1;j<a[i].size();j++)str+=to_string(a[i][j]-a[i][j-1])+"#";
            ans[i]=PrefixNumber(str);
        }
        Clear();
        return ans;
    }
    void Test_CountConsistenKeys(){
        Cleanup cle;
        vector<vector<int>>b={{3,6,12,20},{1,9},{4,7,2},{1,4,-1}};
        vector<vector<int>>a={{2,5},{7,10,5}};
        /*
        for(int i=0;i<10;i++){
            vector<int>nums=cle.RandVector(6,-15,10,i);
            cle.Print(nums);
            if(i%2==0)b.push_back(nums);
            else a.push_back(nums);
        }
        */
        build();
        countConsistenKeys(b,a);
    }
}

namespace LC421{
    void build(vector<int>nums){
        cnt=1;
        int Max=INT_MIN;
        for(int num:nums)Max=max(Max,num);
        //计算最大值的前导0个数，可以忽略这些0，从left开始考虑
        left=32-__builtin_clz(Max);
        for(int num:nums)Insert(num);
    }
    void Insert(int num){
        int cur=1;
        for(int i=left,path;i>=0;i--){
            path=(num>>i)&1;
            if(tree[cur][path]==0)tree[cur][path]=++cnt;
            cur=tree[cur][path];
        }
    }
    int maxXor(int num){
        int ans=0;
        int cur=1;
        for(int i=left,status,want;i>=0;i--){
            status=(num>>i)&1;
            want=status^1;
            if(tree[cur][want]==0)want^=1;
            //如果两个状态相等那么说明没找到想要的状态，直接或进ans
            ans|=(status^want)<<i;
            cur=tree[cur][want];
        }
        return ans;
    }
    void Clear(){
        for(int i=0;i<=cnt;i++){
            tree[i][0]=0;
            tree[i][1]=0;
        }
    }

    int LC421_findMaximumXOR(std::vector<int>&nums){
        build(nums);
        int ans=0;
        for(int num:nums)ans=max(ans,maxXor(num));
        Clear();
        return ans;
    }
    int LC421_findMaximumXOR_Hash(std::vector<int>nums){
        //从最高位为1的地方开始建立ans
        int Max=INT_MIN;
        for(int num:nums)Max=max(Max,num);
        int ans=0;
        unordered_set<int>set;
        for(int i=Max==0?0:(32-__builtin_clz(Max));i>=0;i--){
            //ans就是在保持32……i+1位已生成的情况下
            //第i位能否取到1
            //better：表示第32……i位希望取到的数，也就是第i位希望取到1
            int better=ans|(1<<i);
            set.clear();
            for(int num:nums){
                //每次遍历整个num在考虑第32……第i位，但不考虑第i-1位到第0位的情况下需要取得的数
                num=(num>>i)<<i;
                set.insert(num);
                /*如果存在一个num' 使得num'^num的值就是better
                那么这个值num'^num=better等价于ans^num=num'
                我们希望在遍历的过程中能在set中找到这个值即，num'*/
                if(set.count(better^ans)){
                    //那么ans就可以成为better
                    ans=better;
                    break;
                }
            }
        }
        return ans;
    }
    void Test_LC421_findMaximumXOR(){
        vector<int>nums={1};
        cout<<LC421_findMaximumXOR_Hash(nums)<<endl;
    }
}


namespace LC212{
    void build(vector<string>words){
        cnt=1;
        for(string str:words)Insert(str);
    }
    void Insert(string word){
        int cur=1;
        pass[cur]++;
        for(int i=0,path;i<word.size();i++){
            path=word[i]-'a';
            if(tree[cur][path]==0)tree[cur][path]=++cnt;
            cur=tree[cur][path];
            pass[cur]++;
        }
        end[cur]=word;
    }
    void Clear(){
        for(int i=0;i<=cnt;i++){
            for(int j=0;j<26;j++)tree[i][j]=0;
            end[i]="";
            pass[i]=0;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        build(words);
        vector<string>ans;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                dfs(board,i,j,1,ans);
            }
        }
        return ans;
    }
    //(i,j)当前所在网格
    //t前缀树的编号
    int dfs(vector<vector<char>>&board,int i,int j,int t,vector<string>&ans){
        //越界或者重复走了路
        if(i<0||i==board.size()||j<0||j<board[0].size()||board[i][j]==0)return 0;
        char tmp=board[i][j];
        int road=tmp-'a';
        t=tree[t][road];
        if(t==0||pass[t]==0)return 0;
        //从当前位置出发一共收集到几个字符串
        int fix=0;
        if(end[t]!=""){
            fix++;
            ans.push_back(end[t]);
            end[t]="";
        }
        board[i][j]=0;
        fix+=dfs(board,i-1,j,t,ans);
        fix+=dfs(board,i+1,j,t,ans);
        fix+=dfs(board,i,j-1,t,ans);
        fix+=dfs(board,i,j+1,t,ans);
        pass[t]-=fix;
        board[i][j]=tmp;
        return fix;
    }
}
namespace LC1803{
    void Build(){
        cnt=1;
    }
    void Insert(int num){
        int cur=1;
        pass[cur]++;
        for(int i=BiTSize,path;i>=0;i--){
            path=(num>>i)&1;
            if(tree[cur][path]==-2)tree[cur][path]=++cnt;
            cur=tree[cur][path];
            pass[cur]++;
        }
    }
    int Get(int val,int num){
        int cur=1;
        int ans=0;
        for(int i=BiTSize,path;i>=0;i--){
            path=(num>>i)&1;
            //如果val的第i位上是1的话
            if((val>>i)&1){
                //字典书中的这一位存在
                //在此树下的所有路过结点都记录
                if(tree[cur][path]!=-2)ans+=pass[tree[cur][path]];
                //如果不存在，且他的异或值也不存在，就直接返回
                if(tree[cur][path^1]==-2)return ans;
                //存在就去他的异或子节点
                cur=tree[cur][path^1];
            }else{
                //如果val的第i位上不是1，且字典上还存在num的第i位的话就继续
                if(tree[cur][path]==-2)return ans;
                cur=tree[cur][path];
            }
        }
        ans+=pass[cur];
        return ans;
    }
    int countPairs(vector<int>& nums, int low, int high){
        int ans=0;
        for(int i=1;i<nums.size();i++){
            Insert(nums[i-1]);
            int h=Get(high,nums[i]);
            int l=Get(low-1,nums[i]);
            ans+=h-l;
        }
        return ans;
    }
    void LC1830_countPairs(){
        Build();
        vector<int>nums={1,4,2,7};
        cout<<countPairs(nums,2,6)<<endl;
    }
}

int main(int argc,char*argv[]){
    auto start=chrono::system_clock::now();

    using LC1803::LC1830_countPairs;
    LC1830_countPairs();

    //using LC421::Test_LC421_findMaximumXOR;
    //Test_LC421_findMaximumXOR();
    //cout<<__builtin_clz(7)<<endl;


    //using CountConsistenKeys::Test_CountConsistenKeys;
    //Test_CountConsistenKeys();

    //Prefix pre;
    //pre.Test_LC560_subarraySum();

    //StaticTrie tr;
    //tr.Test_StaticTrie();
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
