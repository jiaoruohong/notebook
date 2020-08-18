import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Solution {
  public int[][] merge(int[][] intervals) {
    ArrayList<int[]> res = new ArrayList<int[]>();
    Arrays.sort(intervals, new Comparator<int[]>() {
      @Override
      public int compare(int[] l, int[] r) {
        return l[0] - r[0];
      }
    });
    int sz = intervals.length;
    for (int i = 0; i < sz; i++) {
      int l = intervals[i][0];
      int r = intervals[i][1];
      while (i < sz - 1 && intervals[i + 1][0] <= r) {
        r = Math.max(r, intervals[i + 1][1]);
        i++;
      }
      res.add(new int[] { l, r });
    }

    return res.toArray(new int[res.size()][2]);
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

      vals = new int[n][2];

      for (int i = 0; i < n; i++) {
        vals[i][0] = in.nextInt();
        vals[i][1] = in.nextInt();
      }

      solve(vals);
    }

    in.close();
  }

  public void solve(int[][] x) {
    int[][] res;
    res = merge(x);
    otput(res);

  }

  public void otput(int[][] x) {
    int sz = x.length;
    for (int i = 0; i < sz; i++)
      System.out.println(x[i][0] + " " + x[i][1]);
  }

  private int n;
  private int[][] vals;
}