import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Solution {

    // Complete the superReducedString function below.
    static String superReducedString(String s) {
        List<Character> res = new ArrayList<>();

        char pre;
        for (int i = 0; i < s.length(); i++) {
            if (res.size() != 0 && s.charAt(i) == res.get(res.size() - 1))
                res.remove(res.size() - 1);
            else
                res.add(s.charAt(i));
        }

        if (res.size() == 0) return "Empty String";
        char[] result = new char[res.size()];
        for (int i = 0; i < res.size(); i++)
            result[i] = res.get(i);
        return new String(result);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        String result = superReducedString(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
