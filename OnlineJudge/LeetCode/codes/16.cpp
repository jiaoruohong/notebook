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
  int threeSumClosest(vector<int>& nums, int target) {
    int res = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
      if (i != 0 && nums[i - 1] == nums[i]) {
        continue;
      }
      int j = i + 1, k = sz - 1;
      while (j < k) {
        int t = nums[i] + nums[j] + nums[k];
        if (t < target) {
          if (abs(target - t) < abs(target - res)) res = t;
          j++;
          while (j < k && nums[j - 1] == nums[j]) j++;
        } else if (t > target) {
          if (abs(target - t) < abs(target - res)) res = t;
          k--;
          while (j < k && nums[k] == nums[k + 1]) k--;
        } else {
          return target;
        }
      }
    }
    return res;
  }

  void input(void) {
    while (~scanf("%d %d", &n, &m)) {
      int t;
      for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        a.push_back(t);
      }
      solve(a, m);
      a.clear();
    }
  }
  void solve(vector<int>& x, int y) {
    int res;
    res = threeSumClosest(x, y);
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
