#include <stdio.h>
#include <string.h>

int sudoku[9][9];
int rowIndex[81];
int colIndex[81];
int blanks;

int checkNum(int n, int row, int col) {

    for (int k = 0; k < 9; k++) {
        if (sudoku[row][k] == n)
            return 0;
        if (sudoku[k][col] == n)
            return 0;
    }

    int refRow;
    int refCol;

    if (row < 3) refRow = 0;
    else if (row < 6) refRow = 3;
    else refRow = 6;

    if (col < 3) refCol = 0;
    else if (col < 6) refCol = 3;
    else refCol = 6;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[refRow + i][refCol + j] == n)
                return 0;
        }
    }
    return 1;
}

void fun(int depth) {
    int row = rowIndex[depth];
    int col = colIndex[depth];
    if (depth == blanks) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }

    for (int n = 1; n <= 9; n++) {
        if (checkNum(n, row, col)) {
            sudoku[row][col] = n;
            fun(depth + 1);
            sudoku[row][col] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
            if (sudoku[i][j] == 0) {
                rowIndex[blanks] = i;
                colIndex[blanks] = j;
                blanks++;
            }
                
        }
    }
    fun(0);
    return 0;
}
