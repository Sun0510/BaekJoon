#include <stdio.h>

char arr[100];

int main() {
	long long int N, sum = 0;
	scanf("%d", &N);
	scanf("%s", arr);
	
	for (int i = 0; i < N; i++) {
		sum += (arr[i] - '0');
	}
	printf("%lld\n", sum);
	return 0;
}
