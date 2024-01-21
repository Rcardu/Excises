#include"../unltle.h"

class Recursion{
private:
    //字符串的全部子序列
    std::vector<std::string> generatePermutation_(std::string str);
    void generatePermutation_f1_(std::string s,int i,std::string&path,std::unordered_set<std::string>&set);
    void generatePermutation_f1_(std::string s,int i,char path[],int size,std::unordered_set<std::string>&set);
public:
    //字符串的全部子序列
    void Test_generatePermutation();
private:
    /*给你一个整数数组 nums ，
    其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
    解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
    示例 1：
    输入：nums = [1,2,2]
    输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
    示例 2：
    输入：nums = [0]
    输出：[[],[0]]*/
    std::vector<std::vector<int>> subsetsWithDup_(std::vector<int>& nums);
    void subsetsWithDup_f1_(std::vector<int>&nums,int i,std::vector<int>&path,int size,std::vector<std::vector<int>>&ans);
public:
    //LeetCode 90 子集II
    void Test_LC90_subsetsWithDup();
private:
    /*给定一个不含重复数字的数组 nums ，
    返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
    示例 1：
    输入：nums = [1,2,3]
    输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    示例 2：
    输入：nums = [0,1]
    输出：[[0,1],[1,0]]
    示例 3：
    输入：nums = [1]
    输出：[[1]]*/
    std::vector<std::vector<int>>LC46_permute_(std::vector<int>& nums);
    void LC46_premute_f_(std::vector<int>&nums,int index,std::vector<std::vector<int>>&ans);
    void Swap(std::vector<int>&nums,int i1,int i2);
public:
    /*LeetCode 46 全排列*/
    void Test_LC46_permute();
private:
    /*逆序栈方法*/
    void Reverse_Stack_(std::stack<int>&stk);
    int BottomOut_Stack_(std::stack<int>&stk);
public:
    /*逆序栈*/
    void Test_Reverse_Stack_();
private:
    /*排序栈中的元素*/
    void Sort_Stack_(std::stack<int>&stk);
    //获得栈的深度
    int Deep_Stack_(std::stack<int>stk);
    //获得栈中的最大元素
    int Max_Stack_(std::stack<int>stk,int deep);
    //获得最大元素的个数
    int Times_Max_Stack_(std::stack<int>stk,int deep,int Max_num);
    //最大元素沉底
    void Down_Max_Stack_(std::stack<int>&stk,int deep,int Max_num,int times);
public:
    void Test_Sort_Stack();
private:
    //汉诺塔问题
    void HanNi_f_(int i,std::string from,std::string to,std::string other);
    void HanNi_f_(int n,std::vector<int>&A,std::vector<int>&B,std::vector<int>&C);
    //汉诺塔
    void HanNo_(int n);
public:
    //汉诺
    void Test_HanNi();
private:
    /*实现一个基本的计算器来计算简单的表达式字符串
    表达式字符串只包含非负整数，算符+、-、*、/、左右括号()。
    整数除法需要向下截断
    假定给定的所有表达式都是有效的，所有中间结果都满足
    [INT_MIN,INT_MAX]
    例一：
    输入s="1+1"
    输出：2
    例二：
    输入s="6-4/2"
    输出：4
    例三：
    输入s="2*(5+5*2)/3+(6/2+8)"
    输出：21
    */
   int LC772_where;
   int LC772_Plus_Calculate_(std::string str);
   int LC772_Plus_Calculate_f_(std::string s,int i);
   void LC772_Plus_Push_(std::stack<int>&nums,std::stack<char>&ops,int cur,char op);
   int LC772_Plus_Compute_(std::stack<int>&nums,std::stack<char>&ops);
public:
    /*LeetCode 772 计算器的基础实现*/
    void Test_LC772_Plus_Calculate();
private:
    /*给定一个经过编码的字符串，返回它解码后的字符串。
    编码规则为: k[encoded_string]，
    表示其中方括号内部的 encoded_string 正好重复 k 次。
    注意 k 保证为正整数。
    你可以认为输入字符串总是有效的；
    输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
    此外，你可以认为原始数据不包含数字，
    所有的数字只表示重复的次数 k ，
    例如不会出现像 3a 或 2[4] 的输入。
    示例 1：
    输入：s = "3[a]2[bc]"
    输出："aaabcbc"
    示例 2：
    输入：s = "3[a2[c]]"
    输出："accaccacc"
    示例 3：
    输入：s = "2[abc]3[cd]ef"
    输出："abcabccdcdcdef"
    示例 4：
    输入：s = "abc3[cd]xyz"
    输出："abccdcdcdxyz"*/
    int LC394_where;
    std::string LC394_decodeString_(std::string s);
    std::string LC394_decodeString_f_(std::string s,int i);
    std::string LC394_Push_(int cur,std::string ch);
public:
    /*LeetCode 394 字符串解码*/
    void Test_LC394_decodeString_();
private:
    /*给你一个字符串化学式 formula ，返回 每种原子的数量 。
    原子总是以一个大写字母开始，接着跟随 0 个或任意个小写字母，表示原子的名字。
    如果数量大于 1，原子后会跟着数字表示原子的数量。
    如果数量等于 1 则不会跟数字。
    例如，"H2O" 和 "H2O2" 是可行的，但 "H1O2" 这个表达是不可行的。
    两个化学式连在一起可以构成新的化学式。
    例如 "H2O2He3Mg4" 也是化学式。
    由括号括起的化学式并佐以数字（可选择性添加）也是化学式。
    例如 "(H2O2)" 和 "(H2O2)3" 是化学式。
    返回所有原子的数量，格式为：第一个（按字典序）原子的名字，
    跟着它的数量（如果数量大于 1），然后是第二个原子的名字（按字典序），
    跟着它的数量（如果数量大于 1），以此类推。
    示例 1：
    输入：formula = "H2O"
    输出："H2O"
    解释：原子的数量是 {'H': 2, 'O': 1}。
    示例 2：
    输入：formula = "Mg(OH)2"
    输出："H2MgO2"
    解释：原子的数量是 {'H': 2, 'Mg': 1, 'O': 2}。
    示例 3：
    输入：formula = "K4(ON(SO3)2)2"
    输出："K4N2O14S4"
    解释：原子的数量是 {'K': 4, 'N': 2, 'O': 14, 'S': 4}。*/
    int LC726_where;
    std::string LC726_countOfAtoms_(std::string formula);
    std::unordered_map<std::string,int>LC726_countOfAtoms_f_(std::string str,int i);
    void LC726_countOfAtoms_fill_(std::unordered_map<std::string,int>&ans,std::string name,std::unordered_map<std::string,int>&pre,int cur);
public:
    /*LeetCode 726 原子的数量*/
    void Test_LC726_countOfAtoms_();
private:
    /*N皇后问题*/
    int LC52_totalNQueens_(int n);
    /*N皇后问题位运算*/
    int LC52_totalNQueens2_(int n);

    //递归检查所有解决方案
    int LC52_totalNQueens_f_(int i,std::vector<int>&path,int n);
    //位运算的解决方案
    /*limit:表示当前是几皇后问题
    col：之前的皇后的列的影响
    left：之前的皇后从右上->左下的对角线的影响
    right：之前的皇后从左上到右下对角线的影响*/
    int LC52_totalNQueens_f_(int limit,int col,int left,int right);
    //检查当前位置是否可以放入
    bool LC52_check_(std::vector<int>&path,int i,int j);
public:
    //LeetCode 52 N皇后
    void Test_LC52_totalNQueens_();
private:
    /*最大公约数*/
    long GreatestCommonDivisor_(long a,long b){
        return b==0?a:GreatestCommonDivisor_(b,a%b);
    }
    /*最小公倍数*/
    long Lcm(long a,long b){
        return (long)a/GreatestCommonDivisor_(a,b)*b;
    }
public:
    void Test_GreatestCommonDivisor();
private:    
    /*一个正整数如果能被 a 或 b 整除，那么它是神奇的。
    给定三个整数 n , a , b ，返回第 n 个神奇的数字。
    因为答案可能很大，所以返回答案 对 10^9 + 7 取模 后的值。
    示例 1：
    输入：n = 1, a = 2, b = 3
    输出：2
    示例 2：
    输入：n = 4, a = 2, b = 3
    输出：6*/
    int LC878_nthMagicalNumber_(int n,int a,int b);
public:
    /*LeetCode 878 第N个神奇的数字*/
    void Test_LC878_nthMagicalNumber();
private:
    /*有6规格的袋子个8规格的袋子，装n个苹果可以组成的结果最少是多少个袋子
    如果装不满袋子则返回-1*/
    int AppleMinBags_(int apple);
    /*暴力递归*/
    int AppleMinBags_f_(int apple);
    /*规律查询*/
    int AppleMinBags_f2_(int apple);
public:
    void Test_AppleMinBags();
private:
    /*草一共有n的重量，两只牛轮流吃草，A牛先吃，B牛后吃
    每只牛在自己的回合，吃草的重量必须是4的幂，1、4、16、64
    谁在自己的回合正好把草吃完谁赢、根据输入的n，返回谁赢*/
    std::string EatGrass_win1_(int n);
    /*rest:还剩多少草
    cur:当前选手的名字
    还剩rest份草，当前选手是cur，返回最终谁赢*/
    std::string EatGrass_win1_f1_(int rest,std::string cur);
    /*规律版*/
    std::string EatGrass_win1_f2_(int rest,std::string cur);
public:
    /*A与B轮流吃草谁会赢*/
    void Test_EatGrass_win1();
private:
    /*判断一个数是否是若干数的连续正整数和*/
    bool IsSumOfConsecutiveNumbers_is1_(int num);
    /*规律版 */
    bool IsSumOfConsecutiveNumbers_is2_(int num);
public:
    void Test_IsSumOfConsecutiveNumbers();
private:
    /*整个字符串中有且仅有一个长度大于等于2的回文子串
    被称作好串*/
    /*只使用r、e、d这三个字符拼出长度为n的字符串中有多少个好串*/
    int RedPalindromeGoodStrings_num1(int n);
    /*规律版*/
    int RedPalindromeGoodStrings_num2(int n);
    //递归生成字符串
    int RedPalindromeGoodStrings_num1_f(std::string path,int i,int n);
    //判断是否为回文
    bool RedPalindromeGoodStrings_num1_is_(std::string path,int left,int right);
public:
    /*字符串中有多少个好串*/
    void Test_RedPalindromeGoodStrings_num1();
};