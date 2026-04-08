#include<iostream>
using namespace std;

long long MOD = 1000000007;

int findLargestPowerOf2(int n) {
    int x = 0;
    while ((1 << (x + 1)) <= n) {
        x++;
    }
    return x;
}

int countSetBits(int A) {
    if (A == 0) return 0;

    int x = findLargestPowerOf2(A);
    
    long long bitsTillPower = (long long)x * (1LL << (x - 1));
    
    long long msbBits = (A - (1LL << x) + 1);
    
    long long total = (bitsTillPower % MOD + msbBits % MOD + countSetBits(A - (1LL << x)) % MOD) % MOD;
    
    return (int)total;
}

int main(){
    int count1 = countSetBits(11);
    cout<< "Total set bits are: "<<count1<<endl;

    int count2 = countSetBits(25);
    cout<< "Total set bits are: "<<count2<<endl;

    return 0;
}
