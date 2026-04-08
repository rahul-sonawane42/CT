#include <iostream>
using namespace std;

void dutchsort(int arr[], int n){
    int lo = 0;
    int hi = n-1;
    int mid = 0;

    while (mid <= hi){
        if (arr[mid] == 0){
            swap(arr[lo++],arr[mid++]);
        }
        else if (arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[hi--]);
        }
    }
}

int main() {
    int arr[] = { 0, 1, 2, 0, 1, 2, 1, 2, 1, 0, 0, 2 };
    int n = sizeof(arr)/sizeof(int);
    
    dutchsort(arr, n); 

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}