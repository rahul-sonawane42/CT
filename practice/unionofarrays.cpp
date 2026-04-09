#include<bits/stdc++.h>
using namespace std;

void Arrunion(int arr1[], int arr2[], int n, int m){
    set<int> s;
    for (int i = 0; i<n; i++){
        s.insert(arr1[i]);
    }
    for (int j = 0; j<m; j++){
        s.insert(arr2[j]);
    }
    for(int it: s){
            cout << it << " ";
        }
        cout << endl;
}

int main(){
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[] = {2,3,4,4,5,11,12};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    Arrunion(arr1, arr2, n, m);
return 0;
}