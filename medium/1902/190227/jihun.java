import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static final int INF = 99999999;
    static int N = 0;
    static int curX = 0;
    static int curY = 0;
    static int curMinLen = INF;

    // Complete the knightlOnAChessboard function below.
    static int[][] knightlOnAChessboard(int n) {
        N = n;
        int[][] answer = new int[N - 1][N - 1];
        for (int i = 0; i < N - 1; i++) {
            for (int j = i; j < N - 1; j++) {
                curX = i + 1;
                curY = j + 1;
                curMinLen = INF;

                bfs();
                answer[i][j] = answer[j][i] = curMinLen == INF ? -1 : curMinLen;
            }
        }

        return answer;
    }

    static void bfs() {
        Deque<int[]> q = new ArrayDeque<>();
        boolean[][] visit = new boolean[N][N];

        visit[0][0] = true;
        int[] curPosAndLen = {0, 0, 0};
        int[][] di = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        int x, y, diffX, diffY;
        q.add(curPosAndLen);
        while (!q.isEmpty()) {
            curPosAndLen = q.poll();
            for (int k = 0; k < 2; k++) {
                if (k == 0) { diffX = curX; diffY = curY; }
                else { diffX = curY; diffY = curX; }

                for (int[] d : di) {
                    x = curPosAndLen[0] + diffX * d[0];
                    y = curPosAndLen[1] + diffY * d[1];

                    if (x < 0 || x >= N || y < 0 || y >= N || visit[x][y]) continue;

                    visit[x][y] = true;
                    if (x == N - 1 && y == N - 1) {
                        curMinLen = curPosAndLen[2] + 1;
                        return;
                    }
                    else {
                        int[] tmp = {x, y, curPosAndLen[2] + 1};
                        q.add(tmp);
                    }
                }
            }
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
//        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[][] result = knightlOnAChessboard(n);

        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[i].length; j++) {
                bufferedWriter.write(String.valueOf(result[i][j]));

                if (j != result[i].length - 1) {
                    bufferedWriter.write(" ");
                }
            }

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
