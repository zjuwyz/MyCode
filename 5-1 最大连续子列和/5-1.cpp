//5 - 1 最大子列和问题(20分)

//给定KK个整数组成的序列 {N_1,N_2,...,N_k}，“连续子列”被定义为{N_i, N_(i+1),...,N_j),其中 1<=i<=j<=k。
//“最大子列和”则被定义为所有连续子列元素的和中最大者。
//例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。
//现要求你编写程序，计算给定整数序列的最大子列和。

//本题旨在测试各种不同的算法在各种数据情况下的表现。各组测试数据特点如下：
//数据1：与样例等价，测试基本正确性；
//数据2：10^2个随机整数；
//数据3：10^3个随机整数；
//数据4：10^4个随机整数；
//数据5：10^5个随机整数；

//输入格式 :
//输入第1行给出正整数K(k≤100000)；第2行给出KK个整数，其间以空格分隔。

//输出格式 :
//在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

//输入样例 :
//6
//- 2 11 - 4 13 - 5 - 2

//输出样例 :
//20

//时间限制 : 5000ms
//空间限制 : 64MB

/*-----------------------------------------------------------------------------------------------------------------*/

//方法一：二分查找。将原序列一分为二，则最大连续子列要么全部在左侧，要么全部在右侧，要么会跨过中点。
//处理跨过中点的情况时可以直接计算。
//时间复杂度O（nlogn)
//已AC， 耗时24ms

//#define MAX 131072
//#include <stdio.h>
//int a[MAX + 1] = { 0 };
//int find(int s, int t);
//int main() {
//	int k, i;
//	scanf("%d", &k);
//	for (i = 1; i <= k; i++) {
//		scanf("%d", &a[i]);
//	}
//	printf("%d", find(1, MAX));
//	return 0;
//}
//int find(int s, int t) {
//	int left = 0, right = 0, cross = 0, cross_l = -2147483647, cross_r = -2147483647;
//	int m = 0, i = 0, sum = 0;
//	m = (s + t - 1) / 2;
//
//	if (s == t) {
//		if (a[s] > 0) return a[s];
//		else return 0;
//	}
//
//	left = find(s, m);
//	right = find(m + 1, t);
//
//	for (i = m; i >= s; i--) {
//		sum += a[i];
//		if (cross_l < sum) cross_l = sum;
//	}
//	sum = 0;
//	for (i = m + 1; i <= t; i++) {
//		sum += a[i];
//		if (cross_r < sum) cross_r = sum;
//	}
//
//	cross = cross_l + cross_r;
//
//	int best = 0;
//	if (left > best) best = left;
//	if (right > best) best = right;
//	if (cross > best) best = cross;
//
//	return best;
//}

/*-----------------------------------------------------------------------------------------------------------------*/

//方法二：DP
//设submax[i]为序列N_1...N_i中包含N_i的最大子序列和
//状态转移方程为 submax[i] = max(submax[i-1] + now, now)
//时间复杂度O(n)
//已AC， 用时18ms
#include <stdio.h>

int main()
{
	int k;
	int max_all = 0;
	int max_now = 0;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		int now;
		scanf("%d", &now);

		max_now = (max_now + now > now) ? max_now + now : now;
		max_all = (max_now > max_all) ? max_now : max_all;
	}

	printf("%d", max_all);
	return 0;
}
