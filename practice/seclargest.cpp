#include <bits/stdc++.h>

using namespace std;

int secondMax(int arr[], int n){
    int maxel = INT_MIN;
    int secmax = INT_MIN;

    for (int i = 0; i < n; i++){
        if (arr[i]>maxel){
            secmax = maxel;
            maxel = arr[i];
        } else if (arr[i] > secmax && arr[i]!=maxel){
            secmax = arr[i];
        }
    }

    return (secmax == INT_MIN) ? -1 : secmax;
}

int main() {
    int arr[] = {4,4,4,4,4,4};
    int size = sizeof(arr)/sizeof(int);

    int sec = secondMax(arr, size);
    if (sec == -1){
        cout << "No second largest number!!" << endl;
    }else{
        cout << "Second Largest is " << sec << endl;
    }
    return 0;
}