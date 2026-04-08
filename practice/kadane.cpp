#include <iostream>
using namespace std;

int kadane(int arr[], int n){
    int res = arr[0];
    int maxending = arr[0];

    for (int i = 1; i< n; i++){
        maxending = max(arr[i], maxending + arr[i]);

        res = max(res,maxending);
    }
    return res;
}

int main() {
    int arr[] = {2, 3, -8, 7, -1, 2, 3};
    int size = sizeof(arr)/sizeof(int);
    cout << kadane(arr, size); 
    return 0;
}