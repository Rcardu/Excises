#include"../unltle.h"
namespace CreatGraph{
using std::vector;
using std::cout;
using std::endl;
using std::string;
    class Graph{
    private:
        const int MAXN=11;
        //只有链式前向星方式建图需要这个数量
        //如果无向图的最大数量是m条边，数量需要准备m*2
        //因为一条无向边需要加两条边
        const int MAXM=21;
    private:
        /*邻接矩阵的图表示*/
        vector<vector<int>>Graph1;
        /*邻接表的图表示*/
        //vector<vector<int>>Graph2;
        /*有权图的邻接表*/
        vector<vector<vector<int>>>Graph2;
        /*链式前向星建图*/
        vector<int>head;
        int cnt;
        vector<int>next;
        vector<int>tos;
        //如果有权重则外加权重数组
        vector<int>weith;
    public:
        Graph();
    private:
        void Build(int n);
        //有向图的建立
        void DirectGraph(vector<vector<int>>&edges);
        //无向图的建立
        void UndirectGraph(vector<vector<int>>&edges);
        //打印图
        void Traversal(int n);
    private:
        /*链式前向星加边*/
        void addEdge(int u,int v,int w);
    public:
        void Test_Graph();
    };
    class Topological{
    private:
        /*现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。
        给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，
        表示在选修课程 ai 前 必须 先选修 bi 。
        例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
        返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，
        你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。
        示例 1：
        输入：numCourses = 2, prerequisites = [[1,0]]
        输出：[0,1]
        解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
        示例 2：
        输入：numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
        输出：[0,2,1,3]
        解释：总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。
        并且课程 1 和课程 2 都应该排在课程 0 之后。
        因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
        示例 3：
        输入：numCourses = 1, prerequisites = []
        输出：[0]
        提示：
        1 <= numCourses <= 2000
        0 <= prerequisites.length <= numCourses * (numCourses - 1)
        prerequisites[i].length == 2
        0 <= ai, bi < numCourses
        ai != bi
        所有[ai, bi] 互不相同*/
        vector<int>LC210_findOrder(int numCourses, vector<vector<int>>& prerequisites);
    public:
        /*LeetCode 210 课程表*/
        void Test_LC210_findOrder();
    };
    class LG_Topological{
    private:
        /*有向无环图上有n个点，m条边。求这张图字典序最小的拓扑排序的结果。
        字典序最小指希望排好序的结果中，比较靠前的数字尽可能小。*/
        const int MAXN=100001;
        const int MAXM=100001;
        //链式前向星建图
        vector<int>head;
        vector<int>next;
        vector<int>tos;
        int cnt;
        //拓扑排序,小根堆
        vector<int>heap;
        int heap_size;
        //拓扑排序,入度表
        vector<int>indegree;
        //收集拓扑排序的结果
        vector<int>ans;
        const int n,m;
    private:
        //初始化
        void Build(int n);
        //添加边
        void addEdge(int u,int v);
    private:
        /*堆相关*/
        void Push(int num);
        void Swap(int n1,int n2);
        int Pop();
        bool isEmpty();
    private:
        /*拓扑排序*/
        void topSort();
    private:
        /*主要函数*/
        void LG_U107394();
    public:
        LG_Topological():n(0),m(0){;}
        //洛谷 U107394 拓扑排序模板
        void Test_LG_U107394();
    };
    class alienOrder{
        /*现有一种使用英语字母的外星文语言，这门语言的字母顺序与英语顺序不同。
        给定一个字符串列表 words ，作为这门语言的词典，
        words 中的字符串已经 按这门新语言的字母顺序进行了排序 。
        请你根据该词典还原出此语言中已知的字母顺序，
        并 按字母递增顺序 排列。若不存在合法字母顺序，
        返回 "" 。若存在多种可能的合法字母顺序，返回其中 任意一种 顺序即可。
        字符串 s 字典顺序小于 字符串 t 有两种情况：
        在第一个不同字母处，如果 s 中的字母在这门外星语言的字
        母顺序中位于 t 中字母之前，那么 s 的字典顺序小于 t 。
        如果前面 min(s.length, t.length) 字母都相同，
        那么 s.length < t.length 时，s 的字典顺序也小于 t 。
        示例 1：
        输入：words = ["wrt","wrf","er","ett","rftt"]
        输出："wertf"
        示例 2：
        输入：words = ["z","x"]
        输出："zx"
        示例 3：
        输入：words = ["z","x","z"]
        输出：""
        解释：不存在合法字母顺序，因此返回 "" 。
        提示：
        1 <= words.length <= 100
        1 <= words[i].length <= 100
        words[i] 仅由小写英文字母组成*/
        /*words = ["wrt","wrf","er","ett","rftt"]
        f(1) e(1) t(1) r(1) w(0)
        t:f
        w:e
        r:t
        e:r
        w e r t f
        */
       string LCR114_alienOrder(vector<string>& words);
    public:
        /*LCR 114 火星词典*/
        void Test_LCR114_alienOrder();
    private:
        /*你想要用小写字母组成一个目标字符串 target。 
        开始的时候，序列由 target.length 个 '?' 记号组成。而你有一个小写字母印章 stamp。
        在每个回合，你可以将印章放在序列上，并将序列中的每个字母替换为印章上的相应字母。
        你最多可以进行 10 * target.length  个回合。
        举个例子，如果初始序列为 "?????"，而你的印章 stamp 是 "abc"，那么在第一回合，
        你可以得到 "abc??"、"?abc?"、"??abc"。（请注意，印章必须完全包含在序列的边界内才能盖下去。）
        如果可以印出序列，那么返回一个数组，该数组由每个回合中被印下的最左边字母的索引组成。
        如果不能印出序列，就返回一个空数组。
        例如，如果序列是 "ababc"，印章是 "abc"，那么我们就可以返回与操作 
        "?????" -> "abc??" -> "ababc" 相对应的答案 [0, 2]；
        另外，如果可以印出序列，那么需要保证可以在 10 * target.length 个回合内完成。
        任何超过此数字的答案将不被接受。
        示例 1：
        输入：stamp = "abc", target = "ababc"
        输出：[0,2]
        （[1,0,2] 以及其他一些可能的结果也将作为答案被接受）
        示例 2：
        输入：stamp = "abca", target = "aabcaca"
        输出：[3,0,1]
        提示：
        1 <= stamp.length <= target.length <= 1000
        stamp 和 target 只包含小写字母。*/
        vector<int>LC936_movesToStamp(string stamp, string target);
    public:
        /*LeetCode 936 戳印序列*/
        void Test_LC936_movesToStamp();
    };
}
/// @brief 
namespace FoodLine{
using namespace std;
static int MAXN=5001;
static int MAXM=500001;
static int MOD=80112002;
//链式前向星
vector<int>Head(MAXN,0);
vector<int>Next(MAXM,0);
vector<int>To(MAXM,0);
int cnt;
//属性
vector<int>Indegree(MAXN,0);
vector<int>Food(MAXN,0);
//队列，用来遍历图
vector<int>que(MAXN,0);
int size;
int n,m;

    //初始化
    void Build(int n){
        cnt=1;
        size=0;
        for(int i=0;i<=n;i++){
            Head[i]=0;
            Indegree[i]=0;
            Food[i]=0;
        }
    }
    //建图
    void addEdge(int u,int v){
        Next[cnt]=Head[u];
        To[cnt]=v;
        Head[u]=cnt++;
    }
    //拓扑排序
    int Ways(){
        int l=0,r=0;
        for(int i=1;i<=n;i++){
            if(Indegree[i]==0){
                que[r++]=i;
                Food[i]=1;
            }
        }
        int ans=0;
        while(l<r){
            int cur=que[l++];
            //如果此节点没有邻接结点（即，此节点为最后一个结点）
            if(Head[cur]==0)ans=(ans+Food[cur])%MOD;
            else{
                for(int ei=Head[cur],v;ei>0;ei=Next[ei]){
                    v=To[ei];
                    Food[v]=(Food[v]+Food[cur])%MOD;
                    if(--Indegree[v]==0)que[r++]=v;

                }
            }
        }
        return ans;
    }
    void FoodLine(){
        scanf("%d%d",&n,&m);
        Build(n);
        for(int i=0,u,v;i<m;i++){
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            Indegree[v]++;
        }
        cout<<Ways()<<endl;
    }
    class loudAndRich{
    private:
        /*有一组 n 个人作为实验对象，从 0 到 n - 1 编号，其中每个人都有不同数目的钱，以及不同程度的安静值（quietness）。
        为了方便起见，我们将编号为 x 的人简称为 "person x "。
        给你一个数组 richer ，其中 richer[i] = [ai, bi] 表示 person ai 比 person bi 更有钱。另给你一个整数数组 quiet ，
        其中 quiet[i] 是 person i 的安静值。richer 中所给出的数据 逻辑自洽（也就是说，在 person x 比 person y 更有钱的同时，
        不会出现 person y 比 person x 更有钱的情况 ）。
        现在，返回一个整数数组 answer 作为答案，其中 answer[x] = y 的前提是，在所有拥有的钱肯定不少于 person x 的人中，
        person y 是最安静的人（也就是安静值 quiet[y] 最小的人）。
        示例 1：
        输入：richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
        输出：[5,5,2,5,4,5,6,7]
        解释： 
        answer[0] = 5，
        person 5 比 person 3 有更多的钱，person 3 比 person 1 有更多的钱，person 1 比 person 0 有更多的钱。
        唯一较为安静（有较低的安静值 quiet[x]）的人是 person 7，
        但是目前还不清楚他是否比 person 0 更有钱。
        answer[7] = 7，
        在所有拥有的钱肯定不少于 person 7 的人中（这可能包括 person 3，4，5，6 以及 7），
        最安静（有较低安静值 quiet[x]）的人是 person 7。
        其他的答案也可以用类似的推理来解释。
        示例 2：
        输入：richer = [], quiet = [0]
        输出：[0]
        提示：
        n == quiet.length
        1 <= n <= 500
        0 <= quiet[i] < n
        quiet 的所有值 互不相同
        0 <= richer.length <= n * (n - 1) / 2
        0 <= ai, bi < n
        ai != bi
        richer 中的所有数对 互不相同
        对 richer 的观察在逻辑上是一致的*/
        vector<int>LC851_loudAndRich(vector<vector<int>>& richer, vector<int>& quiet);
    public:
        /*LeetCode 851 喧闹和富有*/
        void Test_LC851_loudAndRich();
    };
    class mumTime{
    private:
        /*给你一个整数 n ，表示有 n 节课，课程编号从 1 到 n 。
        同时给你一个二维整数数组 relations ，其中 relations[j] = [prevCoursej, nextCoursej] ，
        表示课程 prevCoursej 必须在课程 nextCoursej 之前 完成（先修课的关系）。
        同时给你一个下标从 0 开始的整数数组 time ，其中 time[i] 表示完成第 (i+1) 门课程需要花费的 月份 数。
        请你根据以下规则算出完成所有课程所需要的 最少 月份数：
        如果一门课的所有先修课都已经完成，你可以在 任意 时间开始这门课程。
        你可以 同时 上 任意门课程 。
        请你返回完成所有课程所需要的 最少 月份数。
        注意：测试数据保证一定可以完成所有课程（也就是先修课的关系构成一个有向无环图）。
        示例 1:
        输入：n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
        输出：8
        解释：上图展示了输入数据所表示的先修关系图，以及完成每门课程需要花费的时间。
        你可以在月份 0 同时开始课程 1 和 2 。
        课程 1 花费 3 个月，课程 2 花费 2 个月。
        所以，最早开始课程 3 的时间是月份 3 ，完成所有课程所需时间为 3 + 5 = 8 个月。
        示例 2：
        输入：n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
        输出：12
        解释：上图展示了输入数据所表示的先修关系图，以及完成每门课程需要花费的时间。
        你可以在月份 0 同时开始课程 1 ，2 和 3 。
        在月份 1，2 和 3 分别完成这三门课程。
        课程 4 需在课程 3 之后开始，也就是 3 个月后。课程 4 在 3 + 4 = 7 月完成。
        课程 5 需在课程 1，2，3 和 4 之后开始，也就是在 max(1,2,3,7) = 7 月开始。
        所以完成所有课程所需的最少时间为 7 + 5 = 12 个月。
        提示：
        1 <= n <= 5 * 104
        0 <= relations.length <= min(n * (n - 1) / 2, 5 * 104)
        relations[j].length == 2
        1 <= prevCoursej, nextCoursej <= n
        prevCoursej != nextCoursej
        所有的先修课程对 [prevCoursej, nextCoursej] 都是 互不相同 的。
        time.length == n
        1 <= time[i] <= 104
        先修课程图是一个有向无环图。*/
        int LC2050_minimumTime(int n, vector<vector<int>>& relations, vector<int>& time);
    public:
        /*LeetCode 2050 并行课程III*/
        void Test_LC2050_minimumTime();
    };
    class Invitations{
    private:
        /*一个公司准备组织一场会议，邀请名单上有 n 位员工。公司准备了一张 圆形 的桌子，可以坐下 任意数目 的员工。
        员工编号为 0 到 n - 1 。每位员工都有一位 喜欢 的员工，每位员工 当且仅当 他被安排在喜欢员工的旁边，
        他才会参加会议。每位员工喜欢的员工 不会 是他自己。
        给你一个下标从 0 开始的整数数组 favorite ，其中 favorite[i] 表示第 i 位员工喜欢的员工。请你返回参加会议的 最多员工数目 。
        示例 1：
        输入：favorite = [2,2,1,2]
        输出：3
        解释：
        上图展示了公司邀请员工 0，1 和 2 参加会议以及他们在圆桌上的座位。
        没办法邀请所有员工参与会议，因为员工 2 没办法同时坐在 0，1 和 3 员工的旁边。
        注意，公司也可以邀请员工 1，2 和 3 参加会议。
        所以最多参加会议的员工数目为 3 。
        示例 2：
        输入：favorite = [1,2,0]
        输出：3
        解释：
        每个员工都至少是另一个员工喜欢的员工。所以公司邀请他们所有人参加会议的前提是所有人都参加了会议。
        座位安排同图 1 所示：
        - 员工 0 坐在员工 2 和 1 之间。
        - 员工 1 坐在员工 0 和 2 之间。
        - 员工 2 坐在员工 1 和 0 之间。
        参与会议的最多员工数目为 3 。
        示例 3：
        输入：favorite = [3,0,1,4,1]
        输出：4
        解释：
        上图展示了公司可以邀请员工 0，1，3 和 4 参加会议以及他们在圆桌上的座位。
        员工 2 无法参加，因为他喜欢的员工 0 旁边的座位已经被占领了。
        所以公司只能不邀请员工 2 。
        参加会议的最多员工数目为 4 。
        提示：
        n == favorite.length
        2 <= n <= 105
        0 <= favorite[i] <= n - 1
        favorite[i] != i*/
        int LC2127_maximumInvitations(vector<int>& favorite);
    public:
        /*LeetCode 2127 参加会议最多的员工*/
        void Test_LC2127_maximumInvitations();
    };
    //最小生成树
    class Kruskal{
    private:
        vector<int>father;
        vector<vector<int>>edges;
        constexpr static int MAXN=5001;
        constexpr static int MAXM=200001;
        int n,m;
    private:
        void Build();
        int Find(int i);
        //x和y如果本来就是一个集合返回false，否则合并两个集合
        bool Union(int x,int y);
        void Kruskal_MST();
    public:
        void Test_Kruskal_MST();
    };
    //Prim算法
    class Prim{
    private:
    constexpr static int MAXN=5001;
    constexpr static int MAXM=20001;
    int n,m;
    private:
    //堆
    vector<vector<int>>heap;
    int heap_size;
    private:
        //初始化
        void Build(int n,int m);
        //进队
        void Push(vector<int> num);
        //出堆
        int Pop();
        //交换
        void Swap(int n1,int n2);
        //判空
        bool Empty();
        void Prim_MST();
    public:
        Prim();
        void Test_Prim_MST();

    };
    class PrimPlus{
    /*Prim算法的优化：
        1.小根堆里放（到达的节点，到达节点的花费），根据到达节点的花费来组织小根堆
        2.小根堆里弹出（u节点，到达u节点的花费y），y累加到总权重上去，然后考察u出发的每一条边
            假设，u出发的边，去往v节点，权重w
            A.如果v已经弹出过了（发现过），忽略改变
            B.如果v从来没有进入过堆，向堆里加入记录（v，w）
            C.如果v在堆里，且记录为（v，x）
                1）w<x，则更新记录为（v，w）然后调整该记录在堆中的位置
                2）w>=x，忽略该边
        3.重复步骤2，直到小根堆为空*/
        constexpr static int MAXN=5001;
        constexpr static int MAXM=40001;
        //链式向前星
        vector<int>head;
        vector<int>next;
        vector<int>tos;
        vector<int>weight;
        int cnt;
        //堆
        vector<vector<int>>heap;
        int heap_size;
        //反向索引表，显示节点在数组堆中的位置 
        //用于判断每个元素是否出堆
        vector<int>Where;
        //输入
        int n,m;
        int usv,usw;
        int EdgeCnt;
        //初始化
        void Build(int n);
        //链式向前星加边
        void addEgde(int u,int v,int w);
        //堆的进队与出堆
        void heapInsert(int i);
        //判断是否要加入还是更新或者忽略
        void addOrUpdateOrIgnore(int ei);
        void Swap(int n1,int n2);
        bool Empty();
        //出堆
        void Pop();
        //调整位置
        void heapIfy(int i);
        //主函数
        void PrimPlus_MST();
    public:
        PrimPlus():cnt(0),heap_size(0){
            //节点的头部
            head.resize(MAXN);
            //第几号边
            next.resize(MAXM);
            //到哪个结点
            tos.resize(MAXM);
            weight.resize(MAXM);
            heap.resize(MAXN,vector<int>(2));
            Where.resize(MAXN);
        }
        void Test_PrimPlus_MST();
    };
    class OptimizationOfWaterAllocation{
    private:
        constexpr static int MAXN=10010;
        vector<vector<int>>edges;
        int cnt;
        vector<int>father;
        void Build(int n);
        int find(int i);
        bool Unoin(int x,int y);
        /*LeetCode 1168  水资源分配优化*/
        /*村里面一共有n栋房子，我们希望通过建造水景的方式来为所有房子供水
        对于每个房子i，我们有两种选择，一是直接再房子内建造水井
        成本为wells[i-1]（注意-1，因为索引从0开始）
        另一种是从另一口水井铺设管道引水，数组pipes给出了在房子间铺设管道的成本
        其中每个pipes[j]=[house1j,house2j,cost2j]
        代表用管道将house1j和house2j连接在一起的成本
        请返回所有房子都供水的最低成本*/
        int minCostToSupplyWater(int n,vector<int>well,vector<vector<int>>&pipes);
    public:
        OptimizationOfWaterAllocation(){
            edges.resize(MAXN<<1,vector<int>(3));
            father.resize(MAXN);
        }
        void Test_LC1168_OptimizationOfWaterAllocation();
    };
    class distanceLimitedPathsExist{
    private:
        vector<vector<int>>questions;
        vector<int>father;
        /*给你一个 n 个点组成的无向图边集 edgeList ，
        其中 edgeList[i] = [ui, vi, disi] 表示点 ui 和点 vi 之间有一条长度为 disi 的边。
        请注意，两个点之间可能有 超过一条边 。
        给你一个查询数组queries ，其中 queries[j] = [pj, qj, limitj] ，
        你的任务是对于每个查询 queries[j] ，判断是否存在从 pj 到 qj 的路径，
        且这条路径上的每一条边都 严格小于 limitj 。
        请你返回一个 布尔数组 answer ，其中 answer.length == queries.length ，
        当 queries[j] 的查询结果为 true 时， answer 第 j 个值为 true ，否则为 false 。
        示例 1：
        输入：n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
        输出：[false,true]
        解释：上图为给定的输入数据。注意到 0 和 1 之间有两条重边，分别为 2 和 16 。
        对于第一个查询，0 和 1 之间没有小于 2 的边，所以我们返回 false 。
        对于第二个查询，有一条路径（0 -> 1 -> 2）两条边都小于 5 ，所以这个查询我们返回 true 。
        示例 2：
        输入：n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
        输出：[true,false]
        解释：上图为给定数据。
        提示：
        2 <= n <= 105
        1 <= edgeList.length, queries.length <= 105
        edgeList[i].length == 3
        queries[j].length == 3
        0 <= ui, vi, pj, qj <= n - 1
        ui != vi
        pj != qj
        1 <= disi, limitj <= 109
        两个点之间可能有 多条 边。*/
        vector<bool> LC1697_distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries);
        void Build(int n);
        int Find(int i);
        void Unoin(int x,int y);
        bool isSameSet(int x,int y){return Find(x)==Find(y);}
    public:
        distanceLimitedPathsExist(){questions.resize(10000,vector<int>(4));father.resize(10000,0);}
        /*LeetCode 1697 检查边长度限制的路径是否存在*/
        void Test_LC1697_distanceLimitedPathsExist();
    };

}
/*宽度优先遍历*/
namespace WidthFirstTraversal{
    using std::vector;
    using std::queue;
    using std::priority_queue;
    using std::deque;
    using std::string;
    using std::cout;
    using std::endl;
    using std::unordered_set;
    using std::unordered_map;
    class MaxDistance{
    private:
        /*你现在手里有一份大小为 n x n 的 网格 grid，
        上面的每个 单元格 都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地。
        请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的，
        并返回该距离。如果网格上只有陆地或者海洋，请返回 -1。
        我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：
        (x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - x1| + |y0 - y1| 。
        示例 1：
        输入：grid = [[1,0,1],[0,0,0],[1,0,1]]
        输出：2
        解释： 
        海洋单元格 (1, 1) 和所有陆地单元格之间的距离都达到最大，最大距离为 2。
        示例 2：
        输入：grid = [[1,0,0],[0,0,0],[0,0,0]]
        输出：4
        解释： 
        海洋单元格 (2, 2) 和所有陆地单元格之间的距离都达到最大，最大距离为 4。
        提示：
        n == grid.length
        n == grid[i].length
        1 <= n <= 100
        grid[i][j] 不是 0 就是 1*/
        constexpr static int MAXN=101;
        constexpr static int MAXM=101;
        vector<vector<int>>que;
        vector<vector<bool>>visited;
        int l,r;
        /*i=0   (x-1,y)左
        i=1     (x,y+1)下
        i=2     (x+1,y)右
        i=3     (x,y-1)上*/
    private:
        int LC1162_maxDistance(vector<vector<int>>& grid);
    public:
        MaxDistance(){que.resize(MAXN*MAXM,vector<int>(2,0));visited.resize(MAXN,vector<bool>(MAXM));}
        /*LeetCode 1162 地图分析*/
        void Test_LC1162_maxDistance();
    };
    class MinStickers{
    private:
        constexpr static int MAXN=401;
        //队列，用来进行广搜
        vector<string>que;
        int l,r;
        //图，用来记录以某个字母开头的字符串
        vector<vector<string>>Graph;
        //set，用来记录已经访问过的字符串
        unordered_set<string>visited;
    private:
        /*我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。
        您想要拼写出给定的字符串 target ，
        方法是从收集的贴纸中切割单个字母并重新排列它们。
        如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。
        返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1 。
        注意：在所有的测试用例中，所有的单词都是从 1000 个最常见的美国英语单词中随机选择的，
        并且 target 被选择为两个随机单词的连接。
        示例 1：
        输入： stickers = ["with","example","science"], target = "thehat"
        输出：3
        解释：
        我们可以使用 2 个 "with" 贴纸，和 1 个 "example" 贴纸。
        把贴纸上的字母剪下来并重新排列后，就可以形成目标 “thehat“ 了。
        此外，这是形成目标字符串所需的最小贴纸数量。
        示例 2:
        输入：stickers = ["notice","possible"], target = "basicbasic"
        输出：-1
        解释：我们不能通过剪切给定贴纸的字母来形成目标“basicbasic”。
        提示:
        n == stickers.length
        1 <= n <= 50
        1 <= stickers[i].length <= 10
        1 <= target.length <= 15
        stickers[i] 和 target 由小写英文单词组成*/
        int LC691_minStickers(vector<string>& stickers, string target);
        string Next(string cur,string s);
    public:
        MinStickers();
        /*LeetCode 691 贴纸拼词*/
        void Test_LC691_minStickers();
    };
    class MinimumObstacles{
    private:
        /*给你一个下标从 0 开始的二维整数数组 grid ，数组大小为 m x n 。
        每个单元格都是两个值之一：
        0 表示一个 空 单元格，
        1 表示一个可以移除的 障碍物 。
        你可以向上、下、左、右移动，从一个空单元格移动到另一个空单元格。
        现在你需要从左上角 (0, 0) 移动到右下角 (m - 1, n - 1) ，
        返回需要移除的障碍物的 最小 数目。
        示例 1：
        输入：grid = [[0,1,1],[1,1,0],[1,1,0]]
        输出：2
        解释：可以移除位于 (0, 1) 和 (0, 2) 的障碍物来创建从 (0, 0) 到 (2, 2) 的路径。
        可以证明我们至少需要移除两个障碍物，所以返回 2 。
        注意，可能存在其他方式来移除 2 个障碍物，创建出可行的路径。
        示例 2：
        输入：grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
        输出：0
        解释：不移除任何障碍物就能从 (0, 0) 到 (2, 4) ，所以返回 0 。
        提示：
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 105
        2 <= m * n <= 105
        grid[i][j] 为 0 或 1
        grid[0][0] == grid[m - 1][n - 1] == 0*/
        int LC2290_minimumObstacles(vector<vector<int>>& grid);
    public:
        /*LeetCode 2290 到达角落需要移除的障碍物的最小数目*/
        void Test_LC2290_minimumObstacles();
    };
    class MinCost{
    private:
        /*给你一个 m x n 的网格图 grid 。 grid 中每个格子都有一个数字，
        对应着从该格子出发下一步走的方向。 grid[i][j] 中的数字可能为以下几种情况：
        1 ，下一步往右走，也就是你会从 grid[i][j] 走到 grid[i][j + 1]
        2 ，下一步往左走，也就是你会从 grid[i][j] 走到 grid[i][j - 1]
        3 ，下一步往下走，也就是你会从 grid[i][j] 走到 grid[i + 1][j]
        4 ，下一步往上走，也就是你会从 grid[i][j] 走到 grid[i - 1][j]
        注意网格图中可能会有 无效数字 ，因为它们可能指向 grid 以外的区域。
        一开始，你会从最左上角的格子 (0,0) 出发。我们定义一条 有效路径 为从格子 (0,0) 出发，
        每一步都顺着数字对应方向走，最终在最右下角的格子 (m - 1, n - 1) 结束的路径。有效路径 不需要是最短路径 。
        你可以花费 cost = 1 的代价修改一个格子中的数字，但每个格子中的数字 只能修改一次 。
        请你返回让网格图至少有一条有效路径的最小代价。
        示例 1：
        输入：grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
        输出：3
        解释：你将从点 (0, 0) 出发。
        到达 (3, 3) 的路径为： (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) 
        花费代价 cost = 1 使方向向下 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) 
        花费代价 cost = 1 使方向向下 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) 花费代价 cost = 1 使方向向下 --> (3, 3)
        总花费为 cost = 3.
        示例 2：
        输入：grid = [[1,1,3],[3,2,2],[1,1,4]]
        输出：0
        解释：不修改任何数字你就可以从 (0, 0) 到达 (2, 2) 。
        示例 3：
        输入：grid = [[1,2],[4,3]]
        输出：1
        示例 4：
        输入：grid = [[2,2,2],[2,2,2]]
        输出：3
        示例 5：
        输入：grid = [[4]]
        输出：0
        提示：
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 100*/
        int LC1368_minCost(vector<vector<int>>& grid);
    public:
        /*LeetCode 1368 使网格至少有一条有效路径的最小代价*/
        void Test_LC1368_minCost();
    };
    class trapRainWater{
    private:
        /*给你一个 m x n 的矩阵，其中的值均为非负整数，
        代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。
        示例 1:
        输入: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
        输出: 4
        解释: 下雨后，雨水将会被上图蓝色的方块中。总的接雨水量为1+2+1=4。
        示例 2:
        输入: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
        输出: 10
        提示:
        m == heightMap.length
        n == heightMap[i].length
        1 <= m, n <= 200
        0 <= heightMap[i][j] <= 2 * 104
        */
        int LC407_trapRainWater(vector<vector<int>>& heightMap);
    public: 
        /*LeetCode 407 接雨水II*/
        void Test_LC407_trapRainWater();
    };
    class FindLadders{
    private:
        //单词表，哈希set形式
        unordered_set<string>dict;
        //当前层的单词
        unordered_set<string>curLevel;
        //当前层的下一层的单词
        unordered_set<string>nextLevel;
        //从end到begin的反向图
        unordered_map<string,vector<string>>Graph;
        //当生成一条有效路径时拷贝进ans中
        vector<string>path;
        //答案集合
        vector<vector<string>>ans;
    private:
        /*按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，
        一个表示此过程的 转换序列 是形式上像 beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，并满足：
        每对相邻的单词之间仅有单个字母不同。
        转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。注意，beginWord 不必是字典 wordList 中的单词。
        sk == endWord
        给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。
        请你找出并返回所有从 beginWord 到 endWord 的 最短转换序列 ，如果不存在这样的转换序列，
        返回一个空列表。每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回。
        示例 1：
        输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
        输出：[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
        解释：存在 2 种最短的转换序列：
        "hit" -> "hot" -> "dot" -> "dog" -> "cog"
        "hit" -> "hot" -> "lot" -> "log" -> "cog"
        示例 2：
        输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
        输出：[]
        解释：endWord "cog" 不在字典 wordList 中，所以不存在符合要求的转换序列。
        提示：
        1 <= beginWord.length <= 5
        endWord.length == beginWord.length
        1 <= wordList.length <= 500
        wordList[i].length == beginWord.length
        beginWord、endWord 和 wordList[i] 由小写英文字母组成
        beginWord != endWord
        wordList 中的所有单词 互不相同*/
        vector<vector<string>> LC126_findLadders(string beginWord, string endWord, vector<string>& wordList);
        //初始化
        void Build(vector<string>&wordList);
        //广搜
        bool LC126_findLadders_BFS(string beginword,string endword);
        //深搜
        void LC126_findLadders_DFS(string endword,string beginwrod);
    public:
        /*LeetCode 126 单词接龙II*/
        void Test_LC126_findLadders();
    };
    class LadderLength{
    private:
        /*字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：
        每一对相邻的单词只差一个字母。
        对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
        sk == endWord
        给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。
        示例 1：
        输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
        输出：5
        解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
        示例 2：
        输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
        输出：0
        解释：endWord "cog" 不在字典中，所以无法进行转换。
        提示：
        1 <= beginWord.length <= 10
        endWord.length == beginWord.length
        1 <= wordList.length <= 5000
        wordList[i].length == beginWord.length
        beginWord、endWord 和 wordList[i] 由小写英文字母组成
        beginWord != endWord
        wordList 中的所有字符串 互不相同*/
        int LC127_ladderLength(string beginWord, string endWord, vector<string>& wordList);
    public:
        /*LeetCode 127 单词接龙*/
        void Test_LC127_ladderLength();
    };
    class SnacksWayBuyTickets{
    private:
    constexpr static int MAXN=40;
    constexpr static int MAXM=1<<20;
    //输入的数组
    vector<long long>arr;
    /*双向广搜左半边*/
    vector<long long>lnum;
    /*双向广搜右半边*/
    vector<long long>rnum;
    /*数组长度、最大限制条件*/
    long long n,m;
        /*零食问题&世界冰球竞标赛
        牛牛准备参加学校组织的春游，出发前牛牛准备往背包里装入一些零食，牛牛的背包容量为w
        牛牛在家里一共有n袋零食，第i袋零食的体积为v[i]
        牛牛想知道在总体积不超过背包容量的情况下
        一共有多少种零食的放法（总体积为0也是一种放法）
        数据量：
        1<=n<=40
        1<=w<=w*10^9
        0<=v[i]<=10^9*/
    private:
        void LGP4799_SnacksWayBuyTickets();
        /*双向广搜的数据处理*/
        long long LGP4799_Compute();
        /*双向广搜  arr[i....e]结束，e再往右，不展开；之前的决定所形成的累加和s，限制条件w，此广搜所生成的符合限制条件的集合
        返回值：ans数组填到了什么位置*/
        int LGP4799_f(int i,int e,long long s,long long w,vector<long long>&ans,int j);
    public:
        SnacksWayBuyTickets(){
            arr.resize(MAXN);
            lnum.resize(MAXM);
            rnum.resize(MAXM);
        }
        /*LGP4799 世界冰球锦标赛*/
        void Test_LGP4799_SnacksWayBuyTickets();
    };
    class MinAbsDifference{
    private:
        constexpr static int MAXM=1<<20;
        vector<long long>lsum;
        vector<long long>rsum;
        //记录长度
        int fill;
        /*给你一个整数数组 nums 和一个目标值 goal 。
        你需要从 nums 中选出一个子序列，使子序列元素总和最接近 goal 。也就是说，如果子序列元素和为 sum ，你需要 最小化绝对差 abs(sum - goal) 。
        返回 abs(sum - goal) 可能的 最小值 。
        注意，数组的子序列是通过移除原始数组中的某些元素（可能全部或无）而形成的数组。
        示例 1：
        输入：nums = [5,-7,3,5], goal = 6
        输出：0
        解释：选择整个数组作为选出的子序列，元素和为 6 。
        子序列和与目标值相等，所以绝对差为 0 。
        示例 2：
        输入：nums = [7,-9,15,-2], goal = -5
        输出：1
        解释：选出子序列 [7,-9,-2] ，元素和为 -4 。
        绝对差为 abs(-4 - (-5)) = abs(1) = 1 ，是可能的最小值。
        示例 3：
        输入：nums = [1,2,3], goal = -7
        输出：7
        提示：
        1 <= nums.length <= 40
        -107 <= nums[i] <= 107
        -109 <= goal <= 109*/
        int LC1755_minAbsDifference(vector<int>& nums, int goal);
        /*双向广搜*/
        void LC1755_minAbsDifference_f(vector<int>&arr,int i,int e,long long s,vector<long long>&ans);
    public:
        /*LeetCode 1755 最接近目标值的子序列和*/
        void Test_LC1755_minAbsDifference();
        MinAbsDifference(){
            lsum.resize(MAXM);
            rsum.resize(MAXM);
        }
    };
}

/*Dijkstra算法、分层图最短路*/
namespace HierarchicalDiagramShortestPath{
using std::vector;
using std::queue;
using std::priority_queue;
using std::deque;
using std::string;
using std::cout;
using std::endl;
using std::unordered_set;
using std::unordered_map;
using std::sqrt;
using std::pow;
vector<int>Move={-1,0,1,0,-1};
    /*普通堆实现Dijkstra算法，时间复杂度O(m*logm)m为边数
    1.dustance[i]表示从源点到i点的最短距离，visited[i]表示i节点是否从小根堆里弹出过
    2.准备好小根堆，小根堆存放记录：（x点，源点到x的距离），小根堆根据距离组织
    3.令distance[源点]=0,（源点，0）进入小根堆
    4.从小根堆中弹出（u点，源点到u的距离）
        a.如果vistance[u]==true,不做任何处理，重复步骤4
        b.如果vistance[u]==false令vistance[u]==true,u就算弹出过了
            然后考察u的每一条边，假设某边去往v，边权为w
            1).如果visitance[v]==false并且distance[u]+w<distance[v]
            令distance [v]==distance[u]+w,把(v,distance[u]+w)加入小根堆
            2).处理完u的每一条边之后，重复步骤4 
    5.小根堆为空，过程结束，distance表记录了源点到每个节点的最短距离*/
    class DijkstraAlorgithm{
    private:
        /*有 n 个网络节点，标记为 1 到 n。
        给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。
        现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。
        示例 1：
        输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
        输出：2
        示例 2：
        输入：times = [[1,2,1]], n = 2, k = 1
        输出：1
        示例 3：
        输入：times = [[1,2,1]], n = 2, k = 2
        输出：-1
        提示：
        1 <= k <= n <= 100
        1 <= times.length <= 6000
        times[i].length == 3
        1 <= ui, vi <= n
        ui != vi
        0 <= wi <= 100
        所有 (ui, vi) 对都 互不相同（即，不含重复边）*/
        int LC743_networkDelayTime(vector<vector<int>>& times, int n, int k);
    public:
        /*LeetCode 743 网络延迟时间*/
        void Test_LC743_networkDelayTime();
    };
    /*1.准备好一个反向索引堆，根据源点到当前点的距离组织小根堆，可以做到如下操作
        a.新增记录(X,源点到X的距离)     b.当源点到X的距离更新时，可以进行堆的调整
        c.X点一旦弹出，以后忽略X        d.弹出堆顶的记录(u,源点到u的距离)
    2.把源点(源点，0)加入反向索引堆，过程开始
    3.反向索引堆弹出(u,源点到u的距离),考察u的每一条边，假设某边去往v，边权为w
        1)如果v没有进入过反向索引堆里，新增记录(v,源点到u的距离+w)
        2)如果v曾经从反向索引堆弹出过，忽略
        3)如果v在反向索引堆里，看看源点到v的距离能不能变的更小，如果能，调整堆；不能，忽略
        4)处理完u的一条边，重复步骤3
    4.反向索引堆为空过程结束。反向索引堆里记录了源点到每个节点的最短距离*/
    class InvertedIndexingDijkstra{
        /*基于反向索引堆实现的Dijkstra算法*/
    private:
        constexpr static int MAXN=101;
        constexpr static int MAXM=6001;
        //堆
        vector<int>Heap;
        int Heap_size;
        /*反向索引表 -1:还未进堆    -2:已经出过堆   >=0已经在堆内*/
        vector<int>Where;
        //链式前向星
        vector<int>Head;
        vector<int>next;
        vector<int>tos;
        vector<int>weight;
        int cnt;
        //距离数组
        vector<int>Distance;
    private:
        //初始化
        void Build(int n);
        //链式前向星加边
        void addEdge(int u,int v,int w);
        //LeetCode 743
        int LC743_networkDelayTime(vector<vector<int>>& times, int n, int k);
        //添加或者更新或者跳过
        void addOrUpdateOrIgnore(int u,int c);
        //调整堆
        void HeapInsert(int i);
        //交换
        void Swap(int i,int j);
        //出堆
        int Pop();
        //调整堆
        void HeapFiy(int i);
        //堆是否为空
        bool Empty();
    public:
        InvertedIndexingDijkstra();
        void Test_LC743_networkDelayTime();
    };
    class MinimumEffortPath{
    private:
        /*你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。
        一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。
        请你返回从左上角走到右下角的最小 体力消耗值 。
        示例 1：
        输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
        输出：2
        解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
        这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
        示例 2：
        输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
        输出：1
        解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
        示例 3：
        输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
        输出：0
        解释：上图所示路径不需要消耗任何体力。
        提示：
        rows == heights.length
        columns == heights[i].length
        1 <= rows, columns <= 100
        1 <= heights[i][j] <= 106*/
        int LC1631_minimumEffortPath(vector<vector<int>>& heights);
    public:
        /*LeetCode 1631 消耗最小体力值的路径*/
        void Test_LC1631_minimumEffortPath();
    };
    class SwimInWater{
    private:
        /*在一个 n x n 的整数矩阵 grid 中，每一个方格的值 grid[i][j] 表示位置 (i, j) 的平台高度。
        当开始下雨时，在时间为 t 时，水池中的水位为 t 。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。
        你从坐标方格的左上平台 (0，0) 出发。返回 你到达坐标方格的右下平台 (n-1, n-1) 所需的最少时间 。
        示例 1:
        输入: grid = [[0,2],[1,3]]
        输出: 3
        解释:
        时间为0时，你位于坐标方格的位置为 (0, 0)。
        此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。
        等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置
        示例 2:
        输入: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
        输出: 16
        解释: 最终的路线用加粗进行了标记。
        我们必须等到时间为 16，此时才能保证平台 (0, 0) 和 (4, 4) 是连通的
        提示:
        n == grid.length
        n == grid[i].length
        1 <= n <= 50
        0 <= grid[i][j] < n2
        grid[i][j] 中每个值 均无重复*/
        int LC778_swimInWater(vector<vector<int>>& grid);
    public:
        /*LeetCode 778 在水位升高的泳池中游泳*/
        void Test_LC778_swimInWater();
    };
    /*分层最短路(扩点最短路)*/
    class ShortestPathAllKeys{
    private:
    //矩阵的规模
    constexpr static int MAXN=31;
    constexpr static int MAXM=31;
    //钥匙的数量
    constexpr static int MAXK=6;
    //移动数组
    //点与状态结合的方位情况，(状态的个数为1<<6,即2^6个状态)
    vector<vector<vector<bool>>>visited;
    //队列  [0]:行    [1]:列  [2]:状态
    vector<vector<int>>que;
    //控制队列的指针、行数，列数、钥匙的状态
    int l,r,n,m,key;
        /*给定一个二维网格 grid ，其中：
        '.' 代表一个空房间
        '#' 代表一堵墙
        '@' 是起点
        小写字母代表钥匙
        大写字母代表锁
        我们从起点开始出发，一次移动是指向四个基本方向之一行走一个单位空间。我们不能在网格外面行走，也无法穿过一堵墙。如果途经一个钥匙，我们就把它捡起来。除非我们手里有对应的钥匙，否则无法通过锁。
        假设 k 为 钥匙/锁 的个数，且满足 1 <= k <= 6，字母表中的前 k 个字母在网格中都有自己对应的一个小写和一个大写字母。换言之，每个锁有唯一对应的钥匙，每个钥匙也有唯一对应的锁。另外，代表钥匙和锁的字母互为大小写并按字母顺序排列。
        返回获取所有钥匙所需要的移动的最少次数。如果无法获取所有钥匙，返回 -1 。
        示例 1：
        输入：grid = ["@.a.#","###.#","b.A.B"]
        输出：8
        解释：目标是获得所有钥匙，而不是打开所有锁。
        示例 2：
        输入：grid = ["@..aA","..B#.","....b"]
        输出：6
        示例 3:
        输入: grid = ["@Aa"]
        输出: -1
        提示：
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 30
        grid[i][j] 只含有 '.', '#', '@', 'a'-'f' 以及 'A'-'F'
        钥匙的数目范围是 [1, 6] 
        每个钥匙都对应一个 不同 的字母
        每个钥匙正好打开一个对应的锁*/
        int LC864_shortestPathAllKeys(vector<string>& grid);
        //初始化
        void Build(vector<string>& grid);
    public:
        /*LeetCode 864 获取所有钥匙的最短路径*/
        void Test_LC864_shortestPathAllKeys();
    };
    class ElectricCarPlan{
    private:
        /*小明的电动车电量充满时可行驶距离为 cnt，每行驶 1 单位距离消耗 1 单位电量，且花费 1 单位时间。小明想选择电动车作为代步工具。地图上共有 N 个景点，景点编号为 0 ~ N-1。他将地图信息以 [城市 A 编号,城市 B 编号,两城市间距离] 格式整理在在二维数组 paths，表示城市 A、B 间存在双向通路。初始状态，电动车电量为 0。每个城市都设有充电桩，charge[i] 表示第 i 个城市每充 1 单位电量需要花费的单位时间。请返回小明最少需要花费多少单位时间从起点城市 start 抵达终点城市 end。
        示例 1：
        输入：paths = [[1,3,3],[3,2,1],[2,1,3],[0,1,4],[3,0,5]], cnt = 6, start = 1, end = 0, charge = [2,10,4,1]
        输出：43
        解释：最佳路线为：1->3->0。 在城市 1 仅充 3 单位电至城市 3，然后在城市 3 充 5 单位电，行驶至城市 5。 充电用时共 3*10 + 5*1= 35 行驶用时 3 + 5 = 8，此时总用时最短 43。image.png
        示例 2：
        输入：paths = [[0,4,2],[4,3,5],[3,0,5],[0,1,5],[3,2,4],[1,2,8]], cnt = 8, start = 0, end = 2, charge = [4,1,1,3,2]
        输出：38
        解释：最佳路线为：0->4->3->2。 城市 0 充电 2 单位，行驶至城市 4 充电 8 单位，行驶至城市 3 充电 1 单位，最终行驶至城市 2。 充电用时 4*2+2*8+3*1 = 27 行驶用时 2+5+4 = 11，总用时最短 38。
        提示：
        1 <= paths.length <= 200
        paths[i].length == 3 
        2 <= charge.length == n <= 100
        0 <= path[i][0],path[i][1],start,end < n
        1 <= cnt <= 100
        1 <= path[i][2] <= cnt
        1 <= charge[i] <= 100
        题目保证所有城市相互可以到达*/
        int LCP35_electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge);
    public:
        /*LCP 35 电动车游城市*/
        void Test_LCP35_electricCarPlan();
    };
    class AStarAlgorithm{
    private:
        /*返回从(startX,startY)到(targetX,targetY)的最短距离*/
        //基于Dijkstra算法
        int MinDistance1(vector<vector<int>>&grid,int startX,int startY,int targetX,int targetY);
        //基于Dijkstra算法的进阶A*算法
        int MinDistance2(vector<vector<int>>&grid,int startX,int startY,int targetX,int targetY);
        //曼哈顿距离函数
        int MinDistance2_f1(int SX,int SY,int EX,int EY);
        //对角线距离
        int MinDistance2_f2(int SX,int SY,int EX,int EY);
        //欧式距离
        double MinDistance2_f3(int SX,int SY,int EX,int EY);
    public:
        void Test_MinDistance();
    };
    class Floyd{
    private:
        vector<vector<int>>distance;
        void floyds();
    public:
        void Test_floyds();
    };
    class Bellman_Ford{
    /*松弛操作
    假设源点为A，从A到任意点F的最短距离为distance[F]
    假设从P点出发从某条边去往点S，边权为W
    如果发现，distance[P]+W<distance[S],也就是通过该边可以让distance[S]变小
    那么就说，P出发的这条边对点S进行了松弛操作
    Bellman-Ford过程：
    1.每轮考察一条边，每条边都尝试进行松弛操作，那么若干点的distance会变小
    2.当某一轮发现不再有松弛操作出现时，算法停止*/
    private:
        /*有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [fromi, toi, pricei] ，表示该航班都从城市 fromi 开始，以价格 pricei 抵达 toi。
        现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到出一条最多经过 k 站中转的路线，使得从 src 到 dst 的 价格最便宜 ，并返回该价格。 如果不存在这样的路线，则输出 -1。
        示例 1：
        输入: 
        n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
        src = 0, dst = 2, k = 1
        输出: 200
        解释: 
        城市航班图如下
        从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。
        示例 2：
        输入: 
        n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
        src = 0, dst = 2, k = 0
        输出: 500
        解释: 
        城市航班图如下
        从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。
        示：
        1 <= n <= 100
        0 <= flights.length <= (n * (n - 1) / 2)
        flights[i].length == 3
        0 <= fromi, toi < n
        fromi != toi
        1 <= pricei <= 104
        航班没有重复，且不存在自环
        0 <= src, dst, k < n
        src != dst*/
        int LC_787findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k);
    public:
        /*LeetCode 787 k站中转内最便宜的航班*/
        void LC787_findCheapestPrice();
    };
    /*Bellman-Ford+SPFA优化(Shortest Path Faster Algorithm)
    很轻易就能发现，每一轮考察所有的边看看能否做松弛操作是不必要的
    因为只有上一次被某条边松弛过的节点，所连接的边，才有可能引起下一次松弛操作
    所以用队列来维护，“这一轮有哪些节点的distacne变小了”
    下一轮只需要对这些点的所有边，考察有没有松弛操作即可*/
    class LGP3385_SPFA{
    private:
        //点的个数
        constexpr static int MAXN=2001;
        //边的个数
        constexpr static int MAXM=600001;
        //链式前向星
        vector<int>head;
        vector<int>nexts;
        vector<int>tos;
        vector<int>weight;
        int cnt;
        //SPFA所需要的空间为
        constexpr static int MAXQ=40000001;
        //源点到当前点的最小距离
        vector<int>distances;
        //每个点更新的次数
        vector<int>updateCnt;
        //队列
        vector<int>que;
        int l,r;
        //进堆情况
        vector<bool>enters;
    private:
        /*从某一条便出发是否有负环*/
        void Build(int n);
        bool Spfa(int n);
        void addEdge(int u,int c,int w);
        void SPFA();
    public:
        LGP3385_SPFA();
        void Test_SPFA();
    };
} /*给定一个字符串数组，从起始的字符到目标字符的最短距离
    每两个相同的字符之间可以直接传送*/