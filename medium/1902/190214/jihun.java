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

class Result {

    /*
     * Complete the 'gamingArray' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static String gamingArray(List<Integer> arr) {
        int answer = 0;

        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < arr.size(); i++)
            map.put(arr.get(i), i);

        Collections.sort(arr);

        int idx = arr.size() - 1;

        int sortedI = arr.size() - 1;
        while (sortedI >= 0 && idx >= 0) {
            int maxI = map.get(arr.get(sortedI));
            if (maxI <= idx) {
                idx = maxI;
                answer = (answer + 1) % 2;

                if (idx == 0) break;
            }
            sortedI--;
        }

        if (answer == 0) return "ANDY";
        else return "BOB";

    }
//    public static String gamingArray(List<Integer> arr) {
//        int answer = 0;
//        int idx = arr.size() - 1;
//
//        while (idx >= 0) {
//            int max = 0, maxI = -1;
//
//            for (int i = 0; i <= idx; i++) {
//                if (arr.get(i) > max) {
//                    max = arr.get(i);
//                    maxI = i;
//                }
//            }
//
//            idx = maxI - 1;
//
//            answer = (answer + 1) % 2;
//        }
//
//        if (answer == 0) return "ANDY";
//        else return "BOB";
//    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int g = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, g).forEach(gItr -> {
            try {
                int arrCount = Integer.parseInt(bufferedReader.readLine().trim());

                List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList());

                String result = Result.gamingArray(arr);

                bufferedWriter.write(result);
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
