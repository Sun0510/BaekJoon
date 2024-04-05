#include <stdio.h>
#include <string.h>

char S[100];
int alphabets[26];

int main() {
	int len;
	int ch;
	scanf("%s", S);
	len = strlen(S);

	for (int i = 0; i < 26; i++) 
		alphabets[i] = -1;
	
	for (int i = 0; i < len; i++) {
		ch = S[i] - 97;
		if (alphabets[ch] == -1)
			alphabets[ch] = i;
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", alphabets[i]);
	printf("\n");
	return 0;
}
