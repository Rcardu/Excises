#include"../unltle.h"

namespace Simple{
    using std::vector;
    using std::cout;
    using std::endl;
    using ll=int64_t;
    class DoubleSi{
    private:
        /*给定一个非负整数数组 nums，  
        nums 中一半整数是 奇数 ，一半整数是 偶数 。
        对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；
        当 nums[i] 为偶数时， i 也是 偶数 。
        你可以返回 任何满足上述条件的数组作为答案 */
        vector<int> LC922_sortArrayByParityII(vector<int>& nums);
        //交换数组中的两个数的位置
        void Swap(vector<int>&nums,int i,int j);
    public:
        /*LeetCoed 922 奇偶数排序*/
        void Test_LC922_sortArrayByParityII();
    private:
        int LC287_findDuplicate(vector<int>& nums);
    public:
        /*LeetCode 287 寻找重复数*/
        void Test_LC287_findDuplicate();
    private:
        /*给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
        计算按此排列的柱子，下雨之后能接多少雨水
        输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
        输出：6
        解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，
        在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。*/
        int LC42_trap(vector<int>& height);
        /*双指针解法*/
        int LC42_trap_doublePoint(vector<int>& height);
    public:
        /*LeetCode 42 接雨水*/
        void Test_LC42_trap();
    private:
        /*给定数组 people 。people[i]表示第 i 个人的体重 ，
        船的数量不限，每艘船可以承载的最大重量为 limit。
        每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。
        返回 承载所有人所需的最小船数 。
        示例 1：
        输入：people = [1,2], limit = 3
        输出：1
        解释：1 艘船载 (1, 2)
        示例 2：
        输入：people = [3,2,2,1], limit = 3
        输出：3
        解释：3 艘船分别载 (1, 2), (2) 和 (3)
        示例 3：
        输入：people = [3,5,3,4], limit = 5
        输出：4
        解释：4 艘船分别载 (3), (3), (4), (5)*/
        int LC881_numRescueBoats(vector<int>& people, int limit);
    public:
        /*LeetCode 881 救生艇*/
        void Test_LC881_numRescueBoats();
    private:
        /*给定一个长度为 n 的整数数组 height 。有 n 条垂线，
        第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
        找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
        返回容器可以储存的最大水量。
        说明：你不能倾斜容器。
        输入：[1,8,6,2,5,4,8,3,7]
        输出：49 
        解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，
        容器能够容纳水（表示为蓝色部分）的最大值为 49。
        示例 2：
        输入：height = [1,1]
        输出：1*/
        int LC11_maxArea(vector<int>& height);
    public:
        /*LeetCoed 11 盛水最多的容器*/
        void Test_LC11_maxArea();
    private:
        /*冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
        在加热器的加热半径范围内的每个房屋都可以获得供暖。
        现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，
        请你找出并返回可以覆盖所有房屋的最小加热半径。
        说明：所有供暖器都遵循你的半径标准，加热的半径也一样。
        示例 1:
        输入: houses = [1,2,3], heaters = [2]
        输出: 1
        解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，
        那么所有房屋就都能得到供暖。
        示例 2:
        输入: houses = [1,2,3,4], heaters = [1,4]
        输出: 1
        解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，
        这样所有房屋就都能得到供暖。
        示例 3：
        输入：houses = [1,5], heaters = [2]
        输出：3
        提示：
        1 <= houses.length, heaters.length <= 3 * 104
        1 <= houses[i], heaters[i] <= 109*/
        int LC475_findRadius(vector<int>& houses, vector<int>& heaters);
        //当前地点hourse[i]由heaters[j]供暖是否是最优的
        bool LC475_bast(vector<int>&house,vector<int>&heaters,int i,int j);
    public:
        /*LeetCode 475 供暖器*/
        void Test_LC475_findRadius();
    private:
        /*给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
        请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
        示例 1：
        输入：nums = [1,2,0]
        输出：3
        示例 2：
        输入：nums = [3,4,-1,1]
        输出：2
        示例 3：
        输入：nums = [7,8,9,11,12]
        输出：1*/
        int LC41_firstMissingPositive(vector<int>& nums);
    public:
        /*LeetCode 41 缺失的第一个正数*/
        void Test_LC41_firstMissingPositive();
    };
    class DichotomyMethod{
    private:
        /*珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。
        警卫已经离开了，将在 h 小时后回来。
        珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。
        每个小时，她将会选择一堆香蕉，从中吃掉 k 根。
        如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，
        然后这一小时内不会再吃更多的香蕉。  
        珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
        返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。
        示例 1：
        输入：piles = [3,6,7,11], h = 8
        输出：4
        示例 2：
        输入：piles = [30,11,23,4,20], h = 5
        输出：30
        示例 3：
        输入：piles = [30,11,23,4,20], h = 6
        输出：23
        提示：
        1 <= piles.length <= 104
        piles.length <= h <= 109
        1 <= piles[i] <= 10^9*/    
        int LC875_minEatingSpeed(vector<int>& piles, int h);
        bool LC875_CatEatInTime(vector<int>&piles,int h,int seed);
    public:
        /*LeetCode 875 爱吃香蕉的珂珂*/
        void Test_LC875_minEatingSpeed();
    private:    
        /*给定一个非负整数数组 nums 和一个整数 m ，
        你需要将这个数组分成 m 个非空的连续子数组。
        设计一个算法使得这 m 个子数组各自和的最大值最小。
        示例 1：
        输入：nums = [7,2,5,10,8], m = 2
        输出：18
        解释：
        一共有四种方法将 nums 分割为 2 个子数组。 
        其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
        因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
        示例 2：
        输入：nums = [1,2,3,4,5], m = 2
        输出：9
        示例 3：
        输入：nums = [1,4,4], m = 3
        输出：4
        提示：
        1 <= nums.length <= 1000
        0 <= nums[i] <= 10^6
        1 <= m <= min(50, nums.length)*/
        int LC410_splitArray(vector<int>& nums, int k);
        //将nums平均分配为<=k个使其每一部分的值都小于等于m
        int LC410_splitArray_f(vector<int>&nums,int m);
    public:
        /*LeetCode 410 分割数组的最大值*/
        void Test_LC410_splitArray();
    private:
        /*有一个机器人，没经过一个能量大于它的台阶，他就会用自己的能量
        减去它与这个台阶的差值(sum=sum-abs(sum-nums[i])),
        如果经过的是一个能量小于它的台阶，它就会加上它与此台阶的差值
        (sum=sum+abs(sum-nums[i])),求这个机器人初始能量为多少时，恰好通过*/
        void RobotPassThroughBuilding();
        int compute(vector<int>&nums,int l,int r,int max);
        bool compute_f(vector<int>&nums,int m,int max);
    public:
        /*机器人的通关游戏*/
        void Test_RobotPassThroughBuilding();
    private:
        /*数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。
        给你一个整数数组 nums 和一个整数 k ，数对由 nums[i]和nums[j]
        组成且满足 0 <= i < j < nums.length.
        返回所有数对距离中第k小的数对距离。
        示例 1：
        输入：nums = [1,3,1], k = 1
        输出：0
        解释：数对和对应的距离如下：
        (1,3) -> 2
        (1,1) -> 0
        (3,1) -> 2
        距离第 1 小的数对是 (1,1) ，距离为 0 。
        示例 2：
        输入：nums = [1,1,1], k = 2
        输出：0
        示例 3：
        输入：nums = [1,6,1], k = 3
        输出：5*/
        int LC719_smallestDistancePair(vector<int>& nums, int k);
        int LC719_smallestDistancePair_f(vector<int>& nums, int limit);
    public:
        /*LeetCode 719 找出第k小的数对距离*/
        void Test_LC719_smallestDistancePair();
    private:
        /*你有 n 台电脑。给你整数 n 和一个下标从 0 开始的整数数组 batteries ，
        其中第 i 个电池可以让一台电脑 运行 batteries[i] 分钟。
        你想使用这些电池让 全部 n 台电脑 同时 运行。
        一开始，你可以给每台电脑连接 至多一个电池 。然后在任意整数时刻，
        你都可以将一台电脑与它的电池断开连接，并连接另一个电池，
        你可以进行这个操作 任意次 。新连接的电池可以是一个全新的电池，
        也可以是别的电脑用过的电池。断开连接和连接新的电池不会花费任何时间。
        注意，你不能给电池充电。
        请你返回你可以让 n 台电脑同时运行的 最长 分钟数。
        输入：n = 2, batteries = [1,1,1,1]
        输出：2
        解释：
        一开始，将第一台电脑与电池 0 连接，第二台电脑与电池 2 连接。
        一分钟后，电池 0 和电池 2 同时耗尽，所以你需要将它们断开连接，
        并将电池 1 和第一台电脑连接，电池 3 和第二台电脑连接。
        1 分钟后，电池 1 和电池 3 也耗尽了，所以两台电脑都无法继续运行。
        我们最多能让两台电脑同时运行 2 分钟，所以我们返回 2 。
        提示：
        1 <= n <= batteries.length <= 10^5
        1 <= batteries[i] <= 10^9*/
        ll LC2141_maxRunTime(int n, vector<int>& batteries);
        //用来判断在n台电脑下同时运行limit时间，能不能
        bool LC2141_maxRunTime_f1(vector<int>&nums,int n,long limit);
    public:
        /*LeetCode 2141 同时运行N台电脑的最长时间*/
        void Test_LC2141_maxRunTime();
    private:
        /*计算等位时间
        给定一个数组arr长度为n，表示n个服务员，每服务一个人的时间
        给定一个正整数m，表示有m个人等位，如果你是刚来的人，请问你需要等多久
        假设m远远大于n，比如n<=10^3，m<=10^9，该怎么做是最优解O(m*log(n))*/
        int WaitingTime1(vector<int>arr,int m);
        /*使用二分答案法O(n*log(min*m))*/
        int WaitingTime2(vector<int>arr,int m);
        /*所有人都工作m个小时，能给多少个人提供服务*/
        int WaitingTime2_f(vector<int>arr,int m);
    public:
        /*服务员服务到你的时间*/
        void Test_WaitingTime();
    private:
        /*怪兽的初始血量是一个整数hp，给出每一回合和毒杀的数值cuts和poisons
        第i回合如果用刀砍，怪兽在这回合会损失cuts[i]的血，不再有后续效果
        第i回合如果用毒杀，怪兽在这回合不会损失血量，但是之后的每回合都会损失poisons[i]
        的血量，并且你选择的所有毒杀效果，在之后的回合都会叠加，
        两个数组cuts、poisons，长度都是n，代表你一共可以进行n回合
        每一回合你只能选择刀砍或者毒杀中的一个动作
        如果你在n个回合内没有直接杀死怪物，意味着你已经无法有新的行动了
        但是怪兽如果有中毒效果的话，那么怪兽依然会不停的扣血，直到血量耗尽
        的那回合死掉返回至少多少回合怪兽会死掉
        1<=n<=10^5;  1<=hp<=10^9;    1<=cuts[i]、poisons[i]<=10^9;*/
        int SlashingPoisoning(vector<int>&cuts,vector<int>&poisons,int hp);
        /*三维动态规划，对数器*/
        int SlashingPoisoning1(vector<int>&cuts,vector<int>&poisons,int hp);
        /*在times回合内使用刀砍或者毒杀能不能打死怪物*/
        bool SlashingPoisoning_f(vector<int>&cuts,vector<int>&poisons,long hp,int times);
        /*动态规划子函数*/
        int SlashingPoisoning_f1(vector<int>&cuts,vector<int>&poisons,int i,int r,int p,vector<vector<vector<int>>>dp);
    public:
        /*刀砍毒杀怪物问题*/
        void Test_SlashingPoisoning();
    private:
        /*给你一个整数数组 ranks ，表示一些机械工的 能力值 。
        ranksi 是第 i 位机械工的能力值。
        能力值为 r 的机械工可以在 r * n2 分钟内修好 n 辆车。
        同时给你一个整数 cars ，表示总共需要修理的汽车数目。
        请你返回修理所有汽车 最少 需要多少时间。
        注意：所有机械工可以同时修理汽车。
        示例 1：
        输入：ranks = [4,2,3,1], cars = 10
        输出：16
        解释：
        - 第一位机械工修 2 辆车，需要 4 * 2 * 2 = 16 分钟。
        - 第二位机械工修 2 辆车，需要 2 * 2 * 2 = 8 分钟。
        - 第三位机械工修 2 辆车，需要 3 * 2 * 2 = 12 分钟。
        - 第四位机械工修 4 辆车，需要 1 * 4 * 4 = 16 分钟。
        16 分钟是修理完所有车需要的最少时间。
        示例 2：
        输入：ranks = [5,1,8], cars = 6
        输出：16
        解释：
        - 第一位机械工修 1 辆车，需要 5 * 1 * 1 = 5 分钟。
        - 第二位机械工修 4 辆车，需要 1 * 4 * 4 = 16 分钟。
        - 第三位机械工修 1 辆车，需要 8 * 1 * 1 = 8 分钟。
        16 分钟时修理完所有车需要的最少时间。
        提示：
        1 <= ranks.length <= 105
        1 <= ranks[i] <= 100
        1 <= cars <= 106*/
        long long LC2594_repairCars(vector<int>& ranks, int cars);
        bool LC2594_repairCars_f(vector<int>&ranks,int cars,int time);
    public:
        void Tset_LC2594_repairCars();
    };
}