#include <stdio.h>	
#define MAX 1000
int ans[800] = { 0 };
int main() {
	double sum = 0;
	int prev = 0;
	int now = 0;
	int c = 0;
	while (sum <= 6) {
		c++;
		sum += 1.0 / (c + 1);
		now = (int)(sum * 100);
		for (int i = prev + 1; i <= now; ans[i++] = c);
		prev = now;
	}
	double tmp; 
	scanf("%lf", &tmp);
	while (tmp > 0.001) {
		printf("%d card(s)\n", ans[(int)(tmp * 100)]);
		scanf("%lf", &tmp);
	}
	return 0;

}