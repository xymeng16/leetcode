#include <chrono>
#include <iostream>
#include <vector>

// Matrix on the Heap
void heapMatrixMultiplication() {
  std::vector<std::vector<int>> A(100, std::vector<int>(100, 1));
  std::vector<std::vector<int>> B(100, std::vector<int>(100, 2));
  std::vector<std::vector<int>> C(100, std::vector<int>(100, 0));
  for (int i = 0; i < 100; ++i)
    for (int j = 0; j < 100; ++j)
      for (int k = 0; k < 100; ++k)
        C[i][j] += A[i][k] * B[k][j];
}

// Matrix on the Stack (NTTP)
template <int N>
void stackMatrixMultiplication() {
  int A[N][N] = {};
  int B[N][N] = {};
  int C[N][N] = {};
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      for (int k = 0; k < N; ++k)
        C[i][j] += A[i][k] * B[k][j];
}

int main() {
  auto start1 = std::chrono::high_resolution_clock::now();
  heapMatrixMultiplication();
  auto end1 = std::chrono::high_resolution_clock::now();

  auto start2 = std::chrono::high_resolution_clock::now();
  stackMatrixMultiplication<100>();
  auto end2 = std::chrono::high_resolution_clock::now();

  std::cout << "Heap Matrix Time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end1 -
                                                                     start1)
                   .count()
            << " µs\n";
  std::cout << "Stack Matrix Time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end2 -
                                                                     start2)
                   .count()
            << " µs\n";
}