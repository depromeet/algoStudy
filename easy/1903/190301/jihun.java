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

    // Complete the alternate function below.
    static int alternate(String s) {
        Set<Character> set = new HashSet<>();

        for (Character c : s.toCharArray())
            set.add(c);

        int ans = 0;
        Character[] cList = set.toArray(new Character[set.size()]);
        for (int i = 0; i < cList.length; i++) {
            for (int j = i + 1; j < cList.length; j++) {
                for (int k = 0; k < 2; k++) {
                    char a, b;
                    if (k == 0) {
                        a = cList[i];
                        b = cList[j];
                    }
                    else {
                        a = cList[j];
                        b = cList[i];
                    }
                    char tmp;
                    int idx = 0;
                    int len = 0;

                    while (idx < s.length()) {
                        if (s.charAt(idx) == a) {
                            len++;
                            tmp = a;
                            a = b;
                            b = tmp;
                        } else if (s.charAt(idx) == b) break;

                        idx++;
                    }
                    if (idx == s.length() && len > ans) ans = len;
                }
            }
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int l = Integer.parseInt(bufferedReader.readLine().trim());

        String s = bufferedReader.readLine();

        int result = alternate(s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
