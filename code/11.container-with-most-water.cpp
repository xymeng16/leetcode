#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  int maxArea(vector<int> &height) {
    int l = 0, r = height.size() - 1;
    int max_area = std::min(height[l], height[r]) * (r - l);

    while (l < r) {
      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }

      max_area = std::max(max_area, std::min(height[l], height[r]) * (r - l));
    }

    return max_area;
  }
};
// end_marker
int main() { Solution solution; }
