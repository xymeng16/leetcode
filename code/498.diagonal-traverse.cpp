#include <bits/stdc++.h>
using namespace std;
// start_marker
enum Direction { RightUp, LeftDown, Right, Down };
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    if (m == 1) {
      return mat[0];
    }
    vector<int> ans;
    if (n == 1) {
      for (const auto &v : mat) {
        ans.push_back(v[0]);
      }
      return ans;
    }
    int c = 0, total = m * n, i = 0, j = 0;
    int nextDir = RightUp;
    while (c < total) {
      ans.push_back(mat[i][j]);
      switch (nextDir) {
      case RightUp: {
        if (i == 0) {
          j++;
          nextDir = LeftDown;
        }
      }
      }
    }
    return ans;
  }
};
// end_marker
int main() { Solution solution; }
