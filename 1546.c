#include <stdio.h>

double arr[1000];

int main() {
	double N, sum, max;
	sum = max = 0;
	scanf("%lf", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lf", &arr[i]);
		if (max < arr[i])
			max = arr[i];
	}
	for (int i = 0; i < N; i++) {
		arr[i] = (arr[i] / max) * 100;
		sum += arr[i];
	}
	printf("%lf\n", sum / N);
	return 0;
}
