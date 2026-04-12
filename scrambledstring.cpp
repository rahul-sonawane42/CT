#include <iostream>

class ScrambleString {
public:
    bool isScramble(const char* A, const char* B) {
        int lenA = 0;
        while (A[lenA] != '\0') {
            lenA++;
        }
        
        int lenB = 0;
        while (B[lenB] != '\0') {
            lenB++;
        }
        
        if (lenA != lenB) {
            return false;
        }
        
        if (lenA == 0) {
            return true;
        }
        
        int n = lenA;
        
        bool*** dp = new bool**[n + 1];
        for (int i = 0; i <= n; ++i) {
            dp[i] = new bool*[n];
            for (int j = 0; j < n; ++j) {
                dp[i][j] = new bool[n];
                for (int k = 0; k < n; ++k) {
                    dp[i][j][k] = false;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i] == B[j]) {
                    dp[1][i][j] = true;
                }
            }
        }
        
        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i <= n - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    for (int q = 1; q < k; ++q) {
                        if (dp[q][i][j] && dp[k - q][i + q][j + q]) {
                            dp[k][i][j] = true;
                            break;
                        }
                        if (dp[q][i][j + k - q] && dp[k - q][i + q][j]) {
                            dp[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        bool result = dp[n][0][0];
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < n; ++j) {
                delete[] dp[i][j];
            }
            delete[] dp[i];
        }
        delete[] dp;
        
        return result;
    }
};

int main() {
    ScrambleString solver;
    
    const char* A1 = "great";
    const char* B1 = "rgeat";
    
    std::cout << "Checking if '" << B1 << "' is a scramble of '" << A1 << "': ";
    if (solver.isScramble(A1, B1)) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }

    const char* A2 = "abcde";
    const char* B2 = "caebd";
    
    std::cout << "Checking if '" << B2 << "' is a scramble of '" << A2 << "': ";
    if (solver.isScramble(A2, B2)) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }

    return 0;
}