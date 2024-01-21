#include"DestinationArray.h"
using namespace std;

int DestinationArray::NumberPatternSymbol_(int num){
    /*
    1.将数字转化为单个数字存入数组中
    3.将数组中的元素转化为一个数字
    */
    /*边界
    1.数组索引越界
    2.数值溢出：返回0
    3.首位不为0
    4.符号处理
    */
    int t_num=num;
    vector<int>nums;
    while(t_num){
        nums.push_back(t_num%10);
        t_num/=10;
    }
    long result=0;
    for(int n:nums){
        result+=n;
        result*=10;
    }
    if(result>INT_MAX||result<INT_MIN)return 0;
    else return (int)result;
}
void DestinationArray::TestNumberPatternSymbol(){
    cout<<NumberPatternSymbol_(12346)<<endl;
}

string DestinationArray::longestPalindrome_(string s){
    /*1.删除一个元素看看除这个元素之外的剩下的元素是否可以组成回文
    2.判断回文可以从两端开始检测
    3.使用字符串来记录这个回文子串*/
    string res;
    for(int i=0;i<s.size();i++){
        res=longestPalindrome_fll_(s,i);
        if(res.size()!=0)return res;
    }
    return res;
}
string DestinationArray::longestPalindrome_fll_(string s,int n){
    string res;
    /*n为要删除的元素个数
    分别从头删除和从尾删除*/
    int left=0;
    int right=n;
    while(left<=n){
        bool flag=1;
        for(int l=left,r=s.size()-1-right;l<=r;l++,r--){
            if(s[l]!=s[r]){
                flag=0;
                break;
            }
        }
        if(flag){
            res=s.substr(left,s.size()-n);
            return res;
        }
        left++;
        right--;
    }
    return res;
}
void DestinationArray::TestlongestPalindrome(){
    string s={"badad"};
    cout<<longestPalindrome_(s)<<endl;
}

long long DestinationArray::WaysToBuyPensPencils_(int total,int cost1,int cost2){
        //动态规划
        //dp[i]来记录买i支钢笔的时候还可以买的铅笔数
        //dp[i]=j+1;
        //先看最多能买几次钢笔
        int penNum=total/cost1;
        vector<int>dp(penNum+1);
        for(int i=0;i<=penNum;i++){
            int c_total=total-i*cost1;
            //用买i次钢笔的剩余的钱去买铅笔
            dp[i]=c_total/cost2+1;
        }
        int result=0;
        for(int i=0;i<penNum;i++)result+=dp[i];

        return result;
}
void DestinationArray::TestWaysToBuyPensPencils(){
    cout<<WaysToBuyPensPencils_(20,10,5)<<endl;
}
int DestinationArray::captureForts_(vector<int>& forts) {
    //当遇见空时将城堡摧毁数设置为有效值
    //每经过一个空城堡就记录这个有效值
    int is_fot=forts[0];
    //记录最多摧毁数
    int result=0;
    //记录摧毁数
    int count=0;
    //记录出发点
    int index=-1;
    for(int i=0;i<forts.size();i++){
        if(forts[i]==1||forts[i]==-1){
            is_fot=forts[i];
            index=i;
            break;
        }
    }
    if(index==-1)return 0;
    for(int i=index+1;i<forts.size();i++){
        if(forts[i]==1&&is_fot==-1){
            result=max(result,count);
            is_fot=1;
            count=0;
        }else if(forts[i]==-1&&is_fot==1){
            result=max(result,count);
            is_fot=-1;
            count=0;
        }else count++;
    }

    return result;
}
void DestinationArray::TestCaptureForts(){
    vector<int>fotes={1,0,0,-1,0,0,0,0,1};
    cout<<captureForts_(fotes)<<endl;
}


int main(int argc,char*argv[]){
    DestinationArray tes;
    tes.TestCaptureForts();

    while(getchar()!='\n')continue;
    getchar();
    return 0;
}