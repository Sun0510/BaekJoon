#include <stdio.h>
#include <stdlib.h>

int arr[1000000];

int compare(const void* a, const void* b) {
	int A = *(int*)a;
	int B = *(int*)b;
	if (A < B) return -1;
	if (A > B) return 1;
	return 0;
}

int main() {
	int t, n, K, currentDiff;
	int left, right, m, num;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &K);
		left = 0;
		right = n - 1;
		m = 200000002;
		num = 1;
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[j]);
		}
		qsort(arr, n, sizeof(int), compare);

		while (left != right) {
			currentDiff = K - (arr[left] + arr[right]);

			if (abs(currentDiff) < m) {
				m = abs(currentDiff);
				num = 1;
			}
			else if (abs(currentDiff) == m) {
				num++;
			}

			if (0 >= currentDiff)
				right--;
			else
				left++;
		}
		printf("%d\n", num);
	}

	return 0;
}
