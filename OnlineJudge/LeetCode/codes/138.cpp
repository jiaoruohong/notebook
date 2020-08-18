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

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == NULL) return NULL;

    Node* res = new Node(head->val);
    Node* cur_h = head;
    Node* cur_r = res;
    map<Node*, Node*> mp;
    mp.insert(pair<Node*, Node*>(NULL, NULL));

    while (cur_h != NULL) {
      if (cur_h != head) {
        cur_r->next = new Node(cur_h->val);
        cur_r = cur_r->next;
      }
      mp.insert(pair<Node*, Node*>(cur_h, cur_r));
      cur_h = cur_h->next;
    }

    cur_h = head;
    cur_r = res;
    while (cur_h != NULL) {
      cur_r->random = mp[cur_h->random];
      cur_r = cur_r->next;

      cur_h = cur_h->next;
    }

    return res;
  }
  void input(void) {
    while (~scanf("%d", &n)) {
      a = new Node(0);
      Node* u = a;
      int x;
      vector<int> v;
      vector<Node*> record;

      for (int i = 0; i < n; i++) {
        if (i != 0) {
          u->next = new Node(0);
          u = u->next;
        }

        scanf("%d %d", &u->val, &x);
        v.push_back(x);
        record.push_back(u);
      }
      for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
          record[i]->next = record[i + 1];
        }
        if (v[i] == 11111) {
          continue;
        }
        record[i]->random = record[v[i]];
      }

      solve(a);
    }
  }
  void solve(Node* x) {
    Node* res;
    res = copyRandomList(x);
    otput(res);
  }
  void otput(Node* x) {
    Node* cur = x;
    int cnt = 0;
    map<Node*, int> mp;
    while (cur != NULL) {
      mp.insert(pair<Node*, int>(cur, cnt));
      cnt++;
      cur = cur->next;
    }
    cur = x;
    while (cur != NULL) {
      printf("%d ", cur->val);
      if (cur->random == NULL)
        printf("null\n");
      else
        printf("%d\n", mp[cur->random]);

      cur = cur->next;
    }
  }

 private:
  int n;
  Node* a;
};

int main() {
  freopen("./assets/fipt.txt", "r", stdin);
  freopen("./assets/fopt.txt", "w", stdout);

  Solution sol;

  sol.input();

  return 0;
}
