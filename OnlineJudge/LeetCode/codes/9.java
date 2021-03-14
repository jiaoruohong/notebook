import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public boolean isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int res = x;
    int num = 0;
    int r = Integer.MAX_VALUE / 10;
    while (x > 0) {
      if (num > r) {
        return false;
      } else if (num == r && (x % 10) > 7) {
        return false;
      }
      num = num * 10 + x % 10;
      x /= 10;
    }

    return res == num;
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
      for (int i = 0; i < n; i++) {
        a = in.nextInt();
        solve(a);
      }
    }

    in.close();
  }

  public void solve(int x) {
    boolean res;
    res = isPalindrome(x);
    otput(res);

  }

  public void otput(Boolean x) {
    System.out.println(x);
  }

  private int n;
  private int a;
}