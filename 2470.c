#include <stdio.h>
#include <stdlib.h>

int arr[100005];

int compare(const int* a, const int* b) {
    return(*a - *b);
}

int main() {
    int N;
    int currentNum, minNum, minLeft, minRight;
    int left, right;

    minNum = 2000000000;
    minLeft = -1000000000;
    minRight = 1000000000;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);
    
    left = 0;
    right = N - 1;

    while (left != right) {
        currentNum = arr[left] + arr[right];

        if (abs(currentNum) < minNum) {
            minNum = abs(currentNum);
            minLeft = left;
            minRight = right;

            if (minNum == 0)
                break;
        }
        
        if (0 < currentNum) {
            right--;
        }
        else {
            left++;
        }
    }

    printf("%d %d\n", arr[minLeft], arr[minRight]);
	return 0;
}
