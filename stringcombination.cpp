#include <iostream>
#include <string>
using namespace std;

int lenGet(const string& s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void generateStr(string A[], int N, int index, string currStr) {
    if (index == N) {
        cout << currStr << " ";
        return;
    }
    
    int len = lenGet(A[index]);
    
    for (int i = 0; i < len; i++) {
        generateStr(A, N, index + 1, currStr + A[index][i]);
    }
}

int main() {
    cout << "--- Problem 1 Output ---" << endl;
    string A[] = {"ab", "cd"};
    int N = 2;
    
    cout << "[ ";
    generateStr(A, N, 0, "");
    cout << "]" << endl << endl;

    return 0;
}