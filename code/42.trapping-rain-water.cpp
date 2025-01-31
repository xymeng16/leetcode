/*
*Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
are being trapped.
*/
#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  int trap(vector<int> &height) {
    // vol[i] = height[i] - min(left_max[i], right_max[i])
    int vol = 0;
    int n = height.size();
    vector<int> left_max(n), right_max(n);
    left_max[0] = height[0];
    right_max[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++) {
      left_max[i] = std::max(left_max[i - 1], height[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
      right_max[i] = std::max(right_max[i + 1], height[i]);
    }
    for (int i = 0; i < n; i++) {
      vol += std::min(left_max[i], right_max[i]) - height[i];
    }

    return vol;
  }
};
// end_marker
int main() {
  Solution solution;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  std::cout << solution.trap(height) << std::endl;
}
