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
  int firstUniqChar(string s) {
    int ans = -1;
    int u, v;
    for (char ch = 'a'; ch <= 'z'; ch++) {
      u = s.find(ch);
      v = s.rfind(ch);
      if (u == v && u != -1) {
        if (ans == -1) {
          ans = u;
        } else {
          if (u < ans) ans = u;
        }
      }
    }
    return ans;
  }
  void input(void) {
    while (cin >> str) {
      solve(str);
    }
  }
  void solve(string s) {
    int res;
    res = firstUniqChar(s);
    otput(res);
  }
  void otput(int id) { printf("%d\n", id); }

 private:
  int n, m, t;
  string str;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
