//5 - 5 堆中的路径(25分)
//
//将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。
//
//输入格式 :
//每组测试第1行包含2个正整数 N 和 M (≤1000)，分别是插入元素的个数、以及需要打印的路径条数。
//下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。
//最后一行给出M个下标。
//
//输出格式 :
//对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。
//
//输入样例 :
//5 3
//46 23 26 24 10
//5 4 3

//输出样例 :
//24 23 10
//46 23 10
//26 10

/*-----------------------------------------------------------------------------------------------------------------*/

//思路：插入堆操作，将带插入元素放到最后，然后向上调整。
//本题用链式存储较繁，使用普通的顺序存储。

//已AC 用时4ms

#include <stdio.h>
#define SIZE 1001
void build(int i, int* heap);
void output(int i, int *heap);

int main() {
	int heap[SIZE]; 

	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &heap[i]);
		build(i, heap);
	}

	for (int i = 1; i <= m; i++) {
		int temp;
		scanf("%d", &temp);
		output(temp, heap);
		if (i != m) printf("\n");
	}

	return 0;
	
}

void swap(int* i, int* j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}
int parent(int i) {
	return i / 2;
}

void build(int i, int* heap) {
	while (i != 1 && heap[parent(i)] > heap[i]) {
		swap(&heap[parent(i)], &heap[i]);
		i = parent(i);
	}
}
void output(int i, int *heap) {
	while (i) {
		printf("%d%s", heap[i], i != 1 ? " " : "");
		i = parent(i);
	}
}

//由于这道题实在没必要用C++的特性，这次换回了C-Style
//没什么说的，就是新配色方案挺好看的XD