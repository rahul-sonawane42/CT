#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
};

void counting_sort(int *array, int size)
{

    int min = array[0];
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
            min = array[i];

        if (array[i] > max)
            max = array[i];
    }

    int range = max - min - 1;

    int *count = calloc(range, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            array[index] = i;
            count[i]--;
            index++;
        }
    }

    free(count);
};

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{

    int array1[] = {4, 5, 1, 2, 4, 6, 2, 3};
    int size = sizeof(array1) / sizeof(int);

    bubble_sort(array1, size);
    print_array(array1, size);

    int array2[] = {4, 5, 1, 2, 4, 6, 2, 3};
    size = sizeof(array1) / sizeof(int);

    counting_sort(array1, size);
    print_array(array1, size);

    return 0;
}