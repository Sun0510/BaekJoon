#include <stdio.h>

int arr[9];

int main() {
	int max, index;
	max = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}
	}
	printf("%d\n%d\n", max, index + 1);
	return 0;
}
