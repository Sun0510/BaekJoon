#include <stdio.h>
#include <stdlib.h>

int minNumber(int a, int b) {
	return a > b ? b : a;
}

int main() {
	int n, result;
	int a, b, c;
	scanf("%d", &n);

	int** house = (int**)malloc(sizeof(int*) * n);
	int** sum = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++) {
		house[i] = (int*)malloc(sizeof(int) * 3);
		sum[i] = (int*)malloc(sizeof(int) * 3);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		
		house[i][0] = a;
		house[i][1] = b;
		house[i][2] = c;
	}

	for (int j = 0; j < 3; j++)
		sum[0][j] = house[0][j];

	for (int i = 1; i < n; i++) {
		sum[i][0] = minNumber(sum[i - 1][1], sum[i - 1][2]) + house[i][0];
		sum[i][1] = minNumber(sum[i - 1][0], sum[i - 1][2]) + house[i][1];
		sum[i][2] = minNumber(sum[i - 1][0], sum[i - 1][1]) + house[i][2];
	}

	result = (sum[n - 1][0] < sum[n - 1][1] && sum[n - 1][0] < sum[n - 1][2]) ? sum[n - 1][0] :
		(sum[n - 1][1] < sum[n - 1][2]) ? sum[n - 1][1] :
		sum[n - 1][2];
	
	printf("%d\n", result);

	for (int i = 0; i < n; i++) {
		free(house[i]);
		free(sum[i]);
	}
	free(house);
	free(sum);
	return 0;
}
