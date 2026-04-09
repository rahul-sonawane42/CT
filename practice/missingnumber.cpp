#include<bits/stdc++.h>
using namespace std;

int sum = 0;
void missNum(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "Sum is :" << sum << endl;
}
void sumofNum(int n){
    int size = n+1;
    int actSum = (size* (size+1)) / 2;
    cout << "Actual Sum: " << actSum << endl;
    int num = actSum - sum;
    cout << "Number is: " << num << endl;
}

int main(){
    int arr[] = {8, 2, 4, 5, 3, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "N is: " << n << endl;
    missNum(arr, n);
    sumofNum(n);
return 0;
}