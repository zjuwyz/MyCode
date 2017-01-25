//5 - 3 树的同构(25分)
//给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。
//现给定两棵树，请你判断它们是否是同构的。
//
//输入格式 :
//输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (N <= 10)，即该树的结点数（此时假设结点从0到N-1编号）；
//随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。
//如果孩子结点为空，则在相应位置上给出“ - ”。
//给出的数据间用一个空格分隔。
//注意：题目保证每个结点中存a储的字母是不同的。
//
//输出格式 :
//如果两棵树是同构的，输出“Yes”，否则输出“No”。
//
//输入样例1：
//8
//A 1 2
//B 3 4
//C 5 -
//D - -
//E 6 -
//G 7 -
//F - -
//H - -
//8
//G - 4
//B 7 6
//F - -
//A 5 1
//H - -
//C 0 -
//D - -
//E 2 -

//输出样例1:
//Yes
//
//输入样例2（对应图2）：
//8
//B 5 7
//F - -
//A 0 3
//C 6 -
//H - -
//D - -
//G 4 -
//E 1 -
//8
//D 6 -
//B 5 -
//E - -
//H - -
//C 0 2
//G - 3
//F - -
//A 1 4
//
//输出样例2:
//No

//时空限制：400ms 64MB
/*-----------------------------------------------------------------------------------------------------------------*/

//思路: 
//要判断两棵树 A 和 B 是否同构，首先看它们的孩子数是否相同。若不同直接返回FALSE。
//若相同的话，如果只有一个孩子，那么就是两棵子树同构，若都有两个孩子，则四棵子树两辆同构。
//递归下去即可。
//由于在最坏情况下（即同构的情况下）每个节点都处理且仅处理一遍，算法的时间复杂度为O(n)
//不过由于本题 n = 10， 时间并不是什么大问题。

//已AC， 耗时3ms
#include <stdio.h>
#include <stdlib.h>
struct tree {
	char data;
	struct tree *lson;
	struct tree *rson;
};

int judge(struct tree *t1, struct tree *t2);
struct tree* inputTree();

int main() {
	struct tree *t1, *t2;
	t1 = inputTree();
	t2 = inputTree();

	if (judge(t1, t2)) {
		printf("Yes");
	}
	else {
		printf("No");
	}

	return 0;
}

struct tree* inputTree() {
	int n;
	struct tree *node[10];
	int isRoot[10];
	scanf("%d\n", &n);
	if (n == 0) {
		return NULL;
	}
	for (int i = 0; i < n; i++) {
		node[i] = (struct tree*)malloc(sizeof(struct tree));
		node[i]->lson = node[i]->rson = NULL;
		isRoot[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		char letter, lsnum, rsnum;
		scanf("%c %c %c\n", &letter, &lsnum, &rsnum);

		if (lsnum != '-') {
			lsnum -= '0';
			node[i]->lson = node[lsnum];
			isRoot[lsnum] = 0;
		}
		if (rsnum != '-') {
			rsnum -= '0';
			node[i]->rson = node[rsnum];
			isRoot[rsnum] = 0;
		}

		node[i]->data = letter;
	}

	for (int i = 0; i < n; i++) {
		if (isRoot[i]) {
			return node[i];
		}
	}
}

int judge(struct tree *t1, struct tree *t2) {
	int ret;
	if (t1 == NULL) {
		if (t2 == NULL) {
			return 1;
		}
		else return 0;
	}

	if (t1->data != t2->data) {
		ret = 0;
	}
	else {
		if (t1->lson == NULL && t1->rson == NULL) {
			if (t2->lson == NULL && t2->rson == NULL) {
				ret = 1;
			}
			else {
				ret = 0;
			}
		}//no children nodes
		if (t1->lson != NULL && t1->rson == NULL) {
			if (t2->lson == NULL && t2->rson == NULL) {
				ret = 0;
			}
			else if (t2->lson != NULL && t2->rson != NULL) {
				ret = 0;
			}
			else {
				if (t2->lson != NULL) {
					ret = judge(t1->lson, t2->lson);
				}
				else {
					ret = judge(t1->lson, t2->rson);
				}
			}
		}//a leftson
		if (t1->lson == NULL && t1->rson != NULL) {
			if (t2->lson == NULL && t2->rson == NULL) {
				ret = 0;
			}
			else if (t2->lson != NULL && t2->rson != NULL) {
				ret = 0;
			}
			else {
				if (t2->lson != NULL) {
					ret = judge(t1->rson, t2->lson);
				}
				else {
					ret = judge(t1->rson, t2->rson);
				}
			}
		}// a rightson
		if (t1->lson != NULL && t1->rson != NULL) {
			if (t2->lson == NULL || t2->rson == NULL) {
				ret = 0;
			}
			else {
				if (judge(t1->lson, t2->rson) && judge(t1->rson, t2->lson)) {
					ret = 1;
				}
				else if (judge(t1->lson, t2->lson) && judge(t1->rson, t2->rson)) {
					ret = 1;
				}
				else ret = 0;
			}
		}//two children nodes
	}
	return ret;
}

/*-----------------------------------------------------------------------------------------------------------------*/

//后记：

//测试数据里居然有空树

//关于scanf("\n");的问题，在本地的时候由于shell在读到'\n'之后，只将'\n'之前的字符传给程序
//例如输入"A 1 2\nB 3 4\n"，在按下第二次回车之后，第一个回车才能传给程序。因此B 3 4目前程序是看不到的。

//在本地可以使用 scanf("%c"); 过一个空字符，但是在服务端这句话会导致段错误。