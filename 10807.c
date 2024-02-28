#include <stdio.h>

int arr[201];

int main() {
	int N, num, v;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		arr[num + 100]++;
	}
	scanf("%d", &v);
	printf("%d\n", arr[v + 100]);

	return 0;
}
