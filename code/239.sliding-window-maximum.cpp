#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 1) {
      return nums;
    }
    vector<int> ans(n - k + 1);
    deque<int> deq;

    for (int i = 0; i < k; i++) {
      while (!deq.empty() && nums[i] >= nums[deq.back()]) {
        deq.pop_back();
      }
      deq.push_back(i);
    }
    ans[0] = nums[deq.front()];

    for (int i = k; i < n; i++) {
      while (!deq.empty() && nums[i] >= nums[deq.back()]) {
        deq.pop_back();
      }
      deq.push_back(i);
      while (deq.front() <= i - k) {
        deq.pop_front();
      }
      ans[i - k + 1] = nums[deq.front()];
    }

    return ans;
  }
};
// end_marker
int main() { Solution solution; }
