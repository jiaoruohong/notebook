import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Solution {
  public List<Integer> spiralOrder(int[][] matrix) {
    List<Integer> res = new ArrayList<>();
    int m = matrix.length;
    int n = matrix[0].length;

    int i = 0, j = 0;
    int row = m, col = n;

    int sum;

    int total = m * n;
    while (total > 0) {
      if (row == 1) {
        for (int k = 0; k < col; k++) {
          res.add(matrix[i][j + k]);
        }
        sum = col;
      } else if (col == 1) {
        for (int k = 0; k < row; k++) {
          res.add(matrix[i + k][j + col - 1]);
        }
        sum = row;
      } else {
        for (int k = 0; k < col - 1; k++) {
          res.add(matrix[i][j + k]);
        }
        for (int k = 0; k < row - 1; k++) {
          res.add(matrix[i + k][j + col - 1]);
        }
        for (int k = 0; k < col - 1; k++) {
          res.add(matrix[i + row - 1][j + col - 1 - k]);
        }
        for (int k = 0; k < row - 1; k++) {
          res.add(matrix[i + row - 1 - k][j]);
        }
        sum = 2 * (row + col) - 4;
      }

      total -= sum;

      row -= 2;
      col -= 2;

      i++;
      j++;
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
        a = in.nextInt();
        b = in.nextInt();

        int[][] v = new int[a][b];
        for (int j = 0; j < a; j++) {
          for (int k = 0; k < b; k++) {
            v[j][k] = in.nextInt();
          }
        }
        solve(v);
      }
    }

    in.close();
  }

  public void solve(int[][] x) {
    List<Integer> res;
    res = spiralOrder(x);
    otput(res);

  }

  public void otput(List<Integer> x) {
    System.out.println(x);
  }

  private int n;
  private int a;
  private int b;
}