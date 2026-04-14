#include <bits/stdc++.h>

using namespace std;
int num_inv(int arr[], int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
                count++;
            }
        }
    }
    return count;
}
int main() {
    int arr[] = {5,4,6,3,2,1};
    int n = sizeof(arr)/sizeof(int);

    cout << "Number of Inversions: " << num_inv(arr,n) << endl;
    return 0;
}