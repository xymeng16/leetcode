#include <cstddef>
#include <iostream>
#include <algorithm>
#include <execution>
#include <vector>
#include <random>
#include <chrono>

int main() {
  // Generate random data
  const size_t size = 10000000;
  std::vector<int> data(size);
  std::mt19937 rng(12345);
  std::uniform_int_distribution<int> dist(0, 1000000);
  for (auto &elem : data) {
    elem = dist(rng);
  }

  // Copy for sequential sort
  std::vector<int> data_copy = data;

  // Benchmark sequential sort
  auto start_seq = std::chrono::high_resolution_clock::now();
  std::sort(data_copy.begin(), data_copy.end());
  auto end_seq = std::chrono::high_resolution_clock::now();
  auto seq_time =
      std::chrono::duration_cast<std::chrono::milliseconds>(end_seq - start_seq)
          .count();

  // Benchmark parallel sort
  auto start_par = std::chrono::high_resolution_clock::now();
  std::sort(std::execution::par, data.begin(), data.end());
  auto end_par = std::chrono::high_resolution_clock::now();
  auto par_time =
      std::chrono::duration_cast<std::chrono::milliseconds>(end_par - start_par)
          .count();

  std::cout << "Sequential sort time: " << seq_time << " ms\n"
            << "Parallel sort time:   " << par_time << " ms";

  return 0;
}
