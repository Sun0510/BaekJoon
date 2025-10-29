#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 1000001

int arr[MAX_NUM + 1];
int prime_numbers[MAX_NUM + 1];

void Eratosthenes() 
{
    int k = 0;
    
    for (int i = 2; i <= MAX_NUM; i++) {
        arr[i] = i;
    }
    
    for (int i = 2; i * i <= MAX_NUM; i++)
    {
        if (arr[i] == 0) 
            continue;

        for (int j = i * 2; j <= MAX_NUM; j += i)
            arr[j] = 0;
    }

    for (int i = 0; i <= MAX_NUM + 1; i++)
    {
        if (arr[i] != 0)
            prime_numbers[k++] = arr[i];
    }
    prime_numbers[MAX_NUM - 1] = k;
}

int lower_search(int n, int a) {
    int left = 0, right = n;  
    while (left < right) {
        int mid = (left + right) / 2;
        if (prime_numbers[mid] < a)
            left = mid + 1;
        else
            right = mid;
    }

    if (left >= n) return -1; 
    return left;
}

int upper_search(int n, int b) {
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (prime_numbers[mid] <= b)
            left = mid + 1;
        else
            right = mid;
    }

    if (left == 0) return -1;
    return left - 1;
}


int main()
{
    int N, a, b, i, j, k, mid;
    
    Eratosthenes();

    scanf("%d", &N);
    for (k = 0; k < N; k++)
    {  
        scanf("%d %d", &a, &b);
        i = lower_search(prime_numbers[MAX_NUM - 1], a);
        j = upper_search(prime_numbers[MAX_NUM - 1], b);

        mid = (i + j) / 2;
        if (i == -1 || j == -1)
            printf("-1\n");
        else if ((j - i + 1) % 2 == 0)
            printf("-1\n");
        else
            printf("%d\n", prime_numbers[mid]);
        
    }

	return 0;
}
