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
  int lengthOfLongestSubstring(string s) {
    int res = 0;
    int sz = s.length();
    int l = 0, r = 0;
    if (sz == 0) return 0;
    int mp[256];
    memset(mp, -1, 256 * sizeof(int));

    for (int i = 0; i < sz; i++)
      if (mp[s[i]] == -1) {
        r = i;
        mp[s[i]] = i;
      } else {
        if (mp[s[i]] == -2) {
          r = i;
          mp[s[i]] = i;
        } else {
          res = max(res, r - l + 1);
          int newL = mp[s[i]] + 1;
          for (int j = l; j < mp[s[i]] + 1; j++) mp[s[j]] = -2;
          l = newL;
          r = i;
          mp[s[i]] = i;
        }
      }

    res = max(res, r - l + 1);
    return res;
  }
  void input(void) {
    while (cin >> a) {
      solve(a);
    }
  }
  void solve(string x) {
    int res;
    res = lengthOfLongestSubstring(x);
    otput(res);
  }
  void otput(int x) { printf("%d\n", x); }

 private:
  string a;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
