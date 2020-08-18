import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public int firstUniqChar(String s) {
    int ans = -1;
    int u, v;
    for (char ch = 'a'; ch <= 'z'; ch++) {
      u = s.indexOf(ch);
      v = s.lastIndexOf(ch);
      if (u == v && u != -1) {
        if (ans == -1) {
          ans = u;
        } else {
          if (u < ans)
            ans = u;
        }
      }
    }
    return ans;
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
      String str = in.nextLine();
      solve(str);
    }

    in.close();
  }

  public void solve(String s) {
    int res;
    res = firstUniqChar(s);
    otput(res);
  }

  public void otput(int idx) {
    System.out.println(idx);
  }

  private int n, m, t;
  private int u, v;
  private int[] numbers = new int[10000];
}