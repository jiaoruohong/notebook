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
  int myAtoi(string s) {
    // 2147483647
    // -2147483648
    int res = 0;
    int l = INT_MIN / 10;
    int r = INT_MAX / 10;
    int sz = s.size();
    int trimmingLeft = 1;
    int tmp = 0;
    int op = 1;
    for (int i = 0; i < sz; i++) {
      if ('0' <= s[i] && s[i] <= '9') {
        trimmingLeft = 0;
        tmp = s[i] - '0';
        if (op > 0) {
          if (res > r) {
            return INT_MAX;
          } else if (res == r && tmp > 7) {
            return INT_MAX;
          } else {
            res = res * 10 + tmp * op;
          }
        } else {
          if (res < l) {
            return INT_MIN;
          } else if (res == l && tmp > 8) {
            return INT_MIN;
          } else {
            res = res * 10 + tmp * op;
          }
        }
      } else if (s[i] == ' ') {
        if (trimmingLeft == 0) {
          break;
        }
      } else if (s[i] == '+') {
        if (trimmingLeft == 0) {
          break;
        }
        trimmingLeft = 0;
        op = 1;
      } else if (s[i] == '-') {
        if (trimmingLeft == 0) {
          break;
        }
        trimmingLeft = 0;
        op = -1;
      } else {
        break;
      }
    }
    return res;
  }

  void input(void) {
    while (~scanf("%d", &n)) {
      getline(cin, a);
      for (int i = 0; i < n; i++) {
        // cin >> a;
        getline(cin, a);
        solve(a);
      }
    }
  }

  void solve(string x) {
    int res;
    res = myAtoi(x);
    otput(res);
  }

  void otput(int x) { cout << x << endl; }

 private:
  int n;
  string a;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
