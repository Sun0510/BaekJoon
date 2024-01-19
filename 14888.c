#include <stdio.h>

int expr[30]; // operator : '+' -> 0, '-' -> 1, '*' -> 2, '/' -> 3
int operator[4];
int N;
int max, min;

int calc() {
	int result;
	int operand1, operand2, op;

	result = expr[0];

	for (int i = 1; i < N; i++) {
		op = expr[i * 2 - 1];
		operand1 = result;
		operand2 = expr[i * 2];
		switch (op) {
		case 0: 
			result = operand1 + operand2;
			break;
		case 1:
			result = operand1 - operand2;
			break;
		case 2:
			result = operand1 * operand2;
			break;
		case 3:
			result = operand1 / operand2;
			break;
		}
	}

	return result;
}

void fun(int depth) {
	if (depth == N) {
		int result = calc();
		if (max < result)
			max = result;
		if (min > result)
			min = result;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int op = operator[i];
		if (op > 0) {
			switch (i) {
			case 0: expr[depth * 2 - 1] = 0; break;
			case 1: expr[depth * 2 - 1] = 1; break;
			case 2: expr[depth * 2 - 1] = 2; break;
			default: expr[depth * 2 - 1] = 3; break;
			}
			operator[i]--;
			fun(depth + 1);
			expr[depth * 2 - 1] = 0;
			operator[i]++;
		}
	}
}

int main() {
	max = -1e9 - 1;
	min = 1e9 + 1;

	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N * 2; i += 2) {
		scanf("%d", &expr[i]);
		getchar();
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &operator[i]);
		getchar();
	}
	fun(1);
	printf("%d\n", max);
	printf("%d\n", min);
}
