#pragma once
#include<ctime>
#include<random>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<utility>
class Cleanup{
private:
    void Swap_(int s1,int s2,std::vector<int>&arr){
        int temp=arr[s1];
        arr[s1]=arr[s2];
        arr[s2]=temp;
    }
    void Swap_(int s1,int s2,std::vector<double>&arr){
        int temp=arr[s1];
        arr[s1]=arr[s2];
        arr[s2]=temp;
    }
public:
    //�������һ������
    std::vector<int>RandVector(int len,int range1,int range2,int times){
        std::vector<int>arr(len);
        std::default_random_engine e;
        std::uniform_int_distribution<int> u(range1,range2);
        e.seed(time(0)+times);
        for(int i=0;i<len;i++){
            arr[i]=u(e);
        }
        if(len==1)return arr;
        Swap_(0,RandNum(1,arr.size()-1,times),arr);
        return arr;
    }
    //�������һ��ʵ������
    std::vector<double>RandVector(int len,double range1,double range2,int times){
        std::vector<double>arr(len);
        std::default_random_engine e;
        std::uniform_real_distribution<double> u(range1,range2);
        e.seed(time(0)+times);
        for(int i=0;i<len;i++){
            arr[i]=u(e);
        }
        if(len==1)return arr;
        Swap_(0,RandNum(1,arr.size()-1,times),arr);
        return arr;
    }
    //�����������,�������е���������ͬ
     std::vector<int>RandVectorDifferent(int len,int range1,int range2,int times){
        if(len>range2-range1+1){
            std::cerr<<"���ȴ��ڷ�Χ���ܱ�֤������ͬ"<<std::endl;
            return {};
        }
        std::vector<int>arr(len);
        std::default_random_engine e;
        std::uniform_int_distribution<int> u(range1,range2);
        std::unordered_set<int>set;
        e.seed(time(0)+times);
        int n=u(e);
        for(int i=0;i<len;i++){
            int num=u(e);
            if(set.count(num)){
                i--;
                continue;
            }
            arr[i]=num;
            set.insert(num);
        }
        if(len==1)return arr;
        Swap_(0,RandNum(1,arr.size()-1,times),arr);
        
        return arr;
     }
    //�������һ����
    int RandNum(int range1,int range2,int times){
        std::default_random_engine e;
        std::uniform_int_distribution<int> u(range1,range2);
        e.seed(time(0)+times);
        return u(e);
    }
    //�������һ��ʵ��
    double RandRealNum(int range1,int range2,int times){
        std::default_random_engine e;
        std::uniform_real_distribution<double>u(range1,range2);
        e.seed(time(0)+times);
        return u(e);
    }
    //��������ַ���(Сд)
    std::string RandStringa(int len,char range1,char range2,int times){
        std::default_random_engine e;
        std::uniform_int_distribution<char>u(range1,range2);
        e.seed(time(0)+times);
        std::string s;
        for(int i=0;i<len;i++){
            s+=u(e);
        }
        return s;
    }
    //��������ַ���(��д)
    std::string RandStringA(int len,char range1,char range2,int times){
        std::default_random_engine e;
        std::uniform_int_distribution<char>u(range1,range2);
        e.seed(time(0)+times);
        std::string s;
        for(int i=0;i<len;i++){
            s+=u(e);
        }
        return s;
    }
    //���������Ա����������е���
    bool LogarithmicAxis(std::vector<int>&nums1,std::vector<int>&nums2){
        if(nums1.size()!=nums2.size()){
            std::cerr<<"���鳤�Ȳ��ȣ�"<<std::endl;
            return false;
        }
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]!=nums2[i])return false;
        }
        return true;
    }
    //��ӡ������
    void Print(std::vector<int>&arr){
        for(int a:arr)std::cout<<a<<"  ";
        std::cout<<std::endl;
    }

};