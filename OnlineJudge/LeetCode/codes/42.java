import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public int trap(int[] height) {
    int res = 0;
    int sz = height.length;
    if (sz == 0)
      return 0;

    int[] lmx = new int[sz];
    int[] rmx = new int[sz];

    for (int i = 1, j = sz - 2; i < sz; i++, j--) {
      lmx[i] = Math.max(lmx[i - 1], height[i - 1]);
      rmx[j] = Math.max(rmx[j + 1], height[j + 1]);
    }
    for (int i = 1; i < sz - 1; i++)
      res += Math.max(0, Math.min(lmx[i], rmx[i]) - height[i]);
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
      a = new int[n];
      for (int i = 0; i < n; i++)
        a[i] = in.nextInt();
      solve(a);
    }

    in.close();
  }

  public void solve(int[] x) {
    int res;
    res = trap(x);
    otput(res);

  }

  public void otput(int x) {
    System.out.println(x);
  }

  private int n;
  private int[] a;
}