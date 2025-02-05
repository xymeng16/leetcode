#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    const int &N = nums.size();
    for (int i = 0; i < N; i++) {
      while (nums[i] > 0 && nums[i] <= N && nums[nums[i] - 1] != nums[i]) {
        std::swap(nums[i], nums[nums[i] - 1]);
      }
    };
    int c = 0;
    return std::find_if(nums.begin(), nums.end(),
                        [&c](const int x) { return x != ++c; }) -
           nums.begin() + 1;
  }
};
// end_marker
int main() {
  Solution solution;
  vector<int> nums = {3, 4, -1, 1};
  std::cout << solution.firstMissingPositive(nums) << std::endl;
  return 0;
}
