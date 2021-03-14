import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public int reverse(int x) {
    int res = 0;
    int l = Integer.MIN_VALUE / 10;
    int r = Integer.MAX_VALUE / 10;
    while (0 != (x / 10)) {
      res = res * 10 + x % 10;
      x /= 10;
    }

    if (res < l || res > r) {
      res = 0;
    } else if (res == l && x < -7) {
      res = 0;
    } else if (res == r && x > 8) {
      res = 0;
    } else {
      res = res * 10 + x;
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

      for (int i = 0; i < n; i++) {
        a = in.nextInt();
        solve(a);
      }
    }

    in.close();
  }

  public void solve(int x) {
    int res;
    res = reverse(x);
    otput(res);

  }

  public void otput(int x) {
    System.out.println(x);
  }

  private int n;
  private int a;
}