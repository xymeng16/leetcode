#include <bits/stdc++.h>
using namespace std;
// start_marker
class MinStack {
private:
  std::list<int> _list;
  std::list<int> _min;

public:
  MinStack() {}

  void push(int val) {
    if (this->_list.empty()) {
      this->_min.push_front(val);
    } else {
      const int &last_min = this->_min.front();
      this->_min.push_front(std::min(last_min, val));
    }
    this->_list.push_front(val);
  }

  void pop() {
    this->_list.pop_front();
    this->_min.pop_front();
  }

  int top() { return this->_list.front(); }

  int getMin() { return this->_min.front(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// end_marker
int main() { MinStack stack; }
