//5 - 3 ����ͬ��(25��)
//����������T1��T2�����T1����ͨ�����ɴ����Һ��ӻ����ͱ��T2�������ǳ��������ǡ�ͬ�����ġ�
//�ָ����������������ж������Ƿ���ͬ���ġ�
//
//�����ʽ :
//�������2�ö�����������Ϣ������ÿ������������һ���и���һ���Ǹ�����N (N <= 10)���������Ľ��������ʱ�������0��N-1��ţ���
//���N�У���i�ж�Ӧ��ŵ�i����㣬�����ý���д洢��1��Ӣ�Ĵ�д��ĸ�������ӽ��ı�š��Һ��ӽ��ı�š�
//������ӽ��Ϊ�գ�������Ӧλ���ϸ����� - ����
//���������ݼ���һ���ո�ָ���
//ע�⣺��Ŀ��֤ÿ������д�a������ĸ�ǲ�ͬ�ġ�
//
//�����ʽ :
//�����������ͬ���ģ������Yes�������������No����
//
//��������1��
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

//�������1:
//Yes
//
//��������2����Ӧͼ2����
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
//�������2:
//No

//ʱ�����ƣ�400ms 64MB
/*-----------------------------------------------------------------------------------------------------------------*/

//˼·: 
//Ҫ�ж������� A �� B �Ƿ�ͬ�������ȿ����ǵĺ������Ƿ���ͬ������ֱͬ�ӷ���FALSE��
//����ͬ�Ļ������ֻ��һ�����ӣ���ô������������ͬ�����������������ӣ����Ŀ���������ͬ����
//�ݹ���ȥ���ɡ�
//�����������£���ͬ��������£�ÿ���ڵ㶼�����ҽ�����һ�飬�㷨��ʱ�临�Ӷ�ΪO(n)
//�������ڱ��� n = 10�� ʱ�䲢����ʲô�����⡣

//��AC�� ��ʱ3ms
#include <stdio.h>
#include <stdlib.h>

struct tree
{
	char data;
	struct tree *lson;
	struct tree *rson;
};

int judge(struct tree *t1, struct tree *t2);
struct tree* inputTree();

int main()
{
	struct tree *t1, *t2;
	t1 = inputTree();
	t2 = inputTree();

	if (judge(t1, t2))
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}

	return 0;
}

struct tree* inputTree()
{
	int n;
	struct tree *nodeList[10];
	int isRoot[10];
	scanf("%d\n", &n);
	if (n == 0)
	{
		return NULL;
	}
	for (int i = 0; i < n; i++)
	{
		nodeList[i] = (struct tree*)malloc(sizeof(struct tree));
		nodeList[i]->lson = nodeList[i]->rson = NULL;
		isRoot[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		char letter, lsnum, rsnum;
		scanf("%c %c %c\n", &letter, &lsnum, &rsnum);

		if (lsnum != '-')
		{
			lsnum -= '0';
			nodeList[i]->lson = nodeList[lsnum];
			isRoot[lsnum] = 0;
		}
		if (rsnum != '-')
		{
			rsnum -= '0';
			nodeList[i]->rson = nodeList[rsnum];
			isRoot[rsnum] = 0;
		}

		nodeList[i]->data = letter;
	}

	for (int i = 0; i < n; i++)
	{
		if (isRoot[i])
		{
			return nodeList[i];
		}
	}
}

int judge(struct tree *t1, struct tree *t2)
{
	int ret;
	if (t1 == NULL)
	{
		if (t2 == NULL)
		{
			return 1;
		}
		else return 0;
	}

	if (t1->data != t2->data)
	{
		ret = 0;
	}
	else
	{
		if (t1->lson == NULL && t1->rson == NULL)
		{
			if (t2->lson == NULL && t2->rson == NULL)
			{
				ret = 1;
			}
			else
			{
				ret = 0;
			}
		}//no children nodes
		if (t1->lson != NULL && t1->rson == NULL)
		{
			if (t2->lson == NULL && t2->rson == NULL)
			{
				ret = 0;
			}
			else if (t2->lson != NULL && t2->rson != NULL)
			{
				ret = 0;
			}
			else
			{
				if (t2->lson != NULL)
				{
					ret = judge(t1->lson, t2->lson);
				}
				else
				{
					ret = judge(t1->lson, t2->rson);
				}
			}
		}//a leftson
		if (t1->lson == NULL && t1->rson != NULL)
		{
			if (t2->lson == NULL && t2->rson == NULL)
			{
				ret = 0;
			}
			else if (t2->lson != NULL && t2->rson != NULL)
			{
				ret = 0;
			}
			else
			{
				if (t2->lson != NULL)
				{
					ret = judge(t1->rson, t2->lson);
				}
				else
				{
					ret = judge(t1->rson, t2->rson);
				}
			}
		}// a rightson
		if (t1->lson != NULL && t1->rson != NULL)
		{
			if (t2->lson == NULL || t2->rson == NULL)
			{
				ret = 0;
			}
			else
			{
				if (judge(t1->lson, t2->rson) && judge(t1->rson, t2->lson))
				{
					ret = 1;
				}
				else if (judge(t1->lson, t2->lson) && judge(t1->rson, t2->rson))
				{
					ret = 1;
				}
				else ret = 0;
			}
		}//two children nodes
	}
	return ret;
}

/*-----------------------------------------------------------------------------------------------------------------*/

//��ǣ�

//�����������Ȼ�п���

//����scanf("\n");�����⣬�ڱ��ص�ʱ������shell�ڶ���'\n'֮��ֻ��'\n'֮ǰ���ַ���������
//��������"A 1 2\nB 3 4\n"���ڰ��µڶ��λس�֮�󣬵�һ���س����ܴ����������B 3 4Ŀǰ�����ǿ������ġ�

//�ڱ��ؿ���ʹ�� scanf("%c"); ��һ�����ַ��������ڷ������仰�ᵼ�¶δ���
