#include"../unltle.h"
namespace Difference{
using std::vector;
using std::cout;
static int MAXN=100005;
vector<int>arr(MAXN,0);
    class Arithmetic{
        //一维差分
    private:
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
        vector<int>LC1109_corpFlightBookings_(vector<vector<int>>&bookings,int n);
    public:
        /*LeetCode 1109 航班预定统计*/
        void Test_LC1109_corpFlightBookings();
    private:
        /*洛谷 P4231
        N个柱子排成一排，一开始每个柱子损伤度为0。
        接下来勇仪会进行
        M次攻击，每次攻击可以用4个参数l,r,s,e来描述：
        表示这次攻击作用范围为第l个到第r个之间所有的柱子(包含l,r)，
        对第一个柱子的伤害为s，对最后一个柱子的伤害为e。
        攻击产生的伤害值是一个等差数列。若l=1,r=5,s=2,e=10，
        则对第1~5个柱子分别产生2,4,6,8,10的伤害。
        鬼族们需要的是所有攻击完成之后每个柱子的损伤度。*/
        void LGP4231_build(int n);
        void LGP4231_set(int l,int r,int s,int e,int d);
    private:
        int n,m;
    public:
        /*洛谷 P4231*/
        void LGP4231_ArithmeticSeqenceDifference();
    };

}
namespace Lycanthropy{
    using std::vector;
    using std::cout;
    using std::endl;
    using std::sort;
    static int OFFSET=30001;
    static int MAXN=1000006;
    vector<int>arr(MAXN+2*OFFSET,0);
    int n,m;

    class LycanthropyInBack{
    private:
       /*洛谷 P5026 Lycanthropy*/
       void LGP5026_set(int l,int r,int s,int e,int d);
       void LGP5026_fall(int v,int x);
       void LGP5026_build(int m);
    public:
        /*洛谷 P5026 Lycanthropy*/
        void Test_LGP5026_Lycanthropy();
        //n有多少个人落水，每个人落水就意味着四个数列的操作
    private:
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
        bool LC2132_possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth);
        //建立前缀和
        void LC2132_Build(vector<vector<int>>&sum);
        //前缀和查询
        int LC2132_sumRegion(vector<vector<int>>sum,int a,int b,int c,int d);
        //在(a,b)到(c,d)范围内进行差分操作
        void LC2132_Add(vector<vector<int>>&diff,int a,int b,int c,int d);
    public:
        /*LeetCode 2132 贴邮票*/
        void Test_LC2132_possibleToStamp();
    private:
        /*小扣在探索丛林的过程中，无意间发现了传说中“落寞的黄金之都”。
        而在这片建筑废墟的地带中，小扣使用探测仪监测到了存在某种带有
        「祝福」效果的力场。 经过不断的勘测记录，
        小扣将所有力场的分布都记录了下来。
        forceField[i] = [x,y,side]表示第 i 片力场将覆盖以坐标 (x,y) 为中心，
        边长为 side 的正方形区域。
        若任意一点的力场强度等于覆盖该点的力场数量，
        请求出在这片地带中 力场强度 最强处的 力场强度。*/
        int LCP74_fieldOfGreatestBlessing(vector<vector<int>>& forceField);
        //差分
        void LCP74_Add(vector<vector<int>>&diff,int a,int b,int c,int d);
        //二分查询一个数的索引
        int LCP74_Rank(vector<long>&nums,long v,int size);
        //排序数组并返回去重后的长度
        int LCP74_Sort(vector<long>&nums);
    public:
        /*LeetCode LCP 74 最强祝福立场*/
        void Test_LCP74_fieldOfGreatestBlessing();
    };
    class NumMatrix{
        //二维前缀和
        /*给定一个二维矩阵 matrix，以下类型的多个请求：
        计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，
        右下角 为 (row2, col2) 。
        实现 NumMatrix 类：
        NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
        int sumRegion(int row1, int col1, int row2, int col2) 
        返回左上角(row1, col1)、右下角 (row2, col2)所描述的子矩阵的元素总和*/
        private:
            vector<vector<int>>sum;
            int n,m;
        public:
            NumMatrix(){;}
            NumMatrix(vector<vector<int>>&martix);
            int sumRegion(int row1,int col1,int row2,int col2);
        public:
            /*LeetCode 304 二维区域和检索*/
            void Test_LC304_NumMatrix();
        private:
            /*给你一个由若干 0 和 1 组成的二维网格 grid，
            请你找出边界全部由 1 组成的最大 正方形 子网格，
            并返回该子网格中的元素数量。如果不存在，则返回 0。*/
            int LC1139_largest1BorderedSquare(vector<vector<int>>& grid);
            /*重构差分数组*/
            void LC1139_Build(vector<vector<int>>&martix,int n,int m);
            /*边界判断*/
            int LC1139_Get(vector<vector<int>>&martix,int i,int j);
            /*求范围内的和*/
            int LC1139_Sum(vector<vector<int>>&martix,int a,int b,int c,int d);
        public:
            /*LeetCode 1139 最大的以1为边界的正方形*/
            void Test_LC1139_largest1BorderedSquare();
    };
}
namespace LGP3397{
    using std::vector;
    using std::cout;
    using std::cin;
    using std::endl;
    int n,m;
    void LG_Set(vector<vector<int>>&grid,int a,int b,int c,int d){
        grid[a][b]+=1;
        grid[a][d+1]-=1;
        grid[c+1][b]-=1;
        grid[c+1][d+1]+=1;
    }
    void LG_Add(vector<vector<int>>&grid,int n,int m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
            }
        }
    }
    /*洛谷 3397 地毯*/
    void LGP3397(){
        cin>>n;cin>>m;
        vector<vector<int>>grid(n+2,vector<int>(n+2,0));
        while(m--){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            LG_Set(grid,a,b,c,d);
        }
        LG_Add(grid,n,n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}