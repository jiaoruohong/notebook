import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public int myAtoi(String s) {
    // 2147483647
    // -2147483648
    int res = 0;
    int l = Integer.MIN_VALUE / 10;
    int r = Integer.MAX_VALUE / 10;
    int sz = s.length();
    int trimmingLeft = 1;
    int tmp = 0;
    int op = 1;
    for (int i = 0; i < sz; i++) {
      if ('0' <= s.charAt(i) && s.charAt(i) <= '9') {
        trimmingLeft = 0;
        tmp = s.charAt(i) - '0';
        if (op > 0) {
          if (res > r) {
            return Integer.MAX_VALUE;
          } else if (res == r && tmp > 7) {
            return Integer.MAX_VALUE;
          } else {
            res = res * 10 + tmp * op;
          }
        } else {
          if (res < l) {
            return Integer.MIN_VALUE;
          } else if (res == l && tmp > 8) {
            return Integer.MIN_VALUE;
          } else {
            res = res * 10 + tmp * op;
          }
        }
      } else if (s.charAt(i) == ' ') {
        if (trimmingLeft == 0) {
          break;
        }
      } else if (s.charAt(i) == '+') {
        if (trimmingLeft == 0) {
          break;
        }
        trimmingLeft = 0;
        op = 1;
      } else if (s.charAt(i) == '-') {
        if (trimmingLeft == 0) {
          break;
        }
        trimmingLeft = 0;
        op = -1;
      } else {
        break;
      }
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
      a = in.nextLine();
      for (int i = 0; i < n; i++) {
        a = in.nextLine();
        solve(a);
      }
    }

    in.close();
  }

  public void solve(String x) {
    int res;
    res = myAtoi(x);
    otput(res);

  }

  public void otput(int x) {
    System.out.println(x);
  }

  private int n;
  private String a;
}