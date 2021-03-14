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
  int addDigits(int num) {
    if (num < 10) {
      return num;
    } else {
      int res = num % 9;
      if (res == 0) {
        res = 9;
      }
      return res;
    }
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
    res = addDigits(x);
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
