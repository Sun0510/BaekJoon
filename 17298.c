#include <stdio.h>

int arr[1000001];
int answer[1000001];// 정답 들어갈 배열
int temp[1000001];	// 인덱스 들어갈 스택

int main() {
	int N, j, temp_index, index = -1;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		temp[++index] = i;
		j = i + 1;
		while (j < N && index >= 0) {
			if (arr[temp[index]] < arr[j]) {
				temp_index = temp[index];
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
