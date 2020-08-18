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
  int deleteNode(ListNode* x, int target) {
    if (x == NULL) return 0;

    int u = deleteNode(x->next, target);

    if (u != -1) {
      if (u == target) {
        ListNode* y = x->next->next;
        delete x->next;
        x->next = y;
      } else {
        return u + 1;
      }
    }

    return -1;
  }
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int u = deleteNode(head, n);
    if (u != -1) {
      ListNode* t = head;
      head = head->next;
      delete t;
    }

    return head;
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
    res = removeNthFromEnd(x, y);
    otput(res);
  }
  void otput(ListNode* x) {
    ListNode* cur = x;
    while (cur != NULL) {
      printf("%d", cur->val);
      cur = cur->next;
    }
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
