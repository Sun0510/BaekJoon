#include <stdio.h>

int coins[11];

int main() {
	int N, K, num = 0;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &coins[i]);
	}

	for (int i = N; i > 0; i--) {
		while (K >= coins[i]) {
			K -= coins[i];
			num++;
		}
	}
	printf("%d\n", num);
	return 0;
}
