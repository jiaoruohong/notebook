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
  int reverse(int x) {
    int res = 0;
    int l = INT_MIN / 10;
    int r = INT_MAX / 10;
    while (x / 10) {
      res = res * 10 + x % 10;
      x /= 10;
    }

    if (res < l || res > r) {
      res = 0;
    } else if (res == l && x < -7) {
      res = 0;
    } else if (res == r && x > 8) {
      res = 0;
    } else {
      res = res * 10 + x;
    }

    return res;
  }
  void input(void) {
    while (~scanf("%d", &n)) {
      for (int i = 0; i < n; i++) {
        cin >> a;
        solve(a);
      }
    }
  }

  void solve(int x) {
    int res;
    res = reverse(x);
    otput(res);
  }

  void otput(int x) { cout << x << endl; }

 private:
  int n;
  int a;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
