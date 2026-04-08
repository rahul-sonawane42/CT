#include <stdbool.h>
#include <stdio.h>

bool duplicates_brute_force(int *array, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] == array[j])
            {
                return true;
            }
        }
    }

    return false;
};

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

int main()
{

    int array[] = {6, 7, 1, 4, 3, 5, 2, 6};
    int size = sizeof(array) / sizeof(int);

    bool is_duplicate = duplicates_brute_force(array, size);
    if (is_duplicate)
    {
        puts("Brute Force : Duplicate element present");
    }
    else
    {
        puts("Brute Force : Duplicate element not present");
    }

    is_duplicate = duplicate_optimized(array, size);
    if (is_duplicate)
    {
        puts("Optimized : Duplicate element present");
    }
    else
    {
        puts("Optmized : Duplicate element not present");
    }

    return 0;
}
