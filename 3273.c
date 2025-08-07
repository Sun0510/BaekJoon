#include <stdio.h>

int arr[2000001];

int partition(int arr[], int start, int end) {
    int low, high;
    int pivot = arr[start];

    low = start + 1;
    high = end;

    while (low <= high) {
        while (arr[low] < pivot) low++; 
        while (arr[high] > pivot) high--; 

        if (low <= high) { 
            int temp = arr[low];    
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }

    
    int temp = arr[start];
    arr[start] = arr[high];
    arr[high] = temp;

    return high; 

}

void quick_sort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);

        quick_sort(arr, left, pivot - 1); 
        quick_sort(arr, pivot + 1, right);
    }
}
int main() {
    int n, x, front, end, result = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &x);

    front = 0;
    end = n - 1;

    quick_sort(arr, 0, n - 1);

    while (front < end) {
        if (arr[front] + arr[end] < x)
            front++;
        else if (arr[front] + arr[end] > x)
            end--;
        else {
            result++;
            front++;
        }
    }

    printf("%d\n", result);
}
