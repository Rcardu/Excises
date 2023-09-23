#include"../unltle.h"
namespace Difference{
using std::vector;
using std::cout;
static int MAXN=100005;
vector<int>arr(MAXN,0);
    class Arithmetic{
        //һά���
    private:
        /*������ n �����࣬���Ƿֱ�� 1 �� n ���б�š�
        ��һ�ݺ���Ԥ���� bookings �����е� i ��Ԥ����¼ 
        bookings[i] = [firsti, lasti, seatsi] ��ζ���ڴ� firsti �� lasti 
        ������ firsti �� lasti ���� ÿ������ ��Ԥ���� seatsi ����λ��
        ���㷵��һ������Ϊ n ������ answer�������Ԫ����ÿ������Ԥ������λ������
        ʾ�� 1��
        ���룺bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
        �����[10,55,45,25,25]
        ���ͣ�
        ������        1   2   3   4   5
        Ԥ����¼ 1 ��   10  10
        Ԥ����¼ 2 ��       20  20
        Ԥ����¼ 3 ��       25  25  25  25
        ����λ����      10  55  45  25  25
        ��ˣ�answer = [10,55,45,25,25]
        ʾ�� 2��
        ���룺bookings = [[1,2,10],[2,2,15]], n = 2
        �����[10,25]
        ���ͣ�
        ������        1   2
        Ԥ����¼ 1 ��   10  10
        Ԥ����¼ 2 ��       15
        ����λ����      10  25
        ��ˣ�answer = [10,25]*/
        vector<int>LC1109_corpFlightBookings_(vector<vector<int>>&bookings,int n);
    public:
        /*LeetCode 1109 ����Ԥ��ͳ��*/
        void Test_LC1109_corpFlightBookings();
    private:
        /*��� P4231
        N�������ų�һ�ţ�һ��ʼÿ���������˶�Ϊ0��
        ���������ǻ����
        M�ι�����ÿ�ι���������4������l,r,s,e��������
        ��ʾ��ι������÷�ΧΪ��l������r��֮�����е�����(����l,r)��
        �Ե�һ�����ӵ��˺�Ϊs�������һ�����ӵ��˺�Ϊe��
        �����������˺�ֵ��һ���Ȳ����С���l=1,r=5,s=2,e=10��
        ��Ե�1~5�����ӷֱ����2,4,6,8,10���˺���
        ��������Ҫ�������й������֮��ÿ�����ӵ����˶ȡ�*/
        void LGP4231_build(int n);
        void LGP4231_set(int l,int r,int s,int e,int d);
    private:
        int n,m;
    public:
        /*��� P4231*/
        void LGP4231_ArithmeticSeqenceDifference();
    };

}
namespace Lycanthropy{
    using std::vector;
    using std::cout;
    using std::endl;
    using std::sort;
    static int OFFSET=30001;
    static int MAXN=1000006;
    vector<int>arr(MAXN+2*OFFSET,0);
    int n,m;

    class LycanthropyInBack{
    private:
       /*��� P5026 Lycanthropy*/
       void LGP5026_set(int l,int r,int s,int e,int d);
       void LGP5026_fall(int v,int x);
       void LGP5026_build(int m);
    public:
        /*��� P5026 Lycanthropy*/
        void Test_LGP5026_Lycanthropy();
        //n�ж��ٸ�����ˮ��ÿ������ˮ����ζ���ĸ����еĲ���
    private:
        /*����һ�� m x n �Ķ����ƾ��� grid ��
        ÿ������ҪôΪ 0 ���գ�ҪôΪ 1 ����ռ�ݣ���
        ������Ʊ�ĳߴ�Ϊ stampHeight x stampWidth ��
        �����뽫��Ʊ���������ƾ����У����������� ���� �� Ҫ�� ��
        �������� �� ���ӡ�
        �������κ� ��ռ�� �ĸ��ӡ�
        ���ǿ��Է���������Ŀ����Ʊ��
        ��Ʊ�����໥�� �ص� ���֡�
        ��Ʊ������ ��ת ��
        ��Ʊ������ȫ�ھ��� �� ��
        �������������Ҫ���ǰ���£����Է�����Ʊ���뷵�� true ��
        ���򷵻� false ��*/
        bool LC2132_possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth);
        //����ǰ׺��
        void LC2132_Build(vector<vector<int>>&sum);
        //ǰ׺�Ͳ�ѯ
        int LC2132_sumRegion(vector<vector<int>>sum,int a,int b,int c,int d);
        //��(a,b)��(c,d)��Χ�ڽ��в�ֲ���
        void LC2132_Add(vector<vector<int>>&diff,int a,int b,int c,int d);
    public:
        /*LeetCode 2132 ����Ʊ*/
        void Test_LC2132_possibleToStamp();
    private:
        /*С����̽�����ֵĹ����У�����䷢���˴�˵�С���į�Ļƽ�֮������
        ������Ƭ��������ĵش��У�С��ʹ��̽���Ǽ�⵽�˴���ĳ�ִ���
        ��ף����Ч���������� �������ϵĿ����¼��
        С�۽����������ķֲ�����¼��������
        forceField[i] = [x,y,side]��ʾ�� i Ƭ���������������� (x,y) Ϊ���ģ�
        �߳�Ϊ side ������������
        ������һ�������ǿ�ȵ��ڸ��Ǹõ������������
        ���������Ƭ�ش��� ����ǿ�� ��ǿ���� ����ǿ�ȡ�*/
        int LCP74_fieldOfGreatestBlessing(vector<vector<int>>& forceField);
        //���
        void LCP74_Add(vector<vector<int>>&diff,int a,int b,int c,int d);
        //���ֲ�ѯһ����������
        int LCP74_Rank(vector<long>&nums,long v,int size);
        //�������鲢����ȥ�غ�ĳ���
        int LCP74_Sort(vector<long>&nums);
    public:
        /*LeetCode LCP 74 ��ǿף������*/
        void Test_LCP74_fieldOfGreatestBlessing();
    };
    class NumMatrix{
        //��άǰ׺��
        /*����һ����ά���� matrix���������͵Ķ������
        �������Ӿ��η�Χ��Ԫ�ص��ܺͣ����Ӿ���� ���Ͻ� Ϊ (row1, col1) ��
        ���½� Ϊ (row2, col2) ��
        ʵ�� NumMatrix �ࣺ
        NumMatrix(int[][] matrix) ������������ matrix ���г�ʼ��
        int sumRegion(int row1, int col1, int row2, int col2) 
        �������Ͻ�(row1, col1)�����½� (row2, col2)���������Ӿ����Ԫ���ܺ�*/
        private:
            vector<vector<int>>sum;
            int n,m;
        public:
            NumMatrix(){;}
            NumMatrix(vector<vector<int>>&martix);
            int sumRegion(int row1,int col1,int row2,int col2);
        public:
            /*LeetCode 304 ��ά����ͼ���*/
            void Test_LC304_NumMatrix();
        private:
            /*����һ�������� 0 �� 1 ��ɵĶ�ά���� grid��
            �����ҳ��߽�ȫ���� 1 ��ɵ���� ������ ������
            �����ظ��������е�Ԫ����������������ڣ��򷵻� 0��*/
            int LC1139_largest1BorderedSquare(vector<vector<int>>& grid);
            /*�ع��������*/
            void LC1139_Build(vector<vector<int>>&martix,int n,int m);
            /*�߽��ж�*/
            int LC1139_Get(vector<vector<int>>&martix,int i,int j);
            /*��Χ�ڵĺ�*/
            int LC1139_Sum(vector<vector<int>>&martix,int a,int b,int c,int d);
        public:
            /*LeetCode 1139 ������1Ϊ�߽��������*/
            void Test_LC1139_largest1BorderedSquare();
    };
}
namespace LGP3397{
    using std::vector;
    using std::cout;
    using std::cin;
    using std::endl;
    int n,m;
    void LG_Set(vector<vector<int>>&grid,int a,int b,int c,int d){
        grid[a][b]+=1;
        grid[a][d+1]-=1;
        grid[c+1][b]-=1;
        grid[c+1][d+1]+=1;
    }
    void LG_Add(vector<vector<int>>&grid,int n,int m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
            }
        }
    }
    /*��� 3397 ��̺*/
    void LGP3397(){
        cin>>n;cin>>m;
        vector<vector<int>>grid(n+2,vector<int>(n+2,0));
        while(m--){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            LG_Set(grid,a,b,c,d);
        }
        LG_Add(grid,n,n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}