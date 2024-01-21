#include"../unltle.h"

class Recursion{
private:
    //�ַ�����ȫ��������
    std::vector<std::string> generatePermutation_(std::string str);
    void generatePermutation_f1_(std::string s,int i,std::string&path,std::unordered_set<std::string>&set);
    void generatePermutation_f1_(std::string s,int i,char path[],int size,std::unordered_set<std::string>&set);
public:
    //�ַ�����ȫ��������
    void Test_generatePermutation();
private:
    /*����һ���������� nums ��
    ���п��ܰ����ظ�Ԫ�أ����㷵�ظ��������п��ܵ��Ӽ����ݼ�����
    �⼯ ���� �����ظ����Ӽ������صĽ⼯�У��Ӽ����԰� ����˳�� ���С�
    ʾ�� 1��
    ���룺nums = [1,2,2]
    �����[[],[1],[1,2],[1,2,2],[2],[2,2]]
    ʾ�� 2��
    ���룺nums = [0]
    �����[[],[0]]*/
    std::vector<std::vector<int>> subsetsWithDup_(std::vector<int>& nums);
    void subsetsWithDup_f1_(std::vector<int>&nums,int i,std::vector<int>&path,int size,std::vector<std::vector<int>>&ans);
public:
    //LeetCode 90 �Ӽ�II
    void Test_LC90_subsetsWithDup();
private:
    /*����һ�������ظ����ֵ����� nums ��
    ������ ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�
    ʾ�� 1��
    ���룺nums = [1,2,3]
    �����[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    ʾ�� 2��
    ���룺nums = [0,1]
    �����[[0,1],[1,0]]
    ʾ�� 3��
    ���룺nums = [1]
    �����[[1]]*/
    std::vector<std::vector<int>>LC46_permute_(std::vector<int>& nums);
    void LC46_premute_f_(std::vector<int>&nums,int index,std::vector<std::vector<int>>&ans);
    void Swap(std::vector<int>&nums,int i1,int i2);
public:
    /*LeetCode 46 ȫ����*/
    void Test_LC46_permute();
private:
    /*����ջ����*/
    void Reverse_Stack_(std::stack<int>&stk);
    int BottomOut_Stack_(std::stack<int>&stk);
public:
    /*����ջ*/
    void Test_Reverse_Stack_();
private:
    /*����ջ�е�Ԫ��*/
    void Sort_Stack_(std::stack<int>&stk);
    //���ջ�����
    int Deep_Stack_(std::stack<int>stk);
    //���ջ�е����Ԫ��
    int Max_Stack_(std::stack<int>stk,int deep);
    //������Ԫ�صĸ���
    int Times_Max_Stack_(std::stack<int>stk,int deep,int Max_num);
    //���Ԫ�س���
    void Down_Max_Stack_(std::stack<int>&stk,int deep,int Max_num,int times);
public:
    void Test_Sort_Stack();
private:
    //��ŵ������
    void HanNi_f_(int i,std::string from,std::string to,std::string other);
    void HanNi_f_(int n,std::vector<int>&A,std::vector<int>&B,std::vector<int>&C);
    //��ŵ��
    void HanNo_(int n);
public:
    //��ŵ
    void Test_HanNi();
private:
    /*ʵ��һ�������ļ�����������򵥵ı��ʽ�ַ���
    ���ʽ�ַ���ֻ�����Ǹ����������+��-��*��/����������()��
    ����������Ҫ���½ض�
    �ٶ����������б��ʽ������Ч�ģ������м���������
    [INT_MIN,INT_MAX]
    ��һ��
    ����s="1+1"
    �����2
    ������
    ����s="6-4/2"
    �����4
    ������
    ����s="2*(5+5*2)/3+(6/2+8)"
    �����21
    */
   int LC772_where;
   int LC772_Plus_Calculate_(std::string str);
   int LC772_Plus_Calculate_f_(std::string s,int i);
   void LC772_Plus_Push_(std::stack<int>&nums,std::stack<char>&ops,int cur,char op);
   int LC772_Plus_Compute_(std::stack<int>&nums,std::stack<char>&ops);
public:
    /*LeetCode 772 �������Ļ���ʵ��*/
    void Test_LC772_Plus_Calculate();
private:
    /*����һ������������ַ������������������ַ�����
    �������Ϊ: k[encoded_string]��
    ��ʾ���з������ڲ��� encoded_string �����ظ� k �Ρ�
    ע�� k ��֤Ϊ��������
    �������Ϊ�����ַ���������Ч�ģ�
    �����ַ�����û�ж���Ŀո�������ķ��������Ƿ��ϸ�ʽҪ��ġ�
    ���⣬�������Ϊԭʼ���ݲ��������֣�
    ���е�����ֻ��ʾ�ظ��Ĵ��� k ��
    ���粻������� 3a �� 2[4] �����롣
    ʾ�� 1��
    ���룺s = "3[a]2[bc]"
    �����"aaabcbc"
    ʾ�� 2��
    ���룺s = "3[a2[c]]"
    �����"accaccacc"
    ʾ�� 3��
    ���룺s = "2[abc]3[cd]ef"
    �����"abcabccdcdcdef"
    ʾ�� 4��
    ���룺s = "abc3[cd]xyz"
    �����"abccdcdcdxyz"*/
    int LC394_where;
    std::string LC394_decodeString_(std::string s);
    std::string LC394_decodeString_f_(std::string s,int i);
    std::string LC394_Push_(int cur,std::string ch);
public:
    /*LeetCode 394 �ַ�������*/
    void Test_LC394_decodeString_();
private:
    /*����һ���ַ�����ѧʽ formula ������ ÿ��ԭ�ӵ����� ��
    ԭ��������һ����д��ĸ��ʼ�����Ÿ��� 0 ���������Сд��ĸ����ʾԭ�ӵ����֡�
    ����������� 1��ԭ�Ӻ��������ֱ�ʾԭ�ӵ�������
    ����������� 1 �򲻻�����֡�
    ���磬"H2O" �� "H2O2" �ǿ��еģ��� "H1O2" �������ǲ����еġ�
    ������ѧʽ����һ����Թ����µĻ�ѧʽ��
    ���� "H2O2He3Mg4" Ҳ�ǻ�ѧʽ��
    ����������Ļ�ѧʽ���������֣���ѡ������ӣ�Ҳ�ǻ�ѧʽ��
    ���� "(H2O2)" �� "(H2O2)3" �ǻ�ѧʽ��
    ��������ԭ�ӵ���������ʽΪ����һ�������ֵ���ԭ�ӵ����֣�
    ������������������������� 1����Ȼ���ǵڶ���ԭ�ӵ����֣����ֵ��򣩣�
    ������������������������� 1�����Դ����ơ�
    ʾ�� 1��
    ���룺formula = "H2O"
    �����"H2O"
    ���ͣ�ԭ�ӵ������� {'H': 2, 'O': 1}��
    ʾ�� 2��
    ���룺formula = "Mg(OH)2"
    �����"H2MgO2"
    ���ͣ�ԭ�ӵ������� {'H': 2, 'Mg': 1, 'O': 2}��
    ʾ�� 3��
    ���룺formula = "K4(ON(SO3)2)2"
    �����"K4N2O14S4"
    ���ͣ�ԭ�ӵ������� {'K': 4, 'N': 2, 'O': 14, 'S': 4}��*/
    int LC726_where;
    std::string LC726_countOfAtoms_(std::string formula);
    std::unordered_map<std::string,int>LC726_countOfAtoms_f_(std::string str,int i);
    void LC726_countOfAtoms_fill_(std::unordered_map<std::string,int>&ans,std::string name,std::unordered_map<std::string,int>&pre,int cur);
public:
    /*LeetCode 726 ԭ�ӵ�����*/
    void Test_LC726_countOfAtoms_();
private:
    /*N�ʺ�����*/
    int LC52_totalNQueens_(int n);
    /*N�ʺ�����λ����*/
    int LC52_totalNQueens2_(int n);

    //�ݹ������н������
    int LC52_totalNQueens_f_(int i,std::vector<int>&path,int n);
    //λ����Ľ������
    /*limit:��ʾ��ǰ�Ǽ��ʺ�����
    col��֮ǰ�Ļʺ���е�Ӱ��
    left��֮ǰ�Ļʺ������->���µĶԽ��ߵ�Ӱ��
    right��֮ǰ�Ļʺ�����ϵ����¶Խ��ߵ�Ӱ��*/
    int LC52_totalNQueens_f_(int limit,int col,int left,int right);
    //��鵱ǰλ���Ƿ���Է���
    bool LC52_check_(std::vector<int>&path,int i,int j);
public:
    //LeetCode 52 N�ʺ�
    void Test_LC52_totalNQueens_();
private:
    /*���Լ��*/
    long GreatestCommonDivisor_(long a,long b){
        return b==0?a:GreatestCommonDivisor_(b,a%b);
    }
    /*��С������*/
    long Lcm(long a,long b){
        return (long)a/GreatestCommonDivisor_(a,b)*b;
    }
public:
    void Test_GreatestCommonDivisor();
private:    
    /*һ������������ܱ� a �� b ��������ô��������ġ�
    ������������ n , a , b �����ص� n ����������֡�
    ��Ϊ�𰸿��ܴܺ����Է��ش� �� 10^9 + 7 ȡģ ���ֵ��
    ʾ�� 1��
    ���룺n = 1, a = 2, b = 3
    �����2
    ʾ�� 2��
    ���룺n = 4, a = 2, b = 3
    �����6*/
    int LC878_nthMagicalNumber_(int n,int a,int b);
public:
    /*LeetCode 878 ��N�����������*/
    void Test_LC878_nthMagicalNumber();
private:
    /*��6���Ĵ��Ӹ�8���Ĵ��ӣ�װn��ƻ��������ɵĽ�������Ƕ��ٸ�����
    ���װ���������򷵻�-1*/
    int AppleMinBags_(int apple);
    /*�����ݹ�*/
    int AppleMinBags_f_(int apple);
    /*���ɲ�ѯ*/
    int AppleMinBags_f2_(int apple);
public:
    void Test_AppleMinBags();
private:
    /*��һ����n����������ֻţ�����Բݣ�Aţ�ȳԣ�Bţ���
    ÿֻţ���Լ��Ļغϣ��Բݵ�����������4���ݣ�1��4��16��64
    ˭���Լ��Ļغ����ðѲݳ���˭Ӯ�����������n������˭Ӯ*/
    std::string EatGrass_win1_(int n);
    /*rest:��ʣ���ٲ�
    cur:��ǰѡ�ֵ�����
    ��ʣrest�ݲݣ���ǰѡ����cur����������˭Ӯ*/
    std::string EatGrass_win1_f1_(int rest,std::string cur);
    /*���ɰ�*/
    std::string EatGrass_win1_f2_(int rest,std::string cur);
public:
    /*A��B�����Բ�˭��Ӯ*/
    void Test_EatGrass_win1();
private:
    /*�ж�һ�����Ƿ�����������������������*/
    bool IsSumOfConsecutiveNumbers_is1_(int num);
    /*���ɰ� */
    bool IsSumOfConsecutiveNumbers_is2_(int num);
public:
    void Test_IsSumOfConsecutiveNumbers();
private:
    /*�����ַ��������ҽ���һ�����ȴ��ڵ���2�Ļ����Ӵ�
    �������ô�*/
    /*ֻʹ��r��e��d�������ַ�ƴ������Ϊn���ַ������ж��ٸ��ô�*/
    int RedPalindromeGoodStrings_num1(int n);
    /*���ɰ�*/
    int RedPalindromeGoodStrings_num2(int n);
    //�ݹ������ַ���
    int RedPalindromeGoodStrings_num1_f(std::string path,int i,int n);
    //�ж��Ƿ�Ϊ����
    bool RedPalindromeGoodStrings_num1_is_(std::string path,int left,int right);
public:
    /*�ַ������ж��ٸ��ô�*/
    void Test_RedPalindromeGoodStrings_num1();
};