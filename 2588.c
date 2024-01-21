#include <stdio.h>

int main() {
	int A, B;
	int B100, B10, B1;
	int result = 0;

	scanf("%d", &A);
	scanf("%d", &B);

	B100 = B / 100;
	B10 = B % 100 / 10;
	B1 = B % 100 % 10;

	printf("%d\n", A * B1);
	printf("%d\n", A * B10);
	printf("%d\n", A * B100);

	result = (A * B1) + (A * B10) * 10 + (A * B100) * 100;
	printf("%d\n", result);

	return 0;
}
