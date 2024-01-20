#include"../unltle.h"

namespace Monque{
    using std::vector;
    using std::cout;
    using std::endl;
    using std::queue;
    using std::string;
    using std::deque;
    class Ques{
    private:
        /*给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
        返回 滑动窗口中的最大值 。
        示例 1：
        输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
        输出：[3,3,5,5,6,7]
        解释：
        滑动窗口的位置                最大值
        ---------------               -----
        [1  3  -1] -3  5  3  6  7       3
        1 [3  -1  -3] 5  3  6  7       3
        1  3 [-1  -3  5] 3  6  7       5
        1  3  -1 [-3  5  3] 6  7       5
        1  3  -1  -3 [5  3  6] 7       6
        1  3  -1  -3  5 [3  6  7]      7
        示例 2：
        输入：nums = [1], k = 1
        输出：[1]
        提示：
        1 <= nums.length <= 105
        -104 <= nums[i] <= 104
        1 <= k <= nums.length*/
        vector<int> LC239_maxSlidingWindow(vector<int>& nums, int k);
    public:
        /*LeetCode 239 滑动窗口最大值*/
        void Test_LC239_maxSlidingWindow();
    private:
        /*给你一个整数数组 nums ，和一个表示限制的整数 limit，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit 。
        如果不存在满足条件的子数组，则返回 0 。
        示例 1：
        输入：nums = [8,2,4,7], limit = 4
        输出：2 
        解释：所有子数组如下：
        [8] 最大绝对差 |8-8| = 0 <= 4.
        [8,2] 最大绝对差 |8-2| = 6 > 4. 
        [8,2,4] 最大绝对差 |8-2| = 6 > 4.
        [8,2,4,7] 最大绝对差 |8-2| = 6 > 4.
        [2] 最大绝对差 |2-2| = 0 <= 4.
        [2,4] 最大绝对差 |2-4| = 2 <= 4.
        [2,4,7] 最大绝对差 |2-7| = 5 > 4.
        [4] 最大绝对差 |4-4| = 0 <= 4.
        [4,7] 最大绝对差 |4-7| = 3 <= 4.
        [7] 最大绝对差 |7-7| = 0 <= 4. 
        因此，满足题意的最长子数组的长度为 2 。
        示例 2：
        输入：nums = [10,1,2,4,7,2], limit = 5
        输出：4 
        解释：满足题意的最长子数组是 [2,4,7,2]，其最大绝对差 |2-7| = 5 <= 5 。
        示例 3：
        输入：nums = [4,2,2,2,4,4,2,2], limit = 0
        输出：3
        提示：
        1 <= nums.length <= 10^5
        1 <= nums[i] <= 10^9
        0 <= limit <= 10^9*/
        int LC1438_longestSubarray(vector<int>& nums, int limit);
        //判断窗口中的子数组是否达标
        bool LC1438_longestSubarray_Ok(deque<int>&MinQ,deque<int>&MaxQ,int limit,int num,vector<int>& nums);
        //将数组中的数进入窗口
        void LC1438_longestSubarray_Push(vector<int>& nums,deque<int>&MinQ,deque<int>&MaxQ,int r);
        //出窗口
        void LC1438_longestSubarray_Pop(deque<int>&MinQ,deque<int>&MaxQ,int l);
    public:
        /*LeetCode 1438 绝对值差不超过限制的最长连续子数组*/
        void Test_LC1438_longestSubarray();
    private:
        /*老板需要你帮忙浇花。给出 N 滴水的坐标，
        y 表示水滴的高度，x 表示它下落到 x 轴的位置。每滴水以每秒 1
        1 个单位长度的速度下落。你需要把花盆放在 
        x 轴上的某个位置，使得从被花盆接着的第 1
        1 滴水开始，到被花盆接着的最后 1
        1 滴水结束，之间的时间差至少为 D。
        我们认为，只要水滴落到 x 轴上，与花盆的边沿对齐，
        就认为被接住。给出 N 滴水的坐标和 D 的大小，请算出最小的花盆的宽度 W。*/
        int LGP2698_FallingWaterSmallestFlowerPot();
        int LGP2698_FallingWaterSmallestFlowerPot_compute(vector<vector<int>>&arr,int n,int d);
        //判断当前窗口能不能扩
        bool LGP2698_FallingWaterSmallestFlowerPot_compute_Ok(vector<vector<int>>&arr,deque<int>&MaxQ,deque<int>&MinQ,int d);
        //向窗口中插入元素
        void LGP2698_FallingWaterSmallestFlowerPot_compute_Push(vector<vector<int>>&arr,deque<int>&MaxQ,deque<int>&MinQ,int r);
        //从窗口中移除元素 
        void LGP2698_FallingWaterSmallestFlowerPot_compute_Pop(vector<vector<int>>&arr,deque<int>&MaxQ,deque<int>&MinQ,int l);
    public:
        /*洛谷P2698 接取落水的最小花盆*/
        void Test_LGP2698_FallingWaterSmallestFlowerPot();
    private:
        /*给你一个整数数组 nums 和一个整数 k ，
        找出 nums 中和至少为 k 的 最短非空子数组 ，
        并返回该子数组的长度。如果不存在这样的 子数组 ，返回 -1 。
        子数组 是数组中 连续 的一部分。
        示例 1：
        输入：nums = [1], k = 1
        输出：1
        示例 2：
        输入：nums = [1,2], k = 4
        输出：-1
        示例 3：
        输入：nums = [2,-1,2], k = 3
        输出：3
        提示：
        1 <= nums.length <= 105
        -105 <= nums[i] <= 105
        1 <= k <= 109*/
        int LC862_shortestSubarray(vector<int>& nums, int k);
    public:
        /*LeetCode 862 和至少为k的最短子数组*/
        void LC862_shortestSubarray();
    private:
        /*给你一个数组 points 和一个整数 k 。
        数组中每个元素都表示二维平面上的点的坐标，
        并按照横坐标 x 的值从小到大排序。
        也就是说 points[i] = [xi, yi] ，
        并且在 1 <= i < j <= points.length 的前提下， xi < xj 总成立。
        请你找出 yi + yj + |xi - xj| 的 最大值，
        其中 |xi - xj| <= k 且 1 <= i < j <= points.length。
        题目测试数据保证至少存在一对能够满足 |xi - xj| <= k 的点。
        示例 1：
        输入：points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
        输出：4
        解释：前两个点满足 |xi - xj| <= 1 ，
        代入方程计算，则得到值 3 + 0 + |1 - 2| = 4 。
        第三个和第四个点也满足条件，得到值 10 + -10 + |5 - 6| = 1 。
        没有其他满足条件的点，所以返回 4 和 1 中最大的那个。
        示例 2：
        输入：points = [[0,0],[3,0],[9,2]], k = 3
        输出：3
        解释：只有前两个点满足 |xi - xj| <= 3 ，
        代入方程后得到值 0 + 0 + |0 - 3| = 3 。
        提示：
        2 <= points.length <= 10^5
        points[i].length == 2
        -10^8 <= points[i][0], points[i][1] <= 10^8
        0 <= k <= 2 * 10^8
        对于所有的1 <= i < j <= points.length ，
        points[i][0] < points[j][0] 都成立。
        也就是说，xi 是严格递增的。*/
        int LC1499_findMaxValueOfEquation(vector<vector<int>>& points, int k);
    public:
        /*LeetCode 1499 满足不等式的最大值*/
        void Test_LC1499_findMaxValueOfEquation();
    private:
        /*给你 n 个任务和 m 个工人。每个任务需要一定的力量值才能完成，
        需要的力量值保存在下标从 0 开始的整数数组 tasks 中，
        第 i 个任务需要 tasks[i] 的力量才能完成。
        每个工人的力量值保存在下标从 0 开始的整数数组 workers 中，
        第 j 个工人的力量值为 workers[j] 。
        每个工人只能完成 一个 任务，且力量值需要 
        大于等于 该任务的力量要求值（即 workers[j] >= tasks[i] ）。
        除此以外，你还有 pills 个神奇药丸，可以给 一个工人的力量值 增加 strength 。
        你可以决定给哪些工人使用药丸，但每个工人 最多 只能使用 一片 药丸。
        给你下标从 0 开始的整数数组tasks 和 workers 
        以及两个整数 pills 和 strength ，请你返回 最多 有多少个任务可以被完成。
        示例 1：
        输入：tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
        输出：3
        解释：
        我们可以按照如下方案安排药丸：
        - 给 0 号工人药丸。
        - 0 号工人完成任务 2（0 + 1 >= 1）
        - 1 号工人完成任务 1（3 >= 2）
        - 2 号工人完成任务 0（3 >= 3）
        示例 2：
        输入：tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
        输出：1
        解释：
        我们可以按照如下方案安排药丸：
        - 给 0 号工人药丸。
        - 0 号工人完成任务 0（0 + 5 >= 5）
        示例 3:
        输入：tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
        输出：2
        解释：
        我们可以按照如下方案安排药丸：
        - 给 0 号和 1 号工人药丸。
        - 0 号工人完成任务 0（0 + 10 >= 10）
        - 1 号工人完成任务 1（10 + 10 >= 15）
        示例 4：
        输入：tasks = [5,9,8,5,9], workers = [1,6,4,2,6], pills = 1, strength = 5
        输出：3
        解释：
        我们可以按照如下方案安排药丸：
        - 给 2 号工人药丸。
        - 1 号工人完成任务 0（6 >= 5）
        - 2 号工人完成任务 2（4 + 5 >= 8）
        - 4 号工人完成任务 3（6 >= 5）
        提示：
        n == tasks.length
        m == workers.length
        1 <= n, m <= 5 * 10^4
        0 <= pills <= m
        0 <= tasks[i], workers[j], strength <= 10^9*/
        int LC2071_maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength);
        bool LC2071_maxTaskAssign_f(vector<int>& tasks, vector<int>& workers, int tl,int tr,int wl,int wr,int s,int pills);
        public:
        /*LeetCode 2071 你可以安排的最多任务数目*/
        void Test_LC2071_maxTaskAssign();
    };
}
