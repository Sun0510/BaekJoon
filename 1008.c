#include <stdio.h>
int main() {
	double a, b, result;
	scanf("%lf %lf", &a, &b);
	result = a / b;
	printf("%.9f\n", result);
	return 0;
}
