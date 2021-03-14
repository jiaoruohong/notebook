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
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int res = x;
    int num = 0;
    int r = INT_MAX / 10;
    while (x) {
      if (num > r) {
        return false;
      } else if (num == r && (x % 10) > 7) {
        return false;
      }
      num = num * 10 + x % 10;
      x /= 10;
    }

    return res == num;
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
    bool res;
    res = isPalindrome(x);
    otput(res);
  }

  void otput(bool x) { cout << x << endl; }

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
