#include <cstddef>
#include <iostream>
#include <format>
#include <print>
#include <type_traits>

template <long long N>
struct Factorial {
  static const long long value = Factorial<N - 1>::value * N;
};

template <>
struct Factorial<0> {
  static const long long value = 1;
};

void print(auto *x) { std::print("{}\n", *x); }
void print(auto x) { std::print("{}\n", x); }

template <typename T1, typename T2>
auto max(T1 a, T2 b) -> std::decay_t<decltype(true ? a : b)> {
  return a > b ? a : b;
}

template <typename T1, typename T2>
std::common_type_t<T1, T2> max2(T1 a, T2 b) {
  return a > b ? a : b;
}

int main() {
  // std::cout << Factorial<20>::value << std::endl;
  int &&x = 42;
  auto xx = x; // auto always decays
  print(std::forward<int>(x));
  print(&x);
  print(max2(1, x));
  return 0;
}