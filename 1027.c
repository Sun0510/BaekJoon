#include <stdio.h>
#define MIN_GRADIENTS -1000000001.999999999

long long int buildings[50];
double gradients[50][50];
int views[50];

int main()
{
	int N, i, j, result = 0;
	double highest = MIN_GRADIENTS;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &buildings[i]);

	for (i = 0; i < N; i++)
	{
		for (j = i - 1; j >= 0; j--)
			gradients[i][j] = (double)(buildings[i] - buildings[j]) / (i - j);

		for (j = i + 1; j < N; j++)
			gradients[i][j] = (double)(buildings[j] - buildings[i]) / (j - i);
	}

	for (i = 0; i < N; i++)
	{
		if (i != 0)
		{
			highest = gradients[i][i - 1];
			views[i]++;
		}
			

		for (j = i - 1; j >= 0; j--)
		{
			if (gradients[i][j] < highest)
			{
				views[i]++;
				highest = gradients[i][j];
			}
		}

		if (i != N - 1)
		{
			highest = gradients[i][i + 1];
			views[i]++;
		}

		for (j = i + 1; j < N; j++)
		{
			if (gradients[i][j] > highest)
			{
				views[i]++;
				highest = gradients[i][j];
			}
		}

		if (views[i] >= result)
			result = views[i];
	}

	printf("%d\n", result);

	return 0;
}
