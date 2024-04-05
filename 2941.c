#include <stdio.h>
#include <string.h>

char str[102];

int main() {
	char ch;
	int len, croatia = 0;
	scanf("%s", str);
	len = strlen(str);

	for (int i = 0; i < len; i++) {
		ch = str[i];
		switch (ch) {
		case 'c':
			if (str[i + 1] == '=' || str[i + 1] == '-') i++;
			break;
		case 'd':
			if (str[i + 1] == 'z' && str[i + 2] == '=') i += 2;
			else if (str[i + 1] == '-') i++;
			break;
		case 'l':
			if (str[i + 1] == 'j') i++;
			break;
		case 'n':
			if (str[i + 1] == 'j') i++;
			break;
		case 's':
			if (str[i + 1] == '=') i++;
			break;
		case 'z':
			if (str[i + 1] == '=') i++;
			break;
		default:
			break;
		}
		croatia++;
	}
	printf("%d\n", croatia);
	return 0;
}
