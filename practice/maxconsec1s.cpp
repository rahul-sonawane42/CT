#include<bits/stdc++.h>
using namespace std;
class ConsecOne{
    public:
    void maxConOne(int arr[], int n){
        int counter = 0;
        int maxCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                counter++;
                maxCount = max(maxCount, counter);
            }
            else {
                counter = 0;
            }
        }
        cout << "Max Count is : " << maxCount << endl;
    }
};
int main(){
    ConsecOne co;
    int arr[] = {1, 0, 1, 1, 0, 1, 1, 1, 1} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    co.maxConOne(arr, n);
return 0;
}