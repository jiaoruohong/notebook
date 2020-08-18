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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode(0);
    ListNode* u = l1;
    ListNode* v = l2;
    ListNode* cur = NULL;
    int t = 0;

    while (u != NULL || v != NULL || t != 0) {
      if (cur == NULL) {
        cur = res;
      } else {
        cur->next = new ListNode(0);
        cur = cur->next;
      }
      cur->next = NULL;

      cur->val = t;
      if (u != NULL) {
        cur->val += u->val;
        u = u->next;
      }
      if (v != NULL) {
        cur->val += v->val;
        v = v->next;
      }
      t = cur->val / 10;
      cur->val %= 10;
    }

    return res;
  }
  void input(void) {
    while (~scanf("%d %d", &n, &m)) {
      a = new ListNode(0);
      b = new ListNode(0);
      ListNode* u = a;
      ListNode* v = b;

      for (int i = 0; i < n; i++) {
        u->next = new ListNode(0);
        u = u->next;
        u->next = NULL;

        scanf("%d", &u->val);
      }
      for (int i = 0; i < m; i++) {
        v->next = new ListNode(0);
        v = v->next;
        v->next = NULL;

        scanf("%d", &v->val);
      }

      solve(a, b);
    }
  }
  void show(ListNode* x) {
    ListNode* cur = x;
    while (cur != NULL) {
      printf("%d", cur->val);
      cur = cur->next;
    }
  }
  void solve(ListNode* x, ListNode* y) {
    ListNode* res;
    res = addTwoNumbers(x, y);
    otput(res);
  }
  void otput(ListNode* x) {
    ListNode* cur = x->next;
    while (cur != NULL) {
      printf("%d", cur->val);
      cur = cur->next;
    }
    cout << endl;
  }

 private:
  int n, m;
  ListNode *a, *b;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
