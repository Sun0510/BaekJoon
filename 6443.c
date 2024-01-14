#include <stdio.h>
#include <string.h>

int len;
char string[20];
char anagram[20];
char alphabets[26];

void swap(int a, int b) {
    char temp = string[a];
    string[a] = string[b];
    string[b] = temp;
}

void sort(int start, int end) {
    if (start >= end) return;

    int pivot = start;
    int i = start + 1;
    int j = end;

    while (i <= j) {
        while (i <= end && string[i] <= string[pivot]) i++;

        while (j > start && string[j] >= string[pivot]) j--;

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

void fun(int n) {
    if (n == len) {
        printf("%s\n", anagram);
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (alphabets[i] > 0) {
            alphabets[i]--;
            anagram[n] = 'a' + i;
            fun(n + 1);
            alphabets[i]++;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        scanf("%s", string);
        len = strlen(string);
        sort(0, len - 1);

        for (int j = 0; j < 26; j++) {
            alphabets[j] = 0;
        }
        for (int j = 0; j < len; j++) {
            alphabets[string[j] - 'a']++;
        }
        fun(0);
    }
    return 0;
}
