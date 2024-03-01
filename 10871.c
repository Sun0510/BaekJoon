#include <stdio.h>

int arr[10000];

int main() {
	int N, X;
	scanf("%d %d", &N, &X);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] < X)
			printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
