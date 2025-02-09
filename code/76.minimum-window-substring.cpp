#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  unordered_map<char, int> ori, cnt;
  bool check() {
    for (const auto &[k, v] : ori) {
      if (cnt[k] < v) {
        return false;
      }
    }

    return true;
  }

  string minWindow(string s, string t) {
    int m = s.size(), n = t.size();
    for (const auto &c : t) {
      ori[c]++;
    }

    int l = 0, r = 0;
    int min_len = INT_MAX, ans_l = -1;

    while (r < m) {
      if (ori.find(s[r]) != ori.end()) {
        cnt[s[r]]++;
      }

      while (check() && l <= r) {
        if (r - l + 1 < min_len) {
          min_len = r - l + 1;
          ans_l = l;
        }

        if (ori.find(s[l]) != ori.end()) {
          cnt[s[l]]--;
        }

        l++;
      }
      r++;
    }

    return ans_l == -1 ? "" : s.substr(ans_l, min_len);
  }
};
// end_marker
int main() { Solution solution; }
