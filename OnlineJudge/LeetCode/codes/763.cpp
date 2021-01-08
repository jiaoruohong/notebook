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
  vector<int> partitionLabels(string S) {
    vector<int> res;
    int u[26] = {0};

    int sz = S.size();
    for (int i = 0; i < sz; i++) {
      u[S[i] - 'a'] = i;
    }

    int l = 0, r = u[S[0] - 'a'];
    for (int i = 0; i < sz; i++) {
      r = max(r, u[S[i] - 'a']);
      if (r == i) {
        res.push_back(r - l + 1);
        l = i + 1;
      }
    }
    return res;
  }

  void input(void) {
    while (~scanf("%d", &n)) {
      for (int i = 0; i < n; i++) {
        cin >> a;
        solve(a);
      }
    }
  }

  void solve(string x) {
    vector<int> res;
    res = partitionLabels(x);
    otput(res);
  }
  void otput(vector<int> x) {
    for (int i = 0; i < x.size(); i++) cout << x[i] << endl;
  }

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
