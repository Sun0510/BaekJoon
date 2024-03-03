#include <stdio.h>

int arr[101];

int main() {
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);

	for (int x = 0; x < M; x++) {
		scanf("%d %d %d", &i, &j, &k);
		for (int y = i; y <= j; y++) {
			arr[y] = k;
		}
	}

	for (int x = 1; x <= N; x++) {
		printf("%d ", arr[x]);
	}
	printf("\n");
	return 0;
}
