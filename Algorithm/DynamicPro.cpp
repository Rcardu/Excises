#include"DynamicPro.h"
#include <queue>
#include <utility>
#include <vector>
using namespace std;


namespace DP_One_dimensional{
/***********************************************************************/
    /*斐波那契数列*/
    /// @brief 经典解法
    /// @param n 
    /// @return 
    int FibonacciNumber::FibonacciNumber_fib1(int n){
        return FibonacciNumber_f1(n);
    }
    int FibonacciNumber::FibonacciNumber_f1(int i){
        if(i==0)return 0;
        if(i==1)return 1;
        return FibonacciNumber_f1(i-1)+FibonacciNumber_f1(i-2);
    }
    void FibonacciNumber::Test_FibonacciNumber_fib1(){
        cout<<FibonacciNumber_fib1(10)<<endl;
}
    /// @brief 自顶到底
    /// @param n 
    /// @return 
    int FibonacciNumber::FibonacciNumber_fib2(int n){
        vector<int>findList(n+1,-1);
        return FibonacciNumber_f2(findList,n);
    }
    int FibonacciNumber::FibonacciNumber_f2(vector<int>&findList,int i){
        if(i==0)return 0;
        if(i==1)return 1;
        return findList[i]!=-1?findList[i]:(findList[i]=FibonacciNumber_f2(findList,i-1)+FibonacciNumber_f2(findList,i-2));
    }
    void FibonacciNumber::Test_FibonacciNumber_fib2(){
        cout<<FibonacciNumber_fib2(10)<<endl;
    }

    /// @brief 自底到顶
    /// @param n 
    /// @return 
    int FibonacciNumber::FibonacciNumber_fib3(int n){
        if(n==0)return 0;
        if(n==1)return 1;
        vector<int>dp(n+1);
        dp[1]=1;
        for(int i=2;i<=n;i++)dp[i]=dp[i-2]+dp[i-1];
        return dp[n];
    }
    void FibonacciNumber::Test_FibonacciNumber_fib3(){
        cout<<FibonacciNumber_fib3(10)<<endl;
    }
    /// @brief 空间优化
    /// @param n 
    /// @return 
    int FibonacciNumber::FibonacciNumber_fib4(int n){
        if(n==0)return 0;
        if(n==1)return 1;
        int dp0=0,dp1=1;
        for(int i=2;i<=n;i++){
            dp0+=dp1;
            swap(dp0,dp1);
        }
        return dp1;
    }
    void FibonacciNumber::Test_FibonacciNumber_fib4(){
        cout<<FibonacciNumber_fib4(10)<<endl;
    }
/***********************************************************************/
    /*LeetCode 983 最低票价*/
    ///暴力递归
    int mincostTickets::LC983_mincostTickets1(vector<int>& days, vector<int>& costs){
        return LC983_mincostTickets_f1(days,costs,0);
    }
    int mincostTickets::LC983_mincostTickets_f1(vector<int>&days,vector<int>&costs,int i){
        //当i来到days.size()位置的时候说明已经没有旅行了,最少花费为0
        if(i==days.size())return 0;
        //当来到days[i]天，有一场旅行
        //将三种方案都试一遍,去递归方案天数之外的花费
        
        //从days[i]开始到最后一天的最少花费
        int ans=INT_MAX;
        //一共三种方案 
        for(int k=0,j=i;k<3;k++){
            //从第days[i]天开始到方案k的总天数是否可以包含到第days[j]天
            while(j<days.size()&&days[i]+durations[k]>days[j])j++;
            //当前选择方案所花费的钱加上后续的花费
            ans=min(ans,costs[k]+LC983_mincostTickets_f1(days,costs,j));
        }
        return ans;
    }
    void mincostTickets::Test_LC983_mincostTickets1(){
        vector<int>days={1,2,3,4,5,6,7,8,9,10,30,31};
        vector<int>costs={2,7,15};
        cout<<LC983_mincostTickets1(days,costs);
    }
    /// @brief 自顶到底记忆化搜索
    /// @param days 
    /// @param costs 
    /// @return 
    int mincostTickets::LC983_mincostTickets2(vector<int>& days, vector<int>& costs){
        vector<int>dp(days.size(),INT_MAX);
        return LC983_mincostTickets_f2(days,costs,0,dp);
    }
    int mincostTickets::LC983_mincostTickets_f2(vector<int>&days,vector<int>&costs,int i,vector<int>&dp){
        //当i来到days.size()位置的时候说明已经没有旅行了,最少花费为0
        if(i==days.size())return 0;
        //当来到days[i]天，有一场旅行
        //将三种方案都试一遍,去递归方案天数之外的花费
        
        //如果此方案被记录过就返回此条记录
        if(dp[i]!=INT_MAX)return dp[i];
        //从days[i]开始到最后一天的最少花费
        int ans=INT_MAX;
        //一共三种方案 
        for(int k=0,j=i;k<3;k++){
            //从第days[i]天开始到方案k的总天数是否可以包含到第days[j]天
            while(j<days.size()&&days[i]+durations[k]>days[j])j++;
            //当前选择方案所花费的钱加上后续的花费
            ans=min(ans,costs[k]+LC983_mincostTickets_f2(days,costs,j,dp));
        }
        //记录此条记录
        dp[i]=ans;
        return ans;
    }
    void mincostTickets::Test_LC983_mincostTickets2(){
        vector<int>days={1,2,3,4,5,6,7,8,9,10,30,31};
        vector<int>costs={2,7,15};
        cout<<LC983_mincostTickets2(days,costs);
    }
    /// @brief 自底到顶依赖化递增
    /// @param days 
    /// @param costs 
    /// @return 
    int mincostTickets::LC983_mincostTickets3(vector<int>& days, vector<int>& costs){
        int n=days.size();
        vector<int>dp(n+1,INT_MAX);
        
        //下标n代表越界，即一个旅行也没有了，花费也就是零
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            for(int k=0,j=i;k<3;k++){
                while(j<days.size()&&days[i]+durations[k]>days[j])j++;
                
                //最小花费就是当前方案花费+后续花费
                dp[i]=min(dp[i],costs[k]+dp[j]);
            }
        }
        return dp[0];
    }
    void mincostTickets::Test_LC983_mincostTickets3(){
        vector<int>days={1,2,3,4,5,6,7,8,9,10,30,31};
        vector<int>costs={2,7,15};
        cout<<LC983_mincostTickets3(days,costs);
    }
/***********************************************************************/
    /*LeetCode 91 解码方法*/
    ///暴力递归
    int numDecodings::LC91_numDecodings1(string s){
        return LC91_numDecodings_f1(s,0);
    }
    //从s[i......]有多少种有效的转化方案
    int numDecodings::LC91_numDecodings_f1(string s,int i){
        //代表之前的决策是一种有效的转化
        if(i==s.length())return 1;
        int ans=0;
        //如果当前位置为0，无法转化，非有效转化，直接返回0
        if(s[i]=='0')return 0;
        else{
            //只转化一个
            ans=LC91_numDecodings_f1(s,i+1);
            //转化两个，值需要小于等于26
            if(i+1<s.length()&&((s[i]-'0')*10+s[i+1]-'0')<=26)ans+=LC91_numDecodings_f1(s,i+2);
        }
        return ans;
    }

    void numDecodings::Test_LC91_numDecodings1(){
        string s="226";
        cout<<LC91_numDecodings1(s)<<endl;
    }
    /// @brief 自顶到底记忆化搜索
    /// @param s 
    /// @return 
    int numDecodings::LC91_numDecodings2(string s){
        vector<int>dp(s.length(),-1);
        return LC91_numDecodings_f2(s,0,dp);
    }
    //从s[i......]有多少种有效的转化方案
    int numDecodings::LC91_numDecodings_f2(string s,int i,vector<int>&dp){
        //代表之前的决策是一种有效的转化
        if(i==s.length())return 1;
        //如果当前位置存在转化已被记录返回记录的值
        if(dp[i]!=-1)return dp[i];

        int ans=0;
        //如果当前位置为0，无法转化，非有效转化，直接返回0
        if(s[i]=='0')return 0;
        else{
            //只转化一个
            ans=LC91_numDecodings_f2(s,i+1,dp);
            //转化两个，值需要小于等于26
            if(i+1<s.length()&&((s[i]-'0')*10+s[i+1]-'0')<=26)ans+=LC91_numDecodings_f2(s,i+2,dp);
        }
        //收集当前位置的答案
        dp[i]=ans;
        return ans;
    }
    void numDecodings::Test_LC91_numDecodings2(){
        string s="226";
        cout<<LC91_numDecodings2(s)<<endl;
    }
    /// @brief 自底到顶严格递增
    /// @param s 
    /// @return 
    int numDecodings::LC91_numDecodings3(string s){
        int n=s.length();
        vector<int>dp(n+1,-1);
        dp[n]=1;
        //从右往左推
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')dp[i]=0;
            else{
                dp[i]=dp[i+1];
                if(i+1<n&&((s[i]-'0')*10+s[i+1]-'0')<=26)dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
    int numDecodings::LC91_numDecodings4(string s){
        int n=s.length();
        //dp[n]与dp[n+1]
        int dp0=1,dp1=-1;
        //从右往左推
        for(int i=n-1,cur;i>=0;i--){
            if(s[i]=='0')cur=0;
            else{
                cur=dp0;
                if(i+1<n&&((s[i]-'0')*10+s[i+1]-'0')<=26)cur+=dp1;
            }
            dp1=dp0;
            dp0=cur;
        }
        return dp0;
    }

    void numDecodings::Test_LC91_numDecodings3(){
        string s="226";
        cout<<LC91_numDecodings3(s)<<endl;
    }

/***********************************************************************/
    /*解码方法II*/
    //暴力递归
    int numDecodingsII::LC639_numDecodingsII1(string s){
        return LC639_numDecodingsII_f1(s,0);
    }
    int numDecodingsII::LC639_numDecodingsII_f1(string s,int i){
        if(i==s.length())return 1;
        
        //1分支i位置为0
        if(s[i]=='0')return 0;
        //2分支i位置单独转化
        int ans=LC639_numDecodingsII_f1(s,i+1)*(s[i]=='*'?9:1);

        //3分支i与i+1一起转化
        if(i+1<s.length()){
            if(s[i]!='*'){//i不是*
                if(s[i+1]!='*'){//i+1也不是*
                    if((s[i]-'0')*10+s[i+1]-'0'<=26)ans+=LC639_numDecodingsII_f1(s,i+2);
                }else{//i+1是*
                    if(s[i]=='1')ans+=9*LC639_numDecodingsII_f1(s,i+2);
                    if(s[i]=='2')ans+=6*LC639_numDecodingsII_f1(s,i+2);
                }
            }else{//i是*
                if(s[i+1]!='*'){//i+1不是*
                    if(s[i+1]<='6')ans+=2*LC639_numDecodingsII_f1(s,i+2);
                    else ans+=LC639_numDecodingsII_f1(s,i+2);
                }else{//i+1是*
                    /*
                        考虑到i与i+1位置的所有小于等于26的组合
                        11 12 13 14 15 16 17 18 19  9种
                        21 22 23 24 25 26           6种
                        一共15种组合，再去递归寻找
                    */
                   ans+=15*LC639_numDecodingsII_f1(s,i+2);
                }
            }
        }
        return ans%MOD;
    }
    void numDecodingsII::Test_LC639_numDecodingsII1(){
        string s="1*";
        cout<<LC639_numDecodingsII1(s)<<endl;
    }
    /// @brief 自顶向下记忆化搜索
    /// @param s 
    /// @return 
    int numDecodingsII::LC639_numDecodingsII2(string s){
        vector<long>dp(s.length(),-1);
        return LC639_numDecodingsII_f2(s,0,dp);
    }
    long numDecodingsII::LC639_numDecodingsII_f2(string s,int i,vector<long>&dp){
        if(i==s.length())return 1;
        
        if(dp[i]!=-1)return dp[i];

        //1分支i位置为0
        if(s[i]=='0')return 0;
        //2分支i位置单独转化
        long ans=LC639_numDecodingsII_f2(s,i+1,dp)*(s[i]=='*'?9:1);

        //3分支i与i+1一起转化
        if(i+1<s.length()){
            if(s[i]!='*'){//i不是*
                if(s[i+1]!='*'){//i+1也不是*
                    if((s[i]-'0')*10+s[i+1]-'0'<=26)ans+=LC639_numDecodingsII_f2(s,i+2,dp);
                }else{//i+1是*
                    if(s[i]=='1')ans+=9*LC639_numDecodingsII_f2(s,i+2,dp);
                    if(s[i]=='2')ans+=6*LC639_numDecodingsII_f2(s,i+2,dp);
                }
            }else{//i是*
                if(s[i+1]!='*'){//i+1不是*
                    if(s[i+1]<='6')ans+=2*LC639_numDecodingsII_f2(s,i+2,dp);
                    else ans+=LC639_numDecodingsII_f2(s,i+2,dp);
                }else{//i+1是*
                    /*
                        考虑到i与i+1位置的所有小于等于26的组合
                        11 12 13 14 15 16 17 18 19  9种
                        21 22 23 24 25 26           6种
                        一共15种组合，再去递归寻找
                    */
                   ans+=15*LC639_numDecodingsII_f2(s,i+2,dp);
                }
            }
        }
        //记录此值
        ans%=MOD;
        dp[i]=ans;
        return ans;
    }
    void numDecodingsII::Test_LC639_numDecodingsII2(){
        string s="7*9*3*6*3*0*5*4*9*7*3*7*1*8*3*2*0*0*6*";
        cout<<LC639_numDecodingsII2(s)<<endl;
    }
    /// @brief 自底向上
    /// @param s 
    /// @return 
    int numDecodingsII::LC639_numDecodingsII3(string s){
        int n=s.size();
        vector<long long>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            //ss[i]不能为'0'
            if(s[i]!='0'){
                //只选择i
                dp[i]=(s[i]=='*'?9:1)*dp[i+1];
                if(i+1<n){//选择i与i+1的组合
                    if(s[i]!='*'){//i不为*
                        if(s[i+1]!='*'){//i+1也不为*
                            //两个组和的值在26内
                            if((s[i]-'0')*10+s[i+1]-'0'<=26)dp[i]+=dp[i+2];
                        }else{//i+1是*
                            //1* 与2* 的两种情况，3*就超过26了
                            if(s[i]=='1')dp[i]+=dp[i+2]*9;
                            else if(s[i]=='2')dp[i]+=dp[i+2]*6;
                        }
                    }else{//i是*
                        if(s[i+1]!='*'){//i+1不为*
                            //s[i+1]小于等于6时 1与2都可以和s[i+1]组合
                            if(s[i+1]<='6')dp[i]+=dp[i+2]*2;
                            else dp[i]+=dp[i+2];
                        }else{//i+1是*
                            dp[i]+=dp[i+2]*15;
                        }
                    }
                }
                dp[i]%=MOD;
            }
        }
        return dp[0];
    }
    /// @brief 空间优化
    /// @param s 
    /// @return 
    int numDecodingsII::LC639_numDecodingsII4(string s){
        int n=s.size();
        long long dp0=1,dp1=-1,cur;
        for(int i=n-1;i>=0;i--){
            //ss[i]不能为'0'
            if(s[i]!='0'){
                //只选择i
                cur=(s[i]=='*'?9:1)*dp0;
                if(i+1<n){//选择i与i+1的组合
                    if(s[i]!='*'){//i不为*
                        if(s[i+1]!='*'){//i+1也不为*
                            //两个组和的值在26内
                            if((s[i]-'0')*10+s[i+1]-'0'<=26)cur+=dp1;
                        }else{//i+1是*
                            //1* 与2* 的两种情况，3*就超过26了
                            if(s[i]=='1')cur+=dp1*9;
                            else if(s[i]=='2')cur+=dp1*6;
                        }
                    }else{//i是*
                        if(s[i+1]!='*'){//i+1不为*
                            //s[i+1]小于等于6时 1与2都可以和s[i+1]组合
                            if(s[i+1]<='6')cur+=dp1*2;
                            else cur+=dp1;
                        }else{//i+1是*
                            cur+=dp1*15;
                        }
                    }
                }
                cur%=MOD;
            }
            dp1=dp0;
            dp0=cur;
            cur=0;
        }
        return dp0;
    }
/***********************************************************************/
    /*丑数II*/
    void numDecodingsII::Test_LC639_numDecodingsII3(){
        string s="1*";
        cout<<LC639_numDecodingsII4(s)<<endl;
    }
    int nthUglyNumber::LC264_nthUglyNumber(int n){
        vector<int>dp(n+1);
        dp[0]=1;
        //i2,i3,i5:乘以2、3、5的三个指针分别停在什么下标
        for(int i=1,i2=0,i3=0,i5=0,a,b,c,cur;i<=n;i++){
            //当前指针位置的丑数乘以2、3、5的因子
            a=dp[i2]*2;
            b=dp[i3]*3;
            c=dp[i5]*5;
            //找出最小的那个丑数
            cur=min(a,min(b,c));
            //将最小丑数所指的所有指针+1
            if(cur==a)i2++;
            if(cur==b)i3++;
            if(cur==c)i5++;
            //给予第i个位置丑数cur
            dp[i]=cur;
        }
        return (int)dp[n];
    }
    void nthUglyNumber::Test_LC264_nthUglyNumber(){
        cout<<LC264_nthUglyNumber(1000000000 )<<endl;
    } 
/***********************************************************************/
    /*有效括号*/
    int longestValidParentheses::LC32_longestValidParentheses(string s){
        /*
        dp[i]-->'(':dp[i]==0
        dp[i]->')'*,根据dp[i-1]的长度往前跳到匹配的位置p位置
            a.[p]-->')',dp[i]=0;
            b.[p]-->'(',dp[i]==dp[i-1]+2+dp[p-1]*/
        int n=s.length();
        vector<int>dp(n,0);
        int ans=dp[0];
        for(int i=1,p;i<n;i++){
            if(s[i]==')'){//右括号就记录，左括号直接跳过此条
                p=i-dp[i-1]-1;//定位p的位置
                //如果p在索引内且合格，dp[i]至少是dp[i-1]+2:再看看p-1位置的情况
                if(p>=0&&s[p]=='(')dp[i]=dp[i-1]+2+(p>0?dp[p-1]:0);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
    void longestValidParentheses::Test_LC32_longestValidParentheses(){
        string s="(()";
        cout<<LC32_longestValidParentheses(s)<<endl;
    }
/***********************************************************************/
    /*环绕字符串中唯一的子字符串*/
    int findSubstringInWraproundString::LC467_findSubstringInWraproundString(string s){
         int n=s.length();
         vector<int>str(n);
         for(int i=0;i<n;i++)str[i]=s[i]-'a';
         //dp[0]:s中必须以'a'的子串，最大延伸的长度是多少
         vector<int>dp(26);
         dp[str[0]]=1;
         for(int i=1,cur,pre,len=1;i<n;i++){
            //当前字符
            cur=str[i];
            //前一个字符
            pre=str[i-1];
            if((pre==25&&cur==0)||pre+1==cur){
                //特判，如果前一个字符是z当前是a，那么也成立
                len++;
            }else len=1;
            dp[cur]=max(len,dp[cur]);
         }
         int ans=0;
         for(int i=0;i<26;i++)ans+=dp[i];
         return ans;
    }
    void findSubstringInWraproundString::Test_LC467_findSubstringInWraproundString(){
        string s="zab";
        cout<<LC467_findSubstringInWraproundString(s)<<endl;
    }
/***********************************************************************/
    /*不同的子序列II*/
    int distinctSubseqII::LC940_distinctSubseqII(string s){
        //用来记录以某个字母结尾的子串的个数
        vector<int>cnt(26);
        //总子串的个数、以某个字母结尾的情况下排除已有的子串，纯新增的子串的个数
        int all=1,newAdd;
        for(char x:s){
            //纯新增的子串个数就是之前收集到的总个数-以当前字母结尾的记录的个数
            newAdd=(all-cnt[x-'a']+MOD)%MOD;
            //新的以当前字母结尾的子串的个数就是再加上新增的个数
            cnt[x-'a']=(cnt[x-'a']+newAdd)%MOD;
            //总记录就是新增的加上之前总的
            all=(all+newAdd)%MOD;
        }
        return (all-1+MOD)%MOD;
    }
    void distinctSubseqII::Test_LC940_distinctSubseqII(){
        string s="aba";
        cout<<LC940_distinctSubseqII(s)<<endl;
    }
/***********************************************************************/
}


namespace DP_Two_dimensional{
/***********************************************************************/
    int minPathSum::LC64_minPathSum(vector<vector<int>>& grid){
        return LC64_minPathSum_f1(grid,grid.size()-1,grid[0].size()-1);
    }
    //暴力递归
    int minPathSum::LC64_minPathSum_f1(vector<vector<int>>& grid,int i,int j){
        //到起点时直接返回
        if(i==0&&j==0)return grid[0][0];

        int up=INT_MAX;
        int left=INT_MAX;
        //去上面
        if(i-1>=0)up=LC64_minPathSum_f1(grid,i-1,j);
        //左边
        if(j-1>=0)left=LC64_minPathSum_f1(grid,i,j-1);
        return grid[i][j]+min(up,left);
    }   
    void minPathSum::Test_LC64_minPathSum(){
        vector<vector<int>>grid;
        cout<<LC64_minPathSum(grid)<<endl;
    }
    ///记忆化搜索
    int minPathSum::LC64_minPathSum2(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return LC64_minPathSum_f2(grid,n-1,m-1,dp);
    }
    int minPathSum::LC64_minPathSum_f2(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        int ans;
        if(i==0&&j==0)ans=grid[0][0];
        else{
            int up=INT_MAX;
            int left=INT_MAX;
            if(i>0)up=LC64_minPathSum_f2(grid,i-1,j,dp);
            if(j>0)left=LC64_minPathSum_f2(grid,i,j-1,dp);
            ans=grid[i][j]+min(up,left);
        }
        dp[i][j]=ans;
        return ans;
    }
    void minPathSum::Test_LC64_minPathSum2(){
        vector<vector<int>>grid;
        cout<<LC64_minPathSum2(grid)<<endl;
    }
    //严格位置依赖
    int minPathSum::LC64_minPathSum3(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)dp[0][i]=dp[0][i-1]+grid[0][i];
        for(int i=1;i<n;i++)dp[i][0]=dp[i-1][0]+grid[i][0];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
    //空间优化
    int minPathSum::LC64_minPathSum4(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<int>dp(m,0);
        dp[0]=grid[0][0];
        for(int j=1;j<m;j++)dp[j]=grid[0][j]+dp[j-1];
        for(int i=1;i<n;i++){
            //更新第0列的值
            dp[0]+=grid[i][0];
            for(int j=1;j<m;j++){
                //更新i行j列的值 
                dp[j]=min(dp[j-1],dp[j])+grid[i][j];
            }
        }
        return dp[m-1];
        
    }
    void minPathSum::Test_LC64_minPathSum3(){
        vector<vector<int>>grid={{1,3,1},{1,5,1},{4,2,1}};
        cout<<LC64_minPathSum4(grid)<<endl;
    }
/***********************************************************************/
    /*LeetCode 79 单词搜索*/
    bool exist::LC79_exist(vector<vector<char>>& board, string word){
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(LC79_exist_f(board,i,j,word,0))return true;
            }
        }
        return false;
    }
    bool exist::LC79_exist_f(vector<vector<char>>& board,int i,int j,string word,int k){
        //是否越界与是否合格
        if(i<0||i==board.size()||j<0||j==board[0].size()||board[i][j]!=word[k])return false;
        //匹配则临时修改当前位置，继续递归搜索
        char tmp=board[i][j];
        board[i][j]='0';
        bool ans=LC79_exist_f(board,i-1,j,word,k+1)
                ||LC79_exist_f(board,i+1,j,word,k+1)
                ||LC79_exist_f(board,i,j-1,word,k+1)
                ||LC79_exist_f(board,i,j+1,word,k+1);
        board[i][j]=tmp;
        return ans;
    }
    void exist::Test_LC79_exist(){
        vector<vector<char>>board;
        string word;
        LC79_exist(board,word);
    }
/***********************************************************************/
    /*LeetCode 1143 最长公共子序列*/
    int longestCommonSubsequence::LC1143_longestCommonSubsequence1(string text1, string text2){
        int n=text1.size();
        int m=text2.size();
        return LC1143_longestCommonSubsequence_f1(text1,text2,n-1,m-1);
    }
    /*s1[0....i1]与s2[0....i2]最长公共子序列的长度*/
    int longestCommonSubsequence::LC1143_longestCommonSubsequence_f1(string text1, string text2,int i1,int i2){
        //无论哪个串遍历到0以外，都说明没有了，返回0 
        if(i1<0||i2<0)return 0;
        /*以i1、i2结尾的最长公共子序列一共四种可能性
        1.既不包含以i1结尾，也不包含i2结尾，继续递归讨论以i1-1与i2-1结尾的
        2.只包含i1结尾的，但不包含i2
        3.只包含i2结尾的，但不包含i1
        4.s[i1]==s[i2]都包含，继续递归寻找*/
        int p1=LC1143_longestCommonSubsequence_f1(text1,text2,i1-1,i2-1);
        int p2=LC1143_longestCommonSubsequence_f1(text1,text2,i1,i2-1);
        int p3=LC1143_longestCommonSubsequence_f1(text1,text2,i1-1,i2);
        int p4=text1[i1]==text2[i2]?(p1+1):0;
        return max(max(p1,p2),max(p3,p4));

    }
    /// @brief 改变描述方法
    /// @param text1 
    /// @param text2 
    /// @return 
    int longestCommonSubsequence::LC1143_longestCommonSubsequence2(string text1, string text2){
        int len1=text1.size();
        int len2=text2.size();
        return LC1143_longestCommonSubsequence_f2(text1,text2,len1,len2);
    }
    /*s1[前缀长度为len1]与s2[前缀长度为len2]
    最长公共子序列的长度*/
    int longestCommonSubsequence::LC1143_longestCommonSubsequence_f2(string text1, string text2,int len1,int len2){
        //无论哪个串遍历到0，都说明没有了，返回0 
        if(len1==0||len2==0)return 0;
        /*以i1、i2结尾的最长公共子序列一共四种可能性
        1.既不包含以i1结尾，也不包含i2结尾，继续递归讨论以i1-1与i2-1结尾的
        2.只包含i1结尾的，但不包含i2
        3.只包含i2结尾的，但不包含i1
        4.s[i1]==s[i2]都包含，继续递归寻找*/
        int ans;
        if(text1[len1-1]==text2[len2-1]){
            ans=LC1143_longestCommonSubsequence_f2(text1,text2,len1-1,len2-1)+1;
        }else{
            ans=max(LC1143_longestCommonSubsequence_f2(text1,text2,len1-1,len2),LC1143_longestCommonSubsequence_f2(text1,text2,len1,len2-1));
        }
        return ans;

    }
    /// @brief 记忆化搜索
    /// @param text1 
    /// @param text2 
    /// @return 
    int longestCommonSubsequence::LC1143_longestCommonSubsequence3(string text1, string text2){
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return LC1143_longestCommonSubsequence_f3(text1,text2,n,m,dp);
    }
    /*s1[前缀长度为len1]与s2[前缀长度为len2]
    最长公共子序列的长度*/
    int longestCommonSubsequence::LC1143_longestCommonSubsequence_f3(string text1, string text2,int len1,int len2,vector<vector<int>>&dp){
        //无论哪个串遍历到0，都说明没有了，返回0 
        if(len1==0||len2==0)return 0;
        if(dp[len1][len2]!=-1)return dp[len1][len2];
        /*以i1、i2结尾的最长公共子序列一共四种可能性
        1.既不包含以i1结尾，也不包含i2结尾，继续递归讨论以i1-1与i2-1结尾的
        2.只包含i1结尾的，但不包含i2
        3.只包含i2结尾的，但不包含i1
        4.s[i1]==s[i2]都包含，继续递归寻找*/
        int ans;
        if(text1[len1-1]==text2[len2-1]){
            ans=LC1143_longestCommonSubsequence_f3(text1,text2,len1-1,len2-1,dp)+1;
        }else{
            ans=max(LC1143_longestCommonSubsequence_f3(text1,text2,len1-1,len2,dp),LC1143_longestCommonSubsequence_f3(text1,text2,len1,len2-1,dp));
        }
        dp[len1][len2]=ans;
        return ans;
    }
    /// @brief 严格位置依赖
    /// @param text1 
    /// @param text2 
    /// @return 
    int longestCommonSubsequence::LC1143_longestCommonSubsequence4(string text1, string text2){
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int len1=1;len1<=n;len1++){
            for(int len2=1;len2<=m;len2++){
                //当text1[len1-1]==text2[len2-1]时它依赖于它左上的格子
                if(text1[len1-1]==text2[len2-1])dp[len1][len2]=dp[len1-1][len2-1]+1;
                //否则它依赖于上面的格子或者左边的格子
                else dp[len1][len2]=max(dp[len1][len2-1],dp[len1-1][len2]);
            }
        }
        return dp[n][m];
    }
    /// @brief 空间优化
    /// @param text1 
    /// @param text2 
    /// @return 
    int longestCommonSubsequence::LC1143_longestCommonSubsequence5(string text1, string text2){
        string s1,s2;
        if(text1.size()>text2.size()){
            s1=text1;
            s2=text2;
        }else{
            s1=text2;
            s2=text1;
        }
        int n=s1.size();
        int m=s2.size();
        
        vector<int>dp(m+1,0);
        for(int len1=1;len1<=n;len1++){
            //用来记录当前左上角的值与下一个左上角的值
            int leftUp=0,backUp;
            for(int len2=1;len2<=m;len2++){
                backUp=dp[len2];
                if(s1[len1-1]==s2[len2-1])dp[len2]=leftUp+1;
                //上面的值就是当前位置，前面的值就是len2-1
                else dp[len2]=max(dp[len2],dp[len2-1]);
                //更新左上角的值
                leftUp=backUp;
            }   
        }
        return dp[m];
    }
    void longestCommonSubsequence::Test_LC1143_longestCommonSubsequence(){
        string s1,s2;
        cout<<LC1143_longestCommonSubsequence5(s1,s2)<<endl;
    }
/***********************************************************************/
    /*LeetCode 516 最长回文子序列*/
    /*解法1：一个字符串的最长回文子序列就他与他的逆序串的  最长公共子序列*/
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq_EX(string s){
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;
        int n=s1.size();
        int m=s2.size();
        vector<int>dp(m+1,0);
        for(int i=1;i<=n;i++){
            int leftUp=0,backUp;
            for(int j=1;j<=m;j++){
                backUp=dp[j];
                if(s1[i-1]==s2[j-1])dp[j]=leftUp+1;
                else dp[j]=max(dp[j],dp[j-1]);
                leftUp=backUp;
            }
        }
        return dp[m];
    }
    /// @brief 讨论从[L....R]区间内的最长回文子序列
    /// @param s 
    /// @return 
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq1(string s){
        int n=s.size();
        return LC516_longestPalindromeSubseq1_f1(s,0,n-1);
    }
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq1_f1(string s,int l,int r){
        //当l==r时说明到了同一个位置的字符，长度为1，直接返回
        if(l==r)return 1;
        //如果这个范围上有两个字符
        if(l+1==r){
            //如果这两个字符相等，返回2，否则返回1
            return s[l]==s[r]?2:1;
        }
        //如果当前两个位置的字符相等，结果+2，并讨论[L+1.....R-1]范围内的最长回文子序列
        if(s[l]==s[r])return 2+LC516_longestPalindromeSubseq1_f1(s,l+1,r-1);
        //不相等，则在[L+1....R]与[L....R-1]范围的的最长回文子序列取最大值
        else return max(LC516_longestPalindromeSubseq1_f1(s,l+1,r),LC516_longestPalindromeSubseq1_f1(s,l,r-1));
    }
    /// @brief 记忆化搜索
    /// @param s 
    /// @return 
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq2(string s){
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return LC516_longestPalindromeSubseq1_f2(s,0,n-1,dp);
    }
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq1_f2(string s,int l,int r,vector<vector<int>>&dp){
        //当l==r时说明到了同一个位置的字符，长度为1，直接返回
        if(l==r)return 1;
        //如果这个范围上有两个字符
        if(l+1==r){
            //如果这两个字符相等，返回2，否则返回1
            return s[l]==s[r]?2:1;
        }
        if(dp[l][r]!=-1)return dp[l][r];
        int ans;
        //如果当前两个位置的字符相等，结果+2，并讨论[L+1.....R-1]范围内的最长回文子序列
        if(s[l]==s[r])ans=2+LC516_longestPalindromeSubseq1_f2(s,l+1,r-1,dp);
        //不相等，则在[L+1....R]与[L....R-1]范围的的最长回文子序列取最大值
        else ans=max(LC516_longestPalindromeSubseq1_f2(s,l+1,r,dp),LC516_longestPalindromeSubseq1_f2(s,l,r-1,dp));
        dp[l][r]=ans;
        return ans;
    }
    /// @brief 严格位置依赖
    /// @param s 
    /// @return 
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq3(string s){
        /*当前位置的格子依赖于(l+1,r-1)、(l+1,r)、(l,r-1)位置的格子，说明应该从下到上，从左到右进行遍历*/
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        //从底部开始遍历
        for(int l=n-1;l>=0;l--){
            //l不能大于r，即l大于r的格子都是无效格子
            dp[l][l]=1;
            //如果是两个字符，就直接判断
            if(l+1<n)dp[l][l+1]=s[l]==s[l+1]?2:1;
            //如果两个字符以上开始dp
            for(int r=l+2;r<n;r++){
                if(s[l]==s[r])dp[l][r]=2+dp[l-1][r-1];
                else dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
            }
        }
        return dp[0][n-1];
    }
    /// @brief 空间压缩
    /// @param s 
    /// @return 
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq4(string s){
        int n=s.size();
        vector<int>dp(n,0);
        //记录左下角的值
        for(int l=n-1,leftDown=0,backDown;l>=0;l--){
            dp[l]=1;
            if(l+1<n){
                //更新左下角的值
                leftDown=dp[l+1];
                dp[l+1]=s[l]==s[l+1]?2:1;
            }
            for(int r=l+2;r<n;r++){
                //记录左下角的值
                backDown=dp[r];
                if(s[l]==s[r])dp[r]=2+leftDown;
                else dp[r]=max(dp[r],dp[r-1]);
                //更新左下角的值
                leftDown=backDown;
            }
        }
        return dp[n-1];
    }
    void longestPalindromeSubseq::Test_LC516_longestPalindromeSubseq(){
        string s;
        cout<<LC516_longestPalindromeSubseq4(s)<<endl;

    }
/***********************************************************************/
    /*在限制高度的情况下二叉树的个数*/
    //记忆化搜索
    int NodenHeightNotLargerThanm::Main_Compute1(int n,int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return Compute1(n,m,dp);
    }
    int NodenHeightNotLargerThanm::Compute1(int n,int m,vector<vector<int>>&dp){
        //空树
        if(n==0)return 1;
        //高度为0的话
        if(m==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        int ans=0;
        for(int k=0;k<n;k++){
            //左树有k个,高度限制为m-1   右树有n-k-1个，高度为m-1
            ans=(ans+(Compute1(k,m-1,dp)*Compute1(n-k-1,m-1,dp))%MOD)%MOD;
        }
        dp[n][m]=ans;
        return ans;  
    }
    /// @brief 严格位置依赖
    /// @param n 
    /// @param m 
    /// @return 
    int NodenHeightNotLargerThanm::Main_Compute2(int n,int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++)dp[0][j]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=0;
                for(int k=0;k<i;k++){
                    //一共i个节点，头结点占用了一个名额，
                    //如果左树占用k个，那么右树就占用i-k-1个
                    dp[i][j]=(dp[i][j]+dp[k][j-1]*dp[i-k-1][j-1]%MOD)%MOD;
                }
            }
        }
        return dp[n][m];
    }
    /// @brief 空间压缩
    /// @param n 
    /// @param m 
    /// @return 
    int NodenHeightNotLargerThanm::Main_Compute3(int n,int m){
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int j=1;j<=m;j++){
            //根据依赖，一定要先枚举列
            for(int i=n;i>=1;i--){
                //再枚举行
                dp[i]=0;
                for(int k=0;k<i;k++){//枚举每个节点
                    dp[i]=(dp[i]+dp[k]*dp[i-k-1]%MOD)%MOD;
                }
            }
        }
        return dp[n];
    }
    void NodenHeightNotLargerThanm::Test_Main_Compute(){
        cout<<Main_Compute2(10,10)<<endl;
    }
/***********************************************************************/   
    /*LeetCode 329 矩阵中的最长递增路径*/
    int longestIncreasingPath::LC329_longestIncreasingPath1(vector<vector<int>>& matrix){
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,LC329_longestIncreasingPath1_f1(matrix,i,j));
            }
        }
        return ans;
    }
    //从(i,j)出发能走出来的最长的递增路径
    int longestIncreasingPath::LC329_longestIncreasingPath1_f1(vector<vector<int>>& grid,int i,int j){
        int next=0;
        if(i>0&&grid[i][j]<grid[i-1][j])next=LC329_longestIncreasingPath1_f1(grid,i-1,j);
        if(i+1<grid.size()&&grid[i][j]<grid[i+1][j])next=LC329_longestIncreasingPath1_f1(grid,i+1,j);
        if(j>0&&grid[i][j]<grid[i][j-1])next=LC329_longestIncreasingPath1_f1(grid,i,j-1);
        if(j+1<grid[0].size()&&grid[i][j]<grid[i][j+1])next=LC329_longestIncreasingPath1_f1(grid,i,j+1);
        return next+1;
    }
    int longestIncreasingPath::LC329_longestIncreasingPath2(vector<vector<int>>& matrix){
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,LC329_longestIncreasingPath1_f2(matrix,i,j,dp));
            }
        }
        return ans;
    }
    //记忆化搜索
    int longestIncreasingPath::LC329_longestIncreasingPath1_f2(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        if(dp[i][j]!=0)return dp[i][j];
        int next=0;
        if(i>0&&grid[i][j]<grid[i-1][j])next=max(next,LC329_longestIncreasingPath1_f2(grid,i-1,j,dp));
        if(i+1<grid.size()&&grid[i][j]<grid[i+1][j])next=max(next,LC329_longestIncreasingPath1_f2(grid,i+1,j,dp));
        if(j>0&&grid[i][j]<grid[i][j-1])next=max(next,LC329_longestIncreasingPath1_f2(grid,i,j-1,dp));
        if(j+1<grid[0].size()&&grid[i][j]<grid[i][j+1])next=max(next,LC329_longestIncreasingPath1_f2(grid,i,j+1,dp));
        dp[i][j]=next+1;
        return next+1;
    }
    void longestIncreasingPath::Test_LC329_longestIncreasingPath(){
        vector<vector<int>>grid={{1,2,1},{3,5,7},{7,1,3}};
        cout<<LC329_longestIncreasingPath1(grid)<<endl;
    }
/***********************************************************************/   
    /*LeetCode 115 不同的子序列*/
    int numDistinct::LC115_numDistinct(string s, string t){
        /*dp[i][j]:s串从0到第i个字符串可以生成的子串中包含t串从0到j个字符的个数
        即s的第[i-1]位置的字符不要：那么就只能从[0.....i-2]中取得组合即dp[i-1][j]
        s的第[i-1]位置的字符要，那么就是t[j-1]==s[i-1]
        1.dp[i-1][j]
        2.s[i-1]==t[j-1]    dp[i-1][j-1]*/
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i-1][j];
                if((s[i-1]=t[j-1]))dp[i][j]+=dp[i-1][j-1];
            }
        }
        return dp[n][m];
    }
    /// @brief 空间压缩
    /// @param s 
    /// @param t 
    /// @return 
    int numDistinct::LC115_numDistinct_EC(string s, string t){
        /*dp[i][j]:s串从0到第i个字符串可以生成的子串中包含t串从0到j个字符的个数
        即s的第[i-1]位置的字符不要：那么就只能从[0.....i-2]中取得组合即dp[i-1][j]
        s的第[i-1]位置的字符要，那么就是t[j-1]==s[i-1]
        1.dp[i-1][j]
        2.s[i-1]==t[j-1]    dp[i-1][j-1]*/
        int n=s.size();
        int m=t.size();
        vector<int>dp(m+1,0);
        dp[0]=1;
        for(int i=0;i<=n;i++)
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1])dp[j]+=dp[j-1];
            }
        }
    return dp[m];
    }
    void numDistinct::Test_LC115_numDistinct(){
        string s,t;
        cout<<LC115_numDistinct(s,t)<<endl;
    }
/***********************************************************************/ 
    /*LeetCode 72 编辑距离*/
    int minDistance::LC72_minDistance1(string s1, string s2,int a,int b,int c){
        /*s1取前i个，s2取前j个，要从s1变成s2最少的代价是多少*/
        /*s1[i-1]参与变化:
            a.s1[i-1]变成s2[j-1]:
                1):s1[i-1]==s2[j-1] dp[i][j]=dp[i-1][j-1]
                2):s1[i-1]!=s2[j-1] dp[i][j]=dp[i-1][j-1]+c(替换)
            b.s1[i-1]不去变成s2[j-1] dp[i][j]=dp[i][j-1]+a(插入)
        s1[i-1]不参与变化 dp[i][j]=dp[i-1][j]+b(删除)*/
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)dp[i][0]=i*b;
        for(int j=1;j<=m;j++)dp[0][j]=j*a;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int p1=INT_MAX;
                //如果一样，没有代价即可达成
                if(s1[i-1]==s2[j-1])p1=dp[i-1][j-1];
                int p2=INT_MAX;
                //如果不一样需要一次替换代价
                if(s1[i-1]!=s2[j-1])p2=dp[i-1][j-1]+c;
                //如果s1[i-1]不去变成s2[j-1]那么就是s1[0...i-1]到s2[0....j-2]要对应上，并且加上一个插入代价(插入s2[j-1])
                int p3=dp[i][j-1]+a;
                //如果s1不参与变化那么就是s1[0....i-2]到s2[0....j-1]对应，并且删除s1[i-1]
                int p4=dp[i-1][j]+c;
                dp[i][j]=min(min(p1,p2),min(p3,p4));
            }
        }
        return dp[n][m];
    }
    /// @brief 空间压缩
    /// @param s1 
    /// @param s2 
    /// @param a 
    /// @param b 
    /// @param c 
    /// @return 
    int minDistance::LC72_minDistance_EC(string s1, string s2,int a,int b,int c){
        /*s1取前i个，s2取前j个，要从s1变成s2最少的代价是多少*/
        /*s1[i-1]参与变化:
            a.s1[i-1]变成s2[j-1]:
                1):s1[i-1]==s2[j-1] dp[i][j]=dp[i-1][j-1]
                2):s1[i-1]!=s2[j-1] dp[i][j]=dp[i-1][j-1]+c(替换)
            b.s1[i-1]不去变成s2[j-1] dp[i][j]=dp[i][j-1]+a(插入)
        s1[i-1]不参与变化 dp[i][j]=dp[i-1][j]+b(删除)*/
        int n=s1.size();
        int m=s2.size();
        vector<int>dp(m+1,0);
        for(int j=1;j<=m;j++)dp[j]=j*a;
        for(int i=1,leftUp,backUp;i<=n;i++){
            //每一行的0位置的值
            leftUp=(i-1)*b;
            dp[0]=i*b;
            for(int j=1;j<=m;j++){
                backUp=dp[j];
                //如果一样，没有代价即可达成
                if(s1[i-1]==s2[j-1])dp[j]=leftUp;
                //如果不一样需要一次替换代价
                //如果s1[i-1]不去变成s2[j-1]那么就是s1[0...i-1]到s2[0....j-2]要对应上，并且加上一个插入代价(插入s2[j-1])
                //如果s1不参与变化那么就是s1[0....i-2]到s2[0....j-1]对应，并且删除s1[i-1]
                else{
                    dp[j]=min(min(leftUp+c,dp[j-1]+a),dp[j]+c);
                }
                leftUp=backUp;
            }
        }
        return dp[m];
    }
    void minDistance::Test_LC72_minDistance(){
        string s1,s2;
        cout<<LC72_minDistance1(s1,s2,1,1,1)<<endl; 
    }
    
/***********************************************************************/ 
    /*LeetCode 97 交错字符串*/
    bool isInterleave::LC97_isInterleave(string s1, string s2, string s3){
        /*s1.length()+s2.length()!=s3.length();return false;
        s1[前i个]与s2[前j个]能不能交错组成s3[前i+j个]
        如果s1[i-1]==s3[i+j-1]--->s1[0....i-2] 与 s2[0....j-1]交错组成的s3[0....i+j-2]即dp[i-1][j]*/
        if(s1.length()+s2.length()!=s3.length())return false;
        int n=s1.length(),m=s2.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        //当s2取前0个字符s1取前1个，前2个...前n个字符时能不能对应到s3前1个，前2个...前n个
        for(int i=1;i<=n;i++)if(s1[i-1]!=s3[i-1])break;else dp[i][0]=true;
        //当s1取前0个字符s2取前1个，前2个...前m个字符时能不能对应到s3前1个，前2个...前m个
        for(int j=1;j<=m;j++)if(s2[j-1]!=s3[j-1])break;else dp[0][j]=true;
        //当s1取前1个、前2个...前n个，s2取前1个、前2个...前m个，能不能对应s3取前2个、前4个...前n+m个
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //如果s1的第i-1位置的字符等于s3第i+j-1位置的字符并且，s1取[0....i-2]与s2取[0...j-1]可以对应s3[0....i+j-2]
                //或者，如果s2的第j-1位置的字符等于s3第i+j-1位置的字符并且，s2取[0....j-2]与s1取[0...i-1]可以对应s3[0....i+j-2]
                //那么说明，s1取[0....i-1]与s2取[0...j-1]可以对应s3[0....i+j-1]，即dp[i][j]=true;
                dp[i][j]=(s1[i-1]==s3[i+j-1]&&dp[i-1][j]||s2[j-1]==s3[i+j-1]&&dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    /// @brief 空间压缩
    /// @param s1 
    /// @param s2 
    /// @param s3 
    /// @return 
    bool isInterleave::LC97_isInterleave_EC(string s1, string s2, string s3){
        /*s1.length()+s2.length()!=s3.length();return false;
        s1[前i个]与s2[前j个]能不能交错组成s3[前i+j个]
        如果s1[i-1]==s3[i+j-1]--->s1[0....i-2] 与 s2[0....j-1]交错组成的s3[0....i+j-2]即dp[i-1][j]*/
        if(s1.length()+s2.length()!=s3.length())return false;
        int n=s1.length(),m=s2.length();
        vector<bool>dp(m+1,false);
        //当s1取前0个字符s2取前1个，前2个...前m个字符时能不能对应到s3前1个，前2个...前m个
        for(int j=1;j<=m;j++)if(s2[j-1]!=s3[j-1])break;else dp[j]=true;
        //当s1取前1个、前2个...前n个，s2取前1个、前2个...前m个，能不能对应s3取前2个、前4个...前n+m个

        dp[0]=true;
        for(int i=1;i<=n;i++){
            //当s2取前0个字符s1取前1个，前2个...前n个字符时能不能对应到s3前1个，前2个...前n个
            dp[0]=dp[0]&(s1[i-1]==s3[i-1]);
            for(int j=1;j<=m;j++){
                dp[j]=((s1[i-1]==s3[i+j-1]&&dp[j])||(s2[j-1]==s3[i+j-1]&&dp[j-1]));
            }
        }
        return dp[m];
    }
    void isInterleave::Test_LC97_isInterleave(){
        string s1,s2,s3;
        cout<<LC97_isInterleave_EC(s1,s2,s3)<<endl;
    }
/***********************************************************************/ 
    /*有效涂色问题*/
    int effectiveColoring::Ex_effectiveColoring(int n,int m){
        /*dp[i][j]:前i个格子，涂了j种颜色的方法数
        1.dp[i-1][j]*j
        2.dp[i-1][j-1]*(m-(j-1))*/
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)dp[i][1]=m;
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                //前面的格子的方法数*需要的颜色的个数
                dp[i][j]=(int)(((long long)dp[i-1][j]*j)%MOD);
                //再加上前面的格子数在颜色少一个的情况下*剩余的颜色
                dp[i][j]=(int)(((long long)dp[i-1][j-1]*(m-(j-1))+dp[i][j])%MOD);
            }
        }
        return dp[n][m];
    }
    void effectiveColoring::Test_Ex_effectiveColoring(){
        cout<<Ex_effectiveColoring(5000,4877)<<endl;
    }
/***********************************************************************/ 
    /*删除至少几个字符可以变成另一个字符串的子串*/
    int stringChanges::EX_stringChanges(string s1,string s2){
        int n=s1.length(),m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        /*s1[前缀长度为i]至少删掉多少字符，可以变成s2[前缀长度为j]的任意后缀串*/
        for(int i=1;i<=n;i++){
            dp[i][0]=i;
            for(int j=1;j<=m;j++){
                //相等就不用删除当前位置的字符，看之前至少删除了多少个字符
                if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];
                //不相等就需要删除当前字符，再看之前删掉多少字符能与[0...j]的后缀串匹配
                else dp[i][j]=dp[i-1][j]+1;
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<=m;j++)ans=min(ans,dp[n][j]);
        return ans;
    }
    void stringChanges::Test_EX_stringChanges(){
        string s1,s2;
        cout<<EX_stringChanges(s1,s2)<<endl;
    }
/***********************************************************************/ 
    /*LeetCode 2003 每颗子树内缺失的最小基因值*/
    vector<int> smallestMissingValueSubtree::LC2003_smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums){
        int n=parents.size();
        //优先设置缺失的最小基因值都为1
        vector<int>ans(n,1);
        //查询1是否是所有子树缺失的最小基因值
        auto it=find(nums.begin(),nums.end(),1);
        //如果没找到1，就说明缺失的最小基因值就是1，直接返回ans
        if(it==nums.end())return ans;

        //否则建树
        vector<vector<int>>g(n);
        for(int i=1;i<n;i++)g[parents[i]].push_back(i);
        unordered_set<int>set;
        //写dfs
        function<void(int)>dfs=[&](int x)->void{
            set.insert(nums[x]);
            for(int son:g[x]){
                if(!set.count(nums[son]))dfs(son);
            }
        };
        //枚举最小缺失基因
        int mex=2;
        int node=it-nums.begin();
        while(node>=0){
            dfs(node);
            while(set.count(mex))mex++;
            ans[node]=mex;
            node=parents[node];
        }
        return ans;  
        
    }
    void smallestMissingValueSubtree::Test_LC2003_smallestMissingValueSubtree(){
        vector<int>parents,nums;
        LC2003_smallestMissingValueSubtree(parents,nums);
    }
/***********************************************************************/ 
}
namespace DP_Three_dimensional{
/***********************************************************************/ 
    /*LeetCode 474 一和零*/
    int findMaxForm::LC474_findMaxForm1(vector<string>& strs, int m, int n){
        return LC474_findMaxForm1_f1(strs,0,m,n);
    }
    void findMaxForm::LC474_findMaxForm1_conts(string str){
        zeros=0;
        ones=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='0')zeros++;
            else ones++;
        }
    }
    //strs[i....]自由选择，希望0的数量不超过z，1的数量不超过o
    //最多能选出多少个字符串
    int findMaxForm::LC474_findMaxForm1_f1(vector<string>&strs,int i,int z,int o){
        if(i==strs.size())return 0;
        //不使用当前i位置的字符串
        int p1=LC474_findMaxForm1_f1(strs,i+1,z,o);
        //使用当前位置的字符串
        int p2=0;
        LC474_findMaxForm1_conts(strs[i]);
        if(zeros<=z&&ones<=o)p2=1+LC474_findMaxForm1_f1(strs,i+1,z-zeros,o-ones);
        return max(p1,p2);
    }
    /// @brief 记忆化搜索
    /// @param strs 
    /// @param m 
    /// @param n 
    /// @return 
    int findMaxForm::LC474_findMaxForm2(vector<string>& strs, int m, int n){
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return LC474_findMaxForm1_f2(strs,0,m,n,dp);
    }
    int findMaxForm::LC474_findMaxForm1_f2(vector<string>&strs,int i,int z,int o,vector<vector<vector<int>>>&dp){
        if(i==strs.size())return 0;
        if(dp[i][z][o]!=-1)return dp[i][z][o];
        //不使用当前i位置的字符串
        int p1=LC474_findMaxForm1_f2(strs,i+1,z,o,dp);
        //使用当前位置的字符串
        int p2=0;
        LC474_findMaxForm1_conts(strs[i]);
        if(zeros<=z&&ones<=o)p2=1+LC474_findMaxForm1_f2(strs,i+1,z-zeros,o-ones,dp);
        dp[i][z][o]=max(p1,p2);
        return dp[i][z][o]; 
    }
    /// @brief 严格位置依赖
    /// @param strs 
    /// @param m 
    /// @param n 
    /// @return 
    int findMaxForm::LC474_findMaxForm3(vector<string>& strs, int m, int n){
        int len=strs.size();
        vector<vector<vector<int>>>dp(len+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i=len-1;i>=0;i--){
            LC474_findMaxForm1_conts(strs[i]);
            for(int z=0,p1,p2;z<=m;z++){
                for(int o=0;o<=n;o++){
                    p1=dp[i+1][z][o];
                    p2=zeros<=z&&ones<=o?(1+dp[i+1][z-zeros][o-ones]):0;
                    dp[i][z][o]=max(p1,p2);
                }
            }
        }
        return dp[0][m][n];
    }
    /// @brief 优化
    /// @param strs 
    /// @param m 
    /// @param n 
    /// @return 
    int findMaxForm::LC474_findMaxForm4(vector<string>& strs, int m, int n){
        int len=strs.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(string s:strs){
            LC474_findMaxForm1_conts(s);
            for(int z=m;z>=zeros;z--){
                for(int o=n;o>=ones;o--){
                    dp[z][o]=max(dp[z][o],dp[z-zeros][o-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
    void findMaxForm::Test_LC474_findMaxForm(){
        vector<string>strs={"10","0001","111001","1","0"};
        cout<<LC474_findMaxForm3(strs,5,3);
    }
/***********************************************************************/ 
    /*LeetCode 879 盈利计划*/
    int profitableSchemes::LC879_profitableSchemes1(int n, int minProfit, vector<int>& group, vector<int>& profit){
        return LC879_profitableSchemes_f1(group,profit,0,n,minProfit);
    }
    /*i：来到第i号项目
    r:员工还有r个
    s：利润还有s才能达标，如果s<=0说明之前已经达标了
    返回：有多少种方案*/
    int profitableSchemes::LC879_profitableSchemes_f1(vector<int>&group,vector<int>&profit,int i,int r,int s){
        //人已经耗尽了
        if(r<=0)return s<=0?1:0;
        //工作已经没了
        if(i==group.size())return s<=0?1:0;
        //这项工作不做
        int p1=LC879_profitableSchemes_f1(group,profit,i+1,r,s);
        //这项工作做
        int p2=0;
        //剩余的人要满足做当前工作的人数
        if(group[i]<=r)p2=LC879_profitableSchemes_f1(group,profit,i+1,r-group[i],s-profit[i]);
        return (p1+p2)%MOD;
    }
    /// @brief 记忆化搜索
    /// @param n 
    /// @param minProfit 
    /// @param group 
    /// @param profit 
    /// @return 
    int profitableSchemes::LC879_profitableSchemes2(int n, int minProfit, vector<int>& group, vector<int>& profit){
        int m=group.size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(m+1,vector<int>(minProfit+1,-1)));
        return LC879_profitableSchemes_f2(group,profit,0,n,minProfit,dp);
    }
    /*i：来到第i号项目
    r:员工还有r个
    s：利润还有s才能达标，如果s<=0说明之前已经达标了
    返回：有多少种方案*/
    int profitableSchemes::LC879_profitableSchemes_f2(vector<int>&group,vector<int>&profit,int i,int r,int s,vector<vector<vector<int>>>&dp){
        //人已经耗尽了
        if(r<=0)return s<=0?1:0;
        //工作已经没了
        if(i==group.size())return s<=0?1:0;
        if(dp[i][r][s]!=-1)return dp[i][r][s];
        //这项工作不做
        int p1=LC879_profitableSchemes_f2(group,profit,i+1,r,s,dp);
        //这项工作做
        int p2=0;
        //剩余的人要满足做当前工作的人数
        if(group[i]<=r)p2=LC879_profitableSchemes_f2(group,profit,i+1,r-group[i],max(0,s-profit[i]),dp);
        dp[i][r][s]=(p1+p2)%MOD;
        return dp[i][r][s];
    }
    /// @brief 严格位置依赖
    /// @param n 
    /// @param minProfit 
    /// @param group 
    /// @param profit 
    /// @return 
    int profitableSchemes::LC879_profitableSchemes3(int n, int minProfit, vector<int>& group, vector<int>& profit){
        int m=group.size();
        vector<vector<int>>dp(n+1,vector<int>(minProfit+1,0));
        //没有工作的时候,即i是最高层
        for(int r=0;r<=n;r++)dp[r][0]=1;
        for(int i=m-1;i>=0;i--){
            for(int r=n;r>=0;r--){
                for(int s=minProfit;s>=0;s--){
                    int p1=dp[r][s];
                    int p2=group[i]<=r?dp[r-group[i]][max(0,s-profit[i])]:0;
                    dp[r][s]=(p1+p2)%MOD;
                }
            }
        }
        return dp[n][minProfit];
    }
    void profitableSchemes::Test_LC879_profitableSchemes(){
        vector<int>group,profit;
        cout<<LC879_profitableSchemes3(10,10,group,profit)<<endl;
    }
/***********************************************************************/ 
    /*LeetCode 688 骑士在棋盘上的概率*/
    double knightProbability::LC688_knightProbability1(int n, int k, int row, int column){
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1)));
        return LC688_knightProbability1_f1(n,row,column,k,dp);
    }
    double knightProbability::LC688_knightProbability1_f1(int n, int i,int j,int k,vector<vector<vector<double>>>&dp){
        if(i<0||i>=n||j<0||j>=n)return 0;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        double ans=0;
        if(k==0)ans=1;
        else{
            ans+=(LC688_knightProbability1_f1(n,i-2,j-1,k-1,dp)/8);
            ans+=(LC688_knightProbability1_f1(n,i-2,j+1,k-1,dp)/8);
            
            ans+=(LC688_knightProbability1_f1(n,i-1,j-2,k-1,dp)/8);
            ans+=(LC688_knightProbability1_f1(n,i-1,j+2,k-1,dp)/8);

            
            ans+=(LC688_knightProbability1_f1(n,i+2,j-1,k-1,dp)/8);
            ans+=(LC688_knightProbability1_f1(n,i+2,j+1,k-1,dp)/8);

            ans+=(LC688_knightProbability1_f1(n,i+1,j-2,k-1,dp)/8);
            ans+=(LC688_knightProbability1_f1(n,i+1,j+2,k-1,dp)/8);
        }
        dp[i][j][k]=ans;
        return ans;
    }
    void knightProbability::Test_LC688_knightProbability(){
        cout<<LC688_knightProbability1(3,2,0,0)<<endl;
    }
/***********************************************************************/ 
    /*LeetCode 2435 矩阵中和能被k整除的路径*/
    int numberOfPaths::LC2435_numberOfPaths(vector<vector<int>>& grid, int k){
        int n=grid.size();
        int m=grid[0].size();
        return LC2435_numberOfPaths_f1(grid,n,m,k,0,0,0);
    }
    /*当前来到(i,j)位置，最终一定要走到右下角，从(i,j)到有多少条路径%k的结果余数是r*/
    int numberOfPaths::LC2435_numberOfPaths_f1(vector<vector<int>>&grid,int n,int m,int k,int i,int j,int r){
        if(i==n-1&&j==m-1)return grid[i][j]%k==r?1:0;

        int need=(k+r-(grid[i][j]%k))%k;
        int ans=0;
        //往下面走
        if(i+1<n)ans=LC2435_numberOfPaths_f1(grid,n,m,k,i+1,j,need);
        //往右边走
        if(j+1<m)ans=(ans+LC2435_numberOfPaths_f1(grid,n,m,k,i,j+1,need))%MOD;
        return ans;
    }
    /// @brief 记忆化搜索
    /// @param grid 
    /// @param k 
    /// @return 
    int numberOfPaths::LC2435_numberOfPaths2(vector<vector<int>>& grid, int k){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return LC2435_numberOfPaths_f1(grid,n,m,k,0,0,0);
    }
    /*当前来到(i,j)位置，最终一定要走到右下角，从(i,j)到有多少条路径%k的结果余数是r*/
    int numberOfPaths::LC2435_numberOfPaths_f2(vector<vector<int>>&grid,int n,int m,int k,int i,int j,int r,vector<vector<vector<int>>>&dp){
        if(i==n-1&&j==m-1)return grid[i][j]%k==r?1:0;
        if(dp[i][j][r]!=-1)return dp[i][j][r];
        int need=(k+r-(grid[i][j]%k))%k;
        int ans=0;
        //往下面走
        if(i+1<n)ans=LC2435_numberOfPaths_f2(grid,n,m,k,i+1,j,need,dp);
        //往右边走
        if(j+1<m)ans=(ans+LC2435_numberOfPaths_f2(grid,n,m,k,i,j+1,need,dp))%MOD;
        dp[i][j][r]=ans;
        return ans;
    }
    /// @brief 严格位置依赖
    /// @param grid 
    /// @param k 
    /// @return 
    int numberOfPaths::LC2435_numberOfPaths3(vector<vector<int>>& grid, int k){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k,0)));
        dp[n-1][m-1][grid[n-1][m-1]%k]=1;
        for(int i=n-2;i>=0;i--){
            for(int r=0;r<k;r++){
                dp[i][m-1][r]=dp[i+1][m-1][(k+r-grid[i][m-1]%k)%k];
            }
        }
        for(int j=m-2;j>=0;j--){
            for(int r=0;r<k;r++){
                dp[n-1][j][r]=dp[n-1][j+1][(k+r-grid[n-1][j]%k)%k];
            }
        }
        for(int i=n-2,need;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                for(int r=0;r<k;r++){
                    need=(k+r-grid[i][j]%k)%k;
                    dp[i][j][r]=dp[i+1][j][need];
                    dp[i][j][r]=(dp[i][j][r]+dp[i][j+1][need])%MOD;
                }
            }
        }
        return dp[0][0][0];
    }
    void numberOfPaths::Test_LC2435_numberOfPaths(){
        vector<vector<int>>grid;
        cout<<LC2435_numberOfPaths3(grid,10)<<endl;
    }
/***********************************************************************/ 
    /*LeetCode 87 扰乱字符串*/
    bool isScramble::LC87_isScramble(string s1, string s2){
        int n=s1.length();
        return LC87_isScramble_f1(s1,0,n-1,s2,0,n-1);
    }
    /*s1[l1...r1]
    s2[l2...r2]
    保证l1...r1与l2...r2等长
    是不是扰乱串关系*/
    bool isScramble::LC87_isScramble_f1(string&s1,int l1,int r1,string&s2,int l2,int r2){
        //s1只剩一个字符了，也就是s2也只剩一个字符了
        if(l1==r1)return s1[l1]==s2[l2];
        //s1[l1..i][i+1...r1]
        //s2[l2..j][j+1...r2]
        for(int i=l1,j=l2;i<r1;i++,j++){
            //不交错谈论扰乱关系
            if(LC87_isScramble_f1(s1,l1,i,s2,l2,j)&&LC87_isScramble_f1(s1,i+1,r1,s2,j+1,r2))return true;
        }
        //s1[l1..i][i+1...r1]
        //s2[j..r2][l2...j-1]
        for(int i=l1,j=r2;i<r1;i++,j--){
            //交错讨论扰乱关系
            if(LC87_isScramble_f1(s1,l1,i,s2,j,r2)&&LC87_isScramble_f1(s1,i+1,r1,s2,l2,j-1))return true;
        }
        return false;
    }
    /// @brief 记忆化搜索
    /// @param s1 
    /// @param s2 
    /// @return 
    bool isScramble::LC87_isScramble2(string s1, string s2){
        int n=s1.length();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n+1,0)));
        return LC87_isScramble_f2(s1,s2,0,0,n,dp);
    }
    /*s1[l1...r1]
    s2[l2...r2]
    保证l1...r1与l2...r2等长
    是不是扰乱串关系*/
    bool isScramble::LC87_isScramble_f2(string&s1,string&s2,int l1,int l2,int len,vector<vector<vector<int>>>&dp){
        //s1只剩一个字符了，也就是s2也只剩一个字符了
        if(len==1)return s1[l1]==s2[l2];
        if(dp[l1][l2][len]!=0)return dp[l1][l2][len]==1;
        //s1[l1...] len个
        //s2[l2...] len个
        //左：k个   右：len-k个
        bool ans=false;
        for(int k=1;k<len;k++){
            if(LC87_isScramble_f2(s1,s2,l1,l2,k,dp)&&LC87_isScramble_f2(s1,s2,l1+k,l2+k,len-k,dp)){
                ans=true;
                break;
            }
        }
        if(!ans){
            //s1[l1..i][i+1...r1]
            //s2[j..r2][l2...j-1]
            for(int i=l1+1,j=l2+len-1,k=1;k<len;i++,j--,k++){
                //交错讨论扰乱关系
                if(LC87_isScramble_f2(s1,s2,l1,j,k,dp)&&LC87_isScramble_f2(s1,s2,i,l2,len-k,dp)){
                    ans=true;
                    break;
                }
            }
        }
        dp[l1][l2][len]=ans?1:-1;
        return ans;
    }
    bool isScramble::LC87_isScramble3(string s1, string s2){
        int n=s1.length();
        vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(n,vector<bool>(n+1,0)));
        for(int l1=0;l1<n;l1++){
            for(int l2=0;l2<n;l2++){
                dp[l1][l2][1]=s1[l1]==s2[l2];
            }
        }
        for(int len=2;len<=n;len++){
            //边界条件：l1<=n-len   l2<=n-len
            for(int l1=0;l1<=n-len;l1++){
                for(int l2=0;l2<=n-len;l2++){
                    //不交错
                    for(int k=1;k<len;k++){
                        if(dp[l1][l2][k]&&dp[l1+k][l2+k][len-k]){
                            dp[l1][l2][len]=true;
                            break;
                        }
                    }
                    //交错
                    if(!dp[l1][l2][len]){
                        for(int i=l1+1,j=l2+len-1,k=1;k<len;i++,j--,k++){
                            if(dp[l1][j][k]&&dp[i][l2][len-k]){
                                dp[l1][l2][len]=true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
    void isScramble::Test_LC87_isScramble(){
        string s1,s2;
        cout<<LC87_isScramble3(s1,s2)<<endl;
    }
/***********************************************************************/ 
}
//子数组最大累加和问题
namespace TheNumberOfMaxSubArray{
/***********************************************************************/
    /*LeetCoed 53 子数组最大和*/
    int maxsubArray::LC53_maxsubArray1(vector<int>&nums){
        //以i结尾的数的最大累加和是多少
        vector<int>dp(nums.size());
        int result=nums[0];
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            result=max(result,dp[i]);
        }
        return result;
    }
    int maxsubArray::LC53_maxsubArray2(vector<int>&nums){
        int dp=nums[0];
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            dp=max(dp,0)+nums[i];
            result=max(result,dp);
        }
        return result;
    }
    vector<int> maxsubArray::LC53_maxsubArray_EX(vector<int>&nums){
        int left,right,sum=INT_MIN;
        for(int l=0,r=1,pre=nums[0];r<nums.size();r++){
            //如果前面的累加和大于0，那么就继续加上当前位置的数
            if(pre>=0)pre+=nums[r];
            else{
                //否则从当前位置的数重新开始累加
                pre=nums[r];
                l=r;
            }
            //如果最大累加和可以被更新，就更新最大累加和与区间
            if(pre>sum){
                sum=pre;
                left=l;
                right=r;
            }
        }
        return {left,right,sum};
    }
    int maxsubArray::LC918_maxsubArray3(vector<int>&nums){
        //case 1:最大累加和是连续的，说明取maxsum即可
        //case 2:最大累加和是不连续的，说明取all-minsum即可
        //长度、总体的累加和、最大的累加和、最小的累加和
        int n=nums.size(),all=nums[0],maxsum=nums[0],minsum=nums[0];
        for(int i=1,maxpre=nums[0],minpre=nums[0];i<n;i++){
            all+=nums[i];
            maxpre=max(nums[i],nums[i]+maxpre);
            maxsum=max(maxsum,maxpre);
            minpre=min(nums[i],nums[i]+minpre);
            minsum=min(minsum,minpre);
        }
        //如果最小的累加和就是总累加和，说明没有为正数的最大累加和，此值取为负数的最大值即可
        return all==minsum?maxsum:max(maxsum,all-minsum);
    }
    void maxsubArray::Test_LC53_maxsubArray(){
        vector<int>nums;
        cout<<LC53_maxsubArray2(nums)<<endl;
    }
/***********************************************************************/
    /*LeetCode 198 打家劫舍*/
    int Rob::LC198_rob(vector<int>&nums){
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        //在[0...i]上的最大累加和（相邻不可选）
        vector<int>dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],max(nums[i],dp[i-2]+nums[i]));
        }
        return dp[n-1];
    }
    int Rob::LC198_rob2(vector<int>&nums){
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        //在[0...i]上的最大累加和（相邻不可选）
        int prepre=nums[0];
        int pre=max(nums[0],nums[1]);
        for(int i=2,cur;i<n;i++){
            cur=max(pre,max(prepre+nums[i],nums[i]));
            prepre=pre;
            pre=cur;
        }
        return pre;
    }
    int Rob::LC213_rob(vector<int>&nums){
        int n=nums.size();
        if(n==1)return nums[0];

        //从nums里从l开始偷到r[l...r]内（在不能偷相邻的情况下，最多偷到的数量）
        function<int(int,int)>best=[&](int l,int r)->int{
            if(l>r)return 0;
            if(l==r)return nums[l];
            if(l+1==r)return max(nums[l],nums[r]);
            int prepre=nums[l];
            int pre=nums[l+1];
            for(int i=l+2,cur;i<=r;i++){
                cur=max(pre,nums[i]+max(0,prepre));
                prepre=pre;
                pre=cur;
            }
            return pre;
        };
        //第1种情况：不偷第0个，那么最多能偷到[1...n-1]
        //第2种情况：偷第0个，那么做多偷到nums[0]+[2....n-2]
        return max(best(1,n-1),nums[0]+best(2,n-2));
    }
    int Rob::LC2560_rob(vector<int>&nums,int k){
          int n=nums.size(),l=nums[0],r=nums[0];
          for(int i=1;i<n;i++){
            l=min(l,nums[i]);
            r=max(r,nums[i]);
          }
          int m,ans=0;
          while(l<=r){
            m=(l+r)/2;
            //动态规划
            function<int(int)>mostRob1=[&nums,n](int ability)->int{
                //能力值够了就能偷，不够就偷不了
                if(n==1)return nums[0]<=ability?1:0;
                //只要有一个能偷的就偷，（因为相邻的不能偷）
                if(n==2)return (nums[0]<=ability||nums[1]<=ability)?1:0;
                vector<int>dp(n);
                dp[0]=nums[0]<=ability?1:0;
                dp[1]=(nums[0]<=ability||nums[1]<=ability)?1:0;
                for(int i=2;i<n;i++){
                    dp[i]=max(dp[i-1],(nums[i]<=ability?1:0)+dp[i-2]);
                }
                return dp[n-1];
            };
            //空间压缩
            function<int(int)>mostRob2=[&nums,n](int ability)->int{
                if(n==1)return nums[0]<=ability?1:0;
                if(n==2)return (nums[0]<=ability||nums[1]<=ability)?1:0;
                int prepre=nums[0]<=ability?1:0;
                int pre=(nums[0]<=ability||nums[1]<=ability)?1:0;
                for(int i=2,cur;i<n;i++){
                    cur=max(pre,(nums[i]<=ability?1:0)+prepre);
                    prepre=pre;
                    pre=cur;
                }
                return pre;
            };
            //贪心(能偷就偷)
            function<int(int)>mostRob3=[&nums,n](int ability)->int{
                int ans=0;
                for(int i=0;i<n;i++){
                    if(nums[i]<=ability){
                        ans++;
                        //偷完了跳过下一个
                        i++;
                    }
                }
                return ans;
            };
            if(mostRob1(m)>=k){
                ans=m;
                r=m-1;
            }else l=m+1;
          }
          return ans;
    }
    void Rob::Test_LC198_rob(){
        vector<int>nums;
        cout<<LC198_rob(nums)<<endl;
    }
/***********************************************************************/
    vector<int> getMaxMatrix::MS1724_getMaxMatrix(vector<vector<int>>& grid){
        //包含第0行到第0行，且仅包含第0行到第0行的子矩阵的最大累加和
        //包含第0行到第1行，且仅包含第0行到第1行的子矩阵的最大累加和
        //包含第0行到第i行，且仅包含第0行到第i行的子矩阵的最大累加和
        int n=grid.size();
        int m=grid[0].size();
        int Max=INT_MIN;
        //最大累加和的左上和右下的索引
        int a=0,b=0,c=0,d=0;
        vector<int>nums(m,0);
        //从第一行开始0-0 1-1 2-2等等
        for(int up=0;up<n;up++){
            //重新初始化nums数组
            fill(nums.begin(),nums.end(),0);
            //从每一行开始遍历 0-1 0-2 0-3等等
            for(int down=up;down<n;down++){
                //对每个压缩数组求最大累加和，并且更新左上和右下的索引
                for(int l=0,r=0,pre=INT_MIN;r<m;r++){
                    //压缩子数组
                    nums[r]+=grid[down][r];
                    if(pre>=0)pre+=nums[r];
                    else{
                        pre=nums[r];
                        l=r;
                    }
                    if(pre>Max){
                        Max=pre;
                        a=up;
                        b=l;
                        c=down;
                        d=r;
                    }
                }
            }
        }
        return {a,b,c,d};
    }
    void getMaxMatrix::Test_MS1724_getMaxMatrix(){
        vector<vector<int>>mat;
        for(int n:MS1724_getMaxMatrix(mat))cout<<n<<" ";
        cout<<endl;
    }
/***********************************************************************/
    /*子数组最大乘积*/
    int maxProduct::LC152_maxProduct(vector<int> &nums){
        //以i结尾的情况下最小的累乘积
        //以i结尾的情况下最大的累乘积
        //case 1: [i]   case 2: maxdp[i]*[i]    case 3:min[i-1]*[i]
        int ans=nums[0];
        //i:当前位置的索引，mindp前一个位置的最小累乘积mindp[i-1]，maxdp前一个位置的最大累乘积maxdp[i-1]
        //curmin:当前位置的最小累乘积   curmax:当前位置的最大累乘积
        for(int i=1,mindp=nums[0],maxdp=nums[0],curmin,curmax;i<nums.size();i++){
            //取最小累乘的：case 1: nums[i]   case 2: mindp[i-1]*nums[i]    case 3:maxdp[i-1]*nums[i]
            curmin=min(nums[i],min(mindp*nums[i],maxdp*nums[i]));
            //取最大累乘的：case 1: nums[i]   case 2: maxdp[i-1]*nums[i]    case 3:mindp[i-1]*nums[i]
            curmax=max(nums[i],max(maxdp*nums[i],mindp*nums[i]));
            mindp=curmin;
            maxdp=curmax;
            ans=max(ans,maxdp);
        }
        return ans;
    }

    void maxProduct::Test_LC152_maxProduct(){
        vector<int>nums;
        cout<<LC152_maxProduct(nums)<<endl;
    }
/***********************************************************************/
    int MaxProSub::maxSum1(vector<int> &nums){
        return maxSum1_f(nums,0,0);
    }
    int MaxProSub::maxSum1_f(vector<int> &nums, int i, int s){
        if(i==nums.size())return s%7==0?s:0;
        //当前位置的数要，与当前位置的数不要
        return max(maxSum1_f(nums,i+1,s),maxSum1_f(nums,i+1,s+nums[i]));
    }
    int MaxProSub::maxSum2(vector<int> &nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(7));
        //在数组中前0个数组成的累加和%7的余数是0的累加和为0
        dp[0][0]=0;
        //在数组中前1,2,3,4个数组成的累加和%7的余数是0的累加和不存在
        for(int j=1;j<7;j++)dp[0][j]=-1;
        for(int i=1,x,cur,need;i<=n;i++){
            //当前的数
            x=nums[i-1];
            //当前的余数
            cur=nums[i-1]%7;
            for(int j=0;j<7;j++){
                dp[i][j]=dp[i-1][j];
                //需要的余数
                need=cur<=j?(j-cur):(j-cur+7);
                if(dp[i-1][need]!=-1)dp[i][j]=max(dp[i][j],dp[i-1][need]+x);
            }
        }
        return dp[n][0];
    }
    int MagicReel::maxSum1(vector<int> &nums)
    {
        int n=nums.size();
        //不使用卷轴
        int p1=0;
        for(int num:nums)p1+=num;
        //只使用一次卷轴
        int p2=maxSum1_f1(nums,0,n-1);
        //使用两次卷轴
        int p3=INT_MIN;
        for(int i=1;i<n;i++)p3=max(maxSum1_f1(nums,0,i-1),maxSum1_f1(nums,i,n-1));
        return max(p1,max(p2,p3));
    }
    int MagicReel::maxSum1_f1(vector<int> &nums, int l, int r)
    {
        int ans=INT_MIN;
        //l...r范围上包含a...b
        //如果a...b范围内的数字都变成0
        //返回剩下数字的累加和
        //枚举所有可能的a...b范围
        for(int a=l;a<=r;a++){
            for(int b=a;b<=r;b++){
                int curAns=0;
                //只有l位置的数字变成0.....只有r位置的数字变成0 
                for(int i=l;i<a;i++){
                    curAns+=nums[i];
                }
                for(int i=b+1;i<=r;i++){
                    curAns+=nums[i];
                }
                ans=max(ans,curAns);
            }
        }
        return ans;
    }
    /***********************************************************************/
    int MagicReel::maxSum2(vector<int> &nums)
    {
        int n=nums.size();
        //情况1：完全不使用卷轴
        int p1=0;
        for(int num:nums)p1+=num;

        //prefix[i]:0~i范围上一定要使用一次卷轴的情况下，0~i范围整体最大累加和是多大
        vector<int>prefix(n);
        //每一步的前缀和
        int sum=nums[0];
        //每一步前缀和的最大值
        int maxpresum=max(0,sum);
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1]+nums[i],maxpresum);
            sum+=nums[i];
            maxpresum=max(maxpresum,sum);
        }
        //情况2：必须使用一次卷轴
        int p2=prefix[n-1];

        //suffix[i]:在i~n-1范围上一定用一次卷轴的情况下最大累加和为多少
        vector<int>suffix(n);
        sum=nums[0];
        maxpresum=max(0,sum);
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1]+nums[i],maxpresum);
            sum+=nums[i];
            maxpresum=max(maxpresum,sum);
        }
        //情况3：使用两次卷轴
        int p3=INT_MIN;
        for(int i=1;i<n;i++){
            //0~i-1左
            //i~n-1右
            p3=max(p3,prefix[i-1]+suffix[i]);
        }
        return max(p1,max(p2,p3));
    }
/***********************************************************************/
    vector<int> maxSumOfThreeSubarrays::LC689_maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        //sums[i]:从i开始到k长度的累加和
        int n=nums.size();
        vector<int>sums(n);
        for(int l=0,r=0,sum=0;r<n;r++){
            sum+=nums[r];
            if(r-l+1==k){
                sums[l]=sum;
                sum-=nums[l];
                l++;
            }
        }
        //prefix[i]:0~i范围上，长度为k子数组中,拥有最大累加和的子数组是以什么位置开头的
        vector<int>prefix(n,0);
        /*k=3
        pre[0]:0...0凑不够k个
        pre[1]:0...1凑不够k个
        pre[2]=0:0...2只有一个
        pre[3]=pre[i-1],当前情况可以进行pk了*/
        for(int l=1,r=k;r<n;l++,r++){
            if(sums[l]>sums[prefix[r-1]])prefix[r]=l;
            else prefix[r]=prefix[r-1];
        }
        //suffix[i]:i~n-1范围上，长度为k子数组中,拥有最大累加和的子数组是以什么位置开头的
        vector<int>suffix(n,0);
        suffix[n-k]=n-k;
        for(int l=n-k-1;l>=0;l--){
            //维持字典序最小，如果等于也更新
            if(sums[l]>=sums[suffix[l+1]])suffix[l]=l;
            else suffix[l]=suffix[l+1];
        }
        //0...i-1   i....j  j+1...n-1
        //左        中      右
        int a=0,b=0,c=0,Max=0;
        //维护i...j永远是k长度
        for(int p,s,i=k,j=2*k-1,sum;j<n-k;i++,j++){
            //0...i-1       i....j      j+1...n-1
            //最好开头p     i开头       最好开头s
            p=prefix[i-1];
            s=suffix[j+1];
            sum=sums[p]+sums[i]+sums[s];
            if(sum>Max){
                Max=sum;
                a=p;
                b=i;
                c=s;
            }
        }
        return {a,b,c};
    }
    void maxSumOfThreeSubarrays::Test_LC689_maxSumOfThreeSubarrays()
    {
    }
/***********************************************************************/
    int ReverseArraySubarrayMaxSum::maxSumReverse1(vector<int> &nums)
    {
        int ans=INT_MIN;
        for(int l=0;l<nums.size();l++){
            for(int r=l;r<nums.size();r++){
                reverse(nums.begin()+l,nums.begin()+r);
                ans=max(ans,maxSumReverse1_maxSum(nums));
                reverse(nums.begin()+l,nums.begin()+r);
            }
        }
        return ans;
    }
    int ReverseArraySubarrayMaxSum::maxSumReverse1_maxSum(vector<int> &nums)
    {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=1,pre=nums[0];i<n;i++){
            pre=max(nums[i],nums[i]+pre);
            ans=max(ans,pre);
        }
        return ans;
    }
    int ReverseArraySubarrayMaxSum::maxSumReverse2(vector<int> &nums)
    {
        int n=nums.size();
        //start[i]以i做开头的最大累加和
        vector<int>start(n);
        start[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            start[i]=nums[i]+max(0,start[i+1]);
        }
        int ans=start[0];
        //子数组必须以i-1结尾，其中的最大累加和
        int end=nums[0];
        //MaxEnd:
        //0~i范围上
        //子数组必须以0结尾，其中最大累加和
        //子数组必须以1结尾，其中最大累加和
        //子数组必须以2结尾，其中最大累加和
        //...
        //子数组必须以i结尾，其中最大累加和
        //所有情况中，最大的那个累加和就是maxEnd
        int maxEnd=nums[0];
        for(int i=1;i<n;i++){
            ans=max(ans,maxEnd+start[i]);
            end=nums[i]+max(0,end);
            maxEnd=max(maxEnd,end);
        }
        //不用任何翻转
        ans=max(ans,maxEnd);
        return ans;
    }
/***********************************************************************/
    int DeleteOneNumberLengthKMaxSum::MaxSum1(vector<int> &nums, int k)
    {
        int n=nums.size();
        if(n<=k)return 0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            //删除第i位置的数
            vector<int>rest=nums;
            rest.erase(rest.begin()+i);
            //找到长度为k的最大累加和子数组
            ans=max(ans,MaxSum1_lenKmaxSum(rest,k));
        }
        return ans;
    }
    int DeleteOneNumberLengthKMaxSum::MaxSum1_lenKmaxSum(vector<int> &nums, int k)
    {   
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<=n-k;i++){
            int cur=0;
            for(int j=i,cnt=0;cnt<k;cnt++,j++)cur+=nums[j];
            ans=max(ans,cur);
        }
        return ans;
    }
    int DeleteOneNumberLengthKMaxSum::MaxSum2(vector<int> &nums, int k)
    {
        int n=nums.size();
        if(n<=k)return 0;
        vector<int>window(n);
        int l=0,r=0;
        long sum=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            //如果当前位置的数小于单调队列中最右边的值，就将最右边的值出堆
            while(l<r&&nums[window[r-1]]>=nums[i])r--;
            window[r++]=i;
            sum+=nums[i];
            if(i>=k){
                ans=max(ans,(int)(sum-nums[window[l]]));
                //单调队列：如果单调队列最左侧的位置过期了，从队列中弹出
                if(window[l]==i-k)l++;
                sum-=nums[i-k];
            }
        }
        return ans;
    }
/***********************************************************************/
}
namespace TheNumberOfArrayEX{
    int lengthOfLIS::LC300_lengthOfLIS1(vector<int> &nums)
    {
        int n=nums.size();
        vector<int>dp(n);
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;i++){
                dp[i]=nums[j]<nums[i]?max(dp[i],dp[j]+1):dp[i];
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }

    int lengthOfLIS::LC300_lengthOfLIS(vector<int> &nums)
    {
        //end[i]：目前所有长度为i+1的递增子序列的最小结尾
        int n=nums.size();
        vector<int>ends(n);
        int len=0;
        //用来寻找小于等于nums[i]的最左位置的数
        function<int(int)>bfs1=[&](int num)->int{
            int l=0,r=len-1,ans=-1;
            while(l<=r){
                int m=(l+r)/2;
                if(ends[m]>num){
                    ans=m;
                    r=m-1;
                }else l=m+1;
            }
            return ans;
        };
        for(int i=0,find;i<n;i++){
            find=bfs1(nums[i]);
            if(find==-1)ends[len++]=nums[i];
            else ends[find]=nums[i];
        }
        return len;
    }
    void lengthOfLIS::Test_LC300_lengthOfLIS()
    {
        vector<int>nums={10,9,2,5,3,7,101,18};
        cout<<LC300_lengthOfLIS(nums)<<endl;
    }
}
namespace ZeroAndOneBackpackIssues{
/***********************************************************************/
    int BackPackTemplate::dpBackPack(int n,int m, vector<int> &cost, vector<int> &val)
    {
        //dp[i][j]: 1.....i个物品自由选择，在容量不超过j的情况况下，能选择的物品的最大总价值数
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i-1][j];
                if(cost[i]<=j)dp[i][j]=max(dp[i][j],dp[i-1][j-cost[i]]+val[i]);
            }
        }

        return dp[n][m];
    }
    int BackPackTemplate::dpBackPack2(int n, int m, vector<int> &cost, vector<int> &val)
    {
        vector<int>dp(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=m;j>=cost[i];j--){
                dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
            }
        }
        return dp[m];
    }
/***********************************************************************/
    int lastStoneWeightII::LC1049_lastStoneWeightII(vector<int> &nums)
    {
        /*将nums分成两个集合，求这两个集合各自的和相减尽量接近0
        也就是从nums中选择一些数，使得这些数的和接近nums数组总和sum的一半*/

        //先求和的一半
        int sum=0;
        for(int num:nums)sum+=num;
        int target=sum/2;
        /*dp[i][j]:表示在前0....i个数中选择子序列，使其子序列的和不超过target,且尽量大*/
        /*1)：不选第i个数，那么dp[i][j]=dp[i-1][j]
        2)：选第i个数，那么就要求0....i-1个子序列中的选择中其和不能超过j-nums[i]的情况下在加上nums[i]，即dp[i][j]=dp[i-1][j-nums[i]]+nums[i]*/
        /*空间压缩*/
        vector<int>dp(target+1,0);
        //dp[0](dp[0][0]):表示没有石头时子序列和为0的最大子序列和，即0
        for(int num:nums){
            for(int j=target;j>=num;j--){
                dp[j]=max(dp[j],dp[j-num]+num);
            }
        }
        //返回两个集合相减的值
        return sum-dp[target]-dp[target];
    }
/***********************************************************************/
    vector<int>TopSum::EX_TopSum3(vector<int> &nums,int k)
    {
        //先排序
        sort(nums.begin(),nums.end());
        //创建小根堆
        auto cmp=[](vector<int>&a,vector<int>&b)->bool{
            return a[1]>b[1];
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
        pq.push({0,nums[0]});
        vector<int>ans(k,0);
        for(int i=1;i<k;i++){
            vector<int>cur=pq.top();
            pq.pop();
            int right=cur[0];
            int sum=cur[1];
            ans[i]=sum;
            if(right+1<nums.size()){
                pq.push({right+1,sum-nums[right]+nums[right+1]});
                pq.push({right+1,sum+nums[right+1]});
            }
        }
        return ans;
    }

    int minInsertions::LC1312_minInsertions(string s)
    {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f2(s,0,n-1,dp);
    }

    int minInsertions::f2(string s, int l, int r, vector<vector<int>> &dp)
    {
        
        int ans;
        if(l==r) return dp[l][r]=0;
        if(l+1==r)return dp[l][r]=s[l]==s[l+1]?0:1;
        if(dp[l][r]!=-1)return dp[l][r];
        if(s[l]==s[r])ans=f2(s,l+1,r-1,dp);
        else ans=1+min(f2(s,l,r-1,dp),f2(s,l+1,r,dp));
        dp[l][r]=ans;
        return ans;
    }
    void minInsertions::Test_LC1312_minInsertions()
    {
        string s="zzazz";
        cout<<LC1312_minInsertions(s)<<endl;
    }
    int countPalindromicSubsequences::LC730_countPalindromicSubsequences(string s){
        const int mod=1000000007;
        using ll=long long;
        int n=s.size();
        vector<int>last(256,-1);
        //建立从左往右的索引
        vector<int>left(n);
        for(int i=0;i<n;i++){
            left[i]=last[s[i]];
            last[s[i]]=i;
        }
        last=vector<int>(256,-1);
        //建立从右往左的索引
        vector<int>right(n);
        for(int i=n-1;i>=0;i--){
            right[i]=last[s[i]];
            last[s[i]]=i;
        }
        vector<vector<ll>>dp(n,vector<ll>(n,0));
        //初始化对角线
        for(int i=0;i<n;i++)dp[i][i]=1;
        //
        for(int i=n-2,l,r;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]!=s[j])dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+mod;
                else{
                    l=right[i];
                    r=left[j];
                    if(l>r)dp[i][j]=dp[i+1][j-1]*2+2;
                    else if(l==r)dp[i][j]=dp[i+1][j-1]*2+1;
                    else dp[i][j]=dp[i+1][j-1]*2-dp[l+1][r-1]+mod;
                }
                dp[i][j]%=mod;
            }
        }
        return (int)dp[0][n-1];
    }
    void countPalindromicSubsequences::Test_LC730_countPalindromicSubsequences(){
        string s="abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
        cout<<LC730_countPalindromicSubsequences(s)<<endl;
    }
}
namespace TheTreeDP{
    int MaxBSTSize::LC_MaxBSTSize(TreeNode* head){
        return f2(head).second[0];
    }
    pair<bool,vector<long long>>MaxBSTSize::f(TreeNode* Node){
        //pair<是否为二叉搜索树，<二叉搜索树最大的大小，子树中的最小值，子树中的最大值>>
        if(Node==nullptr)return pair<bool,vector<long long>>({true,{0,LONG_LONG_MAX,LONG_LONG_MIN}});
        pair<bool,vector<long long>>treel=f(Node->left);
        pair<bool,vector<long long>>treer=f(Node->right);

        long long Min=min((long long)Node->val,min(treel.second[1],treer.second[1]));
        long long Max=max((long long)Node->val,max(treel.second[2],treer.second[2]));
        bool isT=treel.first&&treer.first&&treel.second[2]<Node->val&&Node->val<treer.second[1];
        int maxSize;
        if(isT)maxSize=treel.second[0]+treer.second[0]+1;
        else maxSize=max(treel.second[0],treer.second[0]);
        return pair<bool,vector<long long>>({isT,{maxSize,Min,Max}});

    }
    pair<bool,vector<long long>>MaxBSTSize::f2(TreeNode* Node){
        //pair<是否为二叉搜索树，<二叉搜索树最大的和，子树中的最小值，子树中的最大值>>
        if(Node==nullptr)return pair<bool,vector<long long>>({true,{0,0,LONG_LONG_MAX,LONG_LONG_MIN}});
        pair<bool,vector<long long>>treel=f2(Node->left);
        pair<bool,vector<long long>>treer=f2(Node->right);

        long long Min=min((long long)Node->val,min(treel.second[2],treer.second[2]));
        long long Max=max((long long)Node->val,max(treel.second[3],treer.second[3]));
        bool isT=treel.first&&treer.first&&treel.second[3]<Node->val&&Node->val<treer.second[2];
        int Sum=treel.second[1]+treer.second[1]+Node->val;
        int MaxSum=max(treel.second[0],treer.second[0]);
        if(isT)MaxSum=max(MaxSum,Sum);
        return pair<bool,vector<long long>>({isT,{MaxSum,Sum,Min,Max}});

    }
    void MaxBSTSize::Test_LC_MaxBSTSize(){
        TreeNode* head=new TreeNode(8);
        head->left=new TreeNode(5);
        head->right=new TreeNode(9);
        head->left->left=new TreeNode(3);
        head->left->right=new TreeNode(7);
        head->left->left->left=new TreeNode(2);
        head->left->left->right=new TreeNode(4);
        head->left->right->left=new TreeNode(6);
        head->left->right->right=new TreeNode(1);

        cout<<LC_MaxBSTSize(head)<<endl;
    }
}

int main(){
auto statr= chrono::system_clock::now();


// cout<<INT_MAX<<endl<<LONG_MAX<<endl<<LONG_LONG_MAX<<endl;
// priority_queue<int,vector<int>,less<int>>que;
// int m=12;
// vector<vector<int>>envl={{5,4},{6,4},{6,7},{2,3}};
// sort(envl.begin(),envl.end(),[&](vector<int>&a,vector<int>b)->bool{
//     if(a[0]<b[0])return true;
//     else if(a[0]==b[0])return a[1]>b[1];
//     return false;
// });
// vector<int>nums={8,6,3,7,1,9,0,2};
// function<bool(vector<int>,vector<int>)>cmp=[&](vector<int>a,vector<int>b)->bool{
//     return a[1]>b[1];
// };
// priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>dp(cmp);
// dp.push({2,1});
// dp.push({3,0});
// dp.push({4,3});
// dp.push({7,8});
// int n=10;
// vector<vector<vector<int>>>dp(n,vector<vector<int>>(n));
// vector<int>ft={1,1};
// string s;
// cin>>s;
// cout<<s<<endl;
// cin.get();

/***********************************************************************/
    /*斐波那契数列*/
    {
        // using DP_One_dimensional::FibonacciNumber;

        // FibonacciNumber fib1;
        // fib1.Test_FibonacciNumber_fib1();


        // FibonacciNumber fib2;
        // fib2.Test_FibonacciNumber_fib2();

        // FibonacciNumber fib3;
        // fib3.Test_FibonacciNumber_fib3();


        // FibonacciNumber fib4;
        // fib4.Test_FibonacciNumber_fib4();
    }
/***********************************************************************/
    /*最低票价*/
    {
        // using DP_One_dimensional::mincostTickets;

        // mincostTickets mts1;
        // mts1.Test_LC983_mincostTickets1();

        // mincostTickets mts2;
        // mts2.Test_LC983_mincostTickets2();

        // mincostTickets mts3;
        // mts3.Test_LC983_mincostTickets3();
    }
/***********************************************************************/
    /*解码方法*/
    {
        // using DP_One_dimensional::numDecodings;

        // numDecodings nds1;
        // nds1.Test_LC91_numDecodings1();

        // numDecodings nds2;
        // nds2.Test_LC91_numDecodings2();

        // numDecodings nds3;
        // nds3.Test_LC91_numDecodings3();
    }
/***********************************************************************/
    /*解码方法II*/
    {
        // using DP_One_dimensional::numDecodingsII;

        // numDecodingsII nuII1;
        // nuII1.Test_LC639_numDecodingsII1();

        // numDecodingsII nuII2;
        // nuII2.Test_LC639_numDecodingsII2();

        // numDecodingsII nuII3;
        // // nuII3.Test_LC639_numDecodingsII3();
    }
/***********************************************************************/
    /*丑数II*/
    {
        // using DP_One_dimensional::nthUglyNumber;
        // nthUglyNumber ntr;
        // ntr.Test_LC264_nthUglyNumber();
    }
/***********************************************************************/
    /*有效括号*/
    {
        // using DP_One_dimensional::longestValidParentheses;
        // longestValidParentheses les;
        // les.Test_LC32_longestValidParentheses();
    }
/***********************************************************************/
    /*环绕字符串中唯一的子字符串*/
    {
        // using DP_One_dimensional::findSubstringInWraproundString;
        // findSubstringInWraproundString fng;
        // fng.Test_LC467_findSubstringInWraproundString();
    }
/***********************************************************************/
    /*不同的子序列II*/
    {
        // using DP_One_dimensional::distinctSubseqII;
        // distinctSubseqII dis;
        // dis.Test_LC940_distinctSubseqII();
    }
/***********************************************************************/
    /*最小路径和*/
    {
        // using DP_Two_dimensional::minPathSum;
        // minPathSum su;
        // su.Test_LC64_minPathSum3();
    }
/***********************************************************************/
    /*单词搜索*/
    {
        // using DP_Two_dimensional::exist;
        // exist est;
        // est.Test_LC79_exist();
    }
/***********************************************************************/
    /*最长公共子序列*/
    {
        // using DP_Two_dimensional::longestCommonSubsequence;
        // longestCommonSubsequence lce;
        // lce.Test_LC1143_longestCommonSubsequence();
    }
/***********************************************************************/
    /*最长回文子序列*/
    {
        // using DP_Two_dimensional::longestPalindromeSubseq;
        // longestPalindromeSubseq leq;
        // leq.Test_LC516_longestPalindromeSubseq();
    }
/***********************************************************************/
    //限制高度情况下的树的种类个数
    {
        // using DP_Two_dimensional::NodenHeightNotLargerThanm;
        // NodenHeightNotLargerThanm nmN;
        // nmN.Test_Main_Compute();
    }
/***********************************************************************/
    //矩阵中的最长递增路径
    {
        // using DP_Two_dimensional::longestIncreasingPath;
        // longestIncreasingPath loh;
        // loh.Test_LC329_longestIncreasingPath();
    }
/***********************************************************************/
    /*不同的子序列*/
    {
        // using DP_Two_dimensional::numDistinct;
        // numDistinct nnt;
        // nnt.Test_LC115_numDistinct();
    }
/***********************************************************************/
    /*编辑距离*/
    {
        // using DP_Two_dimensional::minDistance;
        // minDistance mce;
        // mce.Test_LC72_minDistance();
    }
/***********************************************************************/
    //交错字符
    {
        // using DP_Two_dimensional::isInterleave;
        // isInterleave ive;
        // ive.Test_LC97_isInterleave();
    }
/***********************************************************************/
    /*有效涂色问题*/
    {
        // using DP_Two_dimensional::effectiveColoring;
        // effectiveColoring eig;
        // eig.Test_Ex_effectiveColoring();
    }
/***********************************************************************/
    /*删除至少几个字符可以变成另一个字符串的子串*/
    {
        // using DP_Two_dimensional::stringChanges;
        // stringChanges ces;
        // ces.Test_EX_stringChanges();
    }
/***********************************************************************/
    /*每颗子树内缺失的最小基因值*/
    {
        // using DP_Two_dimensional::smallestMissingValueSubtree;
        // smallestMissingValueSubtree ter;
        // ter.Test_LC2003_smallestMissingValueSubtree();
    }
/***********************************************************************/
    /*一和零*/
    {
        // using DP_Three_dimensional::findMaxForm;
        // findMaxForm frm;
        // frm.Test_LC474_findMaxForm();
    }
/***********************************************************************/
    /*盈利计划*/
    {
        // using DP_Three_dimensional::profitableSchemes;
        // profitableSchemes pes;
        // pes.Test_LC879_profitableSchemes();
    }
/***********************************************************************/
    /*骑士在棋盘上的概率*/
    {
    //    using DP_Three_dimensional:: knightProbability;
    //    knightProbability kty;
    //    kty.Test_LC688_knightProbability();
    }
/***********************************************************************/
    /*矩阵中和能被k整除的路径*/
    {
        // using DP_Three_dimensional::numberOfPaths;
        // numberOfPaths numb;
        // numb.Test_LC2435_numberOfPaths();
    }
/***********************************************************************/
    /*扰乱字符串*/
    {
        // using DP_Three_dimensional::isScramble;
        // isScramble ile;
        // ile.Test_LC87_isScramble();
    }
/***********************************************************************/
    /*子数组最大累加和*/
    {
        // using TheNumberOfMaxSubArray::maxsubArray;
        // maxsubArray  may;
        // may.Test_LC53_maxsubArray();
    }
/***********************************************************************/
    {
        // using TheNumberOfMaxSubArray::Rob;
        // Rob r;
        // r.Test_LC198_rob();
    }
/***********************************************************************/
    {
        // using TheNumberOfMaxSubArray::getMaxMatrix;
        // getMaxMatrix gix;
        // gix.Test_MS1724_getMaxMatrix();
    }
/***********************************************************************/
    {
        // using TheNumberOfMaxSubArray::maxProduct;
        // maxProduct duc;
        // duc.Test_LC152_maxProduct();
    }
/***********************************************************************/
//{
//     using TheNumberOfArrayEX::lengthOfLIS;
//     lengthOfLIS lis;
//     lis.Test_LC300_lengthOfLIS();
// }
/***********************************************************************/
// {
//     using ZeroAndOneBackpackIssues::minInsertions;
//     minInsertions mos;
//     mos.Test_LC1312_minInsertions();
// }
// {
//     using ZeroAndOneBackpackIssues::countPalindromicSubsequences;
//     countPalindromicSubsequences ces;
//     ces.Test_LC730_countPalindromicSubsequences();
// }
/***********************************************************************/
{
    using TheTreeDP::MaxBSTSize;
    MaxBSTSize sBT;
    sBT.Test_LC_MaxBSTSize();
}
/***********************************************************************/
auto end=chrono::system_clock::now();
cout<<"运行时长："<<chrono::duration_cast<chrono::microseconds>(end-statr).count()<<" ms "<<endl;
while(getchar()!='\n')continue;
getchar();
return 0;
}
