#include <bits/stdc++.h>

using namespace std;

void longestsub(int stk[], int n){
    int max_size = 0;
    int init;
    int curr_size = 0;
    int curr=0;
    for (int i = 0; i<n; i++){
        curr_size++;
        if (stk[i]< stk[i+1]){
            curr++;
        }else{
            if (curr_size> max_size){
                max_size = curr_size;
                init = curr-curr_size+1;
                curr_size = 0;
                curr++;
            }
        }
    }
    cout<< "Max Size: " << max_size << endl;
    for (int i = init; i< init+max_size; i++){
        cout<< stk[i] << " ";
    }
}

int main() {
    int stk[] = {2,3,4,1,5,6,7,3,1};
    int n = sizeof(stk)/sizeof(int);

    longestsub(stk, n);
    return 0;
}