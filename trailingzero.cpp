#include<iostream>
using namespace std;

int countTrailingZeroes(int A) {
    if (A == 0) return 0;
    int count = 0;

    while ((A & 1) == 0) {
        count++;
        A >>= 1;
    }
    return count;
}

int main(){
    int count1 = countTrailingZeroes(18);
    cout<< "Number of trailing zeros are "<< count1 <<endl;
    int count2 = countTrailingZeroes(24);
    cout<< "Number of trailing zeros are "<< count2 <<endl;
    return 0;
}