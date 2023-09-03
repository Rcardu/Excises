#include"../unltle.h"
class SetWindowRgn
{
private:
    /*给定一个含有 n 个正整数的数组和一个正整数 target 。
    找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
    并返回其长度。如果不存在符合条件的子数组，返回 0 。
    输入：target = 7, nums = [2,3,1,2,4,3]
    输出：2
    解释：子数组 [4,3] 是该条件下的长度最小的子数组。*/
    int LCR008_minSubArrayLen_(int target,std::vector<int>&nums);
public:
    /*连续最小子数组*/
    void Test_LCR008_minSubArrayLen();
private:
    /*给定一个字符串 s ，请你找出其中不含有重复字符的 最长连续子字符串 的长度。
    输入: s = "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子字符串是 "abc"，所以其长度为 3。*/
    int LCR016_lengthOfLongestSubstring_(std::string s);
public:
    /*无重复的最长子串*/
    void Test_LCR016_lengthOfLongestSubstring();
private:
    /*给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。
    如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。
    如果 s 中存在多个符合条件的子字符串，返回任意一个。
    注意： 对于 t 中重复字符，
    我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
    输入：s = "ADOBECODEBANC", t = "ABC"
    输出："BANC" 
    解释：最短子字符串 "BANC" 包含了字符串 t 的所有字符 'A'、'B'、'C'*/
    std::string LCR017_minWindow_(std::string s,std::string t);
public:
    /*最小覆盖子串*/
    void Test_LCR017_minWindow();
private:
    /*在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
    你有一辆油箱容量无限的的汽车，
    从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
    你从其中的一个加油站出发，开始时油箱为空。
    给定两个整数数组 gas 和 cost ，
    如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，
    否则返回 -1 。如果存在解，则保证它是唯一的。
    输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
    输出: 3
    解释:
    从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
    开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
    开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
    开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
    开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
    开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
    因此，3 可为起始索引。*/
    int LC134_canCompleteCircuit_(std::vector<int>& gas, std::vector<int>& cost);
public:
    /*LeetCode 134 加油站*/
    void Test_LC134_canCompleteCircuit();
};
