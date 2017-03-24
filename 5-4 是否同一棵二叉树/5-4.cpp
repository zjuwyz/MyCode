//5 - 4 是否同一棵二叉搜索树(25分)
//
//给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。
//例如分别按照序列 {2, 1, 3} 和 {2, 3, 1} 插入初始为空的二叉搜索树，都得到一样的结果。
//于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。
//
//输入格式 :
//输入包含若干组测试数据。每组数据的第1行给出两个正整数N(<=10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出NN个以空格分隔的正整数，作为初始插入序列。最后LL行，每行给出NN个插入的元素，属于LL个需要检查的序列。
//简单起见，我们保证每个插入序列都是1到N的一个排列。当读到NN为0时，标志输入结束，这组数据不要处理。
//
//输出格式 :
//对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。
//
//输入样例 :
//4 2
//3 1 4 2
//3 4 1 2
//3 2 4 1
//2 1
//2 1
//1 2
//0
//
//输出样例:
//Yes
//No
//No
//
//时空限制：400ms 64MB

/*-----------------------------------------------------------------------------------------------------------------*/

//思路：按照要求一步一步做呗，没什么算法。
//时间复杂度：O(nlogn)
//已AC， 用时13ms
#include <stdio.h>
#include <stdlib.h>

class tree
{
private:
	int data;
	tree *lson;
	tree *rson;
public:
	void insert(int x);
	void buildTree(int num);
	tree(int x) : data(x), lson(NULL), rson(NULL) {};

	~tree()
	{
		if (lson) free(lson);
		if (rson) free(rson);
		free(this);
	}

	friend bool isEqualTree(tree *t1, tree *t2);
};

bool isEqualTree(tree *t1, tree *t2);

int main()
{
	int n, l;
	tree *stdTree;
	tree *chkTree;
	//stdTr for the standard tree, chktr for the tree to be checked.
	while (true)
	{
		scanf("%d", &n);
		if (n == 0) return 0;
		scanf("%d", &l);

		stdTree = new tree(0);
		stdTree->buildTree(n);
		bool isEqual = true;
		for (int i = 0; i < l; i++)
		{
			chkTree = new tree(0);
			chkTree->buildTree(n);
			printf("%s", isEqualTree(stdTree, chkTree) ? "Yes\n" : "No\n");
		}
	}
	return 0;
}

void tree::buildTree(int num)
{
	for (int i = 0; i < num; i++)
	{
		int temp;
		scanf("%d", &temp);
		insert(temp);;
	}
}

void tree::insert(int x)
{
	if (data == 0)
	{
		data = x;
		lson = new tree(0);
		rson = new tree(0);
	}
	else
	{
		if (x < data)
		{
			lson->insert(x);
		}
		else rson->insert(x);
	}
}

bool isEqualTree(tree *t1, tree *t2)
{
	if (t1->data != t2->data)
		return false;
	else
	{
		if (t1->data == 0)
			return true;
		else
			return isEqualTree(t1->lson, t2->lson) && isEqualTree(t1->rson, t2->rson);
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/

//后记：第一次尝试使用C++的特性来写东西，有很多不适应的地方，弄不清传指针好还是传值好，结构也很混乱。
//改来改去终于改成了现在这样，至少能跑起来。
