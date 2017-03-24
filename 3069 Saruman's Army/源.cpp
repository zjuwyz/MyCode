#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[1024] = { 0 };
	int n = 0;
	int r = 0;
	cin >> r >> n;
	while (n >= 0 && r >= 0) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << " " << a[0] << "b" << endl;
		sort(a, a + n);

		int left = 0;
		int mid = 0;
		int right = -1;
		int count = 0;

		while (right < n - 1){
			count++;
			while (a[mid] <= a[left] + r && mid < n) {
				mid++;
			}
			mid--;

			right = mid;
			while (a[right] <= a[mid] + r && right < n) {
				right++;
			}
			right--;

			left = right + 1;
			mid = left;
		}

		cout << count << endl;
		cin >> r >> n;
	}
	return 0;
}