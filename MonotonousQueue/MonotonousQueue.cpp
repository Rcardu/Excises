#include"MonotonousQueue.h"
using namespace std;

/// @brief LeetCode 239 滑动窗口最大值 case 1.1
/// @param nums 
/// @param k 
/// @return 
vector<int>Monque::Ques::LC239_maxSlidingWindow(vector<int>& nums, int k){
    deque<int>deq;
    int n=nums.size();
    for(int i=0;i<k-1;i++){
        while(!deq.empty()&&nums[deq.back()]<=nums[i])deq.pop_back();
        deq.push_back(i);
    }
    int m=n-k+1;
    vector<int>ans(m,0);
    for(int l=0,r=k-1;l<m;l++,r++){
        while(!deq.empty()&&nums[deq.back()]<=nums[r])deq.pop_back();
        deq.push_back(r);
        ans[l]=nums[deq.front()];
        if(deq.front()==l)deq.pop_front();
    }
    return ans;
    
}
void Monque::Ques::Test_LC239_maxSlidingWindow(){
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    Print(LC239_maxSlidingWindow(nums,3));
}

/// @brief LeetCode 1438 绝对值差不超过限制的最长连续子数组 case 1.2
/// @param nums 
/// @param limit 
/// @return 
int Monque::Ques::LC1438_longestSubarray(vector<int>& nums, int limit){
    int ans=1;
    //用来维护数组窗口中的最大值与最小值
    deque<int>MinQ;deque<int>MaxQ;
    for(int l=0,r=0;l<nums.size();l++){
        while(r<nums.size()&&LC1438_longestSubarray_Ok(MinQ,MaxQ,limit,nums[r],nums))LC1438_longestSubarray_Push(nums,MinQ,MaxQ,r++);
        ans=max(ans,r-l);
        LC1438_longestSubarray_Pop(MinQ,MaxQ,l);
    }
    return ans;
}
bool Monque::Ques::LC1438_longestSubarray_Ok(deque<int>&MinQ,deque<int>&MaxQ,int limit,int num,vector<int>& nums){
    int Max=!MaxQ.empty()?max(nums[MaxQ.front()],num):num;
    int Min=!MinQ.empty()?min(nums[MinQ.front()],num):num;
    return Max-Min<=limit;
}
void Monque::Ques::LC1438_longestSubarray_Push(vector<int>& nums,deque<int>&MinQ,deque<int>&MaxQ,int r){
    while(!MinQ.empty()&&nums[MinQ.back()]>=nums[r])MinQ.pop_back();
    MinQ.push_back(r);
    while(!MaxQ.empty()&&nums[MaxQ.back()]<=nums[r])MaxQ.pop_back();
    MaxQ.push_back(r);
}
void Monque::Ques::LC1438_longestSubarray_Pop(deque<int>&MinQ,deque<int>&MaxQ,int l){
    if(!MinQ.empty()&&MinQ.front()==l)MinQ.pop_front();
    if(!MaxQ.empty()&&MaxQ.front()==l)MaxQ.pop_front();
}
void Monque::Ques::Test_LC1438_longestSubarray(){
    vector<int>nums={4,2,2,2,4,4,2,2};
    cout<<LC1438_longestSubarray(nums,0)<<endl;
}

/// @brief 洛谷P2698 接取落水的最小花盆 case 1.3
int Monque::Ques::LGP2698_FallingWaterSmallestFlowerPot(){
    int N,D;
    scanf("%d%d",N,D);
    vector<vector<int>>arr(N,vector<int>(2,0));
    for(int i=0;i<N;i++)scanf("%d%d",arr[i][0],arr[i][1]);
    int ans=LGP2698_FallingWaterSmallestFlowerPot_compute(arr,N,D);
    return ans;
}
bool cmp(vector<int>&a,vector<int>&b){
    return a[0]<b[0];
}
int Monque::Ques::LGP2698_FallingWaterSmallestFlowerPot_compute(vector<vector<int>>&arr,int n,int d){
    deque<int>MaxQ,MinQ;
    //所有水滴根据x排序
    sort(arr.begin(),arr.end(),cmp);
    int ans=INT_MAX;
    for(int l=0,r=0;l<n;l++){
        //l:当前花盆的左边界
        while(!LGP2698_FallingWaterSmallestFlowerPot_compute_Ok(arr,MaxQ,MinQ,d)&&r<n)LGP2698_FallingWaterSmallestFlowerPot_compute_Push(arr,MaxQ,MinQ,r++);
        if(LGP2698_FallingWaterSmallestFlowerPot_compute_Ok(arr,MaxQ,MinQ,d))ans=min(ans,arr[r-1][0]-arr[l][0]);
        LGP2698_FallingWaterSmallestFlowerPot_compute_Pop(arr,MaxQ,MinQ,l);
    }
    return ans;
}
bool Monque::Ques::LGP2698_FallingWaterSmallestFlowerPot_compute_Ok(vector<vector<int>>&arr,deque<int>&MaxQ,deque<int>&MinQ,int d){
    int Max=!MaxQ.empty()?arr[MaxQ.front()][1]:0;
    int Min=!MinQ.empty()?arr[MinQ.front()][1]:0;
    return Max-Min>=d;
}
void Monque::Ques::LGP2698_FallingWaterSmallestFlowerPot_compute_Push(vector<vector<int>>&arr,deque<int>&MaxQ,deque<int>&MinQ,int r){
    while(!MaxQ.empty()&&arr[MaxQ.back()][1]<=arr[r][1])MaxQ.pop_back();
    MaxQ.push_back(r);
    while(!MinQ.empty()&&arr[MinQ.back()][1]>=arr[r][1])MinQ.pop_back();
    MinQ.push_back(r);
}
void Monque::Ques::LGP2698_FallingWaterSmallestFlowerPot_compute_Pop(vector<vector<int>>&arr,deque<int>&MaxQ,deque<int>&MinQ,int l){
    if(!MaxQ.empty()&&MaxQ.front()==l)MaxQ.pop_front();
    if(!MinQ.empty()&&MinQ.front()==l)MinQ.pop_front();
}
void Monque::Ques::Test_LGP2698_FallingWaterSmallestFlowerPot(){
    vector<vector<int>>arr{{6,3},{2,4},{4,10},{12,15}};
    cout<<LGP2698_FallingWaterSmallestFlowerPot_compute(arr,4,5)<<endl;
    //cout<<LGP2698_FallingWaterSmallestFlowerPot()<<endl;
}

/// @brief LeetCode 862 和至少为k的最短子数组 case 1.4
/// @param nums 
/// @param k 
/// @return 
int Monque::Ques::LC862_shortestSubarray(vector<int>& nums, int k){
    int ans=INT_MAX;
    vector<int>sums(nums.size()+1,0);
    for(int i=1;i<=nums.size();i++)sums[i]=sums[i-1]+nums[i-1];
    //小到大的双端队列
    deque<int>Deq;
    for(int r=0;r<sums.size();r++){
        while(!Deq.empty()&&sums[r]-sums[Deq.front()]>=k){
            ans=min(ans,r-Deq.front());
            Deq.pop_front();
        }
        while(!Deq.empty()&&sums[Deq.back()]>=sums[r])Deq.pop_back();
        Deq.push_back(r);
    }
    return ans==INT_MAX?-1:ans;
}
void Monque::Ques::LC862_shortestSubarray(){
    vector<int>nums={-28,81,-20,28,-29};
    cout<<LC862_shortestSubarray(nums,89)<<endl;
}

/// @brief LeetCode 1499 满足不等式的最大值 case 1.5
/// @param points 
/// @param k 
/// @return 
int Monque::Ques::LC1499_findMaxValueOfEquation(vector<vector<int>>& points, int k){
    //已知所有的点都是根据x的值来排序的
    //任何两个点组成的指标要求后x-前x<=k
    //返回最大指标
    deque<pair<int,int>>que;
    int n=points.size();
    int ans=INT_MIN;
    for(int i=0,x,y;i<n;i++){
        x=points[i][0];
        y=points[i][1];
        while(!que.empty()&&que.front().first+k<x)que.pop_front();
        //yi + yj + |xi - xj|
        if(!que.empty())ans=max(ans,y+que.front().second+x-que.front().first);
        //i号点的x和y，该从尾部进入单调队列
        while(!que.empty()&&que.back().second-que.back().first<=y-x)que.pop_back();
        que.push_back({x,y});
    }
    return ans;
}
void Monque::Ques::Test_LC1499_findMaxValueOfEquation(){
    vector<vector<int>>arr;
    cout<<LC1499_findMaxValueOfEquation(arr,4)<<endl;
}

/// @brief LeetCode 2071 你可以安排的最多任务数目 case 1.6
/// @param tasks 
/// @param workers 
/// @param pills 
/// @param strength 
/// @return 
int Monque::Ques::LC2071_maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength){
    int tsize=tasks.size(), wsize=workers.size();
    int Max=min(tsize,wsize);
    int ans=0;
    sort(tasks.begin(),tasks.end());
    sort(workers.begin(),workers.end());
    for(int l=0,r=Max,m;l<=r;){
        m=l+((r-l)>>1);
        if(LC2071_maxTaskAssign_f(tasks,workers,0,m-1,wsize-m,wsize-1,strength,pills)<=pills){
            ans=m;
            l=m+1;
        }else r=m-1;
    }
    return ans;
}
bool Monque::Ques::LC2071_maxTaskAssign_f(vector<int>& tasks, vector<int>& workers, int tl,int tr,int wl,int wr,int s,int pills){
    if(wl<0)return false;
    deque<int>que;
    int ans=0;
    for(int i=wl,j=tl;i<=wr;i++){
        //工人不吃药的情况下取解锁任务
        for(;j<=tr&&tasks[j]<=workers[i];j++){
            que.push_back(j);
        }
        //工人不吃药完成头部任务
        if(!que.empty()&&tasks[que.front()]<=workers[i])que.pop_front();
        else{
            // 工人吃药解锁任务
            for(;j<=tr&&tasks[j]<=workers[i]+s;j++)que.push_back(j);
            //工人完成尾部任务
            if(!que.empty()){
                ans++;
                que.pop_back();
            //工人吃了要药也完不成任务
            }else return false;
        }
    }
    return ans<=pills;
}
void Monque::Ques::Test_LC2071_maxTaskAssign(){
    vector<int>nums={3,2,1};
    vector<int>arr={0,3,3};
    cout<<LC2071_maxTaskAssign(nums,arr,18,10)<<endl;
}

int main(){
    auto start=chrono::system_clock::now();
    
    //cin.get();
    int In;cin>>In;
    switch(In){
        case 1:{
            using Monque::Ques;
            Ques qe;
            int Im;cin>>Im;
            switch(Im){
                case 1:qe.Test_LC239_maxSlidingWindow();
                break;
                case 2:qe.Test_LC1438_longestSubarray();
                break;
                case 3:qe.Test_LGP2698_FallingWaterSmallestFlowerPot();
                break;
                case 4:qe.LC862_shortestSubarray();
                break;
                case 5:qe.Test_LC1499_findMaxValueOfEquation();
                break;
                case 6:qe.Test_LC2071_maxTaskAssign();
                break;
                default:break;
            }
        }
        break;
        default:break;
    }

    auto end=chrono::system_clock::now();
    cout<<"运行时长: "<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" ms "<<endl;
    cin.get();
    cin.get();
    return 0;
}