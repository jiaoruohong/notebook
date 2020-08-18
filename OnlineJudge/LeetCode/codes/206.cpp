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
  ListNode* reverseList(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* st = head;
    ListNode* en = NULL;
    ListNode* cur = head;
    while (cur->next != NULL) {
      cur = cur->next;
    }
    en = cur;
    while (st != en) {
      cur = st->next;
      st->next = en->next;
      en->next = st;
      st = cur;
    }
    return en;
  }
  void input(void) {
    while (~scanf("%d", &n)) {
      a = new ListNode(0);
      ListNode* u = a;
      int x;

      for (int i = 0; i < n; i++) {
        if (i != 0) {
          u->next = new ListNode(0);
          u = u->next;
        }

        scanf("%d", &u->val);
      }

      solve(a);
    }
  }
  void solve(ListNode* x) {
    ListNode* res;
    res = reverseList(x);
    otput(res);
  }
  void otput(ListNode* x) {
    ListNode* cur = x;
    while (cur != NULL) {
      printf("%d\n", cur->val);
      cur = cur->next;
    }
  }

 private:
  int n;
  ListNode* a;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
