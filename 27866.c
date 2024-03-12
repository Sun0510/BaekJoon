#include <stdio.h>

char S[1001];

int main() {
	int i;
	scanf("%s %d", S, &i);
	printf("%c", S[i - 1]);

	return 0;
}
