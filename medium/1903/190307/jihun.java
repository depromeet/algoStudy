import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the substrings function below.
    static long substrings(String n) {
        long ans = 0;
        final long MOD = 1000000007;
        long digit = 1;

        for (int i = 1; i <= n.length(); i++) {
            ans = (ans + (digit * (Character.getNumericValue(n.charAt(n.length() - i)) * (n.length() - i + 1)))) % MOD;
            digit = (digit * 10 + 1) % MOD;
        }

        return ans;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String n = scanner.nextLine();

        long result = substrings(n);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
