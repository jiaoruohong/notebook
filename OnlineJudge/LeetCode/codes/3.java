import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

class Solution {
  public int lengthOfLongestSubstring(String s) {
    int res = 0;
    int sz = s.length();
    int l = 0, r = 0;
    if (sz == 0)
      return 0;
    int[] mp = new int[256];
    Arrays.fill(mp, -1);

    for (int i = 0; i < sz; i++)
      if (mp[s.charAt(i)] == -1) {
        r = i;
        mp[s.charAt(i)] = i;
      } else {
        if (mp[s.charAt(i)] == -2) {
          r = i;
          mp[s.charAt(i)] = i;
        } else {
          res = Math.max(res, r - l + 1);
          int newL = mp[s.charAt(i)] + 1;
          for (int j = l; j < mp[s.charAt(i)] + 1; j++)
            mp[s.charAt(j)] = -2;
          l = newL;
          r = i;
          mp[s.charAt(i)] = i;
        }
      }

    res = Math.max(res, r - l + 1);
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
      solve(in.nextLine());
    }

    in.close();
  }

  public void solve(String x) {
    int res;
    res = lengthOfLongestSubstring(x);
    otput(res);

  }

  public void otput(int x) {
    System.out.println(x);
  }

  private String a;
}