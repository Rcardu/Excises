#include"../unltle.h"
class DestinationArray{
private:
    /*��һ�����������*/
    int NumberPatternSymbol_(int num);
public:
    /*��һ�����������*/
    void TestNumberPatternSymbol();
private:
    /*������Ӵ�*/
    std::string longestPalindrome_(std::string s);
    std::string longestPalindrome_fll_(std::string s,int n);
public:
    /*������Ӵ�*/
    void TestlongestPalindrome();
private:
    //��Ǧ����ֱ�
    long long WaysToBuyPensPencils_(int total, int cost1, int cost2);
public:
    //��Ǧ����ֱ�
    void TestWaysToBuyPensPencils();
private:
    //��ྭ���ĵ��˳Ǳ�����
    int captureForts_(std::vector<int>& forts);
public:
    //��ྭ���ĵ��˳Ǳ�����
    void TestCaptureForts();

};
