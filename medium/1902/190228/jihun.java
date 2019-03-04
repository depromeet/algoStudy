import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the bomberMan function below.
    static String[] bomberMan(int n, String[] grid) {
        String[] strAns = new String[grid.length];
        char[][] answer = new char[grid.length + 2][grid[0].length() + 2];
        char[][] answer2 = new char[grid.length + 2][grid[0].length() + 2];

        if (n == 1) return grid;

        if (n % 2 == 0) {
            for (int i = 0; i < grid.length; i++) {
                strAns[i] = grid[i].replaceAll(".", "O");
            }
            return strAns;
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length(); j++) {
                if (grid[i].charAt(j) == 'O') {
                    answer[1 + i][1 + j] = '.';
                    answer[1 + i - 1][1 + j] = '.';
                    answer[1 + i + 1][1 + j] = '.';
                    answer[1 + i][1 + j - 1] = '.';
                    answer[1 + i][1 + j + 1] = '.';
                }
            }
        }

        for (int i = 0; i <= grid.length; i++) {
            for (int j = 0; j <= grid[0].length(); j++) {
                if (answer[i][j] != '.') {
                    answer[i][j] = 'O';
                }
            }
        }

        for (int i = 1; i <= grid.length; i++) {
            strAns[i - 1] = new String(answer[i], 1, grid[0].length());
        }
        if (n % 4 == 1) {
            for (int i = 1; i <= grid.length; i++) {
                for (int j = 1; j <= grid[0].length(); j++) {
                    if (answer[i][j] == 'O') {
                        answer2[i][j] = '.';
                        answer2[i - 1][j] = '.';
                        answer2[i + 1][j] = '.';
                        answer2[i][j - 1] = '.';
                        answer2[i][j + 1] = '.';
                    }

                }
            }
            for (int i = 0; i <= grid.length; i++) {
                for (int j = 0; j <= grid[0].length(); j++) {
                    if (answer2[i][j] != '.') {
                        answer2[i][j] = 'O';
                    }
                }
            }

            for (int i = 1; i <= grid.length; i++) {
                strAns[i - 1] = new String(answer2[i], 1, grid[0].length());
            }
        }

        return strAns;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
//        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] rcn = scanner.nextLine().split(" ");

        int r = Integer.parseInt(rcn[0]);

        int c = Integer.parseInt(rcn[1]);

        int n = Integer.parseInt(rcn[2]);

        String[] grid = new String[r];

        for (int i = 0; i < r; i++) {
            String gridItem = scanner.nextLine();
            grid[i] = gridItem;
        }

        String[] result = bomberMan(n, grid);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(result[i]);

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

