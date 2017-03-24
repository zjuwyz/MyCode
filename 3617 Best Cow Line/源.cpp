#include <stdio.h>
#pragma warning (disable:4996)
int main() {
	int n;
	scanf("%d", &n);
	char s[10000] = { 0 };
	for (int i = 0; i < n; i++) {
		char c = '\n'; 
		while (c == '\n') scanf("%c", &c);
		s[i] = c;
	}

	int tail = n - 1; int head = 0; int count = 0;
	while (head <= tail) {
		int i = head, j = tail;
		while (s[i] == s[j] && i <= j) {
			i++; j--;
		}

		if (s[i] > s[j]) {
			printf("%c", s[tail--]);
		}
		else printf("%c", s[head++]);
		count++;
		if (count == 80) {
			count = 0;
			printf("\n");
		}
	}

	return 0;
}