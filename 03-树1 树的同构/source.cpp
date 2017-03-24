#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
	char data;
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
	void input()
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
			char c;
			string s1, s2;
			cin >> c >> s1 >> s2;
			tree[i].data = c;
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
	friend bool check(Tree &t1, Tree &t2, int h1, int h2);
};

bool check(Tree &t1, Tree &t2, int h1, int h2)
{
	if (h1 == -1 && h2 == -1)
	{
		return true;
	}
	if (h1 == -1 || h2 == -1)
	{
		return false;
	}
	if (t1.tree[h1].data != t2.tree[h2].data)
	{
		return false;
	}
	return check(t1, t2, t1.tree[h1].l, t2.tree[h2].l) && check(t1, t2, t1.tree[h1].r, t2.tree[h2].r) || check(t1, t2, t1.tree[h1].l, t2.tree[h2].r) && check(t1, t2, t1.tree[h1].r, t2.tree[h2].l);
}

int main()
{

	Tree t1, t2;
	t1.input();
	t2.input();
	cout << (check(t1, t2, t1.head, t2.head) ? "Yes" : "No");
	return 0;
}