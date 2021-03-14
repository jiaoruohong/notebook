import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public String multiply(String num1, String num2) {
    StringBuilder res = new StringBuilder();
    int len1 = num1.length();
    int len2 = num2.length();
    int a[] = new int[230];
    int val;

    for (int i = len1 - 1; i >= 0; i--) {
      for (int j = len2 - 1; j >= 0; j--) {
        val = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
        int k = (len1 - i - 1) + (len2 - j - 1);
        a[k] += val;
        a[k + 1] += a[k] / 10;
        a[k] %= 10;
      }
    }

    for (int i = len1 + len2; i >= 0; i--) {
      if (res.length() == 0 && a[i] == 0) {
        continue;
      } else {
        res.append(a[i]);
      }
    }

    if (res.length() == 0) {
      return "0";
    }
    return res.toString();
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
        a = in.next();
        b = in.next();
        solve(a, b);
      }
    }

    in.close();
  }

  public void solve(String x, String y) {
    String res;
    res = multiply(x, y);
    otput(res);

  }

  public void otput(String x) {
    System.out.println(x);
  }

  private int n;
  private String a;
  private String b;
}