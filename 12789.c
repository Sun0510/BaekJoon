#include <stdio.h>

int line[1001];
int temp[1001];

int main() {
	int N, seq, index, waiting;
	seq = 1;
	index = 1;
	waiting = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &line[i]);
	}

	while (seq <= N) {
		if (index > N && temp[waiting] != seq) {
			break;
		}
		if (waiting > 0 && temp[waiting] == seq) {
			temp[waiting] = 0;
			waiting--;
			seq++;
			continue;
		}
		if (line[index] == seq) {
			index++;
			seq++;
			continue;
		}
		else {
			temp[++waiting] = line[index++];
			continue;
		}
	}
	if (waiting == 0) {
		printf("Nice\n");
	}
	else {
		printf("Sad\n");
	}

	return 0;
}
