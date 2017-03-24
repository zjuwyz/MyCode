﻿//5 - 7 六度空间(30分)
//
//“六度空间”理论又称作“六度分隔（Six Degrees of Separation）”理论。
//这个理论可以通俗地阐述为：“你和任何一个陌生人之间所间隔的人不会超过六个，也就是说，最多通过五个人你就能够认识任何一个陌生人。”
//“六度空间”理论虽然得到广泛的认同，并且正在得到越来越多的应用。但是数十年来，试图验证这个理论始终是许多社会学家努力追求的目标。
//然而由于历史的原因，这样的研究具有太大的局限性和困难。
//随着当代人的联络主要依赖于电话、短信、微信以及因特网上即时通信等工具，能够体现社交网络关系的一手数据已经逐渐使得“六度空间”理论
//的验证成为可能。
//
//假如给你一个社交网络图，请你对每个节点计算符合“六度空间”理论的结点占结点总数的百分比。
//
//输入格式 :
//输入第1行给出两个正整数，分别表示社交网络图的结点数N（1 < N <= 10^​4)，表示人数、边数 M(<= 33 × N)，表示社交关系数。
//随后的MM行对应MM条边，每行给出一对正整数，分别是该条边直接连通的两个结点的编号（节点从1到NN编号）。
//
//输出格式 :
//对每个结点输出与该结点距离不超过6的结点数占结点总数的百分比，精确到小数点后2位。
//每个结节点输出一行，格式为“结点编号:（空格）百分比%”。
//	
//输入样例 :
//10 9
//1 2
//2 3
//3 4
//4 5
//5 6
//6 7
//7 8
//8 9
//9 10

//输出样例:
//1 : 70.00 %
//2 : 80.00 %
//3 : 90.00 %
//4 : 100.00 %
//5 : 100.00 %
//6 : 100.00 %
//7 : 100.00 %
//8 : 90.00 %
//9 : 80.00 %
//10 : 70.00%
//
//时空限制: 2500ms 64MB
//
/*-----------------------------------------------------------------------------------------------------------------*/
//
//思路：这道题上打的Tag是广搜，但是朴素的广搜有效率上的疑问。
//然而是我想多了。。。

//已AC 用时278ms，内存6MB
#include <stdio.h>
#define MAXN 10010
#define MAXE 33*MAXN
#define MAX_DIST 6

int main()
{
	int start[MAXN] = {0};
	int t[2 * MAXE] = {0};
	int next[2 * MAXE] = {0};
	int link = 0;
	int N;
	int E;

	scanf("%d%d", &N, &E);
	for (int i = 1; i <= E; i++)
	{
		int n1, n2;
		scanf("%d%d", &n1, &n2);
		link++;
		t[link] = n2;
		next[link] = start[n1];
		start[n1] = link;

		link++;
		t[link] = n1;
		next[link] = start[n2];
		start[n2] = link;
	}

	for (int s = 1; s <= N; s++)
	{
		int queue[MAXN] = {0};
		bool visited[MAXN] = {false};
		int head = 0, tail = 0;
		int count = 0;
		queue[0] = s;
		head = 1;
		visited[s] = true;
		count++;

		for (int dist = 1; dist <= MAX_DIST; dist++)
		{
			int headPos = head;
			for (; tail < headPos; tail++)
			{
				int nowNode = queue[tail];
				int nowLinkNum = start[nowNode];
				int nextNode = t[nowLinkNum];
				while (nextNode)
				{
					if (!visited[nextNode])
					{
						queue[head++] = nextNode;
						visited[nextNode] = true;
						count++;
					}
					nowLinkNum = next[nowLinkNum];
					nextNode = t[nowLinkNum];
				}
			}
		}

		printf("%d: %.2lf%%\n", s, (100.0 * count) / N);
	}

	return 0;
}
