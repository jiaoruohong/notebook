import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
      val = x;
    }
  }

  void reverseGroup(ListNode u, ListNode v) {
    if (u != v) {
      if (u.next == v) {
        v.next = u;
      } else {
        ListNode t = u.next;
        reverseGroup(u.next, v);
        t.next = u;
      }
    }
  }

  public ListNode reverseKGroup(ListNode head, int k) {
    if (k == 1)
      return head;
    ListNode fakeHead = new ListNode(0);
    fakeHead.next = head;
    ListNode pre = fakeHead;
    ListNode cur = head;
    ListNode u = null;
    ListNode t = null;
    ListNode v = null;
    int cnt = 0;
    while (cur != null) {
      cnt++;
      if (cnt == k) {
        u = pre.next;
        v = cur;
        t = cur.next;
        reverseGroup(u, v);
        pre.next = v;
        u.next = t;
        pre = u;
        cur = u;
        cnt = 0;
      }
      cur = cur.next;
    }
    return fakeHead.next;
  }

  public static void main(String[] args) throws FileNotFoundException {
    FileInputStream fin = new FileInputStream("./assets/fipt.txt");
    PrintStream fot = new PrintStream(new FileOutputStream("./assets/fopt.txt"));

    System.setIn(fin);
    System.setOut(fot);

    Solution sol = new Solution();

    sol.input();
  }

  public void input() {
    Scanner in = new Scanner(System.in);
    while (in.hasNext()) {
      n = in.nextInt();
      m = in.nextInt();

      ListNode a = new ListNode(0);
      ListNode u = a;

      for (int i = 0; i < m; i++) {
        if (i != 0) {
          u.next = new ListNode(0);
          u = u.next;
        }
        u.val = in.nextInt();
      }

      solve(a, n);
    }

    in.close();
  }

  public void solve(ListNode x, int y) {
    ListNode res;
    res = reverseKGroup(x, y);
    otput(res);
  }

  public void otput(ListNode x) {
    while (x != null) {
      System.out.print(x.val);
      x = x.next;
    }
    System.out.println("");
  }

  private int n, m;
}