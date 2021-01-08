import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public String longestCommonPrefix(String[] strs) {
    if (strs.length == 0) {
      return "";
    }
    String str = strs[0];
    for (int i = 1; i < strs.length; i++) {
      while (strs[i].indexOf(str) != 0) {
        str = str.substring(0, str.length() - 1);
      }
      if (str.length() == 0) {
        break;
      }
    }
    return str;
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
      a = new String[n];

      for (int i = 0; i < n; i++) {
        a[i] = in.next();
      }

      solve(a);
    }

    in.close();
  }

  public void solve(String[] x) {
    String res;
    res = longestCommonPrefix(x);
    otput(res);

  }

  public void otput(String x) {
    System.out.println(x);
  }

  private int n;
  private String[] a = null;
}