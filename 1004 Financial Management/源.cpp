#include <stdio.h>
int main() {
	double sum = 0;
	for (int i = 0; i < 12; i++) {
		double now;
		scanf("%lf", &now);
		sum += now;
	}
	sum /= 12;
	printf("$%.2lf\n", sum);
}
