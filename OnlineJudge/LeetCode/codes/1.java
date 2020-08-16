import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Solution {
  public int[] twoSum(int[] nums, int target) {
    int[] ans = new int[2];
    for (int i = 0; i < nums.length; i++)
      for (int j = i + 1; j < nums.length; j++)
        if (nums[i] + nums[j] == target) {
          // u = i;
          // v = j;
          ans[0] = i;
          ans[1] = j;
          break;
        }
    return ans;
  }

  public static void main(String[] args) throws FileNotFoundException {
    FileInputStream fin = new FileInputStream("./assets/fipt.txt");
    PrintStream fot = new PrintStream(new FileOutputStream("./assets/fopt.txt"));

    System.setIn(fin);
    System.setOut(fot);

    Solution solve = new Solution();

    solve.input();
    solve.manage();
    solve.output();
  }

  public void input() {
    Scanner in = new Scanner(System.in);

    while (in.hasNext()) {
      n = in.nextInt();
      m = in.nextInt();
      for (int i = 0; i < n; i++)
        numbers[i] = in.nextInt();
    }

    in.close();
  }

  public void manage() {
    twoSum(numbers, m);
  }

  public void output() {
    System.out.println(u + " " + v);
  }

  private int n, m;
  private int u, v;
  private int[] numbers = new int[10000];
}