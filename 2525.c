#include <stdio.h>

int main() {
	int A, B, C, hours, minutes;
	scanf("%d %d", &A, &B);
	scanf("%d", &C);

	hours = C / 60;
	minutes = C % 60;

	A += hours;
	B += minutes;

	if (B >= 60) {
		A += 1;
		B -= 60;
	}

	if (A >= 24) {
		A -= 24;
	}

	printf("%d %d", A, B);

	return 0;
}
