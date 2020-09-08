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
  bool hasCycle(ListNode* head) {
    if (NULL == head) return false;
    ListNode *slow = head, *fast = head->next;
    while (NULL != fast) {
      if (slow == fast) return true;
      slow = slow->next;
      fast = fast->next;
      if (NULL != fast) fast = fast->next;
    }
    return false;
  }

  void input(void) {
    while (~scanf("%d %d", &n, &m)) {
      int t;

      scanf("%d", &t);
      a = new ListNode(t);
      ListNode* cur = a;

      for (int i = 1; i < n; i++) {
        scanf("%d", &t);
        cur->next = new ListNode(t);
        cur = cur->next;
      }
      ListNode* back = cur;
      cur = a;
      if (m >= 0) {
        for (int i = 0; i < m - 1; i++) cur = cur->next;
        back->next = cur;
      }

      solve(a);
    }
  }

  void solve(ListNode* x) {
    bool res;
    res = hasCycle(x);
    otput(res);
  }
  void otput(int x) { printf("%d\n", x); }

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
