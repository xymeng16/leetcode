#include <bits/stdc++.h>
using namespace std;
// start_marker
enum Direction { Up, Down, Left, Right };

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    if (n == 1) {
      return {{1}};
    }
    vector ans(n, vector<int>(n, 0));
    int c = 0, total = n * n;
    int i = 0, j = 0;
    int nextDir = Right;
    while (c < total) {
      ans[i][j] = ++c;
      if (c == total) {
        break;
      }
      switch (nextDir) {
      case Up: {
        i--;
        if (i == 0 || !ans[i - 1][j]) {
          nextDir = Right;
        }
        break;
      }
      case Down: {
        i++;
        if (i == n - 1 || !ans[i + 1][j]) {
          nextDir = Left;
        }
        break;
      }
      case Left: {
        j--;
        if (j == 0 || !ans[i][j - 1]) {
          nextDir = Up;
        }
        break;
      }
      case Right: {
        j++;
        if (j == n - 1 || !ans[i][j + 1]) {
          nextDir = Down;
        }
        break;
      }
      default:
        break;
      }
    }

    return ans;
  }
};
// end_marker
int main() { Solution solution; }
