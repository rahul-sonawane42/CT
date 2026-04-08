#include <iostream>
#include <algorithm>

using namespace std;

void bubble_sort(int* array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void counting_sort(int* array, int size)
{
    if (size <= 0) return;

    int min_val = array[0];
    int max_val = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] < min_val) min_val = array[i];
        if (array[i] > max_val) max_val = array[i];
    }

    int range = max_val - min_val + 1;
    int* count = new int[range]{};

    for (int i = 0; i < size; i++)
    {
        count[array[i] - min_val]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            array[index] = i + min_val;
            count[i]--;
            index++;
        }
    }

    delete[] count;
}

void print_array(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array1[] = {4, 5, 1, 2, 4, 6, 2, 3};
    int size1 = sizeof(array1) / sizeof(int);

    bubble_sort(array1, size1);
    print_array(array1, size1);

    int array2[] = {4, 5, 1, 2, 4, 6, 2, 3};
    int size2 = sizeof(array2) / sizeof(int);

    counting_sort(array2, size2);
    print_array(array2, size2);

    return 0;
}