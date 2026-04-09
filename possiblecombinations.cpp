#include <iostream>

void comb(int n, int k, int start, int* current, int depth) {
    if (depth == k) {
        std::cout << "  [";
        for (int i = 0; i < k; ++i) {
            std::cout << current[i];
            if (i < k - 1) std::cout << ",";
        }
        std::cout << "]\n";
        return;
    }
    for (int i = start; i <= n; ++i) {
        current[depth] = i;
        comb(n, k, i + 1, current, depth + 1);
    }
}

int main() {
    int n = 4;
    int k = 3;
    int current[100];
    
    std::cout << "[\n";
    comb(n, k, 1, current, 0);
    std::cout << "]\n";
    
    return 0;
}