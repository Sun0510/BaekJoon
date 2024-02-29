#include <stdio.h>

int arr[1000001];
int answer[1000001];
int temp[1000001];
int numbers[1000001];

int main() {
	int N, j, temp_index, index = -1;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		numbers[arr[i]]++;
	}

	for (int i = 0; i < N; i++) {
		temp[++index] = i;
		j = i + 1;
		while (j < N && index >= 0) {
			temp_index = temp[index];
			if (numbers[arr[temp_index]] < numbers[arr[j]]) {
				answer[temp_index] = arr[j];
				temp[index--] = 0;
			}
			else {
				i++;
				j++;
				temp[++index] = i;
			}
		}
	}

	while (index >= 0) {
		answer[temp[index--]] = -1;
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", answer[i]);
	}
	printf("\n");

	return 0;
}
