#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool hasDuplicates(int arr[], int n){
    for (int i=1; i<n; i++){
        int j = i-1;
        int temp;
        while (j>=0 && arr[j+1]<arr[j]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j--;
        }
    }

    for (int i = 0; i<n-1; i++){
        if (arr[i] == arr[i+1]){
            return true;
        }
    }

    return false;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int p = partition(array, low, high);
        quicksort(array, low, p - 1);
        quicksort(array, p + 1, high);
    }
}

bool duplicate_optimized(int *array, int size)
{
    quicksort(array, 0, size - 1);

    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] == array[i + 1])
        {
            return true;
        }
    }
    return false;
}

int main() {
    int A[] = {4, 2, 7, 9, 8};
    int n = sizeof(A) / sizeof(A[0]);

    if (hasDuplicates(A, n)) {
        printf("The array contains repeated elements.\n");
    } else {
        printf("The array does not contain repeated elements.\n");
    }

    if (duplicate_optimized(A, n)) {
        printf("The array contains repeated elements.\n");
    } else {
        printf("The array does not contain repeated elements.\n");
    }

    return 0;
}