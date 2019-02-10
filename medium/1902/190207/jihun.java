import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    // Complete the matrixRotation function below.
    static void matrixRotation(List<List<Integer>> matrix, int r) {
        int rowLen = matrix.size(), colLen = matrix.get(0).size();
        int minSize = Math.min(rowLen, colLen);
        int[][] answer = new int[rowLen][colLen];

        for (int t = 0; t < minSize / 2; t++) {
            int curR = r % (2 * rowLen + 2 * colLen - 4);
            Position pos = new Position(t, t, rowLen, colLen);
            Position target = new Position(t, t, rowLen, colLen);

            for (int i = 0; i < curR; i++)
                target.move();

            do {
                answer[target.curRow][target.curCol] = matrix.get(pos.curRow).get(pos.curCol);
                answer[target.curRow][target.curCol] = matrix.get(pos.curRow).get(pos.curCol);
                pos.move();
                target.move();
            } while (!pos.isStart());

            rowLen -= 2;
            colLen -= 2;
        }

        for (int i = 0; i < answer.length; i++) {
            for (int j = 0; j < answer[0].length; j++) {
                System.out.print(answer[i][j] + " ");
            }
            System.out.println();
        }
    }

    static class Position {
        int startRow, startCol;
        int curRow, curCol;
        int rowLen, colLen;

        // Direction = Down : 0, Right : 1, Up : 2, Left : 3
        int di = 0;

        Position(int x, int y, int rowLen, int colLen) {
            this.startRow = curRow = x;
            this.startCol = curCol = y;
            this.rowLen = rowLen;
            this.colLen = colLen;
        }

        void move() {
            switch(di) {
                case 0:
                    curRow++;
                    if (curRow == startRow + rowLen - 1) di = (di + 1) % 4;
                    break;
                case 1:
                    curCol++;
                    if (curCol == startCol + colLen - 1) di = (di + 1) % 4;
                    break;
                case 2:
                    curRow--;
                    if (curRow == startRow) di = (di + 1) % 4;
                    break;
                case 3:
                    curCol--;
                    if (curCol == startCol) di = (di + 1) % 4;
                    break;
            }
        }

        boolean isStart() {
            return startRow == curRow && startCol == curCol;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        String[] mnr = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int m = Integer.parseInt(mnr[0]);

        int n = Integer.parseInt(mnr[1]);

        int r = Integer.parseInt(mnr[2]);

        List<List<Integer>> matrix = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            String[] matrixRowTempItems = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

            List<Integer> matrixRowItems = new ArrayList<>();

            for (int j = 0; j < n; j++) {
                int matrixItem = Integer.parseInt(matrixRowTempItems[j]);
                matrixRowItems.add(matrixItem);
            }

            matrix.add(matrixRowItems);
        }

        matrixRotation(matrix, r);

        bufferedReader.close();
    }
}
