#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int isMatch(const std::string& A, const std::string& B) {
        int m = A.length();
        int n = B.length();

        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= n; ++j) {
            if (B[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (B[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } 
                else if (B[j - 1] == '?' || A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n] ? 1 : 0;
    }
};

int main() {
    Solution solver;
    
    std::string A1 = "aa";
    std::string B1 = "a";
    std::cout << "Input: A = \"" << A1 << "\", B = \"" << B1 << "\"\n";
    if (solver.isMatch(A1, B1)) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }
    std::string A2 = "aa";
    std::string B2 = "*";
    std::cout << "Input: A = \"" << A2 << "\", B = \"" << B2 << "\"\n";
    if (solver.isMatch(A1, B1)) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }

    std::string A3 = "cb";
    std::string B3 = "?a";
    std::cout << "Input: A = \"" << A3 << "\", B = \"" << B3 << "\"\n";
    if (solver.isMatch(A1, B1)) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }

    return 0;
}