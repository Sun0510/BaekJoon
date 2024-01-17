#include <stdio.h>

int ttt[3][3]; // 0 -> blank, 1 -> X, 2 -> O
int blanks;

int min(int a, int b) {
    return a > b ? b : a;
}

int isWin(int turn) {
    int sum = 0;
    // 가로
    for (int i = 0; i < 3; i++) {
        if (ttt[i][0] == turn && ttt[i][0] == ttt[i][1] && ttt[i][1] == ttt[i][2])
            return 1;
    }

    // 세로
    for (int j = 0; j < 3; j++) {
        if (ttt[0][j] == turn && ttt[0][j] == ttt[1][j] && ttt[1][j] == ttt[2][j])
            return 1;
    }
    
    // 대각선1
    if (ttt[0][0] == turn && ttt[0][0] == ttt[1][1] && ttt[1][1] == ttt[2][2])
        return 1;

    // 대각선2
    if (ttt[0][2] == turn && ttt[0][2] == ttt[1][1] && ttt[1][1] == ttt[2][0])
        return 1;

    return 0;
}

int fun(int turn) {
    int result = 2;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ttt[i][j] == 0) {
                ttt[i][j] = turn;

                if (isWin(turn) == 1)
                    result = min(result, -1);

                if (turn == 1)
                    result = min(fun(2), result);
                else
                    result = min(fun(1), result);

                ttt[i][j] = 0;
            }
        }
    }

    if (result == 1)
        return -1;
    else if (result == 0 || result == 2)
        return 0;
    else
        return 1;
}

int main() {
    int result; // -1 -> Lose, 0 -> Draw, 1 -> Win
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &ttt[i][j]);
            if (ttt[i][j] == 0) {
                blanks++;
            }
               
        }
    }
    if (blanks % 2 == 1) { // X 차례
        result = fun(1);
    }
    else { // O 차례
        result = fun(2);
    }
    
    if (result == -1)
        printf("L\n");
    else if (result == 0)
        printf("D\n");
    else
        printf("W\n");

    return 0;
}
