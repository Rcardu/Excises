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
  /*쳲���������*/
  int FibonacciNumber_fib1(int n);
  int FibonacciNumber_f1(int i);

public:
  // 쳲���������
  void Test_FibonacciNumber_fib1();

private:
  /*쳲���������*/
  int FibonacciNumber_fib2(int n);
  int FibonacciNumber_f2(vector<int> &findList, int i);

public:
  // 쳲���������
  void Test_FibonacciNumber_fib2();

private:
  /*쳲���������*/
  int FibonacciNumber_fib3(int n);

public:
  // 쳲���������
  void Test_FibonacciNumber_fib3();

private:
  /*쳲���������*/
  int FibonacciNumber_fib4(int n);

public:
  // 쳲���������
  void Test_FibonacciNumber_fib4();
};
class mincostTickets {
private:
  /*��һ�������к��ܻ�ӭ�Ĺ��ȣ�����ǰһ��ƻ���һЩ�����С��ڽ�������һ���
  ��Ҫ���е����ӽ���һ����Ϊ days �����������ÿһ����һ���� 1 �� 365 ��������
  ��Ʊ�� ���ֲ�ͬ�����۷�ʽ ��
  һ�� Ϊ��һ�� ��ͨ��֤�ۼ�Ϊ costs[0] ��Ԫ��
  һ�� Ϊ������ ��ͨ��֤�ۼ�Ϊ costs[1] ��Ԫ��
  һ�� Ϊ����ʮ�� ��ͨ��֤�ۼ�Ϊ costs[2] ��Ԫ��
  ͨ��֤�������������Ƶ����С� ���磬��������ڵ� 2 ����һ�� Ϊ�� 7 ��
  ��ͨ��֤�� ��ô���ǿ����������� 7 �죺�� 2 �졢�� 3 �졢�� 4 �졢�� 5 �졢�� 6
  �졢�� 7 ��͵� 8 �졣 ���� ����Ҫ����ڸ������б� days
  ���г���ÿһ�����������Ҫ��������� �� ʾ�� 1�� ���룺days = [1,4,6,7,8,20],
  costs = [2,7,15] �����11 ���ͣ�
  ���磬������һ�ֹ���ͨ��֤�ķ����������������������мƻ���
  �ڵ� 1 �죬�㻨�� costs[0] = $2 ����һ��Ϊ�� 1 ���ͨ��֤�������ڵ� 1 ����Ч��
  �ڵ� 3 �죬�㻨�� costs[1] = $7 ����һ��Ϊ�� 7 ���ͨ��֤�������ڵ� 3, 4, ...,
  9 ����Ч�� �ڵ� 20 �죬�㻨�� costs[0] = $2 ����һ��Ϊ�� 1
  ���ͨ��֤�������ڵ� 20 ����Ч�� ���ܹ����� $11�����������ƻ���ÿһ�����С�
  ʾ�� 2��
  ���룺days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
  �����17
  ���ͣ�
  ���磬������һ�ֹ���ͨ��֤�ķ����������������������мƻ���
  �ڵ� 1 �죬�㻨�� costs[2] = $15 ����һ��Ϊ�� 30 ���ͨ��֤�������ڵ� 1, 2,
  ..., 30 ����Ч�� �ڵ� 31 �죬�㻨�� costs[0] = $2 ����һ��Ϊ�� 1
  ���ͨ��֤�������ڵ� 31 ����Ч�� ���ܹ����� $17�����������ƻ���ÿһ�����С�
  ��ʾ��
  1 <= days.length <= 365
  1 <= days[i] <= 365
  days ��˳���ϸ����
  costs.length == 3
  1 <= costs[i] <= 1000*/
  vector<int> durations = {1, 7, 30};

private:
  /*�����ݹ�*/
  int LC983_mincostTickets1(vector<int> &days, vector<int> &costs);
  // ö�ٴӵ�days[i]�쿪ʼ�����һ�����С�����Ƕ���
  int LC983_mincostTickets_f1(vector<int> &days, vector<int> &costs, int i);

public:
  void Test_LC983_mincostTickets1();

private:
  /*�Զ����׼��仯����*/
  int LC983_mincostTickets2(vector<int> &days, vector<int> &costs);
  // ö�ٴӵ�days[i]�쿪ʼ�����һ�����С�����Ƕ���
  int LC983_mincostTickets_f2(vector<int> &days, vector<int> &costs, int i,
                              vector<int> &dp);

public:
  void Test_LC983_mincostTickets2();

private:
  /*�Ե׵�������������*/
  int LC983_mincostTickets3(vector<int> &days, vector<int> &costs);

public:
  void Test_LC983_mincostTickets3();
};
class numDecodings {
private:
  /*һ��������ĸ A-Z ����Ϣͨ������ӳ������� ���� ��
  'A' -> "1"
  'B' -> "2"
  ...
  'Z' -> "26"
  Ҫ ����
  �ѱ������Ϣ���������ֱ����������ӳ��ķ���������ӳ�����ĸ�������ж��ַ����������磬"11106"
  ����ӳ��Ϊ�� "AAJF" ������Ϣ����Ϊ (1 1 10 6) "KJF" ������Ϣ����Ϊ (11 10 6)
  ע�⣬��Ϣ���ܷ���Ϊ  (1 11 06) ����Ϊ "06" ����ӳ��Ϊ "F" ���������� "6" ��
  "06" ��ӳ���в����ȼۡ� ����һ��ֻ�����ֵ� �ǿ� �ַ��� s ������㲢���� ����
  ������ ���� �� ��Ŀ���ݱ�֤�𰸿϶���һ�� 32 λ �������� ʾ�� 1�� ���룺s =
  "12" �����2 ���ͣ������Խ���Ϊ "AB"��1 2������ "L"��12���� ʾ�� 2�� ���룺s =
  "226" �����3 ���ͣ������Խ���Ϊ "BZ" (2 26), "VF" (22 6), ���� "BBF" (2 2 6)
  �� ʾ�� 3�� ���룺s = "06" �����0 ���ͣ�"06" �޷�ӳ�䵽 "F"
  ����Ϊ����ǰ���㣨"6" �� "06" �����ȼۣ��� ��ʾ�� 1 <= s.length <= 100 s
  ֻ�������֣����ҿ��ܰ���ǰ����*/
private:
  // �����ݹ�
  int LC91_numDecodings1(string s);
  // �����ݹ�
  int LC91_numDecodings_f1(string s, int i);

public:
  /*LeetCode 91 ���뷽��*/
  void Test_LC91_numDecodings1();

private:
  // �Զ����׼��仯����
  int LC91_numDecodings2(string s);
  // �Զ����׼��仯����
  int LC91_numDecodings_f2(string s, int i, vector<int> &dp);

public:
  /*LeetCode 91 ���뷽��*/
  void Test_LC91_numDecodings2();

private:
  // �Ե׵����ϸ����
  int LC91_numDecodings3(string s);
  // �ռ��Ż�
  int LC91_numDecodings4(string s);

public:
  /*LeetCode 91 ���뷽��*/
  void Test_LC91_numDecodings3();
};
class numDecodingsII {
private:
  /*һ��������ĸ A-Z ����Ϣͨ�����µķ�ʽ������ ���� ��
  'A' -> "1"
  'B' -> "2"
  ...
  'Z' -> "26"
  Ҫ ����
  һ���ѱ������Ϣ�����е����ֶ�������飬Ȼ��ԭ���ı��뷽������ӳ�����ĸ�����ܴ��ڶ��ַ�ʽ�������磬"11106"
  ����ӳ��Ϊ�� "AAJF" ��Ӧ���� (1 1 10 6) "KJF" ��Ӧ���� (11 10 6) ע�⣬�� (1
  11 06) �����ķ�������Ч�ģ���Ϊ "06" ������ӳ��Ϊ 'F' ����Ϊ "6" �� "06"
  ��ͬ�� ���� ����������������ĸӳ�䷽����������Ϣ�п��ܰ��� '*'
  �ַ������Ա�ʾ�� '1' �� '9' ����һ���֣������� '0'���� ���磬�����ַ��� "1*"
  ���Ա�ʾ "11"��"12"��"13"��"14"��"15"��"16"��"17"��"18" �� "19"
  �е�����һ����Ϣ���� "1*" ���н��룬
  �൱�ڽ�����ַ������Ա�ʾ���κα�����Ϣ��
  ����һ���ַ��� s �������ֺ� '*' �ַ���ɣ����� ���� ���ַ����ķ��� ��Ŀ ��
  ���ڴ���Ŀ���ܷǳ��󣬷��� 109 + 7 �� ģ ��
  ʾ�� 1��
  ���룺s = "*"
  �����9
  ���ͣ���һ��������Ϣ���Ա�ʾ "1"��"2"��"3"��"4"��"5"��"6"��"7"��"8" �� "9"
  �е�����һ���� ���Էֱ������ַ��� "A"��"B"��"C"��"D"��"E"��"F"��"G"��"H" ��
  "I" �� ��ˣ�"*" �ܹ��� 9 �ֽ��뷽���� ʾ�� 2�� ���룺s = "1*" �����18
  ���ͣ���һ��������Ϣ���Ա�ʾ "11"��"12"��"13"��"14"��"15"��"16"��"17"��"18" ��
  "19" �е�����һ���� ÿ����Ϣ�������� 2 �ַ������루���磬"11" ���Խ���� "AA"
  �� "K"���� ��ˣ�"1*" ���� 9 * 2 = 18 �ֽ��뷽���� ʾ�� 3�� ���룺s = "2*"
  �����15
  ���ͣ���һ��������Ϣ���Ա�ʾ "21"��"22"��"23"��"24"��"25"��"26"��"27"��"28" ��
  "29" �е�����һ���� "21"��"22"��"23"��"24"��"25" �� "26" �� 2 �ֽ��뷽������
  "27"��"28" �� "29" ���� 1 �ֽ��뷽���� ��ˣ�"2*" ���� (6 * 2) + (3 * 1) = 12
  + 3 = 15 �ֽ��뷽���� ��ʾ�� 1 <= s.length <= 105 s[i] �� 0 - 9
  �е�һλ���ֻ��ַ� '*'*/
  constexpr static int MOD = 1000000007;

private:
  /*�����ݹ�*/
  int LC639_numDecodingsII1(string s);
  int LC639_numDecodingsII_f1(string s, int i);

public:
  void Test_LC639_numDecodingsII1();

private:
  /*���仯����*/
  int LC639_numDecodingsII2(string s);
  long LC639_numDecodingsII_f2(string s, int i, vector<long> &dp);

public:
  void Test_LC639_numDecodingsII2();

private:
  /*�Ե�����*/
  int LC639_numDecodingsII3(string s);
  /*�ռ��Ż�*/
  int LC639_numDecodingsII4(string s);

public:
  void Test_LC639_numDecodingsII3();
};
class nthUglyNumber {
private:
  /*����һ������ n �������ҳ������ص� n �� ���� ��
  ���� ����ֻ���������� 2��3 ��/�� 5 ����������
  ʾ�� 1��
  ���룺n = 10
  �����12
  ���ͣ�[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] ����ǰ 10 ��������ɵ����С�
  ʾ�� 2��
  ���룺n = 1
  �����1
  ���ͣ�1 ͨ������Ϊ������
  ��ʾ��
  1 <= n <= 1690*/
  int LC264_nthUglyNumber(int n);

public:
  void Test_LC264_nthUglyNumber();
};
class longestValidParentheses {
private:
  /*����һ��ֻ���� '(' �� ')'
  ���ַ������ҳ����Ч����ʽ��ȷ�������������Ӵ��ĳ��ȡ� ʾ�� 1�� ���룺s =
  "(()" �����2 ���ͣ����Ч�����Ӵ��� "()" ʾ�� 2�� ���룺s = ")()())"
  �����4
  ���ͣ����Ч�����Ӵ��� "()()"
  ʾ�� 3��
  ���룺s = ""
  �����0
  ��ʾ��
  0 <= s.length <= 3 * 104
  s[i] Ϊ '(' �� ')'*/
  int LC32_longestValidParentheses(string s);

public:
  void Test_LC32_longestValidParentheses();
};
class findSubstringInWraproundString {
private:
  /*�����ַ��� base Ϊһ�� "abcdefghijklmnopqrstuvwxyz" ���޻��Ƶ��ַ���������
  base �������������ģ�
  "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
  ����һ���ַ��� s ������ͳ�Ʋ����� s ���ж��� ��ͬ�ǿ��Ӵ� Ҳ�� base �г��֡�
  ʾ�� 1��
  ���룺s = "a"
  �����1
  ���ͣ��ַ��� s �����ַ��� "a" �� base �г��֡�
  ʾ�� 2��
  ���룺s = "cac"
  �����2
  ���ͣ��ַ��� s ���������ַ��� ("a", "c") �� base �г��֡�
  ʾ�� 3��
  ���룺s = "zab"
  �����6
  ���ͣ��ַ��� s ���������ַ��� ("z", "a", "b", "za", "ab", and "zab") �� base
  �г��֡� ��ʾ�� 1 <= s.length <= 105 s ��СдӢ����ĸ���*/
  int LC467_findSubstringInWraproundString(string s);

public:
  void Test_LC467_findSubstringInWraproundString();
};
class distinctSubseqII {
private:
  constexpr static int MOD = 1000000007;
  /*����һ���ַ��� s������ s �� ��ͬ�ǿ�������
  �ĸ�������Ϊ������ܴܺ����Է��ش���Ҫ�� 10^9 + 7 ȡ�� �� �ַ����� ������
  �Ǿ���ԭ�ַ���ɾ��һЩ��Ҳ���ܲ�ɾ�����ַ������ı�ʣ���ַ����λ�õ�һ�����ַ�����
  ���磬"ace" �� "abcde" ��һ�������У��� "aec" ���ǡ�
  ʾ�� 1��
  ���룺s = "abc"
  �����7
  ���ͣ�7 ����ͬ�������зֱ��� "a", "b", "c", "ab", "ac", "bc", �Լ� "abc"��
  ʾ�� 2��
  ���룺s = "aba"
  �����6
  ���ͣ�6 ����ͬ�������зֱ��� "a", "b", "ab", "ba", "aa" �Լ� "aba"��
  ʾ�� 3��
  ���룺s = "aaa"
  �����3
  ���ͣ�3 ����ͬ�������зֱ��� "a", "aa" �Լ� "aaa"��
  ��ʾ��
  1 <= s.length <= 2000
  s ����СдӢ����ĸ���
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
  /*����һ�������Ǹ������� m x n ���� grid
  �����ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
  ˵����ÿ��ֻ�����»��������ƶ�һ����
  ʾ�� 1��
  ���룺grid = [[1,3,1],[1,5,1],[4,2,1]]
  �����7
  ���ͣ���Ϊ·�� 1��3��1��1��1 ���ܺ���С��
  ʾ�� 2��
  ���룺grid = [[1,2,3],[4,5,6]]
  �����12
  ��ʾ��
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 200
  0 <= grid[i][j] <= 200*/
private:
  int LC64_minPathSum(vector<vector<int>> &grid);
  // �����ݹ�
  int LC64_minPathSum_f1(vector<vector<int>> &grid, int i, int j);
  // ���仯����
  int LC64_minPathSum2(vector<vector<int>> &grid);
  int LC64_minPathSum_f2(vector<vector<int>> &grid, int i, int j,
                         vector<vector<int>> &dp);
  // �ϸ�����
  int LC64_minPathSum3(vector<vector<int>> &grid);
  // �ռ��Ż�
  int LC64_minPathSum4(vector<vector<int>> &grid);

public:
  void Test_LC64_minPathSum();
  void Test_LC64_minPathSum2();
  void Test_LC64_minPathSum3();
};
class exist {
private:
  /*����һ�� m x n ��ά�ַ����� board ��һ���ַ������� word ����� word
  �����������У����� true �����򣬷��� false ��
  ���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�
  ʾ�� 1��
  ���룺board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
  "ABCCED" �����true ʾ�� 2�� ���룺board =
  [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
  �����true
  ʾ�� 3��
  ���룺board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
  "ABCB" �����false ��ʾ�� m == board.length n = board[i].length 1 <= m, n <= 6
  1 <= word.length <= 15
  board �� word ���ɴ�СдӢ����ĸ���*/
private:
  bool LC79_exist(vector<vector<char>> &board, string word);
  bool LC79_exist_f(vector<vector<char>> &board, int i, int j, string word,
                    int k);

public:
  void Test_LC79_exist();
};
class longestCommonSubsequence {
private:
  /*���������ַ��� text1 �� text2�������������ַ������ ����������
  �ĳ��ȡ���������� ���������� ������ 0 �� һ���ַ����� ������
  ��ָ����һ���µ��ַ�����������ԭ�ַ����ڲ��ı��ַ������˳��������ɾ��ĳЩ�ַ���Ҳ���Բ�ɾ���κ��ַ�������ɵ����ַ�����
  ���磬"ace" �� "abcde" �������У��� "aec" ���� "abcde" �������С�
  �����ַ����� ���������� ���������ַ�������ͬӵ�е������С�
  ʾ�� 1��
  ���룺text1 = "abcde", text2 = "ace"
  �����3
  ���ͣ�������������� "ace" �����ĳ���Ϊ 3 ��
  ʾ�� 2��
  ���룺text1 = "abc", text2 = "abc"
  �����3
  ���ͣ�������������� "abc" �����ĳ���Ϊ 3 ��
  ʾ�� 3
  ���룺text1 = "abc", text2 = "def"
  �����0
  ���ͣ������ַ���û�й��������У����� 0 ��
  ��ʾ��
  1 <= text1.length, text2.length <= 1000
  text1 �� text2 ����СдӢ���ַ���ɡ�*/
private:
  // ���ѵݹ�
  int LC1143_longestCommonSubsequence1(string text1, string text2);
  int LC1143_longestCommonSubsequence_f1(string text1, string text2, int i1,
                                         int i2);
  // ���ѵݹ�,�ñ�������������Ӧ��̬�滮
  int LC1143_longestCommonSubsequence2(string text1, string text2);
  int LC1143_longestCommonSubsequence_f2(string text1, string text2, int len1,
                                         int len2);
  // ���仯����
  int LC1143_longestCommonSubsequence3(string text1, string text2);
  int LC1143_longestCommonSubsequence_f3(string text1, string text2, int len1,
                                         int len2, vector<vector<int>> &dp);
  // �ϸ�λ������
  int LC1143_longestCommonSubsequence4(string text1, string text2);
  // �ռ��Ż�
  int LC1143_longestCommonSubsequence5(string text1, string text2);

public:
  void Test_LC1143_longestCommonSubsequence();
};
class longestPalindromeSubseq {
private:
  /*����һ���ַ��� s ���ҳ�������Ļ��������У������ظ����еĳ��ȡ�
  �����ж���Ϊ�����ı�ʣ���ַ�˳�������£�ɾ��ĳЩ�ַ����߲�ɾ���κ��ַ��γɵ�һ�����С�
  ʾ�� 1��
  ���룺s = "bbbab"
  �����4
  ���ͣ�һ�����ܵ������������Ϊ "bbbb" ��
  ʾ�� 2��
  ���룺s = "cbbd"
  �����2
  ���ͣ�һ�����ܵ������������Ϊ "bb" ��
  ��ʾ��
  1 <= s.length <= 1000
  s ����СдӢ����ĸ���*/
private:
  // ��������������ԭ��������������������
  int LC516_longestPalindromeSubseq_EX(string s);
  // �����ݹ�
  int LC516_longestPalindromeSubseq1(string s);
  int LC516_longestPalindromeSubseq1_f1(string s, int l, int r);
  // ���仯����
  int LC516_longestPalindromeSubseq2(string s);
  int LC516_longestPalindromeSubseq1_f2(string s, int l, int r,
                                        vector<vector<int>> &dp);
  // �ϸ�λ������
  int LC516_longestPalindromeSubseq3(string s);
  // �ռ�ѹ��
  int LC516_longestPalindromeSubseq4(string s);

public:
  void Test_LC516_longestPalindromeSubseq();
};
class NodenHeightNotLargerThanm {
private:
  /*�ڵ���Ϊn�߶Ȳ�����m�Ķ���������
  ������n���ڵ㣬������ж��ٸ���ͬ�ṹ�Ķ�����
  ����ڵ����Ϊn�����ĸ߶Ȳ�����m�ķ���
  ��Ϊ�𰸺ܴ����Դ���Ҫģ��10^9+7���*/
  constexpr static int MOD = 1000000007;

private:
  // ���仯����
  int Main_Compute1(int n, int m);
  int Compute1(int n, int m, vector<vector<int>> &dp);
  // �ϸ�λ������
  int Main_Compute2(int n, int m);
  // �ռ�ѹ��
  int Main_Compute3(int n, int m);

public:
  void Test_Main_Compute();
};
class longestIncreasingPath {
private:
  /*����һ�� m x n �������� matrix ���ҳ����� �����·�� �ĳ��ȡ�
  ����ÿ����Ԫ����������ϣ��£������ĸ������ƶ��� �� ���� �� �Խ���
  �������ƶ����ƶ��� �߽��⣨���������ƣ��� ʾ�� 1�� ���룺matrix =
  [[9,9,4],[6,6,8],[2,1,1]] �����4 ���ͣ������·��Ϊ [1, 2, 6, 9]�� ʾ�� 2��
  ���룺matrix = [[3,4,5],[3,2,6],[2,2,1]]
  �����4
  ���ͣ������·���� [3, 4, 5, 6]��ע�ⲻ�����ڶԽ��߷������ƶ���
  ʾ�� 3��
  ���룺matrix = [[1]]
  �����1*/
private:
  int LC329_longestIncreasingPath1(vector<vector<int>> &matrix);
  int LC329_longestIncreasingPath1_f1(vector<vector<int>> &grid, int i, int j);
  // ���仯����
  int LC329_longestIncreasingPath2(vector<vector<int>> &matrix);
  int LC329_longestIncreasingPath1_f2(vector<vector<int>> &grid, int i, int j,
                                      vector<vector<int>> &dp);

public:
  void Test_LC329_longestIncreasingPath();
};
class numDistinct {
private:
  /*���������ַ��� s �� t ��ͳ�Ʋ������� s �� ������ �� t ���ֵĸ����������Ҫ��
  109 + 7 ȡģ�� ʾ�� 1�� ���룺s = "rabbbit", t = "rabbit" �����3 ���ͣ�
  ������ʾ, �� 3 �ֿ��Դ� s �еõ� "rabbit" �ķ�����
  rabbbit
  rabbbit
  rabbbit
  ʾ�� 2��
  ���룺s = "babgbag", t = "bag"
  �����5
  ���ͣ�
  ������ʾ, �� 5 �ֿ��Դ� s �еõ� "bag" �ķ�����
  babgbag
  babgbag
  babgbag
  babgbag
  babgbag
  ��ʾ��
  1 <= s.length, t.length <= 1000
  s �� t ��Ӣ����ĸ���*/
private:
  int LC115_numDistinct(string s, string t);
  // �ռ�ѹ��
  int LC115_numDistinct_EC(string s, string t);

public:
  void Test_LC115_numDistinct();
};
class minDistance {
private:
  /*������������ word1 �� word2�� �뷵�ؽ� word1 ת���� word2 ��ʹ�õ����ٲ�����
  �� ����Զ�һ�����ʽ����������ֲ����� ����һ���ַ�������a ɾ��һ���ַ�������b
  �滻һ���ַ�������c
  ʾ�� 1��
  ���룺word1 = "horse", word2 = "ros"
  �����3
  ���ͣ�
  horse -> rorse (�� 'h' �滻Ϊ 'r')
  rorse -> rose (ɾ�� 'r')
  rose -> ros (ɾ�� 'e')
  ʾ�� 2��
  ���룺word1 = "intention", word2 = "execution"
  �����5
  ���ͣ�
  intention -> inention (ɾ�� 't')
  inention -> enention (�� 'i' �滻Ϊ 'e')
  enention -> exention (�� 'n' �滻Ϊ 'x')
  exention -> exection (�� 'n' �滻Ϊ 'c')
  exection -> execution (���� 'u')
  ��ʾ��
  0 <= word1.length, word2.length <= 500
  word1 �� word2 ��СдӢ����ĸ���*/
private:
  int LC72_minDistance1(string word1, string word2, int a, int b, int c);
  // �ռ�ѹ��
  int LC72_minDistance_EC(string word1, string word2, int a, int b, int c);

public:
  void Test_LC72_minDistance();
};
class isInterleave {
private:
  /*���������ַ��� s1��s2��s3�������æ��֤ s3 �Ƿ����� s1 �� s2 ���� ��ɵġ�
  �����ַ��� s �� t ���� �Ķ�����������£�����ÿ���ַ������ᱻ�ָ������ �ǿ�
  ���ַ����� s = s1 + s2 + ... + sn t = t1 + t2 + ... + tm |n - m| <= 1 ���� ��
  s1 + t1 + s2 + t2 + s3 + t3 + ... ���� t1 + s1 + t2 + s2 + t3 + s3 + ...
  ע�⣺a + b ��ζ���ַ��� a �� b ���ӡ�
  ʾ�� 1��
  ���룺s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
  �����true
  ʾ�� 2��
  ���룺s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
  �����false
  ʾ�� 3��
  ���룺s1 = "", s2 = "", s3 = ""
  �����true
  ��ʾ��
  0 <= s1.length, s2.length <= 100
  0 <= s3.length <= 200
  s1��s2���� s3 ����СдӢ����ĸ���*/
private:
  bool LC97_isInterleave(string s1, string s2, string s3);
  // �ռ�ѹ��
  bool LC97_isInterleave_EC(string s1, string s2, string s3);

public:
  void Test_LC97_isInterleave();
};
class effectiveColoring {
private:
  /*��ЧͿɫ����
  ����n��m��������
  һ����n�����ӣ�ÿ�����ӿ���Ϳ��һ����ɫ����ɫ��m����ѡ
  ��Ϳ��n�����ӣ�����m����ɫ�������ˣ���һ����Ч����
  ��һ���ж�������ЧͿɫ�ķ���
  1<=n,m<=5000
  ����Ƚϴ����10^9+7ȡ�෵�ؽ��*/
  constexpr static int MOD = 1000000007;

private:
  int Ex_effectiveColoring(int n, int m);

public:
  void Test_Ex_effectiveColoring();
};
class stringChanges {
private:
  /*ɾ�����ټ����ַ����Ա����һ���ַ������Ӵ�
  ���������ַ���s1��s2
  ����s1����ɾ�����ٸ��ַ����Գ�Ϊs2���Ӵ�*/
private:
  int EX_stringChanges(string s1, string s2);

public:
  void Test_EX_stringChanges();
};
class smallestMissingValueSubtree {
private:
  /*��һ�ø��ڵ�Ϊ 0 �� ������ ���ܹ����� n ���ڵ㣬�ڵ���Ϊ 0 �� n - 1
  ������һ���±�� 0 ��ʼ���������� parents ������ parents[i] �ǽڵ� i
  �ĸ��ڵ㡣���ڽڵ� 0 �� �� ������ parents[0] == -1 �� �ܹ��� 105
  ������ֵ��ÿ������ֵ���� ������ [1, 105] �е�һ��������ʾ������һ���±�� 0
  ��ʼ���������� nums ������ nums[i] �ǽڵ� i �Ļ���ֵ���һ���ֵ ������ͬ ��
  ���㷵��һ������ ans ������Ϊ n ������ ans[i] ���Խڵ� i Ϊ���������� ȱʧ ��
  ��С ����ֵ�� �ڵ� x Ϊ���� ���� �����ڵ� x �������е� ��� �ڵ㡣 ʾ�� 1��
  ���룺parents = [-1,0,0,2], nums = [1,2,3,4]
  �����[5,1,1,1]
  ���ͣ�ÿ�������𰸼��������£�
  - 0�����������ڵ� [0,1,2,3] ������ֵ�ֱ�Ϊ [1,2,3,4] ��5 ��ȱʧ����С����ֵ��
  - 1������ֻ�����ڵ� 1 ������ֵΪ 2 ��1 ��ȱʧ����С����ֵ��
  - 2�����������ڵ� [2,3] ������ֵ�ֱ�Ϊ [3,4] ��1 ��ȱʧ����С����ֵ��
  - 3������ֻ�����ڵ� 3 ������ֵΪ 4 ��1��ȱʧ����С����ֵ��
  ʾ�� 2��
  ���룺parents = [-1,0,1,0,3,3], nums = [5,4,6,2,1,3]
  �����[7,1,1,4,2,1]
  ���ͣ�ÿ�������𰸼��������£�
  - 0�������ڰ����ڵ� [0,1,2,3,4,5] ������ֵ�ֱ�Ϊ [5,4,6,2,1,3] ��7
  ��ȱʧ����С����ֵ��
  - 1�������ڰ����ڵ� [1,2] ������ֵ�ֱ�Ϊ [4,6] �� 1 ��ȱʧ����С����ֵ��
  - 2��������ֻ�����ڵ� 2 ������ֵΪ 6 ��1 ��ȱʧ����С����ֵ��
  - 3�������ڰ����ڵ� [3,4,5] ������ֵ�ֱ�Ϊ [2,1,3] ��4 ��ȱʧ����С����ֵ��
  - 4��������ֻ�����ڵ� 4 ������ֵΪ 1 ��2 ��ȱʧ����С����ֵ��
  - 5��������ֻ�����ڵ� 5 ������ֵΪ 3 ��1 ��ȱʧ����С����ֵ��
  ʾ�� 3��
  ���룺parents = [-1,2,3,0,2,4,1], nums = [2,3,4,5,6,7,8]
  �����[1,1,1,1,1,1,1]
  ���ͣ�����������ȱʧ����ֵ 1 ��
  ��ʾ��
  n == parents.length == nums.length
  2 <= n <= 105
  ���� i != 0 ������ 0 <= parents[i] <= n - 1
  parents[0] == -1
  parents ��ʾһ�úϷ�������
  1 <= nums[i] <= 105
  nums[i] ������ͬ��*/
private:
  vector<int> LC2003_smallestMissingValueSubtree(vector<int> &parents,
                                                 vector<int> &nums);

public:
  /*LeetCode 2003 ÿ��������ȱʧ����С����ֵ*/
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
  /*����һ���������ַ������� strs ���������� m �� n ��
  �����ҳ������� strs ������Ӽ��ĳ��ȣ����Ӽ��� ��� �� m �� 0 �� n �� 1 ��
  ��� x ������Ԫ��Ҳ�� y ��Ԫ�أ����� x �Ǽ��� y �� �Ӽ� ��
  ʾ�� 1��
  ���룺strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
  �����4
  ���ͣ������ 5 �� 0 �� 3 �� 1 ������Ӽ��� {"10","0001","1","0"} ����˴���
  4 �� �����������⵫��С���Ӽ����� {"0001","1"} �� {"10","1","0"} ��{"111001"}
  ���������⣬��Ϊ���� 4 �� 1 ������ n ��ֵ 3 �� ʾ�� 2�� ���룺strs = ["10",
  "0", "1"], m = 1, n = 1 �����2 ���ͣ������Ӽ��� {"0", "1"} �����Դ��� 2
  �� ��ʾ�� 1 <= strs.length <= 600 1 <= strs[i].length <= 100 strs[i] ���� '0'
  �� '1' ��� 1 <= m, n <= 100*/
  int zeros, ones;

private:
  int LC474_findMaxForm1(vector<string> &strs, int m, int n);
  // ͳ��һ���ַ��������һ�ĸ���
  void LC474_findMaxForm1_conts(string str);
  // �����ݹ�Ѱ��
  int LC474_findMaxForm1_f1(vector<string> &strs, int i, int z, int o);
  // ���仯����
  int LC474_findMaxForm2(vector<string> &strs, int m, int n);
  int LC474_findMaxForm1_f2(vector<string> &strs, int i, int z, int o,
                            vector<vector<vector<int>>> &dp);
  // �ϸ�λ������
  int LC474_findMaxForm3(vector<string> &strs, int m, int n);
  // �Ż�
  int LC474_findMaxForm4(vector<string> &strs, int m, int n);

public:
  void Test_LC474_findMaxForm();
};
class profitableSchemes {
private:
  /*�������� n ��Ա�������ǿ�����ɸ��ָ����Ĺ�����������
  �� i �ֹ�������� profit[i] ��������Ҫ�� group[i]
  ����Ա��ͬ���롣�����Ա����������һ������Ͳ��ܲ�����һ�����
  �������κ����ٲ��� minProfit ������Ӽ���Ϊ ӯ���ƻ�
  �����ҹ����ĳ�Ա�������Ϊ n �� �ж����ּƻ�����ѡ����Ϊ�𰸺ܴ�����
  ���ؽ��ģ 10^9 + 7 ��ֵ�� ʾ�� 1�� ���룺n = 5, minProfit = 3, group = [2,2],
  profit = [2,3] �����2 ���ͣ����ٲ��� 3 �����󣬸ü��ſ�����ɹ��� 0 �͹��� 1
  �������ɹ��� 1 �� �ܵ���˵�������ּƻ��� ʾ�� 2�� ���룺n = 10, minProfit =
  5, group = [2,3,5], profit = [6,7,8] �����7 ���ͣ����ٲ��� 5
  ������ֻҪ�������һ�ֹ������У����Ըü��ſ�������κι����� �� 7
  �ֿ��ܵļƻ���(0)��(1)��(2)��(0,1)��(0,2)��(1,2)���Լ� (0,1,2) �� ��ʾ�� 1 <=
  n <= 100 0 <= minProfit <= 100 1 <= group.length <= 100 1 <= group[i] <= 100
  profit.length == group.length
  0 <= profit[i] <= 100*/
  constexpr static int MOD = 1000000007;

private:
  int LC879_profitableSchemes1(int n, int minProfit, vector<int> &group,
                               vector<int> &profit);
  int LC879_profitableSchemes_f1(vector<int> &group, vector<int> &profit, int i,
                                 int r, int s);
  // ���仯����
  int LC879_profitableSchemes2(int n, int minProfit, vector<int> &group,
                               vector<int> &profit);
  int LC879_profitableSchemes_f2(vector<int> &group, vector<int> &profit, int i,
                                 int r, int s, vector<vector<vector<int>>> &dp);
  // �ϸ�λ������
  int LC879_profitableSchemes3(int n, int minProfit, vector<int> &group,
                               vector<int> &profit);

public:
  void Test_LC879_profitableSchemes();
};
class knightProbability {
private:
  /*��һ�� n x n �Ĺ������������ϣ�һ����ʿ�ӵ�Ԫ�� (row, column)
  ��ʼ�������Խ��� k ���ƶ����к����� �� 0 ��ʼ �ģ��������ϵ�Ԫ���� (0,0)
  �����µ�Ԫ���� (n - 1, n - 1) ��
  ������ʿ��8�ֿ��ܵ��߷�������ͼ��ʾ��ÿ���ƶ��ڻ�����������������Ԫ��Ȼ����������������һ����Ԫ��
  ÿ����ʿҪ�ƶ�ʱ�������������8�ֿ��ܵ��ƶ���ѡ��һ��(��ʹ���ӻ��뿪����)��Ȼ���ƶ������
  ��ʿ�����ƶ���ֱ�������� k �����뿪�����̡�
  ���� ��ʿ������ֹͣ�ƶ��������������ϵĸ��� ��
  ʾ�� 1��
  ����: n = 3, k = 2, row = 0, column = 0
  ���: 0.0625
  ����: ������(��(1,2)��(2,1))��������ʿ���������ϡ�
  ��ÿһ��λ���ϣ�Ҳ�������ƶ���������ʿ���������ϡ�
  ��ʿ���������ϵ��ܸ�����0.0625��
  ʾ�� 2��
  ����: n = 1, k = 0, row = 0, column = 0
  ���: 1.00000
  ��ʾ:
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
  /*����һ���±�� 0 ��ʼ�� m x n �������� grid ��һ������ k �������� (0, 0)
  ������ÿһ��ֻ���� �� ������ �� ������Ҫ�����յ� (m - 1, n - 1) ��
  ���㷵��·�����ܱ� k ������·����Ŀ�����ڴ𰸿��ܴܺ󣬷��ش𰸶� 109 + 7 ȡ��
  �Ľ���� ʾ�� 1�� ���룺grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3 �����2
  ���ͣ�������·������·����Ԫ�صĺ��ܱ� k ������
  ��һ��·��Ϊ��ͼ���ú�ɫ��ע��·������Ϊ 5 + 2 + 4 + 5 + 2 = 18 ���ܱ� 3
  ������ �ڶ���·��Ϊ��ͼ������ɫ��ע��·������Ϊ 5 + 3 + 0 + 5 + 2 = 15 ���ܱ�
  3 ������ ʾ�� 2�� ���룺grid = [[0,0]], k = 5 �����1 ���ͣ���ɫ��ע��·����Ϊ
  0 + 0 = 0 ���ܱ� 5 ������ ʾ�� 3�� ���룺grid =
  [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1 �����10 ���ͣ�ÿ�����ֶ��ܱ� 1
  ����������ÿһ��·���ĺͶ��ܱ� k ������ ��ʾ�� m == grid.length n ==
  grid[i].length 1 <= m, n <= 5 * 104 1 <= m * n <= 5 * 104 0 <= grid[i][j] <=
  100 1 <= k <= 50*/
  constexpr static int MOD = 1000000007;

private:
  int LC2435_numberOfPaths(vector<vector<int>> &grid, int k);
  // ��ǰλ�õ����ܷ�k����
  int LC2435_numberOfPaths_f1(vector<vector<int>> &grid, int n, int m, int k,
                              int i, int j, int r);

  // ���仯����
  int LC2435_numberOfPaths2(vector<vector<int>> &grid, int k);
  // ��ǰλ�õ����ܷ�k����
  int LC2435_numberOfPaths_f2(vector<vector<int>> &grid, int n, int m, int k,
                              int i, int j, int r,
                              vector<vector<vector<int>>> &dp);
  // �ϸ�λ������
  int LC2435_numberOfPaths3(vector<vector<int>> &grid, int k);

public:
  void Test_LC2435_numberOfPaths();
};
class isScramble {
private:
  /*ʹ�������������㷨���������ַ��� s �õ��ַ��� t ��
  ����ַ����ĳ���Ϊ 1 ���㷨ֹͣ
  ����ַ����ĳ��� > 1 ��ִ���������裺
  ��һ������±괦���ַ����ָ�������ǿյ����ַ��������������֪�ַ��� s
  ������Խ���ֳ��������ַ��� x �� y �������� s = x + y �� ���
  ������Ҫ�������������ַ���������Ҫ���������������ַ�����˳�򲻱䡹��������ִ����һ����֮��s
  ������ s = x + y ���� s = y + x �� �� x �� y ���������ַ����ϼ����Ӳ��� 1
  ��ʼ�ݹ�ִ�д��㷨�� �������� ������� ���ַ��� s1 �� s2���ж� s2 �Ƿ��� s1
  �������ַ���������ǣ����� true �����򣬷��� false �� ʾ�� 1�� ���룺s1 =
  "great", s2 = "rgeat" �����true ���ͣ�s1 �Ͽ��ܷ�����һ�������ǣ� "great" -->
  "gr/eat" // ��һ������±괦�ָ�õ��������ַ��� "gr/eat" --> "gr/eat" //
  ������������������������ַ�����˳�򲻱䡹 "gr/eat" --> "g/r / e/at" //
  �����ַ����ϵݹ�ִ�д��㷨���������ַ����ֱ�������±괦����һ�ַָ� "g/r /
  e/at" --> "r/g / e/at" //
  �����������һ�顸�����������ַ��������ڶ��顸�������������ַ�����˳�򲻱䡹
  "r/g / e/at" --> "r/g / e/ a/t" // �����ݹ�ִ�д��㷨���� "at" �ָ�õ� "a/t"
  "r/g / e/ a/t" --> "r/g / e/ a/t" //
  ������������������������ַ�����˳�򲻱䡹 �㷨��ֹ������ַ����� s2
  ��ͬ������ "rgeat" ����һ���ܹ����� s1 �õ� s2 �����Σ�������Ϊ s2 �� s1
  �������ַ��������� true ʾ�� 2�� ���룺s1 = "abcde", s2 = "caebd" �����false
  ʾ�� 3��
  ���룺s1 = "a", s2 = "a"
  �����true
  ��ʾ��
  s1.length == s2.length
  1 <= s1.length <= 30
  s1 �� s2 ��СдӢ����ĸ���*/
private:
  bool LC87_isScramble(string s1, string s2);
  bool LC87_isScramble_f1(string &s1, int l1, int r1, string &s2, int l2,
                          int r2);
  // ���仯����
  bool LC87_isScramble2(string s1, string s2);
  bool LC87_isScramble_f2(string &s1, string &s2, int l1, int l2, int len,
                          vector<vector<vector<int>>> &dp);
  // �ϸ�λ������
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
  /*����һ���������� nums
  �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
  ������ �������е�һ���������֡�
  ʾ�� 1��
  ���룺nums = [-2,1,-3,4,-1,2,1,-5,4]
  �����6
  ���ͣ����������� [4,-1,2,1] �ĺ����Ϊ 6 ��
  ʾ�� 2��
  ���룺nums = [1]
  �����1
  ʾ�� 3��
  ���룺nums = [5,4,-1,7,8]
  �����23
  ��ʾ��
  1 <= nums.length <= 105
  -104 <= nums[i] <= 104*/
private:
  int LC53_maxsubArray1(vector<int> &nums);
  // �ռ�ѹ��
  int LC53_maxsubArray2(vector<int> &nums);
  // ��չ���ҳ�����ۼӺ͵�����
  vector<int> LC53_maxsubArray_EX(vector<int> &nums);

private:
  /*��������������ۼӺ�����*/
  int LC918_maxsubArray3(vector<int> &nums);

public:
  void Test_LC53_maxsubArray();
};
class Rob {
private:
  /*����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
  ����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������
  ��һҹ֮���ܹ�͵�Ե�����߽� ʾ�� 1�� ���룺[1,2,3,1] �����4 ���ͣ�͵�� 1
  �ŷ��� (��� = 1) ��Ȼ��͵�� 3 �ŷ��� (��� = 3)�� ͵�Ե�����߽�� = 1 + 3 =
  4 �� ʾ�� 2�� ���룺[2,7,9,3,1] �����12 ���ͣ�͵�� 1 �ŷ��� (��� = 2), ͵��
  3 �ŷ��� (��� = 9)������͵�� 5 �ŷ��� (��� = 1)�� ͵�Ե�����߽�� = 2 + 9 +
  1 = 12 �� ��ʾ�� 1 <= nums.length <= 100 0 <= nums[i] <= 400*/
private:
  int LC198_rob(vector<int> &nums);
  int LC198_rob2(vector<int> &nums);

private:
  /*��������������ۼӺ�����*/
  int LC213_rob(vector<int> &nums);
  /*LeetCode 2560 ��ҽ���IV*/
  int LC2560_rob(vector<int> &nums, int k);

public:
  void Test_LC198_rob();
};
class getMaxMatrix {
private:
  /*����һ������������������ 0 ��ɵ� N �� M
  ���󣬱�д�����ҳ�Ԫ���ܺ������Ӿ��� ����һ������ [r1, c1, r2, c2]������
  r1, c1 �ֱ�����Ӿ������Ͻǵ��кź��кţ�r2, c2
  �ֱ�������½ǵ��кź��кš����ж�������������Ӿ��󣬷�������һ�����ɡ�
  ע�⣺�����������ԭ�������Ķ�
  ʾ����
  ���룺
  [
  [-1,0],
  [0,-1]
  ]
  �����[0,1,0,1]
  ���ͣ������б�ֵ�Ԫ�ؼ�Ϊ�������ʾ�ľ���
  ˵����
  1 <= matrix.length, matrix[0].length <= 200*/
private:
  vector<int> MS1724_getMaxMatrix(vector<vector<int>> &matrix);

public:
  void Test_MS1724_getMaxMatrix();
};
class maxProduct {
private:
  /*����һ���������� nums
  �������ҳ������г˻����ķǿ����������飨�������������ٰ���һ�����֣��������ظ�����������Ӧ�ĳ˻���
  ���������Ĵ���һ�� 32-λ ������
  ������ ����������������С�
  ʾ�� 1:
  ����: nums = [2,3,-2,4]
  ���: 6
  ����: ������ [2,3] �����˻� 6��
  ʾ�� 2:
  ����: nums = [-2,0,-1]
  ���: 0
  ����: �������Ϊ 2, ��Ϊ [-2,-1] ���������顣
  ��ʾ:
  1 <= nums.length <= 2 * 104
  -10 <= nums[i] <= 10
  nums ���κ�ǰ׺���׺�ĳ˻��� ��֤ ��һ�� 32-λ ����*/
private:
  int LC152_maxProduct(vector<int> &nums);

public:
  void Test_LC152_maxProduct();
};
class MaxProSub {
private:
  /*�������ۼӺͱ��뱻7����������ۼӺ�
  ����һ���Ǹ�����nums
  ��������ѡ��������������У����������е��ۼӺͱ��뱻7����
  ��������ۼӺ�*/
private:
  // ��������
  int maxSum1(vector<int> &nums);
  // ������������%7==0���ۼӺ�ö�٣��ҳ������Ǹ�
  int maxSum1_f(vector<int> &nums, int i, int s);
  int maxSum2(vector<int> &nums);
};
class MagicReel {
private:
  /*����һ��nums���飬���п�������������0
  ÿ��������԰�nums��������һ��ȫ���0
  ÿ��ϣ������������ۼӺ;����ܴ�
  ����ʹ�ò�ʹ�á�ʹ�ö������⣬��һ��ֻ��2��ħ������
  �뷵�����龡���ܴ���ۼӺ�*/
private:
  // ��������
  int maxSum1(vector<int> &nums);
  // nums[l...r]��Χ����һ�ξ�������µ��ۼӺ�
  int maxSum1_f1(vector<int> &nums, int l, int r);

  /*1.���þ���
  2.ֻ��һ�ξ��ᣬ����С�����������ͣ�dp[i]��[0..i]λ���ϱ�����һ�ε�����µ�iλ�õ�����ۼӺ�
      a.dp[i-1]+nums[i]
      b.dp[i]�������쵽ĳ��λ�ö�ʹ�þ���*/
  int maxSum2(vector<int> &nums);
};
class maxSumOfThreeSubarrays {
private:
  /*����һ���������� nums ��һ������ k ���ҳ���������Ϊ k
  �������ص�����ȫ�����ֺͣ�3 * k ����������飬�����������������顣
  ���±��������ʽ���ؽ���������е�ÿһ��ֱ�ָʾÿ�����������ʼλ�ã��±�� 0
  ��ʼ��������ж������������ֵ�����С��һ���� ʾ�� 1�� ���룺nums =
  [1,2,1,2,6,7,5,1], k = 2 �����[0,3,5] ���ͣ������� [1, 2], [2, 6], [7, 5]
  ��Ӧ����ʼ�±�Ϊ [0, 3, 5]�� Ҳ����ȡ [2, 1], ���ǽ�� [1, 3, 5]
  ���ֵ����ϸ��� ʾ�� 2�� ���룺nums = [1,2,1,2,1,2,1,2,1], k = 2
  �����[0,2,4]
  ��ʾ��
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
  /*���Է�ת1�ε����������������ۼӺ�
  ����
  һ������nums
  ��������������ѡ����������һ�ν��з�ת��Ҳ��������������ĵ���
  ���緭ת[1,2,3,4,5,6]��[2~4]���䣬�õ�����[1,2,5,4,3,6]
  ���ر������ⷭת1�κ������������ۼӺ�*/
private:
  // �����ⷨ
  int maxSumReverse1(vector<int> &nums);
  // ��ת�������������������ۼӺ�
  int maxSumReverse1_maxSum(vector<int> &nums);

  int maxSumReverse2(vector<int> &nums);
};
class DeleteOneNumberLengthKMaxSum {
private:
  /*ɾ��1�����ֺ󳤶�Ϊk������������ۼӺ�
  ����һ������nums�������ɾ��һ�����ֺ����������
  ����Ϊk������������ۼӺͣ�ɾ���ĸ���������*/
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
  /*����һ���������� nums ���ҵ�������ϸ���������еĳ��ȡ�
  ������
  ���������������������У�ɾ������ɾ���������е�Ԫ�ض����ı�����Ԫ�ص�˳�����磬[3,6,2,7]
  ������ [0,3,1,6,2,2,7] �������С� ʾ�� 1�� ���룺nums = [10,9,2,5,3,7,101,18]
  �����4
  ���ͣ�������������� [2,3,7,101]����˳���Ϊ 4 ��
  ʾ�� 2��
  ���룺nums = [0,1,0,3,2,3]
  �����4
  ʾ�� 3��
  ���룺nums = [7,7,7,7,7,7,7]
  �����1
  ��ʾ��
  1 <= nums.length <= 2500
  -104 <= nums[i] <= 104
  ���ף�
  ���ܽ��㷨��ʱ�临�ӶȽ��͵� O(n log(n)) ��?*/
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
/*���P1048*/
class BackPackTemplate {
  int dpBackPack(int n, int m, vector<int> &cost, vector<int> &val);
  // �ռ�ѹ��
  int dpBackPack2(int n, int m, vector<int> &cost, vector<int> &val);
};
class lastStoneWeightII {
private:
  /*��һ��ʯͷ������������ stones ��ʾ������ stones[i] ��ʾ�� i ��ʯͷ��������
  ÿһ�غϣ�����ѡ����������ʯͷ��Ȼ������һ����顣����ʯͷ�������ֱ�Ϊ x ��
  y���� x <= y����ô����Ŀ��ܽ�����£� ��� x ==
  y����ô����ʯͷ���ᱻ��ȫ���飻 ��� x != y����ô����Ϊ x
  ��ʯͷ������ȫ���飬������Ϊ y ��ʯͷ������Ϊ y-x�� ������ֻ��ʣ��һ��
  ʯͷ�����ش�ʯͷ ��С�Ŀ������� �����û��ʯͷʣ�£��ͷ��� 0�� ʾ�� 1��
  ���룺stones = [2,7,4,1,8,1]
  �����1
  ���ͣ�
  ��� 2 �� 4���õ� 2����������ת��Ϊ [2,7,1,8,1]��
  ��� 7 �� 8���õ� 1����������ת��Ϊ [2,1,1,1]��
  ��� 2 �� 1���õ� 1����������ת��Ϊ [1,1,1]��
  ��� 1 �� 1���õ� 0����������ת��Ϊ [1]�����������ֵ��
  ʾ�� 2��
  ���룺stones = [31,26,33,21,40]
  �����5
  ��ʾ��
  1 <= stones.length <= 30
  1 <= stones[i] <= 100*/
private:
  int LC1049_lastStoneWeightII(vector<int> &nums);
};
class TopSum {
private:
  /*�Ǹ�����ǰk����С�����е��ۼӺ�*/
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
  /*����һ���ַ��� s ������ s �в�ͬ�ķǿջ��������и���
  �����ڴ𰸿��ܴܺ��뷵�ض� 109 + 7 ȡ�� �Ľ����
  �ַ����������п��Ծ����ַ���ɾ�� 0 �������ַ���á�
  ���һ������������ת�������һ�£���ô���ǻ������С�
  �������ĳ�� i , ���� ai != bi ������������ a1, a2, ... �� b1, b2, ... ��ͬ��
  ʾ�� 1��
  ���룺s = 'bccb'
  �����6
  ���ͣ�6 ����ͬ�ķǿջ������ַ����зֱ�Ϊ��'b', 'c', 'bb', 'cc', 'bcb',
  'bccb'�� ע�⣺'bcb' ��Ȼ�������ε�������һ�Ρ� ʾ�� 2�� ���룺s =
  'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
  �����104860361
  ���ͣ����� 3104860382 ����ͬ�ķǿջ��������У�104860361 �Ƕ� 109 + 7
  ȡ����ֵ�� ��ʾ�� 1 <= s.length <= 1000 s[i] ������ 'a', 'b', 'c' �� 'd' */
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
      /*����һ�����������ҵ��������Ķ����������ظ������Ĵ�С*/
      int LC_MaxBSTSize(TreeNode* head);
      pair<bool,vector<long long>>f(TreeNode* Node);
      pair<bool,vector<long long>>f2(TreeNode* Node);
    public:
      void Test_LC_MaxBSTSize();
  };
}