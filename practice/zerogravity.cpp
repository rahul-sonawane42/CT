#include <bits/stdc++.h>

using namespace std;

void zerograv(int arr[], int n){
    for (int i = n-1; i>= 0; i--){
        if (arr[i] == 0){
            for (int j = i; j< n; j++){
                arr[j] = arr[j+1];
            }
            arr[n-1] = 0;
        }
    }
}

int main() {
    int arr[] = {0,1,0,13,6,0,0,0,0,23,7,21,0,34,0,12,0};
    int size = sizeof(arr)/sizeof(int);
    zerograv(arr,size);

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}