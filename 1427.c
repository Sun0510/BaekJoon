#include <stdio.h>

int arr[11];
int cntArr[10];

int main(void) 
{
    int num;
    int i;
    scanf("%d", &num);
    
    for (i = 0;  num /= 10 > 0; i++) {
        arr[i] = num % 10;
        num /= 10;
    }

    for (int j = 0; j < i; j++) {
        cntArr[arr[j]] += 1;
    }

    for (i = 9; i >= 0; i--) {
        for (int j = 0; j < cntArr[i]; j++)
            printf("%d", i);
    }
    printf("\n");
    return 0;
}
