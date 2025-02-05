#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    const int &n = nums.size();
    vector<int> ans(n, 1);
    int prefix = 1, suffix = 1; // prefix starts at 0, suffix starts at n - 1

    for (int i = 0; i < n - 1; i++) {
      prefix *= nums[i];
      ans[i + 1] = prefix;
    } // 0 ... n - 2

    for (int i = n - 1; i > 0; i--) {
      suffix *= nums[i];
      ans[i - 1] *= suffix;
    } // 1 ... n - 1

    // int prefix[n];
    // int suffix[n];
    // prefix[0] = 1;
    // suffix[n - 1] = 1;
    //
    // for (int i = 0; i < n - 1; i++) {
    //   prefix[i + 1] = nums[i] * prefix[i];
    //   suffix[n - i - 2] = nums[n - 1 - i] * suffix[n - 1 - i];
    // }
    //
    // for (int i = 0; i < n; i++) {
    //   std::cout << "prefix[" << i << "] = " << prefix[i] << ", suffix[" << i
    //             << "] = " << suffix[i] << std::endl;
    //   ans.push_back(prefix[i] * suffix[i]);
    // }

    return ans;
  }
};
// end_marker
int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3, 4};
  const auto &ans = solution.productExceptSelf(nums);
  for (const auto &v : ans) {
    std::cout << v << ' ';
  }
  std::cout << std::endl;
}
