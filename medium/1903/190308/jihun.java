import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the maxSubarray function below.
    static int[] maxSubarray(int[] arr) {
        int[] ans = new int[2];
        int[] D = new int[arr.length];
        int maxSubArray = 0;


        D[0] = arr[0];
        if (arr[0] > 0) maxSubArray = arr[0];
        for (int i = 1; i < arr.length; i++) {
            int a = arr[i];
            if (a > 0) maxSubArray += a;
            D[i] = D[i - 1] + a > a ? D[i - 1] + a : a;
        }

        int max = D[0];
        for (int i = 1; i < arr.length; i++) {
            if (D[i] > max) max = D[i];
        }

        ans[0] = max;
        ans[1] = maxSubArray == 0 ? max : maxSubArray;

        return ans;
    }


    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] arr = new int[n];

            String[] arrItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                int arrItem = Integer.parseInt(arrItems[i]);
                arr[i] = arrItem;
            }

            int[] result = maxSubarray(arr);

            for (int i = 0; i < result.length; i++) {
                bufferedWriter.write(String.valueOf(result[i]));

                if (i != result.length - 1) {
                    bufferedWriter.write(" ");
                }
            }

            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
