#include"Recursion.h"
using namespace std;
/// @brief 字符串的全部子序列
/// @param str 
/// @return 
vector<string> Recursion::generatePermutation_(string str){
    char path[str.size()];
    unordered_set<string>set;
    generatePermutation_f1_(str,0,path,0,set);
    vector<string>ans(set.size());
    int i=0;
    for(auto&s:set){
        ans[i++]=s;
    }
    return ans;
}
void Recursion::generatePermutation_f1_(string s,int i,string&path,unordered_set<string>&set){
    if(i==s.length()){
        set.insert(path);
    }else{
        path+=s[i];
        generatePermutation_f1_(s,i+1,path,set);
        path.pop_back();
        generatePermutation_f1_(s,i+1,path,set);
    }
}
void Recursion::generatePermutation_f1_(string s,int i,char path[],int size,unordered_set<string>&set){
    if(i==s.length()){
        string temp;
        for(int i=0;i<=size;i++){
            temp+=path[i];
        }
        set.insert(temp);
    }else{
        path[size]=s[i];
        generatePermutation_f1_(s,i+1,path,size+1,set);
        generatePermutation_f1_(s,i+1,path,size,set);
    }
}
void Recursion::Test_generatePermutation(){
    Cleanup cle;
    string str=cle.RandStringa(3,'a','z',20);
    cout<<"生成的字符串为："<<str<<endl;
    for(string s:generatePermutation_(str)){
        cout<<s<<" ";
    }
    cout<<endl;
}

/// @brief LeetCode 90 子集II
/// @param nums 
/// @return 
vector<vector<int>>Recursion::subsetsWithDup_(vector<int>&nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    vector<int>path(nums.size());
    subsetsWithDup_f1_(nums,0,path,0,ans);
    return ans;
}
void Recursion::subsetsWithDup_f1_(vector<int>&nums,int i,vector<int>&path,int size,vector<vector<int>>&ans){
    if(i==path.size()){
        vector<int>cur;
        for(int j=0;j<size;j++)cur.push_back(path[j]);
        ans.push_back(cur);
    }else{
        int j=i+1;
        while(j<nums.size()&&nums[i]==nums[j])j++;
        subsetsWithDup_f1_(nums,j,path,size,ans);
        for(;i<j;i++){
            path[size++]=nums[i];
            subsetsWithDup_f1_(nums,j,path,size,ans);
        }
    }
}
void Recursion::Test_LC90_subsetsWithDup(){
    Cleanup cle;
    vector<int>nums=cle.RandVector(5,0,10,10);
    cle.Print(nums);
    for(auto num:subsetsWithDup_(nums)){
        cle.Print(num);
    }
}

/// @brief LeetCode 46 全排列
/// @param nums 
/// @return 
vector<vector<int>>Recursion::LC46_permute_(vector<int>&nums){
    vector<vector<int>>ans;
    LC46_premute_f_(nums,0,ans);
    return ans;
}
void Recursion::LC46_premute_f_(vector<int>&nums,int index,vector<vector<int>>&ans){
    if(index==nums.size()){
        ans.push_back(nums);
    }else{
        unordered_set<int>set;
        for(int j=index;j<nums.size();j++){
            if(!set.count(nums[j])){
                set.insert(nums[j]);
                Swap(nums,index,j);
                LC46_premute_f_(nums,index+1,ans);
                Swap(nums,index,j);
            }
            
        }
    }
}
void Recursion::Swap(vector<int>&nums,int i1,int i2){
    int temp=nums[i1];
    nums[i1]=nums[i2];
    nums[i2]=temp;
}
void Recursion::Test_LC46_permute(){
    Cleanup cle;
    vector<int>nums={1,1,3};
    for(auto&num:LC46_permute_(nums))cle.Print(num);
}

/// @brief 逆序栈方法
/// @param stk 
void Recursion::Reverse_Stack_(stack<int>&stk){
    if(stk.empty()){
        return;
    }else{
        int num=BottomOut_Stack_(stk);
        Reverse_Stack_(stk);
        stk.push(num);
    }
}
int Recursion::BottomOut_Stack_(stack<int>&stk){
    int ans=stk.top();
    stk.pop();
    if(stk.empty()){
        return ans;
    }else{
        int last=BottomOut_Stack_(stk);
        stk.push(ans);
        return last;
    }
}
void Recursion::Test_Reverse_Stack_(){
    stack<int>stk;
    vector<int>nums={1,2,3};
    for(int num:nums)stk.push(num);
    cout<<endl;
    Reverse_Stack_(stk);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}

/// @brief 排序栈中的元素 
/// @param stk 
void Recursion::Sort_Stack_(stack<int>&stk){
    int deep=Deep_Stack_(stk);
    while(deep){
        int Max=Max_Stack_(stk,deep);
        int times=Times_Max_Stack_(stk,deep,Max);
        Down_Max_Stack_(stk,deep,Max,times);
        deep-=times;
    }
}
int Recursion::Deep_Stack_(stack<int>stk){
    if(stk.empty())return 0;
    else{
        int num=stk.top();
        stk.pop();
        int deep=Deep_Stack_(stk)+1;
        stk.push(num);
        return deep;
    }
}
int Recursion::Max_Stack_(stack<int> stk,int deep){
    deep-=1;
    int num1=stk.top();
    stk.pop();
    if(deep==0){
        stk.push(num1);
        return num1;
    }else{
        int num2=Max_Stack_(stk,deep);
        num2=num2>num1?num2:num1;
        stk.push(num1);
        return num2;
    }
}
int Recursion::Times_Max_Stack_(stack<int>stk,int deep,int Max_num){
    deep-=1;
    int num=stk.top();
    stk.pop();
    if(deep==0){
        stk.push(num);
        return num==Max_num?1:0;
    }else{
        int times=Times_Max_Stack_(stk,deep,Max_num);
        stk.push(num);
        return num==Max_num?times+1:times;
    }
}
void Recursion::Down_Max_Stack_(stack<int>&stk,int deep,int Max_num,int times){
    if(deep==0){
        for(;times>0;times--){
            stk.push(Max_num);
        }
    }else{
        int num=stk.top();
        stk.pop();
        Down_Max_Stack_(stk,deep-1,Max_num,times);
        if(num!=Max_num)stk.push(num);
    }
}
void Recursion::Test_Sort_Stack(){
    stack<int>stk;
    Cleanup cle;
    vector<int>nums=cle.RandVector(20,-10,55,10);
    //vector<int>nums={10,6,7,9,9,2,8,8,10,9};
    cle.Print(nums);
    for(int num:nums)stk.push(num);
    Sort_Stack_(stk);
    while(!stk.empty()){
        int num=stk.top();
        cout<<num<<" ";
        stk.pop();
    }
}

/// @brief 汉诺塔
/// @param i 
/// @param from 
/// @param to 
/// @param other 
void Recursion::HanNi_f_(int i,string from,string to,string other){
    if(i==1){
        cout<<"移动圆盘1从 "<<from<<"到"<<to<<endl;
    }else{
        HanNi_f_(i-1,from,other,to);
        cout<<"移动圆盘"<<i<<"从 "<<from<<"到"<<to<<endl;
        HanNi_f_(i-1,other,to,from);
    }
}
void Recursion::HanNi_f_(int n,vector<int>&A,vector<int>&B,vector<int>&C){
        if(n==1){
            C.push_back(A.back());
            A.pop_back();
        }else{
            HanNi_f_(n-1,A,C,B);
            C.push_back(A.back());
            A.pop_back();
            HanNi_f_(n-1,B,A,C);
        }
}
void Recursion::HanNo_(int n){
    vector<int>A={2,1,0};
    vector<int>B;
    vector<int>C;
    HanNi_f_(A.size(),A,B,C);
    Cleanup cle;
    cle.Print(C);
}
void Recursion::Test_HanNi(){
    HanNo_(4);
}

/// @brief LeetCode 772 计算器的基础实现
/// @param str 
/// @return 
int Recursion::LC772_Plus_Calculate_(string str){
    LC772_where=0;
    return LC772_Plus_Calculate_f_(str,0);
}
int Recursion::LC772_Plus_Calculate_f_(string s,int i){
    int cur=0;
    stack<int>nums;
    stack<char>ops;
    while(i<s.size()&&s[i]!=')'){
        if(s[i]>='0'&&s[i]<='9'){
            cur=cur*10+(s[i++]-'0');
        }else if(s[i]!='('){
            LC772_Plus_Push_(nums,ops,cur,s[i++]);
            cur=0;
        }else{
            cur=LC772_Plus_Calculate_f_(s,i+1);
            i=LC772_where+1;
        }
    }   
    LC772_Plus_Push_(nums,ops,cur,'+');
    LC772_where=i;
    return LC772_Plus_Compute_(nums,ops);
}
void Recursion::LC772_Plus_Push_(stack<int>&nums,stack<char>&ops,int cur,char op){
    if(ops.empty()||ops.top()=='+'||ops.top()=='-'){
        nums.push(cur);
        ops.push(op);
    }else{
        int num=nums.top();
        nums.pop();
        char num_op=ops.top();
        ops.pop();
        if(num_op=='*')nums.push(num*cur);
        else nums.push(num/cur);
        ops.push(op);
    }
}
int Recursion::LC772_Plus_Compute_(stack<int>&nums,stack<char>&ops){
    ops.pop();
    while(!ops.empty()){
        int num2=nums.top();
        nums.pop();
        int num1=nums.top();
        nums.pop();
        char op=ops.top();
        ops.pop();
        if(op=='+')nums.push(num1+num2);
        else nums.push(num1-num2);
    }
    int num=nums.top();
    nums.pop();
    return num;
}
void Recursion::Test_LC772_Plus_Calculate(){
    cout<<LC772_Plus_Calculate_("2*(5+5*2)/3+(6/2+8)")<<endl;
}

/// @brief LeetCode 394 字符串解码
/// @param s 
/// @return 
string Recursion::LC394_decodeString_(string s){
    return LC394_decodeString_f_(s,0);
}
string Recursion::LC394_decodeString_f_(std::string s,int i){
    int cur=0;
    string sc;
    while(i<s.size()&&s[i]!=']'){
        if(s[i]>='0'&&s[i]<='9'){
            cur=cur*10+(s[i++]-'0');
        }else if(s[i]!='['){
            sc+=s[i++];
        }else{
            string tep=LC394_decodeString_f_(s,i+1);
            i=LC394_where+1;
            sc+=LC394_Push_(cur,tep);
            cur=0;
        }
    }
    LC394_where=i;
    return sc;
}
string Recursion::LC394_Push_(int cur,string ch){
    string s;
    for(;cur>0;cur--){
        s+=ch;
    }
    return s;
}
void Recursion::Test_LC394_decodeString_(){
    cout<<LC394_decodeString_("abc3[cd]xyz")<<endl;
}

/// @brief LeetCode 726 原子的数量
/// @param formula 
/// @return 
string Recursion::LC726_countOfAtoms_(string formula){
    unordered_map<string,int>map=LC726_countOfAtoms_f_(formula,0);
    vector<string>ns;
    for(auto&m:map)ns.push_back(m.first);
    sort(ns.begin(),ns.end());
    string ans;
    for(auto n:ns){
        if(map[n]==1)ans+=n;
        else ans+=n+to_string(map[n]);
    }
    return ans;
}
unordered_map<string,int>Recursion::LC726_countOfAtoms_f_(string str,int i){
    unordered_map<string,int>ans;
    string name;
    unordered_map<string,int>pre;
    int cur=0;
    while(i<str.size()&&str[i]!=')'){
        if((str[i]>='A'&&str[i]<='Z')||str[i]=='('){
            LC726_countOfAtoms_fill_(ans,name,pre,cur);
            name.clear();
            cur=0;
            pre.clear();
            if(str[i]>='A'&&str[i]<='Z'){
                name+=str[i++];
            }else{
                pre=LC726_countOfAtoms_f_(str,i+1);
                i=LC726_where+1;
            }
        }else if(str[i]>='a'&&str[i]<='z'){
            name+=str[i++];
        }else{
            cur=cur*10+(str[i++]-'0');
        }
    }
    LC726_countOfAtoms_fill_(ans,name,pre,cur);
    LC726_where=i;
    return ans;
}
void Recursion::LC726_countOfAtoms_fill_(unordered_map<string,int>&ans,string name,unordered_map<string,int>&pre,int cur){
    if(pre.size()!=0||name.size()!=0){
        cur=cur==0?1:cur;
        if(name.size()!=0){
            ans[name]+=cur;
        }else{
            for(auto&key:pre){
                ans[key.first]+=key.second*cur;
            }
        }
    }
}
void Recursion::Test_LC726_countOfAtoms_(){
    cout<<LC726_countOfAtoms_("Mg(OH)2")<<endl;
}

/// @brief LeetCode 52 N皇后
/// @param n 
/// @return 
int Recursion::LC52_totalNQueens_(int n){
    if(n<1)return 0;
    vector<int>path(n);
    return LC52_totalNQueens_f_(0,path,n);
}
int Recursion::LC52_totalNQueens2_(int n){
    if(n<1)return 0;
    //n==5
    //limit=10000-1=011111
    int limit=(1<<n)-1;
    return LC52_totalNQueens_f_(limit,0,0,0);
}
int Recursion::LC52_totalNQueens_f_(int i,vector<int>&path,int n){
    if(i==n)return 1;
    int ans=0;
    for(int j=0;j<n;j++){
        if(LC52_check_(path,i,j)){
             path[i]=j;
            ans+=LC52_totalNQueens_f_(i+1,path,n);
        }
    }
    return ans;
}
int Recursion::LC52_totalNQueens_f_(int limit,int col,int left,int right){
    //col=11111==limit=11111，说明皇后放完了
    if(col==limit)return 1;
    //总限制
    int ban=col|left|right;
    //这个限制能在有效的范围内表现出来
    int candidate=limit&(~ban);
    //放置皇后的尝试
    int place=0;
    //方法数
    int ans=0;
    while(candidate!=0){
        //提取最右侧的1(这个1可以放皇后)
        place=candidate&(-candidate);
        //消掉这个1(已经放了皇后)
        candidate^=place;
        ans+=LC52_totalNQueens_f_(limit,col|place,(left|place)>>1,(right|place)<<1);
    }
    return ans;

}
bool Recursion::LC52_check_(vector<int>&path,int i,int j){
    for(int k=0;k<i;k++){
        //在同一列，或者在同一对角线
        if(j==path[k]||(abs(k-i)==abs(path[k]-j)))return false;
    }
    return true;
}
void Recursion::Test_LC52_totalNQueens_(){
    cout<<LC52_totalNQueens2_(16)<<endl;
}

//最大公约数
void Recursion::Test_GreatestCommonDivisor(){
    cout<<Lcm(50,30)<<endl;
}

/// @brief 第N个神奇的数字
/// @param n 
/// @param a 
/// @param b 
/// @return 
int Recursion::LC878_nthMagicalNumber_(int n,int a,int b){
    long lcm=Lcm(a,b);
    long ans=0;
    for(long l=0,r=(long)n*min(a,b),m=0;l<=r;){
        m=l+((r-l)>>1);
        if(m/a+m/b-m/lcm>=n){
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    return (int)(ans%1000000007);
}
void Recursion::Test_LC878_nthMagicalNumber(){
    cout<<LC878_nthMagicalNumber_(1,2,3)<<endl;
}

/// @brief 装苹果
/// @param apple 
/// @return 
int Recursion::AppleMinBags_(int apple){
    int ans=AppleMinBags_f_(apple);
    return ans==INT_MAX?-1:ans;
}
int Recursion::AppleMinBags_f_(int apple){
    if(apple<0)return INT_MAX;
    if(apple==0)return 0;
    int p1=AppleMinBags_f_(apple-8);
    int p2=AppleMinBags_f_(apple-6);
    p1+=p1==INT_MAX?0:1;
    p2+=p2==INT_MAX?0:1;
    return min(p1,p2);
}
int  Recursion::AppleMinBags_f2_(int apple){
    //任何二进制奇数在第0位都有1，
    //任何二进制偶数在第0位都没有1
    if((apple&1)!=0)return -1;
    if(apple<18){
        if(apple==0)return 0;
        else if(apple==6||apple==8)return 1;
        else if(apple==12||apple==14||apple==16)return 2;
        else return -1;
    }
    //每8个割一次奇偶就会有值，每8个一组
    return (apple-18)/8+3;
}
void Recursion::Test_AppleMinBags(){
    for(int i=1;i<100;i++){
        cout<<i<<" : "<<AppleMinBags_f2_(i)<<endl;
    }
}

/// @brief A与B轮流吃草谁会赢
/// @param n 
/// @return 
string Recursion::EatGrass_win1_(int n){
    return EatGrass_win1_f2_(n,"A");
}
string Recursion::EatGrass_win1_f1_(int rest,string cur){
    string enemy=cur=="A"?"B":"A";
    if(rest<5){
        return (rest==0||rest==2)?enemy:cur;
    }
    //rest>=5
    int pick=1;
    while(pick<=rest){
        if(EatGrass_win1_f1_(rest-pick,enemy)==cur)return cur;
        pick*=4;
    }
    return enemy;
}
string Recursion::EatGrass_win1_f2_(int rest,string cur){
    if(rest%5==0||rest%5==2)return "B";
    return "A";
}
void Recursion::Test_EatGrass_win1(){
    for(int i=0;i<50;i++){
        cout<<i<<" : "<<EatGrass_win1_(i)<<endl;
    }
}

/// @brief 判断一个数是否是若干数的连续正整数和
/// @param num 
/// @return 
bool Recursion::IsSumOfConsecutiveNumbers_is1_(int num){
    for(int start=1,sum=0;start<=num;start++){
        sum=start;
        for(int j=start+1;j<=num;j++){
            if(sum+j>num)break;
            if(sum+j==num)return true;
            sum+=j;
        }
    }
    return false;
}
bool Recursion::IsSumOfConsecutiveNumbers_is2_(int num){
    return (num&(num-1))!=0;
}
void Recursion::Test_IsSumOfConsecutiveNumbers(){
    for(int i=1;i<200;i++){
        int ans=IsSumOfConsecutiveNumbers_is2_(i);
        cout<<i<<" : "<<ans<<endl;
    }
}

/// @brief 字符串中有多少个好串
/// @param n 
/// @return 
int Recursion::RedPalindromeGoodStrings_num1(int n){
    string path;
    return RedPalindromeGoodStrings_num1_f(path,0,n);
}
int Recursion::RedPalindromeGoodStrings_num2(int n){
    if(n==1)return 0;
    if(n==2)return 3;
    if(n==3)return 18;
    return (int)(((long)6*(n+1))%1000000007);
}
int Recursion::RedPalindromeGoodStrings_num1_f(string path,int i,int n){
    if(i==n){
        int cnt=0;
        for(int l=0;l<path.size();l++){
            for(int r=l+1;r<path.size();r++){
                if(RedPalindromeGoodStrings_num1_is_(path,l,r))cnt++;
                if(cnt>1)return 0;
            }
        }
        return cnt==1?1:0;
    }else{
        int ans=0;
        path+='r';
        ans+=RedPalindromeGoodStrings_num1_f(path,i+1,n);
        path.pop_back();
        path+='e';
        ans+=RedPalindromeGoodStrings_num1_f(path,i+1,n);
        path.pop_back();
        path+='d';
        ans+=RedPalindromeGoodStrings_num1_f(path,i+1,n);
        path.pop_back();
        return ans;
    }

}
bool Recursion::RedPalindromeGoodStrings_num1_is_(string path,int left,int right){
    while(left<right){
        if(path[left]!=path[right])return false;
        left++;
        right--;
    }
    return true;
}
void Recursion::Test_RedPalindromeGoodStrings_num1(){
    for(int i=1;i<16;i++){
        cout<<i<<" : "<<RedPalindromeGoodStrings_num2(i)<<endl;
    }
}

int main(int argc,char*argv[]){
    auto start=chrono::system_clock::now();
    Recursion rec;
    rec.Test_RedPalindromeGoodStrings_num1();

    auto end=chrono::system_clock::now();
    cout<<"共花费："<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<" ms "<<endl;

    while(getchar()!='\n')continue;
    getchar();
    return 0;
}