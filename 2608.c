#include <stdio.h>
#include <string.h>

char rome1[100000];
char rome2[100000];
char rome[100000];

int getValue(char ch) {
	int val;
	switch(ch) {
	case 'M':
		val = 1000; break;
	case 'D':
		val = 500; break;
	case 'C':
		val = 100; break;
	case 'L':
		val = 50; break;
	case 'X':
		val = 10; break;
	case 'V':
		val = 5; break;
	case 'I':
		val = 1; break;
	default:
		val = -1; break;
	}
	return val;
}

char getSign(int digits, int num) {
	char ch;
	switch (digits) {
	case 1000: 
		ch = 'M';
		break;
	case 100:
		if (num == 5)
			ch = 'D';
		else
			ch = 'C';
		break;
	case 10: 
		if (num == 5)
			ch = 'L';
		else
			ch = 'X';
		break;
	case 1:
		if (num == 5)
			ch = 'V';
		else
			ch = 'I';
		break;
	default: break;
	}
	return ch;
}

int romeToArab(char* rome, int len) {
	int val1, val2, arab = 0;

	for (int i = 0; i < len; i++) {
		val1 = getValue(rome[i]);
		val2 = getValue(rome[i + 1]);

		if (val1 < val2) {
			arab += (val2 - val1);
			i++;
		}
		else {
			arab += val1;
		}
	}

	return arab;
}

void arabToRome(int arab) {
	int num, index = 0;
	for (int digits = 1000; digits > 0; digits /= 10) {
		num = arab / digits;
		arab -= ((arab / digits) * digits);

		for (int i = 0; i < num; i++) {
			if (num == 4) {
				rome[index++] = getSign(digits, 1);
				rome[index++] = getSign(digits, 5);
				break;
			}
			else if (num >= 5) {
				if (num == 9) {
					rome[index++] = getSign(digits, 1);
					rome[index++] = getSign(digits * 10, 1);
					break;
				}
				else {
					rome[index++] = getSign(digits, 5);
					num -= 5;
					i--;
				}
			}
			else {
				rome[index++] = getSign(digits, num);
			}
		}
	}
}

int main() {
	int len1, len2, arab1, arab2, sum;

	scanf("%s", rome1);
	scanf("%s", rome2);

	len1 = strlen(rome1);
	len2 = strlen(rome2);

	arab1 = romeToArab(rome1, len1);
	arab2 = romeToArab(rome2, len2);

	sum = arab1 + arab2;

	arabToRome(sum);

	printf("%d\n", sum);
	printf("%s\n", rome);

	return 0;
}
