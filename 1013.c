#include <stdio.h>
#include <string.h>

char str[201];

int is_zero(int i)
{
	if (str[i] == '0')
		return 1;
	else
		return 0;
}

int is_one(int i)
{
	if (str[i] == '1')
		return 1;
	else
		return 0;
}

int is_ozz(int i)
{
	if (str[i] == '1' && str[i + 1] == '0'&& str[i + 2] == '0')
		return 1;
	else
		return 0;
}

int is_zo(int i)
{
	if (str[i] == '0' && str[i + 1] == '1')
		return 1;
	else
		return 0;
}

int main()
{
	int T, len, i = 0;
	int result, check;
	scanf("%d", &T);
	for (int cnt = 0; cnt < T; cnt++)
	{
		scanf("%s", str);
		len = strlen(str);
		result = 1;
		check = i = 0;

		while (i < len)
		{
			if (is_zero(len - 1))
			{
				result = 0;
				break;
			}

			if (check == 0 && is_ozz(i))
			{
				i += 3;
				if (is_zero(i))
				{
					i++;
					while (!is_one(i))
						i++;
				}
				if (is_one(i))
				{
					i++;
					while (!is_zero(i))
					{
						check = 1;
						i++;
					}

				}
			}
			else if (check == 1 && is_ozz(i - 1))
			{
				check = 0;
				i += 2;
				if (is_zero(i))
				{
					i++;
					while (!is_one(i))
						i++;
				}
				if (is_one(i))
				{
					i++;
					while (!is_zero(i))
					{
						check = 1;
						i++;
					}

				}
			}
			else if (is_zo(i))
			{
				i += 2;
				check = 0;
			}
			else
			{
				result = 0;
				break;
			}			
		}
		if (result == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
