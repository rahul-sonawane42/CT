#include <iostream>

void sortArray(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void backtrack(int* C, int N, int target, int start, int* current, int depth) {
    if (target == 0) {
        std::cout << "[";
        for (int i = 0; i < depth; ++i) {
            std::cout << current[i];
            if (i < depth - 1) std::cout << ", ";
        }
        std::cout << "]\n";
        return;
    }
    for (int i = start; i < N; ++i) {
        if (i > start && C[i] == C[i - 1]) continue;
        if (C[i] > target) break;
        current[depth] = C[i];
        backtrack(C, N, target - C[i], i + 1, current, depth + 1);
    }
}

int main() {
    int C[] = {10, 1, 2, 7, 6, 1, 5};
    int N = 7;
    int target = 8;
    
    sortArray(C, N);
    
    int current[100];
    backtrack(C, N, target, 0, current, 0);
    
    return 0;
}