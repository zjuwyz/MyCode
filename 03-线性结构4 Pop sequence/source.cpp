#include <iostream>

#include <stack>
using namespace std;

int main()
{

	int k, n, m;
	cin >> m >> n >> k;
	stack<int> s;
	for (int i = 0; i < k; i++)
	{
		int flag = 1;
		while (!s.empty())
		{
			s.pop();
		}
		int now = 1;
		for (int j = 0; j < n; j++)
		{
			int t;
			cin >> t;

			if (s.empty() || t > s.top())
			{
				for (; now <= t; now++)
				{
					s.push(now);
				}
				if (s.size() > m)
				{
					flag = 0;
					break;
				}
				s.pop();
			}
			else if (t == s.top())
			{
				s.pop();
			}
			else
			{
				flag = 0;
				break;
			}
			if (!flag)
			{
				break;
			}
		}
		cout << (flag ? "YES" : "NO") << endl;
		cin.ignore(2147483647, '\n');
	}
	return 0;
}