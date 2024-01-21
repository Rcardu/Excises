#include"DynamicPro.h"
#include <queue>
#include <utility>
#include <vector>
using namespace std;


namespace DP_One_dimensional{
/***********************************************************************/
    /*쳲���������*/
    /// @brief ����ⷨ
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
    /// @brief �Զ�����
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

    /// @brief �Ե׵���
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
    /// @brief �ռ��Ż�
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
    /*LeetCode 983 ���Ʊ��*/
    ///�����ݹ�
    int mincostTickets::LC983_mincostTickets1(vector<int>& days, vector<int>& costs){
        return LC983_mincostTickets_f1(days,costs,0);
    }
    int mincostTickets::LC983_mincostTickets_f1(vector<int>&days,vector<int>&costs,int i){
        //��i����days.size()λ�õ�ʱ��˵���Ѿ�û��������,���ٻ���Ϊ0
        if(i==days.size())return 0;
        //������days[i]�죬��һ������
        //�����ַ�������һ��,ȥ�ݹ鷽������֮��Ļ���
        
        //��days[i]��ʼ�����һ������ٻ���
        int ans=INT_MAX;
        //һ�����ַ��� 
        for(int k=0,j=i;k<3;k++){
            //�ӵ�days[i]�쿪ʼ������k���������Ƿ���԰�������days[j]��
            while(j<days.size()&&days[i]+durations[k]>days[j])j++;
            //��ǰѡ�񷽰������ѵ�Ǯ���Ϻ����Ļ���
            ans=min(ans,costs[k]+LC983_mincostTickets_f1(days,costs,j));
        }
        return ans;
    }
    void mincostTickets::Test_LC983_mincostTickets1(){
        vector<int>days={1,2,3,4,5,6,7,8,9,10,30,31};
        vector<int>costs={2,7,15};
        cout<<LC983_mincostTickets1(days,costs);
    }
    /// @brief �Զ����׼��仯����
    /// @param days 
    /// @param costs 
    /// @return 
    int mincostTickets::LC983_mincostTickets2(vector<int>& days, vector<int>& costs){
        vector<int>dp(days.size(),INT_MAX);
        return LC983_mincostTickets_f2(days,costs,0,dp);
    }
    int mincostTickets::LC983_mincostTickets_f2(vector<int>&days,vector<int>&costs,int i,vector<int>&dp){
        //��i����days.size()λ�õ�ʱ��˵���Ѿ�û��������,���ٻ���Ϊ0
        if(i==days.size())return 0;
        //������days[i]�죬��һ������
        //�����ַ�������һ��,ȥ�ݹ鷽������֮��Ļ���
        
        //����˷�������¼���ͷ��ش�����¼
        if(dp[i]!=INT_MAX)return dp[i];
        //��days[i]��ʼ�����һ������ٻ���
        int ans=INT_MAX;
        //һ�����ַ��� 
        for(int k=0,j=i;k<3;k++){
            //�ӵ�days[i]�쿪ʼ������k���������Ƿ���԰�������days[j]��
            while(j<days.size()&&days[i]+durations[k]>days[j])j++;
            //��ǰѡ�񷽰������ѵ�Ǯ���Ϻ����Ļ���
            ans=min(ans,costs[k]+LC983_mincostTickets_f2(days,costs,j,dp));
        }
        //��¼������¼
        dp[i]=ans;
        return ans;
    }
    void mincostTickets::Test_LC983_mincostTickets2(){
        vector<int>days={1,2,3,4,5,6,7,8,9,10,30,31};
        vector<int>costs={2,7,15};
        cout<<LC983_mincostTickets2(days,costs);
    }
    /// @brief �Ե׵�������������
    /// @param days 
    /// @param costs 
    /// @return 
    int mincostTickets::LC983_mincostTickets3(vector<int>& days, vector<int>& costs){
        int n=days.size();
        vector<int>dp(n+1,INT_MAX);
        
        //�±�n����Խ�磬��һ������Ҳû���ˣ�����Ҳ������
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            for(int k=0,j=i;k<3;k++){
                while(j<days.size()&&days[i]+durations[k]>days[j])j++;
                
                //��С���Ѿ��ǵ�ǰ��������+��������
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
    /*LeetCode 91 ���뷽��*/
    ///�����ݹ�
    int numDecodings::LC91_numDecodings1(string s){
        return LC91_numDecodings_f1(s,0);
    }
    //��s[i......]�ж�������Ч��ת������
    int numDecodings::LC91_numDecodings_f1(string s,int i){
        //����֮ǰ�ľ�����һ����Ч��ת��
        if(i==s.length())return 1;
        int ans=0;
        //�����ǰλ��Ϊ0���޷�ת��������Чת����ֱ�ӷ���0
        if(s[i]=='0')return 0;
        else{
            //ֻת��һ��
            ans=LC91_numDecodings_f1(s,i+1);
            //ת��������ֵ��ҪС�ڵ���26
            if(i+1<s.length()&&((s[i]-'0')*10+s[i+1]-'0')<=26)ans+=LC91_numDecodings_f1(s,i+2);
        }
        return ans;
    }

    void numDecodings::Test_LC91_numDecodings1(){
        string s="226";
        cout<<LC91_numDecodings1(s)<<endl;
    }
    /// @brief �Զ����׼��仯����
    /// @param s 
    /// @return 
    int numDecodings::LC91_numDecodings2(string s){
        vector<int>dp(s.length(),-1);
        return LC91_numDecodings_f2(s,0,dp);
    }
    //��s[i......]�ж�������Ч��ת������
    int numDecodings::LC91_numDecodings_f2(string s,int i,vector<int>&dp){
        //����֮ǰ�ľ�����һ����Ч��ת��
        if(i==s.length())return 1;
        //�����ǰλ�ô���ת���ѱ���¼���ؼ�¼��ֵ
        if(dp[i]!=-1)return dp[i];

        int ans=0;
        //�����ǰλ��Ϊ0���޷�ת��������Чת����ֱ�ӷ���0
        if(s[i]=='0')return 0;
        else{
            //ֻת��һ��
            ans=LC91_numDecodings_f2(s,i+1,dp);
            //ת��������ֵ��ҪС�ڵ���26
            if(i+1<s.length()&&((s[i]-'0')*10+s[i+1]-'0')<=26)ans+=LC91_numDecodings_f2(s,i+2,dp);
        }
        //�ռ���ǰλ�õĴ�
        dp[i]=ans;
        return ans;
    }
    void numDecodings::Test_LC91_numDecodings2(){
        string s="226";
        cout<<LC91_numDecodings2(s)<<endl;
    }
    /// @brief �Ե׵����ϸ����
    /// @param s 
    /// @return 
    int numDecodings::LC91_numDecodings3(string s){
        int n=s.length();
        vector<int>dp(n+1,-1);
        dp[n]=1;
        //����������
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
        //dp[n]��dp[n+1]
        int dp0=1,dp1=-1;
        //����������
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
    /*���뷽��II*/
    //�����ݹ�
    int numDecodingsII::LC639_numDecodingsII1(string s){
        return LC639_numDecodingsII_f1(s,0);
    }
    int numDecodingsII::LC639_numDecodingsII_f1(string s,int i){
        if(i==s.length())return 1;
        
        //1��֧iλ��Ϊ0
        if(s[i]=='0')return 0;
        //2��֧iλ�õ���ת��
        int ans=LC639_numDecodingsII_f1(s,i+1)*(s[i]=='*'?9:1);

        //3��֧i��i+1һ��ת��
        if(i+1<s.length()){
            if(s[i]!='*'){//i����*
                if(s[i+1]!='*'){//i+1Ҳ����*
                    if((s[i]-'0')*10+s[i+1]-'0'<=26)ans+=LC639_numDecodingsII_f1(s,i+2);
                }else{//i+1��*
                    if(s[i]=='1')ans+=9*LC639_numDecodingsII_f1(s,i+2);
                    if(s[i]=='2')ans+=6*LC639_numDecodingsII_f1(s,i+2);
                }
            }else{//i��*
                if(s[i+1]!='*'){//i+1����*
                    if(s[i+1]<='6')ans+=2*LC639_numDecodingsII_f1(s,i+2);
                    else ans+=LC639_numDecodingsII_f1(s,i+2);
                }else{//i+1��*
                    /*
                        ���ǵ�i��i+1λ�õ�����С�ڵ���26�����
                        11 12 13 14 15 16 17 18 19  9��
                        21 22 23 24 25 26           6��
                        һ��15����ϣ���ȥ�ݹ�Ѱ��
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
    /// @brief �Զ����¼��仯����
    /// @param s 
    /// @return 
    int numDecodingsII::LC639_numDecodingsII2(string s){
        vector<long>dp(s.length(),-1);
        return LC639_numDecodingsII_f2(s,0,dp);
    }
    long numDecodingsII::LC639_numDecodingsII_f2(string s,int i,vector<long>&dp){
        if(i==s.length())return 1;
        
        if(dp[i]!=-1)return dp[i];

        //1��֧iλ��Ϊ0
        if(s[i]=='0')return 0;
        //2��֧iλ�õ���ת��
        long ans=LC639_numDecodingsII_f2(s,i+1,dp)*(s[i]=='*'?9:1);

        //3��֧i��i+1һ��ת��
        if(i+1<s.length()){
            if(s[i]!='*'){//i����*
                if(s[i+1]!='*'){//i+1Ҳ����*
                    if((s[i]-'0')*10+s[i+1]-'0'<=26)ans+=LC639_numDecodingsII_f2(s,i+2,dp);
                }else{//i+1��*
                    if(s[i]=='1')ans+=9*LC639_numDecodingsII_f2(s,i+2,dp);
                    if(s[i]=='2')ans+=6*LC639_numDecodingsII_f2(s,i+2,dp);
                }
            }else{//i��*
                if(s[i+1]!='*'){//i+1����*
                    if(s[i+1]<='6')ans+=2*LC639_numDecodingsII_f2(s,i+2,dp);
                    else ans+=LC639_numDecodingsII_f2(s,i+2,dp);
                }else{//i+1��*
                    /*
                        ���ǵ�i��i+1λ�õ�����С�ڵ���26�����
                        11 12 13 14 15 16 17 18 19  9��
                        21 22 23 24 25 26           6��
                        һ��15����ϣ���ȥ�ݹ�Ѱ��
                    */
                   ans+=15*LC639_numDecodingsII_f2(s,i+2,dp);
                }
            }
        }
        //��¼��ֵ
        ans%=MOD;
        dp[i]=ans;
        return ans;
    }
    void numDecodingsII::Test_LC639_numDecodingsII2(){
        string s="7*9*3*6*3*0*5*4*9*7*3*7*1*8*3*2*0*0*6*";
        cout<<LC639_numDecodingsII2(s)<<endl;
    }
    /// @brief �Ե�����
    /// @param s 
    /// @return 
    int numDecodingsII::LC639_numDecodingsII3(string s){
        int n=s.size();
        vector<long long>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            //ss[i]����Ϊ'0'
            if(s[i]!='0'){
                //ֻѡ��i
                dp[i]=(s[i]=='*'?9:1)*dp[i+1];
                if(i+1<n){//ѡ��i��i+1�����
                    if(s[i]!='*'){//i��Ϊ*
                        if(s[i+1]!='*'){//i+1Ҳ��Ϊ*
                            //������͵�ֵ��26��
                            if((s[i]-'0')*10+s[i+1]-'0'<=26)dp[i]+=dp[i+2];
                        }else{//i+1��*
                            //1* ��2* �����������3*�ͳ���26��
                            if(s[i]=='1')dp[i]+=dp[i+2]*9;
                            else if(s[i]=='2')dp[i]+=dp[i+2]*6;
                        }
                    }else{//i��*
                        if(s[i+1]!='*'){//i+1��Ϊ*
                            //s[i+1]С�ڵ���6ʱ 1��2�����Ժ�s[i+1]���
                            if(s[i+1]<='6')dp[i]+=dp[i+2]*2;
                            else dp[i]+=dp[i+2];
                        }else{//i+1��*
                            dp[i]+=dp[i+2]*15;
                        }
                    }
                }
                dp[i]%=MOD;
            }
        }
        return dp[0];
    }
    /// @brief �ռ��Ż�
    /// @param s 
    /// @return 
    int numDecodingsII::LC639_numDecodingsII4(string s){
        int n=s.size();
        long long dp0=1,dp1=-1,cur;
        for(int i=n-1;i>=0;i--){
            //ss[i]����Ϊ'0'
            if(s[i]!='0'){
                //ֻѡ��i
                cur=(s[i]=='*'?9:1)*dp0;
                if(i+1<n){//ѡ��i��i+1�����
                    if(s[i]!='*'){//i��Ϊ*
                        if(s[i+1]!='*'){//i+1Ҳ��Ϊ*
                            //������͵�ֵ��26��
                            if((s[i]-'0')*10+s[i+1]-'0'<=26)cur+=dp1;
                        }else{//i+1��*
                            //1* ��2* �����������3*�ͳ���26��
                            if(s[i]=='1')cur+=dp1*9;
                            else if(s[i]=='2')cur+=dp1*6;
                        }
                    }else{//i��*
                        if(s[i+1]!='*'){//i+1��Ϊ*
                            //s[i+1]С�ڵ���6ʱ 1��2�����Ժ�s[i+1]���
                            if(s[i+1]<='6')cur+=dp1*2;
                            else cur+=dp1;
                        }else{//i+1��*
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
    /*����II*/
    void numDecodingsII::Test_LC639_numDecodingsII3(){
        string s="1*";
        cout<<LC639_numDecodingsII4(s)<<endl;
    }
    int nthUglyNumber::LC264_nthUglyNumber(int n){
        vector<int>dp(n+1);
        dp[0]=1;
        //i2,i3,i5:����2��3��5������ָ��ֱ�ͣ��ʲô�±�
        for(int i=1,i2=0,i3=0,i5=0,a,b,c,cur;i<=n;i++){
            //��ǰָ��λ�õĳ�������2��3��5������
            a=dp[i2]*2;
            b=dp[i3]*3;
            c=dp[i5]*5;
            //�ҳ���С���Ǹ�����
            cur=min(a,min(b,c));
            //����С������ָ������ָ��+1
            if(cur==a)i2++;
            if(cur==b)i3++;
            if(cur==c)i5++;
            //�����i��λ�ó���cur
            dp[i]=cur;
        }
        return (int)dp[n];
    }
    void nthUglyNumber::Test_LC264_nthUglyNumber(){
        cout<<LC264_nthUglyNumber(1000000000 )<<endl;
    } 
/***********************************************************************/
    /*��Ч����*/
    int longestValidParentheses::LC32_longestValidParentheses(string s){
        /*
        dp[i]-->'(':dp[i]==0
        dp[i]->')'*,����dp[i-1]�ĳ�����ǰ����ƥ���λ��pλ��
            a.[p]-->')',dp[i]=0;
            b.[p]-->'(',dp[i]==dp[i-1]+2+dp[p-1]*/
        int n=s.length();
        vector<int>dp(n,0);
        int ans=dp[0];
        for(int i=1,p;i<n;i++){
            if(s[i]==')'){//�����žͼ�¼��������ֱ����������
                p=i-dp[i-1]-1;//��λp��λ��
                //���p���������Һϸ�dp[i]������dp[i-1]+2:�ٿ���p-1λ�õ����
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
    /*�����ַ�����Ψһ�����ַ���*/
    int findSubstringInWraproundString::LC467_findSubstringInWraproundString(string s){
         int n=s.length();
         vector<int>str(n);
         for(int i=0;i<n;i++)str[i]=s[i]-'a';
         //dp[0]:s�б�����'a'���Ӵ����������ĳ����Ƕ���
         vector<int>dp(26);
         dp[str[0]]=1;
         for(int i=1,cur,pre,len=1;i<n;i++){
            //��ǰ�ַ�
            cur=str[i];
            //ǰһ���ַ�
            pre=str[i-1];
            if((pre==25&&cur==0)||pre+1==cur){
                //���У����ǰһ���ַ���z��ǰ��a����ôҲ����
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
    /*��ͬ��������II*/
    int distinctSubseqII::LC940_distinctSubseqII(string s){
        //������¼��ĳ����ĸ��β���Ӵ��ĸ���
        vector<int>cnt(26);
        //���Ӵ��ĸ�������ĳ����ĸ��β��������ų����е��Ӵ������������Ӵ��ĸ���
        int all=1,newAdd;
        for(char x:s){
            //���������Ӵ���������֮ǰ�ռ������ܸ���-�Ե�ǰ��ĸ��β�ļ�¼�ĸ���
            newAdd=(all-cnt[x-'a']+MOD)%MOD;
            //�µ��Ե�ǰ��ĸ��β���Ӵ��ĸ��������ټ��������ĸ���
            cnt[x-'a']=(cnt[x-'a']+newAdd)%MOD;
            //�ܼ�¼���������ļ���֮ǰ�ܵ�
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
    //�����ݹ�
    int minPathSum::LC64_minPathSum_f1(vector<vector<int>>& grid,int i,int j){
        //�����ʱֱ�ӷ���
        if(i==0&&j==0)return grid[0][0];

        int up=INT_MAX;
        int left=INT_MAX;
        //ȥ����
        if(i-1>=0)up=LC64_minPathSum_f1(grid,i-1,j);
        //���
        if(j-1>=0)left=LC64_minPathSum_f1(grid,i,j-1);
        return grid[i][j]+min(up,left);
    }   
    void minPathSum::Test_LC64_minPathSum(){
        vector<vector<int>>grid;
        cout<<LC64_minPathSum(grid)<<endl;
    }
    ///���仯����
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
    //�ϸ�λ������
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
    //�ռ��Ż�
    int minPathSum::LC64_minPathSum4(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<int>dp(m,0);
        dp[0]=grid[0][0];
        for(int j=1;j<m;j++)dp[j]=grid[0][j]+dp[j-1];
        for(int i=1;i<n;i++){
            //���µ�0�е�ֵ
            dp[0]+=grid[i][0];
            for(int j=1;j<m;j++){
                //����i��j�е�ֵ 
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
    /*LeetCode 79 ��������*/
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
        //�Ƿ�Խ�����Ƿ�ϸ�
        if(i<0||i==board.size()||j<0||j==board[0].size()||board[i][j]!=word[k])return false;
        //ƥ������ʱ�޸ĵ�ǰλ�ã������ݹ�����
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
    /*LeetCode 1143 �����������*/
    int longestCommonSubsequence::LC1143_longestCommonSubsequence1(string text1, string text2){
        int n=text1.size();
        int m=text2.size();
        return LC1143_longestCommonSubsequence_f1(text1,text2,n-1,m-1);
    }
    /*s1[0....i1]��s2[0....i2]����������еĳ���*/
    int longestCommonSubsequence::LC1143_longestCommonSubsequence_f1(string text1, string text2,int i1,int i2){
        //�����ĸ���������0���⣬��˵��û���ˣ�����0 
        if(i1<0||i2<0)return 0;
        /*��i1��i2��β�������������һ�����ֿ�����
        1.�Ȳ�������i1��β��Ҳ������i2��β�������ݹ�������i1-1��i2-1��β��
        2.ֻ����i1��β�ģ���������i2
        3.ֻ����i2��β�ģ���������i1
        4.s[i1]==s[i2]�������������ݹ�Ѱ��*/
        int p1=LC1143_longestCommonSubsequence_f1(text1,text2,i1-1,i2-1);
        int p2=LC1143_longestCommonSubsequence_f1(text1,text2,i1,i2-1);
        int p3=LC1143_longestCommonSubsequence_f1(text1,text2,i1-1,i2);
        int p4=text1[i1]==text2[i2]?(p1+1):0;
        return max(max(p1,p2),max(p3,p4));

    }
    /// @brief �ı���������
    /// @param text1 
    /// @param text2 
    /// @return 
    int longestCommonSubsequence::LC1143_longestCommonSubsequence2(string text1, string text2){
        int len1=text1.size();
        int len2=text2.size();
        return LC1143_longestCommonSubsequence_f2(text1,text2,len1,len2);
    }
    /*s1[ǰ׺����Ϊlen1]��s2[ǰ׺����Ϊlen2]
    ����������еĳ���*/
    int longestCommonSubsequence::LC1143_longestCommonSubsequence_f2(string text1, string text2,int len1,int len2){
        //�����ĸ���������0����˵��û���ˣ�����0 
        if(len1==0||len2==0)return 0;
        /*��i1��i2��β�������������һ�����ֿ�����
        1.�Ȳ�������i1��β��Ҳ������i2��β�������ݹ�������i1-1��i2-1��β��
        2.ֻ����i1��β�ģ���������i2
        3.ֻ����i2��β�ģ���������i1
        4.s[i1]==s[i2]�������������ݹ�Ѱ��*/
        int ans;
        if(text1[len1-1]==text2[len2-1]){
            ans=LC1143_longestCommonSubsequence_f2(text1,text2,len1-1,len2-1)+1;
        }else{
            ans=max(LC1143_longestCommonSubsequence_f2(text1,text2,len1-1,len2),LC1143_longestCommonSubsequence_f2(text1,text2,len1,len2-1));
        }
        return ans;

    }
    /// @brief ���仯����
    /// @param text1 
    /// @param text2 
    /// @return 
    int longestCommonSubsequence::LC1143_longestCommonSubsequence3(string text1, string text2){
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return LC1143_longestCommonSubsequence_f3(text1,text2,n,m,dp);
    }
    /*s1[ǰ׺����Ϊlen1]��s2[ǰ׺����Ϊlen2]
    ����������еĳ���*/
    int longestCommonSubsequence::LC1143_longestCommonSubsequence_f3(string text1, string text2,int len1,int len2,vector<vector<int>>&dp){
        //�����ĸ���������0����˵��û���ˣ�����0 
        if(len1==0||len2==0)return 0;
        if(dp[len1][len2]!=-1)return dp[len1][len2];
        /*��i1��i2��β�������������һ�����ֿ�����
        1.�Ȳ�������i1��β��Ҳ������i2��β�������ݹ�������i1-1��i2-1��β��
        2.ֻ����i1��β�ģ���������i2
        3.ֻ����i2��β�ģ���������i1
        4.s[i1]==s[i2]�������������ݹ�Ѱ��*/
        int ans;
        if(text1[len1-1]==text2[len2-1]){
            ans=LC1143_longestCommonSubsequence_f3(text1,text2,len1-1,len2-1,dp)+1;
        }else{
            ans=max(LC1143_longestCommonSubsequence_f3(text1,text2,len1-1,len2,dp),LC1143_longestCommonSubsequence_f3(text1,text2,len1,len2-1,dp));
        }
        dp[len1][len2]=ans;
        return ans;
    }
    /// @brief �ϸ�λ������
    /// @param text1 
    /// @param text2 
    /// @return 
    int longestCommonSubsequence::LC1143_longestCommonSubsequence4(string text1, string text2){
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int len1=1;len1<=n;len1++){
            for(int len2=1;len2<=m;len2++){
                //��text1[len1-1]==text2[len2-1]ʱ�������������ϵĸ���
                if(text1[len1-1]==text2[len2-1])dp[len1][len2]=dp[len1-1][len2-1]+1;
                //����������������ĸ��ӻ�����ߵĸ���
                else dp[len1][len2]=max(dp[len1][len2-1],dp[len1-1][len2]);
            }
        }
        return dp[n][m];
    }
    /// @brief �ռ��Ż�
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
            //������¼��ǰ���Ͻǵ�ֵ����һ�����Ͻǵ�ֵ
            int leftUp=0,backUp;
            for(int len2=1;len2<=m;len2++){
                backUp=dp[len2];
                if(s1[len1-1]==s2[len2-1])dp[len2]=leftUp+1;
                //�����ֵ���ǵ�ǰλ�ã�ǰ���ֵ����len2-1
                else dp[len2]=max(dp[len2],dp[len2-1]);
                //�������Ͻǵ�ֵ
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
    /*LeetCode 516 �����������*/
    /*�ⷨ1��һ���ַ���������������о������������򴮵�  �����������*/
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
    /// @brief ���۴�[L....R]�����ڵ������������
    /// @param s 
    /// @return 
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq1(string s){
        int n=s.size();
        return LC516_longestPalindromeSubseq1_f1(s,0,n-1);
    }
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq1_f1(string s,int l,int r){
        //��l==rʱ˵������ͬһ��λ�õ��ַ�������Ϊ1��ֱ�ӷ���
        if(l==r)return 1;
        //��������Χ���������ַ�
        if(l+1==r){
            //����������ַ���ȣ�����2�����򷵻�1
            return s[l]==s[r]?2:1;
        }
        //�����ǰ����λ�õ��ַ���ȣ����+2��������[L+1.....R-1]��Χ�ڵ������������
        if(s[l]==s[r])return 2+LC516_longestPalindromeSubseq1_f1(s,l+1,r-1);
        //����ȣ�����[L+1....R]��[L....R-1]��Χ�ĵ������������ȡ���ֵ
        else return max(LC516_longestPalindromeSubseq1_f1(s,l+1,r),LC516_longestPalindromeSubseq1_f1(s,l,r-1));
    }
    /// @brief ���仯����
    /// @param s 
    /// @return 
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq2(string s){
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return LC516_longestPalindromeSubseq1_f2(s,0,n-1,dp);
    }
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq1_f2(string s,int l,int r,vector<vector<int>>&dp){
        //��l==rʱ˵������ͬһ��λ�õ��ַ�������Ϊ1��ֱ�ӷ���
        if(l==r)return 1;
        //��������Χ���������ַ�
        if(l+1==r){
            //����������ַ���ȣ�����2�����򷵻�1
            return s[l]==s[r]?2:1;
        }
        if(dp[l][r]!=-1)return dp[l][r];
        int ans;
        //�����ǰ����λ�õ��ַ���ȣ����+2��������[L+1.....R-1]��Χ�ڵ������������
        if(s[l]==s[r])ans=2+LC516_longestPalindromeSubseq1_f2(s,l+1,r-1,dp);
        //����ȣ�����[L+1....R]��[L....R-1]��Χ�ĵ������������ȡ���ֵ
        else ans=max(LC516_longestPalindromeSubseq1_f2(s,l+1,r,dp),LC516_longestPalindromeSubseq1_f2(s,l,r-1,dp));
        dp[l][r]=ans;
        return ans;
    }
    /// @brief �ϸ�λ������
    /// @param s 
    /// @return 
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq3(string s){
        /*��ǰλ�õĸ���������(l+1,r-1)��(l+1,r)��(l,r-1)λ�õĸ��ӣ�˵��Ӧ�ô��µ��ϣ������ҽ��б���*/
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        //�ӵײ���ʼ����
        for(int l=n-1;l>=0;l--){
            //l���ܴ���r����l����r�ĸ��Ӷ�����Ч����
            dp[l][l]=1;
            //����������ַ�����ֱ���ж�
            if(l+1<n)dp[l][l+1]=s[l]==s[l+1]?2:1;
            //��������ַ����Ͽ�ʼdp
            for(int r=l+2;r<n;r++){
                if(s[l]==s[r])dp[l][r]=2+dp[l-1][r-1];
                else dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
            }
        }
        return dp[0][n-1];
    }
    /// @brief �ռ�ѹ��
    /// @param s 
    /// @return 
    int longestPalindromeSubseq::LC516_longestPalindromeSubseq4(string s){
        int n=s.size();
        vector<int>dp(n,0);
        //��¼���½ǵ�ֵ
        for(int l=n-1,leftDown=0,backDown;l>=0;l--){
            dp[l]=1;
            if(l+1<n){
                //�������½ǵ�ֵ
                leftDown=dp[l+1];
                dp[l+1]=s[l]==s[l+1]?2:1;
            }
            for(int r=l+2;r<n;r++){
                //��¼���½ǵ�ֵ
                backDown=dp[r];
                if(s[l]==s[r])dp[r]=2+leftDown;
                else dp[r]=max(dp[r],dp[r-1]);
                //�������½ǵ�ֵ
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
    /*�����Ƹ߶ȵ�����¶������ĸ���*/
    //���仯����
    int NodenHeightNotLargerThanm::Main_Compute1(int n,int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return Compute1(n,m,dp);
    }
    int NodenHeightNotLargerThanm::Compute1(int n,int m,vector<vector<int>>&dp){
        //����
        if(n==0)return 1;
        //�߶�Ϊ0�Ļ�
        if(m==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        int ans=0;
        for(int k=0;k<n;k++){
            //������k��,�߶�����Ϊm-1   ������n-k-1�����߶�Ϊm-1
            ans=(ans+(Compute1(k,m-1,dp)*Compute1(n-k-1,m-1,dp))%MOD)%MOD;
        }
        dp[n][m]=ans;
        return ans;  
    }
    /// @brief �ϸ�λ������
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
                    //һ��i���ڵ㣬ͷ���ռ����һ�����
                    //�������ռ��k������ô������ռ��i-k-1��
                    dp[i][j]=(dp[i][j]+dp[k][j-1]*dp[i-k-1][j-1]%MOD)%MOD;
                }
            }
        }
        return dp[n][m];
    }
    /// @brief �ռ�ѹ��
    /// @param n 
    /// @param m 
    /// @return 
    int NodenHeightNotLargerThanm::Main_Compute3(int n,int m){
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int j=1;j<=m;j++){
            //����������һ��Ҫ��ö����
            for(int i=n;i>=1;i--){
                //��ö����
                dp[i]=0;
                for(int k=0;k<i;k++){//ö��ÿ���ڵ�
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
    /*LeetCode 329 �����е������·��*/
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
    //��(i,j)�������߳�������ĵ���·��
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
    //���仯����
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
    /*LeetCode 115 ��ͬ��������*/
    int numDistinct::LC115_numDistinct(string s, string t){
        /*dp[i][j]:s����0����i���ַ����������ɵ��Ӵ��а���t����0��j���ַ��ĸ���
        ��s�ĵ�[i-1]λ�õ��ַ���Ҫ����ô��ֻ�ܴ�[0.....i-2]��ȡ����ϼ�dp[i-1][j]
        s�ĵ�[i-1]λ�õ��ַ�Ҫ����ô����t[j-1]==s[i-1]
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
    /// @brief �ռ�ѹ��
    /// @param s 
    /// @param t 
    /// @return 
    int numDistinct::LC115_numDistinct_EC(string s, string t){
        /*dp[i][j]:s����0����i���ַ����������ɵ��Ӵ��а���t����0��j���ַ��ĸ���
        ��s�ĵ�[i-1]λ�õ��ַ���Ҫ����ô��ֻ�ܴ�[0.....i-2]��ȡ����ϼ�dp[i-1][j]
        s�ĵ�[i-1]λ�õ��ַ�Ҫ����ô����t[j-1]==s[i-1]
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
    /*LeetCode 72 �༭����*/
    int minDistance::LC72_minDistance1(string s1, string s2,int a,int b,int c){
        /*s1ȡǰi����s2ȡǰj����Ҫ��s1���s2���ٵĴ����Ƕ���*/
        /*s1[i-1]����仯:
            a.s1[i-1]���s2[j-1]:
                1):s1[i-1]==s2[j-1] dp[i][j]=dp[i-1][j-1]
                2):s1[i-1]!=s2[j-1] dp[i][j]=dp[i-1][j-1]+c(�滻)
            b.s1[i-1]��ȥ���s2[j-1] dp[i][j]=dp[i][j-1]+a(����)
        s1[i-1]������仯 dp[i][j]=dp[i-1][j]+b(ɾ��)*/
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)dp[i][0]=i*b;
        for(int j=1;j<=m;j++)dp[0][j]=j*a;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int p1=INT_MAX;
                //���һ����û�д��ۼ��ɴ��
                if(s1[i-1]==s2[j-1])p1=dp[i-1][j-1];
                int p2=INT_MAX;
                //�����һ����Ҫһ���滻����
                if(s1[i-1]!=s2[j-1])p2=dp[i-1][j-1]+c;
                //���s1[i-1]��ȥ���s2[j-1]��ô����s1[0...i-1]��s2[0....j-2]Ҫ��Ӧ�ϣ����Ҽ���һ���������(����s2[j-1])
                int p3=dp[i][j-1]+a;
                //���s1������仯��ô����s1[0....i-2]��s2[0....j-1]��Ӧ������ɾ��s1[i-1]
                int p4=dp[i-1][j]+c;
                dp[i][j]=min(min(p1,p2),min(p3,p4));
            }
        }
        return dp[n][m];
    }
    /// @brief �ռ�ѹ��
    /// @param s1 
    /// @param s2 
    /// @param a 
    /// @param b 
    /// @param c 
    /// @return 
    int minDistance::LC72_minDistance_EC(string s1, string s2,int a,int b,int c){
        /*s1ȡǰi����s2ȡǰj����Ҫ��s1���s2���ٵĴ����Ƕ���*/
        /*s1[i-1]����仯:
            a.s1[i-1]���s2[j-1]:
                1):s1[i-1]==s2[j-1] dp[i][j]=dp[i-1][j-1]
                2):s1[i-1]!=s2[j-1] dp[i][j]=dp[i-1][j-1]+c(�滻)
            b.s1[i-1]��ȥ���s2[j-1] dp[i][j]=dp[i][j-1]+a(����)
        s1[i-1]������仯 dp[i][j]=dp[i-1][j]+b(ɾ��)*/
        int n=s1.size();
        int m=s2.size();
        vector<int>dp(m+1,0);
        for(int j=1;j<=m;j++)dp[j]=j*a;
        for(int i=1,leftUp,backUp;i<=n;i++){
            //ÿһ�е�0λ�õ�ֵ
            leftUp=(i-1)*b;
            dp[0]=i*b;
            for(int j=1;j<=m;j++){
                backUp=dp[j];
                //���һ����û�д��ۼ��ɴ��
                if(s1[i-1]==s2[j-1])dp[j]=leftUp;
                //�����һ����Ҫһ���滻����
                //���s1[i-1]��ȥ���s2[j-1]��ô����s1[0...i-1]��s2[0....j-2]Ҫ��Ӧ�ϣ����Ҽ���һ���������(����s2[j-1])
                //���s1������仯��ô����s1[0....i-2]��s2[0....j-1]��Ӧ������ɾ��s1[i-1]
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
    /*LeetCode 97 �����ַ���*/
    bool isInterleave::LC97_isInterleave(string s1, string s2, string s3){
        /*s1.length()+s2.length()!=s3.length();return false;
        s1[ǰi��]��s2[ǰj��]�ܲ��ܽ������s3[ǰi+j��]
        ���s1[i-1]==s3[i+j-1]--->s1[0....i-2] �� s2[0....j-1]������ɵ�s3[0....i+j-2]��dp[i-1][j]*/
        if(s1.length()+s2.length()!=s3.length())return false;
        int n=s1.length(),m=s2.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        //��s2ȡǰ0���ַ�s1ȡǰ1����ǰ2��...ǰn���ַ�ʱ�ܲ��ܶ�Ӧ��s3ǰ1����ǰ2��...ǰn��
        for(int i=1;i<=n;i++)if(s1[i-1]!=s3[i-1])break;else dp[i][0]=true;
        //��s1ȡǰ0���ַ�s2ȡǰ1����ǰ2��...ǰm���ַ�ʱ�ܲ��ܶ�Ӧ��s3ǰ1����ǰ2��...ǰm��
        for(int j=1;j<=m;j++)if(s2[j-1]!=s3[j-1])break;else dp[0][j]=true;
        //��s1ȡǰ1����ǰ2��...ǰn����s2ȡǰ1����ǰ2��...ǰm�����ܲ��ܶ�Ӧs3ȡǰ2����ǰ4��...ǰn+m��
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //���s1�ĵ�i-1λ�õ��ַ�����s3��i+j-1λ�õ��ַ����ң�s1ȡ[0....i-2]��s2ȡ[0...j-1]���Զ�Ӧs3[0....i+j-2]
                //���ߣ����s2�ĵ�j-1λ�õ��ַ�����s3��i+j-1λ�õ��ַ����ң�s2ȡ[0....j-2]��s1ȡ[0...i-1]���Զ�Ӧs3[0....i+j-2]
                //��ô˵����s1ȡ[0....i-1]��s2ȡ[0...j-1]���Զ�Ӧs3[0....i+j-1]����dp[i][j]=true;
                dp[i][j]=(s1[i-1]==s3[i+j-1]&&dp[i-1][j]||s2[j-1]==s3[i+j-1]&&dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    /// @brief �ռ�ѹ��
    /// @param s1 
    /// @param s2 
    /// @param s3 
    /// @return 
    bool isInterleave::LC97_isInterleave_EC(string s1, string s2, string s3){
        /*s1.length()+s2.length()!=s3.length();return false;
        s1[ǰi��]��s2[ǰj��]�ܲ��ܽ������s3[ǰi+j��]
        ���s1[i-1]==s3[i+j-1]--->s1[0....i-2] �� s2[0....j-1]������ɵ�s3[0....i+j-2]��dp[i-1][j]*/
        if(s1.length()+s2.length()!=s3.length())return false;
        int n=s1.length(),m=s2.length();
        vector<bool>dp(m+1,false);
        //��s1ȡǰ0���ַ�s2ȡǰ1����ǰ2��...ǰm���ַ�ʱ�ܲ��ܶ�Ӧ��s3ǰ1����ǰ2��...ǰm��
        for(int j=1;j<=m;j++)if(s2[j-1]!=s3[j-1])break;else dp[j]=true;
        //��s1ȡǰ1����ǰ2��...ǰn����s2ȡǰ1����ǰ2��...ǰm�����ܲ��ܶ�Ӧs3ȡǰ2����ǰ4��...ǰn+m��

        dp[0]=true;
        for(int i=1;i<=n;i++){
            //��s2ȡǰ0���ַ�s1ȡǰ1����ǰ2��...ǰn���ַ�ʱ�ܲ��ܶ�Ӧ��s3ǰ1����ǰ2��...ǰn��
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
    /*��ЧͿɫ����*/
    int effectiveColoring::Ex_effectiveColoring(int n,int m){
        /*dp[i][j]:ǰi�����ӣ�Ϳ��j����ɫ�ķ�����
        1.dp[i-1][j]*j
        2.dp[i-1][j-1]*(m-(j-1))*/
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)dp[i][1]=m;
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                //ǰ��ĸ��ӵķ�����*��Ҫ����ɫ�ĸ���
                dp[i][j]=(int)(((long long)dp[i-1][j]*j)%MOD);
                //�ټ���ǰ��ĸ���������ɫ��һ���������*ʣ�����ɫ
                dp[i][j]=(int)(((long long)dp[i-1][j-1]*(m-(j-1))+dp[i][j])%MOD);
            }
        }
        return dp[n][m];
    }
    void effectiveColoring::Test_Ex_effectiveColoring(){
        cout<<Ex_effectiveColoring(5000,4877)<<endl;
    }
/***********************************************************************/ 
    /*ɾ�����ټ����ַ����Ա����һ���ַ������Ӵ�*/
    int stringChanges::EX_stringChanges(string s1,string s2){
        int n=s1.length(),m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        /*s1[ǰ׺����Ϊi]����ɾ�������ַ������Ա��s2[ǰ׺����Ϊj]�������׺��*/
        for(int i=1;i<=n;i++){
            dp[i][0]=i;
            for(int j=1;j<=m;j++){
                //��ȾͲ���ɾ����ǰλ�õ��ַ�����֮ǰ����ɾ���˶��ٸ��ַ�
                if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];
                //����Ⱦ���Ҫɾ����ǰ�ַ����ٿ�֮ǰɾ�������ַ�����[0...j]�ĺ�׺��ƥ��
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
    /*LeetCode 2003 ÿ��������ȱʧ����С����ֵ*/
    vector<int> smallestMissingValueSubtree::LC2003_smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums){
        int n=parents.size();
        //��������ȱʧ����С����ֵ��Ϊ1
        vector<int>ans(n,1);
        //��ѯ1�Ƿ�����������ȱʧ����С����ֵ
        auto it=find(nums.begin(),nums.end(),1);
        //���û�ҵ�1����˵��ȱʧ����С����ֵ����1��ֱ�ӷ���ans
        if(it==nums.end())return ans;

        //������
        vector<vector<int>>g(n);
        for(int i=1;i<n;i++)g[parents[i]].push_back(i);
        unordered_set<int>set;
        //дdfs
        function<void(int)>dfs=[&](int x)->void{
            set.insert(nums[x]);
            for(int son:g[x]){
                if(!set.count(nums[son]))dfs(son);
            }
        };
        //ö����Сȱʧ����
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
    /*LeetCode 474 һ����*/
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
    //strs[i....]����ѡ��ϣ��0������������z��1������������o
    //�����ѡ�����ٸ��ַ���
    int findMaxForm::LC474_findMaxForm1_f1(vector<string>&strs,int i,int z,int o){
        if(i==strs.size())return 0;
        //��ʹ�õ�ǰiλ�õ��ַ���
        int p1=LC474_findMaxForm1_f1(strs,i+1,z,o);
        //ʹ�õ�ǰλ�õ��ַ���
        int p2=0;
        LC474_findMaxForm1_conts(strs[i]);
        if(zeros<=z&&ones<=o)p2=1+LC474_findMaxForm1_f1(strs,i+1,z-zeros,o-ones);
        return max(p1,p2);
    }
    /// @brief ���仯����
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
        //��ʹ�õ�ǰiλ�õ��ַ���
        int p1=LC474_findMaxForm1_f2(strs,i+1,z,o,dp);
        //ʹ�õ�ǰλ�õ��ַ���
        int p2=0;
        LC474_findMaxForm1_conts(strs[i]);
        if(zeros<=z&&ones<=o)p2=1+LC474_findMaxForm1_f2(strs,i+1,z-zeros,o-ones,dp);
        dp[i][z][o]=max(p1,p2);
        return dp[i][z][o]; 
    }
    /// @brief �ϸ�λ������
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
    /// @brief �Ż�
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
    /*LeetCode 879 ӯ���ƻ�*/
    int profitableSchemes::LC879_profitableSchemes1(int n, int minProfit, vector<int>& group, vector<int>& profit){
        return LC879_profitableSchemes_f1(group,profit,0,n,minProfit);
    }
    /*i��������i����Ŀ
    r:Ա������r��
    s��������s���ܴ�꣬���s<=0˵��֮ǰ�Ѿ������
    ���أ��ж����ַ���*/
    int profitableSchemes::LC879_profitableSchemes_f1(vector<int>&group,vector<int>&profit,int i,int r,int s){
        //���Ѿ��ľ���
        if(r<=0)return s<=0?1:0;
        //�����Ѿ�û��
        if(i==group.size())return s<=0?1:0;
        //���������
        int p1=LC879_profitableSchemes_f1(group,profit,i+1,r,s);
        //�������
        int p2=0;
        //ʣ�����Ҫ��������ǰ����������
        if(group[i]<=r)p2=LC879_profitableSchemes_f1(group,profit,i+1,r-group[i],s-profit[i]);
        return (p1+p2)%MOD;
    }
    /// @brief ���仯����
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
    /*i��������i����Ŀ
    r:Ա������r��
    s��������s���ܴ�꣬���s<=0˵��֮ǰ�Ѿ������
    ���أ��ж����ַ���*/
    int profitableSchemes::LC879_profitableSchemes_f2(vector<int>&group,vector<int>&profit,int i,int r,int s,vector<vector<vector<int>>>&dp){
        //���Ѿ��ľ���
        if(r<=0)return s<=0?1:0;
        //�����Ѿ�û��
        if(i==group.size())return s<=0?1:0;
        if(dp[i][r][s]!=-1)return dp[i][r][s];
        //���������
        int p1=LC879_profitableSchemes_f2(group,profit,i+1,r,s,dp);
        //�������
        int p2=0;
        //ʣ�����Ҫ��������ǰ����������
        if(group[i]<=r)p2=LC879_profitableSchemes_f2(group,profit,i+1,r-group[i],max(0,s-profit[i]),dp);
        dp[i][r][s]=(p1+p2)%MOD;
        return dp[i][r][s];
    }
    /// @brief �ϸ�λ������
    /// @param n 
    /// @param minProfit 
    /// @param group 
    /// @param profit 
    /// @return 
    int profitableSchemes::LC879_profitableSchemes3(int n, int minProfit, vector<int>& group, vector<int>& profit){
        int m=group.size();
        vector<vector<int>>dp(n+1,vector<int>(minProfit+1,0));
        //û�й�����ʱ��,��i����߲�
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
    /*LeetCode 688 ��ʿ�������ϵĸ���*/
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
    /*LeetCode 2435 �����к��ܱ�k������·��*/
    int numberOfPaths::LC2435_numberOfPaths(vector<vector<int>>& grid, int k){
        int n=grid.size();
        int m=grid[0].size();
        return LC2435_numberOfPaths_f1(grid,n,m,k,0,0,0);
    }
    /*��ǰ����(i,j)λ�ã�����һ��Ҫ�ߵ����½ǣ���(i,j)���ж�����·��%k�Ľ��������r*/
    int numberOfPaths::LC2435_numberOfPaths_f1(vector<vector<int>>&grid,int n,int m,int k,int i,int j,int r){
        if(i==n-1&&j==m-1)return grid[i][j]%k==r?1:0;

        int need=(k+r-(grid[i][j]%k))%k;
        int ans=0;
        //��������
        if(i+1<n)ans=LC2435_numberOfPaths_f1(grid,n,m,k,i+1,j,need);
        //���ұ���
        if(j+1<m)ans=(ans+LC2435_numberOfPaths_f1(grid,n,m,k,i,j+1,need))%MOD;
        return ans;
    }
    /// @brief ���仯����
    /// @param grid 
    /// @param k 
    /// @return 
    int numberOfPaths::LC2435_numberOfPaths2(vector<vector<int>>& grid, int k){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return LC2435_numberOfPaths_f1(grid,n,m,k,0,0,0);
    }
    /*��ǰ����(i,j)λ�ã�����һ��Ҫ�ߵ����½ǣ���(i,j)���ж�����·��%k�Ľ��������r*/
    int numberOfPaths::LC2435_numberOfPaths_f2(vector<vector<int>>&grid,int n,int m,int k,int i,int j,int r,vector<vector<vector<int>>>&dp){
        if(i==n-1&&j==m-1)return grid[i][j]%k==r?1:0;
        if(dp[i][j][r]!=-1)return dp[i][j][r];
        int need=(k+r-(grid[i][j]%k))%k;
        int ans=0;
        //��������
        if(i+1<n)ans=LC2435_numberOfPaths_f2(grid,n,m,k,i+1,j,need,dp);
        //���ұ���
        if(j+1<m)ans=(ans+LC2435_numberOfPaths_f2(grid,n,m,k,i,j+1,need,dp))%MOD;
        dp[i][j][r]=ans;
        return ans;
    }
    /// @brief �ϸ�λ������
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
    /*LeetCode 87 �����ַ���*/
    bool isScramble::LC87_isScramble(string s1, string s2){
        int n=s1.length();
        return LC87_isScramble_f1(s1,0,n-1,s2,0,n-1);
    }
    /*s1[l1...r1]
    s2[l2...r2]
    ��֤l1...r1��l2...r2�ȳ�
    �ǲ������Ҵ���ϵ*/
    bool isScramble::LC87_isScramble_f1(string&s1,int l1,int r1,string&s2,int l2,int r2){
        //s1ֻʣһ���ַ��ˣ�Ҳ����s2Ҳֻʣһ���ַ���
        if(l1==r1)return s1[l1]==s2[l2];
        //s1[l1..i][i+1...r1]
        //s2[l2..j][j+1...r2]
        for(int i=l1,j=l2;i<r1;i++,j++){
            //������̸�����ҹ�ϵ
            if(LC87_isScramble_f1(s1,l1,i,s2,l2,j)&&LC87_isScramble_f1(s1,i+1,r1,s2,j+1,r2))return true;
        }
        //s1[l1..i][i+1...r1]
        //s2[j..r2][l2...j-1]
        for(int i=l1,j=r2;i<r1;i++,j--){
            //�����������ҹ�ϵ
            if(LC87_isScramble_f1(s1,l1,i,s2,j,r2)&&LC87_isScramble_f1(s1,i+1,r1,s2,l2,j-1))return true;
        }
        return false;
    }
    /// @brief ���仯����
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
    ��֤l1...r1��l2...r2�ȳ�
    �ǲ������Ҵ���ϵ*/
    bool isScramble::LC87_isScramble_f2(string&s1,string&s2,int l1,int l2,int len,vector<vector<vector<int>>>&dp){
        //s1ֻʣһ���ַ��ˣ�Ҳ����s2Ҳֻʣһ���ַ���
        if(len==1)return s1[l1]==s2[l2];
        if(dp[l1][l2][len]!=0)return dp[l1][l2][len]==1;
        //s1[l1...] len��
        //s2[l2...] len��
        //��k��   �ң�len-k��
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
                //�����������ҹ�ϵ
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
            //�߽�������l1<=n-len   l2<=n-len
            for(int l1=0;l1<=n-len;l1++){
                for(int l2=0;l2<=n-len;l2++){
                    //������
                    for(int k=1;k<len;k++){
                        if(dp[l1][l2][k]&&dp[l1+k][l2+k][len-k]){
                            dp[l1][l2][len]=true;
                            break;
                        }
                    }
                    //����
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
//����������ۼӺ�����
namespace TheNumberOfMaxSubArray{
/***********************************************************************/
    /*LeetCoed 53 ����������*/
    int maxsubArray::LC53_maxsubArray1(vector<int>&nums){
        //��i��β����������ۼӺ��Ƕ���
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
            //���ǰ����ۼӺʹ���0����ô�ͼ������ϵ�ǰλ�õ���
            if(pre>=0)pre+=nums[r];
            else{
                //����ӵ�ǰλ�õ������¿�ʼ�ۼ�
                pre=nums[r];
                l=r;
            }
            //�������ۼӺͿ��Ա����£��͸�������ۼӺ�������
            if(pre>sum){
                sum=pre;
                left=l;
                right=r;
            }
        }
        return {left,right,sum};
    }
    int maxsubArray::LC918_maxsubArray3(vector<int>&nums){
        //case 1:����ۼӺ��������ģ�˵��ȡmaxsum����
        //case 2:����ۼӺ��ǲ������ģ�˵��ȡall-minsum����
        //���ȡ�������ۼӺ͡������ۼӺ͡���С���ۼӺ�
        int n=nums.size(),all=nums[0],maxsum=nums[0],minsum=nums[0];
        for(int i=1,maxpre=nums[0],minpre=nums[0];i<n;i++){
            all+=nums[i];
            maxpre=max(nums[i],nums[i]+maxpre);
            maxsum=max(maxsum,maxpre);
            minpre=min(nums[i],nums[i]+minpre);
            minsum=min(minsum,minpre);
        }
        //�����С���ۼӺ;������ۼӺͣ�˵��û��Ϊ����������ۼӺͣ���ֵȡΪ���������ֵ����
        return all==minsum?maxsum:max(maxsum,all-minsum);
    }
    void maxsubArray::Test_LC53_maxsubArray(){
        vector<int>nums;
        cout<<LC53_maxsubArray2(nums)<<endl;
    }
/***********************************************************************/
    /*LeetCode 198 ��ҽ���*/
    int Rob::LC198_rob(vector<int>&nums){
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        //��[0...i]�ϵ�����ۼӺͣ����ڲ���ѡ��
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
        //��[0...i]�ϵ�����ۼӺͣ����ڲ���ѡ��
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

        //��nums���l��ʼ͵��r[l...r]�ڣ��ڲ���͵���ڵ�����£����͵����������
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
        //��1���������͵��0������ô�����͵��[1...n-1]
        //��2�������͵��0������ô����͵��nums[0]+[2....n-2]
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
            //��̬�滮
            function<int(int)>mostRob1=[&nums,n](int ability)->int{
                //����ֵ���˾���͵��������͵����
                if(n==1)return nums[0]<=ability?1:0;
                //ֻҪ��һ����͵�ľ�͵������Ϊ���ڵĲ���͵��
                if(n==2)return (nums[0]<=ability||nums[1]<=ability)?1:0;
                vector<int>dp(n);
                dp[0]=nums[0]<=ability?1:0;
                dp[1]=(nums[0]<=ability||nums[1]<=ability)?1:0;
                for(int i=2;i<n;i++){
                    dp[i]=max(dp[i-1],(nums[i]<=ability?1:0)+dp[i-2]);
                }
                return dp[n-1];
            };
            //�ռ�ѹ��
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
            //̰��(��͵��͵)
            function<int(int)>mostRob3=[&nums,n](int ability)->int{
                int ans=0;
                for(int i=0;i<n;i++){
                    if(nums[i]<=ability){
                        ans++;
                        //͵����������һ��
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
        //������0�е���0�У��ҽ�������0�е���0�е��Ӿ��������ۼӺ�
        //������0�е���1�У��ҽ�������0�е���1�е��Ӿ��������ۼӺ�
        //������0�е���i�У��ҽ�������0�е���i�е��Ӿ��������ۼӺ�
        int n=grid.size();
        int m=grid[0].size();
        int Max=INT_MIN;
        //����ۼӺ͵����Ϻ����µ�����
        int a=0,b=0,c=0,d=0;
        vector<int>nums(m,0);
        //�ӵ�һ�п�ʼ0-0 1-1 2-2�ȵ�
        for(int up=0;up<n;up++){
            //���³�ʼ��nums����
            fill(nums.begin(),nums.end(),0);
            //��ÿһ�п�ʼ���� 0-1 0-2 0-3�ȵ�
            for(int down=up;down<n;down++){
                //��ÿ��ѹ������������ۼӺͣ����Ҹ������Ϻ����µ�����
                for(int l=0,r=0,pre=INT_MIN;r<m;r++){
                    //ѹ��������
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
    /*���������˻�*/
    int maxProduct::LC152_maxProduct(vector<int> &nums){
        //��i��β���������С���۳˻�
        //��i��β������������۳˻�
        //case 1: [i]   case 2: maxdp[i]*[i]    case 3:min[i-1]*[i]
        int ans=nums[0];
        //i:��ǰλ�õ�������mindpǰһ��λ�õ���С�۳˻�mindp[i-1]��maxdpǰһ��λ�õ�����۳˻�maxdp[i-1]
        //curmin:��ǰλ�õ���С�۳˻�   curmax:��ǰλ�õ�����۳˻�
        for(int i=1,mindp=nums[0],maxdp=nums[0],curmin,curmax;i<nums.size();i++){
            //ȡ��С�۳˵ģ�case 1: nums[i]   case 2: mindp[i-1]*nums[i]    case 3:maxdp[i-1]*nums[i]
            curmin=min(nums[i],min(mindp*nums[i],maxdp*nums[i]));
            //ȡ����۳˵ģ�case 1: nums[i]   case 2: maxdp[i-1]*nums[i]    case 3:mindp[i-1]*nums[i]
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
        //��ǰλ�õ���Ҫ���뵱ǰλ�õ�����Ҫ
        return max(maxSum1_f(nums,i+1,s),maxSum1_f(nums,i+1,s+nums[i]));
    }
    int MaxProSub::maxSum2(vector<int> &nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(7));
        //��������ǰ0������ɵ��ۼӺ�%7��������0���ۼӺ�Ϊ0
        dp[0][0]=0;
        //��������ǰ1,2,3,4������ɵ��ۼӺ�%7��������0���ۼӺͲ�����
        for(int j=1;j<7;j++)dp[0][j]=-1;
        for(int i=1,x,cur,need;i<=n;i++){
            //��ǰ����
            x=nums[i-1];
            //��ǰ������
            cur=nums[i-1]%7;
            for(int j=0;j<7;j++){
                dp[i][j]=dp[i-1][j];
                //��Ҫ������
                need=cur<=j?(j-cur):(j-cur+7);
                if(dp[i-1][need]!=-1)dp[i][j]=max(dp[i][j],dp[i-1][need]+x);
            }
        }
        return dp[n][0];
    }
    int MagicReel::maxSum1(vector<int> &nums)
    {
        int n=nums.size();
        //��ʹ�þ���
        int p1=0;
        for(int num:nums)p1+=num;
        //ֻʹ��һ�ξ���
        int p2=maxSum1_f1(nums,0,n-1);
        //ʹ�����ξ���
        int p3=INT_MIN;
        for(int i=1;i<n;i++)p3=max(maxSum1_f1(nums,0,i-1),maxSum1_f1(nums,i,n-1));
        return max(p1,max(p2,p3));
    }
    int MagicReel::maxSum1_f1(vector<int> &nums, int l, int r)
    {
        int ans=INT_MIN;
        //l...r��Χ�ϰ���a...b
        //���a...b��Χ�ڵ����ֶ����0
        //����ʣ�����ֵ��ۼӺ�
        //ö�����п��ܵ�a...b��Χ
        for(int a=l;a<=r;a++){
            for(int b=a;b<=r;b++){
                int curAns=0;
                //ֻ��lλ�õ����ֱ��0.....ֻ��rλ�õ����ֱ��0 
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
        //���1����ȫ��ʹ�þ���
        int p1=0;
        for(int num:nums)p1+=num;

        //prefix[i]:0~i��Χ��һ��Ҫʹ��һ�ξ��������£�0~i��Χ��������ۼӺ��Ƕ��
        vector<int>prefix(n);
        //ÿһ����ǰ׺��
        int sum=nums[0];
        //ÿһ��ǰ׺�͵����ֵ
        int maxpresum=max(0,sum);
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1]+nums[i],maxpresum);
            sum+=nums[i];
            maxpresum=max(maxpresum,sum);
        }
        //���2������ʹ��һ�ξ���
        int p2=prefix[n-1];

        //suffix[i]:��i~n-1��Χ��һ����һ�ξ�������������ۼӺ�Ϊ����
        vector<int>suffix(n);
        sum=nums[0];
        maxpresum=max(0,sum);
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1]+nums[i],maxpresum);
            sum+=nums[i];
            maxpresum=max(maxpresum,sum);
        }
        //���3��ʹ�����ξ���
        int p3=INT_MIN;
        for(int i=1;i<n;i++){
            //0~i-1��
            //i~n-1��
            p3=max(p3,prefix[i-1]+suffix[i]);
        }
        return max(p1,max(p2,p3));
    }
/***********************************************************************/
    vector<int> maxSumOfThreeSubarrays::LC689_maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        //sums[i]:��i��ʼ��k���ȵ��ۼӺ�
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
        //prefix[i]:0~i��Χ�ϣ�����Ϊk��������,ӵ������ۼӺ͵�����������ʲôλ�ÿ�ͷ��
        vector<int>prefix(n,0);
        /*k=3
        pre[0]:0...0�ղ���k��
        pre[1]:0...1�ղ���k��
        pre[2]=0:0...2ֻ��һ��
        pre[3]=pre[i-1],��ǰ������Խ���pk��*/
        for(int l=1,r=k;r<n;l++,r++){
            if(sums[l]>sums[prefix[r-1]])prefix[r]=l;
            else prefix[r]=prefix[r-1];
        }
        //suffix[i]:i~n-1��Χ�ϣ�����Ϊk��������,ӵ������ۼӺ͵�����������ʲôλ�ÿ�ͷ��
        vector<int>suffix(n,0);
        suffix[n-k]=n-k;
        for(int l=n-k-1;l>=0;l--){
            //ά���ֵ�����С���������Ҳ����
            if(sums[l]>=sums[suffix[l+1]])suffix[l]=l;
            else suffix[l]=suffix[l+1];
        }
        //0...i-1   i....j  j+1...n-1
        //��        ��      ��
        int a=0,b=0,c=0,Max=0;
        //ά��i...j��Զ��k����
        for(int p,s,i=k,j=2*k-1,sum;j<n-k;i++,j++){
            //0...i-1       i....j      j+1...n-1
            //��ÿ�ͷp     i��ͷ       ��ÿ�ͷs
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
        //start[i]��i����ͷ������ۼӺ�
        vector<int>start(n);
        start[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            start[i]=nums[i]+max(0,start[i+1]);
        }
        int ans=start[0];
        //�����������i-1��β�����е�����ۼӺ�
        int end=nums[0];
        //MaxEnd:
        //0~i��Χ��
        //�����������0��β����������ۼӺ�
        //�����������1��β����������ۼӺ�
        //�����������2��β����������ۼӺ�
        //...
        //�����������i��β����������ۼӺ�
        //��������У������Ǹ��ۼӺ;���maxEnd
        int maxEnd=nums[0];
        for(int i=1;i<n;i++){
            ans=max(ans,maxEnd+start[i]);
            end=nums[i]+max(0,end);
            maxEnd=max(maxEnd,end);
        }
        //�����κη�ת
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
            //ɾ����iλ�õ���
            vector<int>rest=nums;
            rest.erase(rest.begin()+i);
            //�ҵ�����Ϊk������ۼӺ�������
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
            //�����ǰλ�õ���С�ڵ������������ұߵ�ֵ���ͽ����ұߵ�ֵ����
            while(l<r&&nums[window[r-1]]>=nums[i])r--;
            window[r++]=i;
            sum+=nums[i];
            if(i>=k){
                ans=max(ans,(int)(sum-nums[window[l]]));
                //�������У������������������λ�ù����ˣ��Ӷ����е���
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
        //end[i]��Ŀǰ���г���Ϊi+1�ĵ��������е���С��β
        int n=nums.size();
        vector<int>ends(n);
        int len=0;
        //����Ѱ��С�ڵ���nums[i]������λ�õ���
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
        //dp[i][j]: 1.....i����Ʒ����ѡ��������������j��������£���ѡ�����Ʒ������ܼ�ֵ��
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
        /*��nums�ֳ��������ϣ������������ϸ��Եĺ���������ӽ�0
        Ҳ���Ǵ�nums��ѡ��һЩ����ʹ����Щ���ĺͽӽ�nums�����ܺ�sum��һ��*/

        //����͵�һ��
        int sum=0;
        for(int num:nums)sum+=num;
        int target=sum/2;
        /*dp[i][j]:��ʾ��ǰ0....i������ѡ�������У�ʹ�������еĺͲ�����target,�Ҿ�����*/
        /*1)����ѡ��i��������ôdp[i][j]=dp[i-1][j]
        2)��ѡ��i��������ô��Ҫ��0....i-1���������е�ѡ������Ͳ��ܳ���j-nums[i]��������ڼ���nums[i]����dp[i][j]=dp[i-1][j-nums[i]]+nums[i]*/
        /*�ռ�ѹ��*/
        vector<int>dp(target+1,0);
        //dp[0](dp[0][0]):��ʾû��ʯͷʱ�����к�Ϊ0����������кͣ���0
        for(int num:nums){
            for(int j=target;j>=num;j--){
                dp[j]=max(dp[j],dp[j-num]+num);
            }
        }
        //�����������������ֵ
        return sum-dp[target]-dp[target];
    }
/***********************************************************************/
    vector<int>TopSum::EX_TopSum3(vector<int> &nums,int k)
    {
        //������
        sort(nums.begin(),nums.end());
        //����С����
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
        //�����������ҵ�����
        vector<int>left(n);
        for(int i=0;i<n;i++){
            left[i]=last[s[i]];
            last[s[i]]=i;
        }
        last=vector<int>(256,-1);
        //�����������������
        vector<int>right(n);
        for(int i=n-1;i>=0;i--){
            right[i]=last[s[i]];
            last[s[i]]=i;
        }
        vector<vector<ll>>dp(n,vector<ll>(n,0));
        //��ʼ���Խ���
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
        //pair<�Ƿ�Ϊ������������<�������������Ĵ�С�������е���Сֵ�������е����ֵ>>
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
        //pair<�Ƿ�Ϊ������������<�������������ĺͣ������е���Сֵ�������е����ֵ>>
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
    /*쳲���������*/
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
    /*���Ʊ��*/
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
    /*���뷽��*/
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
    /*���뷽��II*/
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
    /*����II*/
    {
        // using DP_One_dimensional::nthUglyNumber;
        // nthUglyNumber ntr;
        // ntr.Test_LC264_nthUglyNumber();
    }
/***********************************************************************/
    /*��Ч����*/
    {
        // using DP_One_dimensional::longestValidParentheses;
        // longestValidParentheses les;
        // les.Test_LC32_longestValidParentheses();
    }
/***********************************************************************/
    /*�����ַ�����Ψһ�����ַ���*/
    {
        // using DP_One_dimensional::findSubstringInWraproundString;
        // findSubstringInWraproundString fng;
        // fng.Test_LC467_findSubstringInWraproundString();
    }
/***********************************************************************/
    /*��ͬ��������II*/
    {
        // using DP_One_dimensional::distinctSubseqII;
        // distinctSubseqII dis;
        // dis.Test_LC940_distinctSubseqII();
    }
/***********************************************************************/
    /*��С·����*/
    {
        // using DP_Two_dimensional::minPathSum;
        // minPathSum su;
        // su.Test_LC64_minPathSum3();
    }
/***********************************************************************/
    /*��������*/
    {
        // using DP_Two_dimensional::exist;
        // exist est;
        // est.Test_LC79_exist();
    }
/***********************************************************************/
    /*�����������*/
    {
        // using DP_Two_dimensional::longestCommonSubsequence;
        // longestCommonSubsequence lce;
        // lce.Test_LC1143_longestCommonSubsequence();
    }
/***********************************************************************/
    /*�����������*/
    {
        // using DP_Two_dimensional::longestPalindromeSubseq;
        // longestPalindromeSubseq leq;
        // leq.Test_LC516_longestPalindromeSubseq();
    }
/***********************************************************************/
    //���Ƹ߶�����µ������������
    {
        // using DP_Two_dimensional::NodenHeightNotLargerThanm;
        // NodenHeightNotLargerThanm nmN;
        // nmN.Test_Main_Compute();
    }
/***********************************************************************/
    //�����е������·��
    {
        // using DP_Two_dimensional::longestIncreasingPath;
        // longestIncreasingPath loh;
        // loh.Test_LC329_longestIncreasingPath();
    }
/***********************************************************************/
    /*��ͬ��������*/
    {
        // using DP_Two_dimensional::numDistinct;
        // numDistinct nnt;
        // nnt.Test_LC115_numDistinct();
    }
/***********************************************************************/
    /*�༭����*/
    {
        // using DP_Two_dimensional::minDistance;
        // minDistance mce;
        // mce.Test_LC72_minDistance();
    }
/***********************************************************************/
    //�����ַ�
    {
        // using DP_Two_dimensional::isInterleave;
        // isInterleave ive;
        // ive.Test_LC97_isInterleave();
    }
/***********************************************************************/
    /*��ЧͿɫ����*/
    {
        // using DP_Two_dimensional::effectiveColoring;
        // effectiveColoring eig;
        // eig.Test_Ex_effectiveColoring();
    }
/***********************************************************************/
    /*ɾ�����ټ����ַ����Ա����һ���ַ������Ӵ�*/
    {
        // using DP_Two_dimensional::stringChanges;
        // stringChanges ces;
        // ces.Test_EX_stringChanges();
    }
/***********************************************************************/
    /*ÿ��������ȱʧ����С����ֵ*/
    {
        // using DP_Two_dimensional::smallestMissingValueSubtree;
        // smallestMissingValueSubtree ter;
        // ter.Test_LC2003_smallestMissingValueSubtree();
    }
/***********************************************************************/
    /*һ����*/
    {
        // using DP_Three_dimensional::findMaxForm;
        // findMaxForm frm;
        // frm.Test_LC474_findMaxForm();
    }
/***********************************************************************/
    /*ӯ���ƻ�*/
    {
        // using DP_Three_dimensional::profitableSchemes;
        // profitableSchemes pes;
        // pes.Test_LC879_profitableSchemes();
    }
/***********************************************************************/
    /*��ʿ�������ϵĸ���*/
    {
    //    using DP_Three_dimensional:: knightProbability;
    //    knightProbability kty;
    //    kty.Test_LC688_knightProbability();
    }
/***********************************************************************/
    /*�����к��ܱ�k������·��*/
    {
        // using DP_Three_dimensional::numberOfPaths;
        // numberOfPaths numb;
        // numb.Test_LC2435_numberOfPaths();
    }
/***********************************************************************/
    /*�����ַ���*/
    {
        // using DP_Three_dimensional::isScramble;
        // isScramble ile;
        // ile.Test_LC87_isScramble();
    }
/***********************************************************************/
    /*����������ۼӺ�*/
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
cout<<"����ʱ����"<<chrono::duration_cast<chrono::microseconds>(end-statr).count()<<" ms "<<endl;
while(getchar()!='\n')continue;
getchar();
return 0;
}
