#include <stdio.h>

int main() {
	int X, N, a, b, result = 0;
	scanf("%d", &X);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		result += (a * b);
	}
	if (X == result) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}
