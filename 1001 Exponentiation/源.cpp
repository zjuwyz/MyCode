#include <stdio.h>
#define MAX_LEN 200
int main(){
	int result[MAX_LEN] = { 0 };
	int len = 0;
	char s[10];
	int n;
	while (scanf("%s%d", s, &n) == 2) {
		int pointPos;
		int input = 0;
		int j = 0;
		for (int i = 0; i < 6; i++) {
			if (s[i] == '.') {
				pointPos = 5 - i;
				pointPos *= n;
				continue;
			}
			input = input * 10 + s[i] - '0';
			j++;
		}

		//bool isInteger = true;
		//for (int i = pointPos; i <= 6; i++)
		//	if (input[i] != 0) isInteger = false;
		result[0] = 1;
		for (int i = 1; i < MAX_LEN; i++) {
			result[i] = 0;
		}
		len = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < len; j++) {
				result[j] *= input;
			}
			int j = 0;
			while (j < len || result[j] != 0) {
				if (result[j] > 9) {
					result[j + 1] += result[j] / 10;
					result[j] %= 10;
				}
				j++;
			}
			len = j;
		}

		int tail_zero = 0;
		while (result[tail_zero] == 0) {
			tail_zero++;
		}

		if (pointPos >= len) {
			printf(".");
			for (int i = pointPos - 1; i >= tail_zero; i--) {
				printf("%d", result[i]);
			}
		}
		else if (pointPos <= tail_zero) {
			for (int i = len - 1; i >= pointPos; i--) {
				printf("%d", result[i]);
			}
		}
		else for (int i = len - 1; i >= tail_zero; i--) {
			printf("%d", result[i]);
			if (i == pointPos) printf(".");
		}
		printf("\n");
	}

	return 0;

}

//00001234500000
//    *  ^ *

