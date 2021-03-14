import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public int addDigits(int num) {
    if (num < 10) {
      return num;
    } else {
      int res = num % 9;
      if (res == 0) {
        res = 9;
      }
      return res;
    }
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
    res = addDigits(x);
    otput(res);

  }

  public void otput(int x) {
    System.out.println(x);
  }

  private int n;
  private int a;
}