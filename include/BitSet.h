#pragma once
#include<vector>
#include<bitset>
/*λͼ��ʵ��*/
class BitSet{
public:
    std::vector<int>Set;
    //����λͼ�Ĵ�С
    BitSet(int n){
        Set.resize((n+32-1)/32);
    }
    void BitSetAdd(int val){
        Set[val/32]|=1<<(val%32);
    }
    void BitSetRemove(int val){
        Set[val/32]&=~(1<<(val%32));
    }
    void BitSetReverse(int val){
        Set[val/32]^=1<<(val%32);
    }
    bool BitSetContains(int val){
        return (Set[val/32]>>(val%32)&1)==1;
    }
};
/// @brief ����λ����
class BitOperator{
private:
    const int Min=INT_MIN;
public:
    //�ӷ�
    uint32_t BitAdd(uint32_t a,uint32_t b){
        uint32_t ans=a;
        while(b){
            //ans: a��b���޽�λ���
            ans=a^b;
            //b�ͳ���a��b�Ľ�λ��Ϣ
            b=(a&b)<<1;
            a=ans;
        }
        return ans;
    }
    int BitAdd(int a,int b){
        int ans=a;
        while(b){
            ans=a^b;
            b=(a&b)<<1;
            a=ans;
        }
        return ans;
    }
    //����
    uint32_t BitMinus(uint32_t a,uint32_t b){return BitAdd(a,BitNeg(b));}
    uint32_t BitNeg(uint32_t n){return BitAdd(~n,(uint32_t)1);}
    int BitMinus(int a,int b){return BitAdd(a,BitNeg(b));}
    int BitNeg(int n){return BitAdd(~n,1);}
    //�˷�
    uint32_t BitMultiply(uint32_t a,uint32_t b){
        uint32_t x=a>0?a:BitNeg(a);
        uint32_t y=b>0?b:BitNeg(b);
        uint64_t ans=0;
        while(y!=0){
            if((y&1)!=0){
                ans=BitAdd(ans,x);
            }
            x<<=1;
            y>>=1;
        }
        ans>=INT_MAX?INT_MAX:ans;
        return a>0^b>0?BitNeg((uint32_t)ans):(uint32_t)ans;
    }
    int BitMultiply(int a,int b){
        int x=a>0?a:BitNeg(a);
        int y=b>0?b:BitNeg(b);
        long ans=0;
        while(y){
            if((y&1)!=0)ans=BitAdd(ans,x);
            x<<=1;
            y>>=1;
        }
        ans>=INT_MAX?INT_MAX:ans;
        return a>0^b>0?BitNeg((int)ans):(int)ans;
    }
    //����
    uint32_t BitDived(uint32_t a,uint32_t b){
        //a��b����������Сֵ�����Ϊ1
        if(a==Min&&b==Min)return 1;
        //a��b������������С���������
        if(a!=Min&&b!=Min)return BitDiv(a,b);
        //b��������С������a�Ƕ��٣��������0
        if(b==Min)return 0;
        //a��������С��b��-1
        if(b==BitNeg(1))return INT_MAX;
        //a��������С��b����������СҲ����-1
        a=BitAdd(a,b>0?b:BitNeg(b));
        uint32_t ans=BitDiv(a,b);
        uint32_t offset=b>0?BitNeg(1):1;
        return BitAdd(ans,offset);
    }
    uint32_t BitDiv(uint32_t a,uint32_t b){
        uint32_t x=a<0?BitNeg(a):a;
        uint32_t y=b<0?BitNeg(b):b;
        uint32_t ans=0;
        for(int i=30;i>=0;i=BitMinus(i,1)){
            if((x>>i)>=y){
                ans|=1<<i;
                x=BitMinus(x,(y<<i));
            }
        }
        return a<0^b<0?BitNeg(ans):ans;
    }
    int BitDived(int a,int b){
        //a��b����������Сֵ�����Ϊ1
        if(a==Min&&b==Min)return 1;
        //a��b������������С���������
        if(a!=Min&&b!=Min)return BitDiv(a,b);
        //b��������С������a�Ƕ��٣��������0
        if(b==Min)return 0;
        //a��������С��b��-1
        if(b==BitNeg(1))return INT_MAX;
        //a��������С��b����������СҲ����-1
        return BitAdd(BitDiv(BitAdd(a,b>0?b:BitNeg(b)),b),b>0?BitNeg(1):1);
    }
    int BitDiv(int a,int b){
        int x=a<0?BitNeg(a):a;
        int y=b<0?BitNeg(b):b;
        int ans=0;
        for(int i=30;i>=0;i=BitMinus(i,1)){
            if((x>>i)>=y){
                ans|=1<<i;
                x=BitMinus(x,(y<<i));
            }
        }
        return a<0^b<0?BitNeg(ans):ans;
    }

};