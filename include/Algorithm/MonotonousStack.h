#include"../unltle.h"
namespace Monotonous{
    using std::vector;
    using std::cout;
    using std::endl;
    using std::string;
    class MonStack{
    private:    
        /*寻找数组中每个数左边和右边第1个比自己小的数，没有就是-1*/
        vector<vector<int>>ANumbeSmallerThanYourself(vector<int>&nums);
        /*寻找当前数的左边第一个比自己小的数*/
        int ANumbeSmallerThanYourself_left(vector<int>&nums,int i);
        /*寻找当前数的右边第一个比自己小的数*/
        int ANumbeSmallerThanYourself_right(vector<int>&nums,int i);
        /*单调栈解法*/
        vector<vector<int>>ANumbeSmallerThanYourself_stack(vector<int>&nums);
    public:
        /*寻找数组中每个数左边和右边第1个比自己小的数，没有就是-1*/
        void Test_ANumbeSmallerThanYourself();
    private:
        /*请根据每日 气温 列表 temperatures ，
        重新生成一个列表，要求其对应位置的输出为：
        要想观测到更高的气温，至少需要等待的天数。
        如果气温在这之后都不会升高，请在该位置用 0 来代替。
        示例 1:
        输入: temperatures = [73,74,75,71,69,72,76,73]
        输出: [1,1,4,2,1,1,0,0]
        示例 2:
        输入: temperatures = [30,40,50,60]
        输出: [1,1,1,0]
        示例 3:
        输入: temperatures = [30,60,90]
        输出: [1,1,0]
        1 <= temperatures.length <= 10^5
        30 <= temperatures[i] <= 100*/
        vector<int> LC739_dailyTemperatures(vector<int>& temperatures);
    public:
        /*LeetCode 739 每日温度*/
        void Test_LC739_dailyTemperatures();
    private:
        /*给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。
        由于答案可能很大，因此 返回答案模 10^9 + 7 。
        示例 1：
        输入：arr = [3,1,2,4]
        输出：17
        解释：
        子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。 
        最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。
        示例 2：
        输入：arr = [11,81,94,43,3]
        输出：444
        提示：
        1 <= arr.length <= 3 * 10^4
        1 <= arr[i] <= 3 * 10^4*/
        const int MOD=1000000007;
        int LC907_sumSubarrayMins(vector<int>& arr);
    public:
        /*LeetCode 907 子数组的最小值之和*/
        void Test_LC907_sumSubarrayMins();
    private:
        /*给定 n 个非负整数，用来表示柱状图中各个柱子的高度。
        每个柱子彼此相邻，且宽度为 1 。
        求在该柱状图中，能够勾勒出来的矩形的最大面积。
        示例 1:
        输入：heights = [2,1,5,6,2,3]
        输出：10
        解释：最大的矩形为图中红色区域，面积为 10
        示例 2：
        输入： heights = [2,4]
        输出： 4*/
        int LC74_largestRectangleArea(vector<int>& heights);
    public:
        /*LeetCode 84 柱状图中最大的矩形*/
        void Test_LC74_largestRectangleArea();
    private:
        /*给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，
        找出只包含 1 的最大矩形，并返回其面积。
        示例 1：
        输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
        输出：6
        解释：最大矩形如上图所示。
        示例 2：
        输入：matrix = []
        输出：0
        示例 3：
        输入：matrix = [["0"]]
        输出：0
        示例 4：
        输入：matrix = [["1"]]
        输出：1
        示例 5：
        输入：matrix = [["0","0"]]
        输出：0*/
        int LC85_maximalRectangle(vector<vector<int>>& matrix);
        int LC85_maximalRectangle_f(vector<int>arr);
    public:
        /*LeetCode 85 最大矩形*/
        void Test_LC85_maximalRectangle();
    private:
        /*给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]。这样的坡的宽度为 j - i。
        找出 A 中的坡的最大宽度，如果不存在，返回 0 。
        示例 1：
        输入：[6,0,8,2,1,5]
        输出：4
        解释：
        最大宽度的坡为 (i, j) = (1, 5): A[1] = 0 且 A[5] = 5.
        示例 2：
        输入：[9,8,1,0,1,9,4,0,4,1]
        输出：7
        解释：
        最大宽度的坡为 (i, j) = (2, 9): A[2] = 1 且 A[9] = 1.
        提示：
        2 <= A.length <= 50000
        0 <= A[i] <= 50000*/
        int LC962_maxWidthRamp(vector<int>& nums);
    public:
        /*LeetCode 962 最大坡宽度*/
        void Test_LC962_maxWidthRamp();
    private:
        /*给你一个字符串 s ，请你去除字符串中重复的字母，
        使得每个字母只出现一次。需保证 返回结果的字典序最小
        （要求不能打乱其他字符的相对位置）。
        示例 1：
        输入：s = "bcabc"
        输出："abc"
        示例 2：
        输入：s = "cbacdcbc"
        输出："acdb"
        提示：
        1 <= s.length <= 10^4
        s 由小写英文字母组成*/
        string LC316_removeDuplicateLetters(string s);
    public:
        /*LeetCode 316 去除重复字母*/
        void Test_LC316_removeDuplicateLetters();
    private:
        /*给定一个数组arr，每个值代表鱼的体重每一轮，
        每条鱼都会吃掉右边离自己最近比自己体重小的鱼，每条鱼向右找吃一只
        但是吃鱼这件事情是同时发生的，也就是同一轮在A吃掉B的同时，A也可能被别的鱼吃掉
        如果有多条鱼在当前轮找到的是同一条鱼，那么在这一轮，这条小鱼同时被这些大鱼吃
        请问多少轮后，鱼的数量固定了
        比如：8,3,1,5,6,7,2,4
        第一轮：8吃3；3吃1；5、6、7吃2；4没有被吃，数组剩下8,5,6,7,4
        第二轮：8吃5；5、6、7吃4.数组剩下8,6,7
        第三轮：8吃6；数组剩下7
        第四轮：8吃7.数组剩下8.
        过程结束，返回4
        例如：8,3,7,3,4,5,6*/
        void BigFishEatSmallFish();
        /*单调栈，逆向遍历，结算每一个数据*/
        int BigFishEatSmallFish_turns(vector<int>arr);
    public:
        /*大鱼吃小鱼问题*/
        void Test_BigFishEatSmallFish();
    private:
        /*给你一个 m x n 的二进制矩阵 mat ，请你返回有多少个 子矩形 的元素全部都是 1 。
        示例 1：
        输入：mat = [[1,0,1],[1,1,0],[1,1,0]]
        输出：13
        解释：
        有 6 个 1x1 的矩形。
        有 2 个 1x2 的矩形。
        有 3 个 2x1 的矩形。
        有 1 个 2x2 的矩形。
        有 1 个 3x1 的矩形。
        矩形数目总共 = 6 + 2 + 3 + 1 + 1 = 13 。
        示例 2：
        输入：mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
        输出：24
        解释：
        有 8 个 1x1 的子矩形。
        有 5 个 1x2 的子矩形。
        有 2 个 1x3 的子矩形。
        有 4 个 2x1 的子矩形。
        有 2 个 2x2 的子矩形。
        有 2 个 3x1 的子矩形。
        有 1 个 3x2 的子矩形。
        矩形数目总共 = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24 。
        提示：
        1 <= m, n <= 150
        mat[i][j] 仅包含 0 或 1*/
        int LC1504_numSubmat(vector<vector<int>>& mat);
        int LC1504_numSubmat_f(vector<int>arr);
    public:
        /*LeetCode 1504 统计全1子矩阵*/
        void Test_LC1504_numSubmat();
        
    };
}
