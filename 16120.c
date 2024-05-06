#include <stdio.h>
#include <string.h>

char str[1000005];

int main() {
	char result[5];
	int numP, len;

	scanf("%s", str);

	numP = 0;
	len = strlen(str);
	
	for (int i = 0; i < len; i++) {
		if (str[i] == 'P') {
			numP++;
		}
		else {
			if (numP >= 2 && str[i + 1] == 'P') {
				numP--;
				i++;
			}
			else {
				numP = -1;
				break;
			}
		}
	}

	if (numP == 1) {
		strcpy(result, "PPAP");
	}
	else {
		strcpy(result, "NP");
	}

	printf("%s\n", result);

	return 0;
}
