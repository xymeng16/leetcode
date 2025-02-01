#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  bool isValid(string s) {
    if (s.size() == 1) {
      return false;
    }
    std::stack<char> st;
    // std::unordered_set<char> leftSet({'(', '{', '['});
    std::unordered_map<char, char> lrMap({{'(', ')'}, {'{', '}'}, {'[', ']'}});
    for (const auto &c : s) {
      if (lrMap.count(c)) {
        std::cout << "left " << c << std::endl;
        st.push(c);
      } else {
        if (st.empty()) {
          return false;
        }
        auto t = st.top();
        if (lrMap[t] != c) {
          return false;
        }
        st.pop();
      }
    }

    return st.empty();
  }
};
// end_marker
int main() {
  Solution solution;
  std::cout << solution.isValid("){") << std::endl;
  return 0;
}
