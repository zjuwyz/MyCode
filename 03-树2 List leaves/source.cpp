#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Node
{
	int l;
	int r;
	int fa;
};

class Tree
{
	vector<Node> tree;
public:
	int head;
	Tree()
	{
		tree.clear();
		head = -1;
	}
	void input();
	void solve();
};

void Tree::input()
{
	int n;
	cin >> n;
	tree.resize(n);
	for (int i = 0; i < n; i++)
	{
		tree[i].fa = -1;
	}
	for (int i = 0; i < n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (s1[0] == '-')
		{
			tree[i].l = -1;
		}
		else
		{
			tree[i].l = atoi(s1.c_str());
			tree[tree[i].l].fa = i;
		}
		if (s2[0] == '-')
		{
			tree[i].r = -1;
		}
		else
		{
			tree[i].r = atoi(s2.c_str());
			tree[tree[i].r].fa = i;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (tree[i].fa == -1)
		{
			head = i;
			break;
		}
	}
}

void Tree::solve()
{
	queue<int> q;
	q.push(head);
	int flag = 1;
	while (!q.empty())
	{
		int current = q.front();
		int l = tree[current].l;
		int r = tree[current].r;
		if (l == -1 && r == -1)
		{
			if (flag)
			{
				cout << current;
				flag = 0;
			}
			else
			{
				cout << " " << current;
			}
		}
		if (l != -1)
		{
			q.push(l);
		}
		if (r != -1)
		{
			q.push(r);
		}
		q.pop();
	}
}

int main()
{
	Tree t;
	t.input();
	t.solve();
	return 0;
}
