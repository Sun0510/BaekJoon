#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char p[100200];
char charArr[450000];
int arr[100001];

void changeArr(int end) {
	char temp[4] = "";
	int tempIndex = 0;
	int arrIndex = 0;
	int i = 1;
	
	while (i <= end) {
		if (charArr[i] == ',' || charArr[i] == ']') {
			arr[arrIndex++] = atoi(temp);
			tempIndex = 0;
			memset(temp, 0, 4 * sizeof(char));
		}
		else {
			temp[tempIndex++] = charArr[i];
		}
		i++;
	}
}

void printArr(int code, int front, int end, int n, int r) {
	if (code == 0) {
		printf("error\n");
	}
	else {
		if (n == 0) {
			printf("[]\n");
		}
		else {
			if (r == 0) {
				printf("[%d", arr[front++]);
				for (int i = front; i <= end; i++) {
					printf(",%d", arr[front++]);
				}
				printf("]\n");
			}
			else {
				printf("[%d", arr[end--]);
				for (int i = end; i >= front; i--) {
					printf(",%d", arr[end--]);
				}
				printf("]\n");
			}
			
		}
	}
}

int main() {
	int T, n, front, end;
	int pLen, code, r; // r == 0 : normal, r == 1 : reverse
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%s %d %s", p, &n, charArr);

		front = 0;
		end = strlen(charArr) - 1;
		pLen = strlen(p);
		code = 1;
		r = 0;

		changeArr(end);
		end = n - 1;

		for (int f = 0; f < pLen; f++) {
			if (p[f] == 'R' && p[f + 1] == 'R') {
				f++;
				continue;
			}
			if (p[f] == 'R') {
				if (r == 0)
					r = 1;
				else
					r = 0;
			}
			else if (p[f] == 'D') {
				if (n == 0) {
					code = 0;
					break;
				}
				else {
					if (r == 0) 
						front++;
					else
						end--;
					n--;
				}
					
			}
		}
		printArr(code, front, end, n, r);

	}

	return 0;
}
