#include"SetWindowRgn.h"
using namespace std;
/// @brief LeetCode LCR008 连续最小子数组
/// @param target 
/// @param nums 
/// @return 
int SetWindowRgn::LCR008_minSubArrayLen_(int target,std::vector<int>&nums){
    int res=INT_MAX;
    for(int l=0,r=0,sum=0;r<nums.size();r++){
        sum+=nums[r];
        while(sum-nums[l]>=target){
            sum-=nums[l++];
        }
        if(sum>=target)res=min(res,r-l+1);
    }
    return res==INT_MAX?0:res;
}
void SetWindowRgn::Test_LCR008_minSubArrayLen(){
    //vector<int>nums={2,3,1,2,4,3};
    //cout<<LCR008_minSubArrayLen_(7,nums)<<endl;
    Cleanup cle;
    //随机生成目标值
    vector<int>n=cle.RandVector(10,1,50,10);
    for(int i=0;i<10;i++){
        vector<int>nums=cle.RandVector(10,0,20,i);
        cout<<"target = "<<n[i]<<endl;
        cout<<"数组为：";
        cle.Print(nums);
        cout<<"结果：";
        cout<<LCR008_minSubArrayLen_(n[i],nums)<<endl;
        
    }
}
/// @brief LeetCode LCR016 无重复的最长子串
/// @param s 
/// @return 
int SetWindowRgn::LCR016_lengthOfLongestSubstring_(string s){
    int res=INT_MIN;
    //unordered_set<char>set;
    vector<int>last(256,-1);
    for(int l=0,r=0;r<s.size();r++){
        //while(set.find(s[r])!=set.end()){
        //    set.erase(s[l++]);
        //}
        //set.insert(s[r]);
        l=max(l,last[s[r]]+1);
        res=max(res,r-l+1);
        last[s[r]]=r;
    }
    return res==INT_MIN?0:res;
}
void SetWindowRgn::Test_LCR016_lengthOfLongestSubstring(){
    //string s="abcabcbb";
    //cout<<LCR016_lengthOfLongestSubstring_(s)<<endl;
    Cleanup cle;
    for(int i=0;i<10;i++){
        string s=cle.RandStringa(100,'a','y',i);
        cout<<"测试字符串为："<<s<<endl;
        cout<<"结果为："<<LCR016_lengthOfLongestSubstring_(s)<<endl;
    }
}
/// @brief LeetCode LCR017 最小覆盖子串
/// @param s 
/// @param t 
/// @return 
string SetWindowRgn::LCR017_minWindow_(string s,string t){
    if(s.size()<t.size())return "";
    int res=INT_MAX;
    //unordered_map<char,int>map;
    //for(char c:t)map[c]--;
    vector<int>map(256,0);
    for(char c:t)map[c]--;
    int t_size=t.size();
    int start=0;//最小覆盖子串的起始点
    for(int l=0,r=0;r<s.size();r++){
        if(map[s[r]]++<0){//如果当前的字符是要找的字符
            //就将次字符计数+1
            //总字符计数-1
            t_size--;
        }
        if(t_size==0){//如果总字符计数为0，说明找完了，开始判断是否可以缩小边界
            while(map[s[l]]>0){//如果最左边的不是要找的，就减去且缩小边界
                map[s[l++]]--;
            }
            if(r-l+1<res){//如果答案可以更小，就更新最小值
                res=r-l+1;
                start=l;
            }
        }
    }
    return res==INT_MAX?"":s.substr(start,res);
}
void SetWindowRgn::Test_LCR017_minWindow(){
    //vector<string>str={"ADOBECODEBANC","ABC",""};
    //str[2]=LCR017_minWindow_(str[0],str[1]);
    //cout<<str[2]<<endl;
    Cleanup cle;
    for(int i=0;i<10;i++){
        string s=cle.RandStringA(15,'A','F',i);
        cout<<"原字符串为："<<s<<endl;
        cout<<"字符串s为："<<s.substr(0,12)<<endl;
        cout<<"字符串t为："<<s.substr(11,3)<<endl;
        cout<<"结果为："<<LCR017_minWindow_(s.substr(0,12),s.substr(11,3))<<endl;
    }
}
/// @brief LeetCode 134 加油站
/// @param gas 
/// @param cost 
/// @return 
int SetWindowRgn::LC134_canCompleteCircuit_(vector<int>& gas, vector<int>& cost){
    for(int l=0,r=0,sum=0,len=0;l<gas.size();l++){
        while(sum>=0){
            //当前窗口累加和>=0，尝试扩
            if(len==gas.size()){//当前l位置可以转一周
                return l;
            }
            //开始扩
            r=(l+(len++))%gas.size();
            //改变总油量
            sum+=gas[r]-cost[r];
        }
        //超过了就退出
        len--;
        //返还油量
        sum-=gas[l]-cost[l];
    }
    return -1;
}
void SetWindowRgn::Test_LC134_canCompleteCircuit(){
    int k=10;
    for(int i=0;i<k;i++){
        Cleanup Rand;
        vector<int>G1=Rand.RandVector(11,3,11,i);
        vector<int>G2=Rand.RandVector(11,5,9,i);
        //vector<int>F1={1,2,3,4,5};
        //vector<int>F2={1,3,1,5,0};
        //cout<<LC134_canCompleteCircuit_(F1,F2)<<endl;
        cout<<"生成的路线为：         "<<endl;
        Rand.Print(G1);
        cout<<"生成的路线对应的花费为："<<endl;
        Rand.Print(G2);
        cout<<"结果为：               "<<endl;
        cout<<LC134_canCompleteCircuit_(G1,G2)<<endl;
        cout<<endl;
    }
}
/// @brief LeetCode 1234 平衡子串
/// @param s 
/// @return 
int SetWindowRgn::LC1234_balancedString_(string s){
    vector<int>num_s(s.size());
    vector<int>cnts(4);
    //词频统计，映射QWER这四个字符到1234
    for(int i=0;i<s.size();i++){
        num_s[i]=s[i]=='R'?3:(s[i]=='E'?2:(s[i]=='W'?1:0));
        cnts[num_s[i]]++;
    }
    int require=s.size()/4;
    int ans=s.size();
    for(int l=0,r=0;l<s.size();l++){
        while(!LC1234_Ok_(cnts,r-l,require)&&r<s.size()){
            cnts[num_s[r++]]--;
        }
        if(LC1234_Ok_(cnts,r-l,require)){
            ans=min(ans,r-l);
        }
        cnts[num_s[l]]++;
    }
    return ans;
}
bool SetWindowRgn::LC1234_Ok_(vector<int>cnts,int len,int require){
    for(int i=0;i<4;i++){
        if(cnts[i]>require)return false;
        len-=require-cnts[i];
    }
    return len==0;
}
void SetWindowRgn::LC1234_Sub_(std::string&s){
    for(char&c:s){
        switch (c)
        {
        case 'A':c='Q';
            break;
        case 'B':c='W';
            break;
        case 'C':c='E';
            break;
        case 'D':c='R';
            break;
        
        default:
            break;
        }
    }
}
void SetWindowRgn::Test_LC1234_LC1234_balancedString(){
    //cout<<LC1234_balancedString_("QQQW")<<endl;
    int baseNum=4;
    Cleanup cle;
    for(int i=0;i<10;i++){
        string s=cle.RandStringA(baseNum*21,'A','D',i);
        LC1234_Sub_(s);
        cout<<"生成的随机测试字符串为："<<s<<endl;
        cout<<"结果值为："<<LC1234_balancedString_(s)<<endl;
    }
}
/// @brief LeetCode 992 k个不同的子数组
/// @param nums 
/// @param k 
/// @return 
int SetWindowRgn::LC992_subarraysWithKDistinct_(std::vector<int>&nums,int k){
    return LC992_findkinds_(nums,k)-LC992_findkinds_(nums,k-1);
}

int SetWindowRgn::LC992_findkinds_(std::vector<int>&nums,int k){
    int n=nums.size();
    unordered_map<int,int>cnts;
    int count=0;
    for(int l=0,r=0,collect=0;r<n;r++){
        //如果当前数的频次＋1后为1，则是一个新的数，数的种类就+1
        if(++cnts[nums[r]]==1)collect++;
        //当数的种类大于3时，则需要缩小左边界
        while(collect>k){
            //如果当前的数被吐出后此数的频次为0，说明数的种类减少了
            if(--cnts[nums[l++]]==0)collect--;
        }
        //到这一步时以r结尾的数的种类符合标准，记录以r结尾的数的种类的子数组的个数
        //此个数为当前数的右索引-左索引+1
        //例如统计以3结尾的0~3的子数组个数则有
        //0~3 1~3 2~3 3~3
        count+=r-l+1;
    }
    return count;
}
void SetWindowRgn::Test_LC992_subarraysWithKDistinct(){
    //vector<int>nums={1,2,1,2,3};
    //cout<<LC992_subarraysWithKDistinct_(nums,2)<<endl;
    Cleanup cle;
    vector<int>n=cle.RandVector(10,1,3,10);
    for(int i=0;i<10;i++){
        vector<int>nums=cle.RandVector(5,1,3,i);
        cout<<"生成的目标整数："<<n[i]<<endl;
        cout<<"生成的测试数组：";
        cle.Print(nums);
        cout<<"结果为："<<LC992_subarraysWithKDistinct_(nums,n[i])<<endl;
    }
}
/// @brief 至少有 K 个重复字符的最长子串
/// @param s 
/// @param k 
/// @return 
int SetWindowRgn::LC395_longestSubstring_(string s,int k){
        int ans=0;
        unordered_map<char,int>map;
        for(char c:s)map[c]++;
        int n=map.size();
        //reaurie 当前要求的种类数
        for(int require=1;require<=n;require++){
            //collect 当前字符的种类数
            //satify 当前窗口内的达标的数量
            vector<int>cnts(26,0);
            for(int l=0,r=0,collect=0,satify=0;r<s.size();r++){
                cnts[(int)(s[r]-'a')]++;
                if(cnts[(int)(s[r]-'a')]==1)collect++;
                if(cnts[(int)(s[r]-'a')]==k)satify++;
                while(collect>require){
                    //如果当前字符在减之前为1,就将种类数减一
                    if(cnts[(int)(s[l]-'a')]==1)collect--;
                    //如果当前字符在减之前频次是达标的，就将达标数减1
                    if(cnts[(int)(s[l]-'a')]==k)satify--;
                    //减去当前字符的频次
                    cnts[(int)(s[l++]-'a')]--;
                }
                //如果达标就记录计数
                if(satify==require)ans=max(ans,r-l+1);
            }
        }
        return ans;
    }
void SetWindowRgn::Test_LC395_longestSubstring(){
    //string s="ababbc";
    //cout<<LC395_longestSubstring_(s,2)<<endl;
    Cleanup cle;
    vector<int>n=cle.RandVector(10,1,5,10);
    for(int i=0;i<10;i++){
        string s=cle.RandStringa(5,'a','c',i);
        cout<<"生成的目标整数为："<<n[i]<<endl;
        cout<<"生成的目标字符串为： "<<s<<endl;
        cout<<"结果为："<<LC395_longestSubstring_(s,n[i])<<endl;
    }
}



int main(int argc,char*argv[]){
    chrono::_V2::system_clock::time_point start=chrono::system_clock::now();

    SetWindowRgn set;
    set.Test_LC395_longestSubstring();

    chrono::_V2::system_clock::time_point end=chrono::system_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(end-start);
    cout<<"共花费："<<duration.count()<<" ms "<<endl;

    while(getchar()!='\n')continue;
    getchar();
    return 0;
}