#include"../unltle.h"

namespace Monque{
    using std::vector;
    using std::cout;
    using std::endl;
    using std::queue;
    using std::string;
    using std::deque;
    class Ques{
    private:
        /*����һ���������� nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k �����֡���������ÿ��ֻ�����ƶ�һλ��
        ���� ���������е����ֵ ��
        ʾ�� 1��
        ���룺nums = [1,3,-1,-3,5,3,6,7], k = 3
        �����[3,3,5,5,6,7]
        ���ͣ�
        �������ڵ�λ��                ���ֵ
        ---------------               -----
        [1  3  -1] -3  5  3  6  7       3
        1 [3  -1  -3] 5  3  6  7       3
        1  3 [-1  -3  5] 3  6  7       5
        1  3  -1 [-3  5  3] 6  7       5
        1  3  -1  -3 [5  3  6] 7       6
        1  3  -1  -3  5 [3  6  7]      7
        ʾ�� 2��
        ���룺nums = [1], k = 1
        �����[1]
        ��ʾ��
        1 <= nums.length <= 105
        -104 <= nums[i] <= 104
        1 <= k <= nums.length*/
        vector<int> LC239_maxSlidingWindow(vector<int>& nums, int k);
    public:
        /*LeetCode 239 �����������ֵ*/
        void Test_LC239_maxSlidingWindow();
    private:
        /*����һ���������� nums ����һ����ʾ���Ƶ����� limit�����㷵�������������ĳ��ȣ����������е���������Ԫ��֮��ľ��Բ����С�ڻ��ߵ��� limit ��
        ������������������������飬�򷵻� 0 ��
        ʾ�� 1��
        ���룺nums = [8,2,4,7], limit = 4
        �����2 
        ���ͣ��������������£�
        [8] �����Բ� |8-8| = 0 <= 4.
        [8,2] �����Բ� |8-2| = 6 > 4. 
        [8,2,4] �����Բ� |8-2| = 6 > 4.
        [8,2,4,7] �����Բ� |8-2| = 6 > 4.
        [2] �����Բ� |2-2| = 0 <= 4.
        [2,4] �����Բ� |2-4| = 2 <= 4.
        [2,4,7] �����Բ� |2-7| = 5 > 4.
        [4] �����Բ� |4-4| = 0 <= 4.
        [4,7] �����Բ� |4-7| = 3 <= 4.
        [7] �����Բ� |7-7| = 0 <= 4. 
        ��ˣ�����������������ĳ���Ϊ 2 ��
        ʾ�� 2��
        ���룺nums = [10,1,2,4,7,2], limit = 5
        �����4 
        ���ͣ������������������� [2,4,7,2]���������Բ� |2-7| = 5 <= 5 ��
        ʾ�� 3��
        ���룺nums = [4,2,2,2,4,4,2,2], limit = 0
        �����3
        ��ʾ��
        1 <= nums.length <= 10^5
        1 <= nums[i] <= 10^9
        0 <= limit <= 10^9*/
        int LC1438_longestSubarray(vector<int>& nums, int limit);
        //�жϴ����е��������Ƿ���
        bool LC1438_longestSubarray_Ok(deque<int>&MinQ,deque<int>&MaxQ,int limit,int num,vector<int>& nums);
        //�������е������봰��
        void LC1438_longestSubarray_Push(vector<int>& nums,deque<int>&MinQ,deque<int>&MaxQ,int r);
        //������
        void LC1438_longestSubarray_Pop(deque<int>&MinQ,deque<int>&MaxQ,int l);
    public:
        /*LeetCode 1438 ����ֵ��������Ƶ������������*/
        void Test_LC1438_longestSubarray();
    private:
        /*�ϰ���Ҫ���æ���������� N ��ˮ�����꣬
        y ��ʾˮ�εĸ߶ȣ�x ��ʾ�����䵽 x ���λ�á�ÿ��ˮ��ÿ�� 1
        1 ����λ���ȵ��ٶ����䡣����Ҫ�ѻ������ 
        x ���ϵ�ĳ��λ�ã�ʹ�ôӱ�������ŵĵ� 1
        1 ��ˮ��ʼ������������ŵ���� 1
        1 ��ˮ������֮���ʱ�������Ϊ D��
        ������Ϊ��ֻҪˮ���䵽 x ���ϣ��뻨��ı��ض��룬
        ����Ϊ����ס������ N ��ˮ������� D �Ĵ�С���������С�Ļ���Ŀ�� W��*/
        int LGP2698_FallingWaterSmallestFlowerPot();
        int LGP2698_FallingWaterSmallestFlowerPot_compute(vector<vector<int>>&arr,int n,int d);
        //�жϵ�ǰ�����ܲ�����
        bool LGP2698_FallingWaterSmallestFlowerPot_compute_Ok(vector<vector<int>>&arr,deque<int>&MaxQ,deque<int>&MinQ,int d);
        //�򴰿��в���Ԫ��
        void LGP2698_FallingWaterSmallestFlowerPot_compute_Push(vector<vector<int>>&arr,deque<int>&MaxQ,deque<int>&MinQ,int r);
        //�Ӵ������Ƴ�Ԫ�� 
        void LGP2698_FallingWaterSmallestFlowerPot_compute_Pop(vector<vector<int>>&arr,deque<int>&MaxQ,deque<int>&MinQ,int l);
    public:
        /*���P2698 ��ȡ��ˮ����С����*/
        void Test_LGP2698_FallingWaterSmallestFlowerPot();
    private:
        /*����һ���������� nums ��һ������ k ��
        �ҳ� nums �к�����Ϊ k �� ��̷ǿ������� ��
        �����ظ�������ĳ��ȡ���������������� ������ ������ -1 ��
        ������ �������� ���� ��һ���֡�
        ʾ�� 1��
        ���룺nums = [1], k = 1
        �����1
        ʾ�� 2��
        ���룺nums = [1,2], k = 4
        �����-1
        ʾ�� 3��
        ���룺nums = [2,-1,2], k = 3
        �����3
        ��ʾ��
        1 <= nums.length <= 105
        -105 <= nums[i] <= 105
        1 <= k <= 109*/
        int LC862_shortestSubarray(vector<int>& nums, int k);
    public:
        /*LeetCode 862 ������Ϊk�����������*/
        void LC862_shortestSubarray();
    private:
        /*����һ������ points ��һ������ k ��
        ������ÿ��Ԫ�ض���ʾ��άƽ���ϵĵ�����꣬
        �����պ����� x ��ֵ��С��������
        Ҳ����˵ points[i] = [xi, yi] ��
        ������ 1 <= i < j <= points.length ��ǰ���£� xi < xj �ܳ�����
        �����ҳ� yi + yj + |xi - xj| �� ���ֵ��
        ���� |xi - xj| <= k �� 1 <= i < j <= points.length��
        ��Ŀ�������ݱ�֤���ٴ���һ���ܹ����� |xi - xj| <= k �ĵ㡣
        ʾ�� 1��
        ���룺points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
        �����4
        ���ͣ�ǰ���������� |xi - xj| <= 1 ��
        ���뷽�̼��㣬��õ�ֵ 3 + 0 + |1 - 2| = 4 ��
        �������͵��ĸ���Ҳ�����������õ�ֵ 10 + -10 + |5 - 6| = 1 ��
        û���������������ĵ㣬���Է��� 4 �� 1 �������Ǹ���
        ʾ�� 2��
        ���룺points = [[0,0],[3,0],[9,2]], k = 3
        �����3
        ���ͣ�ֻ��ǰ���������� |xi - xj| <= 3 ��
        ���뷽�̺�õ�ֵ 0 + 0 + |0 - 3| = 3 ��
        ��ʾ��
        2 <= points.length <= 10^5
        points[i].length == 2
        -10^8 <= points[i][0], points[i][1] <= 10^8
        0 <= k <= 2 * 10^8
        �������е�1 <= i < j <= points.length ��
        points[i][0] < points[j][0] ��������
        Ҳ����˵��xi ���ϸ�����ġ�*/
        int LC1499_findMaxValueOfEquation(vector<vector<int>>& points, int k);
    public:
        /*LeetCode 1499 ���㲻��ʽ�����ֵ*/
        void Test_LC1499_findMaxValueOfEquation();
    private:
        /*���� n ������� m �����ˡ�ÿ��������Ҫһ��������ֵ������ɣ�
        ��Ҫ������ֵ�������±�� 0 ��ʼ���������� tasks �У�
        �� i ��������Ҫ tasks[i] ������������ɡ�
        ÿ�����˵�����ֵ�������±�� 0 ��ʼ���������� workers �У�
        �� j �����˵�����ֵΪ workers[j] ��
        ÿ������ֻ����� һ�� ����������ֵ��Ҫ 
        ���ڵ��� �����������Ҫ��ֵ���� workers[j] >= tasks[i] ����
        �������⣬�㻹�� pills ������ҩ�裬���Ը� һ�����˵�����ֵ ���� strength ��
        ����Ծ�������Щ����ʹ��ҩ�裬��ÿ������ ��� ֻ��ʹ�� һƬ ҩ�衣
        �����±�� 0 ��ʼ����������tasks �� workers 
        �Լ��������� pills �� strength �����㷵�� ��� �ж��ٸ�������Ա���ɡ�
        ʾ�� 1��
        ���룺tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
        �����3
        ���ͣ�
        ���ǿ��԰������·�������ҩ�裺
        - �� 0 �Ź���ҩ�衣
        - 0 �Ź���������� 2��0 + 1 >= 1��
        - 1 �Ź���������� 1��3 >= 2��
        - 2 �Ź���������� 0��3 >= 3��
        ʾ�� 2��
        ���룺tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
        �����1
        ���ͣ�
        ���ǿ��԰������·�������ҩ�裺
        - �� 0 �Ź���ҩ�衣
        - 0 �Ź���������� 0��0 + 5 >= 5��
        ʾ�� 3:
        ���룺tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
        �����2
        ���ͣ�
        ���ǿ��԰������·�������ҩ�裺
        - �� 0 �ź� 1 �Ź���ҩ�衣
        - 0 �Ź���������� 0��0 + 10 >= 10��
        - 1 �Ź���������� 1��10 + 10 >= 15��
        ʾ�� 4��
        ���룺tasks = [5,9,8,5,9], workers = [1,6,4,2,6], pills = 1, strength = 5
        �����3
        ���ͣ�
        ���ǿ��԰������·�������ҩ�裺
        - �� 2 �Ź���ҩ�衣
        - 1 �Ź���������� 0��6 >= 5��
        - 2 �Ź���������� 2��4 + 5 >= 8��
        - 4 �Ź���������� 3��6 >= 5��
        ��ʾ��
        n == tasks.length
        m == workers.length
        1 <= n, m <= 5 * 10^4
        0 <= pills <= m
        0 <= tasks[i], workers[j], strength <= 10^9*/
        int LC2071_maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength);
        bool LC2071_maxTaskAssign_f(vector<int>& tasks, vector<int>& workers, int tl,int tr,int wl,int wr,int s,int pills);
        public:
        /*LeetCode 2071 ����԰��ŵ����������Ŀ*/
        void Test_LC2071_maxTaskAssign();
    };
}
