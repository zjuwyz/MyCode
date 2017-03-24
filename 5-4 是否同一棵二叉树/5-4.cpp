//5 - 4 �Ƿ�ͬһ�ö���������(25��)
//
//����һ���������оͿ���Ψһȷ��һ�ö�����������Ȼ����һ�ø����Ķ���������ȴ�����ɶ��ֲ�ͬ�Ĳ������еõ���
//����ֱ������� {2, 1, 3} �� {2, 3, 1} �����ʼΪ�յĶ��������������õ�һ���Ľ����
//���Ƕ�������ĸ��ֲ������У�����Ҫ�ж������Ƿ�������һ���Ķ�����������
//
//�����ʽ :
//�������������������ݡ�ÿ�����ݵĵ�1�и�������������N(<=10)��L���ֱ���ÿ�����в���Ԫ�صĸ�������Ҫ�������и�������2�и���NN���Կո�ָ�������������Ϊ��ʼ�������С����LL�У�ÿ�и���NN�������Ԫ�أ�����LL����Ҫ�������С�
//����������Ǳ�֤ÿ���������ж���1��N��һ�����С�������NNΪ0ʱ����־����������������ݲ�Ҫ����
//
//�����ʽ :
//��ÿһ����Ҫ�������У���������ɵĶ�������������Ӧ�ĳ�ʼ�������ɵ�һ���������Yes�������������No����
//
//�������� :
//4 2
//3 1 4 2
//3 4 1 2
//3 2 4 1
//2 1
//2 1
//1 2
//0
//
//�������:
//Yes
//No
//No
//
//ʱ�����ƣ�400ms 64MB

/*-----------------------------------------------------------------------------------------------------------------*/

//˼·������Ҫ��һ��һ�����£�ûʲô�㷨��
//ʱ�临�Ӷȣ�O(nlogn)
//��AC�� ��ʱ13ms
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

//��ǣ���һ�γ���ʹ��C++��������д�������кܶ಻��Ӧ�ĵط���Ū���崫ָ��û��Ǵ�ֵ�ã��ṹҲ�ܻ��ҡ�
//������ȥ���ڸĳ���������������������������
