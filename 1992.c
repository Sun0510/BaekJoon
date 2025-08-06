#include <stdio.h>
#include <stdlib.h>

char data[64][64];

void compress(int x, int y, int len) 
{
	int num_white, num_black, half_len;
	num_white = num_black = 0;

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (data[y + i][x + j] == '0')
				num_white++;
			else
				num_black++;
		}
	}
	if (num_white == len * len)
		printf("0");
	else if (num_black == len * len)
		printf("1");
	else 
	{
		half_len = len / 2;

		printf("(");
		compress(x, y, half_len);
		compress(x + half_len, y, half_len);
		compress(x, y + half_len, half_len);
		compress(x + half_len, y + half_len, half_len);
		printf(")");
	}
	return;
}

int main()
{
	int N;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) 
	{
		scanf("%s", data[i]);
	}

	compress(0, 0, N);

	return 0;
}
