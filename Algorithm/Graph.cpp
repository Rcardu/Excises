#include"Graph.h"
using namespace std;

/// @brief 图 case 1
CreatGraph::Graph::Graph():cnt(0){
    Graph1.resize(MAXN,vector<int>(MAXN,0));
    head.resize(MAXN,0);
    next.resize(MAXM,0);
    tos.resize(MAXM,0);
    weith.resize(MAXM,0);
}
void CreatGraph::Graph::Build(int n){
    //邻接矩阵的清空
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            Graph1[i][j]=0;
        }
    }
    //邻接表的清空
    Graph2.clear();
    //下标需要支持1~n，所以加入n+1个列表
    for(int i=0;i<=n;i++){
        Graph2.push_back({});
    }
    //清空链式前向星
    cnt=1;
    for(int&h:head)h=0;
}
void CreatGraph::Graph::DirectGraph(vector<vector<int>>&edges){
    for(vector<int> edge:edges){
        //如果是无权则让权值=1代表有边即可
        Graph1[edge[0]][edge[1]]=edge[2];
    }
    for(vector<int>edge:edges){
        //如果是无权则用另一个无权邻接表，直接插入边即可
        Graph2[edge[0]].push_back({edge[1],edge[2]});
    }
    for(vector<int>edge:edges){
        addEdge(edge[0],edge[1],edge[2]);
    }
}
void CreatGraph::Graph::UndirectGraph(vector<vector<int>>&edges){
    for(vector<int>edge:edges){
        //无权改为1
        Graph1[edge[0]][edge[1]]=edge[2];
        Graph1[edge[1]][edge[0]]=edge[2];
    }
    for(vector<int>edge:edges){
        //无权用另一个无权邻接表
        Graph2[edge[0]].push_back({edge[1],edge[2]});
        Graph2[edge[1]].push_back({edge[0],edge[2]});
    }
    for(vector<int>edge:edges){
        addEdge(edge[0],edge[1],edge[2]);
        addEdge(edge[1],edge[0],edge[2]);
    }
}
void CreatGraph::Graph::addEdge(int u,int v,int w){
    //新的边要去的下一条边的位置就是当前点的头部所表示的边
    next[cnt]=head[u];
    //这条边通往的点为v
    tos[cnt]=v;
    //这条边的权重为w
    weith[cnt]=w;
    //这条边成为当前点的头部
    head[u]=cnt++;
}
void CreatGraph::Graph::Traversal(int n){
    cout<<"邻接矩阵遍历:"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<Graph1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"邻接表的遍历: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<"(邻居、边权):";
        for(auto edge:Graph2[i]){
            cout<<"("<<edge[0]<<","<<edge[1]<<")";
        }
        cout<<endl;
    }
    cout<<"链式前向星的遍历: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<"(邻居、边权): ";
        //这个for循环，是链式前向星的遍历方式
        for(int ei=head[i];ei>0;ei=next[ei]){
            cout<<"("<<tos[ei]<<" "<<weith[ei]<<")";
        }
        cout<<endl;
    }
}
void CreatGraph::Graph::Test_Graph(){
    int n1=4;
    vector<vector<int>>edge1={{1,3,6},{4,3,4},{2,4,2},{1,2,7},{2,3,5},{3,1,1}};
    Build(n1);
    DirectGraph(edge1);
    Traversal(n1);
    int n2=5;
    vector<vector<int>>edge2={{3,5,4},{4,1,1},{3,4,2},{5,2,4},{2,3,7},{1,5,5}};
    Build(n2);
    DirectGraph(edge2);
    Traversal(n2);
}

/// @brief LeetCode 210 课程表 case 2
/// @param numCourses 
/// @param prerequisites 
/// @return 
vector<int>CreatGraph::Topological::LC210_findOrder(int numCourses, vector<vector<int>>& prerequisites){
    //建立图与每个结点的入度表
    vector<vector<int>>Graph;
    //根据节点数添加子表
    for(int i=0;i<numCourses;i++)Graph.push_back({});
    //入度表
    vector<int>indegree(numCourses,0);
    //添加结点及邻居，生成入度
    for(vector<int>edge:prerequisites){
        //edge[1]->edge[0];
        Graph[edge[1]].push_back(edge[0]);
        //edge[0]入度+1
        indegree[edge[0]]++;
    }
    //使用队列来进行拓扑排序
    vector<int>que(numCourses,0);
    int r=0,l=0;
    //先找出所有入度为0的点
    for(int i=0;i<numCourses;i++)if(indegree[i]==0)que[r++]=i;
    //记录所有弹出过的点
    int cnt=0;
    while(l<r){
        int cur=que[l++];
        //每弹出一个记录就+1
        cnt++;
        //如果当前结点的消失导致一个结点的入度为0，则将其加入队列
        for(int next:Graph[cur])if(--indegree[next]==0)que[r++]=next;
    }
    if(cnt!=numCourses)return {};
    return que;
}
void CreatGraph::Topological::Test_LC210_findOrder(){
    vector<vector<int>>edges;
    Print(LC210_findOrder(2,edges));  
}

/// @brief 洛谷 U107394 拓扑排序模板 case 3
/// @param n 
void CreatGraph::LG_Topological::Build(int n){
    cnt=1;
    heap_size=0;
    head.resize(MAXN,0);
    next.resize(MAXM,0);
    tos.resize(MAXM,0);
    heap.resize(MAXN,0);
    indegree.resize(MAXN,0);
    ans.resize(MAXN,0);
}
void CreatGraph::LG_Topological::addEdge(int u,int v){
    next[cnt]=head[u];
    tos[cnt]=v;
    head[u]=cnt++;
}
void CreatGraph::LG_Topological::Push(int num){
    int i=heap_size++;
    heap[i]=num;
    //如果新加入的这个结点比他的父节点还小，那么就交换两个结点的位置
    while(heap[i]<heap[(i-1)/2]){
        Swap(i,(i-1)/2);
        //更新父节点
        i=(i-1)/2;
    }
}
int CreatGraph::LG_Topological::Pop(){
    int ans=heap[0];
    //将最后一个叶子结点放到堆顶
    heap[0]=heap[--heap_size];
    int i=0,l=1;
    // 至少有两个结点可以比较
    while(l<heap_size){
        //如果l+1(右叶子结点)没有越界，取出左叶子与右叶子中最小的那个(索引)
        int best=l+1<heap_size&&heap[l+1]<heap[l]?l+1:l;
        //再与父结点进行比较
        best=heap[best]<heap[i]?best:i;
        //如果最小的就是父节点，直接退出(已经是合格的小顶堆)
        if(best==i)break;
        //否则就交换这两个结点
        Swap(best,i);
        //并循环判断它的子结点
        i=best;
        l=i*2+1;
    }
    //返回堆顶元素
    return ans;
}
void CreatGraph::LG_Topological::Swap(int n1,int n2){
    int temp=heap[n1];
    heap[n1]=heap[n2];
    heap[n2]=temp;
}
bool CreatGraph::LG_Topological::isEmpty(){
    return heap_size==0;
}
void CreatGraph::LG_Topological::topSort(){
    //遍历所有结点，找出入度为0的结点入堆
    for(int i=1;i<=n;i++)if(indegree[i]==0)Push(i);
    //记录出堆的结点个数
    int fill=0;
    while(!isEmpty()){
        int cur=Pop();
        ans[fill++]=cur;
        //遍历链式前向星图
        for(int ei=head[cur];ei>0;ei=next[ei])
            if(--indegree[tos[ei]]==0)
                Push(tos[ei]);
    }
}
void CreatGraph::LG_Topological::LG_U107394(){
    scanf("%d%d",&n,&m);
    Build(n);
    for(int i=0,from,tos;i<m;i++){
        scanf("%d%d",&from,&tos);
        addEdge(from,tos);
        indegree[tos]++;
    }
    topSort();
    for(int i=0;i<n-1;i++)cout<<ans[i]<<" ";
    cout<<ans[n-1]<<endl;
}
void CreatGraph::LG_Topological::Test_LG_U107394(){
    LG_U107394();
}

/// @brief LCR 114 火星词典 case 4
/// @param words 
/// @return 
string CreatGraph::alienOrder::LCR114_alienOrder(vector<string>& words){
    //建立入度表，初始为-1代表当前入度表的字符还没有出现
    vector<int>indegree(26,-1);
    for(string w:words){
        //遍历整个字符串数组，如果当前字符出现在字符串数组中就将其入度设置为0
        for(int i=0;i<w.size();i++)indegree[w[i]-'a']=0;
    }
    //建图
    vector<vector<int>>Graph;
    for(int i=0;i<26;i++)Graph.push_back({});
    //对前后两个字符串进行比较，取出建图
    for(int i=0,j,len;i<words.size()-1;i++){
        string cur=words[i];
        string next=words[i+1];
        j=0;
        len=min(cur.size(),next.size());
        for(;j<len;j++){
            //当前字符不一样时就可以加入图中了
            if(cur[j]!=next[j]){
                Graph[cur[j]-'a'].push_back(next[j]-'a');
                indegree[next[j]-'a']++;
                break;
            }
        }
        //如果出现前一个类似于"abc"后一个为"abcd"说明字典序有误
        if(j<cur.size()&&j==next.size())return "";
    }
    //使用队列进行拓扑排序
    vector<int>que(26,0);
    int l=0,r=0;
    //记录出现的字符个数
    int kinds=0;
    for(int i=0;i<26;i++){
        if(indegree[i]!=-1)kinds++;
        if(indegree[i]==0)que[r++]=i;
    }
    //进行拓扑排序
    string ans;
    while(l<r){
        //弹出首个入度为0的结点
        int cur=que[l++];
        //加入结果集
        ans+=(char)(cur+'a');
        //遍历当前结点的邻接，消除其对邻居的影响
        for(int next:Graph[cur]){
            //如果消除之后邻居的入度为0，就加入队列
            if(--indegree[next]==0)que[r++]=next;
        }
    }
    //如果结果集与出现的字符数相等，说明有拓扑排序，否则返回 ""代表有环，无法进行拓扑排序
    return ans.size()==kinds?ans:"";
}
void CreatGraph::alienOrder::Test_LCR114_alienOrder(){
    vector<string>str;
    cout<<LCR114_alienOrder(str)<<endl;
}

/// @brief LeetCode 936 戳印序列 case 5
/// @param stamp 
/// @param target 
/// @return 
vector<int>CreatGraph::alienOrder::LC936_movesToStamp(string stamp, string target){
    //获取印章长度与目标长度
    int n=target.size(),m=stamp.size();
    //建立入度表，初始入度都为m，代表每个位置都印错了
    vector<int>indegree(n-m+1,m);
    //建图
    vector<vector<int>>Graph;
    for(int i=0;i<n;i++)Graph.push_back({});
    //使用队列进行拓扑排序
    vector<int>que(n-m+1,0);
    int r=0,l=0;
    //遍历每个可以当开头的点对入度进行调整
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<m;j++){
            //判断以i开头的每个位置j的字符是否与印章对的上
            if(target[i+j]==stamp[j]){
                //以i开头的位置如果都对的话就进队
                if(--indegree[i]==0)que[r++]=i;
            //否则，标记第i+j位置为以i开头的印章无法完成匹配
            }else Graph[i+j].push_back(i);
        }
    }
    //当前位置如果可以被前面的印章覆盖，就无需消除此位置的影响了
    vector<bool>visited(n,false);
    //结果集
    vector<int>path(n-m+1,0);
    //结果集大小
    int size=0;
    while(l<r){
        int cur=que[l++];
        path[size++]=cur;
        //判断每个位置是否可以被释放,消除当前印章的影响
        for(int i=0;i<m;i++){
            if(!visited[cur+i]){
                visited[cur+i]=true;
                for(int next:Graph[cur+i]){
                    if(--indegree[next]==0)que[r++]=next;
                }
            }
        }
    }
    if(size!=n-m+1)return {};
    reverse(path.begin(),path.end());
    return path;
}
void CreatGraph::alienOrder::Test_LC936_movesToStamp(){
    string s1="abca",s2="aabcaca";
    Print(LC936_movesToStamp(s1,s2));
}

/// @brief LeetCode 851 喧闹和富有 case 7
/// @param richer 
/// @param quiet 
/// @return 
vector<int>FoodLine::loudAndRich::LC851_loudAndRich(vector<vector<int>>& richer, vector<int>& quiet){
    int n=quiet.size();
    //入读表
    vector<int>indegree(n,0);
    vector<vector<int>>Graph;
    for(int i=0;i<n;i++)Graph.push_back({});
    for(vector<int> r:richer){
        Graph[r[0]].push_back(r[1]);
        indegree[r[1]]++;
    }
    vector<int>que(n,0);
    vector<int>ans(n);
    int l=0,r=0;
    for(int i=0;i<n;i++){
        ans[i]=i;
        if(indegree[i]==0)que[r++]=i;
    }
    while(l<r){
        int cur=que[l++];
        for(int next:Graph[cur]){
            if(quiet[ans[cur]]<quiet[ans[next]])ans[next]=ans[cur];
            if(--indegree[next]==0)que[r++]=next;
        }
    }
    return ans;
}
void FoodLine::loudAndRich::Test_LC851_loudAndRich(){

}

/// @brief LeetCode 2050 并行课程III case 8
/// @param n 
/// @param relations 
/// @param time 
/// @return 
int FoodLine::mumTime::LC2050_minimumTime(int n, vector<vector<int>>& relations, vector<int>& time){
    vector<int>indegree(n+1,0);
    vector<vector<int>>Graph;
    for(int i=0;i<=n;i++)Graph.push_back({});
    for(vector<int>r:relations){
        Graph[r[0]].push_back(r[1]);
        indegree[r[1]]++;
    }
    vector<int>que(n+1,0);
    int l=0,r=0;
    for(int i=1;i<=n;i++)if(indegree[i]==0)que[r++]=i;
    vector<int>cost(n+1,0);
    int ans=0;
    while(l<r){
        int cur=que[l++];
        cost[cur]+=time[cur-1];
        ans=max(ans,cost[cur]);
        for(int next:Graph[cur]){
            cost[next]=max(cost[next],cost[cur]);
            if(--indegree[next]==0)que[r++]=next;
        }
    }
    return ans;
}
void FoodLine::mumTime::Test_LC2050_minimumTime(){

}

/// @brief LeetCode 2127 参加会议最多的员工 case 9
/// @param favorite 
/// @return 
int FoodLine::Invitations::LC2127_maximumInvitations(vector<int>& favorite){
/*分析：如果要使员工能做成一圈，则至少会有一个环：
    对于环：1）如果是一个两人组成的环，那么这两个人可以直接坐，同时喜欢两人的其他人依次坐
        即，小环（两人组成的环）加上这两人各自延伸出去的最大长度，再加上其他的小环，就是能坐下的人数
        2）如果是一个大于两人的大环，那么这张桌子只能坐下这个大环中的人*/
        int n=favorite.size();
        //入度
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)indegree[favorite[i]]++;
        //队列
        vector<int>que(n,0);
        int l=0,r=0;
        for(int i=0;i<n;i++)if(indegree[i]==0)que[r++]=i;
        //深度表
        vector<int>deep(n,0);
        while(l<r){
            //计算每个结点的深度，为小环的结果做准备
            int cur=que[l++];
            int next=favorite[cur];
            deep[next]=max(deep[next],deep[cur]+1);
            //并将所有非环结点删除，即循环之后，入度为0的结点就是没有在环上的结点
            if(--indegree[next]==0)que[r++]=next;
        }
        //进行计算
        //小环ringsize=2；
        int ans1=0;
        //大环ringsize>=3;
        int ans2=0;
        for(int i=0;i<n;i++){
            if(indegree[i]>0){
                int ringsize=1;
                indegree[i]=0;
                //遍历整个环，直到遇见i为止，并沿途将入度修改为0，表示已经遍历过
                for(int j=favorite[i];j!=i;j=favorite[j]){
                    indegree[j]=0;
                }
                //遍历完成后，如果是小环
                if(ringsize==2){
                    ans1+=2+deep[i]+deep[favorite[i]];
                }else ans2=max(ans2,ringsize);
            }
        }
        return max(ans1,ans2);
}
void FoodLine::Invitations::Test_LC2127_maximumInvitations(){
    vector<int>nums;
    cout<<LC2127_maximumInvitations(nums)<<endl;
}

/// @brief Kruskal算法 case 10
void FoodLine::Kruskal::Build(){
    father.resize(MAXN,0);
    edges.resize(MAXN,vector<int>(3));
    //初始化
    for(int i=1;i<=n;i++)father[i]=i;
}
int FoodLine::Kruskal::Find(int i){
    if(i!=father[i])father[i]=Find(father[i]);
    return father[i];
}
bool FoodLine::Kruskal::Union(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x!=y){
        father[x]=y;
        return true;
    }else return false;
}
void FoodLine::Kruskal::Kruskal_MST(){
    scanf("%d%d",n,m);
    Build();
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&edges[i][0],&edges[i][1],&edges[i][2]);
    }
    //注意这里申请了MAXM个位置，但实际只有m个位置，故排序是从0-m-1，即begin(),begin()+m
    sort(edges.begin(),edges.begin()+m,[](vector<int>a,vector<int>b)->bool{
        return a[2]<b[2];});
    int ans=0;
    //记录所收集到的边的条数
    int edgeCnt=0;
    for(vector<int>edge:edges){
        if(Union(edge[0],edge[1])){
            ans+=edge[2];
            edgeCnt++;
            //如果已经收集够了就退出
            if(edgeCnt==n-1)break;
        }
    }
    if(edgeCnt<n-1)cout<<"orz"<<endl;
    else cout<<ans<<endl;
}
void FoodLine::Kruskal::Test_Kruskal_MST(){
    Kruskal_MST();
}

/// @brief Prim算法 case 11
FoodLine::Prim::Prim(){
    cnt=0;
    heap.resize(MAXM,vector<int>(2));
    heap_size=0;
}
void FoodLine::Prim::Build(int n,int m){
    for(int i=0;i<=m;i++){
        heap[i][0]=0;
        heap[i][1]=0;
    }
    cnt=1;
    heap_size=0;
}

void FoodLine::Prim::Push(vector<int> num){
    int i=heap_size++;
    heap[i]=num;
    while(heap[i][1]<heap[(i-1)/2][1]){
        Swap(i,(i-1)/2);
        i=(i-1)/2;
    }

}
int FoodLine::Prim::Pop(){
    int ans=heap[0][1];
    Swap(0,--heap_size);
    int i=0,l=1;
    while(l<heap_size){
        int best=l+1<heap_size&&heap[l+1][1]<heap[l][1]?l+1:l;
        best=heap[best][1]<heap[i][1]?best:i;
        if(best==i)break;
        Swap(i,best);
        i=best;
        l=i*2+1;
    }
    return ans;
}
bool FoodLine::Prim::Empty(){
    return heap_size==0;
}
void FoodLine::Prim::Swap(int n1,int n2){
    vector<int>tmp=heap[n1];
    heap[n1]=heap[n2];  
    heap[n2]=tmp;
}
void FoodLine::Prim::Prim_MST(){
    scanf("%d%d",&n,&m );
    vector<vector<vector<int>>>Graph;
    Build(n,m);
    for(int i=0;i<=n;i++)Graph.push_back({});
    for(int i=0;i<m;i++){
        int u,v,w;
        Graph[u].push_back({v,w});
        Graph[v].push_back({u,w});
    }
    //建立小根堆
    auto cmp=[](vector<int>a,vector<int>b)->bool{return a[2]<b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    //将第一个顶点入的边入堆
    for(vector<int>edge:Graph[1])pq.push(edge);
    //设置标记位，表示当前结点访问情况
    vector<bool>set(n+1,false);
    //收集答案的计数，如果最后收集到的边的条数不是n-1个，说明没有最小生成树
    int nodeCnt=1;
    //第一个结点已经被访问过
    set[1]=true;
    //最小生成树的权值总和
    int ans=0;
    //不为空就继续
    while(!pq.empty()){
        vector<int>edge=pq.top();
        pq.pop();
        //拿出边与权值
        int next=edge[0];
        int cost=edge[1];
        //判断当前结点是否被访问过
        if(!set[next]){
            //边计数++
            nodeCnt++;
            //访问设为true
            set[next]=true;
            //计算总权值
            ans+=cost;
            //将当前结点的边也入堆
            for(vector<int>e:Graph[next])pq.push(e);
        }
    }
    if(nodeCnt<n)cout<<"orzz"<<endl;
    else cout<<ans<<endl;
}
void FoodLine::Prim::Test_Prim_MST(){
    Prim_MST();
}

/// @brief Prim算法的优化 case 12
/// @param u 
/// @param v 
/// @param w 
void FoodLine::PrimPlus::addEgde(int u,int v,int w){
    next[cnt]=head[u];
    tos[cnt]=v;
    weight[cnt]=w;
    head[u]=cnt++;
}
void FoodLine::PrimPlus::addOrUpdateOrIgnore(int ei){
    int v=tos[ei];
    int w=weight[ei];
    if(Where[v]==-1){
        heap[heap_size][0]=v;
        heap[heap_size][1]=w;
        Where[v]=heap_size++;
        heapInsert(Where[v]);
    }else if(Where[v]>=0){
        heap[Where[v]][1]=min(heap[Where[v]][1],w);
        heapInsert(Where[v]);
    }
}
void FoodLine::PrimPlus::heapInsert(int i){
    while(heap[i][1]<heap[(i-1)/2][1]){
        Swap(i,(i-1)/2);
        i=(i-1)/2;
    }
}
void FoodLine::PrimPlus::Swap(int n1,int n2){
    int a=heap[n1][0];
    int b=heap[n2][0];
    Where[a]=n2;
    Where[b]=n1;
    vector<int>tmp=heap[n1];
    heap[n1]=heap[n2];
    heap[n2]=tmp;

}
bool FoodLine::PrimPlus::Empty(){return heap_size==0;}
void FoodLine::PrimPlus::Pop(){
    //堆顶的节点的权重
    usv=heap[0][0];
    usw=heap[0][1];
    //交换堆的最后一个节点到堆顶
    Swap(0,--heap_size);
    //建立索引，准备调整堆
    heapIfy(0);
    Where[usv]=-2;
    EdgeCnt++;
}
void FoodLine::PrimPlus::heapIfy(int i){
    int l=1;
    while(l<heap_size){
        int best=l+1<heap_size&&heap[l+1][1]<heap[l][1]?l+1:l;
        best=heap[i][1]<heap[best][1]?i:best;
        if(i==best)break;
        Swap(i,best);
        i=best;
        l=i*2+1;
    }
}
void FoodLine::PrimPlus::Build(int n){
    cnt=1;
    heap_size=0;
    EdgeCnt=0;
    for(int i=0;i<=n;i++){
        head[i]=0;
        Where[i]=-1;
    }
}
void FoodLine::PrimPlus::PrimPlus_MST(){
    scanf("%d%d",&n,&m);
    Build(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addEgde(u,v,w);
        addEgde(v,v,w);
    }
    auto s=chrono::system_clock::now();
    //先取出第一个结点的所有邻居并入堆，即收集了第一个结点
    long long ans=0;
    for(int ei=head[1];ei>0;ei=next[ei]){
        addOrUpdateOrIgnore(ei);
    }
    EdgeCnt=1;
    Where[1]=-2;
    while(!Empty()){
        //开始遍历每个结点
        //取出堆顶元素
        Pop();
        ans+=(long long)usw;
        for(int ei=head[usv];ei>0;ei=next[ei]){
            addOrUpdateOrIgnore(ei);
        }
    }
    cout<<ans<<endl;
    auto e=chrono::system_clock::now();
    cout<<"运行时长为："<<chrono::duration_cast<chrono::milliseconds>(e-s).count()<<" ms "<<endl;
}
void FoodLine::PrimPlus::Test_PrimPlus_MST(){
    PrimPlus_MST();
}

/// @brief LeetCode 1168  水资源分配优化 case 13
/// @param n 
/// @param well 
/// @param pipes 
/// @return 
int FoodLine::OptimizationOfWaterAllocation::minCostToSupplyWater(int n,vector<int>well,vector<vector<int>>&pipes){
    Build(n);
    for(int i=0;i<n;i++,cnt++){
        edges[cnt][0]=0;
        edges[cnt][1]=i+1;
        edges[cnt][1]=well[i];
    }
    for(int i=0;i<pipes.size();i++){
        edges[cnt][0]=pipes[i][0];
        edges[cnt][1]=pipes[i][1];
        edges[cnt][2]=pipes[i][2];
    }
    sort(edges.begin(),edges.begin()+cnt,[](vector<int>a,vector<int>b)->bool{
        return a[2]<b[2];
    });
    int ans=0;
    for(int i=0;i<cnt;i++){
        if(Unoin(edges[i][0],edges[i][1])){
            ans+=edges[i][2];
        }
    }
    return ans;
}
void FoodLine::OptimizationOfWaterAllocation::Build(int n){
    cnt=0;
    for(int i=0;i<=n;i++){
        father[i]=i;
    }
}
int FoodLine::OptimizationOfWaterAllocation::find(int i){
    if(i!=father[i])father[i]=find(father[i]);
    return father[i];
}
bool FoodLine::OptimizationOfWaterAllocation::Unoin(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        father[fx]=fy;
        return true;
    }else return false;
}
void FoodLine::OptimizationOfWaterAllocation::Test_LC1168_OptimizationOfWaterAllocation(){
    vector<int>nums;
    vector<vector<int>>qu;
    cout<<minCostToSupplyWater(10,nums,qu)<<endl;
}


/// @brief LeetCode 1697 检查边长度限制的路径是否存在 case 14
/// @param n 
/// @param edgeList 
/// @param queries 
/// @return 
vector<bool>FoodLine::distanceLimitedPathsExist::LC1697_distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries){
    sort(edgeList.begin(),edgeList.end(),[](vector<int>a,vector<int>b)->bool{
        return a[2]<b[2];
    });
    int m=edgeList.size();
    int k=queries.size();
    for(int i=0;i<k;i++){
        questions[i][0]=queries[i][0];
        questions[i][1]=queries[i][1];
        questions[i][2]=queries[i][2];
        questions[i][3]=i;
    }
    sort(questions.begin(),questions.begin()+k,[](vector<int>a,vector<int>b)->bool{
        return a[2]<b[2];
    });
    Build(n);
    vector<bool>ans(k,false);
    for(int i=0,j=0;i<k;i++){
        for(;j<m&&edgeList[j][2]<questions[i][2];j++){
            Unoin(edgeList[j][0],edgeList[j][1]);
        }
        ans[questions[i][3]]=isSameSet(questions[i][0],questions[i][1]);
    }
    return ans;
}
void FoodLine::distanceLimitedPathsExist::Build(int n){
    for(int i=0;i<=n;i++)father[i]=i;
}   
int FoodLine::distanceLimitedPathsExist::Find(int i){
    if(i!=father[i])father[i]=Find(father[i]);
    return father[i];
}
void FoodLine::distanceLimitedPathsExist::Unoin(int x,int y){
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy)father[fy]=fx;
}
void FoodLine::distanceLimitedPathsExist::Test_LC1697_distanceLimitedPathsExist(){
    vector<vector<int>>edges;
    vector<vector<int>>quis;
    LC1697_distanceLimitedPathsExist(10,edges,quis);
}

/// @brief LeetCode 1162 地图分析 case 15
/// @param grid 
/// @return 
int WidthFirstTraversal::MaxDistance::LC1162_maxDistance(vector<vector<int>>& grid){
    vector<int>move={-1,0,1,0,-1};
    l=0,r=0;
    int n=grid.size();
    int m=grid[0].size();
    //海洋的数量
    int seas=0;
    //第一次遍历，将所有陆地进队
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                //设置为true表示已经访问过
                visited[i][j]=true;
                que[r][0]=i;
                que[r++][0]=j;
            }else{
                //否则设置为false清除脏数据
                visited[i][j]=false;
                //海洋数量++
                seas++;
            }
        }
    }
    //如果只有陆地或者只有海洋返回-1
    if(seas==0||seas==n*m)return -1;
    //从第0层开始
    int level=0;
    while(l<r){
        level++;
        //每次将每一层的所有元素都遍历，并将邻接元素入队
        int size=r-l;
        for(int k=0,x,y,nx,ny;k<size;k++){
            x=que[l][0];
            y=que[l++][1];
            //使用move数组来实现上下左右的临界元素入队
            for(int i=0;i<4;i++){
                nx=x+move[i];
                ny=y+move[i+1];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==0&&!visited[nx][ny]){
                    visited[nx][ny]=true;
                    que[r][0]=nx;
                    que[r++][0]=ny;
                }
            }
        }
    }
    //返回最后一层-1层为ans
    return level-1;
}
void WidthFirstTraversal::MaxDistance::Test_LC1162_maxDistance(){
    vector<vector<int>>grid={{1,0,1},{0,0,0},{1,0,1}};
    cout<<LC1162_maxDistance(grid)<<endl;
}

/// @brief LeetCode 691 贴纸拼词 case 16
/// @param stickers 
/// @param target 
/// @return 
int WidthFirstTraversal::MinStickers::LC691_minStickers(vector<string>& stickers, string target){
    for(int i=0;i<26;i++)Graph[i].clear();
    visited.clear();
    for(string str:stickers){
        //先对当前遍历到的字符串排序
        sort(str.begin(),str.end());
        //再遍历当前字符串的每个字符，将其加入到图中
        for(int i=0;i<str.size();i++){
            //第一个字符肯定加入图中，后面的字符如果与前面的字符重复，就不用重复加入了
            if(i==0||str[i-1]!=str[i])Graph[str[i]-'a'].push_back(str);
        }
    }
    sort(target.begin(),target.end());
    visited.insert(target);
    l=0,r=0;
    que[r++]=target;
    int level=1;
    while(l<r){
        int size=r-l;
        //遍历整个队列进行添加或出队操作
        for(int i=0;i<size;i++){
            string cur=que[l++];
            //遍历图来寻找可以匹配当前字符串的字符串
            for(string s:Graph[cur[0]-'a']){
                //如果有一个字符串可以和当前的字符串完全匹配则next==""
                string next=Next(cur,s);
                if(next=="")return level;
                if(!visited.count(next)){
                    visited.insert(next);
                    que[r++]=next;
                }
            }
        }
        level++;
    }
    return -1;
}
string WidthFirstTraversal::MinStickers::Next(string cur,string s){
    string ans;
    for(int i=0,j=0;i<cur.size();){
        if(j==s.size())ans+=cur[i++];
        else{
            if(cur[i]<s[j])ans+=cur[i++];
            else if(cur[i]>s[j])j++;
            else{
                i++;
                j++;
            }
        }
    }
    return ans;
}
WidthFirstTraversal::MinStickers::MinStickers(){
    que.resize(MAXN);
    for(int i=0;i<26;i++)Graph.push_back({});
}
void WidthFirstTraversal::MinStickers::Test_LC691_minStickers(){
    vector<string>si;
    string ta;
    cout<<LC691_minStickers(si,ta)<<endl;
}

/// @brief LeetCode 2290 到达角落需要移除的障碍物的最小数目 case 17
/// @param grid 
/// @return 
int WidthFirstTraversal::MinimumObstacles::LC2290_minimumObstacles(vector<vector<int>>& grid){
    vector<int>move={-1,0,1,0,-1};
    int n=grid.size();
    int m=grid[0].size();
    //用来记录当前结点的最小总权值
    vector<vector<int>>distances(n,vector<int>(m,INT_MAX));
    //用来进行01BFS
    deque<vector<int>>dq;
    //初始时起点先进入队列
    dq.push_back({0,0});
    //起点的最小权值为0
    distances[0][0]=0;
    while(!dq.empty()){
        //取出头部的结点
        vector<int>record=dq.front();
        dq.pop_front();
        int x=record[0];
        int y=record[1];
        //根据题意，如果已经走到了最后一个结点则返回从起点到最后一个结点的最小权值
        if(x==n-1&&y==m-1)return distances[x][y];
        //通过move数组实现(x-1,y)(x,y+1)(x+1,y)(x,y-1);
        for(int i=0;i<4;i++){
            int nx=x+move[i];
            int ny=y+move[i+1];
            //如果越界或者当前的最小权值已经无法被新的权值更新为最小的了，就跳过
            if(nx<0||nx>=n||ny<0||ny>=m||distances[x][y]+grid[nx][ny]>=distances[nx][ny])continue;
            distances[nx][ny]=distances[x][y]+grid[nx][ny];
            //如果当前路径为0，则将从头部进入
            if(grid[nx][ny]==0)dq.push_front({nx,ny});
            //否则从尾部进入
            else dq.push_back({nx,ny});
        }
    }
    return -1;
}
void WidthFirstTraversal::MinimumObstacles::Test_LC2290_minimumObstacles(){
    vector<vector<int>>grid={{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    cout<<LC2290_minimumObstacles(grid)<<endl;
}

/// @brief LeetCode 1368 使网格至少有一条有效路径的最小代价 case 18
/// @param grid 
/// @return 
int WidthFirstTraversal::MinCost::LC1368_minCost(vector<vector<int>>& grid){
    //move数组来配合上下左右
    vector<vector<int>>move={{},{0,1},{0,-1},{1,0},{-1,0}};
    //路径权值最小值数组
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>distances(n,vector<int>(m,INT_MAX));
    //队列
    deque<vector<int>>dq;
    dq.push_back({0,0});
    distances[0][0]=0;
    while(!dq.empty()){
        vector<int>record=dq.front();
        dq.pop_front();
        int x=record[0];
        int y=record[1];
        if(x==n-1&&y==m-1)return distances[x][y];
        for(int i=1;i<=4;i++){
            int nx=x+move[i][0];
            int ny=y+move[i][1];
            //如果当前要走的方向与当前结点的方向一致，那么权重就为0，否则为1
            int weight=grid[x][y]==i?0:1;
            if(nx<0||nx>=n||ny<0||ny>=m&&weight+distances[x][y]>=distances[nx][ny])continue;
            distances[nx][ny]=distances[x][y]+weight;
            //如果当前要走的方向与当前结点的方向一致，那么就从头部入队
            if(grid[x][y]==i)dq.push_front({nx,ny});
            else dq.push_back({nx,ny});
        }
    }
    return -1;
}
void WidthFirstTraversal::MinCost::Test_LC1368_minCost(){
    vector<vector<int>>grid;
    cout<<LC1368_minCost(grid)<<endl;
}

/// @brief LeetCode 407 接雨水II case 19
/// @param heightMap 
/// @return 
int WidthFirstTraversal::trapRainWater::LC407_trapRainWater(vector<vector<int>>& heightMap){
    //move数组来实现上下左右移动
    vector<int>move={-1,0,1,0,-1};
    //建立优先队列根据水线高度底的优先
    int n=heightMap.size();
    int m=heightMap[0].size();
    auto cmp=[](vector<int>a,vector<int>b)->bool{return a[2]>b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>dq(cmp);
    //建立访问数组
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    //先遍历一遍将所有边界入队
    for(int i=0;i<n;i++){
        for(int j=0;i<m;j++){
            if(i==0||i==n-1||j==0||j==m-1){
                visited[i][j]=true;
                //边界的水线高度就是自己的高度
                dq.push({i,j,heightMap[i][j]});
            }
        }
    }
    //结果
    int ans=0;
    //再遍历队列中的元素，从元素的四个方向逐渐入队
    while(!dq.empty()){
        vector<int>record=dq.top();
        dq.pop();
        int r=record[0];
        int c=record[1];
        int w=record[2];
        //自身能收集到的水取决于自己的水线高度-自己的高度
        ans+=w-heightMap[r][c];
        for(int i=0,nr,nc;i<4;i++){
            nr=r+move[i];
            nc=c+move[i+1];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&!visited[nr][nc]){
                visited[nr][nc]=true;
                //水线高度取决于自身高度与上一个高度的最大值
                dq.push({nr,nc,max(w,heightMap[nr][nc])});
            }
        }
    }
    return ans;
}
void WidthFirstTraversal::trapRainWater::Test_LC407_trapRainWater(){
    vector<vector<int>>grid;
    cout<<LC407_trapRainWater(grid)<<endl;
}

/// @brief LeetCode 126 单词接龙II case 20
/// @param beginWord 
/// @param endWord 
/// @param wordList 
/// @return 
vector<vector<string>>WidthFirstTraversal::FindLadders::LC126_findLadders(string beginWord, string endWord, vector<string>& wordList){
    Build(wordList);
    if(!dict.count(endWord))return ans;
    //begin->end去寻找路径，并建图
    if(LC126_findLadders_BFS(beginWord,endWord)){
        //找到了，就从end->begin去搜索并收集路径
        LC126_findLadders_DFS(endWord,beginWord);
    }
    return ans;
}
void WidthFirstTraversal::FindLadders::Build(vector<string>&wordList){
    for(string&word:wordList)dict.insert(word);
    Graph.clear();
    ans.clear();
    curLevel.clear();
    nextLevel.clear();
}
bool WidthFirstTraversal::FindLadders::LC126_findLadders_BFS(string beginword,string endword){
    bool find=false;
    //相当于队列，并且带去重，从curLevel中去遍历当前的单词在只修改一个字母的情况下,能变成单词表里的谁
    curLevel.insert(beginword);
    while(!curLevel.empty()){
        //我们希望curLevel表从单词表dict中收集到的单词不会再重复收集，所以将curLevel中收集到的单词在dict单词表中也对应的删掉
        for(string cur:curLevel){
            if(dict.count(cur))dict.erase(cur);
        }
        for(string word:curLevel){
            //word:去扩
            //每个位置，字符从a-z换一遍，检查在词表中是否存在，并且避免跟自己重复
            for(int i=0;i<word.size();i++){
                //从a-z依次尝试
                for(char ch='a';ch<='z';ch++){
                    string str=word;
                    str[i]=ch;
                    //保证在词表中有这个单词，并且不与原来的单词重复
                    if(dict.count(str)&&str!=word){
                        //这个单词就是endword那么就将find标记为找到了
                        if(str==endword)find=true;
                        Graph[str].push_back(word);
                        //当前层生成的str只留一份
                        if(!nextLevel.count(str))nextLevel.insert(str);
                    }
                }
            }
        }
        if(find)return true;
        else {
            //更新curLevel表为nextLevel，继续收集
            unordered_set<string>tmp=curLevel;
            curLevel=nextLevel;
            nextLevel=tmp;
            nextLevel.clear();
        }
    }
    return false;
}
void WidthFirstTraversal::FindLadders::LC126_findLadders_DFS(string endword,string beginwrod){
    //将此单词进入路径
    path.push_back(endword);
    //找到了一条路径就进入结果集
    if(endword==beginwrod){
        ans.push_back(path);
        //反向收集的路径，进入ans之后将路径反过来即可
        reverse(ans.back().begin(),ans.back().end());
    }
    //否则就遍历图中的每个单词
    else if(Graph.count(endword)){
        for(string next:Graph[endword]){
            LC126_findLadders_DFS(next,beginwrod);
        }
    }
    //回溯
    path.pop_back();
}
void WidthFirstTraversal::FindLadders::Test_LC126_findLadders(){
    string st="hit",sp="cog";
    vector<string>words={"hot","dot","dog","lot","log","cog"};
    for(auto&word:LC126_findLadders(st,sp,words)){
        for(auto&w:word){
            cout<<w<<"->";
        }
        cout<<endl;
    }
}

/// @brief LeetCode 127 单词接龙 case 21
/// @param beginWord 
/// @param endWord 
/// @param wordList 
/// @return 
int WidthFirstTraversal::LadderLength::LC127_ladderLength(string beginWord, string endWord, vector<string>& wordList){
    //先将字符串数组转化为哈希Set方便查询
    unordered_set<string>dict;
    for(const string&word:wordList)dict.insert(word);

    //特殊判断，如果单词表里没有endWord这个单词直接返回0
    if(!dict.count(endWord))return 0;

    //数量较小的一侧
    unordered_set<string>SmallSet;
    //数量较大的一侧
    unordered_set<string>BigSet;
    //由数量较小的一侧扩展出来的下一层列表
    unordered_set<string>nextLevel;
    SmallSet.insert(beginWord);
    BigSet.insert(endWord);

    /*双向搜索，开始的长度为2，当SmallSet为空时表示在beginWord或者endWord的双向扩展下，没有找到中间相遇点，
    即在单词表中不存在beginWord到endWord的变化*/
    for(int len=2;!SmallSet.empty();len++){
        //遍历SmallSet中的每个单词，逐一变化进行扩展
        for(string word:SmallSet){
            //将word的每个位置都做一次变换
            for(int j=0;j<word.size();j++){
                //将word交给str进行变化
                string str=word;
                //从a-z都试一遍
                for(char ch='a';ch<='z';ch++){
                    str[j]=ch;
                    //变化为word就直接跳过
                    if(str!=word){
                        //当这个变化后的单词在BigSet中找到是，就是两个出发点所扩展的路径相遇了，直接返回len作为答案
                        if(BigSet.count(str))return len;
                        //否则查询这个单词是否出现在单词表里，如果没有直接跳过，否则加入 
                        if(dict.count(str)){
                            //将其从单词表里删除，防止重复生成str
                            dict.erase(str);
                            //将其加入到nextLevel中作为扩展出来的结点
                            nextLevel.insert(str);
                        }
                    }
                }
            }
        }
        //将这三个表进行更新，nextLevel与BigSet谁小谁作为下一轮的SmallSet
        if(nextLevel.size()<=BigSet.size()){
            unordered_set<string>tmp=SmallSet;
            SmallSet=nextLevel;
            //nextLevel做下一轮的SmallSet时，BigSet就保持原来的样子即可
            nextLevel=tmp;
        }else{
            unordered_set<string>tmp=BigSet;
            BigSet=nextLevel;
            nextLevel=SmallSet;
            SmallSet=tmp;
        }
        nextLevel.clear();
    }
    return 0;
}
void WidthFirstTraversal::LadderLength::Test_LC127_ladderLength(){
    string st="hit",sp="cog";
    vector<string>words={"hot","dot","dog","lot","log","cog"};
    cout<<LC127_ladderLength(st,sp,words)<<endl;
}

/// @brief LGP4799 世界冰球锦标赛 cace 22
void WidthFirstTraversal::SnacksWayBuyTickets::LGP4799_SnacksWayBuyTickets(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<LGP4799_Compute()<<endl;
}
long long WidthFirstTraversal::SnacksWayBuyTickets::LGP4799_Compute(){
    /*范围左闭右开*/
    int lsize=LGP4799_f(0,n>>1,0,m,lnum,0);
    int rsize=LGP4799_f(n>>1,n,0,m,rnum,0);
    /*排序*/
    sort(lnum.begin(),lnum.begin()+lsize);
    sort(rnum.begin(),rnum.begin()+rsize);
    long long ans=0;
    /*双指针*/
    for(int l=lsize-1,r=0;l>=0;l--){
        while(r<rsize&&lnum[l]+rnum[r]<=m){
            r++;
        }
        ans+=r;
    }
    return ans;
}
int WidthFirstTraversal::SnacksWayBuyTickets::LGP4799_f(int i,int e,long long s,long long w,vector<long long>&ans,int j){
    if(s>w)return j;
    //如果没有超过w，但是已经到了终止位置，往ans里填入即可
    if(i==e)ans[j++]=s;
    else{
        //不要arr[i]位置的数
        j=LGP4799_f(i+1,e,s,w,ans,j);
        //要arr[i]位置的数
        j=LGP4799_f(i+1,e,s+arr[i],w,ans,j);
    }
    return j;
}
void WidthFirstTraversal::SnacksWayBuyTickets::Test_LGP4799_SnacksWayBuyTickets(){
    LGP4799_SnacksWayBuyTickets();
}

/// @brief LeetCode 1755 最接近目标值的子序列和 case 23
/// @param nums 
/// @param goal 
/// @return 
int WidthFirstTraversal::MinAbsDifference::LC1755_minAbsDifference(vector<int>& nums, int goal){
    int n=nums.size();
    //剪枝，优化常数时间的复杂度
    long long Max=0;
    long long Min=0;
    for(int i=0;i<n;i++){
        if(nums[i]>=0)Max+=nums[i];
        else Min+=nums[i];
    }
    //如果数组种所有的整数比目标值还小，那么答案就是|max-goal|
    if(Max<goal)return abs(Max-goal);
    //如果数组中的所有正数比目标值还大，那么答案就是|min-goal|
    if(Min>goal)return abs(Min-goal);

    //原始数字排序，递归时还能剪枝,常数时间的优化
    sort(nums.begin(),nums.end());
    fill=0;
    LC1755_minAbsDifference_f(nums,0,n>>1,0,lsum);
    int lsize=fill;
    fill=0;
    LC1755_minAbsDifference_f(nums,n>>1,n,0,rsum);
    int rsize=fill;
    sort(lsum.begin(),lsum.begin()+lsize);
    sort(rsum.begin(),rsum.begin()+rsize);
    int ans=INT_MAX;
    for(int i=0,j=rsize-1;i<lsize;i++){
        while(j>0&&abs(lsum[i]+rsum[j-1]-goal)<=abs(lsum[i]+rsum[j]-goal))j--;
        ans=min(ans,(int)abs((long long)goal-lsum[i]-rsum[j]));
    }
    return ans;
}
void WidthFirstTraversal::MinAbsDifference::LC1755_minAbsDifference_f(vector<int>&arr,int i,int e,long long s,vector<long long>&ans){
    if(i==e)ans[fill++]=s;
    else{
        //从i+1开始记录与arr[i]相同的数有几个
        int j=i+1;
        while(j<e&&arr[j]==arr[i])j++;
        //从零个arr[i]到j-i个arr[i]的展开
        for(int k=0;k<=j-i;k++){
            LC1755_minAbsDifference_f(arr,j,e,s+k*arr[i],ans);
        }
    }
}
void WidthFirstTraversal::MinAbsDifference::Test_LC1755_minAbsDifference(){
    vector<int>nums={7,-9,15,-2};
    cout<<LC1755_minAbsDifference(nums,-5)<<endl;
}

/// @brief LeetCode 743 网络延迟时间 case 24
/// @param times 
/// @param n 
/// @param k 
/// @return 
int HierarchicalDiagramShortestPath::DijkstraAlorgithm::LC743_networkDelayTime(vector<vector<int>>& times, int n, int k){
    //图
    vector<vector<vector<int>>>Graph;
    for(int i=0;i<=n;i++)Graph.push_back({});
    for(vector<int> edge:times)Graph[edge[0]].push_back({edge[1],edge[2]});
    //当前节点到源点的最短距离
    vector<int>Distance(n+1,INT_MAX);
    //当前节点是否被弹出过
    vector<int>Visited(n+1,false);
    //小根堆
    auto cmp=[](vector<int>a,vector<int>b)->bool{return a[1]>b[1];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    pq.push({k,0});
    Distance[k]=0;
    while(!pq.empty()){
        //弹出堆头节点
        int u=pq.top()[0];
        pq.pop();
        //判断是否已经被弹出过
        if(Visited[u])continue;
        Visited[u]=true;
        //遍历此节点的所有邻接节点
        for(vector<int>edge:Graph[u]){
            int v=edge[0];
            int w=edge[1];
            //判断当前邻接节点是否被弹出过，并且当前节点的Distance是否可以被更新为更小
            if(!Visited[v]&&Distance[u]+w<Distance[v]){
                Distance[v]=Distance[u]+w;
                pq.push({v,Distance[u]+w});
            }
        }
    }
    //遍历整个Distance是否都有有效距离，并取出最大值
    int ans=INT_MIN;
    for(int i=1;i<=n;i++){
        if(Distance[i]==INT_MAX)return -1;
        ans=max(ans,Distance[i]);
    }
    return ans;
}
void HierarchicalDiagramShortestPath::DijkstraAlorgithm::Test_LC743_networkDelayTime(){
    vector<vector<int>>times;
    cout<<LC743_networkDelayTime(times,4,2)<<endl;
}

/// @brief 基于反向索引堆实现的Dijkstra算法 case 25
HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::InvertedIndexingDijkstra(){
    Heap.resize(MAXN);
    Where.resize(MAXN);
    Heap_size=0;
    Head.resize(MAXN);
    next.resize(MAXM);
    tos.resize(MAXM);
    weight.resize(MAXM);
    cnt=1;
    Distance.resize(MAXN);
}
void HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::Build(int n){
    cnt=1;
    Heap_size=0;
    for(int i=0;i<=n;i++){
        Head[i]=0;
        Where[i]=-1;
        Distance[i]=INT_MAX;
    }
}
void HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::addEdge(int u,int v,int w){
    next[cnt]=Head[u];
    tos[cnt]=v;
    weight[cnt]=w;
    Head[u]=cnt++;
}
int HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::LC743_networkDelayTime(vector<vector<int>>& times, int n, int k){
    Build(n);
    for(vector<int>edge:times)addEdge(edge[0],edge[1],edge[2]);
    addOrUpdateOrIgnore(k,0);
    while(!Empty()){
        int u=Pop();
        for(int ei=Head[u];ei>0;ei=next[ei])addOrUpdateOrIgnore(tos[ei],Distance[u]+weight[ei]);
    }
    for(int i=1;i<=n;i++){
        cout<<Distance[i]<<" ";
    }
    cout<<endl;
    return 1;
}
void HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::addOrUpdateOrIgnore(int v,int c){
    //未进过堆
    if(Where[v]==-1){
        //将其入堆
        Heap[Heap_size]=v;
        //更改Distance为当前c(Distance[u]+w)
        Distance[v]=c;
        //修改Where[v]为当前堆内索引
        Where[v]=Heap_size++;
        //更新堆
        HeapInsert(Where[v]);
    }else if(Where[v]>=0){
        //取最小值，然后更新堆
        Distance[v]=min(Distance[v],c);
        HeapInsert(Where[v]);
    }
}
void HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::HeapInsert(int i){
    //自底向上堆化
    while(Distance[Heap[i]]<Distance[Heap[(i-1)/2]]){
        Swap(i,(i-1)/2);
        i=(i-1)/2;
    }
}
void HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::Swap(int i,int j){
    /*对于堆：Heap                  对于Where
        [....a........b......]      [....i.......j.....]
        [....i........j......]      [....a.......b.....]
        交换后
        [....b........a......]      [....j.......i.....]
        [....i........j......]      [....a.......b.....]*/

    int tmp=Heap[i];
    Heap[i]=Heap[j];
    Heap[j]=tmp;
    //交换前Heap[i]=a   Heap[j]=b;
    //交换后Heap[i]=b   Heap[j]=a;
    //堆交换之后Head[i]所代表的节点就是b此时Where[b]的索引应该是i
    Where[Head[i]]=i;
    //堆交换之后Head[j]所代表的节点就是a此时Where[a]的索引应该是j
    Where[Heap[j]]=j;
}
int HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::Pop(){
    int ans=Heap[0];
    //交换0位置与最后一个位置
    Swap(0,--Heap_size);
    //自顶向下堆化
    HeapFiy(0);
    //更改Where
    Where[ans]=-2;
    return ans;
}
void HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::HeapFiy(int i){
    int l=1;
    //递归子节点堆化
    while(l<Heap_size){
        int best=l+1<Heap_size&&Distance[Heap[l+1]]<Distance[Heap[l]]?l+1:l;
        best=Distance[Heap[best]]<Distance[Heap[i]]?best:i;
        if(i==best)break;
        Swap(i,best);
        i=best;
        //l是i的左节点索引号为i*2+1
        l=i*2+1;
    }
}
bool HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::Empty(){
    return Heap_size==0;
}
void HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::Test_LC743_networkDelayTime(){
    vector<vector<int>>times={{1,2,2},{2,3,2},{2,4,1},{1,3,5},{3,4,3},{1,4,4}};
    cout<<LC743_networkDelayTime(times,4,1)<<endl;
}

/// @brief LeetCode 1631 消耗最小体力值的路径 case 26
/// @param heights 
/// @return 
int HierarchicalDiagramShortestPath::MinimumEffortPath::LC1631_minimumEffortPath(vector<vector<int>>& heights){
    int n=heights.size();
    int m=heights[0].size();
    //沿途的结果集
    vector<vector<int>>Distance(n,vector<int>(m,INT_MAX));
    //优先队列（小根堆）
    auto cmp=[](vector<int>&a,vector<int>&b)->bool{return a[2]>b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    //是否弹出过
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    //0，0，0位置的节点入堆
    pq.push({0,0,0});
    //起始位置的最大绝对值路径为0
    Distance[0][0]=0;
    //开始遍历
    while(!pq.empty()){
        vector<int>record=pq.top();
        pq.pop();
        int x=record[0];
        int y=record[1];
        int c=record[2];
        //如果已经弹出过，直接跳过
        if(visited[x][y])continue;
        //如果就是最后一个节点，直接返回答案为c
        if(x==n-1&&y==m-1)return c;
        //修改visited
        visited[x][y]=true;
        //开始上下左右遍历
        for(int i=0;i<4;i++){
            int nx=x+Move[i];
            int ny=y+Move[i+1];
            //不越界，且没有别访问过
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]){
                //取出其路径权值（绝对值）
                int nc=max(c,abs(heights[x][y]-heights[nx][ny]));
                //如果这个值比自己Distance[nx][ny]点的值还小，更新此值，并入堆
                if(nc<Distance[nx][ny]){
                    Distance[nx][ny]=nc;
                    pq.push({nx,ny,nc});
                }
            }
        }
    }
    //如果遍历完也没有路返回-1
    return -1;
}
void HierarchicalDiagramShortestPath::MinimumEffortPath::Test_LC1631_minimumEffortPath(){
    vector<vector<int>>he;
    cout<<LC1631_minimumEffortPath(he)<<endl;
 }

/// @brief LeetCode 778 在水位升高的泳池中游泳 case 27
/// @param grid 
/// @return 
int HierarchicalDiagramShortestPath::SwimInWater::LC778_swimInWater(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    //到达每个格子的最小代价
    vector<vector<int>>Distance(n,vector<int>(m,INT_MAX));
    //优先队列
    auto cmp=[](vector<int>&a,vector<int>&b)->bool{return a[2]>b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    //访问与否
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    //初次要等到grid[0][0]才能出发
    Distance[0][0]=grid[0][0];
    //出发点入堆
    pq.push({0,0,grid[0][0]});
    //遍历
    while(!pq.empty()){
        auto record=pq.top();
        pq.pop();
        int x=record[0];
        int y=record[1];
        int c=record[2];
        //如果已经访问过，跳过
        if(visited[x][y])continue;
        //如果是最后一个节点，输出结果
        if(x==n-1&&y==m-1)return c;
        //修改visited
        visited[x][y]=true;
        //遍历邻接点
        for(int i=0,nx,ny;i<4;i++){
            nx=x+Move[i];
            ny=y+Move[i+1];
            //越界以及是否访问过
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&!visited[nx][ny]){
                //取最大的代价
                int nc=max(c,grid[nx][ny]);
                //可以更新为较小的代价
                if(nc<Distance[nx][ny]){
                    Distance[nx][ny]=nc;
                    pq.push({nx,ny,nc});
                }
            }
        }
    }
    return -1;
}
void HierarchicalDiagramShortestPath::SwimInWater::Test_LC778_swimInWater(){
    vector<vector<int>>grid;
    cout<<LC778_swimInWater(grid)<<endl;
}

/// @brief LeetCode 864 获取所有钥匙的最短路径 case 28
/// @param grid 
/// @return 
int HierarchicalDiagramShortestPath::ShortestPathAllKeys::LC864_shortestPathAllKeys(vector<string>& grid){
    Build(grid);
    int Level=1;
    while(l<r){
        for(int k=0,size=r-l,x,y,s;k<size;k++){
            x=que[l][0];
            y=que[l][1];
            s=que[l++][2];
            for(int i=0,nx,ny,ns;i<4;i++){
                nx=x+Move[i];
                ny=y+Move[i+1];
                ns=s;
                //越界或者有阻碍
                if(nx<0||nx==n||ny<0||ny==m||grid[nx][ny]=='#')continue;
                //是锁，但没有对应的钥匙
                if(grid[nx][ny]>='A'&&grid[nx][ny]<='F'&&((ns&(1<<(grid[nx][ny]-'A')))==0))continue;
                //是某一把钥匙,将这把钥匙加入状态
                if(grid[nx][ny]>='a'&&grid[nx][ny]<='f')ns|=1<<(grid[nx][ny]-'a');
                //如果ns已经是key了说明钥匙集齐了，直接退出
                if(ns==key)return Level;
                if(!visited[nx][ny][ns]){
                    visited[nx][ny][ns]=true;
                    que[r][0]=nx;
                    que[r][1]=ny;
                    que[r++][2]=ns;
                }
            }
        }
        Level++;
    }
    return -1;
}
void HierarchicalDiagramShortestPath::ShortestPathAllKeys::Build(vector<string>& grid){
    //队列初始化，记录钥匙有几个
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='@'){
                que[r][0]=i;
                que[r][1]=j;
                que[r++][2]=0;
            }
            //key表示为00011时就是有ba钥匙,也就是两个钥匙
            if(grid[i][j]>='a'&&grid[i][j]<='f')key|=1<<(grid[i][j]-'a');
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int s=0;s<=key;s++){
                visited[i][j][s]=false;
            }
        }
    }
}
void HierarchicalDiagramShortestPath::ShortestPathAllKeys::Test_LC864_shortestPathAllKeys(){
    vector<string>grid;
    cout<<LC864_shortestPathAllKeys(grid)<<endl;
}

/// @brief LCP 35 电动车游城市 case 29
/// @param paths 
/// @param cnt 
/// @param start 
/// @param end 
/// @param charge 
/// @return 
int HierarchicalDiagramShortestPath::ElectricCarPlan::LCP35_electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge){
    int n=charge.size();
    //建图
    vector<vector<vector<int>>>Graph;
    for(int i=0;i<n;i++)Graph.push_back({});
    for(vector<int>path:paths){
        Graph[path[0]].push_back({path[1],path[2]});
        Graph[path[1]].push_back({path[0],path[2]});
    }
    //（点，到达这个点的电量）图上的点
    vector<vector<int>>Distance(n,vector<int>(cnt+1,INT_MAX));
    Distance[start][0]=0;
    //访问标记位
    vector<vector<bool>>visited(n,vector<bool>(cnt+1,false));
    //优先队列
    auto cmp=[](vector<int>&a,vector<int>&b)->bool{return a[2]>b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    //当前所在点、当前电量、当前花费
    pq.push({start,0,0});
    while(!pq.empty()){
        vector<int>record=pq.top();
        pq.pop();
        int cur=record[0];
        int power=record[1];
        int cost=record[2];
        //此状态已被遍历过
        if(visited[cur][power])continue;
        //当前点是目标点
        if(cur==end)return cost;
        visited[cur][power]=true;
        //选择充一格点，改变当前点的状态
        if(power<cnt){
            //充一格电
            //状态改变后的花费是否小于已经记录的花费
            if(!visited[cur][power+1]&&cost+charge[cur]<Distance[cur][power+1]){
                Distance[cur][power+1]=cost+charge[cur];
                //新状态进堆
                pq.push({cur,power+1,cost+charge[cur]});
            }
        }
        //遍历当前点的所有邻接节点
        for(vector<int>edge:Graph[cur]){
            //邻接节点
            int nextCity=edge[0];
            //到达邻接结点后剩余的电量
            int restPower=power-edge[1];
            //到达邻接节点时共花费
            int nextCost=cost+edge[1];
            //如果剩余电量位负数不去、如果此状态已经出过队，不进去、如果此状态不可更新不进去
            if(restPower>=0&&!visited[nextCity][restPower]&&nextCost<Distance[nextCity][restPower]){
                Distance[nextCity][restPower]=nextCost;
                pq.push({nextCity,restPower,nextCost});
            }
        }
    }
    return -1;
}
void HierarchicalDiagramShortestPath::ElectricCarPlan::Test_LCP35_electricCarPlan(){
    vector<vector<int>>path={{1,3,3},{3,2,1},{2,1,3},{0,1,4},{3,0,5}};
    vector<int>nums={2,10,4,1};
    cout<<LCP35_electricCarPlan(path,6,1,0,nums)<<endl;
}

/// @brief case 30
/// @param grid 
/// @param startX 
/// @param startY 
/// @param targetX 
/// @param targetY 
/// @return 
int HierarchicalDiagramShortestPath::AStarAlgorithm::MinDistance1(vector<vector<int>>&grid,int startX,int startY,int targetX,int targetY){
    if(grid[startX][startY]==0||grid[targetX][targetY]==0)return -1;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
    distance[startX][startY]=1;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    //[0]:行    [1]:列  [2]:从源点出发到目标点的距离
    auto cmp=[](vector<int>&a,vector<int>&b)->bool{return a[2]>b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    pq.push({startX,startY,1});
    while(!pq.empty()){
        vector<int>cur=pq.top();
        pq.pop();
        int x=cur[0];
        int y=cur[1];
        if(visited[x][y])continue;
        visited[x][y]=true;
        if(x==targetX&&y==targetY)return distance[x][y];
        for(int i=0;i<4;i++){
            int nx=x+Move[i];
            int ny=y+Move[i+1];
            if(nx>=0&&ny>=0&&nx<n&&ny<n&&grid[nx][ny]==1&&!visited[nx][ny]&&distance[x][y]+1<distance[nx][ny]){
                pq.push({nx,ny,distance[x][y]+1});
                distance[nx][ny]=distance[x][y]+1;
            }
        }
    }
    return -1;
}
int HierarchicalDiagramShortestPath::AStarAlgorithm::MinDistance2(vector<vector<int>>&grid,int startX,int startY,int targetX,int targetY){
    if(grid[startX][startY]==0||grid[targetX][targetY]==0)return -1;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
    distance[startX][startY]=1;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    //[0]:行    [1]:列  [2]:从源点出发到目标点的距离
    auto cmp=[](vector<int>&a,vector<int>&b)->bool{return a[2]>b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    //[2]:当前点到源点的距离+当前点到目标点的曼哈顿距离
    pq.push({startX,startY,1+MinDistance2_f1(startX,startY,targetX,targetY)});
    while(!pq.empty()){
        vector<int>cur=pq.top();
        pq.pop();
        int x=cur[0];
        int y=cur[1];
        if(visited[x][y])continue;
        visited[x][y]=true;
        if(x==targetX&&y==targetY)return distance[x][y];
        for(int i=0,nx,ny;i<4;i++){
            nx=x+Move[i];
            ny=y+Move[i+1];
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&!visited[nx][ny]&&grid[nx][ny]==1&&distance[x][y]+1<distance[nx][ny]){
                distance[nx][ny]=distance[x][y]+1;
                pq.push({nx,ny,distance[x][y]+1+MinDistance2_f1(nx,ny,targetX,targetY)});
            }
        }
    }
    return -1;
}
int HierarchicalDiagramShortestPath::AStarAlgorithm::MinDistance2_f1(int SX,int SY,int EX,int EY){
    return abs(EX-SX)+abs(EY-SY);
}
int HierarchicalDiagramShortestPath::AStarAlgorithm::MinDistance2_f2(int SX,int SY,int EX,int EY){
    return max(abs(EX-SX),abs(EY-SY));
}
double HierarchicalDiagramShortestPath::AStarAlgorithm::MinDistance2_f3(int SX,int SY,int EX,int EY){
    return sqrt(pow(EX-SX,2)+pow(EY-SY,2));
}
void HierarchicalDiagramShortestPath::AStarAlgorithm::Test_MinDistance(){

}

/// @brief case 31
void HierarchicalDiagramShortestPath::Floyd::floyds(){
    //O(N^3)的过程
    //枚举每个跳板
    //注意，跳板要最先枚举
    for(int bridge=0;bridge<distance.size();bridge++){
        for(int i=0;i<distance.size();i++){
            for(int j=0;j<distance.size();j++){
                if(distance[i][bridge]!=INT_MAX
                    &&distance[bridge][j]!=INT_MAX
                    &&distance[i][j]>distance[i][bridge]+distance[bridge][j])
                distance[i][j]=distance[i][bridge]+distance[bridge][j];
            }
        }
    }
}
void HierarchicalDiagramShortestPath::Floyd::Test_floyds(){
    distance={{0,5,1},{5,0,2},{1,2,0}};
    floyds();
    cout<<endl;
}

/// @brief LeetCode 787 k站中转内最便宜的航班 case 32
/// @param n 
/// @param flights 
/// @param src 
/// @param dst 
/// @param k 
/// @return 
int HierarchicalDiagramShortestPath::Bellman_Ford::LC_787findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
    vector<int>cur(n,INT_MAX);
    cur[src]=0;
    for(int i=0;i<=k;i++){
        vector<int>Next=cur;
        for(vector<int>edge:flights){
            if(cur[edge[0]]!=INT_MAX){
                Next[edge[1]]=min(Next[edge[1]],cur[edge[1]]+edge[2]);
            }
        }
        cur=Next;
    }
    return cur[dst]==INT_MAX?-1:cur[dst];
}
void HierarchicalDiagramShortestPath::Bellman_Ford::LC787_findCheapestPrice(){

}


void HierarchicalDiagramShortestPath::LGP3385_SPFA::Build(int n){
    cnt=1;
    l=0,r=0;
    for(int i=0;i<=n;i++){
        head[i]=0;
        distances[i]=INT_MAX;
        updateCnt[i]=0;
        enters[i]=false;
    }
}
bool HierarchicalDiagramShortestPath::LGP3385_SPFA::Spfa(int n){
    distances[1]=0;
    updateCnt[1]++;
    que[r++]=1;
    enters[1]=true;
    while(l<r){
        int u=que[l++];
        enters[u]=false;
        for(int edge=head[u],v,w;edge>0;edge=nexts[edge]){
            v=tos[edge];
            w=weight[edge];
            if(distances[u]+w<distances[v]){
                distances[v]=distances[u]+w;
                if(!enters[v]){
                    if(updateCnt[v]++==n)return true;
                    que[r++]=v;
                    enters[v]=true;
                }
            }
        }
    }
    return  false;
}
void HierarchicalDiagramShortestPath::LGP3385_SPFA::addEdge(int u,int v,int w){
    nexts[cnt]=head[u];
    tos[cnt]=v;
    weight[cnt]=w;
    head[u]=cnt++;
}
void HierarchicalDiagramShortestPath::LGP3385_SPFA::SPFA(){
    int cases;
    cin>>cases;
    for(int i=0,n,m;i<cases;i++){
        cin>>n>>m;
        Build(n);
        for(int j=0,u,v,w;j<m;j++){
            cin>>u>>v>>w;
            if(w>=0){
                addEdge(u,v,w);
                addEdge(v,u,w);
            }else addEdge(u,v,w);
        }
        if(Spfa(n))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
HierarchicalDiagramShortestPath::LGP3385_SPFA::LGP3385_SPFA(){
    head.resize(MAXN);
    distances.resize(MAXN);
    updateCnt.resize(MAXN);
    enters.resize(MAXN);
    nexts.resize(MAXM);
    tos.resize(MAXM);
    weight.resize(MAXM);
    que.resize(MAXQ);
}
void HierarchicalDiagramShortestPath::LGP3385_SPFA::Test_SPFA(){
    SPFA();
}

int main(){
    auto start=chrono::system_clock::now();
    vector<vector<int>>nums={{1,0,3},{0,0,4},{0,1,1},{1,1,2},{1,2,4},{2,3,2},{2,4,6},{3,4,3}};
    //a[2]>b[2]表示数值小的优先级大,在上面
    //auto cmp=[](vector<int>a,vector<int>b)->bool{return a[2]>b[2];};
    //priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);
    //for(auto num:nums)pq.push(num);
    //while(!pq.empty()){
    //    vector<int>top=pq.top();
    //    pq.pop();
    //    cout<<top[0]<<" "<<top[1]<<" "<<top[2]<<endl;
    //};
    //int arr[]={2,1,3,8,9,5,7,4,0};
    //sort(arr+1,arr+sizeof(arr)/sizeof(int));

    //cin.get();
    
    int In;cin>>In;
    switch(In){
        case 1:{
            using CreatGraph::Graph;
            Graph gp;
            gp.Test_Graph();
        }
        break;
        case 2:{
            using CreatGraph::Topological;
            Topological tp;
            tp.Test_LC210_findOrder();
        }
        break;
        case 3:{
            using CreatGraph::LG_Topological;
            LG_Topological lgc;
            lgc.Test_LG_U107394();
        }
        break;
        case 4:{
            using  CreatGraph::alienOrder;
            alienOrder al;
            al.Test_LCR114_alienOrder();
        }
        break;
        case 5: {
            using CreatGraph::alienOrder;
            alienOrder als;
            als.Test_LC936_movesToStamp();
        }
        break;
        case 6:{
            using FoodLine::FoodLine;
            FoodLine();
        }
        break; 
        case 7:{
            using FoodLine::loudAndRich;
            loudAndRich lou;
            lou.Test_LC851_loudAndRich();
        }
        break;
        case 8:{
            using FoodLine::mumTime;
            mumTime mi;
            mi.Test_LC2050_minimumTime();
        }
        break;
        case 9:{
            using FoodLine::Invitations;
            Invitations in;in.Test_LC2127_maximumInvitations();
        }
        break;
        case 10:{
            using FoodLine::Kruskal;
            Kruskal kr;
            kr.Test_Kruskal_MST();
        }
        break;
        case 11:{
            using FoodLine::Prim;
            Prim pr;
            pr.Test_Prim_MST();
        }
        case 12:{
            using FoodLine::PrimPlus;
            PrimPlus pp;
            pp.Test_PrimPlus_MST();
        }
        break;
        case 13:{
            using FoodLine::OptimizationOfWaterAllocation;
            OptimizationOfWaterAllocation op;
            op.Test_LC1168_OptimizationOfWaterAllocation();
        }
        break;
        case 14:{
            using FoodLine::distanceLimitedPathsExist;
            distanceLimitedPathsExist dis;
            dis.Test_LC1697_distanceLimitedPathsExist();
        }
        break;
        case 15:{
            using WidthFirstTraversal::MaxDistance;
            MaxDistance Mce;
            Mce.Test_LC1162_maxDistance();
        }
        break;
        case 16:{
            using WidthFirstTraversal::MinStickers;
            MinStickers min;
            min.Test_LC691_minStickers();
        }
        break; 
        case 17:{
            using WidthFirstTraversal::MinimumObstacles;
            MinimumObstacles cl;
            cl.Test_LC2290_minimumObstacles();
        }
        break;
        case 18:{
            using WidthFirstTraversal::MinCost;
            MinCost mc;
            mc.Test_LC1368_minCost();
        }
        break;
        case 19:{
            using WidthFirstTraversal::trapRainWater;
            trapRainWater tr;
            tr.Test_LC407_trapRainWater();
        }
        case 20:{
            using WidthFirstTraversal::FindLadders;
            FindLadders fes;
            fes.Test_LC126_findLadders();
        }
        break;
        case 21:{
            using WidthFirstTraversal::LadderLength;
            LadderLength lth;
            lth.Test_LC127_ladderLength();
        }
        break;
        case 22:{
            using WidthFirstTraversal::SnacksWayBuyTickets;
            SnacksWayBuyTickets Set;
            Set.Test_LGP4799_SnacksWayBuyTickets();
        }
        break;
        case 23:{
            using WidthFirstTraversal::MinAbsDifference;
            MinAbsDifference Mce;
            Mce.Test_LC1755_minAbsDifference();
        }
        break;
        case 24:{
            using HierarchicalDiagramShortestPath::DijkstraAlorgithm;
            DijkstraAlorgithm dim;
            dim.Test_LC743_networkDelayTime();
        }
        break;
        case 25:{
            using HierarchicalDiagramShortestPath::InvertedIndexingDijkstra;
            InvertedIndexingDijkstra Ira;
            Ira.Test_LC743_networkDelayTime();
        }
        break;
        case 26:{
            using HierarchicalDiagramShortestPath::MinimumEffortPath;
            MinimumEffortPath mith;
            mith.Test_LC1631_minimumEffortPath();
        }
        break;
        case 27:{
            using HierarchicalDiagramShortestPath::SwimInWater;
            SwimInWater Ster;
            Ster.Test_LC778_swimInWater();
        }
        break;
        case 28:{
            using HierarchicalDiagramShortestPath::ShortestPathAllKeys;
            ShortestPathAllKeys Sky;
            Sky.Test_LC864_shortestPathAllKeys();
        }
        break;
        case 29:{
            using HierarchicalDiagramShortestPath::ElectricCarPlan;
            ElectricCarPlan Epa;
            Epa.Test_LCP35_electricCarPlan();
        }
        break;
        case 30:{
            using HierarchicalDiagramShortestPath::AStarAlgorithm;
            AStarAlgorithm Atm;
            Atm.Test_MinDistance();
        }
        break;
        case 31:{
            using HierarchicalDiagramShortestPath::Floyd;
            Floyd fld;
            fld.Test_floyds();
        }
        break;
        case 32:{
            using HierarchicalDiagramShortestPath::Bellman_Ford;
            Bellman_Ford bf;
            bf.LC787_findCheapestPrice();
        }
        break;
        case 33:{
            using HierarchicalDiagramShortestPath::LGP3385_SPFA;
            LGP3385_SPFA sp;
            sp.Test_SPFA();
        }
        break; 
        default:break;
    }

    auto end=chrono::system_clock::now();
    cout<<"运行时长为："<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" ms "<<endl;
    cin.get();
    cin.get();
    return 0;
}