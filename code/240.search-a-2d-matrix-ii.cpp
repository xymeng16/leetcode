#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    for (const auto &row : matrix) {
      if (row[0] > target) {
        return false;
      }
      if (*(row.end() - 1) < target) {
        continue;
      }
      if (binary_search(row.begin(), row.end(), target)) {
        return true;
      }
    }

    return false;
  }
};
// end_marker
int main() { Solution solution; }
