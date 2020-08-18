import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;

class Node {
  int val;
  Node next;
  Node random;

  public Node(int val) {
    this.val = val;
    this.next = null;
    this.random = null;
  }
}

class Solution {
  public Node copyRandomList(Node head) {
    if (head == null)
      return null;

    Node res = new Node(head.val);
    Node cur_h = head;
    Node cur_r = res;
    Map<Node, Node> mp = new HashMap<Node, Node>();
    mp.put(null, null);

    while (cur_h != null) {
      if (cur_h != head) {
        cur_r.next = new Node(cur_h.val);
        cur_r = cur_r.next;
      }
      mp.put(cur_h, cur_r);
      cur_h = cur_h.next;
    }

    cur_h = head;
    cur_r = res;
    while (cur_h != null) {
      cur_r.random = mp.get(cur_h.random);
      cur_r = cur_r.next;

      cur_h = cur_h.next;
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

      Node a = new Node(0);
      Node u = a;
      LinkedList<Integer> v = new LinkedList<Integer>();
      LinkedList<Node> record = new LinkedList<Node>();

      for (int i = 0; i < n; i++) {
        if (i != 0) {
          u.next = new Node(0);
          u = u.next;
        }
        u.val = in.nextInt();

        v.add(in.nextInt());
        record.add(u);
      }
      for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
          record.get(i).next = record.get(i + 1);
        }
        if (v.get(i) == 11111) {
          continue;
        }
        record.get(i).random = record.get(v.get(i));
      }

      solve(a);
    }

    in.close();
  }

  public void solve(Node x) {
    Node res;
    res = copyRandomList(x);
    otput(res);

  }

  public void otput(Node x) {
    Node cur = x;
    int cnt = 0;
    Map<Node, Integer> mp = new HashMap<Node, Integer>();
    while (cur != null) {
      mp.put(cur, cnt);
      cnt++;
      cur = cur.next;
    }
    cur = x;
    while (cur != null) {
      System.out.print(cur.val + " ");
      if (cur.random == null)
        System.out.println("null");
      else
        System.out.println(mp.get(cur.random));

      cur = cur.next;
    }

  }

  private int n, m;
}