#include <iostream>

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

int main() {
  set<a>();
  int b{4};
  // set<b>(); // ERROR, b's address cannot be determined at compile-time
  return 0;
}