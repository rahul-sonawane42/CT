#include<iostream>
using namespace std;

void dsort(int arr[], int n){
    int f = 0;
    int b = n-1;
    while (f<b){
        if (arr[f] == 0){
            f++;
        }
        if (arr[b] == 2){
            b--;
        }
        if (arr[f] == 2){
            swap(arr[f],arr[b]);
            f++;
            b--;
        }
        if (arr[b] == 0){
            swap(arr[f],arr[b]);
            f++;
            b--;
        }
    }
    
}

int main(){
    int arr[] = {0,2,1,2,1,0,2,0,1,0,2,1};
    int size = sizeof(arr)/sizeof(int);
    dsort(arr,size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}