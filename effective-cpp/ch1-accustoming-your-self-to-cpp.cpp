#include <ch1.h>
/* Item 1: View C++ aa a federation of languages (C, OO C++, Template C++, The
 * STL) */

// pass-by-value is generally more efficient than pass-by-reference for built-in
// (C-like) types
void pass_by_value_int(int x) noexcept {}
void pass_by_ref_int(int &x) noexcept {}

static void BM_pass_by_value_int(benchmark::State &state) {
  int x = 42;
  for (auto _ : state) {
    pass_by_value_int(x);
  }
}
BENCHMARK(BM_pass_by_value_int);

static void BM_pass_by_ref_int(benchmark::State &state) {
  int x = 42;
  for (auto _ : state) {
    pass_by_ref_int(x);
  }
}
BENCHMARK(BM_pass_by_ref_int);

void pass_by_value_string(std::string x) noexcept {}
void pass_by_ref_string(std::string &x) noexcept {}

static void BM_pass_by_value_string(benchmark::State &state) {
  std::string x = "hello";
  for (auto _ : state) {
    pass_by_value_string(x);
  }
}
BENCHMARK(BM_pass_by_value_string);

static void BM_pass_by_ref_string(benchmark::State &state) {
  std::string x = "hello";
  for (auto _ : state) {
    pass_by_ref_string(x);
  }
}
BENCHMARK(BM_pass_by_ref_string);

void pass_by_value_vector(std::vector<int> x) noexcept {}
void pass_by_ref_vector(std::vector<int> &x) noexcept {}

static void BM_pass_by_value_vector(benchmark::State &state) {
  std::vector<int> x = {1, 2, 3, 4, 5};
  for (auto _ : state) {
    pass_by_value_vector(x);
  }
}
BENCHMARK(BM_pass_by_value_vector);

static void BM_pass_by_ref_vector(benchmark::State &state) {
  std::vector<int> x = {1, 2, 3, 4, 5};
  for (auto _ : state) {
    pass_by_ref_vector(x);
  }
}
BENCHMARK(BM_pass_by_ref_vector);

/* Item 2: Prefer consts, enums, and inlines to #defines (prefer the compiler to
 * preprocessor) */
#define ASPECT_RATIO                                                           \
  1.653 // BAD, never into symbol table, no debugging, no type checking, error
// message refer to 1.653
const double AspectRatio = 1.653; // GOOD, initialized at runtime, cannot be
                                  // used as constant expression
constexpr double AspectRatioConstExpr =
    1.653; // BETTER, initialized at compile time, can be used as constant
           // expression, since C++11
constexpr int factorial(const int n) {
  return n <= 1 ? 1 : n * factorial(n - 1);
} // C++11, recursive constexpr function
constexpr int factorial_cxx14(int n) {
  int res = 1;
  while (n > 1)
    res *= n--;
  return res;
} // C++14, iterative constexpr function
consteval int sqr(int n) { return n * n; } // C++20, consteval function
constexpr int x = sqr(5);                  // OK
// consteval int y = sqr(5); // ERROR, consteval can only be used in functions
consteval int sqrsqr(int n) { return sqr(sqr(n)); } // OK
// constexpr int dblsqr(int n) {
//   return 2 * sqr(n);
// } // ERROR, not a consteval function and returns a non-constant
const char *const author_name = "Xiangyi Meng";     // GOOD, const pointer to
                                                    // constant data
const std::string author_name_std = "Xiangyi Meng"; // BETTER, const std::string
                                                    // object

const int GamePlayer::NumTurns; // without this definition, the linker will
                                // complain about undefined reference
void game_player_func() { std::cout << GamePlayer::getNumTurns() << std::endl; }

#define CALL_WITH_MAX(a, b) factorial((a) > (b) ? (a) : (b))
int a = 5, b = 0;
int c = CALL_WITH_MAX(++a, b);      // BAD, a is incremented twice
int d = CALL_WITH_MAX(++a, b + 10); // GOOD, a is incremented once, OK
template <typename T>
inline void call_with_max(const T &a, const T &b) {
  factorial(a > b ? a : b);
} // BETTER

// For simple constants, prefer const objects or enums to #defines
// For function-like macros, prefer inline functions to #defines

/* Item 3: Use const whenever possible */
char greeting[] = "Hello";
char *p = greeting; // non-const pointer, non-const data
const char *p1 =
    greeting; // non-const pointer, const data (const char's pointer)
char const *p11 = greeting; // as long as const is on the left of *, it's a
                            // pointer to const data
char *const p2 =
    greeting; // const pointer, non-const data (char's const pointer)

// const member functions (see the header)
TextBlock tb("hello");
const TextBlock ctb("hello");

void text_block_func() {
  std::cout << tb[0] << std::endl;  // OK
  tb[0] = 'x';                      // OK
  std::cout << ctb[0] << std::endl; // OK
  // ctb[0] = 'x';                     // ERROR, ctb is const
}

/* Item 4: Make sure that objects are initialized before they're used */
int x1 = 0; // initialized
// int y1;     // BAD, uninitialized
class Point {
  int x, y;
};
Point pt; // BAD, uninitialized
// always initialize your objects!
// use member initialization list to initialize member variables in constructors
class Point2 {
  std::string info;
  int x, y;
  const int
      z; // must be initialized in member initialization list or in declaration

public:
  Point2() : info(), x(0), y(0), z(0) {};
  Point2(const std::string &info, int x, int y, int z)
      : info(info), x(x), y(y), z(z) {
  } // avoid initialize info and assign it again
};

// singletons
class FileSystem {
public:
  std::size_t num_disks() const { return _num_disks; }

private:
  std::size_t _num_disks;
};
FileSystem &tfs() {
  static FileSystem fs;
  return fs;
}

class Directory {
public:
  Directory() {
    std::size_t nd =
        tfs().num_disks(); // ensure that tfs is initialized before Directory
    // do something with nd
  }
};

BENCHMARK_MAIN();