#include <stdio.h>
#include <math.h>

int isPrime(int n);
int main() {
	int n, i, count = 0;
	scanf("%d", &n);
	for (i = 5; i <= n; i += 2) {
		if (isPrime(i) && isPrime(i - 2)) count++;
	}

	printf("%d\n", count);
}

int isPrime(int n) {
	int max = (int)sqrt(n) + 1;
	int i;
	for (i = 2; i <= max; i++)
		if (n % i == 0) return 0;
	return 1;
}