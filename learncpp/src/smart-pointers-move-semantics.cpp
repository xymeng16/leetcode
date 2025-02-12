#include <cstddef>
#include <atomic>
#include <functional>
#include <iostream>
#include <memory>
#include <thread>
#include <print>

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
  Resource(const Resource &res) { std::cout << "Copy Resource\n"; }
  Resource(const Resource &&res) { std::cout << "Move Resource\n"; }
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

// struct A {
//   std::shared_ptr<A> ptr;
// };
//
// class AA {
//   std::shared_ptr<AA> ptr;
// };

struct A {
  A(int) {}
  A(int, int) {}
  operator bool() const { return true; }
};

struct B {
  explicit B(int) {}
  explicit B(int, int) {}
  explicit operator bool() const { return true; }
};

template <typename T>
class my_shared_ptr {
private:
  T *ptr;
  std::atomic<int> *ref_count;
  std::function<void(T *)> deleter;

  void release() {
    if (ptr && --(*ref_count) == 0) {
      deleter(ptr);
      delete ref_count;
    }
  }

public:
  my_shared_ptr(T *p = nullptr)
      : ptr(p), ref_count(new std::atomic<int>(p ? 1 : 0)),
        deleter([](T *p) { delete p; }) {}

  ~my_shared_ptr() { release(); }

  // copy constructor
  my_shared_ptr(const my_shared_ptr &msp)
      : ptr(msp.ptr), ref_count(msp.ref_count), deleter(msp.deleter) {
    ++(*ref_count);
  }

  // copy assignment operator
  my_shared_ptr &operator=(const my_shared_ptr &msp) {
    if (this != &msp) {
      release(); // current ptr is released
      ptr = msp.ptr;
      ref_count = msp.ref_count;
      deleter = msp.deleter;
      ++(*ref_count); // may throw exception
    }
    return *this;
  }

  // move constructor
  my_shared_ptr(my_shared_ptr &&msp) noexcept
      : ptr(msp.ptr), ref_count(msp.ref_count),
        deleter(std::move(msp.deleter)) {
    msp.ptr = nullptr;
    msp.ref_count = nullptr;
  }

  // move assignment operator
  my_shared_ptr &operator=(my_shared_ptr &&msp) noexcept {
    if (this != &msp) {
      release();
      ptr = msp.ptr;
      msp.ptr = nullptr;
      ref_count = msp.ref_count;
      msp.ref_count = nullptr;
      deleter = std::move(msp.deleter);
    }
    return *this;
  }

  [[nodiscard]] int use_count() const noexcept { return *ref_count; }
  void reset(
      T *np = nullptr,
      std::function<void(T *)> nd = [](T *p) { delete p; }) noexcept {
    release();
    ptr = np;
    ref_count = np ? new std::atomic<int>(1) : nullptr;
    deleter = nd;
  }

  [[nodiscard]] T *get() const noexcept { return ptr; }

  T &operator*() const { return *ptr; }
  T *operator->() const { return ptr; }
};

std::mutex mtx;
std::atomic<std::shared_ptr<int>> sp = std::make_shared<int>(42);
std::shared_ptr<int> sp2 = std::make_shared<int>(42);
std::weak_ptr<int> wp = sp2;

void threadFunc() {
  std::lock_guard<std::mutex> lg(mtx);
  ++(*(sp.load()));
}
constexpr int N = 1000;
int main() {
  std::vector<std::thread> vt;
  vt.reserve(N);
  for (int i = 0; i < N; ++i) {
    vt.emplace_back(threadFunc);
  }

  for (auto &t : vt) {
    t.join();
  }

  std::cout << *(sp.load()) << std::endl;
  // Auto_ptr1<Resource> res1(new Resource()); // allocate here
  // someFunction();
  // Auto_ptr1<Resource> res2(res1); // copy constructor, point to the
  // same memory passedByValue(res1); Auto_ptr1<Resource>
  // res(generateResource()); res->sayHi();

  // Auto_ptr2<Resource> res1(new Resource());
  // Auto_ptr2<Resource> res2; // nullptr as started
  //
  // std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not
  // null\n"); std::cout << "res2 is " << (res2.isNull() ? "null\n"
  // : "not null\n");
  //
  // res2 = res1;
  //
  // std::cout << "Ownership transferred\n";
  //
  // std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not
  // null\n"); std::cout << "res2 is " << (res2.isNull() ? "null\n"
  // : "not null\n");

  // Resource r;
  // std::unique_ptr<Resource> ptr =
  // std::make_unique<Resource>(std::move(r));
  // // std::unique_ptr<Resource> ptr2 = ptr;
  // std::unique_ptr<Resource> ptr2 =
  // std::forward<std::unique_ptr<Resource>>(ptr);

  // std::shared_ptr<Resource> sp1 =
  // std::make_shared<Resource>(); // rc = 1
  // {
  //   std::shared_ptr<Resource> sp2 = sp1; // rc = 2
  //   std::cout << sp1.use_count() << std::endl;
  // }
  // std::cout << sp1.use_count() << std::endl; // rc = 1

  // std::shared_ptr<A> a1 = std::make_shared<A>();
  // std::shared_ptr<A> a2 = std::make_shared<A>();
  //
  // a1->ptr = a2;
  // a2->ptr = a1; // memory leak, use_count never reaches 0

  // std::cout << a1.use_count() << ' ' << a2.use_count() <<
  // std::endl;

  // std::shared_ptr<Resource> sp =
  // std::make_shared<Resource>(); std::weak_ptr<Resource>
  // wp = sp;
  //
  // std::cout << sp.use_count() << std::endl;
  // std::cout << wp.use_count() << std::endl;
  // if (auto sp2 = wp.lock()) {
  //   std::cout << sp2.use_count() << std::endl;
  //   std::cout << "still alive" << std::endl;
  // }
  // std::cout << sp.use_count() << std::endl;

  // for A
  A a1 = 1;
  A a2(2);
  A a3{4, 5};
  A a4 = {4, 5};
  A a5 = (A)1; // static cast
  if (a1) {
  } // A::operator bool()
  bool na1 = a1;
  bool na2 = static_cast<bool>(a1);

  // for B
  // B b1 = 1; // ERROR: copy-init does not consider B::B(int)
  B b2(2);
  B b22(1, 2);
  B b3{4, 5};
  // B b4 = {4, 5}; // ERROR: copy-list does not consider explicit B::B(int,
  // int)
  B b5 = (B)1; // explicit cast performs static_cast
  if (b2) {
  }
  bool nb1 = static_cast<bool>(b2); // works
  // bool nb11 = b2; // ERROR: cannot use l/rvalue of B to directly initialize

  // std::unique_ptr<A> p = new A(1); // ERROR: explicit
  std::unique_ptr<A> p(new A(1));

  auto ptr = std::make_unique<A>(1); // good practice, noexcept
  std::unique_ptr<A> ptr2(
      new A(1)); // bad practice, resource leak in case of exception

  int a[10][10];
  std::cout << a[0] << ' ' << &a[0][0] << std::endl;

  return 0;
}