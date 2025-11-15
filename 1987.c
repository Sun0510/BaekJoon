#include <stdio.h>
#include <stdlib.h>

int R, C, max;
char board[20][20];
int visited[20][20];
int used_alph[26];

void DFS(int y, int x, int cnt) {
	int used;
	
	visited[y][x] = 1;
	used_alph[board[y][x] - 'A'] = 1;
	cnt++;

	if (cnt > max)
		max = cnt;
	
	if (y - 1 >= 0 && y - 1 < R && visited[y - 1][x] == 0) {
		used = board[y - 1][x] - 'A';
		if (used_alph[used] == 0) {
			DFS(y - 1, x, cnt);
			visited[y - 1][x] = 0;
			used_alph[used] = 0;
		}
			
	}
	if (y + 1 >= 0 && y + 1 < R && visited[y + 1][x] == 0) {
		used = board[y + 1][x] - 'A';
		if (used_alph[used] == 0) {
			DFS(y + 1, x, cnt);
			visited[y + 1][x] = 0;
			used_alph[used] = 0;
		}
			
	}
	if (x - 1 >= 0 && x - 1 < C && visited[y][x - 1] == 0) {
		used = board[y][x - 1] - 'A';
		if (used_alph[used] == 0) {
			DFS(y, x - 1, cnt);
			visited[y][x - 1] = 0;
			used_alph[used] = 0;
		}
			
	}
	if (x + 1 >= 0 && x + 1 < C && visited[y][x + 1] == 0) {
		used = board[y][x + 1] - 'A';
		if (used_alph[used] == 0) {
			DFS(y, x + 1, cnt);
			visited[y][x + 1] = 0;
			used_alph[used] = 0;
		}			
	}
}

int main()
{
	char str[20];
	char a;
	int cnt = 0;

	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", str);
		for (int j = 0; j < C; j++) {
			board[i][j] = str[j];
		}
	}

	a = board[0][0];
	used_alph[a - 'A'] = 1;
	DFS(0, 0, cnt);
	
	printf("%d\n", max);
	return 0;
}
