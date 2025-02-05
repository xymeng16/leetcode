#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    const int n = intervals.size();
    if (n == 1) {
      return intervals;
    }
    std::sort(intervals.begin(), intervals.end(),
              [](const vector<int> &a, const vector<int> &b) {
                if (a[0] < b[0]) {
                  return true;
                }
                if (a[0] == b[0]) {
                  return a[1] < b[1];
                }
                return false;
              });
    std::cout << std::endl;
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for (int i = 1; i < n; i++) {
      auto &t = ans.back();
      if (t[1] < intervals[i][0]) {
        ans.push_back(intervals[i]);
      } else {
        t[1] = std::max(t[1], intervals[i][1]);
      }
    }
    return ans;
  }
};
// end_marker
int main() {
  Solution solution;
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  const auto &ans = solution.merge(intervals);
  std::cout << '[';
  for (const auto &p : ans) {
    std::cout << '[' << p[0] << ',' << p[1] << "],";
  }
  std::cout << ']' << std::endl;
  return 0;
}
