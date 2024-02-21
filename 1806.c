#include <stdio.h>
#define MIN 9999999

int arr[100001];

int main() {
	int N, S, sum, min = MIN;
	int left, right;
	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sum = arr[0];
	left = 0;
	right = 0;

	while (left <= right && right < N) {
		if (sum < S) {
			right++;
			sum += arr[right];
		}
		else {
			min = (right - left + 1 < min ? right - left + 1 : min);
			sum -= arr[left++];
		}
	}

	if (min == MIN) {
		printf("0\n");
	}
	else {
		printf("%d\n", min);
	}
	return 0;
}
