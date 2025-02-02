#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  string decodeString(string s) {
    const int &l = s.size();
    if (l <= 3) {
      // pure no-digit strings, or like 3[]
      std::cout << "len: " << l << std::endl;
      return s;
    }
    string ans;
    std::stack<pair<int, int>> st; // <index of digit, digit> pairs
    for (int i = 0; i < l; i++) {
      if (std::isdigit(s[i])) {
        int start = i;
        while (std::isdigit(s[i])) {
          i++;
        }

        st.emplace(i - 1, std::atoi(s.substr(start, i - start).data()));
      } else if (s[i] == ']') {
        const auto &p = st.top();
        st.pop();
        int n = 1;
        auto subS = s.substr(p.first + 2, i - p.first - 2);
        std::cout << subS << ", " << p.first << " " << p.second << std::endl;
        auto t = this->decodeString(subS);
        while (n < p.second) {
          ans.append(t);
          n++;
        }
        std::cout << "current ans:" << ans << std::endl;
      } else {
        ans += s[i];
      }
    }
    return ans;
  }
};
// end_marker
int main() {
  Solution solution;
  std::cout << solution.decodeString("10[a]") << std::endl;
}
