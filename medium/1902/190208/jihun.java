import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the redJohn function below.
    static int redJohn(int n) {
        return getNumOfPrimes(getNumOfWays(n));
    }

    static int getNumOfPrimes(int n) {
        if (n < 2) return 0;

        int count = 0;
        boolean[] prime = new boolean[n + 1];

        for (int i = 2; i <= n; i++) {
            if (!prime[i]) {
                count++;
                for (int j = 2 * i; j < n + 1; j += i)
                    prime[j] = true;
            }
        }

        return count;
    }

    static int getNumOfWays(int n) {
        int[] ways = new int[n + 5];

        ways[1] = ways[2] = ways[3] = 1;
        ways[4] = 2;

        for (int i = 5; i <= n; i++)
            ways[i] = ways[i - 1] + ways[i - 4];

        return ways[n];
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int result = redJohn(n);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
