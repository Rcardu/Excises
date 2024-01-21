#include"AmountData.h"
using namespace std;

/// @brief ���ٶ��ٸ����ܿ���ɱ����
/// @param n 
/// @param m 
/// @param kill 
/// @param blood 
/// @return 
int AmountFOfData::KillMonsterEverySkillUseOnce_(int n,int m,vector<int>kill,vector<int>blood){
    this->kill=kill;
    this->blood=blood;
    return KillMonsterEverySkillUseOnce_f_(n,0,m);
}
int AmountFOfData::KillMonsterEverySkillUseOnce_f_(int n,int i,int r){
    //֮ǰ�ľ����ù������ˣ�ֱ�ӷ���ʹ���˶��ٸ�����
    if(r<=0)return i;
    //û������������·��ͨ
    if(i==n)return INT_MAX;
    int ans=INT_MAX;
    for(int j=i;j<n;j++){
        KillMonsterEverySkillUseOnce_Swap_(i,j);
        ans=min(ans,KillMonsterEverySkillUseOnce_f_(n,i+1,r-(r>blood[i]?kill[i]:kill[i]*2)));
        KillMonsterEverySkillUseOnce_Swap_(i,j);
    }
    return ans;
}
void AmountFOfData::KillMonsterEverySkillUseOnce_Swap_(int i,int j){
    int temp=kill[j];
    kill[j]=kill[i];
    kill[i]=temp;
    temp=blood[j];
    blood[j]=blood[i];
    blood[i]=temp;
}
void AmountFOfData::Test_cin_KillMonsterEverySkillUseOnce(){
    //T���������
    int T;
    cin>>T;
    while(T--){
        //���ܸ��� //����Ѫ��
        int n;int m;
        cin>>n;cin>>m;
        for(int i=0;i<n;i++){
            //�����˺�������˫���˺���ֵ
            int kil,blo;
            cin>>kil;cin>>blo;
            kill.push_back(kil);blood.push_back(blo);
        }
        int ans=KillMonsterEverySkillUseOnce_f_(n,0,m);
        cout<<(ans==INT_MAX?-1:ans)<<endl;
    }
}
void AmountFOfData::Test_KillMonsterEverySkillUseOnce(){
    vector<int>kill;
    vector<int>blood;
    KillMonsterEverySkillUseOnce_(kill.size(),200,kill,blood);
}

/// @brief LeetCode 906 ��������������Ŀ
/// @param left 
/// @param right 
/// @return 
int AmountFOfData::LC906_superpalindromesInRange_(string left,string right){
    long l=stol(left);
    long r=stol(right);
    //x���ţ���Χlimit
    long limit=(long)sqrt((double)r);
    //seed��ö������С 10^18->10^9->10^5
    //seed���������ȵĻ��ġ�ż�����ȵĻ���
    long seed=1;
    //num������x��num^2->x
    long num=0;
    int ans=0;
    do{
        //seed��ż�����ȵĻ�������
        num=LC906_superpalindromesInRange_evenEnlarge_(seed);
        if(LC906_superpalindromesInRange_check_((unsigned long long)num*num,l,r))ans++;
        num=LC906_superpalindromesInRange_oddEnlarge_(seed);
        if(LC906_superpalindromesInRange_check_((unsigned long long)num*num,l,r))ans++;
        seed++;
        //����������ȵĻ����Ѿ������˷�Χ����ô�������Ļ���Ҳ�϶����ڷ�Χ����
    }while(num<limit);
    return ans;
}
int AmountFOfData::LC906_superpalindromesInRange2_(string left,string right){
    long long l=stoll(left);
    long long r=stoll(right);
    int i=0;
    for(;i<record.size();i++){
        if(record[i]>=l)break;
    }
    int j=record.size()-1;
    for(;j>=0;j--){
        if(record[j]<=r)break;
    }
    return j-i+1;
}
vector<long long> AmountFOfData::LC906_superpalindromesInRange_(long long left,long long right){
    long long l=left;
    long long r=right;
    //x���ţ���Χlimit
    long long limit=(long long)sqrt((double)r);
    //seed��ö������С 10^18->10^9->10^5
    //seed���������ȵĻ��ġ�ż�����ȵĻ���
    long long seed=1;
    //num������x��num^2->x
    long long num=0;
    int size=0;
    vector<long long>ans;
    do{
        //seed��ż�����ȵĻ�������
        num=LC906_superpalindromesInRange_evenEnlarge_(seed);
        if(LC906_superpalindromesInRange_check_((unsigned long long)num*num,l,r)){
            ans.push_back(num*num);
            size++;
        }
        num=LC906_superpalindromesInRange_oddEnlarge_(seed);
        if(LC906_superpalindromesInRange_check_((unsigned long long)num*num,l,r)){
            ans.push_back(num*num);
            size++;
        }
        seed++;
        //����������ȵĻ����Ѿ������˷�Χ����ô�������Ļ���Ҳ�϶����ڷ�Χ����
    }while(num<limit);
    return ans;
}
long long AmountFOfData::LC906_superpalindromesInRange_evenEnlarge_(long long seed){
    long long ans=seed;
    while(seed){
        ans=ans*10+(seed%10);
        seed/=10;
    }
    return ans;
}
long long AmountFOfData::LC906_superpalindromesInRange_oddEnlarge_(long long seed){
    long long ans=seed;
    seed/=10;
    while(seed){
        ans=ans*10+(seed%10);
        seed/=10;
    }
    return ans;
}
bool AmountFOfData::LC906_superpalindromesInRange_check_(unsigned long long num,long long l,long long r){
    return num>=l&&num<=r&&LC906_superpalindromesInRange_check_isPalindrome(num);
}
bool AmountFOfData::LC906_superpalindromesInRange_check_isPalindrome(long long num){
    //�ж���λ
    long long offset=1;
    while(num/offset>=10){
        offset*=10;
    }
    //��λ�ж�
    while(num!=0){
        if(num/offset!=num%10)return false;
        //������λ������
        num=(num%offset)/10;
        //��������λ��offsetͬʱ������λ
        offset/=100;
    }
    return true;
}
void AmountFOfData::Test_LC906_superpalindromesInRange(){
    string left="38455498359";
    string right="999999999999999999";
    vector<long long>ans=LC906_superpalindromesInRange_(1,LONG_LONG_MAX);
    sort(ans.begin(),ans.end());
    for(auto L:ans){
        cout<<L<<"L,"<<endl;
    }
    cout<<ans.size()<<endl;
}

int main(int argc,char*argv[]){
    auto start=chrono::system_clock::now();

    AmountFOfData amo;
    amo.Test_LC906_superpalindromesInRange();

    auto end=chrono::system_clock::now();
    cout<<"���к�ʱ��"<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" ms "<<endl;

    while(getchar()!='\n')continue;
    getchar();
    return 0;
}