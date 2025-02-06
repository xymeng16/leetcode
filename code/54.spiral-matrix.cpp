#include <bits/stdc++.h>
using namespace std;
// start_marker
enum Direction { Up, Down, Left, Right };
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int total = m * n;
    int nextDir;
    if (m == 1) {
      if (n == 1) {
        return {matrix[0][0]};
      } else {
        nextDir = Right;
      }
    } else if (n == 1) {
      nextDir = Down;
    } else {
      nextDir = Right;
    }
    int i = 0, j = 0, c = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<int> ans(total);
    while (c < total) {
      visited[i][j] = true;
      ans[c++] = matrix[i][j];
      if (c == total)
        break;

      switch (nextDir) {
      case Up: {
        i--;
        if (i == 0 || visited[i - 1][j]) {
          nextDir = Right;
        }
        break;
      }
      case Down: {
        i++;
        if (i == m - 1 || visited[i + 1][j]) {
          nextDir = Left;
        }
        break;
      }
      case Left: {
        j--;
        if (j == 0 || visited[i][j - 1]) {
          nextDir = Up;
        }
        break;
      }
      case Right: {
        j++;
        if (j == n - 1 || visited[i][j + 1]) {
          nextDir = Down;
        }
        break;
      }
      default:
        break;
      }
    }
    return ans;
  };
  // end_marker
  int main() { Solution solution; }
