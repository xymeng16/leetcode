#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    vector<pair<int, int>> vz;
    int m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          cout << i << ' ' << j << endl;
          vz.emplace(vz.end(), i, j);
        }
      }
    }
    cout << endl;
    for (const auto &[ii, jj] : vz) {
      cout << ii << ' ' << ii << endl;
      for (int i = 0; i < n; i++) {
        matrix[ii][i] = 0;
      }
      for (int i = 0; i < m; i++) {
        matrix[i][jj] = 0;
      }
    }
  }
};
// end_marker
int main() { Solution solution; }
