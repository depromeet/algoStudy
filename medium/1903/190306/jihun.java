import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the fibonacciModified function below.
    static void fibonacciModified(int t1, int t2, int n) {
        BigInteger tt1 = new BigInteger(Integer.toString(t1));
        BigInteger tt2 = new BigInteger(Integer.toString(t2));
        BigInteger tmp;

        for (int i = 0; i < n - 2; i++) {
            tmp = tt2;
            tt2 = tt1.add(tt2.multiply(tt2));
            tt1 = tmp;
        }

        System.out.println(tt2);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        String[] t1T2n = scanner.nextLine().split(" ");

        int t1 = Integer.parseInt(t1T2n[0]);

        int t2 = Integer.parseInt(t1T2n[1]);

        int n = Integer.parseInt(t1T2n[2]);

        fibonacciModified(t1, t2, n);

        scanner.close();
    }
}
