#include <stdio.h>

struct sol
{
	int data;
	int s;
	int t;
};

int main()
{
	int a[10000] = {0};
	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		scanf("%d", &a[i]);
	}

	struct sol max, now;
	max = now = {-1, 0, k - 1};

	for (int i = 0; i < k; i++)
	{
		if (now.data + a[i] >= a[i])
		{
			now.data += a[i];
			now.t = i;
		}
		else
		{
			now.data = a[i];
			now.t = now.s = i;
		}
		if (now.data > max.data)
		{
			max = now;
		}
	}

	if (max.data < 0)
	{
		max.data = 0;
	}
	printf("%d %d %d", max.data, a[max.s], a[max.t]);

	return 0;
}
