import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the separateNumbers function below.
    static void separateNumbers(String s) {
        for (int posCount = 1; posCount <= s.length() / 2; posCount++) {
            StringBuilder tmp = new StringBuilder(s.substring(0, posCount));
            long first = Long.parseLong(tmp.toString());
            long x = first;

            while (tmp.length() < s.length()) tmp.append(++x);

            if (tmp.toString().equals(s)) {
                System.out.println("YES " + first);
                return;
            }
        }

        System.out.println("NO");
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            separateNumbers(s);
        }

        scanner.close();
    }
}
