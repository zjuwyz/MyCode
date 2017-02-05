#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num, l;
		scanf("%d %d", &l, &num);
		int earliest = 0; int latest = 0;
		for (int j = 0; j < num; j++) {
			int now;
			scanf("%d", &now);
			if (now > l / 2) {
				now = l - now;
			}
			if (now > earliest) earliest = now;
			if (l - now > latest) latest = l - now;
		}
		printf("%d %d\n", earliest, latest);
	}
	return 0;
}

