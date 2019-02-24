import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the minimumNumber function below.
    static int minimumNumber(int n, String password) {
        String numbers = "0123456789";
        String lower_case = "abcdefghijklmnopqrstuvwxyz";
        String upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String special_characters = "!@#$%^&*()-+";

        int checks = 0;
        int idx = 0;

        while (checks != 15 && idx < password.length()) {
            String s = Character.toString(password.charAt(idx));
            if (numbers.contains(s))
                checks |= 1;
            else if (lower_case.contains(s))
                checks |= 2;
            else if (upper_case.contains(s))
                checks |= 4;
            else if (special_characters.contains(s))
                checks |= 8;
            idx++;
        }

        int count = 0;
        for (int i = 1; i <= 8; i *= 2) {
            if ((checks & i) > 0) count++;
        }

        return 6 - n > (4 - count) ? 6 - n : 4 - count;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String password = scanner.nextLine();

        int answer = minimumNumber(n, password);

        bufferedWriter.write(String.valueOf(answer));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
