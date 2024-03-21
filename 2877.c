#include <stdio.h>

int arr[1000000];

int main() {
	int K, remainder, num = 0;
	scanf("%d", &K);

	K++;

	while (K >= 1) {
		remainder = K % 2;
		K /= 2;
		if (remainder == 0) 
			arr[num++] = 4;
		else
			arr[num++] = 7;
	}

	for (int i = num - 2; i >= 0; i--) {
		printf("%d", arr[i]);
	}
	printf("\n");

	return 0;
}
