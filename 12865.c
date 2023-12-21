#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, k, w_i, v_i;
	scanf("%d %d", &n, &k);

	int** knapsack = (int**)malloc(sizeof(int*) * (n + 1));
	int* thing_w = (int*)malloc(sizeof(int) * (n + 1));
	int* thing_v = (int*)malloc(sizeof(int) * (n + 1));

	for (int i = 0; i <= n; i++) {
		knapsack[i] = (int*)malloc(sizeof(int) * (k + 1));
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &w_i, &v_i);
		thing_w[i] = w_i;
		thing_v[i] = v_i;
	}

	for (int i = 0; i <= n; i++) {
		knapsack[i][0] = 0;
	}

	for (int j = 0; j <= k; j++) {
		knapsack[0][j] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - thing_w[i] >= 0) {
				if (knapsack[i - 1][j] < knapsack[i - 1][j - thing_w[i]] + thing_v[i]) {
					knapsack[i][j] = knapsack[i - 1][j - thing_w[i]] + thing_v[i];
				}
				else {
					knapsack[i][j] = knapsack[i - 1][j];
				}
			}
			else {
				knapsack[i][j] = knapsack[i - 1][j];
			}
		}
	}
	printf("%d\n", knapsack[n][k]);

	for (int i = 0; i < n; i++) {
		free(knapsack[i]);
	}
	free(knapsack);
	free(thing_w);
	free(thing_v);

	return 0;
}
