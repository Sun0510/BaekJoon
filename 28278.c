#include <stdio.h>

int stack[1000001];
int top;

void push(int x) {
	top++;
	stack[top] = x;
}

void pop() {
	if (top == -1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", stack[top]);
		top--;
	}
}

void printNum() {
	printf("%d\n", top + 1);
}

void isEmpty() {
	if (top == -1)
		printf("1\n");
	else
		printf("0\n");
}

void printTop() {
	if (top == -1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", stack[top]);
	}
}

int main() {
	int N, op, x;
	top = -1;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			scanf("%d", &x);
			push(x);
			break;
		case 2:
			pop();
			break;
		case 3:
			printNum();
			break;
		case 4:
			isEmpty();
			break;
		case 5:
			printTop();
			break;
		default:
			break;
		}
	}

	return 0;
}
