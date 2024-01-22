#include <stdio.h>

int arr[1000];
int dp[1000];

int maxNum(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N, max = 1;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}

	for (int i = 1; i < N ; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = maxNum(dp[i], dp[j] + 1);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (max < dp[i]) {
			max = dp[i];
		}
	}
	printf("%d\n", max);
	return 0;
}
