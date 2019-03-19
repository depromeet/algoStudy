import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the fairCut function below.
     */
    static int fairCut(int k, int[] arr) {
        int n = arr.length;

        if (n - k < k) k = n - k;
        Arrays.sort(arr);

        int[] a1 = new int[k];
        int[] a2 = new int[n - k];
        int idx1 = 0, idx2 = 0;

        for (int i = 0; i < k - 1; i++) {
            a2[idx2++] = arr[i];
        }

        for (int i = k - 1; i < n; i++) {
            if (i % 2 == 1) a1[idx1++] = arr[i];
            else a2[idx2++] = arr[i];
        }

        int sum = 0;
        int diff;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n - k; j++) {
                diff = a2[j] - a1[i];
                if (diff < 0) diff *= -1;
                sum = diff;
            }
        }

        return sum;

        // k = 3
        // 2 3 2 4 19 29 28 39 18 32

        // 2 2 3 4 18 19 28 29 32 39

        // 2 2 3 o 18 o 28 o 32 39

        // 2 2 o 4 o 19 o 29 32 39
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0].trim());

        int k = Integer.parseInt(nk[1].trim());

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");

        for (int arrItr = 0; arrItr < n; arrItr++) {
            int arrItem = Integer.parseInt(arrItems[arrItr].trim());
            arr[arrItr] = arrItem;
        }

        int result = fairCut(k, arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
