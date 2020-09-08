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
  string convert(string s, int numRows) {
    if (s.length() <= 1) return s;
    if (numRows == 1) return s;
    string res = "";
    vector<int> v;
    int addItem = 2 * (numRows - 1);
    int sz = s.length();
    int item = 0;
    int len;
    int l, r;
    while (item < sz) {
      v.push_back(item);
      res += s[item];
      item += addItem;
    }
    v.push_back(item);
    for (len = 1; len < numRows - 1; len++) {
      for (int i = 0; i < v.size(); i++) {
        l = v[i] - len;
        r = v[i] + len;
        if (0 <= l && l < sz) {
          res += s[l];
        }
        if (0 <= r && r < sz) {
          res += s[r];
        }
      }
    }
    for (int i = 0; i < v.size(); i++) {
      r = v[i] + numRows - 1;
      if (r < sz) {
        res += s[r];
      }
    }
    return res;
  }
  void input(void) {
    while (~scanf("%d", &n)) {
      cin >> a;

      solve(a, n);
    }
  }

  void solve(string x, int y) {
    string res;
    res = convert(x, y);
    otput(res);
  }
  void otput(string x) { cout << x << endl; }

 private:
  int n;
  string a;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
