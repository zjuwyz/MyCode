//5 - 6 �г���ͨ��(25��)
//
//����һ���� N ������� E ���ߵ�����ͼ������DFS��BFS�ֱ��г������е���ͨ����
//���趥��� 0 �� N - 1 ��š���������ʱ�������������Ǵӱ����С�Ķ������������ŵ�����˳������ڽӵ㡣
//
//�����ʽ :
//�����1�и���2������ N (0 < N <= 10) �� E���ֱ���ͼ�Ķ������ͱ�����
//���E�У�ÿ�и���һ���ߵ������˵㡣ÿ���е�����֮����һ�ո�ָ���
//
//�����ʽ :
//����"{v1 v2 ... vk}"�ĸ�ʽ��ÿ�����һ����ͨ���������DFS�Ľ���������BFS�Ľ����

//��������:
//8 6
//0 7
//0 1
//2 0
//4 1
//2 4
//3 5
//
//�������:
//{ 0 1 4 2 7 }
//{ 3 5 }
//{ 6 }
//{ 0 1 2 7 4 }
//{ 3 5 }
//{ 6 }

//ʱ������: 400ms 64MB
/*-----------------------------------------------------------------------------------------------------------------*/

//˼·����ȻҪ���ӱ����С�ĵ����������ŵ�����˳����ʡ����������ݹ�ģ��С�����ڽӱ��Ǻܺõ�ѡ��
//ͼ�Ͷ�������д��class

//��AC ��ʱ��2ms

#include <iostream>
#define SIZE 10

using namespace std;

struct arr
{
	int size = 0;
	int data[SIZE] = {0};

	void output()
	{
		cout << '{';
		for (int i = 0; i < size; i++)
		{
			cout << ' ' << data[i];
		}
		cout << " }" << endl;
	}

	void clear()
	{
		size = 0;
		for (int i = 0; i < SIZE; i++)
		{
			data[i] = 0;
		}
	}
};

class node
{
private:
	arr link;
public:
	void addLink(int num)
	{
		int i = link.size - 1;
		while (link.data[i] > num && i >= 0)
		{
			link.data[i + 1] = link.data[i];
			i--;
		}
		link.data[i + 1] = num;
		link.size++;
	};

	int getNthLink(int n)
	{
		return link.data[n];
	}

	int getLinksNum()
	{
		return link.size;
	}
};

class queue
{
private:
	int &head = que.size;
	int tail = 0;
	arr que;
public:
	int pop()
	{
		int ret = que.data[tail];
		tail++;
		return ret;
	}

	void append(int num)
	{
		que.data[head] = num;
		head++;
	}

	bool isEmpty()
	{
		return head == tail;
	}
};

class graph
{
private:
	bool visited[SIZE] = {false};
	node nodeList[SIZE];
	int N, E;
public:
	void link(int n1, int n2)
	{
		nodeList[n1].addLink(n2);
		nodeList[n2].addLink(n1);
	}

	void build()
	{
		cin >> N >> E;
		for (int i = 0; i < E; i++)
		{
			int n1, n2;
			cin >> n1 >> n2;
			link(n1, n2);
		}
	};

	arr* DFSconnect(int start)
	{
		arr *visitList = new arr;
		visitList->size = 1;
		visitList->data[0] = start;
		visited[start] = true;
		for (int i = 0; i < nodeList[start].getLinksNum(); i++)
		{
			if (!visited[nodeList[start].getNthLink(i)])
			{
				arr *newVisit = DFSconnect(nodeList[start].getNthLink(i));
				for (int j = 0; j < newVisit->size; j++)
				{
					int &tail = visitList->size;
					visitList->data[tail++] = newVisit->data[j];
				}
			}
		}
		return visitList;
	};

	arr* BFSconnect(int start)
	{
		arr *visitList = new arr;
		queue que;
		que.append(start);
		visited[start] = true;
		while (!que.isEmpty())
		{
			int now = que.pop();
			for (int i = 0; i < nodeList[now].getLinksNum(); i++)
			{
				int nextNode = nodeList[now].getNthLink(i);
				if (!visited[nextNode])
				{
					que.append(nextNode);
					visited[nextNode] = true;
				}
			}
			visitList->data[visitList->size++] = now;
		}
		return visitList;
	};

	void solve(int times)
	{
		for (int i = 0; i < N; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < N; i++)
		{
			if (!visited[i])
			{
				if (times == 1)
				{
					DFSconnect(i)->output();
				}
				else if (times == 2)
				{
					BFSconnect(i)->output();
				}
			}
		}
		if (times == 1) solve(2);
	};
};

int main()
{
	graph G;
	G.build();
	G.solve(1);
	return 0;
}

/*-----------------------------------------------------------------------------------------------------------------*/
//��ǣ�д��������C++д��ô��������ɱ����ţ���ĸо�
//���ο��һ�������ţ��
//
//ȷʵ�����ִ����ά���ԺͿɸ����Ժܸߣ���д����ʵ���Ǻܺľ�������Ҫ���ϵز²��Ұ��Сʱ֮������Ҫ��ʲô��ڡ�����
//ȫ������ϰC++��
//
