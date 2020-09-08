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

  public ListNode middleNode(ListNode head) {
    if (null == head)
      return null;
    ListNode slow = head;
    ListNode fast = head.next;
    while (fast != null) {
      slow = slow.next;
      fast = fast.next;
      if (fast == null) {
        return slow;
      } else {
        fast = fast.next;
      }
    }
    return slow;
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
      a = new ListNode(0);
      ListNode cur = a;
      for (int i = 0; i < n; i++) {
        if (i == 0) {
          cur.val = in.nextInt();
        } else {
          cur.next = new ListNode(in.nextInt());
          cur = cur.next;
        }
      }
      solve(a);
    }

    in.close();
  }

  public void solve(ListNode x) {
    ListNode res;
    res = middleNode(x);
    otput(res);

  }

  public void otput(ListNode x) {
    ListNode cur = x;
    while (cur != null) {
      System.out.println(cur.val);
      cur = cur.next;
    }
  }

  private int n, m;
  private ListNode a;
}