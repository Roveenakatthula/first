#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Function to multiply two matrices
void matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size();
    int m = B.size();
    int p = B[0].size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < m; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Example matrix sizes
    int n = 512, m = 512, p = 512;

    // Initialize matrices
    vector<vector<int>> A(n, vector<int>(m, 1)); // Matrix A with all 1s
    vector<vector<int>> B(m, vector<int>(p, 2)); // Matrix B with all 2s
    vector<vector<int>> C(n, vector<int>(p, 0)); // Result matrix C initialized to 0

    // Measure execution time
    auto start = high_resolution_clock::now();
    matrixMultiply(A, B, C);
    auto stop = high_resolution_clock::now();

    // Output execution time
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Execution Time: " << duration.count() << " ms" << endl;

    return 0;
}
