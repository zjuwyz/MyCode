#include <iostream>
using namespace std;
#define pi 3.1415926535897932384626
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		double x, y;
		cin >> x >> y;
		double area = (x * x + y * y) * pi * 0.5;
		int ans = (int)(area / 50) + 1;
		cout << "Property " << i << ": This property will begin eroding in year " << ans << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}
