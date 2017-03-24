#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
bool space = false;
void solve(vector<int>& in, vector<int>& mid, int sin, int tin, int smid, int tmid);

int main()
{
	ifstream fin("data.txt");
	cin.rdbuf(fin.rdbuf());

	vector<int> s;
	vector<int> inOrder, midOrder;
	int n;
	cin >> n;
	s.reserve(n);
	inOrder.reserve(n);
	midOrder.reserve(n);
	for (int i = 0; i < n * 2; i++)
	{
		string str;
		cin >> str;

		if (str == "Push")
		{
			int d;
			cin >> d;
			s.push_back(d);
			inOrder.push_back(d);
		}
		if (str == "Pop")
		{
			midOrder.push_back(s[s.size() - 1]);
			s.pop_back();
		}
	}

	solve(inOrder,midOrder,0,n - 1,0,n - 1);
}

void solve(vector<int>& in, vector<int>& mid, int sin, int tin, int smid, int tmid)
{
	
	int root = in[sin];
	int i;
	for (i = smid; mid[i] != root; i++) {}
	int lsize = (i - smid);
	int rsize = (tmid - i);

	if (lsize > 0)
	{
		solve(in,mid,sin + 1,sin + lsize,smid,smid + lsize - 1);
	}
	if (rsize > 0)
	{
		solve(in,mid,tin - rsize + 1,tin,tmid - rsize + 1,tmid);
	}

	if (space)
	{
		cout << " ";
	}
	else
	{
		space = true;
	}
	cout << root;
}

