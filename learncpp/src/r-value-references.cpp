#include <cstddef>
#include <iostream>
#include <memory>
#include <print>

/*
 * Value caterogies:
 * - lvalue: the name of var, a function, a template parameter object, or a data
 * member, regardless of type. Even if the variable's type is rvalue reference,
 * the expression consisting of its name is a lvalue expression.
 * - prvalue: pure rvalue, an expression whose evaluation:
 *   - computes the value of an operand of a built-in operator, or
 *   - initializes an object
 * - xvalue: eXpiring value, a glvalue that denotes an object whose resourses
 * can be reused
 * - glvalue: an expression whose evaluation determines the identity of an
 * object or function
 *
 * An lvalue is a glvalue that is not an xvalue?
 */

template <int &v>
void set() {
  v = 5;
}

int a{3}; // static, fixed address known at compile-time

struct A {
  A(int &&n) { std::cout << "rvalue overloaded, n = " << n << std::endl; }
  A(int &n) { std::cout << "lvalue overloaded, n = " << n << std::endl; }
};

class B {
public:
  template <class T1, class T2, class T3>
  B(T1 &&t1, T2 &&t2, T3 &&t3)
      : a1_{std::forward<T1>(t1)}, a2_{std::forward<T2>(t2)},
        a3_{std::forward<T3>(t3)} {}

private:
  A a1_, a2_, a3_;
};

template <class T, class U>
std::unique_ptr<T> make_unique1(U &&u) {
  return std::unique_ptr<T>(new T(std::forward<U>(u)));
}

template <class T, class... U>
std::unique_ptr<T> make_unique2(U &&...u) {
  return std::unique_ptr<T>(new T(std::forward<U>(u)...));
}

auto make_B(auto &&...args) { return B(std::forward<decltype(args)>(args)...); }

int main() {
  // set<a>();
  // int b{4};
  // set<b>(); // ERROR, b's address cannot be determined at compile-time
  //
  // auto p1 = make_unique1<A>(2); // rvalue
  // int i = 1;
  // int &&rli = 1;
  // auto p2 = make_unique1<A>(std::forward<int &>(1)); // lvalue
  //
  // std::cout << "B\n";
  // auto t = make_unique2<B>(2, rli, 3);
  //
  // std::cout << "make_B\n";
  // [[maybe_unused]] B b = make_B(4, rli, 5);

  int xxx = 1;
  int &x = xxx;
  auto xx = x;
  // int &xx = std::forward<int &>(x);
  std::print("{} {}\n", x, xx);
  x -= 1;
  std::print("{} {}\n", x, xx);

  return 0;
}