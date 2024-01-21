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
private:
    /*有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。
    假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。
    给你一个这样的字符串 s，请通过「替换一个子串」的方式，
    使原字符串 s 变成一个「平衡字符串」。
    你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。
    请返回待替换子串的最小可能长度。
    如果原字符串自身就是一个平衡字符串，则返回 0。
    示例 1：
    输入：s = "QWER"
    输出：0
    解释：s 已经是平衡的了。
    示例 2：
    输入：s = "QQWE"
    输出：1
    解释：我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
    示例 3：
    输入：s = "QQQW"
    输出：2
    解释：我们可以把前面的 "QQ" 替换成 "ER"。 
    示例 4：
    输入：s = "QQQQ"
    输出：3
    解释：我们可以替换后 3 个 'Q'，使 s = "QWER"。*/
    int LC1234_balancedString_(std::string s);
    /*cnts:除窗口之外的词频统计
    len:自由变换的窗口的长度
    require:每一种字符需要达到的数量
    返回值：能不能做到*/
    bool LC1234_Ok_(std::vector<int>cnts,int len,int require);
    /*附加转换函数，将随机生成的ABCD转化成QWER*/
    void LC1234_Sub_(std::string&s);
public:
    /*LeetCode 1234 平衡子串*/
    void Test_LC1234_LC1234_balancedString();
private:
    /*给定一个正整数数组 nums和一个整数 k，返回 nums 中 「好子数组」 的数目。
    如果 nums 的某个子数组中不同整数的个数恰好为 k，
    则称 nums 的这个连续、不一定不同的子数组为 「好子数组 」。
    例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。
    子数组 是数组的 连续 部分。
    示例 1：
    输入：nums = [1,2,1,2,3], k = 2
    输出：7
    解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
    示例 2：
    输入：nums = [1,2,1,3,4], k = 3
    输出：3
    解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].*/
    int LC992_subarraysWithKDistinct_(std::vector<int>&nums,int k);
    /* 寻找小于等于k的种类的个数*/
    int LC992_findkinds_(std::vector<int>&nums,int k);
public:
    /*LeetCode 992 k个不同的子数组*/
    void Test_LC992_subarraysWithKDistinct();
private:
    /*给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串，
    要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
    如果不存在这样的子字符串，则返回 0。
    示例 1：
    输入：s = "aaabb", k = 3
    输出：3
    解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
    示例 2：
    输入：s = "ababbc", k = 2
    输出：5
    解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。*/
    int LC395_longestSubstring_(std::string s,int k);
public:
    /*LeetCode 395 至少有 K 个重复字符的最长子串*/
    void Test_LC395_longestSubstring();
};
