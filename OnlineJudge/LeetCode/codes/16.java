import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

class Solution {
  public int threeSumClosest(int[] nums, int target) {
    int res = nums[0] + nums[1] + nums[2];
    Arrays.sort(nums);
    int sz = nums.length;
    for (int i = 0; i < sz; i++) {
      if (i != 0 && nums[i - 1] == nums[i]) {
        continue;
      }
      int j = i + 1, k = sz - 1;
      while (j < k) {
        int t = nums[i] + nums[j] + nums[k];
        if (t < target) {
          if (Math.abs(target - t) < Math.abs(target - res))
            res = t;
          j++;
          while (j < k && nums[j - 1] == nums[j])
            j++;
        } else if (t > target) {
          if (Math.abs(target - t) < Math.abs(target - res))
            res = t;
          k--;
          while (j < k && nums[k] == nums[k + 1])
            k--;
        } else {
          return target;
        }
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
      a = new int[n];
      for (int i = 0; i < n; i++)
        a[i] = in.nextInt();
      solve(a);
    }

    in.close();
  }

  public void solve(int[] x, int y) {
    int res;
    res = threeSumClosest(x, y);
    otput(res);

  }

  public void otput(int x) {
    System.out.println(x);
  }

  private int n;
  private int[] a;
}