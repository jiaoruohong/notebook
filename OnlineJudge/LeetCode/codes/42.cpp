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
  int trap(vector<int>& height) {
    int res = 0;
    int sz = height.size();
    if (sz == 0) return 0;

    vector<int> lmx(sz, 0), rmx(sz, 0);

    for (int i = 1, j = sz - 2; i < sz; i++, j--) {
      lmx[i] = max(lmx[i - 1], height[i - 1]);
      rmx[j] = max(rmx[j + 1], height[j + 1]);
    }
    for (int i = 1; i < sz - 1; i++)
      res += max(0, min(lmx[i], rmx[i]) - height[i]);
    return res;
  }

  void input(void) {
    while (~scanf("%d", &n)) {
      int t;
      for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        a.push_back(t);
      }
      solve(a);
      a.clear();
    }
  }
  void solve(vector<int>& x) {
    int res;
    res = trap(x);
    otput(res);
  }
  void otput(int x) { printf("%d\n", x); }

 private:
  int n;
  vector<int> a;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
