#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, k;
	int temp;
	scanf("%d %d", &n, &k);

	int *arr = (int*)malloc(sizeof(int) * (k + 1));
	for (int i = 0; i < k + 1; i++) {
		arr[i] = 0;
	}
	
	int* c = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		c[i] = temp;
	}

	arr[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = c[i]; j < k + 1; j++) {
			arr[j] += arr[j - c[i]];
		}
	}

	printf("%d\n", arr[k]);
	free(arr);
	free(c);

	return 0;
}
