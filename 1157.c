#include <stdio.h>
#include <string.h>

char str[1000001];
int alphabets[26];

int main() {
	char alphabet;
	int len, check, max;
	scanf("%s", str);

	check = max = 0;
	len = strlen(str);

	for (int i = 0; i < len; i++) {
		if (str[i] >= 97) {
			alphabets[str[i] - 97]++;
		}
		else {
			alphabets[str[i] - 65]++;
		}
			
	}

	for (int i = 0; i < 26; i++) {
		if (alphabets[i] > max) {
			check = 0;
			max = alphabets[i];
			alphabet = i + 65;
		}
		else if (alphabets[i] == max) {
			check = 1;
		}
	}

	if (check == 0) {
		printf("%c\n", alphabet);
	}
	else {
		printf("?\n");
	}
	return 0;
}
