#include <stdio.h>
#include <string.h>

int main() {
	int len_s, len_t, result = 1;
	char s[1000] = "";
	char t[1000] = "";
	char temp;

	scanf("%s", s);
	scanf("%s", t);

	len_s = strlen(s);
	len_t = strlen(t);

	for (int i = len_t - 1; i > len_s - 1; i--) {
		if (t[i] == 'B') { // 뒤집고 B 추가
			t[i] = 0;
			for (int j = 0; j < i / 2; j++) {
				temp = t[j];
				t[j] = t[i - j - 1];
				t[i - j - 1] = temp;
			}
		}
		else {
			t[i] = 0;
		}
	}
	if (strcmp(s, t) != 0)
		result = 0;
	printf("%d\n", result);
	return 0;
}
