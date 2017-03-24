#include <iostream>
using namespace std;
int abs(int a) {
	if (a < 0)
	{
		return -a;
	}
	return a;
}
int main() {
	int n;
	char c;
	cin >> n >> c;
	n--;
	int size = 1;
	for (int i = 6; ; i += 4) {
		if (n - i > 0) {
			size++;
			n -= i;
		}
		else break;
	}
	for (int i = 1; i <= size * 2 - 1; i++) {
		for (int j = 0; j < size - abs(size - i) - 1; j++) {
			cout << " ";
		}
		for (int j = 0; j < abs(size - i) * 2 + 1; j++) {
			cout << c;
		}
		cout << endl;
	}

	cout << n << endl;
	return 0;
}