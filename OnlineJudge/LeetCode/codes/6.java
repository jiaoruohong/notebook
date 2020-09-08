import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

class Solution {
  public String convert(String s, int numRows) {
    if (s.length() <= 1)
      return s;
    if (numRows == 1)
      return s;
    String res = "";
    ArrayList<Integer> v = new ArrayList<Integer>();
    int addItem = 2 * (numRows - 1);
    int sz = s.length();
    int item = 0;
    int len;
    int l, r;
    while (item < sz) {
      v.add(item);

      res += s.charAt(item);
      item += addItem;
    }
    v.add(item);
    for (len = 1; len < numRows - 1; len++) {
      for (int i = 0; i < v.size(); i++) {
        l = v.get(i) - len;
        r = v.get(i) + len;
        if (0 <= l && l < sz) {
          res += s.charAt(l);
        }
        if (0 <= r && r < sz) {
          res += s.charAt(r);
        }
      }
    }
    for (int i = 0; i < v.size(); i++) {
      r = v.get(i) + numRows - 1;
      if (r < sz) {
        res += s.charAt(r);
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

      a = in.next();

      solve(a, n);
    }

    in.close();
  }

  public void solve(String x, int y) {
    String res;
    res = convert(x, y);
    otput(res);

  }

  public void otput(String x) {
    System.out.println(x);
  }

  private int n;
  private String a;
}