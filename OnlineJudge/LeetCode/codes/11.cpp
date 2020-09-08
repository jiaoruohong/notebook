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
  int maxArea(vector<int>& height) {
    int res = 0;
    int sz = height.size();
    int l = 0, r = sz - 1;
    while (l < r) {
      res = max(res, min(height[l], height[r]) * (r - l));
      if (height[l] < height[r])
        l++;
      else
        r--;
    }

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
    }
  }
  void solve(vector<int>& x) {
    int res;
    res = maxArea(x);
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
