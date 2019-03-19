import java.util.Scanner;

class Solution {
    static Scanner scanner = new Scanner(System.in);
    static boolean[][] gears = new boolean[4][8];
    static int[] gearI = new int[4];
    public static void main(String[] args) {
        for (int i = 0; i < 4; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < 8; j++)
                gears[i][j] = line.charAt(j) == '1';
        }

        int k = Integer.parseInt(scanner.nextLine());
        int idx, di;
        int tmpDi;

        for (int i = 0; i < k; i++) {
            int[] checks = new int[4];
            String[] line = scanner.nextLine().split(" ");
            idx = Integer.parseInt(line[0]) - 1;
            di = Integer.parseInt(line[1]);

            checks[idx] = di;

            tmpDi = di;
            for (int j = idx + 1; j < 4; j++) {
                tmpDi *= -1;
                if (isS(j - 1, 2) == isS(j, 6)) break;
                else checks[j] = tmpDi;
            }

            tmpDi = di;
            for (int j = idx - 1; j >= 0; j--) {
                tmpDi *= -1;
                if (isS(j + 1, 6) == isS(j, 2)) break;
                else checks[j] = tmpDi;
            }

            for (int j = 0; j < 4; j++)
                if (checks[j] != 0) rotate(j, checks[j]);
        }

        int ans = 0;
        for (int i = 0; i < 4; i++) {
            if (gears[i][gearI[i]])
                ans += Math.pow(2, i);
        }

        System.out.println(ans);
    }

    static void rotate(int idx, int di) {
        if (di == 1) gearI[idx] = (gearI[idx] + 7) % 8;
        else gearI[idx] = (gearI[idx] + 1) % 8;
    }

    static boolean isS(int gearIdx, int pos) {
        return gears[gearIdx][(gearI[gearIdx] + pos) % 8];
    }
}
