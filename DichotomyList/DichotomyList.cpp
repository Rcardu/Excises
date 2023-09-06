#include"DichotomyList.h"
using namespace std;

/// @brief LeetCode 162 Ѱ�ҷ�ֵ
/// @param nums 
/// @return 
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
/// @brief ��������
/// @param nums 

void DichotomyList::QuickSort_(vector<int>&nums){
    QuickSort_Switch2(nums,0,nums.size()-1);
}
void DichotomyList::QuickSort_Switch1(vector<int>&nums,int left,int right){
    if(left>=right)return;
    int pivot=QuickSort_BFS_1(nums,left,right);
    QuickSort_Switch1(nums,left,pivot-1);
    QuickSort_Switch1(nums,pivot+1,right);
}
void DichotomyList::QuickSort_Switch2(vector<int>&nums,int left,int right){
    while(left<right){
        int pivot=QuickSort_BFS_1(nums,left,right);
        if(pivot-left<right-pivot){
            QuickSort_Switch2(nums,left,pivot-1);
            left=pivot+1;
        }else{
            QuickSort_Switch2(nums,pivot+1,right);
            right=pivot-1;
        }
    }
}
int DichotomyList::QuickSort_BFS_1(vector<int>&nums,int left,int right){
    //ѡȡ��׼��
    int mid=SelectMidNum_(left,right,left+((right-left)/2),nums);
    //����׼�������������
    swap(nums[left],nums[mid]);
    int i=left,j=right;
    while(i<j){
        //���������ҵ�һ���Ȼ�׼��С��
        while(i<j&&nums[left]<=nums[j])j--;
        while(i<j&&nums[left]>=nums[i])i++;
        //if(i==j&&i==0)return left+((right-left)>>1);
        //��������������λ��
        swap(nums[i],nums[j]);
    }
    //����
    swap(nums[i],nums[left]);
    return i;
}
int DichotomyList::QuickSort_BFS_2(vector<int>&nums,int left,int right){
    int mid=SelectMidNum_(left,right,left+((right-left)>>1),nums);
    int pivod=nums[mid];
    int a=left,xi=0;
    for(int i=left;i<=right;i++){
        if(nums[i]<=pivod){
            Swap(nums,i,a);
            //��¼��׼�����ߵ��ڻ�׼�����±�
            if(nums[a]==pivod)xi=a;
            a++;
        }
    }
    //������׼����a-1λ�õ�����ʹ��׼����Ϊ[left,a-1]λ�õ������
    Swap(nums,a-1,xi);
    //���ػ�׼��λ�õ��±�
    return a-1;
}
int DichotomyList::QuickSort_BFS_3(vector<int>&nums,int left,int right){
    int mid=SelectMidNum_(left,right,left+((right-left)>>1),nums);
    int pivod=nums[mid];
    Swap(nums,right,mid);
    int i=left-1;
    int j;
    for(j=left;j<=right-1;j++){
        if(nums[j]<=pivod){
            i++;
            Swap(nums,i,j);
        }
    }
    //������׼����a-1λ�õ�����ʹ��׼����Ϊ[left,a-1]λ�õ������
    Swap(nums,i+1,right);
    //���ػ�׼��λ�õ��±�
    return i+1;
}
void DichotomyList::Swap(vector<int>&nums,int left,int right){
    int temp=nums[left];
    nums[left]=nums[right];
    nums[right]=temp;
}
int DichotomyList::SelectMidNum_(int left,int right,int mid,vector<int>&nums){
    if(nums[left]<nums[mid]^nums[left]<nums[right])return left;
    else if(nums[mid]<=nums[left]^nums[mid]<nums[right])return mid;
    else return right;
}

void DichotomyList::Test_QuickSort(){
    Cleanup cle;
    for(int i=0;i<1;i++){
        //vector<int>nums={0,1,0,1,2,5};
        vector<int>nums=cle.RandVector(50000,2,2,i);
        vector<int>num1=nums;
        vector<int>num2=nums;
        cout<<"ԭ����Ϊ��"<<endl;
        //cle.Print(nums);
        QuickSort_(num1);
        //cle.Print(num1);
        //Sortingalgorithms_(num2);
        //cle.Print(num2);
        //if(cle.LogarithmicAxis(num1,num2))cout<<"true!"<<endl;
        //else cout<<"false!"<<endl;
    }
}
/// @brief ð������
/// @param nums 
void DichotomyList::Sortingalgorithms_(vector<int>&nums){
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]>nums[j])Swap(nums,i,j);
        }
    }
}
/// @brief �鲢����
/// @param nums 
void DichotomyList::Merge_Sort_(vector<int>&nums){
    merge_Sort_Sell_(nums,0,nums.size()-1);
}
void DichotomyList::merge_Sort_Sell_(vector<int>&nums,int left,int right){
    if(left>=right)return;
    int mid=left+((right-left)>>1);
    merge_Sort_Sell_(nums,left,mid);
    merge_Sort_Sell_(nums,mid+1,right);
    Merge_(nums,left,mid,right);
}
void DichotomyList::Merge_(vector<int>&nums,int left,int mid,int right){
    vector<int>temp(nums.begin()+left,nums.begin()+right+1);
    for(int l_be=left-left,r_be=mid-left+1,i=left;i<=right;i++){
        if(l_be>mid-left)nums[i]=temp[r_be++];
        else if(r_be>right-left)nums[i]=temp[l_be++];
        else if(temp[l_be]<temp[r_be])nums[i]=temp[l_be++];
        else nums[i]=temp[r_be++];
    }
}
void DichotomyList::Test_Merge_Sort(){
    Cleanup cle;
    for(int i=0;i<1;i++){
        //vector<int>nums={};
        vector<int>nums=cle.RandVector(50000,2,2,i);
        vector<int>num1=nums;
        vector<int>num2=nums;
        //cle.Print(nums);
        Merge_Sort_(num1);
        //cle.Print(num1);
        //Sortingalgorithms_(num2);
        //cle.Print(num2);
        //if(cle.LogarithmicAxis(num1,num2))cout<<"True!"<<endl;
        //else cout<<"False!"<<endl;
    }
}
/// @brief ������
/// @param nums 
/// @return 
vector<int>DichotomyList::SortArray_(vector<int>&nums){
    int n=nums.size();
    if(n<1)return nums;
    BuildMaxHeap_(nums,n);
    while(n){
        Swap(nums,0,n-1);
        n--;
        adjustHeap_(nums,0,n);
    }
    return nums;
}
void DichotomyList::BuildMaxHeap_(vector<int>&nums,int n){
    for(int i=n/2-1;i>=0;i--){
        //�����һ����Ҷ�ӽ�㿪ʼ��ʼ����
        adjustHeap_(nums,i,n);
    }
}
void DichotomyList::adjustHeap_(vector<int>&nums,int i,int n){
    int Maxindex=i;
    int left=2*i+1;
    int right=2*(i+1);
    if(left<n&&nums[left]>nums[Maxindex])Maxindex=left;
    if(right<n&&nums[right]>nums[Maxindex]&&nums[right]>nums[left])Maxindex=right;
    if(i!=Maxindex){
        Swap(nums,i,Maxindex);
        //�ݹ��޸�ǰ���������������
        adjustHeap_(nums,Maxindex,n);
    }
}
void DichotomyList::Test_SortArray(){
    Cleanup cle;
    for(int i=0;i<1;i++){
        vector<int>nums=cle.RandVector(50000,2,2,i);
        vector<int>num1=nums;
        vector<int>num2=nums;
        //cle.Print(nums);
        SortArray_(num1);
        //cle.Print(num1);
        //Sortingalgorithms_(num2);
        //cle.Print(num2);
        //if(cle.LogarithmicAxis(num1,num2))cout<<"True!"<<endl;
        //else cout<<"False!"<<endl;
    }
}

vector<int>DichotomyList::HearArrySort_(vector<int>&nums){
    //����ϣ������
    int n=nums.size();
    int digit=n/2;
    int currValue;
    while(digit){
        for(int i=digit;i<n;i++){
            //���������
            currValue=nums[i];
            //����Ҫ�����λ��
            int index=i-digit;
            while(index>=0&&nums[index]>currValue){
                //�ͽ�indexλ�õ������뵽��ǰ�����µ�λ��
                nums[index+digit]=nums[index];
                index-=digit;
            }
            nums[index+digit]=currValue;
        }
        digit/=2;
    }
    return nums;
}
void DichotomyList::Test_HearArrySort_(){
    Cleanup cle;
    for(int i=0;i<10;i++){
        vector<int>nums=cle.RandVector(50000,2,2,i);
        vector<int>num1=nums;
        vector<int>num2=nums;
        //cle.Print(nums);
        HearArrySort_(num1);
        //cle.Print(num1);
        //Sortingalgorithms_(num2);
        //cle.Print(num2);
        //if(cle.LogarithmicAxis(num1,num2))cout<<"True!"<<endl;
        //else cout<<"False!"<<endl;
    }
}


int main(int argc,char*argv[]){
    chrono::_V2::system_clock::time_point start=chrono::system_clock::now();

    DichotomyList dic;
    dic.Test_HearArrySort_();

    chrono::_V2::system_clock::time_point end=chrono::system_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(end-start);
    cout<<"�����ѣ�"<<duration.count()<<" ms "<<endl;

    while(getchar()!='\n')continue;
    getchar();
    return 0;
}