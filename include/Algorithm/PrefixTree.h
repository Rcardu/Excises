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
class Prefix{
private:
    /*����ǰ׺��������ֵ�λ�á����������������ۼӺ�Ϊ����ֵ��������鳤��*/
    int LongestSubarraySumEqualsAim_(std::vector<int>nums,int aim);
public:
    /*�ۼӺ�Ϊ����ֵ��������鳤��*/
    void Test_LongestSubarraySumEqualsAim();
private:
    /*����һ���������� nums ��һ������ k ��
    ����ͳ�Ʋ����� �������к�Ϊ k ������������ĸ��� ��
    ��������������Ԫ�ص������ǿ����С�
    ʾ�� 1��
    ���룺nums = [1,1,1], k = 2
    �����2
    ʾ�� 2��
    ���룺nums = [1,2,3], k = 3
    �����2*/
    int LC560_subarraySum_(std::vector<int>&nums,int k);
public:
    /*LeetCode 60 ��Ϊk��������*/
    void Test_LC560_subarraySum();
private:
    /*����һ�ݹ���ʱ��� hours�������¼��ĳһλԱ��ÿ��Ĺ���Сʱ����
    ������Ϊ��Ա��һ���еĹ���Сʱ������ 8 Сʱ��ʱ��
    ��ô��һ����ǡ����۵�һ�졹��
    ��ν���������õ�ʱ��Ρ�����ζ�����ʱ���ڣ�
    �����۵����������ϸ� ���ڡ������۵���������
    ���㷵�ء���������ʱ��Ρ�����󳤶ȡ�
    ʾ�� 1��
    ���룺hours = [9,9,6,0,6,6,9]
    �����3
    ���ͣ���ı�������ʱ����� [9,9,6]��
    ʾ�� 2��
    ���룺hours = [6,6,6]
    �����0*/
    int LC1124_longestWPI_(std::vector<int>hours);
public:
    /*LeetCode 1124 �������õ��ʱ���*/
    void Test_LC1124_longestWPI();
private:
    /*����һ������������ nums�������Ƴ� ��� �����飨����Ϊ �գ���
    ʹ��ʣ��Ԫ�ص� �� �ܱ� p ������ ������ ���������鶼�Ƴ���
    ���㷵������Ҫ�Ƴ������������ĳ��ȣ�����޷�������ĿҪ�󣬷��� -1 ��
    ������ ����Ϊԭ������������һ��Ԫ�ء�
    ʾ�� 1��
    ���룺nums = [3,1,4,2], p = 6
    �����1
    ���ͣ�nums ��Ԫ�غ�Ϊ 10�����ܱ� p ���������ǿ����Ƴ������� [4] ��ʣ��Ԫ�صĺ�Ϊ 6 ��
    ʾ�� 2��
    ���룺nums = [6,3,5,2], p = 9
    �����2
    ���ͣ������޷��Ƴ��κ�һ��Ԫ��ʹ�úͱ� 9 ���������ŷ������Ƴ������� [5,2] ��ʣ��Ԫ��Ϊ [6,3]����Ϊ 9 ��
    ʾ�� 3��
    ���룺nums = [1,2,3], p = 3
    �����0
    ���ͣ���ǡ��Ϊ 6 ���Ѿ��ܱ� 3 �����ˡ��������ǲ���Ҫ�Ƴ��κ�Ԫ�ء�
    ʾ��  4��
    ���룺nums = [1,2,3], p = 7
    �����-1
    ���ͣ�û���κη���ʹ���Ƴ��������ʣ��Ԫ�صĺͱ� 7 ������
    ʾ�� 5��
    ���룺nums = [1000000000,1000000000,1000000000], p = 3
    �����0*/
    int LC1590_minSubarray_(std::vector<int>&nums,int p);
public:
    /*LeetCode 1590 ���Ա�p��������СҪɾ����������ĳ���*/
    void Test_LC1590_minSubarray();
private:
    /*����һ���ַ��� s ��
    ���㷵��������������������ַ����ĳ��ȣ�ÿ��Ԫ����ĸ��
    �� 'a'��'e'��'i'��'o'��'u' �������ַ����ж�ǡ�ó�����ż���Ρ�
    ʾ�� 1��
    ���룺s = "eleetminicoworoep"
    �����13
    ���ͣ�����ַ����� "leetminicowor" ��
    ������ e��i��o �� 2 �����Լ� 0 �� a��u ��
    ʾ�� 2��
    ���룺s = "leetcodeisgreat"
    �����5
    ���ͣ�����ַ����� "leetc" �����а��� 2 �� e ��
    ʾ�� 3��
    ���룺s = "bcbcbc"
    �����6
    ���ͣ����ʾ���У��ַ��� "bcbcbc" ���������ģ�
    ��Ϊ���е�Ԫ�� a��e��i��o��u �������� 0 �Ρ�
    ��ʾ��
    1 <= s.length <= 5 x 10^5
    s ֻ����СдӢ����ĸ��*/
    int LC1371_findTheLongestSubstring_(std::string s);
    /*Ԫ������ȡ*/
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
    /*��ͷ��Կ
    ţţ������������Լ����һ�׽�ͷ��Կϵͳ����ʶ��˴����
    ��Կ��һ���������б�ʾ��������Կ���϶�Ϊ��һ�µģ����������������
    ��Կb�ĳ��Ȳ��ᳬ����Կa
    ���������0<=i<length(b),��b[i+1]-b[i]==a[i+1]-a[i]
    ���ڸ�����m����Կb�����飬�Լ�n����Կa������
    ���㷵��һ������Ϊm�Ľ������ans��ʾÿ����Կb���ж���һ�µ���Կ
    ����a������b�е�Ԫ�ظ�����������10^5
    1<=m,n<=1000*/
    /*ǰ׺������ʱ�䣺O( a��������ָ���*10)+O(b��������ָ���*10)
    �ռ䣺O(a��������ָ���*10 )*/
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

    /*����һ���������� nums ������ nums[i] XOR nums[j] �������������
    ���� 0 �� i �� j < n ��
    ʾ�� 1��
    ���룺nums = [3,10,5,25,2,8]
    �����28
    ���ͣ������������ 5 XOR 25 = 28.
    ʾ�� 2��
    ���룺nums = [14,70,53,83,49,91,36,80,92,51,66,70]
    �����127*/
    int LC421_findMaximumXOR(std::vector<int>&nums);
    //��ϣ���ʵ��
    int LC421_findMaximumXOR_Hash(std::vector<int>nums);
    void Test_LC421_findMaximumXOR();
}
    /*����һ�� m x n ��ά�ַ����� board ��һ�����ʣ��ַ������б� words��
    �������ж�ά�����ϵĵ��� ��
    ���ʱ��밴����ĸ˳��ͨ�� ���ڵĵ�Ԫ�� �ڵ���ĸ���ɣ�
    ���С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��
    ͬһ����Ԫ���ڵ���ĸ��һ�������в������ظ�ʹ�á�*/
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
