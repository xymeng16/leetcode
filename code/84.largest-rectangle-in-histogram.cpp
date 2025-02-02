#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    const int &n = heights.size();
    std::stack<int> mono_st;
    vector<int> left(n), right(n, n);
    int ans = 0;

    for (int i = 0; i < n; i++) {
      while (!mono_st.empty() && heights[mono_st.top()] >= heights[i]) {
        // popping confirms the right boundary
        right[mono_st.top()] = i;
        mono_st.pop();
      }
      left[i] = mono_st.empty() ? -1 : mono_st.top();
      mono_st.push(i);
    }

    for (int i = 0; i < n; i++) {
      ans = std::max(ans, heights[i] * (right[i] - left[i] - 1));
    }

    return ans;
  }
};
// end_marker
int main() {
  Solution solution;
  vector<int> heights({2, 1, 5, 6, 2, 3});
  std::cout << solution.largestRectangleArea(heights) << std::endl;
  return 0;
}
