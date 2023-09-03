#include"SetWindowRgn.h"
using namespace std;

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
    vector<int>nums={2,3,1,2,4,3};
    cout<<LCR008_minSubArrayLen_(7,nums)<<endl;
}

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
    string s="abcabcbb";
    cout<<LCR016_lengthOfLongestSubstring_(s)<<endl;
}
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
    vector<string>str={"ADOBECODEBANC","ABC",""};
    str[2]=LCR017_minWindow_(str[0],str[1]);
    cout<<str[2]<<endl;
}
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
    vector<vector<int>>G_C={{1,2,3,4,5},{3,4,5,1,2}};
    cout<<LC134_canCompleteCircuit_(G_C[0],G_C[1])<<endl;
}



int main(int argc,char*argv[]){
    SetWindowRgn set;
    set.Test_LC134_canCompleteCircuit();


    while(getchar()!='\n')continue;
    getchar();
    return 0;
}