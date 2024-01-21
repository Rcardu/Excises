#include"Graph.h"
using namespace std;

/// @brief ͼ case 1
CreatGraph::Graph::Graph():cnt(0){
    Graph1.resize(MAXN,vector<int>(MAXN,0));
    head.resize(MAXN,0);
    next.resize(MAXM,0);
    tos.resize(MAXM,0);
    weith.resize(MAXM,0);
}
void CreatGraph::Graph::Build(int n){
    //�ڽӾ�������
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            Graph1[i][j]=0;
        }
    }
    //�ڽӱ�����
    Graph2.clear();
    //�±���Ҫ֧��1~n�����Լ���n+1���б�
    for(int i=0;i<=n;i++){
        Graph2.push_back({});
    }
    //�����ʽǰ����
    cnt=1;
    for(int&h:head)h=0;
}
void CreatGraph::Graph::DirectGraph(vector<vector<int>>&edges){
    for(vector<int> edge:edges){
        //�������Ȩ����Ȩֵ=1�����б߼���
        Graph1[edge[0]][edge[1]]=edge[2];
    }
    for(vector<int>edge:edges){
        //�������Ȩ������һ����Ȩ�ڽӱ�ֱ�Ӳ���߼���
        Graph2[edge[0]].push_back({edge[1],edge[2]});
    }
    for(vector<int>edge:edges){
        addEdge(edge[0],edge[1],edge[2]);
    }
}
void CreatGraph::Graph::UndirectGraph(vector<vector<int>>&edges){
    for(vector<int>edge:edges){
        //��Ȩ��Ϊ1
        Graph1[edge[0]][edge[1]]=edge[2];
        Graph1[edge[1]][edge[0]]=edge[2];
    }
    for(vector<int>edge:edges){
        //��Ȩ����һ����Ȩ�ڽӱ�
        Graph2[edge[0]].push_back({edge[1],edge[2]});
        Graph2[edge[1]].push_back({edge[0],edge[2]});
    }
    for(vector<int>edge:edges){
        addEdge(edge[0],edge[1],edge[2]);
        addEdge(edge[1],edge[0],edge[2]);
    }
}
void CreatGraph::Graph::addEdge(int u,int v,int w){
    //�µı�Ҫȥ����һ���ߵ�λ�þ��ǵ�ǰ���ͷ������ʾ�ı�
    next[cnt]=head[u];
    //������ͨ���ĵ�Ϊv
    tos[cnt]=v;
    //�����ߵ�Ȩ��Ϊw
    weith[cnt]=w;
    //�����߳�Ϊ��ǰ���ͷ��
    head[u]=cnt++;
}
void CreatGraph::Graph::Traversal(int n){
    cout<<"�ڽӾ������:"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<Graph1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"�ڽӱ�ı���: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<"(�ھӡ���Ȩ):";
        for(auto edge:Graph2[i]){
            cout<<"("<<edge[0]<<","<<edge[1]<<")";
        }
        cout<<endl;
    }
    cout<<"��ʽǰ���ǵı���: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<"(�ھӡ���Ȩ): ";
        //���forѭ��������ʽǰ���ǵı�����ʽ
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

/// @brief LeetCode 210 �γ̱� case 2
/// @param numCourses 
/// @param prerequisites 
/// @return 
vector<int>CreatGraph::Topological::LC210_findOrder(int numCourses, vector<vector<int>>& prerequisites){
    //����ͼ��ÿ��������ȱ�
    vector<vector<int>>Graph;
    //���ݽڵ�������ӱ�
    for(int i=0;i<numCourses;i++)Graph.push_back({});
    //��ȱ�
    vector<int>indegree(numCourses,0);
    //��ӽ�㼰�ھӣ��������
    for(vector<int>edge:prerequisites){
        //edge[1]->edge[0];
        Graph[edge[1]].push_back(edge[0]);
        //edge[0]���+1
        indegree[edge[0]]++;
    }
    //ʹ�ö�����������������
    vector<int>que(numCourses,0);
    int r=0,l=0;
    //���ҳ��������Ϊ0�ĵ�
    for(int i=0;i<numCourses;i++)if(indegree[i]==0)que[r++]=i;
    //��¼���е������ĵ�
    int cnt=0;
    while(l<r){
        int cur=que[l++];
        //ÿ����һ����¼��+1
        cnt++;
        //�����ǰ������ʧ����һ���������Ϊ0������������
        for(int next:Graph[cur])if(--indegree[next]==0)que[r++]=next;
    }
    if(cnt!=numCourses)return {};
    return que;
}
void CreatGraph::Topological::Test_LC210_findOrder(){
    vector<vector<int>>edges;
    Print(LC210_findOrder(2,edges));  
}

/// @brief ��� U107394 ��������ģ�� case 3
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
    //����¼��������������ĸ��ڵ㻹С����ô�ͽ�����������λ��
    while(heap[i]<heap[(i-1)/2]){
        Swap(i,(i-1)/2);
        //���¸��ڵ�
        i=(i-1)/2;
    }
}
int CreatGraph::LG_Topological::Pop(){
    int ans=heap[0];
    //�����һ��Ҷ�ӽ��ŵ��Ѷ�
    heap[0]=heap[--heap_size];
    int i=0,l=1;
    // ���������������ԱȽ�
    while(l<heap_size){
        //���l+1(��Ҷ�ӽ��)û��Խ�磬ȡ����Ҷ������Ҷ������С���Ǹ�(����)
        int best=l+1<heap_size&&heap[l+1]<heap[l]?l+1:l;
        //���븸�����бȽ�
        best=heap[best]<heap[i]?best:i;
        //�����С�ľ��Ǹ��ڵ㣬ֱ���˳�(�Ѿ��Ǻϸ��С����)
        if(best==i)break;
        //����ͽ������������
        Swap(best,i);
        //��ѭ���ж������ӽ��
        i=best;
        l=i*2+1;
    }
    //���ضѶ�Ԫ��
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
    //�������н�㣬�ҳ����Ϊ0�Ľ�����
    for(int i=1;i<=n;i++)if(indegree[i]==0)Push(i);
    //��¼���ѵĽ�����
    int fill=0;
    while(!isEmpty()){
        int cur=Pop();
        ans[fill++]=cur;
        //������ʽǰ����ͼ
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

/// @brief LCR 114 ���Ǵʵ� case 4
/// @param words 
/// @return 
string CreatGraph::alienOrder::LCR114_alienOrder(vector<string>& words){
    //������ȱ���ʼΪ-1����ǰ��ȱ���ַ���û�г���
    vector<int>indegree(26,-1);
    for(string w:words){
        //���������ַ������飬�����ǰ�ַ��������ַ��������оͽ����������Ϊ0
        for(int i=0;i<w.size();i++)indegree[w[i]-'a']=0;
    }
    //��ͼ
    vector<vector<int>>Graph;
    for(int i=0;i<26;i++)Graph.push_back({});
    //��ǰ�������ַ������бȽϣ�ȡ����ͼ
    for(int i=0,j,len;i<words.size()-1;i++){
        string cur=words[i];
        string next=words[i+1];
        j=0;
        len=min(cur.size(),next.size());
        for(;j<len;j++){
            //��ǰ�ַ���һ��ʱ�Ϳ��Լ���ͼ����
            if(cur[j]!=next[j]){
                Graph[cur[j]-'a'].push_back(next[j]-'a');
                indegree[next[j]-'a']++;
                break;
            }
        }
        //�������ǰһ��������"abc"��һ��Ϊ"abcd"˵���ֵ�������
        if(j<cur.size()&&j==next.size())return "";
    }
    //ʹ�ö��н�����������
    vector<int>que(26,0);
    int l=0,r=0;
    //��¼���ֵ��ַ�����
    int kinds=0;
    for(int i=0;i<26;i++){
        if(indegree[i]!=-1)kinds++;
        if(indegree[i]==0)que[r++]=i;
    }
    //������������
    string ans;
    while(l<r){
        //�����׸����Ϊ0�Ľ��
        int cur=que[l++];
        //��������
        ans+=(char)(cur+'a');
        //������ǰ�����ڽӣ���������ھӵ�Ӱ��
        for(int next:Graph[cur]){
            //�������֮���ھӵ����Ϊ0���ͼ������
            if(--indegree[next]==0)que[r++]=next;
        }
    }
    //������������ֵ��ַ�����ȣ�˵�����������򣬷��򷵻� ""�����л����޷�������������
    return ans.size()==kinds?ans:"";
}
void CreatGraph::alienOrder::Test_LCR114_alienOrder(){
    vector<string>str;
    cout<<LCR114_alienOrder(str)<<endl;
}

/// @brief LeetCode 936 ��ӡ���� case 5
/// @param stamp 
/// @param target 
/// @return 
vector<int>CreatGraph::alienOrder::LC936_movesToStamp(string stamp, string target){
    //��ȡӡ�³�����Ŀ�곤��
    int n=target.size(),m=stamp.size();
    //������ȱ���ʼ��ȶ�Ϊm������ÿ��λ�ö�ӡ����
    vector<int>indegree(n-m+1,m);
    //��ͼ
    vector<vector<int>>Graph;
    for(int i=0;i<n;i++)Graph.push_back({});
    //ʹ�ö��н�����������
    vector<int>que(n-m+1,0);
    int r=0,l=0;
    //����ÿ�����Ե���ͷ�ĵ����Ƚ��е���
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<m;j++){
            //�ж���i��ͷ��ÿ��λ��j���ַ��Ƿ���ӡ�¶Ե���
            if(target[i+j]==stamp[j]){
                //��i��ͷ��λ��������ԵĻ��ͽ���
                if(--indegree[i]==0)que[r++]=i;
            //���򣬱�ǵ�i+jλ��Ϊ��i��ͷ��ӡ���޷����ƥ��
            }else Graph[i+j].push_back(i);
        }
    }
    //��ǰλ��������Ա�ǰ���ӡ�¸��ǣ�������������λ�õ�Ӱ����
    vector<bool>visited(n,false);
    //�����
    vector<int>path(n-m+1,0);
    //�������С
    int size=0;
    while(l<r){
        int cur=que[l++];
        path[size++]=cur;
        //�ж�ÿ��λ���Ƿ���Ա��ͷ�,������ǰӡ�µ�Ӱ��
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

/// @brief LeetCode 851 ���ֺ͸��� case 7
/// @param richer 
/// @param quiet 
/// @return 
vector<int>FoodLine::loudAndRich::LC851_loudAndRich(vector<vector<int>>& richer, vector<int>& quiet){
    int n=quiet.size();
    //�����
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

/// @brief LeetCode 2050 ���пγ�III case 8
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

/// @brief LeetCode 2127 �μӻ�������Ա�� case 9
/// @param favorite 
/// @return 
int FoodLine::Invitations::LC2127_maximumInvitations(vector<int>& favorite){
/*���������ҪʹԱ��������һȦ�������ٻ���һ������
    ���ڻ���1�������һ��������ɵĻ�����ô�������˿���ֱ������ͬʱϲ�����˵�������������
        ����С����������ɵĻ������������˸��������ȥ����󳤶ȣ��ټ���������С�������������µ�����
        2�������һ���������˵Ĵ󻷣���ô��������ֻ������������е���*/
        int n=favorite.size();
        //���
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)indegree[favorite[i]]++;
        //����
        vector<int>que(n,0);
        int l=0,r=0;
        for(int i=0;i<n;i++)if(indegree[i]==0)que[r++]=i;
        //��ȱ�
        vector<int>deep(n,0);
        while(l<r){
            //����ÿ��������ȣ�ΪС���Ľ����׼��
            int cur=que[l++];
            int next=favorite[cur];
            deep[next]=max(deep[next],deep[cur]+1);
            //�������зǻ����ɾ������ѭ��֮�����Ϊ0�Ľ�����û���ڻ��ϵĽ��
            if(--indegree[next]==0)que[r++]=next;
        }
        //���м���
        //С��ringsize=2��
        int ans1=0;
        //��ringsize>=3;
        int ans2=0;
        for(int i=0;i<n;i++){
            if(indegree[i]>0){
                int ringsize=1;
                indegree[i]=0;
                //������������ֱ������iΪֹ������;������޸�Ϊ0����ʾ�Ѿ�������
                for(int j=favorite[i];j!=i;j=favorite[j]){
                    indegree[j]=0;
                }
                //������ɺ������С��
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

/// @brief Kruskal�㷨 case 10
void FoodLine::Kruskal::Build(){
    father.resize(MAXN,0);
    edges.resize(MAXN,vector<int>(3));
    //��ʼ��
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
    //ע������������MAXM��λ�ã���ʵ��ֻ��m��λ�ã��������Ǵ�0-m-1����begin(),begin()+m
    sort(edges.begin(),edges.begin()+m,[](vector<int>a,vector<int>b)->bool{
        return a[2]<b[2];});
    int ans=0;
    //��¼���ռ����ıߵ�����
    int edgeCnt=0;
    for(vector<int>edge:edges){
        if(Union(edge[0],edge[1])){
            ans+=edge[2];
            edgeCnt++;
            //����Ѿ��ռ����˾��˳�
            if(edgeCnt==n-1)break;
        }
    }
    if(edgeCnt<n-1)cout<<"orz"<<endl;
    else cout<<ans<<endl;
}
void FoodLine::Kruskal::Test_Kruskal_MST(){
    Kruskal_MST();
}

/// @brief Prim�㷨 case 11
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
    //����С����
    auto cmp=[](vector<int>a,vector<int>b)->bool{return a[2]<b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    //����һ��������ı����
    for(vector<int>edge:Graph[1])pq.push(edge);
    //���ñ��λ����ʾ��ǰ���������
    vector<bool>set(n+1,false);
    //�ռ��𰸵ļ������������ռ����ıߵ���������n-1����˵��û����С������
    int nodeCnt=1;
    //��һ������Ѿ������ʹ�
    set[1]=true;
    //��С��������Ȩֵ�ܺ�
    int ans=0;
    //��Ϊ�վͼ���
    while(!pq.empty()){
        vector<int>edge=pq.top();
        pq.pop();
        //�ó�����Ȩֵ
        int next=edge[0];
        int cost=edge[1];
        //�жϵ�ǰ����Ƿ񱻷��ʹ�
        if(!set[next]){
            //�߼���++
            nodeCnt++;
            //������Ϊtrue
            set[next]=true;
            //������Ȩֵ
            ans+=cost;
            //����ǰ���ı�Ҳ���
            for(vector<int>e:Graph[next])pq.push(e);
        }
    }
    if(nodeCnt<n)cout<<"orzz"<<endl;
    else cout<<ans<<endl;
}
void FoodLine::Prim::Test_Prim_MST(){
    Prim_MST();
}

/// @brief Prim�㷨���Ż� case 12
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
    //�Ѷ��Ľڵ��Ȩ��
    usv=heap[0][0];
    usw=heap[0][1];
    //�����ѵ����һ���ڵ㵽�Ѷ�
    Swap(0,--heap_size);
    //����������׼��������
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
    //��ȡ����һ�����������ھӲ���ѣ����ռ��˵�һ�����
    long long ans=0;
    for(int ei=head[1];ei>0;ei=next[ei]){
        addOrUpdateOrIgnore(ei);
    }
    EdgeCnt=1;
    Where[1]=-2;
    while(!Empty()){
        //��ʼ����ÿ�����
        //ȡ���Ѷ�Ԫ��
        Pop();
        ans+=(long long)usw;
        for(int ei=head[usv];ei>0;ei=next[ei]){
            addOrUpdateOrIgnore(ei);
        }
    }
    cout<<ans<<endl;
    auto e=chrono::system_clock::now();
    cout<<"����ʱ��Ϊ��"<<chrono::duration_cast<chrono::milliseconds>(e-s).count()<<" ms "<<endl;
}
void FoodLine::PrimPlus::Test_PrimPlus_MST(){
    PrimPlus_MST();
}

/// @brief LeetCode 1168  ˮ��Դ�����Ż� case 13
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


/// @brief LeetCode 1697 ���߳������Ƶ�·���Ƿ���� case 14
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

/// @brief LeetCode 1162 ��ͼ���� case 15
/// @param grid 
/// @return 
int WidthFirstTraversal::MaxDistance::LC1162_maxDistance(vector<vector<int>>& grid){
    vector<int>move={-1,0,1,0,-1};
    l=0,r=0;
    int n=grid.size();
    int m=grid[0].size();
    //���������
    int seas=0;
    //��һ�α�����������½�ؽ���
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                //����Ϊtrue��ʾ�Ѿ����ʹ�
                visited[i][j]=true;
                que[r][0]=i;
                que[r++][0]=j;
            }else{
                //��������Ϊfalse���������
                visited[i][j]=false;
                //��������++
                seas++;
            }
        }
    }
    //���ֻ��½�ػ���ֻ�к��󷵻�-1
    if(seas==0||seas==n*m)return -1;
    //�ӵ�0�㿪ʼ
    int level=0;
    while(l<r){
        level++;
        //ÿ�ν�ÿһ�������Ԫ�ض������������ڽ�Ԫ�����
        int size=r-l;
        for(int k=0,x,y,nx,ny;k<size;k++){
            x=que[l][0];
            y=que[l++][1];
            //ʹ��move������ʵ���������ҵ��ٽ�Ԫ�����
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
    //�������һ��-1��Ϊans
    return level-1;
}
void WidthFirstTraversal::MaxDistance::Test_LC1162_maxDistance(){
    vector<vector<int>>grid={{1,0,1},{0,0,0},{1,0,1}};
    cout<<LC1162_maxDistance(grid)<<endl;
}

/// @brief LeetCode 691 ��ֽƴ�� case 16
/// @param stickers 
/// @param target 
/// @return 
int WidthFirstTraversal::MinStickers::LC691_minStickers(vector<string>& stickers, string target){
    for(int i=0;i<26;i++)Graph[i].clear();
    visited.clear();
    for(string str:stickers){
        //�ȶԵ�ǰ���������ַ�������
        sort(str.begin(),str.end());
        //�ٱ�����ǰ�ַ�����ÿ���ַ���������뵽ͼ��
        for(int i=0;i<str.size();i++){
            //��һ���ַ��϶�����ͼ�У�������ַ������ǰ����ַ��ظ����Ͳ����ظ�������
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
        //�����������н�����ӻ���Ӳ���
        for(int i=0;i<size;i++){
            string cur=que[l++];
            //����ͼ��Ѱ�ҿ���ƥ�䵱ǰ�ַ������ַ���
            for(string s:Graph[cur[0]-'a']){
                //�����һ���ַ������Ժ͵�ǰ���ַ�����ȫƥ����next==""
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

/// @brief LeetCode 2290 ���������Ҫ�Ƴ����ϰ������С��Ŀ case 17
/// @param grid 
/// @return 
int WidthFirstTraversal::MinimumObstacles::LC2290_minimumObstacles(vector<vector<int>>& grid){
    vector<int>move={-1,0,1,0,-1};
    int n=grid.size();
    int m=grid[0].size();
    //������¼��ǰ������С��Ȩֵ
    vector<vector<int>>distances(n,vector<int>(m,INT_MAX));
    //��������01BFS
    deque<vector<int>>dq;
    //��ʼʱ����Ƚ������
    dq.push_back({0,0});
    //������СȨֵΪ0
    distances[0][0]=0;
    while(!dq.empty()){
        //ȡ��ͷ���Ľ��
        vector<int>record=dq.front();
        dq.pop_front();
        int x=record[0];
        int y=record[1];
        //�������⣬����Ѿ��ߵ������һ������򷵻ش���㵽���һ��������СȨֵ
        if(x==n-1&&y==m-1)return distances[x][y];
        //ͨ��move����ʵ��(x-1,y)(x,y+1)(x+1,y)(x,y-1);
        for(int i=0;i<4;i++){
            int nx=x+move[i];
            int ny=y+move[i+1];
            //���Խ����ߵ�ǰ����СȨֵ�Ѿ��޷����µ�Ȩֵ����Ϊ��С���ˣ�������
            if(nx<0||nx>=n||ny<0||ny>=m||distances[x][y]+grid[nx][ny]>=distances[nx][ny])continue;
            distances[nx][ny]=distances[x][y]+grid[nx][ny];
            //�����ǰ·��Ϊ0���򽫴�ͷ������
            if(grid[nx][ny]==0)dq.push_front({nx,ny});
            //�����β������
            else dq.push_back({nx,ny});
        }
    }
    return -1;
}
void WidthFirstTraversal::MinimumObstacles::Test_LC2290_minimumObstacles(){
    vector<vector<int>>grid={{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    cout<<LC2290_minimumObstacles(grid)<<endl;
}

/// @brief LeetCode 1368 ʹ����������һ����Ч·������С���� case 18
/// @param grid 
/// @return 
int WidthFirstTraversal::MinCost::LC1368_minCost(vector<vector<int>>& grid){
    //move�����������������
    vector<vector<int>>move={{},{0,1},{0,-1},{1,0},{-1,0}};
    //·��Ȩֵ��Сֵ����
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>distances(n,vector<int>(m,INT_MAX));
    //����
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
            //�����ǰҪ�ߵķ����뵱ǰ���ķ���һ�£���ôȨ�ؾ�Ϊ0������Ϊ1
            int weight=grid[x][y]==i?0:1;
            if(nx<0||nx>=n||ny<0||ny>=m&&weight+distances[x][y]>=distances[nx][ny])continue;
            distances[nx][ny]=distances[x][y]+weight;
            //�����ǰҪ�ߵķ����뵱ǰ���ķ���һ�£���ô�ʹ�ͷ�����
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

/// @brief LeetCode 407 ����ˮII case 19
/// @param heightMap 
/// @return 
int WidthFirstTraversal::trapRainWater::LC407_trapRainWater(vector<vector<int>>& heightMap){
    //move������ʵ�����������ƶ�
    vector<int>move={-1,0,1,0,-1};
    //�������ȶ��и���ˮ�߸߶ȵ׵�����
    int n=heightMap.size();
    int m=heightMap[0].size();
    auto cmp=[](vector<int>a,vector<int>b)->bool{return a[2]>b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>dq(cmp);
    //������������
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    //�ȱ���һ�齫���б߽����
    for(int i=0;i<n;i++){
        for(int j=0;i<m;j++){
            if(i==0||i==n-1||j==0||j==m-1){
                visited[i][j]=true;
                //�߽��ˮ�߸߶Ⱦ����Լ��ĸ߶�
                dq.push({i,j,heightMap[i][j]});
            }
        }
    }
    //���
    int ans=0;
    //�ٱ��������е�Ԫ�أ���Ԫ�ص��ĸ����������
    while(!dq.empty()){
        vector<int>record=dq.top();
        dq.pop();
        int r=record[0];
        int c=record[1];
        int w=record[2];
        //�������ռ�����ˮȡ�����Լ���ˮ�߸߶�-�Լ��ĸ߶�
        ans+=w-heightMap[r][c];
        for(int i=0,nr,nc;i<4;i++){
            nr=r+move[i];
            nc=c+move[i+1];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&!visited[nr][nc]){
                visited[nr][nc]=true;
                //ˮ�߸߶�ȡ��������߶�����һ���߶ȵ����ֵ
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

/// @brief LeetCode 126 ���ʽ���II case 20
/// @param beginWord 
/// @param endWord 
/// @param wordList 
/// @return 
vector<vector<string>>WidthFirstTraversal::FindLadders::LC126_findLadders(string beginWord, string endWord, vector<string>& wordList){
    Build(wordList);
    if(!dict.count(endWord))return ans;
    //begin->endȥѰ��·��������ͼ
    if(LC126_findLadders_BFS(beginWord,endWord)){
        //�ҵ��ˣ��ʹ�end->beginȥ�������ռ�·��
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
    //�൱�ڶ��У����Ҵ�ȥ�أ���curLevel��ȥ������ǰ�ĵ�����ֻ�޸�һ����ĸ�������,�ܱ�ɵ��ʱ����˭
    curLevel.insert(beginword);
    while(!curLevel.empty()){
        //����ϣ��curLevel��ӵ��ʱ�dict���ռ����ĵ��ʲ������ظ��ռ������Խ�curLevel���ռ����ĵ�����dict���ʱ���Ҳ��Ӧ��ɾ��
        for(string cur:curLevel){
            if(dict.count(cur))dict.erase(cur);
        }
        for(string word:curLevel){
            //word:ȥ��
            //ÿ��λ�ã��ַ���a-z��һ�飬����ڴʱ����Ƿ���ڣ����ұ�����Լ��ظ�
            for(int i=0;i<word.size();i++){
                //��a-z���γ���
                for(char ch='a';ch<='z';ch++){
                    string str=word;
                    str[i]=ch;
                    //��֤�ڴʱ�����������ʣ����Ҳ���ԭ���ĵ����ظ�
                    if(dict.count(str)&&str!=word){
                        //������ʾ���endword��ô�ͽ�find���Ϊ�ҵ���
                        if(str==endword)find=true;
                        Graph[str].push_back(word);
                        //��ǰ�����ɵ�strֻ��һ��
                        if(!nextLevel.count(str))nextLevel.insert(str);
                    }
                }
            }
        }
        if(find)return true;
        else {
            //����curLevel��ΪnextLevel�������ռ�
            unordered_set<string>tmp=curLevel;
            curLevel=nextLevel;
            nextLevel=tmp;
            nextLevel.clear();
        }
    }
    return false;
}
void WidthFirstTraversal::FindLadders::LC126_findLadders_DFS(string endword,string beginwrod){
    //���˵��ʽ���·��
    path.push_back(endword);
    //�ҵ���һ��·���ͽ�������
    if(endword==beginwrod){
        ans.push_back(path);
        //�����ռ���·��������ans֮��·������������
        reverse(ans.back().begin(),ans.back().end());
    }
    //����ͱ���ͼ�е�ÿ������
    else if(Graph.count(endword)){
        for(string next:Graph[endword]){
            LC126_findLadders_DFS(next,beginwrod);
        }
    }
    //����
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

/// @brief LeetCode 127 ���ʽ��� case 21
/// @param beginWord 
/// @param endWord 
/// @param wordList 
/// @return 
int WidthFirstTraversal::LadderLength::LC127_ladderLength(string beginWord, string endWord, vector<string>& wordList){
    //�Ƚ��ַ�������ת��Ϊ��ϣSet�����ѯ
    unordered_set<string>dict;
    for(const string&word:wordList)dict.insert(word);

    //�����жϣ�������ʱ���û��endWord�������ֱ�ӷ���0
    if(!dict.count(endWord))return 0;

    //������С��һ��
    unordered_set<string>SmallSet;
    //�����ϴ��һ��
    unordered_set<string>BigSet;
    //��������С��һ����չ��������һ���б�
    unordered_set<string>nextLevel;
    SmallSet.insert(beginWord);
    BigSet.insert(endWord);

    /*˫����������ʼ�ĳ���Ϊ2����SmallSetΪ��ʱ��ʾ��beginWord����endWord��˫����չ�£�û���ҵ��м������㣬
    ���ڵ��ʱ��в�����beginWord��endWord�ı仯*/
    for(int len=2;!SmallSet.empty();len++){
        //����SmallSet�е�ÿ�����ʣ���һ�仯������չ
        for(string word:SmallSet){
            //��word��ÿ��λ�ö���һ�α任
            for(int j=0;j<word.size();j++){
                //��word����str���б仯
                string str=word;
                //��a-z����һ��
                for(char ch='a';ch<='z';ch++){
                    str[j]=ch;
                    //�仯Ϊword��ֱ������
                    if(str!=word){
                        //������仯��ĵ�����BigSet���ҵ��ǣ�������������������չ��·�������ˣ�ֱ�ӷ���len��Ϊ��
                        if(BigSet.count(str))return len;
                        //�����ѯ��������Ƿ�����ڵ��ʱ�����û��ֱ��������������� 
                        if(dict.count(str)){
                            //����ӵ��ʱ���ɾ������ֹ�ظ�����str
                            dict.erase(str);
                            //������뵽nextLevel����Ϊ��չ�����Ľ��
                            nextLevel.insert(str);
                        }
                    }
                }
            }
        }
        //������������и��£�nextLevel��BigSet˭С˭��Ϊ��һ�ֵ�SmallSet
        if(nextLevel.size()<=BigSet.size()){
            unordered_set<string>tmp=SmallSet;
            SmallSet=nextLevel;
            //nextLevel����һ�ֵ�SmallSetʱ��BigSet�ͱ���ԭ�������Ӽ���
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

/// @brief LGP4799 ������������ cace 22
void WidthFirstTraversal::SnacksWayBuyTickets::LGP4799_SnacksWayBuyTickets(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<LGP4799_Compute()<<endl;
}
long long WidthFirstTraversal::SnacksWayBuyTickets::LGP4799_Compute(){
    /*��Χ����ҿ�*/
    int lsize=LGP4799_f(0,n>>1,0,m,lnum,0);
    int rsize=LGP4799_f(n>>1,n,0,m,rnum,0);
    /*����*/
    sort(lnum.begin(),lnum.begin()+lsize);
    sort(rnum.begin(),rnum.begin()+rsize);
    long long ans=0;
    /*˫ָ��*/
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
    //���û�г���w�������Ѿ�������ֹλ�ã���ans�����뼴��
    if(i==e)ans[j++]=s;
    else{
        //��Ҫarr[i]λ�õ���
        j=LGP4799_f(i+1,e,s,w,ans,j);
        //Ҫarr[i]λ�õ���
        j=LGP4799_f(i+1,e,s+arr[i],w,ans,j);
    }
    return j;
}
void WidthFirstTraversal::SnacksWayBuyTickets::Test_LGP4799_SnacksWayBuyTickets(){
    LGP4799_SnacksWayBuyTickets();
}

/// @brief LeetCode 1755 ��ӽ�Ŀ��ֵ�������к� case 23
/// @param nums 
/// @param goal 
/// @return 
int WidthFirstTraversal::MinAbsDifference::LC1755_minAbsDifference(vector<int>& nums, int goal){
    int n=nums.size();
    //��֦���Ż�����ʱ��ĸ��Ӷ�
    long long Max=0;
    long long Min=0;
    for(int i=0;i<n;i++){
        if(nums[i]>=0)Max+=nums[i];
        else Min+=nums[i];
    }
    //������������е�������Ŀ��ֵ��С����ô�𰸾���|max-goal|
    if(Max<goal)return abs(Max-goal);
    //��������е�����������Ŀ��ֵ������ô�𰸾���|min-goal|
    if(Min>goal)return abs(Min-goal);

    //ԭʼ�������򣬵ݹ�ʱ���ܼ�֦,����ʱ����Ż�
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
        //��i+1��ʼ��¼��arr[i]��ͬ�����м���
        int j=i+1;
        while(j<e&&arr[j]==arr[i])j++;
        //�����arr[i]��j-i��arr[i]��չ��
        for(int k=0;k<=j-i;k++){
            LC1755_minAbsDifference_f(arr,j,e,s+k*arr[i],ans);
        }
    }
}
void WidthFirstTraversal::MinAbsDifference::Test_LC1755_minAbsDifference(){
    vector<int>nums={7,-9,15,-2};
    cout<<LC1755_minAbsDifference(nums,-5)<<endl;
}

/// @brief LeetCode 743 �����ӳ�ʱ�� case 24
/// @param times 
/// @param n 
/// @param k 
/// @return 
int HierarchicalDiagramShortestPath::DijkstraAlorgithm::LC743_networkDelayTime(vector<vector<int>>& times, int n, int k){
    //ͼ
    vector<vector<vector<int>>>Graph;
    for(int i=0;i<=n;i++)Graph.push_back({});
    for(vector<int> edge:times)Graph[edge[0]].push_back({edge[1],edge[2]});
    //��ǰ�ڵ㵽Դ�����̾���
    vector<int>Distance(n+1,INT_MAX);
    //��ǰ�ڵ��Ƿ񱻵�����
    vector<int>Visited(n+1,false);
    //С����
    auto cmp=[](vector<int>a,vector<int>b)->bool{return a[1]>b[1];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    pq.push({k,0});
    Distance[k]=0;
    while(!pq.empty()){
        //������ͷ�ڵ�
        int u=pq.top()[0];
        pq.pop();
        //�ж��Ƿ��Ѿ���������
        if(Visited[u])continue;
        Visited[u]=true;
        //�����˽ڵ�������ڽӽڵ�
        for(vector<int>edge:Graph[u]){
            int v=edge[0];
            int w=edge[1];
            //�жϵ�ǰ�ڽӽڵ��Ƿ񱻵����������ҵ�ǰ�ڵ��Distance�Ƿ���Ա�����Ϊ��С
            if(!Visited[v]&&Distance[u]+w<Distance[v]){
                Distance[v]=Distance[u]+w;
                pq.push({v,Distance[u]+w});
            }
        }
    }
    //��������Distance�Ƿ�����Ч���룬��ȡ�����ֵ
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

/// @brief ���ڷ���������ʵ�ֵ�Dijkstra�㷨 case 25
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
    //δ������
    if(Where[v]==-1){
        //�������
        Heap[Heap_size]=v;
        //����DistanceΪ��ǰc(Distance[u]+w)
        Distance[v]=c;
        //�޸�Where[v]Ϊ��ǰ��������
        Where[v]=Heap_size++;
        //���¶�
        HeapInsert(Where[v]);
    }else if(Where[v]>=0){
        //ȡ��Сֵ��Ȼ����¶�
        Distance[v]=min(Distance[v],c);
        HeapInsert(Where[v]);
    }
}
void HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::HeapInsert(int i){
    //�Ե����϶ѻ�
    while(Distance[Heap[i]]<Distance[Heap[(i-1)/2]]){
        Swap(i,(i-1)/2);
        i=(i-1)/2;
    }
}
void HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::Swap(int i,int j){
    /*���ڶѣ�Heap                  ����Where
        [....a........b......]      [....i.......j.....]
        [....i........j......]      [....a.......b.....]
        ������
        [....b........a......]      [....j.......i.....]
        [....i........j......]      [....a.......b.....]*/

    int tmp=Heap[i];
    Heap[i]=Heap[j];
    Heap[j]=tmp;
    //����ǰHeap[i]=a   Heap[j]=b;
    //������Heap[i]=b   Heap[j]=a;
    //�ѽ���֮��Head[i]������Ľڵ����b��ʱWhere[b]������Ӧ����i
    Where[Head[i]]=i;
    //�ѽ���֮��Head[j]������Ľڵ����a��ʱWhere[a]������Ӧ����j
    Where[Heap[j]]=j;
}
int HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::Pop(){
    int ans=Heap[0];
    //����0λ�������һ��λ��
    Swap(0,--Heap_size);
    //�Զ����¶ѻ�
    HeapFiy(0);
    //����Where
    Where[ans]=-2;
    return ans;
}
void HierarchicalDiagramShortestPath::InvertedIndexingDijkstra::HeapFiy(int i){
    int l=1;
    //�ݹ��ӽڵ�ѻ�
    while(l<Heap_size){
        int best=l+1<Heap_size&&Distance[Heap[l+1]]<Distance[Heap[l]]?l+1:l;
        best=Distance[Heap[best]]<Distance[Heap[i]]?best:i;
        if(i==best)break;
        Swap(i,best);
        i=best;
        //l��i����ڵ�������Ϊi*2+1
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

/// @brief LeetCode 1631 ������С����ֵ��·�� case 26
/// @param heights 
/// @return 
int HierarchicalDiagramShortestPath::MinimumEffortPath::LC1631_minimumEffortPath(vector<vector<int>>& heights){
    int n=heights.size();
    int m=heights[0].size();
    //��;�Ľ����
    vector<vector<int>>Distance(n,vector<int>(m,INT_MAX));
    //���ȶ��У�С���ѣ�
    auto cmp=[](vector<int>&a,vector<int>&b)->bool{return a[2]>b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    //�Ƿ񵯳���
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    //0��0��0λ�õĽڵ����
    pq.push({0,0,0});
    //��ʼλ�õ�������ֵ·��Ϊ0
    Distance[0][0]=0;
    //��ʼ����
    while(!pq.empty()){
        vector<int>record=pq.top();
        pq.pop();
        int x=record[0];
        int y=record[1];
        int c=record[2];
        //����Ѿ���������ֱ������
        if(visited[x][y])continue;
        //����������һ���ڵ㣬ֱ�ӷ��ش�Ϊc
        if(x==n-1&&y==m-1)return c;
        //�޸�visited
        visited[x][y]=true;
        //��ʼ�������ұ���
        for(int i=0;i<4;i++){
            int nx=x+Move[i];
            int ny=y+Move[i+1];
            //��Խ�磬��û�б���ʹ�
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]){
                //ȡ����·��Ȩֵ������ֵ��
                int nc=max(c,abs(heights[x][y]-heights[nx][ny]));
                //������ֵ���Լ�Distance[nx][ny]���ֵ��С�����´�ֵ�������
                if(nc<Distance[nx][ny]){
                    Distance[nx][ny]=nc;
                    pq.push({nx,ny,nc});
                }
            }
        }
    }
    //���������Ҳû��·����-1
    return -1;
}
void HierarchicalDiagramShortestPath::MinimumEffortPath::Test_LC1631_minimumEffortPath(){
    vector<vector<int>>he;
    cout<<LC1631_minimumEffortPath(he)<<endl;
 }

/// @brief LeetCode 778 ��ˮλ���ߵ�Ӿ������Ӿ case 27
/// @param grid 
/// @return 
int HierarchicalDiagramShortestPath::SwimInWater::LC778_swimInWater(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    //����ÿ�����ӵ���С����
    vector<vector<int>>Distance(n,vector<int>(m,INT_MAX));
    //���ȶ���
    auto cmp=[](vector<int>&a,vector<int>&b)->bool{return a[2]>b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    //�������
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    //����Ҫ�ȵ�grid[0][0]���ܳ���
    Distance[0][0]=grid[0][0];
    //���������
    pq.push({0,0,grid[0][0]});
    //����
    while(!pq.empty()){
        auto record=pq.top();
        pq.pop();
        int x=record[0];
        int y=record[1];
        int c=record[2];
        //����Ѿ����ʹ�������
        if(visited[x][y])continue;
        //��������һ���ڵ㣬������
        if(x==n-1&&y==m-1)return c;
        //�޸�visited
        visited[x][y]=true;
        //�����ڽӵ�
        for(int i=0,nx,ny;i<4;i++){
            nx=x+Move[i];
            ny=y+Move[i+1];
            //Խ���Լ��Ƿ���ʹ�
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&!visited[nx][ny]){
                //ȡ���Ĵ���
                int nc=max(c,grid[nx][ny]);
                //���Ը���Ϊ��С�Ĵ���
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

/// @brief LeetCode 864 ��ȡ����Կ�׵����·�� case 28
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
                //Խ��������谭
                if(nx<0||nx==n||ny<0||ny==m||grid[nx][ny]=='#')continue;
                //��������û�ж�Ӧ��Կ��
                if(grid[nx][ny]>='A'&&grid[nx][ny]<='F'&&((ns&(1<<(grid[nx][ny]-'A')))==0))continue;
                //��ĳһ��Կ��,�����Կ�׼���״̬
                if(grid[nx][ny]>='a'&&grid[nx][ny]<='f')ns|=1<<(grid[nx][ny]-'a');
                //���ns�Ѿ���key��˵��Կ�׼����ˣ�ֱ���˳�
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
    //���г�ʼ������¼Կ���м���
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='@'){
                que[r][0]=i;
                que[r][1]=j;
                que[r++][2]=0;
            }
            //key��ʾΪ00011ʱ������baԿ��,Ҳ��������Կ��
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

/// @brief LCP 35 �綯���γ��� case 29
/// @param paths 
/// @param cnt 
/// @param start 
/// @param end 
/// @param charge 
/// @return 
int HierarchicalDiagramShortestPath::ElectricCarPlan::LCP35_electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge){
    int n=charge.size();
    //��ͼ
    vector<vector<vector<int>>>Graph;
    for(int i=0;i<n;i++)Graph.push_back({});
    for(vector<int>path:paths){
        Graph[path[0]].push_back({path[1],path[2]});
        Graph[path[1]].push_back({path[0],path[2]});
    }
    //���㣬���������ĵ�����ͼ�ϵĵ�
    vector<vector<int>>Distance(n,vector<int>(cnt+1,INT_MAX));
    Distance[start][0]=0;
    //���ʱ��λ
    vector<vector<bool>>visited(n,vector<bool>(cnt+1,false));
    //���ȶ���
    auto cmp=[](vector<int>&a,vector<int>&b)->bool{return a[2]>b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    //��ǰ���ڵ㡢��ǰ��������ǰ����
    pq.push({start,0,0});
    while(!pq.empty()){
        vector<int>record=pq.top();
        pq.pop();
        int cur=record[0];
        int power=record[1];
        int cost=record[2];
        //��״̬�ѱ�������
        if(visited[cur][power])continue;
        //��ǰ����Ŀ���
        if(cur==end)return cost;
        visited[cur][power]=true;
        //ѡ���һ��㣬�ı䵱ǰ���״̬
        if(power<cnt){
            //��һ���
            //״̬�ı��Ļ����Ƿ�С���Ѿ���¼�Ļ���
            if(!visited[cur][power+1]&&cost+charge[cur]<Distance[cur][power+1]){
                Distance[cur][power+1]=cost+charge[cur];
                //��״̬����
                pq.push({cur,power+1,cost+charge[cur]});
            }
        }
        //������ǰ��������ڽӽڵ�
        for(vector<int>edge:Graph[cur]){
            //�ڽӽڵ�
            int nextCity=edge[0];
            //�����ڽӽ���ʣ��ĵ���
            int restPower=power-edge[1];
            //�����ڽӽڵ�ʱ������
            int nextCost=cost+edge[1];
            //���ʣ�����λ������ȥ�������״̬�Ѿ������ӣ�����ȥ�������״̬���ɸ��²���ȥ
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
    //[0]:��    [1]:��  [2]:��Դ�������Ŀ���ľ���
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
    //[0]:��    [1]:��  [2]:��Դ�������Ŀ���ľ���
    auto cmp=[](vector<int>&a,vector<int>&b)->bool{return a[2]>b[2];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
    //[2]:��ǰ�㵽Դ��ľ���+��ǰ�㵽Ŀ���������پ���
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
    //O(N^3)�Ĺ���
    //ö��ÿ������
    //ע�⣬����Ҫ����ö��
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

/// @brief LeetCode 787 kվ��ת������˵ĺ��� case 32
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
    //a[2]>b[2]��ʾ��ֵС�����ȼ���,������
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
    cout<<"����ʱ��Ϊ��"<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" ms "<<endl;
    cin.get();
    cin.get();
    return 0;
}