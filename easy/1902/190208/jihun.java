import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the decentNumber function below.
    static void decentNumber(int n) {
        if (n % 3 == 0) {
            String answer = new String(new char[n]).replace("\0", "5");
            System.out.println(answer);
            return;
        }

        else {
            for (int i = n/3; i >= 0; i--) {
                int count5 = 3 * i;
                int count3 = n - count5;
                if (count3 % 5 == 0) {
                    String a5 = new String(new char[count5]).replace("\0", "5");
                    String a3 = new String(new char[count3]).replace("\0", "3");
                    System.out.println(a5 + a3);
                    return;
                }
            }
        }

        System.out.println("-1");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(bufferedReader.readLine().trim());

        for (int tItr = 0; tItr < t; tItr++) {
            int n = Integer.parseInt(bufferedReader.readLine().trim());

            decentNumber(n);
        }

        bufferedReader.close();
    }
}
