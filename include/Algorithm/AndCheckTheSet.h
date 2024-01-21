#include"../unltle.h"

namespace CheckSet{
using std::vector;
using std::cout;
using std::endl;
using std::string;
static int MAXN=1000001;
    class Cheack{
    private:
        vector<int>father;
        vector<int>size;
        vector<int>stack;
        int n;
    public:
        Cheack():n(0){father.resize(MAXN,0);size.resize(MAXN,0);stack.resize(MAXN,0);}
    private:
        /*i号结点往上查，一直查到代表结点*/
        int Check_find(int i);
        /*判断两个元素是否在同一集合*/
        bool Check_isSameSet(int x,int y);
        //合并两个元素所在的集合
        void Check_union(int x,int y);
    public:
        /*并查集*/
        void Test_Check();
    };
    class ChSet{
    private:
        vector<int>father;
        int sets;
        /*n 对情侣坐在连续排列的 2n 个座位上，想要牵到对方的手。
        人和座位由一个整数数组 row 表示，
        其中 row[i] 是坐在第 i 个座位上的人的 ID。
        情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，
        以此类推，最后一对是 (2n-2, 2n-1)。
        返回 最少交换座位的次数，以便每对情侣可以并肩坐在一起。 
        每次交换可选择任意两人，让他们站起来交换座位。
        示例 1:
        输入: row = [0,2,1,3]
        输出: 1
        解释: 只需要交换row[1]和row[2]的位置即可。
        示例 2:
        输入: row = [3,2,0,1]
        输出: 0
        解释: 无需交换座位，所有的情侣都已经可以手牵手了。
        提示:
        2n == row.length
        2 <= n <= 30
        n 是偶数
        0 <= row[i] < 2n
        row 中所有元素均无重复*/
        int LC765_minSwapsCouples(vector<int>& row);
        void LC765_build(int n);
        int LC756_find(int i);
        void LC765_Union(int x,int y);
    public:
        ChSet():sets(0){father.resize(31,0);}
        /*LeetCode 765 情侣牵手*/
        void Test_LC765_minSwapsCouples();
    private:
        /*如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，
        那么称 X 和 Y 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。
        例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； 
        "rats" 和 "arts" 也是相似的，但是 "star" 不与 "tars"，"rats"，或 "arts" 相似。
        总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 
        和 {"star"}。注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似。
        形式上，对每个组而言，要确定一个单词在组中，
        只需要这个词和该组中至少一个单词相似。
        给你一个字符串列表 strs。列表中的每个字符串都是 
        strs 中其它所有字符串的一个字母异位词。
        请问 strs 中有多少个相似字符串组？
        示例 1：
        输入：strs = ["tars","rats","arts","star"]
        输出：2
        示例 2：
        输入：strs = ["omv","ovm"]
        输出：1
        提示：
        1 <= strs.length <= 300
        1 <= strs[i].length <= 300
        strs[i] 只包含小写字母。
        strs 中的所有单词都具有相同的长度，且是彼此的字母异位词。*/
        int LC839_numSimilarGroups(vector<string>& strs);
    public:
        /*LeetCode 839 相似的字符串组*/
        void Test_LC839_numSimilarGroups();
    };
    class AllPeople{
    private:
        /*并查集*/
        vector<int>father;
        /*并查集标记*/
        vector<bool>secret;
    public:
        /*初始化并查集*/
        AllPeople(){father.resize(100001,0);secret.resize(100001,false);} 
    private:
        /*建立并查集*/
        void Build(int n,int first);
        /*查找并查集中元素i所在的集合*/
        int find(int i);
        /*将元素x和元素y合并在同一个集合中*/
        void Union(int x,int y);
        /*给你一个整数 n ，表示有 n 个专家从 0 到 n - 1 编号。
        另外给你一个下标从 0 开始的二维整数数组 meetings ，
        其中 meetings[i] = [xi, yi, timei] 表示专家 xi 和专家 yi 在时间 timei 要开一场会。
        一个专家可以同时参加 多场会议 。最后，给你一个整数 firstPerson 。
        专家 0 有一个 秘密 ，最初，他在时间 0 将这个秘密分享给了专家 firstPerson 。
        接着，这个秘密会在每次有知晓这个秘密的专家参加会议时进行传播。更正式的表达是，
        每次会议，如果专家 xi 在时间 timei 时知晓这个秘密，那么他将会与专家 yi 分享这个秘密，反之亦然。
        秘密共享是 瞬时发生 的。也就是说，在同一时间，
        一个专家不光可以接收到秘密，还能在其他会议上与其他专家分享。
        在所有会议都结束之后，返回所有知晓这个秘密的专家列表。你可以按 任何顺序 返回答案。
        示例 1：
        输入：n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
        输出：[0,1,2,3,5]
        解释：
        时间 0 ，专家 0 将秘密与专家 1 共享。
        时间 5 ，专家 1 将秘密与专家 2 共享。
        时间 8 ，专家 2 将秘密与专家 3 共享。
        时间 10 ，专家 1 将秘密与专家 5 共享。
        因此，在所有会议结束后，专家 0、1、2、3 和 5 都将知晓这个秘密。
        示例 2：
        输入：n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
        输出：[0,1,3]
        解释：
        时间 0 ，专家 0 将秘密与专家 3 共享。
        时间 2 ，专家 1 与专家 2 都不知晓这个秘密。
        时间 3 ，专家 3 将秘密与专家 0 和专家 1 共享。
        因此，在所有会议结束后，专家 0、1 和 3 都将知晓这个秘密。
        示例 3：
        输入：n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
        输出：[0,1,2,3,4]
        解释：
        时间 0 ，专家 0 将秘密与专家 1 共享。
        时间 1 ，专家 1 将秘密与专家 2 共享，专家 2 将秘密与专家 3 共享。
        注意，专家 2 可以在收到秘密的同一时间分享此秘密。
        时间 2 ，专家 3 将秘密与专家 4 共享。
        因此，在所有会议结束后，专家 0、1、2、3 和 4 都将知晓这个秘密。
        提示：
        2 <= n <= 105
        1 <= meetings.length <= 10^5
        meetings[i].length == 3
        0 <= xi, yi <= n - 1
        xi != yi
        1 <= time[i] <= 10^5
        1 <= firstPerson <= n - 1*/
        vector<int>LC2092_findAllPeople(int n,vector<vector<int>>&meeting,int first);  
    public:
        /*LeetCode 2092 找出所有知晓秘密的专家*/
        void Test_LC2092_findAllPeople();
    };
    class GoodPaths{
    private:
        /*给你一棵 n 个节点的树（连通无向无环的图），
        节点编号从 0 到 n - 1 且恰好有 n - 1 条边。
        给你一个长度为 n 下标从 0 开始的整数数组 vals ，
        分别表示每个节点的值。同时给你一个二维整数数组 edges 
        其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条 无向 边。
        一条 好路径 需要满足以下条件：
        开始节点和结束节点的值 相同 。
        开始节点和结束节点中间的所有节点值都 
        小于等于 开始节点的值（也就是说开始节点的值应该是路径上所有节点的最大值）。
        请你返回不同好路径的数目。
        注意，一条路径和它反向的路径算作 同一 路径。
        比方说， 0 -> 1 与 1 -> 0 视为同一条路径。单个节点也视为一条合法路径。
        示例 1：
        输入：vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
        输出：6
        解释：总共有 5 条单个节点的好路径。
        还有 1 条好路径：1 -> 0 -> 2 -> 4 。
        （反方向的路径 4 -> 2 -> 0 -> 1 视为跟 1 -> 0 -> 2 -> 4 一样的路径）
        注意 0 -> 2 -> 3 不是一条好路径，因为 vals[2] > vals[0] 。
        示例2：
        输入：vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
        输出：7
        解释：总共有 5 条单个节点的好路径。
        还有 2 条好路径：0 -> 1 和 2 -> 3 。
        示例 3：
        输入：vals = [1], edges = []
        输出：1
        解释：这棵树只有一个节点，所以只有一条好路径。
        提示：
        n == vals.length
        1 <= n <= 3 * 104
        0 <= vals[i] <= 105
        edges.length == n - 1
        edges[i].length == 2
        0 <= ai, bi < n
        ai != bi
        edges 表示一棵合法的树。*/
        vector<int>father_;
        vector<int>maxcnt_;
    public:
        GoodPaths(){father_.resize(10001,0);maxcnt_.resize(10001,0);}
    private:
        /*初始化并查集*/
        void Build(int n);
        /*查找元素i在哪个集合中*/
        int Find(int i);
        /*合并并返回两个几个中最大值个数的乘积*/
        int Unoin(int x,int y,vector<int>&vals);
        /*结果函数*/
        int LC2421_numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges);
    public:
        /*LeetCode 好路径的数目*/
        void Test_LC2421_numberOfGoodPaths();
    };
    class MalwareSpread{
    private:
        /*并查集的固有信息*/
        vector<int>father_;
        /*病毒点*/
        vector<bool>virus_;
        /*当前源头删掉能拯救多少数据*/
        vector<int>cnts_;
        /*集合的大小*/
        vector<int>size_;
        /*集合的标签
        -1：表示没有被感染
        -2：表示被感染的次数超过1，无法拯救
        >=0：表示当前只被一个点感染，感染点的索引为此值*/
        vector<int>infect_;
    public:
        MalwareSpread();
    private:
        /*给定一个由 n 个节点组成的网络，用 n x n 个邻接矩阵 graph 表示。
        在节点网络中，只有当 graph[i][j] = 1 时，节点 i 能够直接连接到另一个节点 j。
        一些节点 initial 最初被恶意软件感染。只要两个节点直接连接，
        且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。
        这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。
        假设 M(initial) 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。
        我们可以从 initial 中删除一个节点，并完全移除该节点以及从该节点到任何其他节点的任何连接。
        请返回移除后能够使 M(initial) 最小化的节点。如果有多个节点满足条件，返回索引 最小的节点 。
        示例 1：
        输入：graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
        输出：0
        示例 2：
        输入：graph = [[1,1,0],[1,1,1],[0,1,1]], initial = [0,1]
        输出：1
        示例 3：
        输入：graph = [[1,1,0,0],[1,1,1,0],[0,1,1,1],[0,0,1,1]], initial = [0,1]
        输出：1
        提示：
        n == graph.length
        n == graph[i].length
        2 <= n <= 300
        graph[i][j] 是 0 或 1.
        graph[i][j] == graph[j][i]
        graph[i][i] == 1
        1 <= initial.length < n
        0 <= initial[i] <= n - 1
        initial 中每个整数都不同*/
        int LC928_minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial);
        /*建立并查集*/
        void Build(int n,vector<int>&initial);
        /*查找元素i在哪个集合中*/
        int Find(int i);
        /*合并元素x与元素y所在的集合*/
        void Unoin(int x,int y);
    public:
        /*LeetCode 928 尽量减少恶意软件的传播*/
        void Test_LC928_minMalwareSpread();
    };
    class Islands{
    private:
        //并查集固有信息
        vector<int>father;
        //行数，用来组成行列元素的映射值
        int cols;
        //集合的个数，用来返回结果
        int sets;
        /*给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
        岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
        此外，你可以假设该网格的四条边均被水包围。
        示例 1：
        输入：grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
        ]
        输出：1
        示例 2：
        输入：grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
        ]
        输出：3
        提示：
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 300
        grid[i][j] 的值为 '0' 或 '1'*/
        //并查集
        int numIslands1(vector<vector<char>>& grid);
        //建立并查集
        void Build(int n,int m,vector<vector<char>>&grid);
        //查找元素i所在的集合
        int Find(int i);
        //合并x和y所在的集合
        void Unoin(int x,int y);
        //生成映射值(根据行列)
        int Index(int i,int j);
        //洪水填充
        int numIslands2(vector<vector<char>>& grid);
        //洪水DFS
        void numIslands2_DFS(vector<vector<char>>&grid,int i,int j);
    public:
        Islands():sets(0){father.resize(90001,0);}
        /*LeetCode 200 岛屿数量*/
        void Test_LC200_numIslands();
    };
    class Solve{
    private:
        /*给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
        示例 1：
        输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
        输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
        解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 
        任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
        示例 2：
        输入：board = [["X"]]
        输出：[["X"]]
        提示：
        m == board.length
        n == board[i].length
        1 <= m, n <= 200
        board[i][j] 为 'X' 或 'O'*/
        void LC130_solve(vector<vector<char>>& board);
        //深度优先搜素
        void LC130_dfs(vector<vector<char>>&board,int n,int m,int i,int j);
    public:
        /*LeetCode 130 被围绕的区域*/
        void Test_LC130_solve();
    };
    class LargeLand{
    private:
        vector<int>father;
        vector<int>size;
        int cols;
        int sets;
        /*给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
        返回执行此操作后，grid 中最大的岛屿面积是多少？
        岛屿 由一组上、下、左、右四个方向相连的 1 形成。
        示例 1:
        输入: grid = [[1, 0], [0, 1]]
        输出: 3
        解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
        示例 2:
        输入: grid = [[1, 1], [1, 0]]
        输出: 4
        解释: 将一格0变成1，岛屿的面积扩大为 4。
        示例 3:
        输入: grid = [[1, 1], [1, 1]]
        输出: 4
        解释: 没有0可以让我们变成1，面积依然为 4。
        提示：
        n == grid.length
        n == grid[i].length
        1 <= n <= 500
        grid[i][j] 为 0 或 1*/
        int LC827_largestIsland(vector<vector<int>>& grid);
        //建立并查集
        void Build(int n,int m,vector<vector<int>>&grid);
        //建立索引映射
        int Index(int i,int j);
        //查找元素i所在的集合
        int Find(int i);
        //将x所在集合与y所在集合合并
        void Unoin(int x,int y);
    public:
        LargeLand():sets(0){father.resize(250001,0);size.resize(250001,0);}
        //LeetCode 827 最大的人工岛
        void Test_LC827_largestIsland();
    private:
        /*洪水填充(常数时间复杂度比并查集好)*/
        int LC827_largestIsland2(vector<vector<int>>& grid);
        /*DFS*/
        void LC827_largestIsland2_DFS(vector<vector<int>>&grid,int n,int m,int i,int j,int id);
    };
    class Bricks{
    private:
        vector<vector<int>>grid;
        int n,m;
        /*有一个 m x n 的二元网格 grid ，其中 1 表示砖块，0 表示空白。砖块 稳定（不会掉落）的前提是：
        一块砖直接连接到网格的顶部，或者
        至少有一块相邻（4 个方向之一）砖块 稳定 不会掉落时
        给你一个数组 hits ，这是需要依次消除砖块的位置。每当消除 hits[i] = (rowi, coli) 
        位置上的砖块时，对应位置的砖块（若存在）会消失，
        然后其他的砖块可能因为这一消除操作而 掉落 。一旦砖块掉落，
        它会 立即 从网格 grid 中消失（即，它不会落在其他稳定的砖块上）。
        返回一个数组 result ，其中 result[i] 表示第 i 次消除操作对应掉落的砖块数目。
        注意，消除可能指向是没有砖块的空白位置，如果发生这种情况，则没有砖块掉落。
        示例 1：
        输入：grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
        输出：[2]
        解释：网格开始为：
        [[1,0,0,0]，
        [1,1,1,0]]
        消除 (1,0) 处加粗的砖块，得到网格：
        [[1,0,0,0]
        [0,1,1,0]]
        两个加粗的砖不再稳定，因为它们不再与顶部相连，也不再与另一个稳定的砖相邻，因此它们将掉落。得到网格：
        [[1,0,0,0],
        [0,0,0,0]]
        因此，结果为 [2] 。
        示例 2：
        输入：grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
        输出：[0,0]
        解释：网格开始为：
        [[1,0,0,0],
        [1,1,0,0]]
        消除 (1,1) 处加粗的砖块，得到网格：
        [[1,0,0,0],
        [1,0,0,0]]
        剩下的砖都很稳定，所以不会掉落。网格保持不变：
        [[1,0,0,0], 
        [1,0,0,0]]
        接下来消除 (1,0) 处加粗的砖块，得到网格：
        [[1,0,0,0],
        [0,0,0,0]]
        剩下的砖块仍然是稳定的，所以不会有砖块掉落。
        因此，结果为 [0,0] 。
        提示：
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 200
        grid[i][j] 为 0 或 1
        1 <= hits.length <= 4 * 104
        hits[i].length == 2
        0 <= xi <= m - 1
        0 <= yi <= n - 1
        所有 (xi, yi) 互不相同*/
        vector<int> LC803_hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits);
        int LC803_hitBricks_DFS(int i,int j);
        bool LC803_hitBricks_worth(int i,int j);
    public:
        /*LeetCode 803 打砖块*/
        void Test_LC803_hitBricks();
    };
}