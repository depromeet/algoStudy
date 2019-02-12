import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static int n;
    static int answer = -1;
    static int[][] map;

    // Complete the beautifulPath function below.
    static int beautifulPath(int[][] edges, int A, int B) {

        for (int i = 0 ; i < edges.length; i++) {
            if (map[edges[i][0]][edges[i][1]] == 0 || edges[i][2] < map[edges[i][0]][edges[i][1]]) {
                map[edges[i][0]][edges[i][1]] = edges[i][2];
                map[edges[i][1]][edges[i][0]] = edges[i][2];
            }
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                System.out.printf("%3d ", map[i][j]);
            }
            System.out.println();
        }

        getMinimalPath(new HashSet<Integer>(), 0, A, B);

        return answer;
    }

    static void getMinimalPath(Set<Integer> set, int path, int src, int dst) {
        if (set.contains(src)) return;
        if (answer != -1 && path >= answer) return;
        if (src == dst) {
            answer = path;
            return;
        }

        Set<Integer> newSet = new HashSet<>(set);
        newSet.add(src);

        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 1; i < n + 1; i++) {
            if (map[src][i] > 0 && !set.contains(i)) {
                a.add(i);
            }
        }

        Collections.sort(a);

        for (int val : a)
            getMinimalPath(newSet, path | map[src][val], val, dst);

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        n = Integer.parseInt(nm[0]);
        map = new int[n + 1][n + 1];

        int m = Integer.parseInt(nm[1]);

        int[][] edges = new int[m][3];

        for (int i = 0; i < m; i++) {
            String[] edgesRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 3; j++) {
                int edgesItem = Integer.parseInt(edgesRowItems[j]);
                edges[i][j] = edgesItem;
            }
        }

        String[] AB = scanner.nextLine().split(" ");

        int A = Integer.parseInt(AB[0]);

        int B = Integer.parseInt(AB[1]);

        int result = beautifulPath(edges, A, B);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
