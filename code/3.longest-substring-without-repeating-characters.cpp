#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    const int n = s.size();
    if (n == 0 || n == 1) {
      return n;
    }
    int start = 0, index = 0, ans = 0;
    unordered_set<char> nodup;
    while (start + index < n) {
      auto p = nodup.insert(s[start + index]);
      if (p.second == false) {
        // inserted is false -> duplicated
        ans = std::max(ans, static_cast<int>(nodup.size()));
        nodup.clear();
        // start += 1;
        while (nodup.count(s[++start]))
          ;
        index = 0;
      } else {
        index++;
      }
    }

    return std::max(ans, static_cast<int>(nodup.size()));
  }
};
// end_marker
int main() {
  Solution solution;
  string s("dvdf");
  std::cout << solution.lengthOfLongestSubstring(s) << std::endl;
  return 0;
}
