#include <iostream>
using namespace std;

long long findPalindrome(int A) {
    if (A == 1) return 1; 

    int len = 1;
    int count = 0;

    while (true) {
        int num_palin = 1 << ((len - 1) / 2);
        if (count + num_palin >= A) {
            break;
        }
        count += num_palin;
        len++;
    }

    int offset = A - count - 1;
    
    long long firstHalf = (1LL << ((len - 1) / 2)) | offset;
    
    long long result = firstHalf;
    
    int mirrorBits = len / 2;
    long long mirrorPart = firstHalf;
    
    if (len % 2 != 0) {
        mirrorPart >>= 1; 
    }
    
    for (int i = 0; i < mirrorBits; i++) {
        result <<= 1;
        result |= (mirrorPart & 1);
        mirrorPart >>= 1;
    }

    return result;
}

int main() {
    cout << findPalindrome(9) << endl;
    cout << findPalindrome(5) << endl;
    return 0;
}