#include"../unltle.h"
namespace Monotonous{
    using std::vector;
    using std::cout;
    using std::endl;
    using std::string;
    class MonStack{
    private:    
        /*Ѱ��������ÿ������ߺ��ұߵ�1�����Լ�С������û�о���-1*/
        vector<vector<int>>ANumbeSmallerThanYourself(vector<int>&nums);
        /*Ѱ�ҵ�ǰ������ߵ�һ�����Լ�С����*/
        int ANumbeSmallerThanYourself_left(vector<int>&nums,int i);
        /*Ѱ�ҵ�ǰ�����ұߵ�һ�����Լ�С����*/
        int ANumbeSmallerThanYourself_right(vector<int>&nums,int i);
        /*����ջ�ⷨ*/
        vector<vector<int>>ANumbeSmallerThanYourself_stack(vector<int>&nums);
    public:
        /*Ѱ��������ÿ������ߺ��ұߵ�1�����Լ�С������û�о���-1*/
        void Test_ANumbeSmallerThanYourself();
    private:
        /*�����ÿ�� ���� �б� temperatures ��
        ��������һ���б�Ҫ�����Ӧλ�õ����Ϊ��
        Ҫ��۲⵽���ߵ����£�������Ҫ�ȴ���������
        �����������֮�󶼲������ߣ����ڸ�λ���� 0 �����档
        ʾ�� 1:
        ����: temperatures = [73,74,75,71,69,72,76,73]
        ���: [1,1,4,2,1,1,0,0]
        ʾ�� 2:
        ����: temperatures = [30,40,50,60]
        ���: [1,1,1,0]
        ʾ�� 3:
        ����: temperatures = [30,60,90]
        ���: [1,1,0]
        1 <= temperatures.length <= 10^5
        30 <= temperatures[i] <= 100*/
        vector<int> LC739_dailyTemperatures(vector<int>& temperatures);
    public:
        /*LeetCode 739 ÿ���¶�*/
        void Test_LC739_dailyTemperatures();
    private:
        /*����һ���������� arr���ҵ� min(b) ���ܺͣ����� b �ķ�ΧΪ arr ��ÿ���������������顣
        ���ڴ𰸿��ܴܺ���� ���ش�ģ 10^9 + 7 ��
        ʾ�� 1��
        ���룺arr = [3,1,2,4]
        �����17
        ���ͣ�
        ������Ϊ [3]��[1]��[2]��[4]��[3,1]��[1,2]��[2,4]��[3,1,2]��[1,2,4]��[3,1,2,4]�� 
        ��СֵΪ 3��1��2��4��1��1��2��1��1��1����Ϊ 17��
        ʾ�� 2��
        ���룺arr = [11,81,94,43,3]
        �����444
        ��ʾ��
        1 <= arr.length <= 3 * 10^4
        1 <= arr[i] <= 3 * 10^4*/
        const int MOD=1000000007;
        int LC907_sumSubarrayMins(vector<int>& arr);
    public:
        /*LeetCode 907 ���������Сֵ֮��*/
        void Test_LC907_sumSubarrayMins();
    private:
        /*���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�
        ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��
        ���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
        ʾ�� 1:
        ���룺heights = [2,1,5,6,2,3]
        �����10
        ���ͣ����ľ���Ϊͼ�к�ɫ�������Ϊ 10
        ʾ�� 2��
        ���룺 heights = [2,4]
        ����� 4*/
        int LC74_largestRectangleArea(vector<int>& heights);
    public:
        /*LeetCode 84 ��״ͼ�����ľ���*/
        void Test_LC74_largestRectangleArea();
    private:
        /*����һ�������� 0 �� 1 ����СΪ rows x cols �Ķ�ά�����ƾ���
        �ҳ�ֻ���� 1 �������Σ��������������
        ʾ�� 1��
        ���룺matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
        �����6
        ���ͣ�����������ͼ��ʾ��
        ʾ�� 2��
        ���룺matrix = []
        �����0
        ʾ�� 3��
        ���룺matrix = [["0"]]
        �����0
        ʾ�� 4��
        ���룺matrix = [["1"]]
        �����1
        ʾ�� 5��
        ���룺matrix = [["0","0"]]
        �����0*/
        int LC85_maximalRectangle(vector<vector<int>>& matrix);
        int LC85_maximalRectangle_f(vector<int>arr);
    public:
        /*LeetCode 85 ������*/
        void Test_LC85_maximalRectangle();
    private:
        /*����һ���������� A������Ԫ�� (i, j)������  i < j �� A[i] <= A[j]���������µĿ��Ϊ j - i��
        �ҳ� A �е��µ�����ȣ���������ڣ����� 0 ��
        ʾ�� 1��
        ���룺[6,0,8,2,1,5]
        �����4
        ���ͣ�
        ����ȵ���Ϊ (i, j) = (1, 5): A[1] = 0 �� A[5] = 5.
        ʾ�� 2��
        ���룺[9,8,1,0,1,9,4,0,4,1]
        �����7
        ���ͣ�
        ����ȵ���Ϊ (i, j) = (2, 9): A[2] = 1 �� A[9] = 1.
        ��ʾ��
        2 <= A.length <= 50000
        0 <= A[i] <= 50000*/
        int LC962_maxWidthRamp(vector<int>& nums);
    public:
        /*LeetCode 962 ����¿��*/
        void Test_LC962_maxWidthRamp();
    private:
        /*����һ���ַ��� s ������ȥ���ַ������ظ�����ĸ��
        ʹ��ÿ����ĸֻ����һ�Ρ��豣֤ ���ؽ�����ֵ�����С
        ��Ҫ���ܴ��������ַ������λ�ã���
        ʾ�� 1��
        ���룺s = "bcabc"
        �����"abc"
        ʾ�� 2��
        ���룺s = "cbacdcbc"
        �����"acdb"
        ��ʾ��
        1 <= s.length <= 10^4
        s ��СдӢ����ĸ���*/
        string LC316_removeDuplicateLetters(string s);
    public:
        /*LeetCode 316 ȥ���ظ���ĸ*/
        void Test_LC316_removeDuplicateLetters();
    private:
        /*����һ������arr��ÿ��ֵ�����������ÿһ�֣�
        ÿ���㶼��Ե��ұ����Լ�������Լ�����С���㣬ÿ���������ҳ�һֻ
        ���ǳ������������ͬʱ�����ģ�Ҳ����ͬһ����A�Ե�B��ͬʱ��AҲ���ܱ������Ե�
        ����ж������ڵ�ǰ���ҵ�����ͬһ���㣬��ô����һ�֣�����С��ͬʱ����Щ�����
        ���ʶ����ֺ���������̶���
        ���磺8,3,1,5,6,7,2,4
        ��һ�֣�8��3��3��1��5��6��7��2��4û�б��ԣ�����ʣ��8,5,6,7,4
        �ڶ��֣�8��5��5��6��7��4.����ʣ��8,6,7
        �����֣�8��6������ʣ��7
        �����֣�8��7.����ʣ��8.
        ���̽���������4
        ���磺8,3,7,3,4,5,6*/
        void BigFishEatSmallFish();
        /*����ջ���������������ÿһ������*/
        int BigFishEatSmallFish_turns(vector<int>arr);
    public:
        /*�����С������*/
        void Test_BigFishEatSmallFish();
    private:
        /*����һ�� m x n �Ķ����ƾ��� mat �����㷵���ж��ٸ� �Ӿ��� ��Ԫ��ȫ������ 1 ��
        ʾ�� 1��
        ���룺mat = [[1,0,1],[1,1,0],[1,1,0]]
        �����13
        ���ͣ�
        �� 6 �� 1x1 �ľ��Ρ�
        �� 2 �� 1x2 �ľ��Ρ�
        �� 3 �� 2x1 �ľ��Ρ�
        �� 1 �� 2x2 �ľ��Ρ�
        �� 1 �� 3x1 �ľ��Ρ�
        ������Ŀ�ܹ� = 6 + 2 + 3 + 1 + 1 = 13 ��
        ʾ�� 2��
        ���룺mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
        �����24
        ���ͣ�
        �� 8 �� 1x1 ���Ӿ��Ρ�
        �� 5 �� 1x2 ���Ӿ��Ρ�
        �� 2 �� 1x3 ���Ӿ��Ρ�
        �� 4 �� 2x1 ���Ӿ��Ρ�
        �� 2 �� 2x2 ���Ӿ��Ρ�
        �� 2 �� 3x1 ���Ӿ��Ρ�
        �� 1 �� 3x2 ���Ӿ��Ρ�
        ������Ŀ�ܹ� = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24 ��
        ��ʾ��
        1 <= m, n <= 150
        mat[i][j] ������ 0 �� 1*/
        int LC1504_numSubmat(vector<vector<int>>& mat);
        int LC1504_numSubmat_f(vector<int>arr);
    public:
        /*LeetCode 1504 ͳ��ȫ1�Ӿ���*/
        void Test_LC1504_numSubmat();
        
    };
}
