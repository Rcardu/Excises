#include"AndCheckTheSet.h"
using namespace std;

/// @brief ���鼯 case 1
/// @param i 
/// @return 
int CheckSet::Cheack::Check_find(int i){
    //��;�ռ��˼�����
    int size=0;
    while(i!=father[i]){
        stack[size++]=i;
        i=father[i];
    }
    //��;�ڵ��Ѿ��ռ�����,i�Ѿ���������Ԫ����
    while(size>0)father[stack[--size]]=i;
    return i;
}
bool CheckSet::Cheack::Check_isSameSet(int x,int y){
    return Check_find(x)==Check_find(y);
}
void CheckSet::Cheack::Check_union(int x,int y){
    int fx=Check_find(x);
    int fy=Check_find(y);
    if(fx!=fy){
        //fx,fy�����������ϵĴ���Ԫ��
        if(size[fx]>=size[fy]){
            size[fx]+=size[fy];
            father[fy]=fx;
        }else{
            size[fy]+=size[fx];
            father[fx]=fy;
        }
    }
}
void CheckSet::Cheack::Test_Check(){

}

/// @brief LeetCode 765 ����ǣ�� case 2.1
/// @param row 
/// @return 
int CheckSet::ChSet::LC765_minSwapsCouples(vector<int>& row){
    int n=row.size();
    LC765_build(n/2);
    for(int i=0;i<n;i+=2){
        LC765_Union(row[i]/2,row[i+1]/2);
    }
    return n/2-sets;
}
void CheckSet::ChSet::LC765_build(int n){
    for(int i=0;i<n;i++){
        father[i]=i;
    }
    sets=n;
}
int CheckSet::ChSet::LC756_find(int i){
    if(i!=father[i])father[i]=LC756_find(father[i]);
    return father[i];
}
void CheckSet::ChSet::LC765_Union(int x,int y){
    int fx=LC756_find(x);
    int fy=LC756_find(y);
    if(fx!=fy){
        father[fx]=fy;
        sets--;
    }
}
void CheckSet::ChSet::Test_LC765_minSwapsCouples(){
    vector<int>nums;
    cout<<LC765_minSwapsCouples(nums)<<endl;
}

/// @brief LeetCode 839 ���Ƶ��ַ����� case 2.2 
/// @param strs 
/// @return 
int CheckSet::ChSet::LC839_numSimilarGroups(vector<string>& strs){
    father.resize(301,0);
    int n=strs.size();
    int m=strs[0].size();
    LC765_build(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(LC756_find(i)!=LC756_find(j)){
                int diff=0;
                for(int k=0;k<m&&diff<3;k++){
                    if(strs[i][k]!=strs[j][k])diff++;
                }
                if(diff==0||diff==2)LC765_Union(i,j);
            }
        }
    }
    return sets;
}
void CheckSet::ChSet::Test_LC839_numSimilarGroups(){
    vector<string>strs;
    cout<<LC839_numSimilarGroups(strs)<<endl;
}

/// @brief LeetCode 2092 �ҳ�����֪�����ܵ�ר�� case 3
/// @param n 
/// @param first 
void CheckSet::AllPeople::Build(int n,int first){
    for(int i=0;i<n;i++)father[i]=i;
    father[first]=0;
    secret[0]=true;
}
int CheckSet::AllPeople::find(int i){
    if(i!=father[i])father[i]=find(father[i]);
    return father[i];
}
void CheckSet::AllPeople::Union(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        father[fy]=fx;
        secret[fx]=secret[fx]|secret[fy];
    }
}
bool cmp(vector<int>&a,vector<int>&b){return a[2]<b[2];}
vector<int>CheckSet::AllPeople::LC2092_findAllPeople(int n,vector<vector<int>>&meeting,int first){
    Build(n,first);
    sort(meeting.begin(),meeting.end(),cmp);
    int m=meeting.size();
    for(int l=0,r;l<m;){
        r=l;
        while(r+1<m&&meeting[l][2]==meeting[r+1][2])r++;
        for(int i=l;i<=r;i++)Union(meeting[i][0],meeting[i][1]);

        for(int i=l,a,b;i<=r;i++){
            a=meeting[i][0];
            b=meeting[i][1];
            if(!secret[find(a)])father[a]=a;
            if(!secret[find(b)])father[b]=b;
        }
        l=r+1;
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(secret[find(i)])ans.push_back(i);
    }
    return ans;
}
void CheckSet::AllPeople::Test_LC2092_findAllPeople(){
    vector<vector<int>>meet={{1,2,5},{2,3,8},{1,5,10}};
    Print(LC2092_findAllPeople(6,meet,1));
}

/// @brief LeetCode ��·������Ŀ case 4
/// @param n 
void CheckSet::GoodPaths::Build(int n){
    for(int i=0;i<n;i++){
        //��ʼ��ÿ������Լ�Ϊһ�����ϣ����ֵΪ�Լ�������Ϊ1
        father_[i]=i;
        maxcnt_[i]=1;
    }
}
int CheckSet::GoodPaths::Find(int i){
    if(i!=father_[i])father_[i]=Find(father_[i]);
    return father_[i];
}
int CheckSet::GoodPaths::Unoin(int x,int y,vector<int>&vals){
    //���ҵ�ǰ����������ڼ��ϵĴ�����
    int fx=Find(x);
    int fy=Find(y);
    int path=0;
    //��������������ֵ����ȣ���û�к�·��
    //����С��һ�����ڽϴ�ĵ���
    if(vals[fx]>vals[fy])father_[fy]=fx;
    else if(vals[fx]<vals[fy])father_[fx]=fy;
    //���һ���󣬾ͷ���¼��·������������
    else{
        path=maxcnt_[fx]*maxcnt_[fy];
        father_[fx]=fy;
        maxcnt_[fy]+=maxcnt_[fx];
    }
    return path;
}
int CheckSet::GoodPaths::LC2421_numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges){
    int n=vals.size();
    /*��edge������������ÿ�����е������ֵ����ȡ���������и������Ľ��ֵ��������*/
    sort(edges.begin(),edges.end(),[&vals,&edges](vector<int>&a,vector<int>&b)->bool {
        return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
    });
    int ans=n;
    //����ÿ���߽��кϲ�
    for(const vector<int>&edge:edges){
        ans+=Unoin(edge[0],edge[1],vals);
    }
    return ans;
}
void CheckSet::GoodPaths::Test_LC2421_numberOfGoodPaths(){
    vector<int>vals={1,2,1,4,3};
    vector<vector<int>>edge={{0,1},{1,2},{2,3},{2,4}};
    cout<<LC2421_numberOfGoodPaths(vals,edge)<<endl;
}

/// @brief LeetCode 928 �������ٶ�������Ĵ��� case 5
CheckSet::MalwareSpread::MalwareSpread(){
    father_.resize(301,0);
    cnts_.resize(301,0);
    infect_.resize(301,-1);
    virus_.resize(301,false);
    size_.resize(301,1);
}
int CheckSet::MalwareSpread::LC928_minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial){
    int n=graph.size();
    Build(n,initial);
    //�ϲ��� ��ȾԴΪһ������
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==1&&!virus_[i]&&!virus_[j])Unoin(i,j);
        }
    }
    //��ѯ��ȾԴ�����Ľ�㣬�������Ⱦ
    for(int sick:initial){
        for(int neighbor=0;neighbor<n;neighbor++){
            if(sick!=neighbor&&!virus_[neighbor]&&graph[sick][neighbor]==1){
                int fn=Find(neighbor);
                if(infect_[fn]==-1)infect_[fn]=sick;
                else if(infect_[fn]!=-2&&infect_[fn]!=sick)infect_[fn]=-2;
            }
        }
    }
    //����ÿ�����ϵĴ�����
    for(int i=0;i<n;i++){
        if(i==Find(i)&&infect_[i]>=0)cnts_[infect_[i]]+=size_[i];
    }
    sort(initial.begin(),initial.end());
    int ans=initial[0];
    int max=cnts_[ans];
    for(int i:initial){
        if(cnts_[i]>max){
            ans=i;
            max=cnts_[i];
        }
    }
    return ans;
}
void CheckSet::MalwareSpread::Build(int n,vector<int>&initial){
    for(int i=0;i<n;i++)father_[i]=i;
    for(int i:initial)virus_[i]=true;
}
int CheckSet::MalwareSpread::Find(int i){
    if(i!=father_[i])father_[i]=Find(father_[i]);
    return father_[i];
}
void CheckSet::MalwareSpread::Unoin(int x,int y){
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy){
        father_[fx]=fy;
        size_[fy]+=size_[fx];
    }
}
void CheckSet::MalwareSpread::Test_LC928_minMalwareSpread(){
    vector<vector<int>>graph={{1,0,0,0,0,0,0},{0,1,0,0,0,1,0},{0,0,1,0,0,0,1},{0,0,0,1,0,1,0},{0,0,0,0,1,0,1},{0,1,0,1,0,1,0},{0,0,1,0,1,0,1}};
    vector<int>inital={0,1,6};
    cout<<LC928_minMalwareSpread(graph,inital)<<endl;
}

/// @brief LeetCode �������� 200 case 6
/// @param grid 
/// @return 
int CheckSet::Islands::numIslands1(vector<vector<char>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    Build(n,m,grid);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j>0&&grid[i][j]=='1'&&grid[i][j-1]=='1')Unoin(Index(i,j),Index(i,j-1));
            if(i>0&&grid[i][j]=='1'&&grid[i-1][j]=='1')Unoin(Index(i,j),Index(i-1,j));
        }
    }
    return sets;
}
void CheckSet::Islands::Build(int n,int m,vector<vector<char>>&grid){
    cols=m;
    for(int i=0;i<n;i++)
        for(int j=0,index;j<m;j++)
            if(grid[i][j]=='1'){
                index=Index(i,j);
                father[index]=index;
                sets++;
            }
}
int CheckSet::Islands::Find(int i){
    if(i!=father[i])father[i]=Find(father[i]);
    return father[i];
}
void CheckSet::Islands::Unoin(int x,int y){
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy){
        father[fy]=fx;
        sets--;
    }
}
int CheckSet::Islands::Index(int i,int j){
    return i*cols+j;
}
int CheckSet::Islands::numIslands2(vector<vector<char>>& grid){
    int n=grid.size(),m=grid[0].size();
    int land=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                land++;
                numIslands2_DFS(grid,i,j);
            }
        }
    }
    return land;
}
void CheckSet::Islands::numIslands2_DFS(vector<vector<char>>&grid,int i,int j){
    if(i<0||i==grid.size()||j<0&&j==grid[0].size()||grid[i][j]!='1')return;
    grid[i][j]='2';
    numIslands2_DFS(grid,i,j-1);
    numIslands2_DFS(grid,i,j+1);
    numIslands2_DFS(grid,i-1,j);
    numIslands2_DFS(grid,i+1,j);
}
void CheckSet::Islands::Test_LC200_numIslands(){
    vector<vector<char>>grid;
    cout<<numIslands2(grid)<<endl;
}

/// @brief LeetCode 130 ��Χ�Ƶ����� case 7
/// @param board 
void CheckSet::Solve::LC130_solve(vector<vector<char>>& board){
    int n=board.size(),m=board[0].size();
    for(int j=0;j<m;j++){
        if(board[0][j]=='O')LC130_dfs(board,n,m,0,j);
        if(board[n-1][j]=='O')LC130_dfs(board,n,m,n-1,j);
    }
    for(int i=0;i<n;i++){
        if(board[i][0]=='O')LC130_dfs(board,n,m,i,0);
        if(board[i][m-1]=='O')LC130_dfs(board,n,m,i,m-1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O')board[i][j]='X';
            if(board[i][j]=='F')board[i][j]='O';
        }
    }
}
void CheckSet::Solve::LC130_dfs(vector<vector<char>>&board,int n,int m,int i,int j){
    if(i<0||i==n||j<0||j<m||board[i][j]!='O')return;
    board[i][j]='F';
    LC130_dfs(board,n,m,i,j-1);
    LC130_dfs(board,n,m,i,j+1);
    LC130_dfs(board,n,m,i-1,j);
    LC130_dfs(board,n,m,i+1,j);
}
void CheckSet::Solve::Test_LC130_solve(){
    vector<vector<char>>grid;
    LC130_solve(grid);
}

/// @brief LeetCode 827 �����˹��� case 8
/// @param grid 
/// @return 
int CheckSet::LargeLand::LC827_largestIsland(vector<vector<int>>& grid){
    int n=grid.size(),m=grid[0].size();
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                if(j>0&&grid[i][j-1]==1)Unoin(Index(i,j),Index(i,j-1));
                if(i>0&&grid[i-1][j]==1)Unoin(Index(i,j),Index(i-1,j));
                ans=max(ans,size[Index(i,j)]);
            }
        }
    }
    unordered_map<int,bool>visited;
    int up,down,left,right,merge;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                merge=0;
                if(i>0&&grid[i-1][j]==1)up=Find(Index(i-1,j));
                else up=-1;
                if(i+1<n&&grid[i+1][j]==1)down=Find(Index(i+1,j));
                else down=-1;
                if(j>0&&grid[i][j-1]==1)left=Find(Index(i,j-1));
                else left=-1;
                if(j+1<m&&grid[i][j+1]==1)right=Find(Index(i,j+1));
                else right=-1;
                visited[up]=false;
                visited[down]=false;
                visited[left]=false;
                visited[right]=false;
                if(up!=-1)merge+=size[up];
                if(down!=-1&&!visited[down]){
                    merge+=size[down];
                    visited[down]=true;
                }
                if(left!=-1&&!visited[left]){
                    merge+=size[left];
                    visited[left]=true;
                }
                if(right!=-1&&!visited[right]){
                    merge+=size[right];
                    visited[right]=true;
                }
                ans=max(ans,merge+1);
            }
        }
    }
    return ans;
}
void CheckSet::LargeLand::Build(int n,int m,vector<vector<int>>&grid){
    cols=m;
    for(int i=0;i<n;i++){
        for(int j=0,index;j<m;j++){
            if(grid[i][j]==1){
                index=Index(i,j);
                father[index]=index;
                sets++;
                size[index]=1;
            }
        }
    }
}
int CheckSet::LargeLand::Index(int i,int j){
    return i*cols+j;
}
int CheckSet::LargeLand::Find(int i){
    if(i!=father[i])father[i]=Find(father[i]);
    return father[i];
}
void CheckSet::LargeLand::Unoin(int x,int y){
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy){
        father[fy]=fx;
        size[fx]+=size[fy];
        sets--;
    }
    
}
void CheckSet::LargeLand::Test_LC827_largestIsland(){
    vector<vector<int>>grid;
    cout<<LC827_largestIsland(grid)<<endl;
}
int CheckSet::LargeLand::LC827_largestIsland2(vector<vector<int>>& grid){
    int n=grid.size(),m=grid[0].size(),id=2;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]==1)LC827_largestIsland2_DFS(grid,n,m,i,j,id++);
    vector<int>size(id,0);
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]>1)ans=max(ans,++size[grid[i][j]]);
    vector<bool>visited(id,false);
    int up,down,left,right,merge;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]==0){
                up=i>0?grid[i-1][j]:0;
                down=i+1<n?grid[i+1][j]:0;
                left=j>0?grid[i][j-1]:0;
                right=j+1<m?grid[i][j+1]:0;
                visited[up]=true;
                merge=1+size[up];
                if(!visited[down]){
                    merge+=size[down];
                    visited[down]=true;
                }
                if(!visited[left]){
                    merge+=size[left];
                    visited[left]=true;
                }
                if(!visited[right]){
                    merge+=size[right];
                    visited[right]=true;
                }
                ans=max(ans,merge);
                visited[up]=false;
                visited[down]=false;
                visited[left]=false;
                visited[right]=false;
            }
    return ans;
}
void CheckSet::LargeLand::LC827_largestIsland2_DFS(vector<vector<int>>&grid,int n,int m,int i,int j,int id){
    if(i<0||i==n||j<0||j==m||grid[i][j]!=1)return;
    grid[i][j]=id;
    LC827_largestIsland2_DFS(grid,n,m,i-1,j,id);
    LC827_largestIsland2_DFS(grid,n,m,i+1,j,id);
    LC827_largestIsland2_DFS(grid,n,m,i,j-1,id);
    LC827_largestIsland2_DFS(grid,n,m,i,j+1,id);
}

/// @brief LeetCode 803 ��ש�� case 9
/// @param grid 
/// @param hits 
/// @return 
vector<int>CheckSet::Bricks::LC803_hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits){
//1)�ڵ����ڵ�λ��-1
//2)���컨����к�ˮ���
//3)ʱ�⵹��(�������ڵ�)����ڵ�λ��+1��Ϊ1�������˴ε���Ϊ0
//���Ϊ1����ѯ���������Ƿ���2������λ��+1��������ˮ��䣬����������2��������ټ�1
//����������컨���Ͼ�ֱ�Ӻ�ˮ���
    int n=grid.size(),m=grid[0].size();
    vector<int>ans(hits.size());
    if(n==1)return ans;
    for(auto h:hits)grid[h[0]][h[1]]--;
    for(int j=0;j<m;j++)LC803_hitBricks_DFS(0,j);
    for(int i=hits.size()-1,row,col;i>=0;i--){
        row=hits[i][0];
        col=hits[i][1];
        grid[row][col]++;
        if(LC803_hitBricks_worth(row,col)){
            ans[i]=LC803_hitBricks_DFS(row,col);
        }
    }
    return ans;
}
int CheckSet::Bricks::LC803_hitBricks_DFS(int i,int j){
    if(i<0||i==n||j<0||j==m||grid[i][j]!=1)return 0;
    grid[i][j]=2;
    return 1+LC803_hitBricks_DFS(i-1,j)+LC803_hitBricks_DFS(i+1,j)+LC803_hitBricks_DFS(i,j-1)+LC803_hitBricks_DFS(i,j+1);
}
bool CheckSet::Bricks::LC803_hitBricks_worth(int i,int j){
    return grid[i][j]==1
    &&
    (i==0
    ||(i>0&&grid[i-1][j]==2)
    ||(i+1<n&&grid[i+1][j]==2)
    ||(j>0&&grid[i][j-1]==2)
    ||(j+1<m&&grid[i][j+1]==2));
}
void CheckSet::Bricks::Test_LC803_hitBricks(){
    vector<vector<int>>g;
    vector<vector<int>>hits;
    Print(LC803_hitBricks(g,hits));
}

int main(){
    auto start=chrono::system_clock::now();
    //vector<vector<int>>meet={{1,2,12},{2,3,8},{1,5,10}};
    //sort(meet.begin(),meet.end(),[&](vector<int>&a,vector<int>&b)->bool {return a[2]<b[2];});
    //cout<<endl;
    //vector<int>vals={1,2,1,4,3};
    //vector<vector<int>>edge={{0,1},{1,2},{2,3},{2,4}};
    //sort(edge.begin(),edge.end(),[&vals,&edge](vector<int>a,vector<int>b)->bool {return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);});
    //cout<<endl;
//
    //cin.get();
    int In;cin>>In;
    switch(In){
        case 1:{
            using CheckSet::Cheack;
            Cheack che;
            che.Test_Check();
        }
        break;
        case 2:{
            using CheckSet::ChSet;
            ChSet ch;
            int Im;cin>>Im;
            switch(Im){
                case 1:ch.Test_LC765_minSwapsCouples();
                break;
                case 2:ch.Test_LC839_numSimilarGroups();
                default:break;
            }
        }
        case 3:{
            using CheckSet::AllPeople;
            AllPeople all;
            all.Test_LC2092_findAllPeople();
        }
        break;
        case 4:{
            using CheckSet::GoodPaths;
            GoodPaths go;
            go.Test_LC2421_numberOfGoodPaths();
        }
        break;
        case 5:{
            using CheckSet::MalwareSpread;
            MalwareSpread mal;
            mal.Test_LC928_minMalwareSpread();
        }
        break;
        case 6:{
            using CheckSet::Islands;
            Islands ls;
            ls.Test_LC200_numIslands();
        }
        break;
        case 7:{
            using CheckSet::Solve;
            Solve sle;
            sle.Test_LC130_solve();
        }
        break;
        case 8:{
            using CheckSet::LargeLand;
            LargeLand lg;
            lg.Test_LC827_largestIsland();
        }
        break;
        case 9:{
            using CheckSet::Bricks;
            Bricks bi;
            bi.Test_LC803_hitBricks();
        }
        break;
        default:break;
    }

    auto end=chrono::system_clock::now();
    cout<<"����ʱ��: "<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" ms "<<endl;
    cin.get();
    cin.get();
    return 0;
}