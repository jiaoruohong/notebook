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
  int cal(int x) {
    int res = 0;
    int t;
    while (x != 0) {
      t = x % 10;
      x /= 10;
      res += t * t;
    }
    return res;
  }
  bool isHappy(int n) {
    if (n == 1) return true;
    int slow = n, fast = cal(n);
    while (slow != fast) {
      if (slow == 1 || fast == 1) return true;
      slow = cal(slow);
      fast = cal(cal(fast));
    }
    return false;
  }

  void input(void) {
    while (~scanf("%d", &n)) {
      solve(n);
    }
  }

  void solve(int x) {
    bool res;
    res = isHappy(x);
    otput(res);
  }
  void otput(int x) { printf("%d\n", x); }

 private:
  int n, m;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
