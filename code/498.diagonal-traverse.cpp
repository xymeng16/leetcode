#include <bits/stdc++.h>
using namespace std;
// start_marker
enum Direction { RightUp, LeftDown };
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
    ans.push_back(mat[0][0]);
    int c = 1, total = m * n, i = 0, j = 1;
    int nextDir = LeftDown;
    while (c < total) {
      // cout << i << ' ' << j << endl;
      ans.push_back(mat[i][j]);
      c++;
      if (c == total) {
        break;
      }
      switch (nextDir) {
      case RightUp: {
        i--;
        j++;
        if (j == n - 1) {
          ans.push_back(mat[i][j]);
          i++;
          c++;
          nextDir = LeftDown;
        } else if (i == 0) {
          ans.push_back(mat[i][j]);
          j++;
          c++;
          nextDir = LeftDown;
        }
        break;
      }
      case LeftDown: {
        i++;
        j--;
        if (i == m - 1) {
          ans.push_back(mat[i][j]);
          j++;
          c++;
          nextDir = RightUp;
        } else if (j == 0) {
          ans.push_back(mat[i][j]);
          i++;
          c++;
          nextDir = RightUp;
        }
        break;
      }
      }
    }
    return ans;
  }
};
// end_marker
int main() {
  Solution solution;
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  solution.findDiagonalOrder(mat);
}
