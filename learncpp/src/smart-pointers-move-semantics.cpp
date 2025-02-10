#include <iostream>

template <typename T>
class Auto_ptr1 {
  T *m_ptr{};

public:
  Auto_ptr1(T *ptr = nullptr) : m_ptr(ptr) {}

  ~Auto_ptr1() { delete m_ptr; }

  T *operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
};

class Resource {
public:
  Resource() { std::cout << "Resource Acquired\n"; }
  ~Resource() { std::cout << "Resource Destroyed\n"; }
  void sayHi() { std::cout << "Hi\n"; }
};

void someFunction() {
  Auto_ptr1<Resource> ptr(new Resource);
  int x;
  std::cout << "Enter on integer: ";
  std::cin >> x;

  if (x == 0)
    return;

  ptr->sayHi();
}

void passedByValue(Auto_ptr1<Resource> res) {}
Auto_ptr1<Resource> generateResource() {
  Resource *r{new Resource()};
  return Auto_ptr1<Resource>(r);
}

template <typename T>
class Auto_ptr2 { // smart pointer with move semantics
  T *m_ptr{};

public:
  Auto_ptr2(T *ptr = nullptr) : m_ptr(ptr) {}

  ~Auto_ptr2() {
    delete m_ptr;
  } // it's okay to delete nullptr, as it does nothing

  // A copy constructor that implements move semantics
  Auto_ptr2(Auto_ptr2 &a) { // not const
    m_ptr = a.m_ptr;
    a.m_ptr = nullptr;
  }

  // An assignment operator that implements the move semantic
  Auto_ptr2 &operator=(Auto_ptr2 &a) { // not const
    if (&a == this) {
      return *this;
    }

    delete m_ptr; // make sure old destination is freed
    m_ptr = a.m_ptr;
    a.m_ptr = nullptr;
    return *this;
  }

  T &operator*() { return *m_ptr; }
  T *operator->() { return m_ptr; }

  bool isNull() const { return m_ptr == nullptr; }
};

/*
 * Problem of Auto_ptr2:
 * - Move semantics implemented by copy constructor and assignment operator,
 * hence passing by value will cause your resource to get moved ti the function
 * parameter and be destroyed at the end of function (out of scope), causing
 * your original Auto_ptr2 to be nullptr.
 * - Deconstructor always use delete, instead of delete[], won't work with
 * dynamically allocated array
 * - Most STL containers assume to be actually copied when copying them, not
 * move
 *
 * So std::auto_ptr is deprecated in C++11 and removed in C++17.
 *
 * The core problem: C++ prior to C++11 cannot differentiate "copy semantics"
 * from "move semantics". So std::move is introduced in C++11.
 *
 * Also, C++11 introduces a bunch of "move-aware" smart pointers:
 * std::unique_ptr, std::weak_ptr, and std::shared_ptr.
 */

int main() {
  // Auto_ptr1<Resource> res1(new Resource()); // allocate here
  // someFunction();
  // Auto_ptr1<Resource> res2(res1); // copy constructor, point to the same
  // memory
  // passedByValue(res1);
  // Auto_ptr1<Resource> res(generateResource());
  // res->sayHi();

  Auto_ptr2<Resource> res1(new Resource());
  Auto_ptr2<Resource> res2; // nullptr as started

  std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
  std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

  res2 = res1;

  std::cout << "Ownership transferred\n";

  std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
  std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

  return 0;
}