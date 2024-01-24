#include <stdio.h>

int main() {
	int point;
	char grade;

	scanf("%d", &point);

	if (point >= 90)
		grade = 'A';
	else if (point >= 80)
		grade = 'B';
	else if (point >= 70)
		grade = 'C';
	else if (point >= 60)
		grade = 'D';
	else
		grade = 'F';
	
	printf("%c\n", grade);

	return 0;
}
