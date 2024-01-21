#include"../unltle.h"

class AmountFOfData{
private:
    /*������һ��������͵���Ϸ�������Ϸ�������ģ�����n������
    ÿһ�����ܻ���һ���˺�
    ͬʱ���ɹ���С�ڵ���һ����Ѫ������ü��ܿ������˫�����˺�
    ÿ���������ֻ���ͷ�һ�Σ���֪������m��Ѫ��
    ���������������ü�����������������Ѫ��С�ڵ���0��
    ���ܵ�������n�������Ѫ����m
    i�ż��ܵĴ�����˫���˺���Ѫ����Сֵ��y[i]
    1<=n<=10
    1<=m��x[i]��y[i]<=10^6*/
    int MAXN=11;
    //���ܵĵ����˺�
    std::vector<int>kill;
    //���ܵ�˫���˺�Ѫ����ֵ
    std::vector<int>blood;
    int KillMonsterEverySkillUseOnce_(int n,int m,std::vector<int>kill,std::vector<int>blood);
    /*n��һ����������
    i����ǰ���ڼ�������
    r������ʣ���Ѫ��*/
    int KillMonsterEverySkillUseOnce_f_(int n,int i,int r);
    /*���������е�ֵ*/
    void KillMonsterEverySkillUseOnce_Swap_(int i,int j);
public:
    //���ٶ��ٸ����ܿ���ɱ����
    void Test_cin_KillMonsterEverySkillUseOnce();
    //���ٶ��ٸ����ܿ���ɱ����
    void Test_KillMonsterEverySkillUseOnce();
private:
    //�����㷨���ɵĽ����
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
    /*���һ�������������ǻ��ģ�������Ҳ��һ�����ĵ�ƽ������ô���ǳ������Ϊ��������
    ���ڣ���������������L��R�����ַ�����ʽ��ʾ����
    ���ذ����ڷ�Χ[L,R]�еĳ�������������Ŀ
    1<=len(L)<=18
    1<=len(R)<=18
    L��R�Ǳ�ʾ[1,10^18)��Χ���������ַ���*/
    int LC906_superpalindromesInRange_(std::string left,std::string right);
    //ֱ����record����������Ѱ�ҷ�Χ
    int LC906_superpalindromesInRange2_(std::string left,std::string right);
    //�������long���͵ĳ���������
    std::vector<long long> LC906_superpalindromesInRange_(long long left,long long right);
    //�����������ȵĻ���
    long long LC906_superpalindromesInRange_evenEnlarge_(long long seed);
    //����ż�����ȵĻ���
    long long LC906_superpalindromesInRange_oddEnlarge_(long long seed);
    //�ж��Ƿ���l��r�ڣ��Լ��Ƿ��ǻ���
    bool LC906_superpalindromesInRange_check_(unsigned long long num,long long l,long long r);
    //�ж����Ƿ��ǻ���
    bool LC906_superpalindromesInRange_check_isPalindrome(long long num);
public:
    /*LeetCode 906 ��������������Ŀ*/
    void Test_LC906_superpalindromesInRange();
};