#include"DichotomyList.h"
using namespace std;

int DichotomyList::LC162_findPeakElement_(vector<int>&nums){
    int n=nums.size();
    if(n==1)return nums[0];
    int l=0;
    int r=n-1;
    if(nums[l]>nums[l+1])return l;
    if(nums[r]>nums[r-1])return r;
    while(l<r){
        int mid=l+((r-l)>>1);
        //����[mid-1,mid+1]��������ֵ���ұߣ��ƶ���߽�
        if(nums[mid]>nums[mid-1]&&nums[mid]<nums[mid+1])l=mid;
        //����[mid-1,mid+1]�ݼ�����ֵ����ߣ��ƶ��ұ߽�
        else if(nums[mid]<nums[mid-1]&&nums[mid]>nums[mid+1])r=mid;
        //����[mid-1,mid+1]�ȼ����������ұ߽綼���ƶ��������ƶ���߽�
        else if(nums[mid]<nums[mid-1]&&nums[mid]<nums[mid+1])r=mid;
        //����[mid-1,mid+1]���������mid���Ƿ�ֵ��ֱ�ӷ���
        else return mid;

    }
    return l;
}
void DichotomyList::Test_LC162_findPeakElement(){
    vector<int>nums={1,2,1,2,1};
    cout<<LC162_findPeakElement_(nums)<<endl;
}

int main(int argc,char*argv[]){
    chrono::_V2::system_clock::time_point start=chrono::system_clock::now();

    DichotomyList dic;
    dic.Test_LC162_findPeakElement();

    chrono::_V2::system_clock::time_point end=chrono::system_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(end-start);
    cout<<"�����ѣ�"<<duration.count()<<" ms "<<endl;

    while(getchar()!='\n')continue;
    getchar();
    return 0;
}