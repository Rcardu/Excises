���ļ���ͼ�����ִ�����ʽ
Graph����
1���ڽӾ���
2���ڽӱ�
3����ʽǰ����

Topological ����
����LeetCode 210 �γ̱�II

LG_Topological����
��ȵ���������ģ��

alienOrder����
�Լ�LCR 114 ���Ǵʵ����������
����LeetCode 936 ��ӡ����

namespace FoodLine��
ʹ���������򴫵���Ϣ��ʳ����

loudAndRich����
����LeetCode 851 ���ֺ͸���

mumTime����
����LeetCode 2050 ���пγ�

Invitations����
����LeetCode 2127 �μӻ�������Ա��

Kruskal���е���С�������㷨ʹ�ò��鼯�����л��ļ�⣬������������ɸѡѡ��
a[2]>b[2]��ʾ��ֵС�����ȼ���,������
auto cmp=[](vector<int>a,vector<int>b)->bool{return a[2]>b[2];};
cmp��һ��lamba���ʽ������һ��boolֵ����ʾ��ֵ������ȼ������ڶ�β
priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);

decltype()����Ϊpriority_queue�ĵ����������Ǻ���ָ�루��Ҫ��������������cmp��һ�����󣩣�������Ҫʹ��decltype()����ȡ����ָ������ͣ���ת��Ϊ���ͣ�

��Ϊlambda���������classû��Ĭ�Ϲ��캯����pq�ڲ�����Ƚϵ�ʱ��Ҫʹ�õ���һ��ʵ������lambda����ֻ��ͨ��lambda�� copy�������ʵ������������copy�أ�����Ҫpq���캯����ʱ�������lambda����pq���Զ���Ƚ�Ҳ����ʹ��struct����class����Ϊstruct��class����Ĭ�Ϲ��캯������ʱ�Ͳ���Ҫpq(Type)����ֱ��pq���ɡ�ͬ���Զ���Ƚ�Ҳ����ʹ�ú�����ͬ����ʱҲ��Ҫ�ṩ�����������ʵ����pq(CmpFunc)������ȽϺ���Ϊbool CmpFunc(int x, int y) {return x < y;}

Prim���б�ʾ�˶���ͼ����С�������㷨��ʹ��С������������С�������Ĺ���
PrimPlus����Prim�㷨�Ľ�һ���Ż�ʹ�÷�������������¼��ǰ����ڶ��е������������޸Ķ��еĽ���Ȩֵ����֤���еĴ�С���������й�

OptimizationOfWaterAllocation����LeetCode 1168 ˮ��Դ�Ż�������̣�ʹ��ͼ�벢�鼯

distanceLimitedPathsExist��LeetCode 1697 ��鳤�����Ƶ�·���Ƿ����

������ȱ�������
MaxDistance LeetCode 1162 ��ͼ����

MinStickers��LeetCode 691 ��ֽƴ��

MinCost��LeetCode 1368 ʹ����������һ����Ч·��

trapRainWater��LeetCode 407 ����ˮII

FindLadders��LeetCode 126 ���ʽ���

SnacksWayBuyTickets��LG P4799 ��������������˫����ѣ�ͨ������������չ��

MinAbsDifference��LeetCode 1755 ��ӽ�Ŀ��ֵ�������к�