#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int s, int m, int e){
    int i = s;
    int j = m+1;
    int temp[e];
    int r=0;
    
    while (i<=m &&j<=e){
        if (arr[i]<arr[j]){
            temp[r] = arr[i];
            r++;
            i++;
        } else {
            temp[r] = arr[j];
            r++;
            j++;
        }
    }

    while (i<=m){
        temp[r] = arr[i];
        r++;
        i++;
    }

    while (j<=e){
        temp[r] = arr[j];
        r++;
        j++;
    }

    for (int k = 0; k<r; k++){
        arr[s+k] = temp[k];
    }
}

void divide(int arr[], int s, int e){
    int m = (s+e)/2;

    if (s<e){
        divide(arr, s, m);
        divide(arr, m+1, e);
        merge(arr, s, m, e);
    }
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr)/sizeof(int);
    divide(arr, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
        
    return 0;
}