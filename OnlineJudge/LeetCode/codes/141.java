import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
      val = x;
      next = null;
    }
  }

  public boolean hasCycle(ListNode head) {
    if (null == head)
      return false;
    ListNode slow = head, fast = head.next;
    while (null != fast) {
      if (slow == fast)
        return true;
      slow = slow.next;
      fast = fast.next;
      if (null != fast)
        fast = fast.next;
    }
    return false;
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
      a = new ListNode(0);

      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (cnt == 0) {
          a.val = in.nextInt();
        } else {
          a.next = new ListNode(in.nextInt());
        }
      }

      solve(a);
    }

    in.close();
  }

  public void solve(ListNode x) {
    boolean res;
    res = hasCycle(x);
    otput(res);

  }

  public void otput(boolean x) {
    System.out.println(x);
  }

  private int n, m;
  private ListNode a;
}