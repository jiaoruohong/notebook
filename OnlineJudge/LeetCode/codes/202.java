import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public int cal(int x) {
    int res = 0;
    int t;
    while (x != 0) {
      t = x % 10;
      x /= 10;
      res += t * t;
    }
    return res;
  }

  public boolean isHappy(int n) {
    if (n == 1)
      return true;
    int slow = n, fast = cal(n);
    while (slow != fast) {
      if (slow == 1 || fast == 1)
        return true;
      slow = cal(slow);
      fast = cal(cal(fast));
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
      solve(n);
    }

    in.close();
  }

  public void solve(int x) {
    boolean res;
    res = isHappy(x);
    otput(res);

  }

  public void otput(boolean x) {
    System.out.println(x);
  }

  private int n, m;
  private ListNode a;
}