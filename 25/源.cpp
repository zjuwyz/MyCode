#include <iostream>

using namespace std;

int main()
{
	int max[20][5010] = { 0 };
	int use[20][5010] = { 0 };
	int w[20] = { 0 };

	for (int i = 0; i < 15; i++)
	{
		int idx;
		cin >> idx;
		cin >> w[idx];
	}

	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 5000; j++)
		{
			max[i][j] = max[i - 1][j];
			use[i][j] = 0;
			if (j - w[i] > 0 && max[i - 1][j - w[i]] + w[i] > max[i][j])
			{
				max[i][j] = max[i - 1][j - w[i]] + w[i];
				use[i][j] = 1;
			}
		}
	}	

	int idx = 15;
	int c = 5000;
	while (idx >= 1)
	{
		if (use[idx][c])
		{
			cout << idx << endl;
			c -= w[idx];
		};
		idx--;
	}
	cout << max[15][5000];
	return 0;
}