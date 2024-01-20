#include "../unltle.h"
#include <vector>

namespace DP_One_dimensional {
using std::cout;
using std::endl;
using std::function;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class FibonacciNumber {
private:
  /*斐波那契数列*/
  int FibonacciNumber_fib1(int n);
  int FibonacciNumber_f1(int i);

public:
  // 斐波那契数列
  void Test_FibonacciNumber_fib1();

private:
  /*斐波那契数列*/
  int FibonacciNumber_fib2(int n);
  int FibonacciNumber_f2(vector<int> &findList, int i);

public:
  // 斐波那契数列
  void Test_FibonacciNumber_fib2();

private:
  /*斐波那契数列*/
  int FibonacciNumber_fib3(int n);

public:
  // 斐波那契数列
  void Test_FibonacciNumber_fib3();

private:
  /*斐波那契数列*/
  int FibonacciNumber_fib4(int n);

public:
  // 斐波那契数列
  void Test_FibonacciNumber_fib4();
};
class mincostTickets {
private:
  /*在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，
  你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。
  火车票有 三种不同的销售方式 ：
  一张 为期一天 的通行证售价为 costs[0] 美元；
  一张 为期七天 的通行证售价为 costs[1] 美元；
  一张 为期三十天 的通行证售价为 costs[2] 美元。
  通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张 为期 7 天
  的通行证， 那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6
  天、第 7 天和第 8 天。 返回 你想要完成在给定的列表 days
  中列出的每一天的旅行所需要的最低消费 。 示例 1： 输入：days = [1,4,6,7,8,20],
  costs = [2,7,15] 输出：11 解释：
  例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
  在第 1 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 1 天生效。
  在第 3 天，你花了 costs[1] = $7 买了一张为期 7 天的通行证，它将在第 3, 4, ...,
  9 天生效。 在第 20 天，你花了 costs[0] = $2 买了一张为期 1
  天的通行证，它将在第 20 天生效。 你总共花了 $11，并完成了你计划的每一天旅行。
  示例 2：
  输入：days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
  输出：17
  解释：
  例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
  在第 1 天，你花了 costs[2] = $15 买了一张为期 30 天的通行证，它将在第 1, 2,
  ..., 30 天生效。 在第 31 天，你花了 costs[0] = $2 买了一张为期 1
  天的通行证，它将在第 31 天生效。 你总共花了 $17，并完成了你计划的每一天旅行。
  提示：
  1 <= days.length <= 365
  1 <= days[i] <= 365
  days 按顺序严格递增
  costs.length == 3
  1 <= costs[i] <= 1000*/
  vector<int> durations = {1, 7, 30};

private:
  /*暴力递归*/
  int LC983_mincostTickets1(vector<int> &days, vector<int> &costs);
  // 枚举从第days[i]天开始到最后一天的最小花费是多少
  int LC983_mincostTickets_f1(vector<int> &days, vector<int> &costs, int i);

public:
  void Test_LC983_mincostTickets1();

private:
  /*自顶到底记忆化搜索*/
  int LC983_mincostTickets2(vector<int> &days, vector<int> &costs);
  // 枚举从第days[i]天开始到最后一天的最小花费是多少
  int LC983_mincostTickets_f2(vector<int> &days, vector<int> &costs, int i,
                              vector<int> &dp);

public:
  void Test_LC983_mincostTickets2();

private:
  /*自底到顶依赖化递增*/
  int LC983_mincostTickets3(vector<int> &days, vector<int> &costs);

public:
  void Test_LC983_mincostTickets3();
};
class numDecodings {
private:
  /*一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
  'A' -> "1"
  'B' -> "2"
  ...
  'Z' -> "26"
  要 解码
  已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106"
  可以映射为： "AAJF" ，将消息分组为 (1 1 10 6) "KJF" ，将消息分组为 (11 10 6)
  注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和
  "06" 在映射中并不等价。 给你一个只含数字的 非空 字符串 s ，请计算并返回 解码
  方法的 总数 。 题目数据保证答案肯定是一个 32 位 的整数。 示例 1： 输入：s =
  "12" 输出：2 解释：它可以解码为 "AB"（1 2）或者 "L"（12）。 示例 2： 输入：s =
  "226" 输出：3 解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6)
  。 示例 3： 输入：s = "06" 输出：0 解释："06" 无法映射到 "F"
  ，因为存在前导零（"6" 和 "06" 并不等价）。 提示： 1 <= s.length <= 100 s
  只包含数字，并且可能包含前导零*/
private:
  // 暴力递归
  int LC91_numDecodings1(string s);
  // 暴力递归
  int LC91_numDecodings_f1(string s, int i);

public:
  /*LeetCode 91 解码方法*/
  void Test_LC91_numDecodings1();

private:
  // 自顶到底记忆化搜索
  int LC91_numDecodings2(string s);
  // 自顶到底记忆化搜索
  int LC91_numDecodings_f2(string s, int i, vector<int> &dp);

public:
  /*LeetCode 91 解码方法*/
  void Test_LC91_numDecodings2();

private:
  // 自底到顶严格递增
  int LC91_numDecodings3(string s);
  // 空间优化
  int LC91_numDecodings4(string s);

public:
  /*LeetCode 91 解码方法*/
  void Test_LC91_numDecodings3();
};
class numDecodingsII {
private:
  /*一条包含字母 A-Z 的消息通过以下的方式进行了 编码 ：
  'A' -> "1"
  'B' -> "2"
  ...
  'Z' -> "26"
  要 解码
  一条已编码的消息，所有的数字都必须分组，然后按原来的编码方案反向映射回字母（可能存在多种方式）。例如，"11106"
  可以映射为： "AAJF" 对应分组 (1 1 10 6) "KJF" 对应分组 (11 10 6) 注意，像 (1
  11 06) 这样的分组是无效的，因为 "06" 不可以映射为 'F' ，因为 "6" 与 "06"
  不同。 除了 上面描述的数字字母映射方案，编码消息中可能包含 '*'
  字符，可以表示从 '1' 到 '9' 的任一数字（不包括 '0'）。 例如，编码字符串 "1*"
  可以表示 "11"、"12"、"13"、"14"、"15"、"16"、"17"、"18" 或 "19"
  中的任意一条消息。对 "1*" 进行解码，
  相当于解码该字符串可以表示的任何编码消息。
  给你一个字符串 s ，由数字和 '*' 字符组成，返回 解码 该字符串的方法 数目 。
  由于答案数目可能非常大，返回 109 + 7 的 模 。
  示例 1：
  输入：s = "*"
  输出：9
  解释：这一条编码消息可以表示 "1"、"2"、"3"、"4"、"5"、"6"、"7"、"8" 或 "9"
  中的任意一条。 可以分别解码成字符串 "A"、"B"、"C"、"D"、"E"、"F"、"G"、"H" 和
  "I" 。 因此，"*" 总共有 9 种解码方法。 示例 2： 输入：s = "1*" 输出：18
  解释：这一条编码消息可以表示 "11"、"12"、"13"、"14"、"15"、"16"、"17"、"18" 或
  "19" 中的任意一条。 每种消息都可以由 2 种方法解码（例如，"11" 可以解码成 "AA"
  或 "K"）。 因此，"1*" 共有 9 * 2 = 18 种解码方法。 示例 3： 输入：s = "2*"
  输出：15
  解释：这一条编码消息可以表示 "21"、"22"、"23"、"24"、"25"、"26"、"27"、"28" 或
  "29" 中的任意一条。 "21"、"22"、"23"、"24"、"25" 和 "26" 由 2 种解码方法，但
  "27"、"28" 和 "29" 仅有 1 种解码方法。 因此，"2*" 共有 (6 * 2) + (3 * 1) = 12
  + 3 = 15 种解码方法。 提示： 1 <= s.length <= 105 s[i] 是 0 - 9
  中的一位数字或字符 '*'*/
  constexpr static int MOD = 1000000007;

private:
  /*暴力递归*/
  int LC639_numDecodingsII1(string s);
  int LC639_numDecodingsII_f1(string s, int i);

public:
  void Test_LC639_numDecodingsII1();

private:
  /*记忆化搜索*/
  int LC639_numDecodingsII2(string s);
  long LC639_numDecodingsII_f2(string s, int i, vector<long> &dp);

public:
  void Test_LC639_numDecodingsII2();

private:
  /*自底向上*/
  int LC639_numDecodingsII3(string s);
  /*空间优化*/
  int LC639_numDecodingsII4(string s);

public:
  void Test_LC639_numDecodingsII3();
};
class nthUglyNumber {
private:
  /*给你一个整数 n ，请你找出并返回第 n 个 丑数 。
  丑数 就是只包含质因数 2、3 和/或 5 的正整数。
  示例 1：
  输入：n = 10
  输出：12
  解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
  示例 2：
  输入：n = 1
  输出：1
  解释：1 通常被视为丑数。
  提示：
  1 <= n <= 1690*/
  int LC264_nthUglyNumber(int n);

public:
  void Test_LC264_nthUglyNumber();
};
class longestValidParentheses {
private:
  /*给你一个只包含 '(' 和 ')'
  的字符串，找出最长有效（格式正确且连续）括号子串的长度。 示例 1： 输入：s =
  "(()" 输出：2 解释：最长有效括号子串是 "()" 示例 2： 输入：s = ")()())"
  输出：4
  解释：最长有效括号子串是 "()()"
  示例 3：
  输入：s = ""
  输出：0
  提示：
  0 <= s.length <= 3 * 104
  s[i] 为 '(' 或 ')'*/
  int LC32_longestValidParentheses(string s);

public:
  void Test_LC32_longestValidParentheses();
};
class findSubstringInWraproundString {
private:
  /*定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串，所以
  base 看起来是这样的：
  "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
  给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现。
  示例 1：
  输入：s = "a"
  输出：1
  解释：字符串 s 的子字符串 "a" 在 base 中出现。
  示例 2：
  输入：s = "cac"
  输出：2
  解释：字符串 s 有两个子字符串 ("a", "c") 在 base 中出现。
  示例 3：
  输入：s = "zab"
  输出：6
  解释：字符串 s 有六个子字符串 ("z", "a", "b", "za", "ab", and "zab") 在 base
  中出现。 提示： 1 <= s.length <= 105 s 由小写英文字母组成*/
  int LC467_findSubstringInWraproundString(string s);

public:
  void Test_LC467_findSubstringInWraproundString();
};
class distinctSubseqII {
private:
  constexpr static int MOD = 1000000007;
  /*给定一个字符串 s，计算 s 的 不同非空子序列
  的个数。因为结果可能很大，所以返回答案需要对 10^9 + 7 取余 。 字符串的 子序列
  是经由原字符串删除一些（也可能不删除）字符但不改变剩余字符相对位置的一个新字符串。
  例如，"ace" 是 "abcde" 的一个子序列，但 "aec" 不是。
  示例 1：
  输入：s = "abc"
  输出：7
  解释：7 个不同的子序列分别是 "a", "b", "c", "ab", "ac", "bc", 以及 "abc"。
  示例 2：
  输入：s = "aba"
  输出：6
  解释：6 个不同的子序列分别是 "a", "b", "ab", "ba", "aa" 以及 "aba"。
  示例 3：
  输入：s = "aaa"
  输出：3
  解释：3 个不同的子序列分别是 "a", "aa" 以及 "aaa"。
  提示：
  1 <= s.length <= 2000
  s 仅由小写英文字母组成
  */

  int LC940_distinctSubseqII(string s);

public:
  void Test_LC940_distinctSubseqII();
};
} // namespace DP_One_dimensional
namespace DP_Two_dimensional {
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
class minPathSum {
private:
  /*给定一个包含非负整数的 m x n 网格 grid
  ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
  说明：每次只能向下或者向右移动一步。
  示例 1：
  输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
  输出：7
  解释：因为路径 1→3→1→1→1 的总和最小。
  示例 2：
  输入：grid = [[1,2,3],[4,5,6]]
  输出：12
  提示：
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 200
  0 <= grid[i][j] <= 200*/
private:
  int LC64_minPathSum(vector<vector<int>> &grid);
  // 暴力递归
  int LC64_minPathSum_f1(vector<vector<int>> &grid, int i, int j);
  // 记忆化搜索
  int LC64_minPathSum2(vector<vector<int>> &grid);
  int LC64_minPathSum_f2(vector<vector<int>> &grid, int i, int j,
                         vector<vector<int>> &dp);
  // 严格依赖
  int LC64_minPathSum3(vector<vector<int>> &grid);
  // 空间优化
  int LC64_minPathSum4(vector<vector<int>> &grid);

public:
  void Test_LC64_minPathSum();
  void Test_LC64_minPathSum2();
  void Test_LC64_minPathSum3();
};
class exist {
private:
  /*给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word
  存在于网格中，返回 true ；否则，返回 false 。
  单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
  示例 1：
  输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
  "ABCCED" 输出：true 示例 2： 输入：board =
  [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
  输出：true
  示例 3：
  输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
  "ABCB" 输出：false 提示： m == board.length n = board[i].length 1 <= m, n <= 6
  1 <= word.length <= 15
  board 和 word 仅由大小写英文字母组成*/
private:
  bool LC79_exist(vector<vector<char>> &board, string word);
  bool LC79_exist_f(vector<vector<char>> &board, int i, int j, string word,
                    int k);

public:
  void Test_LC79_exist();
};
class longestCommonSubsequence {
private:
  /*给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列
  的长度。如果不存在 公共子序列 ，返回 0 。 一个字符串的 子序列
  是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
  例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
  两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
  示例 1：
  输入：text1 = "abcde", text2 = "ace"
  输出：3
  解释：最长公共子序列是 "ace" ，它的长度为 3 。
  示例 2：
  输入：text1 = "abc", text2 = "abc"
  输出：3
  解释：最长公共子序列是 "abc" ，它的长度为 3 。
  示例 3
  输入：text1 = "abc", text2 = "def"
  输出：0
  解释：两个字符串没有公共子序列，返回 0 。
  提示：
  1 <= text1.length, text2.length <= 1000
  text1 和 text2 仅由小写英文字符组成。*/
private:
  // 深搜递归
  int LC1143_longestCommonSubsequence1(string text1, string text2);
  int LC1143_longestCommonSubsequence_f1(string text1, string text2, int i1,
                                         int i2);
  // 深搜递归,该边描述方法以适应动态规划
  int LC1143_longestCommonSubsequence2(string text1, string text2);
  int LC1143_longestCommonSubsequence_f2(string text1, string text2, int len1,
                                         int len2);
  // 记忆化搜索
  int LC1143_longestCommonSubsequence3(string text1, string text2);
  int LC1143_longestCommonSubsequence_f3(string text1, string text2, int len1,
                                         int len2, vector<vector<int>> &dp);
  // 严格位置依赖
  int LC1143_longestCommonSubsequence4(string text1, string text2);
  // 空间优化
  int LC1143_longestCommonSubsequence5(string text1, string text2);

public:
  void Test_LC1143_longestCommonSubsequence();
};
class longestPalindromeSubseq {
private:
  /*给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
  子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
  示例 1：
  输入：s = "bbbab"
  输出：4
  解释：一个可能的最长回文子序列为 "bbbb" 。
  示例 2：
  输入：s = "cbbd"
  输出：2
  解释：一个可能的最长回文子序列为 "bb" 。
  提示：
  1 <= s.length <= 1000
  s 仅由小写英文字母组成*/
private:
  // 利用他的逆序串与原串求最长公共子序列来求解
  int LC516_longestPalindromeSubseq_EX(string s);
  // 暴力递归
  int LC516_longestPalindromeSubseq1(string s);
  int LC516_longestPalindromeSubseq1_f1(string s, int l, int r);
  // 记忆化搜索
  int LC516_longestPalindromeSubseq2(string s);
  int LC516_longestPalindromeSubseq1_f2(string s, int l, int r,
                                        vector<vector<int>> &dp);
  // 严格位置依赖
  int LC516_longestPalindromeSubseq3(string s);
  // 空间压缩
  int LC516_longestPalindromeSubseq4(string s);

public:
  void Test_LC516_longestPalindromeSubseq();
};
class NodenHeightNotLargerThanm {
private:
  /*节点数为n高度不大于m的二叉树个数
  现在有n个节点，计算出有多少个不同结构的二叉树
  满足节点个数为n且树的高度不超过m的方案
  因为答案很大，所以答案需要模上10^9+7输出*/
  constexpr static int MOD = 1000000007;

private:
  // 记忆化搜索
  int Main_Compute1(int n, int m);
  int Compute1(int n, int m, vector<vector<int>> &dp);
  // 严格位置依赖
  int Main_Compute2(int n, int m);
  // 空间压缩
  int Main_Compute3(int n, int m);

public:
  void Test_Main_Compute();
};
class longestIncreasingPath {
private:
  /*给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
  对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线
  方向上移动或移动到 边界外（即不允许环绕）。 示例 1： 输入：matrix =
  [[9,9,4],[6,6,8],[2,1,1]] 输出：4 解释：最长递增路径为 [1, 2, 6, 9]。 示例 2：
  输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
  输出：4
  解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
  示例 3：
  输入：matrix = [[1]]
  输出：1*/
private:
  int LC329_longestIncreasingPath1(vector<vector<int>> &matrix);
  int LC329_longestIncreasingPath1_f1(vector<vector<int>> &grid, int i, int j);
  // 记忆化搜索
  int LC329_longestIncreasingPath2(vector<vector<int>> &matrix);
  int LC329_longestIncreasingPath1_f2(vector<vector<int>> &grid, int i, int j,
                                      vector<vector<int>> &dp);

public:
  void Test_LC329_longestIncreasingPath();
};
class numDistinct {
private:
  /*给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对
  109 + 7 取模。 示例 1： 输入：s = "rabbbit", t = "rabbit" 输出：3 解释：
  如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
  rabbbit
  rabbbit
  rabbbit
  示例 2：
  输入：s = "babgbag", t = "bag"
  输出：5
  解释：
  如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。
  babgbag
  babgbag
  babgbag
  babgbag
  babgbag
  提示：
  1 <= s.length, t.length <= 1000
  s 和 t 由英文字母组成*/
private:
  int LC115_numDistinct(string s, string t);
  // 空间压缩
  int LC115_numDistinct_EC(string s, string t);

public:
  void Test_LC115_numDistinct();
};
class minDistance {
private:
  /*给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数
  。 你可以对一个单词进行如下三种操作： 插入一个字符，代价a 删除一个字符，代价b
  替换一个字符，代价c
  示例 1：
  输入：word1 = "horse", word2 = "ros"
  输出：3
  解释：
  horse -> rorse (将 'h' 替换为 'r')
  rorse -> rose (删除 'r')
  rose -> ros (删除 'e')
  示例 2：
  输入：word1 = "intention", word2 = "execution"
  输出：5
  解释：
  intention -> inention (删除 't')
  inention -> enention (将 'i' 替换为 'e')
  enention -> exention (将 'n' 替换为 'x')
  exention -> exection (将 'n' 替换为 'c')
  exection -> execution (插入 'u')
  提示：
  0 <= word1.length, word2.length <= 500
  word1 和 word2 由小写英文字母组成*/
private:
  int LC72_minDistance1(string word1, string word2, int a, int b, int c);
  // 空间压缩
  int LC72_minDistance_EC(string word1, string word2, int a, int b, int c);

public:
  void Test_LC72_minDistance();
};
class isInterleave {
private:
  /*给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
  两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空
  子字符串： s = s1 + s2 + ... + sn t = t1 + t2 + ... + tm |n - m| <= 1 交错 是
  s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
  注意：a + b 意味着字符串 a 和 b 连接。
  示例 1：
  输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
  输出：true
  示例 2：
  输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
  输出：false
  示例 3：
  输入：s1 = "", s2 = "", s3 = ""
  输出：true
  提示：
  0 <= s1.length, s2.length <= 100
  0 <= s3.length <= 200
  s1、s2、和 s3 都由小写英文字母组成*/
private:
  bool LC97_isInterleave(string s1, string s2, string s3);
  // 空间压缩
  bool LC97_isInterleave_EC(string s1, string s2, string s3);

public:
  void Test_LC97_isInterleave();
};
class effectiveColoring {
private:
  /*有效涂色问题
  给定n、m两个参数
  一共有n个格子，每个格子可以涂上一种颜色，颜色在m种里选
  当涂满n个格子，并且m种颜色都是用了，叫一种有效方法
  求一共有多少种有效涂色的方法
  1<=n,m<=5000
  结果比较大请对10^9+7取余返回结果*/
  constexpr static int MOD = 1000000007;

private:
  int Ex_effectiveColoring(int n, int m);

public:
  void Test_Ex_effectiveColoring();
};
class stringChanges {
private:
  /*删除至少几个字符可以变成另一个字符串的子串
  给定两个字符串s1和s2
  返回s1至少删除多少个字符可以成为s2的子串*/
private:
  int EX_stringChanges(string s1, string s2);

public:
  void Test_EX_stringChanges();
};
class smallestMissingValueSubtree {
private:
  /*有一棵根节点为 0 的 家族树 ，总共包含 n 个节点，节点编号为 0 到 n - 1
  。给你一个下标从 0 开始的整数数组 parents ，其中 parents[i] 是节点 i
  的父节点。由于节点 0 是 根 ，所以 parents[0] == -1 。 总共有 105
  个基因值，每个基因值都用 闭区间 [1, 105] 中的一个整数表示。给你一个下标从 0
  开始的整数数组 nums ，其中 nums[i] 是节点 i 的基因值，且基因值 互不相同 。
  请你返回一个数组 ans ，长度为 n ，其中 ans[i] 是以节点 i 为根的子树内 缺失 的
  最小 基因值。 节点 x 为根的 子树 包含节点 x 和它所有的 后代 节点。 示例 1：
  输入：parents = [-1,0,0,2], nums = [1,2,3,4]
  输出：[5,1,1,1]
  解释：每个子树答案计算结果如下：
  - 0：子树包含节点 [0,1,2,3] ，基因值分别为 [1,2,3,4] 。5 是缺失的最小基因值。
  - 1：子树只包含节点 1 ，基因值为 2 。1 是缺失的最小基因值。
  - 2：子树包含节点 [2,3] ，基因值分别为 [3,4] 。1 是缺失的最小基因值。
  - 3：子树只包含节点 3 ，基因值为 4 。1是缺失的最小基因值。
  示例 2：
  输入：parents = [-1,0,1,0,3,3], nums = [5,4,6,2,1,3]
  输出：[7,1,1,4,2,1]
  解释：每个子树答案计算结果如下：
  - 0：子树内包含节点 [0,1,2,3,4,5] ，基因值分别为 [5,4,6,2,1,3] 。7
  是缺失的最小基因值。
  - 1：子树内包含节点 [1,2] ，基因值分别为 [4,6] 。 1 是缺失的最小基因值。
  - 2：子树内只包含节点 2 ，基因值为 6 。1 是缺失的最小基因值。
  - 3：子树内包含节点 [3,4,5] ，基因值分别为 [2,1,3] 。4 是缺失的最小基因值。
  - 4：子树内只包含节点 4 ，基因值为 1 。2 是缺失的最小基因值。
  - 5：子树内只包含节点 5 ，基因值为 3 。1 是缺失的最小基因值。
  示例 3：
  输入：parents = [-1,2,3,0,2,4,1], nums = [2,3,4,5,6,7,8]
  输出：[1,1,1,1,1,1,1]
  解释：所有子树都缺失基因值 1 。
  提示：
  n == parents.length == nums.length
  2 <= n <= 105
  对于 i != 0 ，满足 0 <= parents[i] <= n - 1
  parents[0] == -1
  parents 表示一棵合法的树。
  1 <= nums[i] <= 105
  nums[i] 互不相同。*/
private:
  vector<int> LC2003_smallestMissingValueSubtree(vector<int> &parents,
                                                 vector<int> &nums);

public:
  /*LeetCode 2003 每颗子树内缺失的最小基因值*/
  void Test_LC2003_smallestMissingValueSubtree();
};
} // namespace DP_Two_dimensional
namespace DP_Three_dimensional {
using std::cout;
using std::endl;
using std::function;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
class findMaxForm {
private:
  /*给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
  请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
  如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
  示例 1：
  输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
  输出：4
  解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是
  4 。 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"}
  不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。 示例 2： 输入：strs = ["10",
  "0", "1"], m = 1, n = 1 输出：2 解释：最大的子集是 {"0", "1"} ，所以答案是 2
  。 提示： 1 <= strs.length <= 600 1 <= strs[i].length <= 100 strs[i] 仅由 '0'
  和 '1' 组成 1 <= m, n <= 100*/
  int zeros, ones;

private:
  int LC474_findMaxForm1(vector<string> &strs, int m, int n);
  // 统计一个字符串中零和一的个数
  void LC474_findMaxForm1_conts(string str);
  // 暴力递归寻找
  int LC474_findMaxForm1_f1(vector<string> &strs, int i, int z, int o);
  // 记忆化搜索
  int LC474_findMaxForm2(vector<string> &strs, int m, int n);
  int LC474_findMaxForm1_f2(vector<string> &strs, int i, int z, int o,
                            vector<vector<vector<int>>> &dp);
  // 严格位置依赖
  int LC474_findMaxForm3(vector<string> &strs, int m, int n);
  // 优化
  int LC474_findMaxForm4(vector<string> &strs, int m, int n);

public:
  void Test_LC474_findMaxForm();
};
class profitableSchemes {
private:
  /*集团里有 n 名员工，他们可以完成各种各样的工作创造利润。
  第 i 种工作会产生 profit[i] 的利润，它要求 group[i]
  名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。
  工作的任何至少产生 minProfit 利润的子集称为 盈利计划
  。并且工作的成员总数最多为 n 。 有多少种计划可以选择？因为答案很大，所以
  返回结果模 10^9 + 7 的值。 示例 1： 输入：n = 5, minProfit = 3, group = [2,2],
  profit = [2,3] 输出：2 解释：至少产生 3 的利润，该集团可以完成工作 0 和工作 1
  ，或仅完成工作 1 。 总的来说，有两种计划。 示例 2： 输入：n = 10, minProfit =
  5, group = [2,3,5], profit = [6,7,8] 输出：7 解释：至少产生 5
  的利润，只要完成其中一种工作就行，所以该集团可以完成任何工作。 有 7
  种可能的计划：(0)，(1)，(2)，(0,1)，(0,2)，(1,2)，以及 (0,1,2) 。 提示： 1 <=
  n <= 100 0 <= minProfit <= 100 1 <= group.length <= 100 1 <= group[i] <= 100
  profit.length == group.length
  0 <= profit[i] <= 100*/
  constexpr static int MOD = 1000000007;

private:
  int LC879_profitableSchemes1(int n, int minProfit, vector<int> &group,
                               vector<int> &profit);
  int LC879_profitableSchemes_f1(vector<int> &group, vector<int> &profit, int i,
                                 int r, int s);
  // 记忆化搜索
  int LC879_profitableSchemes2(int n, int minProfit, vector<int> &group,
                               vector<int> &profit);
  int LC879_profitableSchemes_f2(vector<int> &group, vector<int> &profit, int i,
                                 int r, int s, vector<vector<vector<int>>> &dp);
  // 严格位置依赖
  int LC879_profitableSchemes3(int n, int minProfit, vector<int> &group,
                               vector<int> &profit);

public:
  void Test_LC879_profitableSchemes();
};
class knightProbability {
private:
  /*在一个 n x n 的国际象棋棋盘上，一个骑士从单元格 (row, column)
  开始，并尝试进行 k 次移动。行和列是 从 0 开始 的，所以左上单元格是 (0,0)
  ，右下单元格是 (n - 1, n - 1) 。
  象棋骑士有8种可能的走法，如下图所示。每次移动在基本方向上是两个单元格，然后在正交方向上是一个单元格。
  每次骑士要移动时，它都会随机从8种可能的移动中选择一种(即使棋子会离开棋盘)，然后移动到那里。
  骑士继续移动，直到它走了 k 步或离开了棋盘。
  返回 骑士在棋盘停止移动后仍留在棋盘上的概率 。
  示例 1：
  输入: n = 3, k = 2, row = 0, column = 0
  输出: 0.0625
  解释: 有两步(到(1,2)，(2,1))可以让骑士留在棋盘上。
  在每一个位置上，也有两种移动可以让骑士留在棋盘上。
  骑士留在棋盘上的总概率是0.0625。
  示例 2：
  输入: n = 1, k = 0, row = 0, column = 0
  输出: 1.00000
  提示:
  1 <= n <= 25
  0 <= k <= 100
  0 <= row, column <= n - 1*/
private:
  double LC688_knightProbability1(int n, int k, int row, int column);
  double LC688_knightProbability1_f1(int n, int i, int j, int k,
                                     vector<vector<vector<double>>> &dp);

public:
  void Test_LC688_knightProbability();
};
class numberOfPaths {
private:
  /*给你一个下标从 0 开始的 m x n 整数矩阵 grid 和一个整数 k 。你从起点 (0, 0)
  出发，每一步只能往 下 或者往 右 ，你想要到达终点 (m - 1, n - 1) 。
  请你返回路径和能被 k 整除的路径数目，由于答案可能很大，返回答案对 109 + 7 取余
  的结果。 示例 1： 输入：grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3 输出：2
  解释：有两条路径满足路径上元素的和能被 k 整除。
  第一条路径为上图中用红色标注的路径，和为 5 + 2 + 4 + 5 + 2 = 18 ，能被 3
  整除。 第二条路径为上图中用蓝色标注的路径，和为 5 + 3 + 0 + 5 + 2 = 15 ，能被
  3 整除。 示例 2： 输入：grid = [[0,0]], k = 5 输出：1 解释：红色标注的路径和为
  0 + 0 = 0 ，能被 5 整除。 示例 3： 输入：grid =
  [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1 输出：10 解释：每个数字都能被 1
  整除，所以每一条路径的和都能被 k 整除。 提示： m == grid.length n ==
  grid[i].length 1 <= m, n <= 5 * 104 1 <= m * n <= 5 * 104 0 <= grid[i][j] <=
  100 1 <= k <= 50*/
  constexpr static int MOD = 1000000007;

private:
  int LC2435_numberOfPaths(vector<vector<int>> &grid, int k);
  // 当前位置的数能否被k整除
  int LC2435_numberOfPaths_f1(vector<vector<int>> &grid, int n, int m, int k,
                              int i, int j, int r);

  // 记忆化搜索
  int LC2435_numberOfPaths2(vector<vector<int>> &grid, int k);
  // 当前位置的数能否被k整除
  int LC2435_numberOfPaths_f2(vector<vector<int>> &grid, int n, int m, int k,
                              int i, int j, int r,
                              vector<vector<vector<int>>> &dp);
  // 严格位置依赖
  int LC2435_numberOfPaths3(vector<vector<int>> &grid, int k);

public:
  void Test_LC2435_numberOfPaths();
};
class isScramble {
private:
  /*使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
  如果字符串的长度为 1 ，算法停止
  如果字符串的长度 > 1 ，执行下述步骤：
  在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s
  ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。 随机
  决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s
  可能是 s = x + y 或者 s = y + x 。 在 x 和 y 这两个子字符串上继续从步骤 1
  开始递归执行此算法。 给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1
  的扰乱字符串。如果是，返回 true ；否则，返回 false 。 示例 1： 输入：s1 =
  "great", s2 = "rgeat" 输出：true 解释：s1 上可能发生的一种情形是： "great" -->
  "gr/eat" // 在一个随机下标处分割得到两个子字符串 "gr/eat" --> "gr/eat" //
  随机决定：「保持这两个子字符串的顺序不变」 "gr/eat" --> "g/r / e/at" //
  在子字符串上递归执行此算法。两个子字符串分别在随机下标处进行一轮分割 "g/r /
  e/at" --> "r/g / e/at" //
  随机决定：第一组「交换两个子字符串」，第二组「保持这两个子字符串的顺序不变」
  "r/g / e/at" --> "r/g / e/ a/t" // 继续递归执行此算法，将 "at" 分割得到 "a/t"
  "r/g / e/ a/t" --> "r/g / e/ a/t" //
  随机决定：「保持这两个子字符串的顺序不变」 算法终止，结果字符串和 s2
  相同，都是 "rgeat" 这是一种能够扰乱 s1 得到 s2 的情形，可以认为 s2 是 s1
  的扰乱字符串，返回 true 示例 2： 输入：s1 = "abcde", s2 = "caebd" 输出：false
  示例 3：
  输入：s1 = "a", s2 = "a"
  输出：true
  提示：
  s1.length == s2.length
  1 <= s1.length <= 30
  s1 和 s2 由小写英文字母组成*/
private:
  bool LC87_isScramble(string s1, string s2);
  bool LC87_isScramble_f1(string &s1, int l1, int r1, string &s2, int l2,
                          int r2);
  // 记忆化搜索
  bool LC87_isScramble2(string s1, string s2);
  bool LC87_isScramble_f2(string &s1, string &s2, int l1, int l2, int len,
                          vector<vector<vector<int>>> &dp);
  // 严格位置依赖
  bool LC87_isScramble3(string s1, string s2);

public:
  void Test_LC87_isScramble();
};

} // namespace DP_Three_dimensional
namespace TheNumberOfMaxSubArray {
using std::cout;
using std::endl;
using std::function;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
class maxsubArray {
private:
  /*给你一个整数数组 nums
  ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
  子数组 是数组中的一个连续部分。
  示例 1：
  输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
  输出：6
  解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
  示例 2：
  输入：nums = [1]
  输出：1
  示例 3：
  输入：nums = [5,4,-1,7,8]
  输出：23
  提示：
  1 <= nums.length <= 105
  -104 <= nums[i] <= 104*/
private:
  int LC53_maxsubArray1(vector<int> &nums);
  // 空间压缩
  int LC53_maxsubArray2(vector<int> &nums);
  // 扩展：找出最大累加和的区间
  vector<int> LC53_maxsubArray_EX(vector<int> &nums);

private:
  /*环形子数组最大累加和问题*/
  int LC918_maxsubArray3(vector<int> &nums);

public:
  void Test_LC53_maxsubArray();
};
class Rob {
private:
  /*你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
  给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下
  ，一夜之内能够偷窃到的最高金额。 示例 1： 输入：[1,2,3,1] 输出：4 解释：偷窃 1
  号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。 偷窃到的最高金额 = 1 + 3 =
  4 。 示例 2： 输入：[2,7,9,3,1] 输出：12 解释：偷窃 1 号房屋 (金额 = 2), 偷窃
  3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。 偷窃到的最高金额 = 2 + 9 +
  1 = 12 。 提示： 1 <= nums.length <= 100 0 <= nums[i] <= 400*/
private:
  int LC198_rob(vector<int> &nums);
  int LC198_rob2(vector<int> &nums);

private:
  /*环形子数组最大累加和问题*/
  int LC213_rob(vector<int> &nums);
  /*LeetCode 2560 打家劫舍IV*/
  int LC2560_rob(vector<int> &nums, int k);

public:
  void Test_LC198_rob();
};
class getMaxMatrix {
private:
  /*给定一个正整数、负整数和 0 组成的 N × M
  矩阵，编写代码找出元素总和最大的子矩阵。 返回一个数组 [r1, c1, r2, c2]，其中
  r1, c1 分别代表子矩阵左上角的行号和列号，r2, c2
  分别代表右下角的行号和列号。若有多个满足条件的子矩阵，返回任意一个均可。
  注意：本题相对书上原题稍作改动
  示例：
  输入：
  [
  [-1,0],
  [0,-1]
  ]
  输出：[0,1,0,1]
  解释：输入中标粗的元素即为输出所表示的矩阵
  说明：
  1 <= matrix.length, matrix[0].length <= 200*/
private:
  vector<int> MS1724_getMaxMatrix(vector<vector<int>> &matrix);

public:
  void Test_MS1724_getMaxMatrix();
};
class maxProduct {
private:
  /*给你一个整数数组 nums
  ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
  测试用例的答案是一个 32-位 整数。
  子数组 是数组的连续子序列。
  示例 1:
  输入: nums = [2,3,-2,4]
  输出: 6
  解释: 子数组 [2,3] 有最大乘积 6。
  示例 2:
  输入: nums = [-2,0,-1]
  输出: 0
  解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
  提示:
  1 <= nums.length <= 2 * 104
  -10 <= nums[i] <= 10
  nums 的任何前缀或后缀的乘积都 保证 是一个 32-位 整数*/
private:
  int LC152_maxProduct(vector<int> &nums);

public:
  void Test_LC152_maxProduct();
};
class MaxProSub {
private:
  /*子序列累加和必须被7整除的最大累加和
  给定一个非负数组nums
  可以任意选择数组组成子序列，但是子序列的累加和必须被7整除
  返回最大累加和*/
private:
  // 暴力方法
  int maxSum1(vector<int> &nums);
  // 将所有子序列%7==0的累加和枚举，找出最大的那个
  int maxSum1_f(vector<int> &nums, int i, int s);
  int maxSum2(vector<int> &nums);
};
class MagicReel {
private:
  /*给定一个nums数组，其中可能有正、负、0
  每个卷轴可以把nums中连续的一段全变成0
  每个希望数组整体的累加和尽可能大
  卷轴使用不使用、使用多少随意，但一共只有2个魔法卷轴
  请返回数组尽可能大的累加和*/
private:
  // 暴力方法
  int maxSum1(vector<int> &nums);
  // nums[l...r]范围上用一次卷轴情况下的累加和
  int maxSum1_f1(vector<int> &nums, int l, int r);

  /*1.不用卷轴
  2.只用一次卷轴，（最小子数组连续和）dp[i]在[0..i]位置上必须用一次的情况下到i位置的最大累加和
      a.dp[i-1]+nums[i]
      b.dp[i]往左延伸到某个位置都使用卷轴*/
  int maxSum2(vector<int> &nums);
};
class maxSumOfThreeSubarrays {
private:
  /*给你一个整数数组 nums 和一个整数 k ，找出三个长度为 k
  、互不重叠、且全部数字和（3 * k 项）最大的子数组，并返回这三个子数组。
  以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 0
  开始）。如果有多个结果，返回字典序最小的一个。 示例 1： 输入：nums =
  [1,2,1,2,6,7,5,1], k = 2 输出：[0,3,5] 解释：子数组 [1, 2], [2, 6], [7, 5]
  对应的起始下标为 [0, 3, 5]。 也可以取 [2, 1], 但是结果 [1, 3, 5]
  在字典序上更大。 示例 2： 输入：nums = [1,2,1,2,1,2,1,2,1], k = 2
  输出：[0,2,4]
  提示：
  1 <= nums.length <= 2 * 104
  1 <= nums[i] < 216
  1 <= k <= floor(nums.length / 3)*/
private:
  vector<int> LC689_maxSumOfThreeSubarrays(vector<int> &nums, int k);

public:
  void Test_LC689_maxSumOfThreeSubarrays();
};
class ReverseArraySubarrayMaxSum {
private:
  /*可以翻转1次的情况下子数组最大累加和
  给定
  一个数组nums
  现在允许你随意选择数组连续一段进行翻转，也就是子数组逆序的调整
  比如翻转[1,2,3,4,5,6]的[2~4]区间，得到的是[1,2,5,4,3,6]
  返回必须随意翻转1次后，子数组的最大累加和*/
private:
  // 暴力解法
  int maxSumReverse1(vector<int> &nums);
  // 求翻转后的数组的最大子数组的累加和
  int maxSumReverse1_maxSum(vector<int> &nums);

  int maxSumReverse2(vector<int> &nums);
};
class DeleteOneNumberLengthKMaxSum {
private:
  /*删掉1个数字后长度为k的子数组最大累加和
  给定一个数组nums，求必须删除一个数字后的新数组中
  长度为k的子数组最大累加和，删除哪个数组随意*/
private:
  int MaxSum1(vector<int> &nums, int k);
  int MaxSum1_lenKmaxSum(vector<int> &nums, int k);
  int MaxSum2(vector<int> &nums, int k);
};
} // namespace TheNumberOfMaxSubArray
namespace TheNumberOfArrayEX {
using std::cout;
using std::endl;
using std::function;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
class lengthOfLIS {
private:
  /*给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
  子序列
  是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7]
  是数组 [0,3,1,6,2,2,7] 的子序列。 示例 1： 输入：nums = [10,9,2,5,3,7,101,18]
  输出：4
  解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
  示例 2：
  输入：nums = [0,1,0,3,2,3]
  输出：4
  示例 3：
  输入：nums = [7,7,7,7,7,7,7]
  输出：1
  提示：
  1 <= nums.length <= 2500
  -104 <= nums[i] <= 104
  进阶：
  你能将算法的时间复杂度降低到 O(n log(n)) 吗?*/
private:
  // O(n^2)
  int LC300_lengthOfLIS1(vector<int> &nums);
  // O(n*logn)
  int LC300_lengthOfLIS(vector<int> &nums);

public:
  void Test_LC300_lengthOfLIS();
};
} // namespace TheNumberOfArrayEX
namespace ZeroAndOneBackpackIssues {
using std::cout;
using std::endl;
using std::function;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
/*洛谷P1048*/
class BackPackTemplate {
  int dpBackPack(int n, int m, vector<int> &cost, vector<int> &val);
  // 空间压缩
  int dpBackPack2(int n, int m, vector<int> &cost, vector<int> &val);
};
class lastStoneWeightII {
private:
  /*有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
  每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和
  y，且 x <= y。那么粉碎的可能结果如下： 如果 x ==
  y，那么两块石头都会被完全粉碎； 如果 x != y，那么重量为 x
  的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。 最后，最多只会剩下一块
  石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。 示例 1：
  输入：stones = [2,7,4,1,8,1]
  输出：1
  解释：
  组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
  组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
  组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
  组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
  示例 2：
  输入：stones = [31,26,33,21,40]
  输出：5
  提示：
  1 <= stones.length <= 30
  1 <= stones[i] <= 100*/
private:
  int LC1049_lastStoneWeightII(vector<int> &nums);
};
class TopSum {
private:
  /*非负数组前k个最小子序列的累加和*/
  vector<int> EX_TopSum3(vector<int> &nums, int k);
};
class minInsertions {
private:
  int LC1312_minInsertions(string s);
  int f2(string s, int l, int r, vector<vector<int>> &dp);

public:
  void Test_LC1312_minInsertions();
};
class countPalindromicSubsequences {
private:
  /*给你一个字符串 s ，返回 s 中不同的非空回文子序列个数
  。由于答案可能很大，请返回对 109 + 7 取余 的结果。
  字符串的子序列可以经由字符串删除 0 个或多个字符获得。
  如果一个序列与它反转后的序列一致，那么它是回文序列。
  如果存在某个 i , 满足 ai != bi ，则两个序列 a1, a2, ... 和 b1, b2, ... 不同。
  示例 1：
  输入：s = 'bccb'
  输出：6
  解释：6 个不同的非空回文子字符序列分别为：'b', 'c', 'bb', 'cc', 'bcb',
  'bccb'。 注意：'bcb' 虽然出现两次但仅计数一次。 示例 2： 输入：s =
  'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
  输出：104860361
  解释：共有 3104860382 个不同的非空回文子序列，104860361 是对 109 + 7
  取余后的值。 提示： 1 <= s.length <= 1000 s[i] 仅包含 'a', 'b', 'c' 或 'd' */
  int LC730_countPalindromicSubsequences(string s);

public:
  void Test_LC730_countPalindromicSubsequences();
};
} // namespace ZeroAndOneBackpackIssues
namespace TheTreeDP{
  using std::cout;
  using std::endl;
  using std::function;
  using std::string;
  using std::unordered_map;
  using std::unordered_set;
  using std::vector;
  using std::pair;
  struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int val):val(val),left(nullptr),right(nullptr){};
    TreeNode(int val,TreeNode* left,TreeNode* right):val(val),left(left),right(right){};
  };
  class MaxBSTSize{
    private:
      /*给定一个二叉树，找到其中最大的二叉树，返回该子树的大小*/
      int LC_MaxBSTSize(TreeNode* head);
      pair<bool,vector<long long>>f(TreeNode* Node);
      pair<bool,vector<long long>>f2(TreeNode* Node);
    public:
      void Test_LC_MaxBSTSize();
  };
}