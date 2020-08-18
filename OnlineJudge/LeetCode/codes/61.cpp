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

typedef struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) return head;
    ListNode* res = head;
    ListNode* cur = head;
    ListNode* pre = NULL;
    ListNode* st = NULL;
    ListNode* en = NULL;
    vector<ListNode*> v;
    while (cur != NULL) {
      v.push_back(cur);

      if (cur->next == NULL) en = cur;
      cur = cur->next;
    }

    int lenOfList = v.size();
    int mk = k % lenOfList;
    if (mk != 0) {
      pre = v[lenOfList - mk - 1];
      st = v[lenOfList - mk];
      pre->next = NULL;
      en->next = res;
      res = st;
    }

    return res;
  }

  void input(void) {
    while (~scanf("%d %d", &n, &m)) {
      a = new ListNode(0);
      ListNode* u = a;

      for (int i = 0; i < m; i++) {
        if (i != 0) {
          u->next = new ListNode(0);
          u = u->next;
        }

        scanf("%d", &u->val);
      }

      solve(a, n);
    }
  }
  void solve(ListNode* x, int y) {
    ListNode* res;
    res = rotateRight(x, y);
    otput(res);
  }
  void otput(ListNode* x) {
    ListNode* cur = x;
    while (cur != NULL) {
      printf("%d", cur->val);
      cur = cur->next;
    }
    cout << endl;
  }

 private:
  int n, m;
  ListNode* a;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
