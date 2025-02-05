#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    if (k == 0)
      return;
    k %= nums.size();
    // std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend()); // ...
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin(), nums.end());
  }
};
// end_marker
int main() { Solution solution; }
