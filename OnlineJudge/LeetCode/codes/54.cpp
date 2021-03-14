#include <math.h>

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size();
    int n = matrix[0].size();

    int i = 0, j = 0;
    int row = m, col = n;

    int sum;

    int total = m * n;
    while (total) {
      if (row == 1) {
        for (int k = 0; k < col; k++) {
          res.push_back(matrix[i][j + k]);
        }
        sum = col;
      } else if (col == 1) {
        for (int k = 0; k < row; k++) {
          res.push_back(matrix[i + k][j + col - 1]);
        }
        sum = row;
      } else {
        for (int k = 0; k < col - 1; k++) {
          res.push_back(matrix[i][j + k]);
        }
        for (int k = 0; k < row - 1; k++) {
          res.push_back(matrix[i + k][j + col - 1]);
        }
        for (int k = 0; k < col - 1; k++) {
          res.push_back(matrix[i + row - 1][j + col - 1 - k]);
        }
        for (int k = 0; k < row - 1; k++) {
          res.push_back(matrix[i + row - 1 - k][j]);
        }
        sum = 2 * (row + col) - 4;
      }

      total -= sum;

      row -= 2;
      col -= 2;

      i++;
      j++;
    }

    return res;
  }

  void input(void) {
    while (~scanf("%d", &n)) {
      for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        int v;
        vector<vector<int>> data;

        for (int j = 0; j < a; j++) {
          vector<int> item;
          for (int k = 0; k < b; k++) {
            cin >> v;
            // cout << v << endl;
            item.push_back(v);
          }
          data.push_back(item);
        }
        solve(data);
      }
    }
  }

  void solve(vector<vector<int>>& x) {
    vector<int> res;
    res = spiralOrder(x);
    otput(res);
  }

  void otput(vector<int> x) {
    for (int i = 0; i < x.size(); i++) {
      cout << x[i] << endl;
    }
    cout << endl;
  }

 private:
  int n;
  int a;
  int b;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
