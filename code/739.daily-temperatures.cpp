#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    auto const &temps = temperatures;
    auto const &n = temps.size();
    if (n == 1) {
      return {0};
    }
    if (n == 2) {
      return {temps[0] < temps[1], 0};
    }

    std::vector<int> days(n);
    std::stack<std::pair<const int, const int>> decTemps; // index, temp
    int i = 0;
    days[n - 1] = 0;
    bool dec = false;
    while (i < n) {
      if (i != n - 1) {
        if (temps[i + 1] > temps[i]) {
          days[i] = 1;
          dec = false;
        } else {
          days[i] = 0; // default
          dec = true;
        }
      }
      while (!decTemps.empty()) {
        auto &top = decTemps.top();
        std::cout << "top.first: " << top.first
                  << ", top.second: " << top.second << ", i: " << i
                  << ", temps[i]: " << temps[i] << std::endl;
        if (temps[i] > top.second) {
          days[top.first] += i - top.first;
          decTemps.pop(); // top is finalized
        } else {
          break;
        }
      }
      if (dec) {
        decTemps.emplace(i, temps[i]);
        dec = false;
      }
      i++;
    }
    return days;
  }
};
// end_marker
int main() {
  Solution solution;
  vector<int> temps({77, 77, 77, 77, 77, 41, 77, 41, 41, 77});
  auto days = solution.dailyTemperatures(temps);
  for (const auto &d : days) {
    std::cout << d << ',';
  }
  std::cout << std::endl;
}
