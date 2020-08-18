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
  
  vector<vector<int> > merge(vector<vector<int> >& intervals) {
    vector<vector<int> > res;
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++) {
      if (res.empty()) {
        res.push_back(intervals[i]);
      } else {
        if (res.back()[1] < intervals[i][0]) {
          res.push_back(intervals[i]);
        } else {
          if (res.back()[1] < intervals[i][1]) res.back()[1] = intervals[i][1];
        }
      }
    }

    return res;
  }
  void input(void) {
    while (~scanf("%d", &n)) {
      int u, v;
      for (int i = 0; i < n; i++) {
        vector<int> t;
        scanf("%d %d", &u, &v);

        t.push_back(u);
        t.push_back(v);
        a.push_back(t);
      }

      solve(a);
      a.clear();
    }
  }
  void solve(vector<vector<int> >& x) {
    vector<vector<int> > res;
    res = merge(x);
    otput(res);
  }
  void otput(vector<vector<int> >& x) {
    vector<vector<int> > cur = x;
    for (int i = 0; i < cur.size(); i++)
      printf("%d %d\n", cur[i][0], cur[i][1]);
  }

 private:
  int n;
  vector<vector<int> > a;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
