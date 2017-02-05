#include <stdio.h>
#define MAXNUM 9999999+1
int used[MAXNUM] = { 0 };
int main() {
	int map[] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		int number = 0;
		int digit;
		char c = '\0';
		while (c != '\n') {
			c = getchar();
			if (c >= 'A' && c <= 'Z') {
				digit = map[c - 'A'];
				number = number * 10 + digit;
			}
			if (c >= '0' && c <= '9') {
				digit = c - '0';
				number = number * 10 + digit;
			}
		}
 		used[number]++;
	}

	int repeated = 0;
	for (int i = 0; i < MAXNUM; i++) {
		if (used[i] > 1) {
			printf("%03d-%04d %d\n", i / 10000, i % 10000, used[i]);
			repeated = 1;
		}
	}

	if (!repeated) printf("No duplicates.\n");

	return 0;

}