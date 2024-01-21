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
        /*i�Ž�����ϲ飬һֱ�鵽������*/
        int Check_find(int i);
        /*�ж�����Ԫ���Ƿ���ͬһ����*/
        bool Check_isSameSet(int x,int y);
        //�ϲ�����Ԫ�����ڵļ���
        void Check_union(int x,int y);
    public:
        /*���鼯*/
        void Test_Check();
    };
    class ChSet{
    private:
        vector<int>father;
        int sets;
        /*n �����������������е� 2n ����λ�ϣ���Ҫǣ���Է����֡�
        �˺���λ��һ���������� row ��ʾ��
        ���� row[i] �����ڵ� i ����λ�ϵ��˵� ID��
        �����ǰ�˳���ţ���һ���� (0, 1)���ڶ����� (2, 3)��
        �Դ����ƣ����һ���� (2n-2, 2n-1)��
        ���� ���ٽ�����λ�Ĵ������Ա�ÿ�����¿��Բ�������һ�� 
        ÿ�ν�����ѡ���������ˣ�������վ����������λ��
        ʾ�� 1:
        ����: row = [0,2,1,3]
        ���: 1
        ����: ֻ��Ҫ����row[1]��row[2]��λ�ü��ɡ�
        ʾ�� 2:
        ����: row = [3,2,0,1]
        ���: 0
        ����: ���轻����λ�����е����¶��Ѿ�������ǣ���ˡ�
        ��ʾ:
        2n == row.length
        2 <= n <= 30
        n ��ż��
        0 <= row[i] < 2n
        row ������Ԫ�ؾ����ظ�*/
        int LC765_minSwapsCouples(vector<int>& row);
        void LC765_build(int n);
        int LC756_find(int i);
        void LC765_Union(int x,int y);
    public:
        ChSet():sets(0){father.resize(31,0);}
        /*LeetCode 765 ����ǣ��*/
        void Test_LC765_minSwapsCouples();
    private:
        /*��������ַ��� X �е�������ͬλ�õ���ĸ��ʹ�������ַ��� Y ��ȣ�
        ��ô�� X �� Y �����ַ������ơ�����������ַ�����������ȵģ�������Ҳ�����Ƶġ�
        ���磬"tars" �� "rats" �����Ƶ� (���� 0 �� 2 ��λ��)�� 
        "rats" �� "arts" Ҳ�����Ƶģ����� "star" ���� "tars"��"rats"���� "arts" ���ơ�
        ��֮������ͨ���������γ������������飺{"tars", "rats", "arts"} 
        �� {"star"}��ע�⣬"tars" �� "arts" ����ͬһ���У���ʹ���ǲ������ơ�
        ��ʽ�ϣ���ÿ������ԣ�Ҫȷ��һ�����������У�
        ֻ��Ҫ����ʺ͸���������һ���������ơ�
        ����һ���ַ����б� strs���б��е�ÿ���ַ������� 
        strs �����������ַ�����һ����ĸ��λ�ʡ�
        ���� strs ���ж��ٸ������ַ����飿
        ʾ�� 1��
        ���룺strs = ["tars","rats","arts","star"]
        �����2
        ʾ�� 2��
        ���룺strs = ["omv","ovm"]
        �����1
        ��ʾ��
        1 <= strs.length <= 300
        1 <= strs[i].length <= 300
        strs[i] ֻ����Сд��ĸ��
        strs �е����е��ʶ�������ͬ�ĳ��ȣ����Ǳ˴˵���ĸ��λ�ʡ�*/
        int LC839_numSimilarGroups(vector<string>& strs);
    public:
        /*LeetCode 839 ���Ƶ��ַ�����*/
        void Test_LC839_numSimilarGroups();
    };
    class AllPeople{
    private:
        /*���鼯*/
        vector<int>father;
        /*���鼯���*/
        vector<bool>secret;
    public:
        /*��ʼ�����鼯*/
        AllPeople(){father.resize(100001,0);secret.resize(100001,false);} 
    private:
        /*�������鼯*/
        void Build(int n,int first);
        /*���Ҳ��鼯��Ԫ��i���ڵļ���*/
        int find(int i);
        /*��Ԫ��x��Ԫ��y�ϲ���ͬһ��������*/
        void Union(int x,int y);
        /*����һ������ n ����ʾ�� n ��ר�Ҵ� 0 �� n - 1 ��š�
        �������һ���±�� 0 ��ʼ�Ķ�ά�������� meetings ��
        ���� meetings[i] = [xi, yi, timei] ��ʾר�� xi ��ר�� yi ��ʱ�� timei Ҫ��һ���ᡣ
        һ��ר�ҿ���ͬʱ�μ� �ೡ���� ����󣬸���һ������ firstPerson ��
        ר�� 0 ��һ�� ���� �����������ʱ�� 0 ��������ܷ������ר�� firstPerson ��
        ���ţ�������ܻ���ÿ����֪��������ܵ�ר�Ҳμӻ���ʱ���д���������ʽ�ı���ǣ�
        ÿ�λ��飬���ר�� xi ��ʱ�� timei ʱ֪��������ܣ���ô��������ר�� yi ����������ܣ���֮��Ȼ��
        ���ܹ����� ˲ʱ���� �ġ�Ҳ����˵����ͬһʱ�䣬
        һ��ר�Ҳ�����Խ��յ����ܣ�����������������������ר�ҷ���
        �����л��鶼����֮�󣬷�������֪��������ܵ�ר���б�����԰� �κ�˳�� ���ش𰸡�
        ʾ�� 1��
        ���룺n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
        �����[0,1,2,3,5]
        ���ͣ�
        ʱ�� 0 ��ר�� 0 ��������ר�� 1 ����
        ʱ�� 5 ��ר�� 1 ��������ר�� 2 ����
        ʱ�� 8 ��ר�� 2 ��������ר�� 3 ����
        ʱ�� 10 ��ר�� 1 ��������ר�� 5 ����
        ��ˣ������л��������ר�� 0��1��2��3 �� 5 ����֪��������ܡ�
        ʾ�� 2��
        ���룺n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
        �����[0,1,3]
        ���ͣ�
        ʱ�� 0 ��ר�� 0 ��������ר�� 3 ����
        ʱ�� 2 ��ר�� 1 ��ר�� 2 ����֪��������ܡ�
        ʱ�� 3 ��ר�� 3 ��������ר�� 0 ��ר�� 1 ����
        ��ˣ������л��������ר�� 0��1 �� 3 ����֪��������ܡ�
        ʾ�� 3��
        ���룺n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
        �����[0,1,2,3,4]
        ���ͣ�
        ʱ�� 0 ��ר�� 0 ��������ר�� 1 ����
        ʱ�� 1 ��ר�� 1 ��������ר�� 2 ����ר�� 2 ��������ר�� 3 ����
        ע�⣬ר�� 2 �������յ����ܵ�ͬһʱ���������ܡ�
        ʱ�� 2 ��ר�� 3 ��������ר�� 4 ����
        ��ˣ������л��������ר�� 0��1��2��3 �� 4 ����֪��������ܡ�
        ��ʾ��
        2 <= n <= 105
        1 <= meetings.length <= 10^5
        meetings[i].length == 3
        0 <= xi, yi <= n - 1
        xi != yi
        1 <= time[i] <= 10^5
        1 <= firstPerson <= n - 1*/
        vector<int>LC2092_findAllPeople(int n,vector<vector<int>>&meeting,int first);  
    public:
        /*LeetCode 2092 �ҳ�����֪�����ܵ�ר��*/
        void Test_LC2092_findAllPeople();
    };
    class GoodPaths{
    private:
        /*����һ�� n ���ڵ��������ͨ�����޻���ͼ����
        �ڵ��Ŵ� 0 �� n - 1 ��ǡ���� n - 1 ���ߡ�
        ����һ������Ϊ n �±�� 0 ��ʼ���������� vals ��
        �ֱ��ʾÿ���ڵ��ֵ��ͬʱ����һ����ά�������� edges 
        ���� edges[i] = [ai, bi] ��ʾ�ڵ� ai �� bi ֮����һ�� ���� �ߡ�
        һ�� ��·�� ��Ҫ��������������
        ��ʼ�ڵ�ͽ����ڵ��ֵ ��ͬ ��
        ��ʼ�ڵ�ͽ����ڵ��м�����нڵ�ֵ�� 
        С�ڵ��� ��ʼ�ڵ��ֵ��Ҳ����˵��ʼ�ڵ��ֵӦ����·�������нڵ�����ֵ����
        ���㷵�ز�ͬ��·������Ŀ��
        ע�⣬һ��·�����������·������ ͬһ ·����
        �ȷ�˵�� 0 -> 1 �� 1 -> 0 ��Ϊͬһ��·���������ڵ�Ҳ��Ϊһ���Ϸ�·����
        ʾ�� 1��
        ���룺vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
        �����6
        ���ͣ��ܹ��� 5 �������ڵ�ĺ�·����
        ���� 1 ����·����1 -> 0 -> 2 -> 4 ��
        ���������·�� 4 -> 2 -> 0 -> 1 ��Ϊ�� 1 -> 0 -> 2 -> 4 һ����·����
        ע�� 0 -> 2 -> 3 ����һ����·������Ϊ vals[2] > vals[0] ��
        ʾ��2��
        ���룺vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
        �����7
        ���ͣ��ܹ��� 5 �������ڵ�ĺ�·����
        ���� 2 ����·����0 -> 1 �� 2 -> 3 ��
        ʾ�� 3��
        ���룺vals = [1], edges = []
        �����1
        ���ͣ������ֻ��һ���ڵ㣬����ֻ��һ����·����
        ��ʾ��
        n == vals.length
        1 <= n <= 3 * 104
        0 <= vals[i] <= 105
        edges.length == n - 1
        edges[i].length == 2
        0 <= ai, bi < n
        ai != bi
        edges ��ʾһ�úϷ�������*/
        vector<int>father_;
        vector<int>maxcnt_;
    public:
        GoodPaths(){father_.resize(10001,0);maxcnt_.resize(10001,0);}
    private:
        /*��ʼ�����鼯*/
        void Build(int n);
        /*����Ԫ��i���ĸ�������*/
        int Find(int i);
        /*�ϲ��������������������ֵ�����ĳ˻�*/
        int Unoin(int x,int y,vector<int>&vals);
        /*�������*/
        int LC2421_numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges);
    public:
        /*LeetCode ��·������Ŀ*/
        void Test_LC2421_numberOfGoodPaths();
    };
    class MalwareSpread{
    private:
        /*���鼯�Ĺ�����Ϣ*/
        vector<int>father_;
        /*������*/
        vector<bool>virus_;
        /*��ǰԴͷɾ�������ȶ�������*/
        vector<int>cnts_;
        /*���ϵĴ�С*/
        vector<int>size_;
        /*���ϵı�ǩ
        -1����ʾû�б���Ⱦ
        -2����ʾ����Ⱦ�Ĵ�������1���޷�����
        >=0����ʾ��ǰֻ��һ�����Ⱦ����Ⱦ�������Ϊ��ֵ*/
        vector<int>infect_;
    public:
        MalwareSpread();
    private:
        /*����һ���� n ���ڵ���ɵ����磬�� n x n ���ڽӾ��� graph ��ʾ��
        �ڽڵ������У�ֻ�е� graph[i][j] = 1 ʱ���ڵ� i �ܹ�ֱ�����ӵ���һ���ڵ� j��
        һЩ�ڵ� initial ��������������Ⱦ��ֻҪ�����ڵ�ֱ�����ӣ�
        ����������һ���ڵ��ܵ���������ĸ�Ⱦ����ô�����ڵ㶼�������������Ⱦ��
        ���ֶ�������Ĵ�����������ֱ��û�и���Ľڵ���Ա����ַ�ʽ��Ⱦ��
        ���� M(initial) ���ڶ������ֹͣ����֮�����������и�Ⱦ������������սڵ�����
        ���ǿ��Դ� initial ��ɾ��һ���ڵ㣬����ȫ�Ƴ��ýڵ��Լ��Ӹýڵ㵽�κ������ڵ���κ����ӡ�
        �뷵���Ƴ����ܹ�ʹ M(initial) ��С���Ľڵ㡣����ж���ڵ������������������� ��С�Ľڵ� ��
        ʾ�� 1��
        ���룺graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
        �����0
        ʾ�� 2��
        ���룺graph = [[1,1,0],[1,1,1],[0,1,1]], initial = [0,1]
        �����1
        ʾ�� 3��
        ���룺graph = [[1,1,0,0],[1,1,1,0],[0,1,1,1],[0,0,1,1]], initial = [0,1]
        �����1
        ��ʾ��
        n == graph.length
        n == graph[i].length
        2 <= n <= 300
        graph[i][j] �� 0 �� 1.
        graph[i][j] == graph[j][i]
        graph[i][i] == 1
        1 <= initial.length < n
        0 <= initial[i] <= n - 1
        initial ��ÿ����������ͬ*/
        int LC928_minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial);
        /*�������鼯*/
        void Build(int n,vector<int>&initial);
        /*����Ԫ��i���ĸ�������*/
        int Find(int i);
        /*�ϲ�Ԫ��x��Ԫ��y���ڵļ���*/
        void Unoin(int x,int y);
    public:
        /*LeetCode 928 �������ٶ�������Ĵ���*/
        void Test_LC928_minMalwareSpread();
    };
    class Islands{
    private:
        //���鼯������Ϣ
        vector<int>father;
        //�����������������Ԫ�ص�ӳ��ֵ
        int cols;
        //���ϵĸ������������ؽ��
        int sets;
        /*����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
        �������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γɡ�
        ���⣬����Լ��������������߾���ˮ��Χ��
        ʾ�� 1��
        ���룺grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
        ]
        �����1
        ʾ�� 2��
        ���룺grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
        ]
        �����3
        ��ʾ��
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 300
        grid[i][j] ��ֵΪ '0' �� '1'*/
        //���鼯
        int numIslands1(vector<vector<char>>& grid);
        //�������鼯
        void Build(int n,int m,vector<vector<char>>&grid);
        //����Ԫ��i���ڵļ���
        int Find(int i);
        //�ϲ�x��y���ڵļ���
        void Unoin(int x,int y);
        //����ӳ��ֵ(��������)
        int Index(int i,int j);
        //��ˮ���
        int numIslands2(vector<vector<char>>& grid);
        //��ˮDFS
        void numIslands2_DFS(vector<vector<char>>&grid,int i,int j);
    public:
        Islands():sets(0){father.resize(90001,0);}
        /*LeetCode 200 ��������*/
        void Test_LC200_numIslands();
    };
    class Solve{
    private:
        /*����һ�� m x n �ľ��� board ���������ַ� 'X' �� 'O' ���ҵ����б� 'X' Χ�Ƶ����򣬲�����Щ���������е� 'O' �� 'X' ��䡣
        ʾ�� 1��
        ���룺board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
        �����[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
        ���ͣ���Χ�Ƶ����䲻������ڱ߽��ϣ����仰˵���κα߽��ϵ� 'O' �����ᱻ���Ϊ 'X'�� 
        �κβ��ڱ߽��ϣ�����߽��ϵ� 'O' ������ 'O' ���ն��ᱻ���Ϊ 'X'���������Ԫ����ˮƽ��ֱ�������ڣ���������ǡ��������ġ�
        ʾ�� 2��
        ���룺board = [["X"]]
        �����[["X"]]
        ��ʾ��
        m == board.length
        n == board[i].length
        1 <= m, n <= 200
        board[i][j] Ϊ 'X' �� 'O'*/
        void LC130_solve(vector<vector<char>>& board);
        //�����������
        void LC130_dfs(vector<vector<char>>&board,int n,int m,int i,int j);
    public:
        /*LeetCode 130 ��Χ�Ƶ�����*/
        void Test_LC130_solve();
    };
    class LargeLand{
    private:
        vector<int>father;
        vector<int>size;
        int cols;
        int sets;
        /*����һ����СΪ n x n �����ƾ��� grid ����� ֻ�ܽ�һ�� 0 ��� 1 ��
        ����ִ�д˲�����grid �����ĵ�������Ƕ��٣�
        ���� ��һ���ϡ��¡������ĸ����������� 1 �γɡ�
        ʾ�� 1:
        ����: grid = [[1, 0], [0, 1]]
        ���: 3
        ����: ��һ��0���1��������ͨ����С���õ����Ϊ 3 �ĵ��졣
        ʾ�� 2:
        ����: grid = [[1, 1], [1, 0]]
        ���: 4
        ����: ��һ��0���1��������������Ϊ 4��
        ʾ�� 3:
        ����: grid = [[1, 1], [1, 1]]
        ���: 4
        ����: û��0���������Ǳ��1�������ȻΪ 4��
        ��ʾ��
        n == grid.length
        n == grid[i].length
        1 <= n <= 500
        grid[i][j] Ϊ 0 �� 1*/
        int LC827_largestIsland(vector<vector<int>>& grid);
        //�������鼯
        void Build(int n,int m,vector<vector<int>>&grid);
        //��������ӳ��
        int Index(int i,int j);
        //����Ԫ��i���ڵļ���
        int Find(int i);
        //��x���ڼ�����y���ڼ��Ϻϲ�
        void Unoin(int x,int y);
    public:
        LargeLand():sets(0){father.resize(250001,0);size.resize(250001,0);}
        //LeetCode 827 �����˹���
        void Test_LC827_largestIsland();
    private:
        /*��ˮ���(����ʱ�临�ӶȱȲ��鼯��)*/
        int LC827_largestIsland2(vector<vector<int>>& grid);
        /*DFS*/
        void LC827_largestIsland2_DFS(vector<vector<int>>&grid,int n,int m,int i,int j,int id);
    };
    class Bricks{
    private:
        vector<vector<int>>grid;
        int n,m;
        /*��һ�� m x n �Ķ�Ԫ���� grid ������ 1 ��ʾש�飬0 ��ʾ�հס�ש�� �ȶ���������䣩��ǰ���ǣ�
        һ��שֱ�����ӵ�����Ķ���������
        ������һ�����ڣ�4 ������֮һ��ש�� �ȶ� �������ʱ
        ����һ������ hits ��������Ҫ��������ש���λ�á�ÿ������ hits[i] = (rowi, coli) 
        λ���ϵ�ש��ʱ����Ӧλ�õ�ש�飨�����ڣ�����ʧ��
        Ȼ��������ש�������Ϊ��һ���������� ���� ��һ��ש����䣬
        ���� ���� ������ grid ����ʧ���������������������ȶ���ש���ϣ���
        ����һ������ result ������ result[i] ��ʾ�� i ������������Ӧ�����ש����Ŀ��
        ע�⣬��������ָ����û��ש��Ŀհ�λ�ã�������������������û��ש����䡣
        ʾ�� 1��
        ���룺grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
        �����[2]
        ���ͣ�����ʼΪ��
        [[1,0,0,0]��
        [1,1,1,0]]
        ���� (1,0) ���Ӵֵ�ש�飬�õ�����
        [[1,0,0,0]
        [0,1,1,0]]
        �����Ӵֵ�ש�����ȶ�����Ϊ���ǲ����붥��������Ҳ��������һ���ȶ���ש���ڣ�������ǽ����䡣�õ�����
        [[1,0,0,0],
        [0,0,0,0]]
        ��ˣ����Ϊ [2] ��
        ʾ�� 2��
        ���룺grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
        �����[0,0]
        ���ͣ�����ʼΪ��
        [[1,0,0,0],
        [1,1,0,0]]
        ���� (1,1) ���Ӵֵ�ש�飬�õ�����
        [[1,0,0,0],
        [1,0,0,0]]
        ʣ�µ�ש�����ȶ������Բ�����䡣���񱣳ֲ��䣺
        [[1,0,0,0], 
        [1,0,0,0]]
        ���������� (1,0) ���Ӵֵ�ש�飬�õ�����
        [[1,0,0,0],
        [0,0,0,0]]
        ʣ�µ�ש����Ȼ���ȶ��ģ����Բ�����ש����䡣
        ��ˣ����Ϊ [0,0] ��
        ��ʾ��
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 200
        grid[i][j] Ϊ 0 �� 1
        1 <= hits.length <= 4 * 104
        hits[i].length == 2
        0 <= xi <= m - 1
        0 <= yi <= n - 1
        ���� (xi, yi) ������ͬ*/
        vector<int> LC803_hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits);
        int LC803_hitBricks_DFS(int i,int j);
        bool LC803_hitBricks_worth(int i,int j);
    public:
        /*LeetCode 803 ��ש��*/
        void Test_LC803_hitBricks();
    };
}