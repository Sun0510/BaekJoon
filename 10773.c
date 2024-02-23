#include <stdio.h>

int stack[100000];

int main() {
	int K, num, sum, index;
	sum = index = 0;
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d", &num);
		if (num == 0) {
			stack[index--] = 0;
		}
		else {
			stack[++index] = num;
		}
	}

	for (int i = 0; i <= index; i++) {
		sum += stack[i];
	}
	printf("%d\n", sum);
	return 0;
}
