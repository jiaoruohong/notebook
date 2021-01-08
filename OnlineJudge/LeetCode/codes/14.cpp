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
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) {
      return "";
    }
    string str = strs[0];
    for (int i = 1; i < strs.size(); i++) {
      while (strs[i].find(str) != 0) {
        str = str.substr(0, str.length() - 1);
      }
      if (str.size() == 0) {
        break;
      }
    }
    return str;
  }
  // string longestCommonPrefix(vector<string>& strs) {
  //   string res = "";
  //   int sz = strs.size();

  //   if (sz != 0) {
  //     sort(strs.begin(), strs.end());
  //     int cnt = strs.front().length();
  //     if (cnt != 0) {
  //       if (sz == 1) {
  //         res = strs.front();
  //       } else {
  //         for (int j = 0; j < cnt; j++) {
  //           int i = sz - 1;
  //           if (strs[i][j] != strs.front()[j]) {
  //             return res;
  //           }
  //           res += strs.front()[j];
  //         }
  //       }
  //     }
  //   }
  //   return res;
  // }
  void input(void) {
    while (~scanf("%d", &n)) {
      a.clear();
      string str;
      for (int i = 0; i < n; i++) {
        cin >> str;
        a.push_back(str);
      }

      solve(a);
    }
  }

  void solve(vector<string>& x) {
    string res;
    res = longestCommonPrefix(x);
    otput(res);
  }
  void otput(string x) { cout << x << endl; }

 private:
  int n;
  vector<string> a;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
