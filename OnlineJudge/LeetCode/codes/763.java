import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Solution {
  public List<Integer> partitionLabels(String S) {
    List<Integer> res = new ArrayList<>();
    List<Integer> u = new ArrayList<Integer>(Collections.nCopies(26, -1));

    int sz = S.length();
    for (int i = 0; i < sz; i++) {
      u.set(S.charAt(i) - 'a', i);
    }

    int l = 0, r = u.get(S.charAt(0) - 'a');
    for (int i = 0; i < sz; i++) {
      r = Math.max(r, u.get(S.charAt(i) - 'a'));
      if (r == i) {
        res.add(r - l + 1);
        l = i + 1;
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

      for (int i = 0; i < n; i++) {
        a = in.next();
      }

      solve(a);
    }

    in.close();
  }

  public void solve(String x) {
    List<Integer> res;
    res = partitionLabels(x);
    otput(res);

  }

  public void otput(List<Integer> x) {
    System.out.println(x);
  }

  private int n;
  private String a = null;
}