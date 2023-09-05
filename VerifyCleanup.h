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
public:
    //随机生成一个数组
    std::vector<int>RandVector(int len,int range1,int range2,int times){
        std::vector<int>arr(len);
        std::default_random_engine e;
        std::uniform_int_distribution<int> u(range1,range2);
        e.seed(time(0)+times);
        for(int i=0;i<len;i++){
            arr[i]=u(e);
        }
        Swap_(0,RandNum(range1,range2,times),arr);
        return arr;
    }
    //生成随机数组,且数组中的数互不相同
     std::vector<int>RandVectorDifferent(int len,int range1,int range2,int times){
        if(len>range2-range1+1){
            std::cerr<<"长度大于范围不能保证都不相同"<<std::endl;
            return {};
        }
        std::vector<int>arr(len);
        std::default_random_engine e;
        std::uniform_int_distribution<int> u(range1,range2);
        std::unordered_set<int>set;
        e.seed(time(0)+times);
        for(int i=0;i<len;i++){
            int num=u(e);
            if(set.count(num)){
                i--;
                continue;
            }
            arr[i]=num;
            set.insert(num);
        }
        Swap_(0,RandNum(range1,range2,times),arr);
        
        return arr;
     }

    //随机生成一个数
    int RandNum(int range1,int range2,int times){
        std::default_random_engine e;
        std::uniform_int_distribution<int> u(range1,range2);
        e.seed(time(0)+times);
        return u(e);
    }
    //随机生成字符串(小写)
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
    //随机生成字符串(大写)
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


    //打印此数组
    void Print(std::vector<int>&arr){
        for(int a:arr)std::cout<<a<<"  ";
        std::cout<<std::endl;
    }

};