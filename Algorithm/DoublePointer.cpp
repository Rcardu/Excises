#include"DoublePointer.h"
using namespace std;

/// @brief LeetCoed 922 ��ż������ case 1.1
/// @param nums 
/// @return 
vector<int>Simple::DoubleSi::LC922_sortArrayByParityII(vector<int>& nums){
    int n=nums.size();
    for(int odd=1,even=0;odd<n&&even<n;){
        if((nums[n-1]&1)==1){
            Swap(nums,odd,n-1);
            odd+=2;
        }else{
            Swap(nums,even,n-1);
            even+=2;
        }
    }
    return nums;
}
void Simple::DoubleSi::Swap(vector<int>&nums,int i,int j){
    int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
}
void Simple::DoubleSi::Test_LC922_sortArrayByParityII(){
    vector<int>nums;
    LC922_sortArrayByParityII(nums);
}

/// @brief LeetCode 287 Ѱ���ظ��� case 1.2
/// @param nums 
/// @return 
int Simple::DoubleSi::LC287_findDuplicate(vector<int>& nums){
    if(nums.size()<2)return -1;
    int slow=nums[0];
    int fast=nums[nums[0]];
    while(slow!=fast){
        fast=nums[nums[fast]];
        slow=nums[slow];
    }
    fast=0;
    while(fast!=slow){
        fast=nums[fast];
        slow=nums[slow];
    }
    return slow;
}
void Simple::DoubleSi::Test_LC287_findDuplicate(){
    vector<int>nums;
    LC287_findDuplicate(nums);
}
 
/// @brief LeetCode 42 ����ˮ case 1.3
/// @param height 
/// @return 
int Simple::DoubleSi::LC42_trap(vector<int>& height){
    int n=height.size();
    vector<int>left(n,0);
    vector<int>right(n,0);
    left[0]=height[0];
    for(int i=1;i<n;i++){
        if(height[i]>left[i-1])left[i]=height[i];
        else left[i]=left[i-1];
    }
    right[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        if(height[i]>right[i+1])right[i]=height[i];
        else right[i]=right[i+1];
    }
    int ans=0;
    for(int i=1;i<n-1;i++){
        ans+=max(0,min(left[i-1],right[i+1])-height[i]);
    }
    return ans;
}
int Simple::DoubleSi::LC42_trap_doublePoint(vector<int>& height){
    int l=1,r=height.size()-1;
    int lmax=height[0];
    int rmax=height[height.size()-1];
    int ans=0;
    while(l<=r){
        if(lmax<=rmax){
            ans+=max(0,lmax-height[l]);
            lmax=max(lmax,height[l++]);
        }else{
            ans+=max(0,rmax-height[r]);
            rmax=max(rmax,height[r--]);
        }
    }
    return ans;
}
void Simple::DoubleSi::Test_LC42_trap(){
    vector<int>nums;
    LC42_trap(nums);
}

/// @brief LeetCode 881 ����ͧ case 1.4
/// @param people 
/// @param limit 
/// @return 
int Simple::DoubleSi::LC881_numRescueBoats(vector<int>& people, int limit){
    int n=people.size();
    int l=0;
    int r=n-1;
    int ans=0;
    sort(people.begin(),people.end());
    while(l<=r){
        if(people[l]+people[r]>limit){
            ans++;
            r--;
        }else{
            ans++;
            r--;
            l++;
        }
    }
    return ans;
}
void Simple::DoubleSi::Test_LC881_numRescueBoats(){
    vector<int>nums;
    LC881_numRescueBoats(nums,3);
}

/// @brief LeetCoed 11 ʢˮ�������� case 1.5
/// @param height 
/// @return 
int Simple::DoubleSi::LC11_maxArea(vector<int>& height){
    int n=height.size();
    int l=0;
    int r=n-1;  
    int ans=0;
    while(l<=r){
        ans=max(ans,(r-l)*min(height[r],height[l]));
        if(height[l]<=height[r])l++;
        else r--;
    }
    return ans;
}
void Simple::DoubleSi::Test_LC11_maxArea(){
    vector<int>nums;
    LC11_maxArea(nums);
}

/// @brief LeetCode 475 ��ů��* case 1.6
/// @param houses 
/// @param heaters 
/// @return 
int Simple::DoubleSi::LC475_findRadius(vector<int>& houses, vector<int>& heaters){
    sort(heaters.begin(),heaters.end());
    sort(houses.begin(),houses.end());
    int ans=0;
    for(int i=0,j=0;i<houses.size();i++){
        while(!LC475_bast(houses,heaters,i,j))j++;
        ans=max(ans,abs(heaters[j]-houses[i]));
    }
    return ans;
}
bool Simple::DoubleSi::LC475_bast(vector<int>&house,vector<int>&heaters,int i,int j){
    return j==heaters.size()-1||abs(heaters[j]-house[i])<abs(heaters[j+1]-house[i]);
}
void Simple::DoubleSi::Test_LC475_findRadius(){
    vector<int>house;
    vector<int>heaters;
    LC475_findRadius(house,heaters);
}

/// @brief LeetCode 41 ȱʧ�ĵ�һ������ case 1.7 
/// @param nums 
/// @return 
int Simple::DoubleSi::LC41_firstMissingPositive(vector<int>& nums){
    /*[-3,5,2,1,8,5,4,2,3,13]
    arr[l]==l+1,l++;
    arr[l]<=l,����
    arr[l]>r,����
    arr[arr[l]-1]==arr[l],����*/
    //l����ߣ���������iλ���Ϸ���i+1������
    //��Զ����lλ�õ����ֿ����ܲ�������l++
    int l=0,r=nums.size();
    //r[��������]������
    //��õ�״���£���Ϊ1~r�ǿ����ռ�ȫ�ģ�ÿ�������ռ�1��������������
    //�������Ļ�Ԥ�ھͻ���(r--);
    while(l<r){
        if(nums[l]==l+1)l++;
        else if(nums[l]<=l||nums[l]>r||nums[nums[l]-1]==nums[l])Swap(nums,l,--r);
        else Swap(nums,l,nums[l]-1);
    }
    return l+1;
}
void Simple::DoubleSi::Test_LC41_firstMissingPositive(){
    vector<int>nums;
    LC41_firstMissingPositive(nums);
}

/// @brief LeetCode 875 �����㽶������ case 2.1
/// @param piles 
/// @param h 
/// @return 
int Simple::DichotomyMethod::LC875_minEatingSpeed(vector<int>& piles, int h){
    int r=0;
    int l=1;
    for(int i=0;i<piles.size();i++)r=max(r,piles[i]);
    int ans=0;
    int m;
    //�𰸶�������[l��������r]�ķ�Χ�ڣ�ʹ�ö��ַ���h��Ϊ�߽���Ѱ��������Ŵ�
    while(l<=r){
        m=(l+r)/2;
        if(LC875_CatEatInTime(piles,h,m)){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    return ans;
}
bool Simple::DichotomyMethod::LC875_CatEatInTime(vector<int>&piles,int h,int speed){
    int ans=0;
    for(int i=0;i<piles.size();i++){
        ans+=(piles[i]+speed-1)/speed;
    }
    return ans<=h;
}
void Simple::DichotomyMethod::Test_LC875_minEatingSpeed(){
    vector<int>nums={30,11,23,4,20};
    cout<<LC875_minEatingSpeed(nums,5);
}

/// @brief LeetCode 410 �ָ���������ֵ case 2.2
/// @param nums 
/// @param k 
/// @return 
int Simple::DichotomyMethod::LC410_splitArray(vector<int>& nums, int k){
    long sum=0;
    for(int i=0;i<nums.size();i++)sum+=nums[i];
    long ans=0;
    for(long l=0,r=sum,m,cur;l<=r;){
        m=l+((r-l)>>1);
        //�����������ÿһ���ֵ��ۼӺ�<=m �����ʻ��ֳɼ������ֲŹ�
        cur=LC410_splitArray_f(nums,m);
        if(cur<=k){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    return (int)ans;
}
int Simple::DichotomyMethod::LC410_splitArray_f(vector<int>&nums,int limit){
    int parts=1;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>limit)return INT_MAX;
        if(sum+nums[i]>limit){
            parts++;
            sum=nums[i];
        }else sum+=nums[i];
    }
    return parts;
}
void Simple::DichotomyMethod::Test_LC410_splitArray(){
    vector<int>nums={7,2,5,10,8};
    cout<<LC410_splitArray(nums,2)<<endl;
}

/// @brief �����˵�ͨ����Ϸ case 2.3
void Simple::DichotomyMethod::RobotPassThroughBuilding(){
    int n;
    cin>>n;
    vector<int>nums(n,0);
    int Max=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        Max=max(Max,nums[i]);
    }
    cout<<compute(nums,0,Max,Max)<<endl;
}
int Simple::DichotomyMethod::compute(vector<int>&nums,int l,int r,int max){
    int m,ans=-1;
    while(l<=r){
        //m�е㣬��ʱͨ�����������
        m=l+((r-l)>>1);
        if(compute_f(nums,m,max)){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    return ans;
}
bool Simple::DichotomyMethod::compute_f(vector<int>&nums,int energy,int max){
    for(int i=0;i<nums.size();i++){
        if(energy>=max)return true;
        if(energy<0)return false;
        if(energy>nums[i])energy+=energy-nums[i];
        else energy-=nums[i]-energy;
    }
    return true;
}
void Simple::DichotomyMethod::Test_RobotPassThroughBuilding(){
    RobotPassThroughBuilding();
}

/// @brief LeetCode 719 �ҳ���kС�����Ծ��� case 2.4
/// @param nums 
/// @param k 
/// @return 
int Simple::DichotomyMethod::LC719_smallestDistancePair(vector<int>& nums, int k){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int ans=0;
    for(int l=0,r=nums[n-1]-nums[0],m,cnt;l<=r;){
        //m�е㣬nums�����������Ĳ�ֵ<=m
        m=l+((r-l)>>1);
        cnt=LC719_smallestDistancePair_f(nums,m);
        if(cnt>=k){
            ans=m;
            r=m-1;
        }else l=m+1;
        
    }
    return ans;
}
int Simple::DichotomyMethod::LC719_smallestDistancePair_f(vector<int>& nums, int limit){
    int cnt=0;
    for(int l=0,r=0;l<nums.size();l++){
        //����һ��λ�ã����ң���һ��λ�õ���-lλ�õ�����꣬r++����ȥ
        while(r+1<nums.size()&&nums[r+1]<=nums[l]+limit)r++;
        cnt+=r-l;
    }
    return cnt;
}
void Simple::DichotomyMethod::Test_LC719_smallestDistancePair(){
    vector<int>nums;
    LC719_smallestDistancePair(nums,2);
}

/// @brief LeetCode 2141 ͬʱ����N̨���Ե��ʱ�� case 2.5
/// @param n 
/// @param batteries 
/// @return 
long long Simple::DichotomyMethod::LC2141_maxRunTime(int n, vector<int>& batteries){
    long sum=0;
    //for(int num:batteries)sum+=num;
    int Max=0;
    for(int num:batteries){
        Max=max(Max,num);
        sum+=num;
    }
    if(sum>(long)Max*n){
        //���е�ص���������Max
        //�����ʱsum>(long)max*num
        //˵�������յĹ���ʱ��һ����>=Max,��������յĹ���ʱ��>=Max
        //˵�������ڴ�x��˵�����е�ض�����Ƭƴ�Ӹ���
        //��ôѰ��?*num<=sum ������о�����ģ�����
        //��sum/num
        return sum/n;
    }
    long ans=0;
    for(long l=0,r=Max,m;l<=r;){
        //��num̨���Թ�ͬ����m�����ܲ�������
        m=l+((r-l)>>1);
        if(LC2141_maxRunTime_f1(batteries,n,m)){
            ans=m;
            l=m+1;
        }else r=m-1;
    }
    return ans;
}
bool Simple::DichotomyMethod::LC2141_maxRunTime_f1(vector<int>&nums,int n,long limit){
    long sum=0;
    for(int num:nums){
        if(num>limit)n--;
        else sum+=num;
        if(sum>=(long)n*limit)return true;
    }
    return false;
}
void Simple::DichotomyMethod::Test_LC2141_maxRunTime(){
    vector<int>nums;
    LC2141_maxRunTime(10,nums);
}

/// @brief ����Ա�������ʱ�� case 2.6
struct cmp{
    bool operator()(vector<int>&a,vector<int>&b){
        return b[0]<a[0];
    }
};
int Simple::DichotomyMethod::WaitingTime1(vector<int>arr,int m){
    //����һ��С����
    priority_queue<vector<int>,vector<vector<int>>,cmp>que;
    int n=arr.size();
    //��ʼʱʱ��Ϊ0
    for(int i=0;i<n;i++)que.push({0,arr[i]});
    for(int i=0;i<m;i++){
        //�Ӷ���ȡ��һ����ʼʱ����С�Ľ��з���
        vector<int>cur={que.top()[0],que.top()[1]};
        que.pop();
        //�����˷���Ա�ĳ�ʼʱ�����ӵ��������ʱ��
        cur[0]+=cur[1];
        que.push(cur);
        //һ�����ƣ�ֱ������Ա���񵽵�m��
    }
    //��m+1�������ң���ʱ��ʱ�䣬�����ҽ��շ���ʱ��ʱ��
    return que.top()[0];
}
int Simple::DichotomyMethod::WaitingTime2(vector<int>arr,int m){
    int Min=INT_MAX;
    for(int a:arr)Min=min(Min,a);
    int ans=0;
    for(int l=0,r=Min*m,mid;l<=r;){
        mid=l+((r-l)>>1);
        if(WaitingTime2_f(arr,mid)>=m+1){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return ans;
}
int Simple::DichotomyMethod::WaitingTime2_f(vector<int>arr,int m){
    /*����arr[i]=2,m=8
    0~2 1�� 2~4 1�� 4~6 1�� 6~8 1�� ��8��ʼ���ԽӴ��ˣ���û��
    Ҫ��ȶ���з���(�����Ƿ������)������Ӧ����+1 =5*/
    int ans=0;
    for(int a:arr)ans+=(m/a)+1;
    return ans;
}
void Simple::DichotomyMethod::Test_WaitingTime(){
    Cleanup cle;
    vector<int>times=cle.RandVector(100,1,200,1000);
    vector<int>ans1(100,0);
    vector<int>ans2(100,0);
    for(int i=0;i<times.size();i++){
        vector<int>arr=cle.RandVector(20,1,100,20);
        ans1[i]=WaitingTime1(arr,times[i]);
        ans2[i]=WaitingTime2(arr,times[i]);
    }
    if(!(ans1==ans2))cout<<"����"<<endl;
    cout<<"����"<<endl;
}

/// @brief ������ɱ�������� case 2.7
/// @param cuts 
/// @param poisons 
/// @param hp 
/// @return 
int Simple::DichotomyMethod::SlashingPoisoning(vector<int>&cuts,vector<int>&poisons,int hp){
    int ans=INT_MAX;
    for(int l=1,r=hp+1,m;l<=r;){
        //һ��Ҫ�ù�����m�غ�������
        m=l+((r-l)>>1);
        if(SlashingPoisoning_f(cuts,poisons,hp,m)){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    return ans;
}
bool Simple::DichotomyMethod::SlashingPoisoning_f(vector<int>&cuts,vector<int>&poisons,long hp,int times){
    //�ӵ�0�غϿ�ʼ����times�غϽ���
    int n=min((int)cuts.size(),times);
    for(int i=0,j=1;i<n;i++){
        hp-=max((long)cuts[i],(long)(times-j)*(long)poisons[i]);
        if(hp<=0)return true;
    }
    return false;
}
int Simple::DichotomyMethod::SlashingPoisoning1(vector<int>&cuts,vector<int>&poisons,int hp){
    int sum=0;
    for(int num:poisons)sum+=num;
    vector<vector<vector<int>>>dp(cuts.size(),vector<vector<int>>(hp+1,vector<int>(sum+1)));
    return SlashingPoisoning_f1(cuts,poisons,0,hp,0,dp);
}
int Simple::DichotomyMethod::SlashingPoisoning_f1(vector<int>&cuts,vector<int>&poisons,int i,int r,int p,vector<vector<vector<int>>>dp){
    r-=p;
    if(r<=0)return i+1;
    if(i==cuts.size()){
        if(p==0)return INT_MAX;
        else return cuts.size()+1+(r+p-1)/p;
    }
    if(dp[i][r][p]!=0)return dp[i][r][p];
    int p1=r<=cuts[i]?(i+1):SlashingPoisoning_f1(cuts,poisons,i+1,r-cuts[i],p,dp);
    int p2=SlashingPoisoning_f1(cuts,poisons,i+1,r,p+poisons[i],dp);
    int ans=min(p1,p2);
    dp[i][r][p]=ans;
    return ans;
}
void Simple::DichotomyMethod::Test_SlashingPoisoning(){
    Cleanup cle;
    vector<int>ans1(10,0);
    vector<int>ans2(10,0);
    vector<int>Hp=cle.RandVector(10,100,200,300);
    for(int i=0;i<10;i++){
        vector<int>cnts=cle.RandVector(10,33,100,200);
        vector<int>poisons=cle.RandVector(10,14,50,200);
        ans1[i]=SlashingPoisoning(cnts,poisons,Hp[i]);
        ans2[i]=SlashingPoisoning1(cnts,poisons,Hp[i]);
    }
    if(!(ans1==ans2))cout<<"����"<<endl;
    cout<<"����"<<endl;
}

long long Simple::DichotomyMethod::LC2594_repairCars(vector<int>& ranks, int cars){
    long long Max=INT_MIN;
    for(int r:ranks)Max=max(Max,(long long)r);
    Max=Max*cars*cars;
    long long ans=0;
    for(long long l=0,r=Max,m;l<=r;){
        m=l+((r-l)>>1);
        //����ʱ�䣬�ܲ����޺���Щ��
        if(LC2594_repairCars_f(ranks,cars,m)){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    return ans;
}
bool Simple::DichotomyMethod::LC2594_repairCars_f(vector<int>&ranks,int cars,int time){
    /*����ÿһ��������time�����޺ö�������*/
    for(int i=0;i<ranks.size();i++){
        cars-=(int)sqrt(time/ranks[i]);
        if(cars<=0)return true;
    }
    return cars<=0;
}
void Simple::DichotomyMethod::Tset_LC2594_repairCars(){
    vector<int>ranks={4,2,3,1};
    cout<<LC2594_repairCars(ranks,10)<<endl;
}

int main(){
    auto start=chrono::system_clock::now();
    int In;
    cin>>In;
    switch(In){
        case 1:{
            using Simple::DoubleSi;
            DoubleSi dou;
            int Im;
            cin>>Im;
            switch(Im){
                case 1:dou.Test_LC922_sortArrayByParityII();
                break;
                case 2:dou.Test_LC287_findDuplicate();
                break;
                case 3:dou.Test_LC42_trap();
                break;
                case 4:dou.Test_LC881_numRescueBoats();
                break;
                case 5:dou.Test_LC11_maxArea();
                break;
                case 6:dou.Test_LC475_findRadius();
                break;
                case 7:dou.Test_LC41_firstMissingPositive();
                break;
                default:break;
            }
        }
        break;
        case 2:{
            using Simple::DichotomyMethod;
            DichotomyMethod dic;
            int Im;
            cin>>Im;
            switch(Im){
                case 1:dic.Test_LC875_minEatingSpeed();
                break;
                case 2:dic.Test_LC410_splitArray();
                break;
                case 3:dic.Test_RobotPassThroughBuilding();
                break;
                case 4:dic.Test_LC719_smallestDistancePair();
                break;
                case 5:dic.Test_LC2141_maxRunTime();
                break;
                case 6:dic.Test_WaitingTime();
                break;
                case 7:dic.Test_SlashingPoisoning();
                break;
                case 8:dic.Tset_LC2594_repairCars();
                default:break;
            }
        }
        break;
        default:break;
    }

    auto end=chrono::system_clock::now();
    cout<<"���к�ʱ��"<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" ms "<<endl;
    cin.get();
    cin.get();
    return 0;
}