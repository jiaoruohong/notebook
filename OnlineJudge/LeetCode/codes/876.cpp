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
 public:
  ListNode* middleNode(ListNode* head) {
    if (NULL == head) return NULL;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != NULL) {
      slow = slow->next;
      fast = fast->next;
      if (fast == NULL) {
        return slow;
      } else {
        fast = fast->next;
      }
    }
    return slow;
  }

  void input(void) {
    while (~scanf("%d", &n)) {
      a = new ListNode(0);
      ListNode* cur = a;
      for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (i == 0) {
          cur->val = t;
        } else {
          cur->next = new ListNode(t);
          cur = cur->next;
        }
      }
      solve(a);
    }
  }

  void solve(ListNode* x) {
    ListNode* res;
    res = middleNode(x);
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
