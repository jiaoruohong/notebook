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
  vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > res;
    int sz = nums.size();
    int i, j, k;
    int r;
    if (sz < 3) return res;
    sort(nums.begin(), nums.end());

    for (i = 0; i < sz; i++) {
      if (nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      j = i + 1;
      k = sz - 1;
      while (j < k) {
        int tmp = nums[i] + nums[j] + nums[k];
        if (tmp < 0) {
          j++;
        } else if (tmp > 0) {
          k--;
        } else {
          res.push_back({nums[i], nums[j], nums[k]});
          j++;
          k--;
          while (j < k && nums[j] == nums[j - 1]) j++;
          while (j < k && nums[k] == nums[k + 1]) k--;
        }
      }
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
      a.clear();
    }
  }
  void solve(vector<int>& x) {
    vector<vector<int> > res;
    res = threeSum(x);
    otput(res);
  }
  void otput(vector<vector<int> > x) {
    for (int i = 0; i < x.size(); i++)
      printf("%d %d %d\n", x[i][0], x[i][1], x[i][2]);
    puts("");
  }

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
