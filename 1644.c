#include <stdio.h>

int prime_check_numbers[4000001];
int prime_numbers[4000002];

int main() {
	int N, front, rear, sum, cnt = 0;
	int i, j, k = 0;

	scanf("%d", &N);

	prime_check_numbers[1] = 1;

	for (i = 2; i <= N; i++) {		
		for (j = 2; i * j <= N; j++) {
			prime_check_numbers[i * j] = 1;
		}
		if (prime_check_numbers[i] == 0) {
			prime_numbers[k++] = i;
		}
			
	}

	front = rear = sum = 0;
	while (front <= rear && rear <= k) {
		if (sum < N) {
			sum += prime_numbers[rear++];
		}
		else if (sum > N) {
			sum -= prime_numbers[front++];
		}
		else {
			sum += prime_numbers[rear++];
			cnt++;
		}
			
	}

	printf("%d\n", cnt);

	return 0;
}
