#include <stdio.h>
#include <string.h>

int arr[101];
int temp[101];

void reverse(int i, int j) {
	int y = j;
	memcpy(temp, arr, sizeof(int) * 101);
	for (int x = i; x <= j; x++) {
		arr[x] = temp[y--];
	}
}

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);

	for (int x = 1; x < 101; x++) {
		arr[x] = x;
	}

	for (int x = 0; x < M; x++) {
		scanf("%d %d", &i, &j);
		reverse(i, j);
	}

	for (int x = 1; x <= N; x++) {
		printf("%d ", arr[x]);
	}
	printf("\n");
	return 0;
}
