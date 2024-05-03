#include <stdio.h>

char infix[100];
char postfix[100];
char temp_op[100];

int get_value_op(char ch) {
	int val;
	switch (ch) {
	case '+': case'-':
		val = 0; break;
	case '*': case '/':
		val = 1; break;
	default:
		val = -1; break;
	}
	return val;
}

int compare_op(char ch, int top) {
	int val = 0;
	if (get_value_op(ch) > get_value_op(temp_op[top]))
		val = 1;
	return val;
}

void in_to_post() {
	char ch;
	int i, post_top, op_top;
	i = 0;
	post_top = op_top = -1;

	while (infix[i] != 0) {
		ch = infix[i];
		switch (ch) {
		case '+': case '-': case '*': case '/':
			while (op_top > -1 && compare_op(ch, op_top) == 0) {
				postfix[++post_top] = temp_op[op_top--];
			}
			temp_op[++op_top] = ch;
			break;
		case '(':
			temp_op[++op_top] = ch;
			break;
		case ')':
			while (temp_op[op_top] != '(') {
				postfix[++post_top] = temp_op[op_top--];
			}
			op_top--;
			break;
		default:
			postfix[++post_top] = ch;
		}
		i++;
	}
	
	while (op_top > -1) {
		postfix[++post_top] = temp_op[op_top--];
	}

	printf("%s\n", postfix);
}

int main() {
	scanf("%s", infix);
	in_to_post();

	return 0;
}
