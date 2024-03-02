#include <stdio.h>
#include <string.h>

int stack[100000];
char cmd[101];

int top = -1;

void push(int x) {
	stack[++top] = x;
}

void pop() {
	if (top == -1)
		printf("-1\n");
	else
		printf("%d\n", stack[top--]);
}

void printSize() {
	printf("%d\n", top + 1);
}

void isEmpty() {
	if (top == -1)
		printf("1\n");
	else
		printf("0\n");
}

void printTop() {
	if (top == -1)
		printf("-1\n");
	else
		printf("%d\n", stack[top]);
}

int main() {
	int N, x;
	top = -1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%s", cmd);

		if (strcmp(cmd, "push") == 0) {
			scanf("%d", &x);
			push(x);
		}
		else if (strcmp(cmd, "pop") == 0) {
			pop();
		}
		else if (strcmp(cmd, "size") == 0) {
			printSize();
		}
		else if (strcmp(cmd, "empty") == 0) {
			isEmpty();
		}
		else if (strcmp(cmd, "top") == 0) {
			printTop();
		}	
	}

	return 0;
}
