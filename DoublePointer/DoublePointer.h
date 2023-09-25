#include"../unltle.h"

namespace Simple{
    using std::vector;
    using std::cout;
    using std::endl;
    using ll=int64_t;
    class DoubleSi{
    private:
        /*����һ���Ǹ��������� nums��  
        nums ��һ�������� ���� ��һ�������� ż�� ��
        ��������������Ա㵱 nums[i] Ϊ����ʱ��i Ҳ�� ���� ��
        �� nums[i] Ϊż��ʱ�� i Ҳ�� ż�� ��
        ����Է��� �κ���������������������Ϊ�� */
        vector<int> LC922_sortArrayByParityII(vector<int>& nums);
        //���������е���������λ��
        void Swap(vector<int>&nums,int i,int j);
    public:
        /*LeetCoed 922 ��ż������*/
        void Test_LC922_sortArrayByParityII();
    private:
        int LC287_findDuplicate(vector<int>& nums);
    public:
        /*LeetCode 287 Ѱ���ظ���*/
        void Test_LC287_findDuplicate();
    private:
        /*���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ��
        ���㰴�����е����ӣ�����֮���ܽӶ�����ˮ
        ���룺height = [0,1,0,2,1,0,1,3,2,1,2,1]
        �����6
        ���ͣ������������� [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ�ĸ߶�ͼ��
        ����������£����Խ� 6 ����λ����ˮ����ɫ���ֱ�ʾ��ˮ����*/
        int LC42_trap(vector<int>& height);
        /*˫ָ��ⷨ*/
        int LC42_trap_doublePoint(vector<int>& height);
    public:
        /*LeetCode 42 ����ˮ*/
        void Test_LC42_trap();
    private:
        /*�������� people ��people[i]��ʾ�� i ���˵����� ��
        �����������ޣ�ÿ�Ҵ����Գ��ص��������Ϊ limit��
        ÿ�Ҵ�����ͬʱ�����ˣ�����������Щ�˵�����֮�����Ϊ limit��
        ���� �����������������С���� ��
        ʾ�� 1��
        ���룺people = [1,2], limit = 3
        �����1
        ���ͣ�1 �Ҵ��� (1, 2)
        ʾ�� 2��
        ���룺people = [3,2,2,1], limit = 3
        �����3
        ���ͣ�3 �Ҵ��ֱ��� (1, 2), (2) �� (3)
        ʾ�� 3��
        ���룺people = [3,5,3,4], limit = 5
        �����4
        ���ͣ�4 �Ҵ��ֱ��� (3), (3), (4), (5)*/
        int LC881_numRescueBoats(vector<int>& people, int limit);
    public:
        /*LeetCode 881 ����ͧ*/
        void Test_LC881_numRescueBoats();
    private:
        /*����һ������Ϊ n ���������� height ���� n �����ߣ�
        �� i ���ߵ������˵��� (i, 0) �� (i, height[i]) ��
        �ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
        �����������Դ�������ˮ����
        ˵�����㲻����б������
        ���룺[1,8,6,2,5,4,8,3,7]
        �����49 
        ���ͣ�ͼ�д�ֱ�ߴ����������� [1,8,6,2,5,4,8,3,7]���ڴ�����£�
        �����ܹ�����ˮ����ʾΪ��ɫ���֣������ֵΪ 49��
        ʾ�� 2��
        ���룺height = [1,1]
        �����1*/
        int LC11_maxArea(vector<int>& height);
    public:
        /*LeetCoed 11 ʢˮ��������*/
        void Test_LC11_maxArea();
    private:
        /*�����Ѿ����١� ������������һ���й̶����Ȱ뾶�Ĺ�ů�������з��ݹ�ů��
        �ڼ������ļ��Ȱ뾶��Χ�ڵ�ÿ�����ݶ����Ի�ù�ů��
        ���ڣ�����λ��һ��ˮƽ���ϵķ��� houses �͹�ů�� heaters ��λ�ã�
        �����ҳ������ؿ��Ը������з��ݵ���С���Ȱ뾶��
        ˵�������й�ů������ѭ��İ뾶��׼�����ȵİ뾶Ҳһ����
        ʾ�� 1:
        ����: houses = [1,2,3], heaters = [2]
        ���: 1
        ����: ����λ��2����һ����ů����������ǽ����Ȱ뾶��Ϊ1��
        ��ô���з��ݾͶ��ܵõ���ů��
        ʾ�� 2:
        ����: houses = [1,2,3,4], heaters = [1,4]
        ���: 1
        ����: ��λ��1, 4����������ů����������Ҫ�����Ȱ뾶��Ϊ1��
        �������з��ݾͶ��ܵõ���ů��
        ʾ�� 3��
        ���룺houses = [1,5], heaters = [2]
        �����3
        ��ʾ��
        1 <= houses.length, heaters.length <= 3 * 104
        1 <= houses[i], heaters[i] <= 109*/
        int LC475_findRadius(vector<int>& houses, vector<int>& heaters);
        //��ǰ�ص�hourse[i]��heaters[j]��ů�Ƿ������ŵ�
        bool LC475_bast(vector<int>&house,vector<int>&heaters,int i,int j);
    public:
        /*LeetCode 475 ��ů��*/
        void Test_LC475_findRadius();
    private:
        /*����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������
        ����ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������
        ʾ�� 1��
        ���룺nums = [1,2,0]
        �����3
        ʾ�� 2��
        ���룺nums = [3,4,-1,1]
        �����2
        ʾ�� 3��
        ���룺nums = [7,8,9,11,12]
        �����1*/
        int LC41_firstMissingPositive(vector<int>& nums);
    public:
        /*LeetCode 41 ȱʧ�ĵ�һ������*/
        void Test_LC41_firstMissingPositive();
    };
    class DichotomyMethod{
    private:
        /*����ϲ�����㽶�������� n ���㽶���� i ������ piles[i] ���㽶��
        �����Ѿ��뿪�ˣ����� h Сʱ�������
        ������Ծ��������㽶���ٶ� k ����λ����/Сʱ����
        ÿ��Сʱ��������ѡ��һ���㽶�����гԵ� k ����
        �������㽶���� k ���������Ե���ѵ������㽶��
        Ȼ����һСʱ�ڲ����ٳԸ�����㽶��  
        ����ϲ�������ԣ�����Ȼ���ھ�������ǰ�Ե����е��㽶��
        ������������ h Сʱ�ڳԵ������㽶����С�ٶ� k��k Ϊ��������
        ʾ�� 1��
        ���룺piles = [3,6,7,11], h = 8
        �����4
        ʾ�� 2��
        ���룺piles = [30,11,23,4,20], h = 5
        �����30
        ʾ�� 3��
        ���룺piles = [30,11,23,4,20], h = 6
        �����23
        ��ʾ��
        1 <= piles.length <= 104
        piles.length <= h <= 109
        1 <= piles[i] <= 10^9*/    
        int LC875_minEatingSpeed(vector<int>& piles, int h);
        bool LC875_CatEatInTime(vector<int>&piles,int h,int seed);
    public:
        /*LeetCode 875 �����㽶������*/
        void Test_LC875_minEatingSpeed();
    private:    
        /*����һ���Ǹ��������� nums ��һ������ m ��
        ����Ҫ���������ֳ� m ���ǿյ����������顣
        ���һ���㷨ʹ���� m ����������Ժ͵����ֵ��С��
        ʾ�� 1��
        ���룺nums = [7,2,5,10,8], m = 2
        �����18
        ���ͣ�
        һ�������ַ����� nums �ָ�Ϊ 2 �������顣 
        ������õķ�ʽ�ǽ����Ϊ [7,2,5] �� [10,8] ��
        ��Ϊ��ʱ��������������Եĺ͵����ֵΪ18���������������С��
        ʾ�� 2��
        ���룺nums = [1,2,3,4,5], m = 2
        �����9
        ʾ�� 3��
        ���룺nums = [1,4,4], m = 3
        �����4
        ��ʾ��
        1 <= nums.length <= 1000
        0 <= nums[i] <= 10^6
        1 <= m <= min(50, nums.length)*/
        int LC410_splitArray(vector<int>& nums, int k);
        //��numsƽ������Ϊ<=k��ʹ��ÿһ���ֵ�ֵ��С�ڵ���m
        int LC410_splitArray_f(vector<int>&nums,int m);
    public:
        /*LeetCode 410 �ָ���������ֵ*/
        void Test_LC410_splitArray();
    private:
        /*��һ�������ˣ�û����һ��������������̨�ף����ͻ����Լ�������
        ��ȥ�������̨�׵Ĳ�ֵ(sum=sum-abs(sum-nums[i])),
        �����������һ������С������̨�ף����ͻ���������̨�׵Ĳ�ֵ
        (sum=sum+abs(sum-nums[i])),����������˳�ʼ����Ϊ����ʱ��ǡ��ͨ��*/
        void RobotPassThroughBuilding();
        int compute(vector<int>&nums,int l,int r,int max);
        bool compute_f(vector<int>&nums,int m,int max);
    public:
        /*�����˵�ͨ����Ϸ*/
        void Test_RobotPassThroughBuilding();
    private:
        /*���� (a,b) ������ a �� b ��ɣ������Ծ��붨��Ϊ a �� b �ľ��Բ�ֵ��
        ����һ���������� nums ��һ������ k �������� nums[i]��nums[j]
        ��������� 0 <= i < j < nums.length.
        �����������Ծ����е�kС�����Ծ��롣
        ʾ�� 1��
        ���룺nums = [1,3,1], k = 1
        �����0
        ���ͣ����ԺͶ�Ӧ�ľ������£�
        (1,3) -> 2
        (1,1) -> 0
        (3,1) -> 2
        ����� 1 С�������� (1,1) ������Ϊ 0 ��
        ʾ�� 2��
        ���룺nums = [1,1,1], k = 2
        �����0
        ʾ�� 3��
        ���룺nums = [1,6,1], k = 3
        �����5*/
        int LC719_smallestDistancePair(vector<int>& nums, int k);
        int LC719_smallestDistancePair_f(vector<int>& nums, int limit);
    public:
        /*LeetCode 719 �ҳ���kС�����Ծ���*/
        void Test_LC719_smallestDistancePair();
    private:
        /*���� n ̨���ԡ��������� n ��һ���±�� 0 ��ʼ���������� batteries ��
        ���е� i ����ؿ�����һ̨���� ���� batteries[i] ���ӡ�
        ����ʹ����Щ����� ȫ�� n ̨���� ͬʱ ���С�
        һ��ʼ������Ը�ÿ̨�������� ����һ����� ��Ȼ������������ʱ�̣�
        �㶼���Խ�һ̨���������ĵ�ضϿ����ӣ���������һ����أ�
        ����Խ���������� ����� �������ӵĵ�ؿ�����һ��ȫ�µĵ�أ�
        Ҳ�����Ǳ�ĵ����ù��ĵ�ء��Ͽ����Ӻ������µĵ�ز��Ứ���κ�ʱ�䡣
        ע�⣬�㲻�ܸ���س�硣
        ���㷵��������� n ̨����ͬʱ���е� � ��������
        ���룺n = 2, batteries = [1,1,1,1]
        �����2
        ���ͣ�
        һ��ʼ������һ̨�������� 0 ���ӣ��ڶ�̨�������� 2 ���ӡ�
        һ���Ӻ󣬵�� 0 �͵�� 2 ͬʱ�ľ�����������Ҫ�����ǶϿ����ӣ�
        ������� 1 �͵�һ̨�������ӣ���� 3 �͵ڶ�̨�������ӡ�
        1 ���Ӻ󣬵�� 1 �͵�� 3 Ҳ�ľ��ˣ�������̨���Զ��޷��������С�
        �������������̨����ͬʱ���� 2 ���ӣ��������Ƿ��� 2 ��
        ��ʾ��
        1 <= n <= batteries.length <= 10^5
        1 <= batteries[i] <= 10^9*/
        ll LC2141_maxRunTime(int n, vector<int>& batteries);
        //�����ж���n̨������ͬʱ����limitʱ�䣬�ܲ���
        bool LC2141_maxRunTime_f1(vector<int>&nums,int n,long limit);
    public:
        /*LeetCode 2141 ͬʱ����N̨���Ե��ʱ��*/
        void Test_LC2141_maxRunTime();
    private:
        /*�����λʱ��
        ����һ������arr����Ϊn����ʾn������Ա��ÿ����һ���˵�ʱ��
        ����һ��������m����ʾ��m���˵�λ��������Ǹ������ˣ���������Ҫ�ȶ��
        ����mԶԶ����n������n<=10^3��m<=10^9������ô�������Ž�O(m*log(n))*/
        int WaitingTime1(vector<int>arr,int m);
        /*ʹ�ö��ִ𰸷�O(n*log(min*m))*/
        int WaitingTime2(vector<int>arr,int m);
        /*�����˶�����m��Сʱ���ܸ����ٸ����ṩ����*/
        int WaitingTime2_f(vector<int>arr,int m);
    public:
        /*����Ա�������ʱ��*/
        void Test_WaitingTime();
    private:
        /*���޵ĳ�ʼѪ����һ������hp������ÿһ�غϺͶ�ɱ����ֵcuts��poisons
        ��i�غ�����õ�������������غϻ���ʧcuts[i]��Ѫ�������к���Ч��
        ��i�غ�����ö�ɱ����������غϲ�����ʧѪ��������֮���ÿ�غ϶�����ʧpoisons[i]
        ��Ѫ����������ѡ������ж�ɱЧ������֮��Ļغ϶�����ӣ�
        ��������cuts��poisons�����ȶ���n��������һ�����Խ���n�غ�
        ÿһ�غ���ֻ��ѡ�񵶿����߶�ɱ�е�һ������
        �������n���غ���û��ֱ��ɱ�������ζ�����Ѿ��޷����µ��ж���
        ���ǹ���������ж�Ч���Ļ�����ô������Ȼ�᲻ͣ�Ŀ�Ѫ��ֱ��Ѫ���ľ�
        ���ǻغ������������ٶ��ٻغϹ��޻�����
        1<=n<=10^5;  1<=hp<=10^9;    1<=cuts[i]��poisons[i]<=10^9;*/
        int SlashingPoisoning(vector<int>&cuts,vector<int>&poisons,int hp);
        /*��ά��̬�滮��������*/
        int SlashingPoisoning1(vector<int>&cuts,vector<int>&poisons,int hp);
        /*��times�غ���ʹ�õ������߶�ɱ�ܲ��ܴ�������*/
        bool SlashingPoisoning_f(vector<int>&cuts,vector<int>&poisons,long hp,int times);
        /*��̬�滮�Ӻ���*/
        int SlashingPoisoning_f1(vector<int>&cuts,vector<int>&poisons,int i,int r,int p,vector<vector<vector<int>>>dp);
    public:
        /*������ɱ��������*/
        void Test_SlashingPoisoning();
    private:
        /*����һ���������� ranks ����ʾһЩ��е���� ����ֵ ��
        ranksi �ǵ� i λ��е��������ֵ��
        ����ֵΪ r �Ļ�е�������� r * n2 �������޺� n ������
        ͬʱ����һ������ cars ����ʾ�ܹ���Ҫ�����������Ŀ��
        ���㷵�������������� ���� ��Ҫ����ʱ�䡣
        ע�⣺���л�е������ͬʱ����������
        ʾ�� 1��
        ���룺ranks = [4,2,3,1], cars = 10
        �����16
        ���ͣ�
        - ��һλ��е���� 2 ��������Ҫ 4 * 2 * 2 = 16 ���ӡ�
        - �ڶ�λ��е���� 2 ��������Ҫ 2 * 2 * 2 = 8 ���ӡ�
        - ����λ��е���� 2 ��������Ҫ 3 * 2 * 2 = 12 ���ӡ�
        - ����λ��е���� 4 ��������Ҫ 1 * 4 * 4 = 16 ���ӡ�
        16 ���������������г���Ҫ������ʱ�䡣
        ʾ�� 2��
        ���룺ranks = [5,1,8], cars = 6
        �����16
        ���ͣ�
        - ��һλ��е���� 1 ��������Ҫ 5 * 1 * 1 = 5 ���ӡ�
        - �ڶ�λ��е���� 4 ��������Ҫ 1 * 4 * 4 = 16 ���ӡ�
        - ����λ��е���� 1 ��������Ҫ 8 * 1 * 1 = 8 ���ӡ�
        16 ����ʱ���������г���Ҫ������ʱ�䡣
        ��ʾ��
        1 <= ranks.length <= 105
        1 <= ranks[i] <= 100
        1 <= cars <= 106*/
        long long LC2594_repairCars(vector<int>& ranks, int cars);
        bool LC2594_repairCars_f(vector<int>&ranks,int cars,int time);
    public:
        void Tset_LC2594_repairCars();
    };
}