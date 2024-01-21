#include"DestinationArray.h"
using namespace std;

int DestinationArray::NumberPatternSymbol_(int num){
    /*
    1.������ת��Ϊ�������ִ���������
    3.�������е�Ԫ��ת��Ϊһ������
    */
    /*�߽�
    1.��������Խ��
    2.��ֵ���������0
    3.��λ��Ϊ0
    4.���Ŵ���
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
    /*1.ɾ��һ��Ԫ�ؿ��������Ԫ��֮���ʣ�µ�Ԫ���Ƿ������ɻ���
    2.�жϻ��Ŀ��Դ����˿�ʼ���
    3.ʹ���ַ�������¼��������Ӵ�*/
    string res;
    for(int i=0;i<s.size();i++){
        res=longestPalindrome_fll_(s,i);
        if(res.size()!=0)return res;
    }
    return res;
}
string DestinationArray::longestPalindrome_fll_(string s,int n){
    string res;
    /*nΪҪɾ����Ԫ�ظ���
    �ֱ��ͷɾ���ʹ�βɾ��*/
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
        //��̬�滮
        //dp[i]����¼��i֧�ֱʵ�ʱ�򻹿������Ǧ����
        //dp[i]=j+1;
        //�ȿ�������򼸴θֱ�
        int penNum=total/cost1;
        vector<int>dp(penNum+1);
        for(int i=0;i<=penNum;i++){
            int c_total=total-i*cost1;
            //����i�θֱʵ�ʣ���Ǯȥ��Ǧ��
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
    //��������ʱ���Ǳ��ݻ�������Ϊ��Чֵ
    //ÿ����һ���ճǱ��ͼ�¼�����Чֵ
    int is_fot=forts[0];
    //��¼���ݻ���
    int result=0;
    //��¼�ݻ���
    int count=0;
    //��¼������
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