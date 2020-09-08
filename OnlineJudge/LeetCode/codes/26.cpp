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
  int removeDuplicates(vector<int>& nums) {
    int res = 0;
    int sz = nums.size();
    if (sz == 0) return 0;
    int cur = 0;
    for (int i = 0; i < sz; i++)
      if (nums[cur] != nums[i]) {
        cur++;
        nums[cur] = nums[i];
      }
    res = cur + 1;
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
    res = removeDuplicates(x);
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
