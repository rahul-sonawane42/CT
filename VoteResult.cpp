#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;

struct Vote{
    int id;
    int count;
};

int Votes(int A[], int n){
    Vote result[n];
    int UnqId = 0;

    int MaxVotes = 0;
    int WinId= -1;

    for (int i = 0; i<n; i++){
        int currid = A[i];
        bool found = false;

        for (int j=0; j<UnqId; j++){
            if (result[j].id == currid){
                result[j].count++;
                found = true;

                if (result[j].count > MaxVotes){
                    MaxVotes = result[j].count;
                    WinId = result[j].id;
                }

                break;
            }
        }

        if (!found){
            result[UnqId].id = currid;
            result[UnqId].count = 1;
            UnqId++;
        }

    }
    return WinId;
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

int votes_optimized(int *array, int size)
{
    quicksort(array, 0, size - 1);

    int result = array[0];
    int max_count = 1;
    int count = 1;

    for (int i = 1; i < size; i++)
    {
        if (array[i] == array[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }

        if (count > max_count)
        {
            max_count = count;
            result = array[i];
        }
    }

    return result;
}

int main() {
    int A[] = {4, 2, 7, 9, 2, 8};
    int n = sizeof(A) / sizeof(A[0]);

    int WinId = Votes(A,n);
    printf("Winner is : %d\n", WinId);

    WinId = votes_optimized(A,n);
    printf("Winner is : %d", WinId);

    return 0;
}