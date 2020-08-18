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

  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode res = new ListNode(0);
    ListNode u = l1;
    ListNode v = l2;
    ListNode cur = null;
    int t = 0;

    while (u != null || v != null || t != 0) {
      if (cur == null) {
        cur = res;
      } else {
        cur.next = new ListNode(0);
        cur = cur.next;
      }
      cur.next = null;

      cur.val = t;
      if (u != null) {
        cur.val += u.val;
        u = u.next;
      }
      if (v != null) {
        cur.val += v.val;
        v = v.next;
      }
      t = cur.val / 10;
      cur.val %= 10;
    }

    return res;
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
      ListNode b = new ListNode(0);
      ListNode u = a;
      ListNode v = b;

      for (int i = 0; i < n; i++) {
        if (i != 0) {
          u.next = new ListNode(0);
          u = u.next;
        }
        u.val = in.nextInt();
      }
      for (int i = 0; i < m; i++) {
        if (i != 0) {
          v.next = new ListNode(0);
          v = v.next;
        }
        v.val = in.nextInt();
      }

      solve(a, b);
    }

    in.close();
  }

  public void solve(ListNode x, ListNode y) {
    ListNode res;
    res = addTwoNumbers(x, y);
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