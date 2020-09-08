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
  int minSubArrayLen(int s, vector<int>& nums) {
    int res = nums.size();
    int sz = res;
    int sum = 0;
    int u = 0, v = 0;
    bool occur = false;

    for (v = 0; v < sz; v++) {
      sum += nums[v];
      while (sum >= s && u <= v) {
        occur = true;
        res = min(res, v - u + 1);
        sum -= nums[u];
        u++;
      }
    }
    if (occur == false) return 0;

    return res;
  }

  void input(void) {
    while (~scanf("%d %d", &n, &m)) {
      int t;
      for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        a.push_back(t);
      }
      solve(m, a);
      a.clear();
    }
  }
  void solve(int s, vector<int>& x) {
    int res;
    res = minSubArrayLen(s, x);
    otput(res);
  }
  void otput(int x) { printf("%d\n", x); }

 private:
  int n, m;
  vector<int> a;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
