#include <stdio.h>
#include <string.h>

int results[4][18];
int current[18];
int possibility[4];

void fun(int seq, int team1, int team2, int result) {
    if (result == 0) {
        current[team1 * 3]++;
        current[team2 * 3 + 2]++;
    }
    else if (result == 1) {
        current[team1 * 3 + 1]++;
        current[team2 * 3 + 1]++;
    }
    else {
        current[team1 * 3 + 2]++;
        current[team2 * 3]++;
    }

    if (team1 == 4 && team2 == 5) {
        int check = 1;
        for (int j = 0; j < 18; j++) {
            if (results[seq][j] != current[j]) {
                return;
            }
        }
        possibility[seq] = 1;
        return;
    }

    if (team1 < 4 && team2 < 5) {
        // team1 이김
        fun(seq, team1, team2 + 1, 0);
        current[team1 * 3]--;
        current[(team2 + 1) * 3 + 2]--;

        // 비김
        fun(seq, team1, team2 + 1, 1);
        current[team1 * 3 + 1]--;
        current[(team2 + 1) * 3 + 1]--;

        // team1 짐
        fun(seq, team1, team2 + 1, 2);
        current[team1 * 3 + 2]--;
        current[(team2 + 1) * 3]--;
    }
    
    if (team1 < 4 && team2 == 5) {
        // team1 이김
        fun(seq, team1 + 1, team1 + 2, 0);
        current[(team1 + 1) * 3]--;
        current[(team1 + 2) * 3 + 2]--;

        // 비김
        fun(seq, team1 + 1, team1 + 2, 1);
        current[(team1 + 1) * 3 + 1]--;
        current[(team1 + 2) * 3 + 1]--;

        // team1 짐
        fun(seq, team1 + 1, team1 + 2, 2);
        current[(team1 + 1) * 3 + 2]--;
        current[(team1 + 2) * 3]--;
    }  
    
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 18; j++) {
            scanf("%d", &results[i][j]);
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            fun(i, 0, 1, j);
            memset(current, 0, sizeof(int) * 18);
        }
        
    }
    for (int i = 0; i < 4; i++) {
        printf("%d ", possibility[i]);
    }
    printf("\n"); 
    return 0;
}
