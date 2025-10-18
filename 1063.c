#include <stdio.h>
#include <string.h>

int is_in(int x, int y)
{
	if (x <= 0 || x >= 9 || y <= 0 || y >= 9)
		return 0;
	else
		return 1;
}

int is_stone(int king_x, int king_y, int stone_x, int stone_y)
{
	if (king_x == stone_x && king_y == stone_y)
		return 1;
	else
		return 0;
}

int main()
{
	char moving[5];
	char king[5];
	char stone[5];
	int N;
	int king_x, king_y;
	int stone_x, stone_y;

	scanf("%s %s %d", king, stone, &N);

	king_x = king[0] - 'A' + 1;
	king_y = king[1] - '0';
	stone_x = stone[0] - 'A' + 1;
	stone_y = stone[1] - '0';

	for (int i = 0; i < N; i++)
	{
		scanf("%s", moving);

		if (!strcmp(moving, "R") && is_in(king_x + 1, king_y))
		{	
			if (is_stone(king_x + 1, king_y, stone_x, stone_y))
			{
				if (is_in(stone_x + 1, stone_y))
				{
					king_x++;
					stone_x++;
				}
			}
			else
				king_x++;
		}
				
		else if (!strcmp(moving, "L") && is_in(king_x - 1, king_y))
		{
			if (is_stone(king_x - 1, king_y, stone_x, stone_y))
			{
				if (is_in(stone_x - 1, stone_y))
				{
					king_x--;
					stone_x--;
				}
			}
			else
				king_x--;
				
		}
		else if (!strcmp(moving, "B") && is_in(king_x, king_y - 1))
		{
			if (is_stone(king_x, king_y - 1, stone_x, stone_y))
			{
				if (is_in(stone_x, stone_y - 1))
				{
					king_y--;
					stone_y--;
				}
			}
			else
				king_y--;
		}
		else if (!strcmp(moving, "T") && is_in(king_x, king_y + 1))
		{
			if (is_stone(king_x, king_y + 1, stone_x, stone_y))
			{
				if (is_in(stone_x, stone_y + 1))
				{
					king_y++;
					stone_y++;
				}
			}
			else
				king_y++;
		}
		else if (!strcmp(moving, "RT") && is_in(king_x + 1, king_y + 1))
		{
			if (is_stone(king_x + 1, king_y + 1, stone_x, stone_y))
			{
				if (is_in(stone_x + 1, stone_y + 1))
				{
					king_x++;
					king_y++;
					stone_x++;
					stone_y++;
				}
			}
			else
			{
				king_x++;
				king_y++;
			}
		}
		else if (!strcmp(moving, "LT") && is_in(king_x - 1, king_y + 1))
		{
			if (is_stone(king_x - 1, king_y + 1, stone_x, stone_y))
			{
				if (is_in(stone_x - 1, stone_y + 1))
				{
					king_x--;
					king_y++;
					stone_x--;
					stone_y++;
				}
			}
			else
			{
				king_x--;
				king_y++;
			}			
		}
		else if (!strcmp(moving, "RB") && is_in(king_x + 1, king_y - 1))
		{
			if (is_stone(king_x + 1, king_y - 1, stone_x, stone_y))
			{
				if (is_in(stone_x, stone_y - 1))
				{
					king_x++;
					king_y--;
					stone_x++;
					stone_y--;
				}
			}
			else
			{
				king_x++;
				king_y--;
			}
		}
		else if (!strcmp(moving, "LB") && is_in(king_x - 1, king_y - 1))
		{
			if (is_stone(king_x - 1, king_y - 1, stone_x, stone_y))
			{
				if (is_in(stone_x - 1, stone_y - 1))
				{
					king_x--;
					king_y--;
					stone_x--;
					stone_y--;
				}
			}
			else
			{
				king_x--;
				king_y--;
			}
		}
	}

	king[0] = king_x + 'A' - 1;
	king[1] = king_y + '0';
	stone[0] = stone_x + 'A' - 1;
	stone[1] = stone_y + '0';

	printf("%s\n", king);
	printf("%s\n", stone);

	return 0;
}
