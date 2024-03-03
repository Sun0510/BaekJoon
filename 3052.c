#include <stdio.h>

int arr[42];

int main() {
	int n, result = 0;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &n);
		arr[n % 42]++;
	}
	for (int i = 0; i < 42; i++) {
		if (arr[i] >= 1)
			result++;
	}
	printf("%d\n", result);
	return 0;
}
