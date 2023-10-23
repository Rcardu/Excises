#include"../unltle.h"
namespace CreatGraph{
using std::vector;
using std::cout;
using std::endl;
using std::string;
    class Graph{
    private:
        const int MAXN=11;
        //ֻ����ʽǰ���Ƿ�ʽ��ͼ��Ҫ�������
        //�������ͼ�����������m���ߣ�������Ҫ׼��m*2
        //��Ϊһ���������Ҫ��������
        const int MAXM=21;
    private:
        /*�ڽӾ����ͼ��ʾ*/
        vector<vector<int>>Graph1;
        /*�ڽӱ��ͼ��ʾ*/
        //vector<vector<int>>Graph2;
        /*��Ȩͼ���ڽӱ�*/
        vector<vector<vector<int>>>Graph2;
        /*��ʽǰ���ǽ�ͼ*/
        vector<int>head;
        int cnt;
        vector<int>next;
        vector<int>tos;
        //�����Ȩ�������Ȩ������
        vector<int>weith;
    public:
        Graph();
    private:
        void Build(int n);
        //����ͼ�Ľ���
        void DirectGraph(vector<vector<int>>&edges);
        //����ͼ�Ľ���
        void UndirectGraph(vector<vector<int>>&edges);
        //��ӡͼ
        void Traversal(int n);
    private:
        /*��ʽǰ���Ǽӱ�*/
        void addEdge(int u,int v,int w);
    public:
        void Test_Graph();
    };
    class Topological{
    private:
        /*�������ܹ��� numCourses �ſ���Ҫѡ����Ϊ 0 �� numCourses - 1��
        ����һ������ prerequisites ������ prerequisites[i] = [ai, bi] ��
        ��ʾ��ѡ�޿γ� ai ǰ ���� ��ѡ�� bi ��
        ���磬��Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��������һ��ƥ������ʾ��[0,1] ��
        ������Ϊ��ѧ�����пγ������ŵ�ѧϰ˳�򡣿��ܻ��ж����ȷ��˳��
        ��ֻҪ���� ����һ�� �Ϳ����ˡ����������������пγ̣����� һ�������� ��
        ʾ�� 1��
        ���룺numCourses = 2, prerequisites = [[1,0]]
        �����[0,1]
        ���ͣ��ܹ��� 2 �ſγ̡�Ҫѧϰ�γ� 1������Ҫ����ɿγ� 0����ˣ���ȷ�Ŀγ�˳��Ϊ [0,1] ��
        ʾ�� 2��
        ���룺numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
        �����[0,2,1,3]
        ���ͣ��ܹ��� 4 �ſγ̡�Ҫѧϰ�γ� 3����Ӧ������ɿγ� 1 �Ϳγ� 2��
        ���ҿγ� 1 �Ϳγ� 2 ��Ӧ�����ڿγ� 0 ֮��
        ��ˣ�һ����ȷ�Ŀγ�˳���� [0,1,2,3] ����һ����ȷ�������� [0,2,1,3] ��
        ʾ�� 3��
        ���룺numCourses = 1, prerequisites = []
        �����[0]
        ��ʾ��
        1 <= numCourses <= 2000
        0 <= prerequisites.length <= numCourses * (numCourses - 1)
        prerequisites[i].length == 2
        0 <= ai, bi < numCourses
        ai != bi
        ����[ai, bi] ������ͬ*/
        vector<int>LC210_findOrder(int numCourses, vector<vector<int>>& prerequisites);
    public:
        /*LeetCode 210 �γ̱�*/
        void Test_LC210_findOrder();
    };
    class LG_Topological{
    private:
        /*�����޻�ͼ����n���㣬m���ߡ�������ͼ�ֵ�����С����������Ľ����
        �ֵ�����Сָϣ���ź���Ľ���У��ȽϿ�ǰ�����־�����С��*/
        const int MAXN=100001;
        const int MAXM=100001;
        //��ʽǰ���ǽ�ͼ
        vector<int>head;
        vector<int>next;
        vector<int>tos;
        int cnt;
        //��������,С����
        vector<int>heap;
        int heap_size;
        //��������,��ȱ�
        vector<int>indegree;
        //�ռ���������Ľ��
        vector<int>ans;
        const int n,m;
    private:
        //��ʼ��
        void Build(int n);
        //��ӱ�
        void addEdge(int u,int v);
    private:
        /*�����*/
        void Push(int num);
        void Swap(int n1,int n2);
        int Pop();
        bool isEmpty();
    private:
        /*��������*/
        void topSort();
    private:
        /*��Ҫ����*/
        void LG_U107394();
    public:
        LG_Topological():n(0),m(0){;}
        //��� U107394 ��������ģ��
        void Test_LG_U107394();
    };
    class alienOrder{
        /*����һ��ʹ��Ӣ����ĸ�����������ԣ��������Ե���ĸ˳����Ӣ��˳��ͬ��
        ����һ���ַ����б� words ����Ϊ�������ԵĴʵ䣬
        words �е��ַ����Ѿ� �����������Ե���ĸ˳����������� ��
        ������ݸôʵ仹ԭ������������֪����ĸ˳��
        �� ����ĸ����˳�� ���С��������ںϷ���ĸ˳��
        ���� "" �������ڶ��ֿ��ܵĺϷ���ĸ˳�򣬷������� ����һ�� ˳�򼴿ɡ�
        �ַ��� s �ֵ�˳��С�� �ַ��� t �����������
        �ڵ�һ����ͬ��ĸ������� s �е���ĸ�������������Ե���
        ĸ˳����λ�� t ����ĸ֮ǰ����ô s ���ֵ�˳��С�� t ��
        ���ǰ�� min(s.length, t.length) ��ĸ����ͬ��
        ��ô s.length < t.length ʱ��s ���ֵ�˳��ҲС�� t ��
        ʾ�� 1��
        ���룺words = ["wrt","wrf","er","ett","rftt"]
        �����"wertf"
        ʾ�� 2��
        ���룺words = ["z","x"]
        �����"zx"
        ʾ�� 3��
        ���룺words = ["z","x","z"]
        �����""
        ���ͣ������ںϷ���ĸ˳����˷��� "" ��
        ��ʾ��
        1 <= words.length <= 100
        1 <= words[i].length <= 100
        words[i] ����СдӢ����ĸ���*/
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
        /*LCR 114 ���Ǵʵ�*/
        void Test_LCR114_alienOrder();
    private:
        /*����Ҫ��Сд��ĸ���һ��Ŀ���ַ��� target�� 
        ��ʼ��ʱ�������� target.length �� '?' �Ǻ���ɡ�������һ��Сд��ĸӡ�� stamp��
        ��ÿ���غϣ�����Խ�ӡ�·��������ϣ����������е�ÿ����ĸ�滻Ϊӡ���ϵ���Ӧ��ĸ��
        �������Խ��� 10 * target.length  ���غϡ�
        �ٸ����ӣ������ʼ����Ϊ "?????"�������ӡ�� stamp �� "abc"����ô�ڵ�һ�غϣ�
        ����Եõ� "abc??"��"?abc?"��"??abc"������ע�⣬ӡ�±�����ȫ���������еı߽��ڲ��ܸ���ȥ����
        �������ӡ�����У���ô����һ�����飬��������ÿ���غ��б�ӡ�µ��������ĸ��������ɡ�
        �������ӡ�����У��ͷ���һ�������顣
        ���磬��������� "ababc"��ӡ���� "abc"����ô���ǾͿ��Է�������� 
        "?????" -> "abc??" -> "ababc" ���Ӧ�Ĵ� [0, 2]��
        ���⣬�������ӡ�����У���ô��Ҫ��֤������ 10 * target.length ���غ�����ɡ�
        �κγ��������ֵĴ𰸽��������ܡ�
        ʾ�� 1��
        ���룺stamp = "abc", target = "ababc"
        �����[0,2]
        ��[1,0,2] �Լ�����һЩ���ܵĽ��Ҳ����Ϊ�𰸱����ܣ�
        ʾ�� 2��
        ���룺stamp = "abca", target = "aabcaca"
        �����[3,0,1]
        ��ʾ��
        1 <= stamp.length <= target.length <= 1000
        stamp �� target ֻ����Сд��ĸ��*/
        vector<int>LC936_movesToStamp(string stamp, string target);
    public:
        /*LeetCode 936 ��ӡ����*/
        void Test_LC936_movesToStamp();
    };
}
/// @brief 
namespace FoodLine{
using namespace std;
static int MAXN=5001;
static int MAXM=500001;
static int MOD=80112002;
//��ʽǰ����
vector<int>Head(MAXN,0);
vector<int>Next(MAXM,0);
vector<int>To(MAXM,0);
int cnt;
//����
vector<int>Indegree(MAXN,0);
vector<int>Food(MAXN,0);
//���У���������ͼ
vector<int>que(MAXN,0);
int size;
int n,m;

    //��ʼ��
    void Build(int n){
        cnt=1;
        size=0;
        for(int i=0;i<=n;i++){
            Head[i]=0;
            Indegree[i]=0;
            Food[i]=0;
        }
    }
    //��ͼ
    void addEdge(int u,int v){
        Next[cnt]=Head[u];
        To[cnt]=v;
        Head[u]=cnt++;
    }
    //��������
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
            //����˽ڵ�û���ڽӽ�㣨�����˽ڵ�Ϊ���һ����㣩
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
        /*��һ�� n ������Ϊʵ����󣬴� 0 �� n - 1 ��ţ�����ÿ���˶��в�ͬ��Ŀ��Ǯ���Լ���ͬ�̶ȵİ���ֵ��quietness����
        Ϊ�˷�����������ǽ����Ϊ x ���˼��Ϊ "person x "��
        ����һ������ richer ������ richer[i] = [ai, bi] ��ʾ person ai �� person bi ����Ǯ�������һ���������� quiet ��
        ���� quiet[i] �� person i �İ���ֵ��richer �������������� �߼���Ǣ��Ҳ����˵���� person x �� person y ����Ǯ��ͬʱ��
        ������� person y �� person x ����Ǯ����� ����
        ���ڣ�����һ���������� answer ��Ϊ�𰸣����� answer[x] = y ��ǰ���ǣ�������ӵ�е�Ǯ�϶������� person x �����У�
        person y ��������ˣ�Ҳ���ǰ���ֵ quiet[y] ��С���ˣ���
        ʾ�� 1��
        ���룺richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
        �����[5,5,2,5,4,5,6,7]
        ���ͣ� 
        answer[0] = 5��
        person 5 �� person 3 �и����Ǯ��person 3 �� person 1 �и����Ǯ��person 1 �� person 0 �и����Ǯ��
        Ψһ��Ϊ�������нϵ͵İ���ֵ quiet[x]�������� person 7��
        ����Ŀǰ����������Ƿ�� person 0 ����Ǯ��
        answer[7] = 7��
        ������ӵ�е�Ǯ�϶������� person 7 �����У�����ܰ��� person 3��4��5��6 �Լ� 7����
        ������нϵͰ���ֵ quiet[x]�������� person 7��
        �����Ĵ�Ҳ���������Ƶ����������͡�
        ʾ�� 2��
        ���룺richer = [], quiet = [0]
        �����[0]
        ��ʾ��
        n == quiet.length
        1 <= n <= 500
        0 <= quiet[i] < n
        quiet ������ֵ ������ͬ
        0 <= richer.length <= n * (n - 1) / 2
        0 <= ai, bi < n
        ai != bi
        richer �е��������� ������ͬ
        �� richer �Ĺ۲����߼�����һ�µ�*/
        vector<int>LC851_loudAndRich(vector<vector<int>>& richer, vector<int>& quiet);
    public:
        /*LeetCode 851 ���ֺ͸���*/
        void Test_LC851_loudAndRich();
    };
    class mumTime{
    private:
        /*����һ������ n ����ʾ�� n �ڿΣ��γ̱�Ŵ� 1 �� n ��
        ͬʱ����һ����ά�������� relations ������ relations[j] = [prevCoursej, nextCoursej] ��
        ��ʾ�γ� prevCoursej �����ڿγ� nextCoursej ֮ǰ ��ɣ����޿εĹ�ϵ����
        ͬʱ����һ���±�� 0 ��ʼ���������� time ������ time[i] ��ʾ��ɵ� (i+1) �ſγ���Ҫ���ѵ� �·� ����
        ����������¹������������пγ�����Ҫ�� ���� �·�����
        ���һ�ſε��������޿ζ��Ѿ���ɣ�������� ���� ʱ�俪ʼ���ſγ̡�
        ����� ͬʱ �� �����ſγ� ��
        ���㷵��������пγ�����Ҫ�� ���� �·�����
        ע�⣺�������ݱ�֤һ������������пγ̣�Ҳ�������޿εĹ�ϵ����һ�������޻�ͼ����
        ʾ�� 1:
        ���룺n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
        �����8
        ���ͣ���ͼչʾ��������������ʾ�����޹�ϵͼ���Լ����ÿ�ſγ���Ҫ���ѵ�ʱ�䡣
        ��������·� 0 ͬʱ��ʼ�γ� 1 �� 2 ��
        �γ� 1 ���� 3 ���£��γ� 2 ���� 2 ���¡�
        ���ԣ����翪ʼ�γ� 3 ��ʱ�����·� 3 ��������пγ�����ʱ��Ϊ 3 + 5 = 8 ���¡�
        ʾ�� 2��
        ���룺n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
        �����12
        ���ͣ���ͼչʾ��������������ʾ�����޹�ϵͼ���Լ����ÿ�ſγ���Ҫ���ѵ�ʱ�䡣
        ��������·� 0 ͬʱ��ʼ�γ� 1 ��2 �� 3 ��
        ���·� 1��2 �� 3 �ֱ���������ſγ̡�
        �γ� 4 ���ڿγ� 3 ֮��ʼ��Ҳ���� 3 ���º󡣿γ� 4 �� 3 + 4 = 7 ����ɡ�
        �γ� 5 ���ڿγ� 1��2��3 �� 4 ֮��ʼ��Ҳ������ max(1,2,3,7) = 7 �¿�ʼ��
        ����������пγ����������ʱ��Ϊ 7 + 5 = 12 ���¡�
        ��ʾ��
        1 <= n <= 5 * 104
        0 <= relations.length <= min(n * (n - 1) / 2, 5 * 104)
        relations[j].length == 2
        1 <= prevCoursej, nextCoursej <= n
        prevCoursej != nextCoursej
        ���е����޿γ̶� [prevCoursej, nextCoursej] ���� ������ͬ �ġ�
        time.length == n
        1 <= time[i] <= 104
        ���޿γ�ͼ��һ�������޻�ͼ��*/
        int LC2050_minimumTime(int n, vector<vector<int>>& relations, vector<int>& time);
    public:
        /*LeetCode 2050 ���пγ�III*/
        void Test_LC2050_minimumTime();
    };
    class Invitations{
    private:
        /*һ����˾׼����֯һ�����飬������������ n λԱ������˾׼����һ�� Բ�� �����ӣ��������� ������Ŀ ��Ա����
        Ա�����Ϊ 0 �� n - 1 ��ÿλԱ������һλ ϲ�� ��Ա����ÿλԱ�� ���ҽ��� ����������ϲ��Ա�����Աߣ�
        ���Ż�μӻ��顣ÿλԱ��ϲ����Ա�� ���� �����Լ���
        ����һ���±�� 0 ��ʼ���������� favorite ������ favorite[i] ��ʾ�� i λԱ��ϲ����Ա�������㷵�زμӻ���� ���Ա����Ŀ ��
        ʾ�� 1��
        ���룺favorite = [2,2,1,2]
        �����3
        ���ͣ�
        ��ͼչʾ�˹�˾����Ա�� 0��1 �� 2 �μӻ����Լ�������Բ���ϵ���λ��
        û�취��������Ա��������飬��ΪԱ�� 2 û�취ͬʱ���� 0��1 �� 3 Ա�����Աߡ�
        ע�⣬��˾Ҳ��������Ա�� 1��2 �� 3 �μӻ��顣
        �������μӻ����Ա����ĿΪ 3 ��
        ʾ�� 2��
        ���룺favorite = [1,2,0]
        �����3
        ���ͣ�
        ÿ��Ա������������һ��Ա��ϲ����Ա�������Թ�˾�������������˲μӻ����ǰ���������˶��μ��˻��顣
        ��λ����ͬͼ 1 ��ʾ��
        - Ա�� 0 ����Ա�� 2 �� 1 ֮�䡣
        - Ա�� 1 ����Ա�� 0 �� 2 ֮�䡣
        - Ա�� 2 ����Ա�� 1 �� 0 ֮�䡣
        �����������Ա����ĿΪ 3 ��
        ʾ�� 3��
        ���룺favorite = [3,0,1,4,1]
        �����4
        ���ͣ�
        ��ͼչʾ�˹�˾��������Ա�� 0��1��3 �� 4 �μӻ����Լ�������Բ���ϵ���λ��
        Ա�� 2 �޷��μӣ���Ϊ��ϲ����Ա�� 0 �Աߵ���λ�Ѿ���ռ���ˡ�
        ���Թ�˾ֻ�ܲ�����Ա�� 2 ��
        �μӻ�������Ա����ĿΪ 4 ��
        ��ʾ��
        n == favorite.length
        2 <= n <= 105
        0 <= favorite[i] <= n - 1
        favorite[i] != i*/
        int LC2127_maximumInvitations(vector<int>& favorite);
    public:
        /*LeetCode 2127 �μӻ�������Ա��*/
        void Test_LC2127_maximumInvitations();
    };
    //��С������
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
        //x��y�����������һ�����Ϸ���false������ϲ���������
        bool Union(int x,int y);
        void Kruskal_MST();
    public:
        void Test_Kruskal_MST();
    };
    //Prim�㷨
    class Prim{
    private:
    constexpr static int MAXN=5001;
    constexpr static int MAXM=20001;
    int n,m;
    private:
    //��
    vector<vector<int>>heap;
    int heap_size;
    private:
        //��ʼ��
        void Build(int n,int m);
        //����
        void Push(vector<int> num);
        //����
        int Pop();
        //����
        void Swap(int n1,int n2);
        //�п�
        bool Empty();
        void Prim_MST();
    public:
        Prim();
        void Test_Prim_MST();

    };
    class PrimPlus{
    /*Prim�㷨���Ż���
        1.С������ţ�����Ľڵ㣬����ڵ�Ļ��ѣ������ݵ���ڵ�Ļ�������֯С����
        2.С�����ﵯ����u�ڵ㣬����u�ڵ�Ļ���y����y�ۼӵ���Ȩ����ȥ��Ȼ�󿼲�u������ÿһ����
            ���裬u�����ıߣ�ȥ��v�ڵ㣬Ȩ��w
            A.���v�Ѿ��������ˣ����ֹ��������Ըı�
            B.���v����û�н�����ѣ����������¼��v��w��
            C.���v�ڶ���Ҽ�¼Ϊ��v��x��
                1��w<x������¼�¼Ϊ��v��w��Ȼ������ü�¼�ڶ��е�λ��
                2��w>=x�����Ըñ�
        3.�ظ�����2��ֱ��С����Ϊ��*/
        constexpr static int MAXN=5001;
        constexpr static int MAXM=40001;
        //��ʽ��ǰ��
        vector<int>head;
        vector<int>next;
        vector<int>tos;
        vector<int>weight;
        int cnt;
        //��
        vector<vector<int>>heap;
        int heap_size;
        //������������ʾ�ڵ���������е�λ�� 
        //�����ж�ÿ��Ԫ���Ƿ����
        vector<int>Where;
        //����
        int n,m;
        int usv,usw;
        int EdgeCnt;
        //��ʼ��
        void Build(int n);
        //��ʽ��ǰ�Ǽӱ�
        void addEgde(int u,int v,int w);
        //�ѵĽ��������
        void heapInsert(int i);
        //�ж��Ƿ�Ҫ���뻹�Ǹ��»��ߺ���
        void addOrUpdateOrIgnore(int ei);
        void Swap(int n1,int n2);
        bool Empty();
        //����
        void Pop();
        //����λ��
        void heapIfy(int i);
        //������
        void PrimPlus_MST();
    public:
        PrimPlus():cnt(0),heap_size(0){
            //�ڵ��ͷ��
            head.resize(MAXN);
            //�ڼ��ű�
            next.resize(MAXM);
            //���ĸ����
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
        /*LeetCode 1168  ˮ��Դ�����Ż�*/
        /*������һ����n�����ӣ�����ϣ��ͨ������ˮ���ķ�ʽ��Ϊ���з��ӹ�ˮ
        ����ÿ������i������������ѡ��һ��ֱ���ٷ����ڽ���ˮ��
        �ɱ�Ϊwells[i-1]��ע��-1����Ϊ������0��ʼ��
        ��һ���Ǵ���һ��ˮ������ܵ���ˮ������pipes�������ڷ��Ӽ�����ܵ��ĳɱ�
        ����ÿ��pipes[j]=[house1j,house2j,cost2j]
        �����ùܵ���house1j��house2j������һ��ĳɱ�
        �뷵�����з��Ӷ���ˮ����ͳɱ�*/
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
        /*����һ�� n ������ɵ�����ͼ�߼� edgeList ��
        ���� edgeList[i] = [ui, vi, disi] ��ʾ�� ui �͵� vi ֮����һ������Ϊ disi �ıߡ�
        ��ע�⣬������֮������� ����һ���� ��
        ����һ����ѯ����queries ������ queries[j] = [pj, qj, limitj] ��
        ��������Ƕ���ÿ����ѯ queries[j] ���ж��Ƿ���ڴ� pj �� qj ��·����
        ������·���ϵ�ÿһ���߶� �ϸ�С�� limitj ��
        ���㷵��һ�� �������� answer ������ answer.length == queries.length ��
        �� queries[j] �Ĳ�ѯ���Ϊ true ʱ�� answer �� j ��ֵΪ true ������Ϊ false ��
        ʾ�� 1��
        ���룺n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
        �����[false,true]
        ���ͣ���ͼΪ�������������ݡ�ע�⵽ 0 �� 1 ֮���������رߣ��ֱ�Ϊ 2 �� 16 ��
        ���ڵ�һ����ѯ��0 �� 1 ֮��û��С�� 2 �ıߣ��������Ƿ��� false ��
        ���ڵڶ�����ѯ����һ��·����0 -> 1 -> 2�������߶�С�� 5 �����������ѯ���Ƿ��� true ��
        ʾ�� 2��
        ���룺n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
        �����[true,false]
        ���ͣ���ͼΪ�������ݡ�
        ��ʾ��
        2 <= n <= 105
        1 <= edgeList.length, queries.length <= 105
        edgeList[i].length == 3
        queries[j].length == 3
        0 <= ui, vi, pj, qj <= n - 1
        ui != vi
        pj != qj
        1 <= disi, limitj <= 109
        ������֮������� ���� �ߡ�*/
        vector<bool> LC1697_distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries);
        void Build(int n);
        int Find(int i);
        void Unoin(int x,int y);
        bool isSameSet(int x,int y){return Find(x)==Find(y);}
    public:
        distanceLimitedPathsExist(){questions.resize(10000,vector<int>(4));father.resize(10000,0);}
        /*LeetCode 1697 ���߳������Ƶ�·���Ƿ����*/
        void Test_LC1697_distanceLimitedPathsExist();
    };

}
/*������ȱ���*/
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
        /*������������һ�ݴ�СΪ n x n �� ���� grid��
        �����ÿ�� ��Ԫ�� ���� 0 �� 1 ��Ǻ��ˡ����� 0 ������1 ����½�ء�
        �����ҳ�һ������Ԫ���������Ԫ�����������½�ص�Ԫ��ľ��������ģ�
        �����ظþ��롣���������ֻ��½�ػ��ߺ����뷵�� -1��
        ��������˵�ľ����ǡ������پ��롹�� Manhattan Distance����
        (x0, y0) �� (x1, y1) ��������Ԫ��֮��ľ����� |x0 - x1| + |y0 - y1| ��
        ʾ�� 1��
        ���룺grid = [[1,0,1],[0,0,0],[1,0,1]]
        �����2
        ���ͣ� 
        ����Ԫ�� (1, 1) ������½�ص�Ԫ��֮��ľ��붼�ﵽ���������Ϊ 2��
        ʾ�� 2��
        ���룺grid = [[1,0,0],[0,0,0],[0,0,0]]
        �����4
        ���ͣ� 
        ����Ԫ�� (2, 2) ������½�ص�Ԫ��֮��ľ��붼�ﵽ���������Ϊ 4��
        ��ʾ��
        n == grid.length
        n == grid[i].length
        1 <= n <= 100
        grid[i][j] ���� 0 ���� 1*/
        constexpr static int MAXN=101;
        constexpr static int MAXM=101;
        vector<vector<int>>que;
        vector<vector<bool>>visited;
        int l,r;
        /*i=0   (x-1,y)��
        i=1     (x,y+1)��
        i=2     (x+1,y)��
        i=3     (x,y-1)��*/
    private:
        int LC1162_maxDistance(vector<vector<int>>& grid);
    public:
        MaxDistance(){que.resize(MAXN*MAXM,vector<int>(2,0));visited.resize(MAXN,vector<bool>(MAXM));}
        /*LeetCode 1162 ��ͼ����*/
        void Test_LC1162_maxDistance();
    };
    class MinStickers{
    private:
        constexpr static int MAXN=401;
        //���У��������й���
        vector<string>que;
        int l,r;
        //ͼ��������¼��ĳ����ĸ��ͷ���ַ���
        vector<vector<string>>Graph;
        //set��������¼�Ѿ����ʹ����ַ���
        unordered_set<string>visited;
    private:
        /*������ n �ֲ�ͬ����ֽ��ÿ����ֽ�϶���һ��Сд��Ӣ�ĵ��ʡ�
        ����Ҫƴд���������ַ��� target ��
        �����Ǵ��ռ�����ֽ���и����ĸ�������������ǡ�
        �����Ը�⣬����Զ��ʹ��ÿ����ֽ��ÿ����ֽ�����������޵ġ�
        ��������Ҫƴ�� target ����С��ֽ������������񲻿��ܣ��򷵻� -1 ��
        ע�⣺�����еĲ��������У����еĵ��ʶ��Ǵ� 1000 �����������Ӣ�ﵥ�������ѡ��ģ�
        ���� target ��ѡ��Ϊ����������ʵ����ӡ�
        ʾ�� 1��
        ���룺 stickers = ["with","example","science"], target = "thehat"
        �����3
        ���ͣ�
        ���ǿ���ʹ�� 2 �� "with" ��ֽ���� 1 �� "example" ��ֽ��
        ����ֽ�ϵ���ĸ���������������к󣬾Ϳ����γ�Ŀ�� ��thehat�� �ˡ�
        ���⣬�����γ�Ŀ���ַ����������С��ֽ������
        ʾ�� 2:
        ���룺stickers = ["notice","possible"], target = "basicbasic"
        �����-1
        ���ͣ����ǲ���ͨ�����и�����ֽ����ĸ���γ�Ŀ�ꡰbasicbasic����
        ��ʾ:
        n == stickers.length
        1 <= n <= 50
        1 <= stickers[i].length <= 10
        1 <= target.length <= 15
        stickers[i] �� target ��СдӢ�ĵ������*/
        int LC691_minStickers(vector<string>& stickers, string target);
        string Next(string cur,string s);
    public:
        MinStickers();
        /*LeetCode 691 ��ֽƴ��*/
        void Test_LC691_minStickers();
    };
    class MinimumObstacles{
    private:
        /*����һ���±�� 0 ��ʼ�Ķ�ά�������� grid �������СΪ m x n ��
        ÿ����Ԫ��������ֵ֮һ��
        0 ��ʾһ�� �� ��Ԫ��
        1 ��ʾһ�������Ƴ��� �ϰ��� ��
        ��������ϡ��¡������ƶ�����һ���յ�Ԫ���ƶ�����һ���յ�Ԫ��
        ��������Ҫ�����Ͻ� (0, 0) �ƶ������½� (m - 1, n - 1) ��
        ������Ҫ�Ƴ����ϰ���� ��С ��Ŀ��
        ʾ�� 1��
        ���룺grid = [[0,1,1],[1,1,0],[1,1,0]]
        �����2
        ���ͣ������Ƴ�λ�� (0, 1) �� (0, 2) ���ϰ����������� (0, 0) �� (2, 2) ��·����
        ����֤������������Ҫ�Ƴ������ϰ�����Է��� 2 ��
        ע�⣬���ܴ���������ʽ���Ƴ� 2 ���ϰ�����������е�·����
        ʾ�� 2��
        ���룺grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
        �����0
        ���ͣ����Ƴ��κ��ϰ�����ܴ� (0, 0) �� (2, 4) �����Է��� 0 ��
        ��ʾ��
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 105
        2 <= m * n <= 105
        grid[i][j] Ϊ 0 �� 1
        grid[0][0] == grid[m - 1][n - 1] == 0*/
        int LC2290_minimumObstacles(vector<vector<int>>& grid);
    public:
        /*LeetCode 2290 ���������Ҫ�Ƴ����ϰ������С��Ŀ*/
        void Test_LC2290_minimumObstacles();
    };
    class MinCost{
    private:
        /*����һ�� m x n ������ͼ grid �� grid ��ÿ�����Ӷ���һ�����֣�
        ��Ӧ�ŴӸø��ӳ�����һ���ߵķ��� grid[i][j] �е����ֿ���Ϊ���¼��������
        1 ����һ�������ߣ�Ҳ�������� grid[i][j] �ߵ� grid[i][j + 1]
        2 ����һ�������ߣ�Ҳ�������� grid[i][j] �ߵ� grid[i][j - 1]
        3 ����һ�������ߣ�Ҳ�������� grid[i][j] �ߵ� grid[i + 1][j]
        4 ����һ�������ߣ�Ҳ�������� grid[i][j] �ߵ� grid[i - 1][j]
        ע������ͼ�п��ܻ��� ��Ч���� ����Ϊ���ǿ���ָ�� grid ���������
        һ��ʼ�����������Ͻǵĸ��� (0,0) ���������Ƕ���һ�� ��Ч·�� Ϊ�Ӹ��� (0,0) ������
        ÿһ����˳�����ֶ�Ӧ�����ߣ������������½ǵĸ��� (m - 1, n - 1) ������·������Ч·�� ����Ҫ�����·�� ��
        ����Ի��� cost = 1 �Ĵ����޸�һ�������е����֣���ÿ�������е����� ֻ���޸�һ�� ��
        ���㷵��������ͼ������һ����Ч·������С���ۡ�
        ʾ�� 1��
        ���룺grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
        �����3
        ���ͣ��㽫�ӵ� (0, 0) ������
        ���� (3, 3) ��·��Ϊ�� (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) 
        ���Ѵ��� cost = 1 ʹ�������� --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) 
        ���Ѵ��� cost = 1 ʹ�������� --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) ���Ѵ��� cost = 1 ʹ�������� --> (3, 3)
        �ܻ���Ϊ cost = 3.
        ʾ�� 2��
        ���룺grid = [[1,1,3],[3,2,2],[1,1,4]]
        �����0
        ���ͣ����޸��κ�������Ϳ��Դ� (0, 0) ���� (2, 2) ��
        ʾ�� 3��
        ���룺grid = [[1,2],[4,3]]
        �����1
        ʾ�� 4��
        ���룺grid = [[2,2,2],[2,2,2]]
        �����3
        ʾ�� 5��
        ���룺grid = [[4]]
        �����0
        ��ʾ��
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 100*/
        int LC1368_minCost(vector<vector<int>>& grid);
    public:
        /*LeetCode 1368 ʹ����������һ����Ч·������С����*/
        void Test_LC1368_minCost();
    };
    class trapRainWater{
    private:
        /*����һ�� m x n �ľ������е�ֵ��Ϊ�Ǹ�������
        �����ά�߶�ͼÿ����Ԫ�ĸ߶ȣ������ͼ����״����ܽӶ����������ˮ��
        ʾ�� 1:
        ����: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
        ���: 4
        ����: �������ˮ���ᱻ��ͼ��ɫ�ķ����С��ܵĽ���ˮ��Ϊ1+2+1=4��
        ʾ�� 2:
        ����: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
        ���: 10
        ��ʾ:
        m == heightMap.length
        n == heightMap[i].length
        1 <= m, n <= 200
        0 <= heightMap[i][j] <= 2 * 104
        */
        int LC407_trapRainWater(vector<vector<int>>& heightMap);
    public: 
        /*LeetCode 407 ����ˮII*/
        void Test_LC407_trapRainWater();
    };
    class FindLadders{
    private:
        //���ʱ���ϣset��ʽ
        unordered_set<string>dict;
        //��ǰ��ĵ���
        unordered_set<string>curLevel;
        //��ǰ�����һ��ĵ���
        unordered_set<string>nextLevel;
        //��end��begin�ķ���ͼ
        unordered_map<string,vector<string>>Graph;
        //������һ����Ч·��ʱ������ans��
        vector<string>path;
        //�𰸼���
        vector<vector<string>>ans;
    private:
        /*���ֵ� wordList ��ɴӵ��� beginWord ������ endWord ת����
        һ����ʾ�˹��̵� ת������ ����ʽ���� beginWord -> s1 -> s2 -> ... -> sk �����ĵ������У������㣺
        ÿ�����ڵĵ���֮����е�����ĸ��ͬ��
        ת�������е�ÿ������ si��1 <= i <= k���������ֵ� wordList �еĵ��ʡ�ע�⣬beginWord �������ֵ� wordList �еĵ��ʡ�
        sk == endWord
        ������������ beginWord �� endWord ���Լ�һ���ֵ� wordList ��
        �����ҳ����������д� beginWord �� endWord �� ���ת������ �����������������ת�����У�
        ����һ�����б�ÿ�����ж�Ӧ���Ե����б� [beginWord, s1, s2, ..., sk] ����ʽ���ء�
        ʾ�� 1��
        ���룺beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
        �����[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
        ���ͣ����� 2 ����̵�ת�����У�
        "hit" -> "hot" -> "dot" -> "dog" -> "cog"
        "hit" -> "hot" -> "lot" -> "log" -> "cog"
        ʾ�� 2��
        ���룺beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
        �����[]
        ���ͣ�endWord "cog" �����ֵ� wordList �У����Բ����ڷ���Ҫ���ת�����С�
        ��ʾ��
        1 <= beginWord.length <= 5
        endWord.length == beginWord.length
        1 <= wordList.length <= 500
        wordList[i].length == beginWord.length
        beginWord��endWord �� wordList[i] ��СдӢ����ĸ���
        beginWord != endWord
        wordList �е����е��� ������ͬ*/
        vector<vector<string>> LC126_findLadders(string beginWord, string endWord, vector<string>& wordList);
        //��ʼ��
        void Build(vector<string>&wordList);
        //����
        bool LC126_findLadders_BFS(string beginword,string endword);
        //����
        void LC126_findLadders_DFS(string endword,string beginwrod);
    public:
        /*LeetCode 126 ���ʽ���II*/
        void Test_LC126_findLadders();
    };
    class LadderLength{
    private:
        /*�ֵ� wordList �дӵ��� beginWord �� endWord �� ת������ ��һ������������γɵ����� beginWord -> s1 -> s2 -> ... -> sk��
        ÿһ�����ڵĵ���ֻ��һ����ĸ��
        ���� 1 <= i <= k ʱ��ÿ�� si ���� wordList �С�ע�⣬ beginWord ����Ҫ�� wordList �С�
        sk == endWord
        ������������ beginWord �� endWord ��һ���ֵ� wordList ������ �� beginWord �� endWord �� ���ת������ �е� ������Ŀ �����������������ת�����У����� 0 ��
        ʾ�� 1��
        ���룺beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
        �����5
        ���ͣ�һ�����ת�������� "hit" -> "hot" -> "dot" -> "dog" -> "cog", �������ĳ��� 5��
        ʾ�� 2��
        ���룺beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
        �����0
        ���ͣ�endWord "cog" �����ֵ��У������޷�����ת����
        ��ʾ��
        1 <= beginWord.length <= 10
        endWord.length == beginWord.length
        1 <= wordList.length <= 5000
        wordList[i].length == beginWord.length
        beginWord��endWord �� wordList[i] ��СдӢ����ĸ���
        beginWord != endWord
        wordList �е������ַ��� ������ͬ*/
        int LC127_ladderLength(string beginWord, string endWord, vector<string>& wordList);
    public:
        /*LeetCode 127 ���ʽ���*/
        void Test_LC127_ladderLength();
    };
    class SnacksWayBuyTickets{
    private:
    constexpr static int MAXN=40;
    constexpr static int MAXM=1<<20;
    //���������
    vector<long long>arr;
    /*˫���������*/
    vector<long long>lnum;
    /*˫������Ұ��*/
    vector<long long>rnum;
    /*���鳤�ȡ������������*/
    long long n,m;
        /*��ʳ����&������򾺱���
        ţţ׼���μ�ѧУ��֯�Ĵ��Σ�����ǰţţ׼����������װ��һЩ��ʳ��ţţ�ı�������Ϊw
        ţţ�ڼ���һ����n����ʳ����i����ʳ�����Ϊv[i]
        ţţ��֪������������������������������
        һ���ж�������ʳ�ķŷ��������Ϊ0Ҳ��һ�ַŷ���
        ��������
        1<=n<=40
        1<=w<=w*10^9
        0<=v[i]<=10^9*/
    private:
        void LGP4799_SnacksWayBuyTickets();
        /*˫����ѵ����ݴ���*/
        long long LGP4799_Compute();
        /*˫�����  arr[i....e]������e�����ң���չ����֮ǰ�ľ������γɵ��ۼӺ�s����������w���˹��������ɵķ������������ļ���
        ����ֵ��ans�������ʲôλ��*/
        int LGP4799_f(int i,int e,long long s,long long w,vector<long long>&ans,int j);
    public:
        SnacksWayBuyTickets(){
            arr.resize(MAXN);
            lnum.resize(MAXM);
            rnum.resize(MAXM);
        }
        /*LGP4799 ������������*/
        void Test_LGP4799_SnacksWayBuyTickets();
    };
    class MinAbsDifference{
    private:
        constexpr static int MAXM=1<<20;
        vector<long long>lsum;
        vector<long long>rsum;
        //��¼����
        int fill;
        /*����һ���������� nums ��һ��Ŀ��ֵ goal ��
        ����Ҫ�� nums ��ѡ��һ�������У�ʹ������Ԫ���ܺ���ӽ� goal ��Ҳ����˵�����������Ԫ�غ�Ϊ sum ������Ҫ ��С�����Բ� abs(sum - goal) ��
        ���� abs(sum - goal) ���ܵ� ��Сֵ ��
        ע�⣬�������������ͨ���Ƴ�ԭʼ�����е�ĳЩԪ�أ�����ȫ�����ޣ����γɵ����顣
        ʾ�� 1��
        ���룺nums = [5,-7,3,5], goal = 6
        �����0
        ���ͣ�ѡ������������Ϊѡ���������У�Ԫ�غ�Ϊ 6 ��
        �����к���Ŀ��ֵ��ȣ����Ծ��Բ�Ϊ 0 ��
        ʾ�� 2��
        ���룺nums = [7,-9,15,-2], goal = -5
        �����1
        ���ͣ�ѡ�������� [7,-9,-2] ��Ԫ�غ�Ϊ -4 ��
        ���Բ�Ϊ abs(-4 - (-5)) = abs(1) = 1 ���ǿ��ܵ���Сֵ��
        ʾ�� 3��
        ���룺nums = [1,2,3], goal = -7
        �����7
        ��ʾ��
        1 <= nums.length <= 40
        -107 <= nums[i] <= 107
        -109 <= goal <= 109*/
        int LC1755_minAbsDifference(vector<int>& nums, int goal);
        /*˫�����*/
        void LC1755_minAbsDifference_f(vector<int>&arr,int i,int e,long long s,vector<long long>&ans);
    public:
        /*LeetCode 1755 ��ӽ�Ŀ��ֵ�������к�*/
        void Test_LC1755_minAbsDifference();
        MinAbsDifference(){
            lsum.resize(MAXM);
            rsum.resize(MAXM);
        }
    };
}

/*Dijkstra�㷨���ֲ�ͼ���·*/
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
    /*��ͨ��ʵ��Dijkstra�㷨��ʱ�临�Ӷ�O(m*logm)mΪ����
    1.dustance[i]��ʾ��Դ�㵽i�����̾��룬visited[i]��ʾi�ڵ��Ƿ��С�����ﵯ����
    2.׼����С���ѣ�С���Ѵ�ż�¼����x�㣬Դ�㵽x�ľ��룩��С���Ѹ��ݾ�����֯
    3.��distance[Դ��]=0,��Դ�㣬0������С����
    4.��С�����е�����u�㣬Դ�㵽u�ľ��룩
        a.���vistance[u]==true,�����κδ����ظ�����4
        b.���vistance[u]==false��vistance[u]==true,u���㵯������
            Ȼ�󿼲�u��ÿһ���ߣ�����ĳ��ȥ��v����ȨΪw
            1).���visitance[v]==false����distance[u]+w<distance[v]
            ��distance [v]==distance[u]+w,��(v,distance[u]+w)����С����
            2).������u��ÿһ����֮���ظ�����4 
    5.С����Ϊ�գ����̽�����distance���¼��Դ�㵽ÿ���ڵ����̾���*/
    class DijkstraAlorgithm{
    private:
        /*�� n ������ڵ㣬���Ϊ 1 �� n��
        ����һ���б� times����ʾ�źž��� ���� �ߵĴ���ʱ�䡣 times[i] = (ui, vi, wi)������ ui ��Դ�ڵ㣬vi ��Ŀ��ڵ㣬 wi ��һ���źŴ�Դ�ڵ㴫�ݵ�Ŀ��ڵ��ʱ�䡣
        ���ڣ���ĳ���ڵ� K ����һ���źš���Ҫ��ò���ʹ���нڵ㶼�յ��źţ��������ʹ���нڵ��յ��źţ����� -1 ��
        ʾ�� 1��
        ���룺times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
        �����2
        ʾ�� 2��
        ���룺times = [[1,2,1]], n = 2, k = 1
        �����1
        ʾ�� 3��
        ���룺times = [[1,2,1]], n = 2, k = 2
        �����-1
        ��ʾ��
        1 <= k <= n <= 100
        1 <= times.length <= 6000
        times[i].length == 3
        1 <= ui, vi <= n
        ui != vi
        0 <= wi <= 100
        ���� (ui, vi) �Զ� ������ͬ�����������ظ��ߣ�*/
        int LC743_networkDelayTime(vector<vector<int>>& times, int n, int k);
    public:
        /*LeetCode 743 �����ӳ�ʱ��*/
        void Test_LC743_networkDelayTime();
    };
    /*1.׼����һ�����������ѣ�����Դ�㵽��ǰ��ľ�����֯С���ѣ������������²���
        a.������¼(X,Դ�㵽X�ľ���)     b.��Դ�㵽X�ľ������ʱ�����Խ��жѵĵ���
        c.X��һ���������Ժ����X        d.�����Ѷ��ļ�¼(u,Դ�㵽u�ľ���)
    2.��Դ��(Դ�㣬0)���뷴�������ѣ����̿�ʼ
    3.���������ѵ���(u,Դ�㵽u�ľ���),����u��ÿһ���ߣ�����ĳ��ȥ��v����ȨΪw
        1)���vû�н���������������������¼(v,Դ�㵽u�ľ���+w)
        2)���v�����ӷ��������ѵ�����������
        3)���v�ڷ��������������Դ�㵽v�ľ����ܲ��ܱ�ĸ�С������ܣ������ѣ����ܣ�����
        4)������u��һ���ߣ��ظ�����3
    4.����������Ϊ�չ��̽������������������¼��Դ�㵽ÿ���ڵ����̾���*/
    class InvertedIndexingDijkstra{
        /*���ڷ���������ʵ�ֵ�Dijkstra�㷨*/
    private:
        constexpr static int MAXN=101;
        constexpr static int MAXM=6001;
        //��
        vector<int>Heap;
        int Heap_size;
        /*���������� -1:��δ����    -2:�Ѿ�������   >=0�Ѿ��ڶ���*/
        vector<int>Where;
        //��ʽǰ����
        vector<int>Head;
        vector<int>next;
        vector<int>tos;
        vector<int>weight;
        int cnt;
        //��������
        vector<int>Distance;
    private:
        //��ʼ��
        void Build(int n);
        //��ʽǰ���Ǽӱ�
        void addEdge(int u,int v,int w);
        //LeetCode 743
        int LC743_networkDelayTime(vector<vector<int>>& times, int n, int k);
        //��ӻ��߸��»�������
        void addOrUpdateOrIgnore(int u,int c);
        //������
        void HeapInsert(int i);
        //����
        void Swap(int i,int j);
        //����
        int Pop();
        //������
        void HeapFiy(int i);
        //���Ƿ�Ϊ��
        bool Empty();
    public:
        InvertedIndexingDijkstra();
        void Test_LC743_networkDelayTime();
    };
    class MinimumEffortPath{
    private:
        /*��׼���μ�һ��Զ��������һ����ά rows x columns �ĵ�ͼ heights ������ heights[row][col] ��ʾ���� (row, col) �ĸ߶ȡ�һ��ʼ���������Ͻǵĸ��� (0, 0) ������ϣ��ȥ�����½ǵĸ��� (rows-1, columns-1) ��ע���±�� 0 ��ʼ��ţ�����ÿ�ο����� �ϣ��£����� �ĸ�����֮һ�ƶ�������Ҫ�ҵ��ķ� ���� ��С��һ��·����
        һ��·���ķѵ� ����ֵ ��·�������ڸ���֮�� �߶Ȳ����ֵ �� ���ֵ �����ġ�
        ���㷵�ش����Ͻ��ߵ����½ǵ���С ��������ֵ ��
        ʾ�� 1��
        ���룺heights = [[1,2,2],[3,8,2],[5,3,5]]
        �����2
        ���ͣ�·�� [1,3,5,3,5] �������ӵĲ�ֵ����ֵ���Ϊ 2 ��
        ����·����·�� [1,2,2,2,5] ���ţ���Ϊ��һ��·����ֵ���ֵΪ 3 ��
        ʾ�� 2��
        ���룺heights = [[1,2,3],[3,8,4],[5,3,5]]
        �����1
        ���ͣ�·�� [1,2,3,4,5] �����ڸ��Ӳ�ֵ����ֵ���Ϊ 1 ����·�� [1,3,5,3,5] ���š�
        ʾ�� 3��
        ���룺heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
        �����0
        ���ͣ���ͼ��ʾ·������Ҫ�����κ�������
        ��ʾ��
        rows == heights.length
        columns == heights[i].length
        1 <= rows, columns <= 100
        1 <= heights[i][j] <= 106*/
        int LC1631_minimumEffortPath(vector<vector<int>>& heights);
    public:
        /*LeetCode 1631 ������С����ֵ��·��*/
        void Test_LC1631_minimumEffortPath();
    };
    class SwimInWater{
    private:
        /*��һ�� n x n ���������� grid �У�ÿһ�������ֵ grid[i][j] ��ʾλ�� (i, j) ��ƽ̨�߶ȡ�
        ����ʼ����ʱ����ʱ��Ϊ t ʱ��ˮ���е�ˮλΪ t ������Դ�һ��ƽ̨�����������ڵ�����һ��ƽ̨������ǰ���Ǵ�ʱˮλ����ͬʱ��û������ƽ̨���ٶ������˲���ƶ����޾��룬Ҳ����Ĭ���ڷ����ڲ��ζ��ǲ���ʱ�ġ���Ȼ��������Ӿ��ʱ�������������귽�����档
        ������귽�������ƽ̨ (0��0) ���������� �㵽�����귽�������ƽ̨ (n-1, n-1) ���������ʱ�� ��
        ʾ�� 1:
        ����: grid = [[0,2],[1,3]]
        ���: 3
        ����:
        ʱ��Ϊ0ʱ����λ�����귽���λ��Ϊ (0, 0)��
        ��ʱ�㲻���������ⷽ����Ϊ�ĸ����ڷ���ƽ̨�ĸ߶ȶ����ڵ�ǰʱ��Ϊ 0 ʱ��ˮλ��
        ��ʱ�䵽�� 3 ʱ����ſ�������ƽ̨ (1, 1). ��Ϊ��ʱ��ˮλ�� 3�����귽���е�ƽ̨û�б�ˮλ 3 ���ߵģ�����������������귽���е�����λ��
        ʾ�� 2:
        ����: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
        ���: 16
        ����: ���յ�·���üӴֽ����˱�ǡ�
        ���Ǳ���ȵ�ʱ��Ϊ 16����ʱ���ܱ�֤ƽ̨ (0, 0) �� (4, 4) ����ͨ��
        ��ʾ:
        n == grid.length
        n == grid[i].length
        1 <= n <= 50
        0 <= grid[i][j] < n2
        grid[i][j] ��ÿ��ֵ �����ظ�*/
        int LC778_swimInWater(vector<vector<int>>& grid);
    public:
        /*LeetCode 778 ��ˮλ���ߵ�Ӿ������Ӿ*/
        void Test_LC778_swimInWater();
    };
    /*�ֲ����·(�������·)*/
    class ShortestPathAllKeys{
    private:
    //����Ĺ�ģ
    constexpr static int MAXN=31;
    constexpr static int MAXM=31;
    //Կ�׵�����
    constexpr static int MAXK=6;
    //�ƶ�����
    //����״̬��ϵķ�λ�����(״̬�ĸ���Ϊ1<<6,��2^6��״̬)
    vector<vector<vector<bool>>>visited;
    //����  [0]:��    [1]:��  [2]:״̬
    vector<vector<int>>que;
    //���ƶ��е�ָ�롢������������Կ�׵�״̬
    int l,r,n,m,key;
        /*����һ����ά���� grid �����У�
        '.' ����һ���շ���
        '#' ����һ��ǽ
        '@' �����
        Сд��ĸ����Կ��
        ��д��ĸ������
        ���Ǵ���㿪ʼ������һ���ƶ���ָ���ĸ���������֮һ����һ����λ�ռ䡣���ǲ����������������ߣ�Ҳ�޷�����һ��ǽ�����;��һ��Կ�ף����ǾͰ������������������������ж�Ӧ��Կ�ף������޷�ͨ������
        ���� k Ϊ Կ��/�� �ĸ����������� 1 <= k <= 6����ĸ���е�ǰ k ����ĸ�������ж����Լ���Ӧ��һ��Сд��һ����д��ĸ������֮��ÿ������Ψһ��Ӧ��Կ�ף�ÿ��Կ��Ҳ��Ψһ��Ӧ���������⣬����Կ�׺�������ĸ��Ϊ��Сд������ĸ˳�����С�
        ���ػ�ȡ����Կ������Ҫ���ƶ������ٴ���������޷���ȡ����Կ�ף����� -1 ��
        ʾ�� 1��
        ���룺grid = ["@.a.#","###.#","b.A.B"]
        �����8
        ���ͣ�Ŀ���ǻ������Կ�ף������Ǵ���������
        ʾ�� 2��
        ���룺grid = ["@..aA","..B#.","....b"]
        �����6
        ʾ�� 3:
        ����: grid = ["@Aa"]
        ���: -1
        ��ʾ��
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 30
        grid[i][j] ֻ���� '.', '#', '@', 'a'-'f' �Լ� 'A'-'F'
        Կ�׵���Ŀ��Χ�� [1, 6] 
        ÿ��Կ�׶���Ӧһ�� ��ͬ ����ĸ
        ÿ��Կ�����ô�һ����Ӧ����*/
        int LC864_shortestPathAllKeys(vector<string>& grid);
        //��ʼ��
        void Build(vector<string>& grid);
    public:
        /*LeetCode 864 ��ȡ����Կ�׵����·��*/
        void Test_LC864_shortestPathAllKeys();
    };
    class ElectricCarPlan{
    private:
        /*С���ĵ綯����������ʱ����ʻ����Ϊ cnt��ÿ��ʻ 1 ��λ�������� 1 ��λ�������һ��� 1 ��λʱ�䡣С����ѡ��綯����Ϊ�������ߡ���ͼ�Ϲ��� N �����㣬������Ϊ 0 ~ N-1��������ͼ��Ϣ�� [���� A ���,���� B ���,�����м����] ��ʽ�������ڶ�ά���� paths����ʾ���� A��B �����˫��ͨ·����ʼ״̬���綯������Ϊ 0��ÿ�����ж����г��׮��charge[i] ��ʾ�� i ������ÿ�� 1 ��λ������Ҫ���ѵĵ�λʱ�䡣�뷵��С��������Ҫ���Ѷ��ٵ�λʱ��������� start �ִ��յ���� end��
        ʾ�� 1��
        ���룺paths = [[1,3,3],[3,2,1],[2,1,3],[0,1,4],[3,0,5]], cnt = 6, start = 1, end = 0, charge = [2,10,4,1]
        �����43
        ���ͣ����·��Ϊ��1->3->0�� �ڳ��� 1 ���� 3 ��λ�������� 3��Ȼ���ڳ��� 3 �� 5 ��λ�磬��ʻ������ 5�� �����ʱ�� 3*10 + 5*1= 35 ��ʻ��ʱ 3 + 5 = 8����ʱ����ʱ��� 43��image.png
        ʾ�� 2��
        ���룺paths = [[0,4,2],[4,3,5],[3,0,5],[0,1,5],[3,2,4],[1,2,8]], cnt = 8, start = 0, end = 2, charge = [4,1,1,3,2]
        �����38
        ���ͣ����·��Ϊ��0->4->3->2�� ���� 0 ��� 2 ��λ����ʻ������ 4 ��� 8 ��λ����ʻ������ 3 ��� 1 ��λ��������ʻ������ 2�� �����ʱ 4*2+2*8+3*1 = 27 ��ʻ��ʱ 2+5+4 = 11������ʱ��� 38��
        ��ʾ��
        1 <= paths.length <= 200
        paths[i].length == 3 
        2 <= charge.length == n <= 100
        0 <= path[i][0],path[i][1],start,end < n
        1 <= cnt <= 100
        1 <= path[i][2] <= cnt
        1 <= charge[i] <= 100
        ��Ŀ��֤���г����໥���Ե���*/
        int LCP35_electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge);
    public:
        /*LCP 35 �綯���γ���*/
        void Test_LCP35_electricCarPlan();
    };
    class AStarAlgorithm{
    private:
        /*���ش�(startX,startY)��(targetX,targetY)����̾���*/
        //����Dijkstra�㷨
        int MinDistance1(vector<vector<int>>&grid,int startX,int startY,int targetX,int targetY);
        //����Dijkstra�㷨�Ľ���A*�㷨
        int MinDistance2(vector<vector<int>>&grid,int startX,int startY,int targetX,int targetY);
        //�����پ��뺯��
        int MinDistance2_f1(int SX,int SY,int EX,int EY);
        //�Խ��߾���
        int MinDistance2_f2(int SX,int SY,int EX,int EY);
        //ŷʽ����
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
    /*�ɳڲ���
    ����Դ��ΪA����A�������F����̾���Ϊdistance[F]
    �����P�������ĳ����ȥ����S����ȨΪW
    ������֣�distance[P]+W<distance[S],Ҳ����ͨ���ñ߿�����distance[S]��С
    ��ô��˵��P�����������߶Ե�S�������ɳڲ���
    Bellman-Ford���̣�
    1.ÿ�ֿ���һ���ߣ�ÿ���߶����Խ����ɳڲ�������ô���ɵ��distance���С
    2.��ĳһ�ַ��ֲ������ɳڲ�������ʱ���㷨ֹͣ*/
    private:
        /*�� n ������ͨ��һЩ�������ӡ�����һ������ flights ������ flights[i] = [fromi, toi, pricei] ����ʾ�ú��඼�ӳ��� fromi ��ʼ���Լ۸� pricei �ִ� toi��
        ���ڸ������еĳ��кͺ��࣬�Լ��������� src ��Ŀ�ĵ� dst������������ҵ���һ����ྭ�� k վ��ת��·�ߣ�ʹ�ô� src �� dst �� �۸������ �������ظü۸� ���������������·�ߣ������ -1��
        ʾ�� 1��
        ����: 
        n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
        src = 0, dst = 2, k = 1
        ���: 200
        ����: 
        ���к���ͼ����
        �ӳ��� 0 ������ 2 �� 1 վ��ת���ڵ�����˼۸��� 200����ͼ�к�ɫ��ʾ��
        ʾ�� 2��
        ����: 
        n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
        src = 0, dst = 2, k = 0
        ���: 500
        ����: 
        ���к���ͼ����
        �ӳ��� 0 ������ 2 �� 0 վ��ת���ڵ�����˼۸��� 500����ͼ����ɫ��ʾ��
        ʾ��
        1 <= n <= 100
        0 <= flights.length <= (n * (n - 1) / 2)
        flights[i].length == 3
        0 <= fromi, toi < n
        fromi != toi
        1 <= pricei <= 104
        ����û���ظ����Ҳ������Ի�
        0 <= src, dst, k < n
        src != dst*/
        int LC_787findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k);
    public:
        /*LeetCode 787 kվ��ת������˵ĺ���*/
        void LC787_findCheapestPrice();
    };
    /*Bellman-Ford+SPFA�Ż�(Shortest Path Faster Algorithm)
    �����׾��ܷ��֣�ÿһ�ֿ������еı߿����ܷ����ɳڲ����ǲ���Ҫ��
    ��Ϊֻ����һ�α�ĳ�����ɳڹ��Ľڵ㣬�����ӵıߣ����п���������һ���ɳڲ���
    �����ö�����ά��������һ������Щ�ڵ��distacne��С�ˡ�
    ��һ��ֻ��Ҫ����Щ������бߣ�������û���ɳڲ�������*/
    class LGP3385_SPFA{
    private:
        //��ĸ���
        constexpr static int MAXN=2001;
        //�ߵĸ���
        constexpr static int MAXM=600001;
        //��ʽǰ����
        vector<int>head;
        vector<int>nexts;
        vector<int>tos;
        vector<int>weight;
        int cnt;
        //SPFA����Ҫ�Ŀռ�Ϊ
        constexpr static int MAXQ=40000001;
        //Դ�㵽��ǰ�����С����
        vector<int>distances;
        //ÿ������µĴ���
        vector<int>updateCnt;
        //����
        vector<int>que;
        int l,r;
        //�������
        vector<bool>enters;
    private:
        /*��ĳһ��������Ƿ��и���*/
        void Build(int n);
        bool Spfa(int n);
        void addEdge(int u,int c,int w);
        void SPFA();
    public:
        LGP3385_SPFA();
        void Test_SPFA();
    };
} /*����һ���ַ������飬����ʼ���ַ���Ŀ���ַ�����̾���
    ÿ������ͬ���ַ�֮�����ֱ�Ӵ���*/