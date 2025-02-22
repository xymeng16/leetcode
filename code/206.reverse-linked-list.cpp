#include <bits/stdc++.h>
using namespace std;
// start_marker

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode *next = nullptr, *last = head;
    head = head->next;
    while (head) {
      next = head->next;
      head->next = last;
      cout << head->val << ' ';
      last = head;
      head = next;
    }

    cout << "end";

    return last;
  }
};
// end_marker
int main() { Solution solution; }
