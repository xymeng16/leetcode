#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    const auto &n = nums.size();
    if (n == 1) {
      return k == nums[0];
    }
    unordered_map<int, int> map;
    map[0] = 1;
    int count = 0, sum = 0;
    for (const auto &x : nums) {
      sum += x;
      if (auto t = map.find(sum - k); t != map.end()) {
        count += t->second;
      }
      map[sum]++;
    }

    return count;
  }
};
// end_marker
int main() {
  Solution solution;
  vector<int> nums({-1, -1, 1});
  std::cout << solution.subarraySum(nums, 0) << std::endl;
  return 0;
}
