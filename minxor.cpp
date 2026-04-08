#include <iostream>
using namespace std;


int findMinXor(int arr[], int N) {
    for (int i=1; i<N; i++){
        int j = i-1;
        int temp;
        while (j>=0 && arr[j+1]<arr[j]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j--;
        }
    }

    int min_xor = arr[0] ^ arr[1];
    for (int i = 1; i < N - 1; i++) {
        int val = arr[i] ^ arr[i+1];
        if (val < min_xor) {
            min_xor = val;
        }
    }
    return min_xor;
}

int main()
{
    int array1[] = {0, 2, 5, 7};
    int size1 = sizeof(array1) / sizeof(int);

    int minxor1 = findMinXor(array1, size1);
    cout<< "The min xor value of array1 is "<<minxor1<<endl;

    int array2[] = {6, 9, 12, 20};
    int size2 = sizeof(array2) / sizeof(int);

    int minxor2 = findMinXor(array2, size2);
    cout<< "The min xor value of array2 is "<<minxor2<<endl;
    return 0;
}