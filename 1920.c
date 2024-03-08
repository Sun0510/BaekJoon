#include <stdio.h>
#include <stdlib.h>

long long int arr[100000];
long long int numbers[100000];

void search(int start, int end, long long x) {
	if (start >= end && x != arr[start]) {
		printf("0\n"); return;
	}
	int mid = (start + end) / 2;
	
	if (x < arr[mid]) {
		search(start, mid - 1, x);
	}
	else if (x == arr[mid]) {
		printf("1\n");
	}
	else if (x > arr[mid]) {
		search(mid + 1, end, x);
	}
}

int compare(const void* a, const void* b) {
	long long int A = *(long long int*)a;
	long long int B = *(long long int*)b;
	if (A < B) return -1;
	if (A > B) return 1;
	return 0;
}

int main() {
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	qsort(arr, N, sizeof(long long int), compare);
	
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%lld", &numbers[i]);
	}

	for (int i = 0; i < M; i++) {
		search(0, N - 1, numbers[i]);
	}

	return 0;
}
