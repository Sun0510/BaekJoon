#include <stdio.h>
#include <string.h>

int L;
int C;
char code[15];
char alphabets[15];

void swap(int a, int b) {
    char temp = alphabets[a];
    alphabets[a] = alphabets[b];
    alphabets[b] = temp;
}

void sort(int start, int end) {
    if (start >= end) return;

    int pivot = start;
    int i = start + 1;
    int j = end;

    while (i <= j) { 
        while (i <= end && alphabets[i] <= alphabets[pivot]) i++;

        while (j > start && alphabets[j] >= alphabets[pivot]) j--; 

        if (i > j) {
            swap(j, pivot);
        }
        else {
            swap(i, j);
        }
    }

    sort(start, j - 1);
    sort(j + 1, end);
}

void fun(int n, int start, int vowel, int consonant) {
    if (n == L) {
        if (vowel >= 1 && consonant >= 2) {
            for (int i = 0; i < L; i++) {
                printf("%c", code[i]);
            }
            printf("\n");
        }
    }

    char alphabet;

    for (int i = start; i < C; i++) {
        alphabet = alphabets[i];
        code[n] = alphabet;
        
        if (alphabet == 'a' || alphabet == 'i' || alphabet == 'u' || alphabet == 'e' || alphabet == 'o') {
            fun(n + 1, i + 1, vowel + 1, consonant);
        }
        else {
            fun(n + 1, i + 1, vowel, consonant + 1);
        }
    }
}

int main() {
    scanf("%d %d", &L, &C);
    getchar();
    for (int i = 0; i < C; i++) {
        scanf("%c", &alphabets[i]);
        getchar();
    }
    sort(0, C - 1);
    fun(0, 0, 0, 0);
    return 0;
}
