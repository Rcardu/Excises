此文件有图的三种创建方式
Graph类中
1）邻接矩阵
2）邻接表
3）链式前向星

Topological 类中
包含LeetCode 210 课程表II

LG_Topological类中
洛谷的拓扑排序模板

alienOrder类中
以及LCR 114 火星词典的拓扑排序
包含LeetCode 936 戳印序列

namespace FoodLine中
使用拓扑排序传递信息的食物链

loudAndRich类中
包含LeetCode 851 喧闹和富有

mumTime类中
包含LeetCode 2050 并行课程

Invitations类中
包含LeetCode 2127 参加会议最多的员工

Kruskal类中的最小生成树算法使用并查集来进行环的检测，将边排序后进行筛选选择
a[2]>b[2]表示数值小的优先级大,在上面
auto cmp=[](vector<int>a,vector<int>b)->bool{return a[2]>b[2];};
cmp是一个lamba表达式，返回一个bool值，表示数值大的优先级大排在队尾
priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);

decltype()：因为priority_queue的第三个参数是函数指针（需要的是类型名，而cmp是一个对象），所以需要使用decltype()来获取函数指针的类型（即转化为类型）

因为lambda这种特殊的class没有默认构造函数，pq内部排序比较的时候要使用的是一个实例化的lambda对象，只能通过lambda的 copy构造进行实例化，从哪里copy呢，就需要pq构造函数的时候传入这个lambda对象。pq的自定义比较也可以使用struct或者class，因为struct和class都有默认构造函数，此时就不需要pq(Type)而是直接pq即可。同理，自定义比较也可以使用函数，同样此时也需要提供函数对象进行实例化pq(CmpFunc)，假设比较函数为bool CmpFunc(int x, int y) {return x < y;}

Prim类中表示了对于图的最小生成树算法，使用小根堆来进行最小生成树的构造
PrimPlus类是Prim算法的进一步优化使用反向索引表来记录当前结点在堆中的索引，用来修改堆中的结点的权值，保证堆中的大小与结点数量有关

OptimizationOfWaterAllocation类是LeetCode 1168 水资源优化解题过程，使用图与并查集

distanceLimitedPathsExist类LeetCode 1697 检查长度限制的路径是否存在

宽度优先遍历部分
MaxDistance LeetCode 1162 地图分析

MinStickers类LeetCode 691 贴纸拼词

MinCost类LeetCode 1368 使网格至少有一条有效路径

trapRainWater类LeetCode 407 接雨水II

FindLadders类LeetCode 126 单词接龙

SnacksWayBuyTickets类LG P4799 世界冰球锦标赛，双向广搜，通过半量样本的展开

MinAbsDifference类LeetCode 1755 最接近目标值的子序列和