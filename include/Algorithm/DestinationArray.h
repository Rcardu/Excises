#include"../unltle.h"
class DestinationArray{
private:
    /*将一个数逆序输出*/
    int NumberPatternSymbol_(int num);
public:
    /*将一个数逆序输出*/
    void TestNumberPatternSymbol();
private:
    /*最长回文子串*/
    std::string longestPalindrome_(std::string s);
    std::string longestPalindrome_fll_(std::string s,int n);
public:
    /*最长回文子串*/
    void TestlongestPalindrome();
private:
    //买铅笔与钢笔
    long long WaysToBuyPensPencils_(int total, int cost1, int cost2);
public:
    //买铅笔与钢笔
    void TestWaysToBuyPensPencils();
private:
    //最多经过的敌人城堡个数
    int captureForts_(std::vector<int>& forts);
public:
    //最多经过的敌人城堡个数
    void TestCaptureForts();

};
