#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int left = 0, right = 0;
    int n = nums.size();

    while (right < n) {
      if (nums[right] != 0) {
        std::swap(nums[right], nums[left]);
        left++;
      }
      right++;
    }
  }
};
// end_marker
int main() { Solution solution; }
