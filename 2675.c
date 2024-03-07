#include <stdio.h>
#include <string.h>

char S[20];

int main() {
	int T, R, len;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &R);
		getchar();
		scanf("%s", S);
		len = strlen(S);
		for (int s = 0; s < len; s++) {
			for (int r = 0; r < R; r++) {
				printf("%c", S[s]);
			}
		}
		printf("\n");
	}

	return 0;
}
