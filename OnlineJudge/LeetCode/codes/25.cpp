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
  void reverseGroup(ListNode* u, ListNode* v) {
    if (u != v) {
      if (u->next == v) {
        v->next = u;
      } else {
        ListNode* t = u->next;
        reverseGroup(u->next, v);
        t->next = u;
      }
    }
  }
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) return head;

    ListNode* fakeHead = new ListNode(0);
    fakeHead->next = head;
    ListNode* pre = fakeHead;
    ListNode* cur = head;
    ListNode* u = NULL;
    ListNode* t = NULL;
    ListNode* v = NULL;
    int cnt = 0;
    while (cur != NULL) {
      cnt++;
      if (cnt == k) {
        u = pre->next;
        v = cur;
        t = cur->next;
        reverseGroup(u, v);
        pre->next = v;
        u->next = t;
        pre = u;
        cur = u;
        cnt = 0;
      }
      cur = cur->next;
    }
    return fakeHead->next;
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
    res = reverseKGroup(x, y);
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
