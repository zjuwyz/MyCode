//5 - 2 一元多项式的乘法与加法运算(20分)

//设计函数分别求两个一元多项式的乘积与和。

//输入格式 :
//输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（均为绝对值不超过1000的整数）。
//数字间以空格分隔。

//输出格式 :
//输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
//数字间以空格分隔，但结尾不能有多余空格。零多项式应输出 0 0。

//输入样例 :
//4 3 4 -5 2  6 1 -2 0
//3 5 20 -7 4  3 1

//输出样例 :
//5 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
//5 20 -4 4 -5 2 9 1 -2 0

//时空限制：200ms 64MB
/*-----------------------------------------------------------------------------------------------------------------*/

//题解：很简单的一道模拟题。只需将多项式加法和乘法写好即可。
//不过代码还有改进的空间，重复部分太多。
//时间复杂度：O(n^2)
//已AC， 用时17ms
#include <stdio.h>
#define MAX 2001
int main() {
	int c1[MAX] = { 0 }, c2[MAX] = { 0 };
	int cans1[MAX] = { 0 }, cans2[MAX] = { 0 };
	// cans1 for plus, c ans2 for product
	int n1, n2;

	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		int exp, cons;
		scanf("%d%d", &cons, &exp);
		c1[exp] = cons;
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		int exp, cons;
		scanf("%d%d", &cons, &exp);
		c2[exp] = cons;
	}

	for (int i = 0; i < MAX; i++) {
		cans1[i] = c1[i] + c2[i];
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; i + j <= MAX; j++) {
			cans2[i + j] += c1[i] * c2[j];
		}
	}
	int printed = 0;
	for (int i = MAX - 1; i >= 0; i--) {
		if (cans2[i] != 0) {
			printf("%s%d %d", printed ? " " : "", cans2[i], i);
			printed = 1;
		}
	}
	if (!printed) {
		printf("0 0");
	}

	printf("\n");

	printed = 0;
	for (int i = MAX - 1; i >= 0; i--) {
		if (cans1[i] != 0) {
			printf("%s%d %d", printed ? " " : "", cans1[i], i);
			printed = 1;
		}
	}
	if (!printed) {
		printf("0 0");
	}

	return 0;

}