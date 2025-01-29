#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); i++) {
      auto it = hashtable.find(target - nums[i]);
      if (it != hashtable.end()) {
        return {it->second, i};
      }
      hashtable[nums[i]] = i; // avoid self-matching
    }

    return {};
  }
};
// end_marker
int main() {
  Solution solution;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> result = solution.twoSum(nums, target);
  cout << result[0] << " " << result[1] << endl;
  return 0;
}
