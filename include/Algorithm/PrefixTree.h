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
class Prefix{
private:
    /*构建前缀和最早出现的位置。返回无序数组中累加和为给定值的最长子数组长度*/
    int LongestSubarraySumEqualsAim_(std::vector<int>nums,int aim);
public:
    /*累加和为给定值的最长子数组长度*/
    void Test_LongestSubarraySumEqualsAim();
private:
    /*给你一个整数数组 nums 和一个整数 k ，
    请你统计并返回 该数组中和为 k 的连续子数组的个数 。
    子数组是数组中元素的连续非空序列。
    示例 1：
    输入：nums = [1,1,1], k = 2
    输出：2
    示例 2：
    输入：nums = [1,2,3], k = 3
    输出：2*/
    int LC560_subarraySum_(std::vector<int>&nums,int k);
public:
    /*LeetCode 60 和为k的子数组*/
    void Test_LC560_subarraySum();
private:
    /*给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。
    我们认为当员工一天中的工作小时数大于 8 小时的时候，
    那么这一天就是「劳累的一天」。
    所谓「表现良好的时间段」，意味在这段时间内，
    「劳累的天数」是严格 大于「不劳累的天数」。
    请你返回「表现良好时间段」的最大长度。
    示例 1：
    输入：hours = [9,9,6,0,6,6,9]
    输出：3
    解释：最长的表现良好时间段是 [9,9,6]。
    示例 2：
    输入：hours = [6,6,6]
    输出：0*/
    int LC1124_longestWPI_(std::vector<int>hours);
public:
    /*LeetCode 1124 表现良好的最长时间段*/
    void Test_LC1124_longestWPI();
private:
    /*给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），
    使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
    请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
    子数组 定义为原数组中连续的一组元素。
    示例 1：
    输入：nums = [3,1,4,2], p = 6
    输出：1
    解释：nums 中元素和为 10，不能被 p 整除。我们可以移除子数组 [4] ，剩余元素的和为 6 。
    示例 2：
    输入：nums = [6,3,5,2], p = 9
    输出：2
    解释：我们无法移除任何一个元素使得和被 9 整除，最优方案是移除子数组 [5,2] ，剩余元素为 [6,3]，和为 9 。
    示例 3：
    输入：nums = [1,2,3], p = 3
    输出：0
    解释：和恰好为 6 ，已经能被 3 整除了。所以我们不需要移除任何元素。
    示例  4：
    输入：nums = [1,2,3], p = 7
    输出：-1
    解释：没有任何方案使得移除子数组后剩余元素的和被 7 整除。
    示例 5：
    输入：nums = [1000000000,1000000000,1000000000], p = 3
    输出：0*/
    int LC1590_minSubarray_(std::vector<int>&nums,int p);
public:
    /*LeetCode 1590 可以被p整除的最小要删掉的子数组的长度*/
    void Test_LC1590_minSubarray();
private:
    /*给你一个字符串 s ，
    请你返回满足以下条件的最长子字符串的长度：每个元音字母，
    即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。
    示例 1：
    输入：s = "eleetminicoworoep"
    输出：13
    解释：最长子字符串是 "leetminicowor" ，
    它包含 e，i，o 各 2 个，以及 0 个 a，u 。
    示例 2：
    输入：s = "leetcodeisgreat"
    输出：5
    解释：最长子字符串是 "leetc" ，其中包含 2 个 e 。
    示例 3：
    输入：s = "bcbcbc"
    输出：6
    解释：这个示例中，字符串 "bcbcbc" 本身就是最长的，
    因为所有的元音 a，e，i，o，u 都出现了 0 次。
    提示：
    1 <= s.length <= 5 x 10^5
    s 只包含小写英文字母。*/
    int LC1371_findTheLongestSubstring_(std::string s);
    /*元音的提取*/
    int LC1371_findTheLongestSubstring_move_(char a);
public:
    void Test_LC1371_findTheLongestSubstring();
};

namespace CountConsistenKeys{
using std::vector;
    static int MAXN=150001;
    vector<vector<int>>tree(MAXN,vector<int>(12,0));
    vector<int>pass(MAXN,0);
    vector<int>end(MAXN,0);
    int cnt;
    void build();
    void Insert(std::string word);
    int Serach(std::string word);
    int PrefixNumber(std::string prefix);
    int Path(char ch);
    void remove(std::string word);
    void Clear();
    /*接头密钥
    牛牛和他的朋友们约定了一套接头密钥系统用于识别彼此身份
    密钥由一组数字序列表示，两个密钥被认定为是一致的，如果满足以下条件
    密钥b的长度不会超过密钥a
    对于任意的0<=i<length(b),有b[i+1]-b[i]==a[i+1]-a[i]
    现在给定了m个密钥b的数组，以及n个密钥a的数组
    请你返回一个长度为m的结果数组ans表示每个密钥b都有多少一致的密钥
    数组a和数组b中的元素个数均不超过10^5
    1<=m,n<=1000*/
    /*前缀树方法时间：O( a数组的数字个数*10)+O(b数组的数字个数*10)
    空间：O(a数组的数字个数*10 )*/
    vector<int> countConsistenKeys(std::vector<std::vector<int>>b,std::vector<std::vector<int>>a);

    void Test_CountConsistenKeys();
}
namespace LC421{
    using std::vector;
    using std::string;
    static int MAXN=150001;
    vector<vector<int>>tree(MAXN,vector<int>(2,0));
    int cnt;
    int left;

    void build(vector<int>nums);
    void Insert(int num);
    int maxXor(int num);
    void Clear();

    /*给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，
    其中 0 ≤ i ≤ j < n 。
    示例 1：
    输入：nums = [3,10,5,25,2,8]
    输出：28
    解释：最大运算结果是 5 XOR 25 = 28.
    示例 2：
    输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
    输出：127*/
    int LC421_findMaximumXOR(std::vector<int>&nums);
    //哈希表的实现
    int LC421_findMaximumXOR_Hash(std::vector<int>nums);
    void Test_LC421_findMaximumXOR();
}
    /*给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，
    返回所有二维网格上的单词 。
    单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，
    其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
    同一个单元格内的字母在一个单词中不允许被重复使用。*/
namespace LC212{
    static int MAXN=150001;
    using std::vector;
    using std::string;
    vector<vector<int>>tree(MAXN,vector<int>(26,0));
    vector<int>pass(MAXN);
    vector<string>end(MAXN,"");
    int cnt;
    void build(vector<string>words);
    void Insert(string word);
    void Clear();

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
    int dfs(vector<vector<char>>&board,int i,int j,int t,vector<string>&ans);
}
namespace LC1803{
    using std::vector;
    using std::cout;
    using std::endl;
    static int MAXN=1400001;
    static int BiTSize=14;
    vector<vector<int>>tree(MAXN,vector<int>(2,-2));
    vector<int>pass(MAXN,0);
    int cnt;
    void Build();
    void Insert(int num);
    int Get(int val,int num);

    int countPairs(vector<int>& nums, int low, int high);
    void LC1830_countPairs();
}
