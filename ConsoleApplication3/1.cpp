#include <iostream>

using namespace std;

int main()
{
	int count = 0;
	for (int i = 1; ; i++)
	{
		if ((i % 2 == 0) || (i % 3 == 0))
		{
			count++;
		}
		if (count == 2333)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}
