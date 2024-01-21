#include"../unltle.h"

class AmountFOfData{
private:
    /*现在有一个打怪类型的游戏，这个游戏是这样的，你有n个技能
    每一个技能会有一个伤害
    同时若干怪物小于等于一定的血量，则该技能可能造成双倍的伤害
    每个技能最多只能释放一次，已知怪物有m点血量
    现在想问你最少用几个技能能消灭它（血量小于等于0）
    技能的数量是n，怪物的血量是m
    i号技能的触发的双倍伤害的血量最小值是y[i]
    1<=n<=10
    1<=m、x[i]、y[i]<=10^6*/
    int MAXN=11;
    //技能的单倍伤害
    std::vector<int>kill;
    //技能的双倍伤害血量阈值
    std::vector<int>blood;
    int KillMonsterEverySkillUseOnce_(int n,int m,std::vector<int>kill,std::vector<int>blood);
    /*n：一共几个技能
    i：当前到第几个技能
    r：怪兽剩余的血量*/
    int KillMonsterEverySkillUseOnce_f_(int n,int i,int r);
    /*交换数组中的值*/
    void KillMonsterEverySkillUseOnce_Swap_(int i,int j);
public:
    //至少多少个技能可以杀死怪
    void Test_cin_KillMonsterEverySkillUseOnce();
    //至少多少个技能可以杀死怪
    void Test_KillMonsterEverySkillUseOnce();
private:
    //根据算法生成的结果集
    std::vector<long long>record={
        1L,
        4L,
        9L,
        121L,
        484L,
        10201L,
        12321L,
        14641L,
        40804L,
        44944L,
        1002001L,
        1234321L,
        4008004L,
        100020001L,
        102030201L,
        104060401L,
        121242121L,
        123454321L,
        125686521L,
        400080004L,
        404090404L,
        10000200001L,
        10221412201L,
        12102420121L,
        12345654321L,
        40000800004L,
        1000002000001L,
        1002003002001L,
        1004006004001L,
        1020304030201L,
        1022325232201L,
        1024348434201L,
        1210024200121L,
        1212225222121L,
        1214428244121L,
        1232346432321L,
        1234567654321L,
        4000008000004L,
        4004009004004L,
        100000020000001L,
        100220141022001L,
        102012040210201L,
        102234363432201L,
        121000242000121L,
        121242363242121L,
        123212464212321L,
        123456787654321L,
        400000080000004L,
        10000000200000001L,
        10002000300020001L,
        10004000600040001L,
        10020210401202001L,
        10022212521222001L,
        10024214841242001L,
        10201020402010201L,
        10203040504030201L,
        10205060806050201L,
        10221432623412201L,
        10223454745432201L,
        12100002420000121L,
        12102202520220121L,
        12104402820440121L,
        12122232623222121L,
        12124434743442121L,
        12321024642012321L,
        12323244744232321L,
        12343456865434321L,
        12345678987654321L,
        40000000800000004L,
        40004000900040004L,
        1000000002000000001L,
        1000220014100220001L,
        1002003004003002001L,
        1002223236323222001L,
        1020100204020010201L,
        1020322416142230201L,
        1022123226223212201L,
        1022345658565432201L,
        1210000024200000121L,
        1210242036302420121L,
        1212203226223022121L,
        1212445458545442121L,
        1232100246420012321L,
        1232344458544432321L,
        1234323468643234321L,
        4000000008000000004L
    };
    /*如果一个正整数自身是回文，而且它也是一个回文的平方，那么我们称这个数为超级回文
    现在，给定两个正整数L和R（以字符串形式表示），
    返回包含在范围[L,R]中的超级回文数的数目
    1<=len(L)<=18
    1<=len(R)<=18
    L和R是表示[1,10^18)范围内整数的字符串*/
    int LC906_superpalindromesInRange_(std::string left,std::string right);
    //直接用record数组来遍历寻找范围
    int LC906_superpalindromesInRange2_(std::string left,std::string right);
    //输出所有long类型的超级回文数
    std::vector<long long> LC906_superpalindromesInRange_(long long left,long long right);
    //生成奇数长度的回文
    long long LC906_superpalindromesInRange_evenEnlarge_(long long seed);
    //生成偶数长度的回文
    long long LC906_superpalindromesInRange_oddEnlarge_(long long seed);
    //判断是否在l，r内，以及是否是回文
    bool LC906_superpalindromesInRange_check_(unsigned long long num,long long l,long long r);
    //判断你是否是回文
    bool LC906_superpalindromesInRange_check_isPalindrome(long long num);
public:
    /*LeetCode 906 超级回文数的数目*/
    void Test_LC906_superpalindromesInRange();
};