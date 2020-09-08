import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public int minSubArrayLen(int s, int[] nums) {
    int res = nums.length;
    int sz = res;
    int sum = 0;
    int u = 0, v = 0;
    boolean occur = false;

    for (v = 0; v < sz; v++) {
      sum += nums[v];
      while (sum >= s && u <= v) {
        occur = true;
        res = Math.min(res, v - u + 1);
        sum -= nums[u];
        u++;
      }
    }
    if (occur == false)
      return 0;

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
      m = in.nextInt();
      a = new int[n];
      for (int i = 0; i < n; i++)
        a[i] = in.nextInt();
      solve(m, a);
    }

    in.close();
  }

  public void solve(int s, int[] x) {
    int res;
    res = minSubArrayLen(s, x);
    otput(res);

  }

  public void otput(int x) {
    System.out.println(x);
  }

  private int n, m;
  private int[] a;
}