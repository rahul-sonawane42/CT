#include <inttypes.h>
#include <stdio.h>
int frequent_brute_force(int *array, int size)
{
    int max_count = 0;
    int result = array[0];

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (array[i] == array[j])
            {
                count++;
            }
        }

        if (count > max_count)
        {
            max_count = count;
            result = array[i];
        }
    }

    return result;
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

int frequent_optimized(int *array, int size)
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

int main()
{
    int array[] = {2, 4, 1, 2, 5, 1, 2, 3, 4};
    int size = sizeof(array) / sizeof(int);

    int most_frequent = frequent_brute_force(array, size);
    printf("Brute Force : Most frequent element : %d\n", most_frequent);

    most_frequent = frequent_optimized(array, size);
    printf("Optimized : Most frequent element : %d\n", most_frequent);

    return 0;
}