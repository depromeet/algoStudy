import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static int n;
    static boolean[][] answer = new boolean[1001][1024];
    static HashMap<Integer, ArrayList<BCost>> map = new HashMap<>();

    static class BCost {
        int b;
        int cost;

        BCost(int b, int cost) {
            this.b = b;
            this.cost = cost;
        }
    }

    // Complete the beautifulPath function below.
    static int beautifulPath(int[][] edges, int A, int B) {
        for (int[] e : edges) {
            int a = e[0];
            int b = e[1];
            int cost = e[2];

            ArrayList<BCost> bCosts = map.getOrDefault(a, new ArrayList<>());
            bCosts.add(new BCost(b, cost));
            map.put(a, bCosts);

            bCosts = map.getOrDefault(b, new ArrayList<>());
            bCosts.add(new BCost(a, cost));
            map.put(b, bCosts);
        }

        dfs(A, 0);

        for (int i = 1; i < 1024; i++) {
            if (answer[B][i]) return i;
        }

        return -1;
    }

    static void dfs(int a, int cost) {
        answer[a][cost] = true;

        ArrayList<BCost> bCosts = map.get(a);
        if (bCosts == null) return;
        for (BCost bc : bCosts) {
            if (!answer[bc.b][cost | bc.cost]) {
                dfs(bc.b, cost | bc.cost);
            }
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        n = Integer.parseInt(nm[0]);

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
