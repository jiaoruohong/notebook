#include <math.h>

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
  string multiply(string num1, string num2) {
    string res = "";
    int len1 = num1.size();
    int len2 = num2.size();
    int a[230] = {0};
    int val;

    for (int i = len1 - 1; i >= 0; i--) {
      for (int j = len2 - 1; j >= 0; j--) {
        val = (num1[i] - '0') * (num2[j] - '0');
        int k = (len1 - i - 1) + (len2 - j - 1);
        a[k] += val;
        a[k + 1] += a[k] / 10;
        a[k] %= 10;
      }
    }

    for (int i = len1 + len2; i >= 0; i--) {
      if (res.size() == 0 && a[i] == 0) {
        continue;
      } else {
        res += '0' + a[i];
      }
    }

    if (res.size() == 0) {
      res = "0";
    }
    return res;
  }

  void input(void) {
    while (~scanf("%d", &n)) {
      for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        solve(a, b);
      }
    }
  }

  void solve(string x, string y) {
    string res;
    res = multiply(x, y);
    otput(res);
  }

  void otput(string x) { cout << x << endl; }

 private:
  int n;
  string a;
  string b;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
