#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3) {
      return {};
    }
    vector<vector<int>> ans = {};
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {
      if (nums[i] > 0) {
        break;
      }
      int l = i + 1;
      int r = nums.size() - 1;
      
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int target = -nums[i];
      while (l < r) {
        if (nums[l] + nums[r] == target) {
          ans.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1]) {
            l++;
          }
          while (l < r && nums[r] == nums[r - 1]) {
            r--;
          }
          l++; r--;
        } else if (nums[i] + nums[l] + nums[r] < 0) {
          // l too small 
          l++;
        } else {
          r--;
        }
      }
    }
    return ans;
  }
};
// end_marker
int main() {
  Solution solution;
  vector<int> nums = {1, -1, -1, 0};
  auto ans = solution.threeSum(nums);
  for (const auto &v : ans) {
    std::cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
  }
}
