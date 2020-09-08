import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public int removeDuplicates(int[] nums) {
    int res = 0;
    int sz = nums.length;
    if (sz == 0)
      return 0;
    int cur = 0;
    for (int i = 0; i < sz; i++)
      if (nums[cur] != nums[i]) {
        cur++;
        nums[cur] = nums[i];
      }
    res = cur + 1;
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
    res = removeDuplicates(x);
    otput(res);

  }

  public void otput(int x) {
    System.out.println(x);
  }

  private int n;
  private int[] a;
}