#include <stdio.h>
#include <string.h>

int N;
char expr[20];

void fun(int depth, int sum, int operand, char operator) {
    if (operator == '+') {
        sum += operand;
    }
    else if (operator == '-') {
        sum -= operand;
    }

    if (depth == N && sum == 0) {
        printf("%s", expr);
        printf("\n");
        
        return;
    }
    else if (depth == N && sum != 0) {
        return;
    }

    depth++;
    expr[depth * 2 - 3] = ' ';
    if (operator == '+') {
        fun(depth, sum - operand, operand * 10 + depth, '+');
    }
    else if (operator == '-') {
        fun(depth, sum + operand, operand * 10 + depth, '-');
    }
    
    expr[depth * 2 - 3] = '+';
    fun(depth, sum, depth, '+');

    expr[depth * 2 - 3] = '-';
    fun(depth, sum, depth, '-');
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int i = 1; i <= 9; i++) {
        expr[(i - 1) * 2] = i + '0';
    }
    for (int i = 0; i < cases; i++) {
        scanf("%d", &N);
        for (int i = 0; i < 9; i++) {
            expr[i * 2 + 1] = 0;
        }
        fun(1, 0, 1, '+');
        printf("\n");
    }
    
    return 0;
}
