#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    if (n == 1) {
      return;
    }
    for (auto &l : matrix) {
      reverse(l.begin(), l.end());
    }
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1 - i; j++) {
        swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
      }
    }
  }
};
// end_marker
int main() { Solution solution; }
