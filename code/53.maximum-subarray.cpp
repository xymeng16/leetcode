#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    const int &n = nums.size();
    if (n == 1) {
      return nums[0];
    }

    int dp = nums[0], max = nums[0];
    for (int i = 1; i < n; i++) {
      if (dp > 0) {
        dp = dp + nums[i];
      } else {
        dp = nums[i];
      }
      max = std::max(max, dp);
    }
    return max;
  }
};
// end_marker
int main() {
  Solution solution;
  vector<int> nums({-2, 1, -3, 4, -1, 2, 1, -5, 4});
  std::cout << solution.maxSubArray(nums) << std::endl;
  return 0;
}
