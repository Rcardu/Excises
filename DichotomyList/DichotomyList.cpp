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
        //区间[mid-1,mid+1]递增，峰值在右边，移动左边界
        if(nums[mid]>nums[mid-1]&&nums[mid]<nums[mid+1])l=mid;
        //区间[mid-1,mid+1]递减，峰值在左边，移动右边界
        else if(nums[mid]<nums[mid-1]&&nums[mid]>nums[mid+1])r=mid;
        //区间[mid-1,mid+1]先减后增，左右边界都可移动，这里移动左边界
        else if(nums[mid]<nums[mid-1]&&nums[mid]<nums[mid+1])r=mid;
        //区间[mid-1,mid+1]先增后减，mid就是峰值，直接返回
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
    cout<<"共花费："<<duration.count()<<" ms "<<endl;

    while(getchar()!='\n')continue;
    getchar();
    return 0;
}