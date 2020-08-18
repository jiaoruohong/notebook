#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
      for (int j = i + 1; j < nums.size(); j++)
        if (nums[i] + nums[j] == target) {
          // u = i;
          // v = j;
          ans.push_back(i);
          ans.push_back(j);
          break;
        }
    return ans;
  }
  void input(void) {
    while (~scanf("%d %d", &n, &m))
      for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        numbers.push_back(t);
      }
  }
  void solve(void) { twoSum(numbers, m); }
  void otput(void) { printf("%d %d\n", u, v); }

 private:
  int n, m, t;
  int u, v;
  vector<int> numbers;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();
  sol.solve();
  sol.otput();

  return 0;
}
