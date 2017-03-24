#include <iostream>
using namespace std;

int main() {
	int n, c;
	int a[1000] = { 0 };
	cin >> n >> c;
	for (int i = 0; i < n - c; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < c; i++) {
		int temp;
		cin >> temp;
		cout << temp << " ";
	}
	for (int i = 0; i < n - c; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}