#include <stdio.h>

int arr[31];

int main() {
	int n;
	for (int i = 0; i < 28; i++) {
		scanf("%d", &n);
		arr[n] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (arr[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}
