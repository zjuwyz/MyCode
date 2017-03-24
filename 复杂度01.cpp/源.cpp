#include <stdio.h>

int main()
{
	int k;
	int max_all = 0;
	int max_now = 0;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		int now;
		scanf("%d", &now);

		max_now = (max_now + now > now) ? max_now + now : now;
		max_all = (max_now > max_all) ? max_now : max_all;
	}

	printf("%d", max_all);
	return 0;
}
