#include <stdio.h>
#include <string.h>

char str[50];
char stack[50];

int isCheck() {
	int top, len = strlen(str);
	char ch;
	top = -1;
	for (int i = 0; i < len; i++) {
		ch = str[i];
		if (ch == '(') {
			stack[++top] = ch;
		}
		else {
			if (stack[top] == '(')
				stack[top--] = 0;
			else
				return 0;
		}
	}
	if (top == -1)
		return 1;
	else
		return 0;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		if (isCheck() == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
