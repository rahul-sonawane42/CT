#include <bits/stdc++.h>

using namespace std;

void rotateright(int arr[],int n, int k){
    int count = 0;
    while (count < k){
        int temp = arr[n-1];
        for (int i = n-1; i>0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = temp;
        count++;
    }
}

int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    int k = 2;
    rotateright(arr, size, k);

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}