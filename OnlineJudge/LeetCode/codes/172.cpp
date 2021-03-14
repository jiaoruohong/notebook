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
  int trailingZeroes(int n) {
    int res = 0;
    while (n) {
      res += n / 5;
      n /= 5;
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
    res = trailingZeroes(x);
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
