#include"MonotonousStack.h"
using namespace std;

/// @brief 寻找数组中每个数左边和右边第1个比自己小的数，没有就是-1
/// @param nums 
/// @return 
vector<vector<int>>Monotonous::MonStack::ANumbeSmallerThanYourself(vector<int>&nums){
    if(nums.size()<1)return {{}};
    vector<vector<int>>ans(nums.size(),vector<int>(2,0));
    for(int i=0;i<nums.size();i++){
        ans[i][0]=ANumbeSmallerThanYourself_left(nums,i);
        ans[i][1]=ANumbeSmallerThanYourself_right(nums,i);
    }
    return ans;
}
int Monotonous::MonStack::ANumbeSmallerThanYourself_left(vector<int>&nums,int i){
    if(i==0)return -1;
    for(int j=i-1;j>=0;j--){
        if(nums[j]<nums[i])return nums[j];
    }
    return -1;
}
int Monotonous::MonStack::ANumbeSmallerThanYourself_right(vector<int>&nums,int i){
    if(i==nums.size()-1)return -1;
    for(int j=i+1;j<nums.size();j++){
        if(nums[j]<nums[i])return nums[j];
    }
    return -1;
}
void Monotonous::MonStack::Test_ANumbeSmallerThanYourself(){
    vector<int>nums={2,3,4,3,2,1,3,5,6,3,4,3,2};
    vector<vector<int>>ans1=ANumbeSmallerThanYourself(nums);
    vector<vector<int>>ans2=ANumbeSmallerThanYourself_stack(nums);
    //for(vector<int>a:ans1)Print(a);
    //for(vector<int>a:ans2)Print(a);
    if(ans1!=ans2)cout<<"错误"<<endl;
    cout<<"结束"<<endl;
}
vector<vector<int>>Monotonous::MonStack::ANumbeSmallerThanYourself_stack(vector<int>&nums){
    if(nums.size()<1)return {{}};
    vector<vector<int>>ans(nums.size(),vector<int>(2,0));
    stack<int>sk;
    sk.push(0);
    //先遍历整个数组尽可能使所有数字都入栈
    for(int i=1;i<nums.size();i++){
        int pre=sk.top();
        //如果当前数字比栈顶的数字大或者相等，就结算栈顶的数字，等于也结算
        while(nums[pre]>=nums[i]){
            sk.pop();
            if(sk.empty())ans[pre][0]=-1;
            else ans[pre][0]=sk.top();
            ans[pre][1]=i;
            if(sk.empty())break;
            pre=sk.top();
        }
        sk.push(i);
    }
    //清算栈内的数字
    while(!sk.empty()){
        int pre=sk.top();
        sk.pop();
        ans[pre][1]=-1;
        if(!sk.empty())ans[pre][0]=sk.top();
        else ans[pre][0]=-1;
    }
    //修正结果集内相同的数
    for(int i=0;i<nums.size();i++){
        if(nums[ans[i][1]]==nums[i])ans[i][1]=ans[ans[i][1]][1];
    }
    //重新生成结果集
    for(int i=0;i<nums.size();i++){
        if(ans[i][0]!=-1)ans[i][0]=nums[ans[i][0]];
        if(ans[i][1]!=-1)ans[i][1]=nums[ans[i][1]];
    }
    return ans;
}

/// @brief LeetCode 739 每日温度 case 1.2
/// @param temperatures 
/// @return 
vector<int>Monotonous::MonStack::LC739_dailyTemperatures(vector<int>& temperatures){
    if(temperatures.size()==1)return {0};
    vector<int>ans(temperatures.size(),0);
    //单调栈、小压大
    stack<int>sk;
    sk.push(0);
    for(int i=1;i<temperatures.size();i++){
        //严格小压大，如果栈内元素小于等于即将入栈的元素就结算栈内元素
        while(!sk.empty()&&temperatures[sk.top()]<temperatures[i]){
            int index=sk.top();
            sk.pop();
            ans[index]=i-index;
        }
        sk.push(i);
    }
    return ans;
}
void Monotonous::MonStack::Test_LC739_dailyTemperatures(){
    vector<int>nums={34,80,80,34,34,80,80,80,80,34};
    Print(LC739_dailyTemperatures(nums));
}

/// @brief LeetCode 907 子数组的最小值之和 case 1.3
/// @param arr 
/// @return 
int Monotonous::MonStack::LC907_sumSubarrayMins(vector<int>& arr){
    long ans=0;
    stack<int>sk;
    for(int i=0;i<arr.size();i++){
        while(!sk.empty()&&arr[sk.top()]>=arr[i]){
            int cur=sk.top();
            sk.pop();
            int left=sk.empty()?-1:sk.top();
            ans=(ans+(long)(cur-left)*(i-cur)*arr[cur])%MOD;
        }
        sk.push(i);
    }
    while(!sk.empty()){
        int cur=sk.top();
        sk.pop();
        int left=sk.empty()?-1:sk.top();
        ans=(ans+(long)(cur-left)*(arr.size()-cur)*arr[cur])%MOD;
    }
    return (int)ans;
}
void Monotonous::MonStack::Test_LC907_sumSubarrayMins(){
    vector<int>arr={3,1,2,4};
    cout<<LC907_sumSubarrayMins(arr);
}

/// @brief LeetCode 84 柱状图中最大的矩形 case 1.4
/// @param heights 
/// @return 
int Monotonous::MonStack::LC74_largestRectangleArea(vector<int>& heights){
    int n=heights.size();
    int ans=0;
    stack<int>sk;
    for(int i=0;i<n;i++){
        while(!sk.empty()&&heights[sk.top()]>=heights[i]){
            int cur=sk.top();
            sk.pop();
            int left=sk.empty()?-1:sk.top();
            ans=max(ans,(i-left-1)*heights[cur]);
        }
        sk.push(i);
    }
    while(!sk.empty()){
        int cur=sk.top();
        sk.pop();
        int left=sk.empty()?-1:sk.top();
        ans=max(ans,(n-left-1)*heights[cur]);
    }
    return ans;
}
void Monotonous::MonStack::Test_LC74_largestRectangleArea(){
    vector<int>arr;
    cout<<LC74_largestRectangleArea(arr)<<endl;
}

/// @brief LeetCode 85 最大矩形 case 1.5
/// @param matrix 
/// @return 
int Monotonous::MonStack::LC85_maximalRectangle(vector<vector<int>>& matrix){
    //长方形在必须以0行做低的情况下他的最大的面积
    //在以1为底的情况下最大面积
    int ans=0;
    vector<int>arr(matrix[0].size());
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0)arr[j]=0;
            else arr[j]+=matrix[i][j];
        }
        ans=max(ans,LC85_maximalRectangle_f(arr));
    }
    return ans;
}
int Monotonous::MonStack::LC85_maximalRectangle_f(vector<int>arr){
    int ans=0;
    int n=arr.size();
    stack<int>sk;
    for(int i=0,cur,left;i<n;i++){
        while(!sk.empty()&&arr[sk.top()]>=arr[i]){
            cur=sk.top();
            sk.pop();
            left=sk.empty()?-1:sk.top();
            ans=max(ans,(i-left-1)*arr[cur]);
        }
        sk.push(i);
    }
    while(!sk.empty()){
        int cur=sk.top();
        sk.pop();
        int left=sk.empty()?-1:sk.top();
        ans=max(ans,(n-left-1)*arr[cur]);
    }
    return ans;
}
void Monotonous::MonStack::Test_LC85_maximalRectangle(){
    vector<vector<int>>matrix{{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    cout<<LC85_maximalRectangle(matrix)<<endl;
}

/// @brief LeetCode 962 最大坡宽度 case 1.6
/// @param nums 
/// @return 
int Monotonous::MonStack::LC962_maxWidthRamp(vector<int>& nums){
    int n=nums.size();
    int ans=0;
    stack<int>sk;
    for(int i=0;i<n;i++){
        if(!sk.empty()&&nums[sk.top()]<=nums[i])continue;
        sk.push(i);
    }
    for(int i=n-1;i>=0&&!sk.empty();i--){
        while(!sk.empty()&&nums[i]>=nums[sk.top()]){
            ans=max(ans,i-sk.top());
            sk.pop();
        }
    }
    return ans;
}
void Monotonous::MonStack::Test_LC962_maxWidthRamp(){
    vector<int>nums={9,8,1,0,1,9,4,0,4,1};
    cout<<LC962_maxWidthRamp(nums)<<endl;
}

/// @brief LeetCode 316 去除重复字母 case 1.7
/// @param s 
/// @return 
string Monotonous::MonStack::LC316_removeDuplicateLetters(string s){
    //保留字符的情况下，最小的字典序的可能性
    vector<int>map(26,0);
    stack<int>sk;
    vector<bool>us(26,false);
    for(int i=0;i<s.size();i++)map[s[i]-'a']++;
    for(int i=0;i<s.size();i++){
        //如果这个单词没有被记录过
        if(!us[s[i]-'a']){
            //
            while(!sk.empty()&&s[sk.top()]>s[i]&&map[s[sk.top()]-'a']>0){
                us[s[sk.top()]-'a']=false;
                sk.pop();
            }
            sk.push(i);
            us[s[i]-'a']=true;
        }
        
        map[s[i]-'a']--;
    }
    //清算
    int n=sk.size();
    string ans(" ",sk.size());
    cout<<ans<<endl;
    int m=ans.length();
    for(int i=m-1;i>=0;i--){
        ans[i]=s[sk.top()];
        sk.pop();
    }
    return ans;
}
void Monotonous::MonStack::Test_LC316_removeDuplicateLetters(){
    string s="cbacdcbc";
    cout<<LC316_removeDuplicateLetters(s)<<endl;
}

/// @brief 大鱼吃小鱼问题 case 1.8
void Monotonous::MonStack::BigFishEatSmallFish(){
    int n;
    scanf("%d",n);
    vector<int>arr(n);
    for(int i=0;i<n;i++)scanf("%d",arr[i]);
    cout<<BigFishEatSmallFish_turns(arr)<<endl;
}
int Monotonous::MonStack::BigFishEatSmallFish_turns(vector<int>arr){
    int n=arr.size();
    int ans=0;
    stack<pair<int,int>>sk;
    for(int i=n-1;i>=0;i--){
        pair<int,int>cur={i,0};
        while(!sk.empty()&&arr[sk.top().first]<arr[i]){
            cur.second=max(cur.second+1,sk.top().second);
            sk.pop();
        }
        ans=max(ans,cur.second);
        sk.push(cur);
    }
    return ans;
}
void Monotonous::MonStack::Test_BigFishEatSmallFish(){
    BigFishEatSmallFish();
    //vector<int>arr={8,3,7,3,4,5,6};
    //cout<<BigFishEatSmallFish_turns(arr)<<endl;
}

/// @brief LeetCode 1504 统计全1子矩阵 case 1.9
/// @param mat 
/// @return 
/*比如：
            1   
            1   
            1      1
    1       1      1
    1       1      1
    1       1      1

    3   ……  6   …… 8
    left    cur    i
    如上图，假设6位置从栈中弹出，6位置的高度为6（上面6个1）
    6位置的左边、离6最近、且小于高度6的是3位置（left），3的位置的高度是3
    6的右边、离6最近、且小于高度6的的位置是6位置（i），8位置的高度是4
    此时，
    1）求在索引(3+1,8-1)也就是4~7范围内上必须以高度6作为高的矩形有几个
    2）求在索引(3+1,8-1)也就是4~7范围内上必须以高度5作为高的矩形有几个
    也就是说，<=4的高度一律不求，>6的高度也一律不求
    其他位置也会从栈里弹出，等其他位置弹出的时候去求
    那么在4~7范围上必须以高度6作为高的矩形有：
    4……4    4……5    4……6    4……7
    5……5    5……6    5……7
    6……6    6……7
    7……7
    10个，公式为：
    4……7范围内的长度为4，那么数量就是：4*(4+1)/2;
    同理，在4~7范围上，必须以5作为高度的矩形也有这么多
    所以cur从栈里弹出时产生的矩形的数量为
    （cur位置的高度-MAX(left位置的高度，i位置的高度))*((i-left-1)*(i-left)/2)
    */
int Monotonous::MonStack::LC1504_numSubmat(vector<vector<int>>& mat){
    int n=mat.size();
    int m=mat[0].size();
    int ans=0;
    vector<int>arr(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)arr[j]=mat[i][j]==0?0:arr[j]+1;
        ans+=LC1504_numSubmat_f(arr);
    }
    return ans;
}
int Monotonous::MonStack::LC1504_numSubmat_f(vector<int>arr){
    int n=arr.size();
    stack<int>sk;
    int ans=0;
    for(int i=0,cur,left;i<n;i++){
        while(!sk.empty()&&arr[sk.top()]>=arr[i]){
            cur=sk.top();
            sk.pop();
            if(arr[cur]==arr[i])continue;
            //边界判断，如果此时栈为空，说明cur左侧的比他小的索引为-1
            left=sk.empty()?-1:sk.top();
            //如果left为-1那么其中最大的值就是arr[i],否则就取arr[left]与arr[i]的最大值
            int rs=left==-1?arr[i]:(arr[left]>arr[i]?arr[left]:arr[i]);
            //再用公式((i-left-1)*(i-left)/2)*(cur位置的高度-MAX(left位置的高度，i位置的高度))
            ans+=((i-left-1)*(i-left)/2*(arr[cur]-rs));
        }
        sk.push(i);
    }
    //清算
    while(!sk.empty()){
        int cur=sk.top();
        sk.pop();
        int left=sk.empty()?-1:sk.top();
        //因为右侧已经没有小于arr[cur]的值了
        //所以此时的范围就是从left到n（arr.size())
        //即要减去的也是arr[left]或者left也没有时取0
        int rs=left==-1?0:arr[left];
        ans+=((n-left-1)*(n-left)/2*(arr[cur]-rs));
    }
    return ans;
}
void Monotonous::MonStack::Test_LC1504_numSubmat(){
    vector<vector<int>>mat={{0,1,1,0},{0,1,1,1},{1,1,1,0}};
    cout<<LC1504_numSubmat(mat)<<endl;
}

int main(){
    auto start=chrono::system_clock::now();
    //cin.get();
    int In;
    cin>>In;
    switch(In){
        case 1:{
            using Monotonous::MonStack;
            MonStack mon;
            int Im;
            cin>>Im;
            switch(Im){
                case 1:mon.Test_ANumbeSmallerThanYourself();
                break;
                case 2:mon.Test_LC739_dailyTemperatures();
                break;
                case 3:mon.Test_LC907_sumSubarrayMins();
                break;
                case 4:mon.Test_LC74_largestRectangleArea();
                break;
                case 5:mon.Test_LC85_maximalRectangle();
                break;
                case 6:mon.Test_LC962_maxWidthRamp();
                break;
                case 7:mon.Test_LC316_removeDuplicateLetters();
                break;
                case 8:mon.Test_BigFishEatSmallFish();
                break;
                case 9:mon.Test_LC1504_numSubmat();
                break;
                default:break;
            }
        }
        break;

        default:break;
    }


    auto end=chrono::system_clock::now();
    cout<<"运行时长："<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" ms "<<endl;
    cin.get();
    cin.get();

}