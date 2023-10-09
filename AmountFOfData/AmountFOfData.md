AmountFOfData.h头文件中介绍且声明了题目与函数
int KillMonsterEverySkillUseOnce_(int n,int m,std::vector<int>kill,std::vector<int>blood);是用来计算杀死怪的最少攻击次数的，这个函数只用来测试并暴力递归数据，从而获得数据量猜测解法
这是LeetCode 906 的题目
LC906_superpalindromesInRange_(string left,string right)；
当一个数是回文数，且这个数是平方数，那么这个数就是超级回文数
要寻找区间[left,right]内所有的超级回文数
在l与r的根号下寻找，如果一个数是回文数，且他的平方也是回文数，超级回文数也就是它的平方了
分别生成奇偶数长度的回文数，并判断其平方是否为回文，如果同一个种子下它的奇数长度的回文数已经超过了根号下r，那么下一个的奇数长度的回文数就不用判断了，因为它的平方一定大于r了
接下来只需要判断生成的奇偶数长度的回文的平方是否为回文即可
每生成一个超级回文数，就将其添加到ans中
int AmountFOfData::LC906_superpalindromesInRange2_(string left,string right);
这个函数是基于上一个方法得出的计算超级回文数的算术方法，其时间复杂度为O(1);
