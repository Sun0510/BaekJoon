#include <stdio.h>

int arr[1025][1025];

int main() {
	int N, M, num, x1, y1, x2, y2, sum;

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &num);
			arr[i][j] = arr[i][j - 1] + num;
		}
	}

	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		sum = 0;
		for (int j = x1; j <= x2; j++) {
			sum += (arr[j][y2] - arr[j][y1 - 1]);
		}
		printf("%d\n", sum);
	}

	return 0;
}
