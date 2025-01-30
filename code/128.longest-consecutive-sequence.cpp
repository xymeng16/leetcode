#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
// start_marker
struct Comp {
  bool operator()(const int &lhs, const int &rhs) const { return (lhs < rhs); }
};

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    std::unordered_set<int> hashset(nums.begin(), nums.end());
    if (hashset.size() == 0 || hashset.size() == 1) {
      return hashset.size();
    }
    int max_consec_len = 1;
    int curr_consec_len = 1;
    for (auto n : nums) {
      if (hashset.count(n - 1) == 0) { // the begin of a consecutive sequence
        while (hashset.count(n++ + 1) == 1) {
          curr_consec_len++;
          max_consec_len = std::max(max_consec_len, curr_consec_len);
        }
        curr_consec_len = 0;
      }
    }
    // std::set<int, Comp> hashset(nums.begin(), nums.end());
    // int consec_len = 1;
    // int max_consec_len = 1;
    // if (hashset.size() == 0 || hashset.size() == 1) {
    //   return hashset.size();
    // }
    // for (auto v = hashset.begin();;) {
    //   auto curr = *v;
    //   auto next = *(++v);
    //   std::cout << curr << ' ' << next;
    //   if (next == (curr + 1)) {
    //     consec_len++;
    //     max_consec_len = max(consec_len, max_consec_len);
    //     std::cout << " conseq_len++ = " << consec_len
    //               << ", max_consec_len = " << max_consec_len;
    //   } else {
    //     consec_len = 1;
    //   }
    //   std::cout << endl;
    //   if (std::next(v) == hashset.end()) {
    //     break;
    //   }
    // }
    return max_consec_len;
  }
};
// end_marker
int main() {
  Solution solution;
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  std::cout << solution.longestConsecutive(nums) << endl;
}
