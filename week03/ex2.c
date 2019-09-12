#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}


void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}


int main() {
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(int);
    bubble_sort(arr, n);
    printArray(arr, n);
    return 0;
}
