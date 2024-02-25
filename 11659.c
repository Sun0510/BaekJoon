#include <stdio.h>

int arr[100001];

int main() {
	int N, M, i, j, num;
	
	scanf("%d %d", &N, &M);
	for (int k = 1; k <= N; k++) {
		scanf("%d", &num);
		arr[k] = arr[k - 1] + num;
	}

	for (int k = 1; k <= M; k++) {
		scanf("%d %d", &i, &j);
		printf("%d\n", arr[j] - arr[i - 1]);
	}

	return 0;
}
