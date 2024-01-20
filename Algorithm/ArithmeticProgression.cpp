#include"ArithmeticProgression.h"
using namespace std;
using Difference::Arithmetic;

/// @brief LeetCode 1109 航班预定统计 case 1.1
/// @param bookings 
/// @param n 
/// @return 
vector<int>Arithmetic::LC1109_corpFlightBookings_(vector<vector<int>>&bookings,int n){
    vector<int>cnt(n+2);
    for(vector<int>book:bookings){
        cnt[book[0]]+=book[2];
        cnt[book[1]+1]-=book[2];
    }
    //对差分数组求前缀和
    for(int i=1;i<cnt.size();i++)cnt[i]+=cnt[i-1];
    //生成结果数组
    vector<int>ans(n);
    for(int i=0;i<n;i++)ans[i]=cnt[i+1];
    return ans;
}
void Arithmetic::Test_LC1109_corpFlightBookings(){
    /*测试 case=1.1 */
    vector<vector<int>>bookings={
        {1,2,10},{2,3,20},{2,5,25}
    };
    Cleanup cle;
    cle.Print(LC1109_corpFlightBookings_(bookings,5));
}

/// @brief 洛谷 P4231   case 1.2
/// @param n 
void Arithmetic::LGP4231_build(int n){
    for(int i=1;i<=n;i++)arr[i]+=arr[i-1];
    for(int i=1;i<=n;i++)arr[i]+=arr[i-1];
}
void Arithmetic::LGP4231_set(int l,int r,int s,int e,int d){
    arr[l]+=s;
    arr[l+1]+=(d-s);
    arr[r+1]-=(d+e);
    arr[r+2]+=e;
}
void Arithmetic::LGP4231_ArithmeticSeqenceDifference(){
    int n,m;
    cin>>n;cin>>m;
    while(m--){
        int l,r,s,e;
        cin>>l;cin>>r;cin>>s;cin>>e;
        LGP4231_set(l,r,s,e,(e-s)/(r-l));
        //LGP4231_build(n);
    }
    LGP4231_build(n);
    int Max=INT_MIN,Xor=0;
    for(int i=1;i<=n;i++){
        Max=max(Max,arr[i]);
        Xor^=arr[i];
    }
    cout<<Xor<<" "<<Max<<endl;
}

using Lycanthropy::LycanthropyInBack;
/// @brief 洛谷 P5026 Lycanthropy case 2.1
/// @param l 
/// @param r 
/// @param s 
/// @param e 
/// @param d 
void LycanthropyInBack::LGP5026_set(int l,int r,int s,int e,int d){
    arr[l+OFFSET]+=s;
    arr[l+OFFSET+1]+=(d-s);
    arr[r+OFFSET+1]-=(d+e);
    arr[r+OFFSET+2]+=e;
}
void LycanthropyInBack::LGP5026_fall(int v,int x){
    LGP5026_set(x-3*v+1,x-2*v,1,v,1);
    LGP5026_set(x-2*v+1,x,v-1,-v,-1);
    LGP5026_set(x+1,x+2*v,-v+1,v,1);
    LGP5026_set(x+v*2+1,x+3*v-1,v-1,1,-1);
}
void LycanthropyInBack::LGP5026_build(int m){
    for(int i=1;i<=m+OFFSET;i++)arr[i]+=arr[i-1];
    for(int i=1;i<=m+OFFSET;i++)arr[i]+=arr[i-1];
}
void LycanthropyInBack::Test_LGP5026_Lycanthropy(){
    cin>>n;cin>>m;
    while(n--){
        int v,x;
        cin>>v;cin>>x;
        LGP5026_fall(v,x);
    }
    LGP5026_build(m);
    int start=OFFSET+1;
    cout<<arr[start++]<<" ";
    for(int i=2;i<=m;i++)cout<<arr[start++]<<" ";
    cout<<endl;
}

using Lycanthropy::NumMatrix;
/// @brief LeetCode 304 二维区域和检索  case 3
/// @param martix 
NumMatrix::NumMatrix(vector<vector<int>>&martix){
    n=martix.size();
    m=martix[0].size();
    sum.resize(n+1,vector<int>(m+1,0));
    for(int i=1;i<sum.size();i++){
        for(int j=1;j<sum[i].size();j++){
            sum[i][j]=martix[i-1][j-1];
        }
    }
    for(int i=1;i<sum.size();i++){
        for(int j=1;j<sum[i].size();j++){
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
}
int NumMatrix::sumRegion(int row1,int col1,int row2,int col2){
    return sum[row2+1][col2+1]-sum[row2+1][col1]-sum[row1][col2+1]+sum[row1][col1];
}
void NumMatrix::Test_LC304_NumMatrix(){
    using std::cout;
    cout<<sumRegion(2,1,4,3)<<endl;
    cout<<sumRegion(1,1,2,2)<<endl;
    cout<<sumRegion(1,2,2,4)<<endl;
}

/// @brief LeetCode 1139 最大的以1为边界的正方形 case 4
/// @param martix 
/// @param i 
/// @param j 
/// @return 
int NumMatrix::LC1139_Get(vector<vector<int>>&martix,int i,int j){
    return (i<0||j<0)?0:martix[i][j];
}
void NumMatrix::LC1139_Build(vector<vector<int>>&martix,int n,int m){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            martix[i][j]+=LC1139_Get(martix,i-1,j)+LC1139_Get(martix,i,j-1)-LC1139_Get(martix,i-1,j-1);
}
int NumMatrix::LC1139_Sum(vector<vector<int>>&martix,int a,int b,int c,int d){
    //a>c:表示
    /*
    00
    00  下的内部正方形是没有的，所以判断此内部的索引会越界，   */
    return a>c?0:(martix[c][d]-LC1139_Get(martix,c,b-1)-LC1139_Get(martix,a-1,d)+LC1139_Get(martix,a-1,b-1));
}
int NumMatrix::LC1139_largest1BorderedSquare(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    LC1139_Build(grid,n,m);
    if(LC1139_Sum(grid,0,0,n-1,m-1)==0)return 0;
    int ans=1;
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            for(int c=a+ans,d=b+ans,k=ans+1;c<n&&d<m;c++,d++,k++){
                if(LC1139_Sum(grid,a,b,c,d)-LC1139_Sum(grid,a+1,b+1,c-1,d-1)==(k-1)<<2){
                    ans=k;
                }
            }
        }
    }
    return ans*ans;
}
void NumMatrix::Test_LC1139_largest1BorderedSquare(){
    vector<vector<int>>grid={{1,1,1},{1,0,1},{1,1,1}};
    cout<<LC1139_largest1BorderedSquare(grid)<<endl;
}

/// @brief LeetCode 2132 贴邮票 case 2.2
/// @param grid 
/// @param stampHeight 
/// @param stampWidth 
/// @return 
bool LycanthropyInBack::LC2132_possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth){
    int n=grid.size();
    int m=grid[0].size();
    //当前网格的前缀和
    vector<vector<int>>sum(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum[i+1][j+1]=grid[i][j];
        }
    }
    LC2132_Build(sum);
    //差分数组
    vector<vector<int>>diff(n+2,vector<int>(m+2,0));
    for(int a=1,c=a+stampHeight-1;c<=n;a++,c++){
        for(int b=1,d=b+stampWidth-1;d<=m;b++,d++){
            //判断从(a,b)到(c,d)范围内能不能贴邮票
            //c=a+hight-1   d=b+Width-1
            //即，(a,b)到(c,d)范围内的前缀和是否为0
            if(LC2132_sumRegion(sum,a,b,c,d)==0){
                LC2132_Add(diff,a,b,c,d);
            }
        }
    }
    //对差分数组求前缀和
    LC2132_Build(diff);
    //检查所有的格子
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(diff[i+1][j+1]==0&&grid[i][j]==0)return false;
        }
    }
    return true;
}
void LycanthropyInBack::LC2132_Build(vector<vector<int>>&sum){
    for(int i=1;i<sum.size();i++)
        for(int j=1;j<sum[i].size();j++)
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
}
int LycanthropyInBack::LC2132_sumRegion(vector<vector<int>>sum,int a,int b,int c,int d){
    return sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1];
}
void LycanthropyInBack::LC2132_Add(vector<vector<int>>&diff,int a,int b,int c,int d){
    diff[a][b]+=1;
    diff[a][d+1]-=1;
    diff[c+1][b]-=1;
    diff[c+1][d+1]+=1;
}
void LycanthropyInBack::Test_LC2132_possibleToStamp(){
    vector<vector<int>>grid={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    cout<<LC2132_possibleToStamp(grid,2,2)<<endl;
}

/// @brief  LeetCode LCP 74 最强祝福立场 case 2.3
/// @param forceField 
/// @return 
int LycanthropyInBack::LCP74_fieldOfGreatestBlessing(vector<vector<int>>&forceField){
    int n=forceField.size();
    vector<long>xs(2*n,0);
    vector<long>ys(2*n,0);
    for(int i=0,p=0,k=0;i<n;i++){
        long x=forceField[i][0];
        long y=forceField[i][1];
        long r=forceField[i][2];
        xs[p++]=(x<<1)-r;
        xs[p++]=(x<<1)+r;
        ys[k++]=(y<<1)-r;
        ys[k++]=(y<<1)+r;
    }
    int Sizex=LCP74_Sort(xs);
    int Sizey=LCP74_Sort(ys);
    vector<vector<int>>diff(Sizex+2,vector<int>(Sizey+2,0));
    for(int i=0,a,b,c,d;i<n;i++){
        long x=forceField[i][0];
        long y=forceField[i][1];
        long r=forceField[i][2];
        a=LCP74_Rank(xs,(x<<1)-r,Sizex);
        b=LCP74_Rank(ys,(y<<1)-r,Sizey);
        c=LCP74_Rank(xs,(x<<1)+r,Sizex);
        d=LCP74_Rank(ys,(y<<1)+r,Sizey);
        LCP74_Add(diff,a,b,c,d);
    }
    int ans=0;
    for(int i=1;i<diff.size();i++){
        for(int j=1;j<diff[0].size();j++){
            diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
            ans=max(ans,diff[i][j]);
        }
    }
    return ans;
}
void LycanthropyInBack::LCP74_Add(vector<vector<int>>&diff,int a,int b,int c,int d){
    diff[a][b]+=1;
    diff[a][d+1]-=1;
    diff[c+1][b]-=1;
    diff[c+1][d+1]+=1;
}
int LycanthropyInBack::LCP74_Rank(vector<long>&nums,long v,int size){
    int l=0;
    int r=size-1;
    int m,ans=0;
    while(l<=r){
        m=(l+r)/2;
        if(nums[m]>=v){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    return ans;
}
int LycanthropyInBack::LCP74_Sort(vector<long>&nums){
    sort(nums.begin(),nums.end());
    int size=1;
    for(int i=1;i<nums.size();i++)
        if(nums[i]!=nums[i-1])nums[size++]=nums[i];
    return size;
}
void LycanthropyInBack::Test_LCP74_fieldOfGreatestBlessing(){
    vector<vector<int>>grid={{4,7,6},{7,5,3},{1,6,2},{4,6,3}};
    cout<<LCP74_fieldOfGreatestBlessing(grid)<<endl;
}

int main(int argc,char*argv[]){
    using std::cin;
    using std::cout;
    auto start=chrono::system_clock::now();
    int In;
    cin>>In;
    switch(In){
        case 1:{
            Arithmetic ari;
            int Im;cin>>Im;
            switch(Im){
                case 1:ari.Test_LC1109_corpFlightBookings();
                break;
                case 2:ari.LGP4231_ArithmeticSeqenceDifference();
                break;
                default:break;
            }
        }
        break;
        case 2:{
            LycanthropyInBack lyc;
            int Im;cin>>Im;
            switch(Im){
                case 1:lyc.Test_LGP5026_Lycanthropy();
                break;
                case 2:lyc.Test_LC2132_possibleToStamp();
                break;
                case 3:lyc.Test_LCP74_fieldOfGreatestBlessing();
                default:break;
            }
        }
        break;
        case 3:{
            vector<vector<int>>martix={{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
            NumMatrix num(martix);
            num.Test_LC304_NumMatrix();
        }
        break;
        case 4:{
            NumMatrix num;
            num.Test_LC1139_largest1BorderedSquare();
        }
        case 5:{
            using LGP3397::LGP3397;
            LGP3397();
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