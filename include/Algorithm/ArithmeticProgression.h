#include "../unltle.h"

namespace Ricardo {

/*LeetCode 1109 航班预定统计*/
/*这里有 n 个航班，它们分别从 1 到 n 进行编号。
       有一份航班预订表 bookings ，表中第 i 条预订记录
       bookings[i] = [firsti, lasti, seatsi] 意味着在从 firsti 到 lasti
       （包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。
       请你返回一个长度为 n 的数组 answer，里面的元素是每个航班预定的座位总数。
       示例 1：
       输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
       输出：[10,55,45,25,25]
       解释：
       航班编号        1   2   3   4   5
       预订记录 1 ：   10  10
       预订记录 2 ：       20  20
       预订记录 3 ：       25  25  25  25
       总座位数：      10  55  45  25  25
       因此，answer = [10,55,45,25,25]
       示例 2：
       输入：bookings = [[1,2,10],[2,2,15]], n = 2
       输出：[10,25]
       解释：
       航班编号        1   2
       预订记录 1 ：   10  10
       预订记录 2 ：       15
       总座位数：      10  25
       因此，answer = [10,25]*/
class Arithmetic {
 public:
  Arithmetic(std::vector<std::vector<int>> bookings = {
                 {1, 2, 10}, {2, 3, 20}, {2, 5, 25}});

 private:
  std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings,
                                      int n);

 private:
  int MAXN = 100005;
  std::vector<int> arr;
};
/*洛谷 P4231
N个柱子排成一排，一开始每个柱子损伤度为0。
接下来勇仪会进行
M次攻击，每次攻击可以用4个参数l,r,s,e来描述：
表示这次攻击作用范围为第l个到第r个之间所有的柱子(包含l,r)，
对第一个柱子的伤害为s，对最后一个柱子的伤害为e。
攻击产生的伤害值是一个等差数列。若l=1,r=5,s=2,e=10，
则对第1~5个柱子分别产生2,4,6,8,10的伤害。
鬼族们需要的是所有攻击完成之后每个柱子的损伤度。*/
class Seqence {
 public:
  Seqence();

 private:
  void build(int n);
  void setOut(int l, int r, int s, int e, int d);

 private:
  int n = 0;
  int m = 0;
  int MAXN = 100005;
  std::vector<int> arr;
};

/*洛谷 P5026 Lycanthropy*/
// n有多少个人落水，每个人落水就意味着四个数列的操作
class LycanthropyInBack {
 public:
  LycanthropyInBack();

 private:
  void setOut(int l, int r, int s, int e, int d);
  void fall(int v, int x);
  void build(int m);

 private:
  int OFFSET = 30001;
  int MAXN = 1000006;
  std::vector<int> arr;
  int n, m;
};

/*给你一个 m x n 的二进制矩阵 grid ，
每个格子要么为 0 （空）要么为 1 （被占据）。
给你邮票的尺寸为 stampHeight x stampWidth 。
我们想将邮票贴进二进制矩阵中，且满足以下 限制 和 要求 ：
覆盖所有 空 格子。
不覆盖任何 被占据 的格子。
我们可以放入任意数目的邮票。
邮票可以相互有 重叠 部分。
邮票不允许 旋转 。
邮票必须完全在矩阵 内 。
如果在满足上述要求的前提下，可以放入邮票，请返回 true ，
否则返回 false 。*/
class PossibleStamp {
 public:
  PossibleStamp(std::vector<std::vector<int>> grid = {
                    {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});

 private:
  bool possibleToStamp(std::vector<std::vector<int>>& grid, int stampHeight,
                       int stampWidth);
  // 建立前缀和
  void Build(std::vector<std::vector<int>>& sum);
  // 前缀和查询
  int sumRegion(std::vector<std::vector<int>> sum, int a, int b, int c, int d);
  // 在(a,b)到(c,d)范围内进行差分操作
  void Add(std::vector<std::vector<int>>& diff, int a, int b, int c, int d);
};

/*LeetCode LCP 74 最强祝福立场*/
/*小扣在探索丛林的过程中，无意间发现了传说中“落寞的黄金之都”。
而在这片建筑废墟的地带中，小扣使用探测仪监测到了存在某种带有
「祝福」效果的力场。 经过不断的勘测记录，
小扣将所有力场的分布都记录了下来。
forceField[i] = [x,y,side]表示第 i 片力场将覆盖以坐标 (x,y) 为中心，
边长为 side 的正方形区域。
若任意一点的力场强度等于覆盖该点的力场数量，
请求出在这片地带中 力场强度 最强处的 力场强度。*/
class FieldOfGreatestBlessing {
 public:
  FieldOfGreatestBlessing(std::vector<std::vector<int>> grid = {
                              {4, 7, 6}, {7, 5, 3}, {1, 6, 2}, {4, 6, 3}});

 private:
  int fieldOfGreatestBlessing(std::vector<std::vector<int>>& forceField);
  void Add(std::vector<std::vector<int>>& diff, int a, int b, int c, int d);
  int Rank(std::vector<long>& nums, long v, int size);
  int Sort(std::vector<long>& nums);
};
/*LeetCode 304 二维区域和检索*/
class NumMatrix {
 public:
  NumMatrix(std::vector<std::vector<int>> martix);

 private:
  int sumRegion(int row1, int col1, int row2, int col2);

 private:
  std::vector<std::vector<int>> sum;
  int n, m;
};

/*给你一个由若干 0 和 1 组成的二维网格 grid，
请你找出边界全部由 1 组成的最大 正方形 子网格，
并返回该子网格中的元素数量。如果不存在，则返回 0。*/
class LargestBorderedSquare {
 public:
  /*LeetCode 1139 最大的以1为边界的正方形*/
  LargestBorderedSquare(std::vector<std::vector<int>> grid = {
                            {1, 1, 1}, {1, 0, 1}, {1, 1, 1}});

 private:
  int largestBorderedSquare(std::vector<std::vector<int>>& grid);
  /*重构差分数组*/
  void Build(std::vector<std::vector<int>>& martix, int n, int m);
  /*边界判断*/
  int Get(std::vector<std::vector<int>>& martix, int i, int j);
  /*求范围内的和*/
  int Sum(std::vector<std::vector<int>>& martix, int a, int b, int c, int d);

 private:
  std::vector<std::vector<int>> sum;
  int n, m;
};

/*洛谷 3397 地毯*/
class LGP3397 {
 public:
  LGP3397();

 private:
  void LG_Set(std::vector<std::vector<int>>& grid, int a, int b, int c, int d);
  void LG_Add(std::vector<std::vector<int>>& grid, int n, int m);

 private:
  int n, m;
};

}  // namespace Ricardo
