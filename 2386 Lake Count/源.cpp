#include <stdio.h>
#define MAX_SIZE 200
int isNewLake(int[MAX_SIZE][MAX_SIZE], int[MAX_SIZE][MAX_SIZE] , int i, int j, int m, int n);
int main() {
	int m, n;
	int area[MAX_SIZE][MAX_SIZE] = { 0 };
	int visited[MAX_SIZE][MAX_SIZE] = { 0 };
	scanf("%d%d\n", &m, &n);
	char c;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%c", &c);
			if (c == 'W') {
				area[i][j] = 1;
				}
		}
		scanf("%c", &c);
	}
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (isNewLake(area, visited, i, j, m, n)) {
				count++;
			}
		}
	}
	printf("%d", count);
}

int isNewLake(int area[][MAX_SIZE], int visited[][MAX_SIZE], int i, int j, int m, int n) {
	int ans = 0;

	if (i < 0 || i >= m) return 0;
	if (j < 0 || j >= n) return 0;
	if (!area[i][j]) return 0;
	if (visited[i][j]) return 0;

	visited[i][j] = 1;
	ans = 1;

	for (int ii = i - 1; ii <= i + 1; ii++) {
		for (int jj = j - 1; jj <= j + 1; jj++) {
			if (ii != i || jj != j) {
				isNewLake(area, visited, ii, jj, m, n);
			}
		}
	}
	
	return ans;
}