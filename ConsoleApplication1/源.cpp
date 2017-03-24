#include <iostream>
#include <string.h>

using namespace std;

int main() {
	char s[30];
	int num[30] = { 0 };
	int  count[10] = { 0 };
	fgets(s, 30, stdin);
	s[strlen(s) - 1] = '\0';
	for (int i = 0; i < strlen(s); i++) {
		num[i] = s[strlen(s) - i - 1] - '0';
		count[num[i]]++;
	}
	for (int i = 0; i < strlen(s); i++) {
		num[i] *= 2;
	}
	for (int i = 0; i < strlen(s); i++) {
		num[i + 1] += num[i] / 10;
		num[i] %= 10;
	}
	int retlen = strlen(s);
	if (num[retlen] != 0) {
		retlen++;
	}
	for (int i = 0; i < retlen; i++) {
		count[num[i]]--;
	}
	bool ret = true;
	for (int i = 0; i < 10; i++) {
		if (count[i] != 0) {
			ret = false;
			break;
		}
	}
	cout << (ret ? "Yes" : "No") << endl;
	for (int i = retlen - 1; i >= 0; i--) {
		cout << num[i];
	}

	return 0;
}