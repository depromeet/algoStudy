import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the aOrB function below.
     */
    static void aOrB(int k, String a, String b, String c) {
        int count = 0;
        StringBuilder[] answer = {new StringBuilder(), new StringBuilder()};

        int ia = a.length() - 1, ib = b.length() - 1, ic = c.length() - 1;

        while (ia >= 0 || ib >= 0 || ic >= 0) {
            int aa = (ia == -1) ? 0 : Character.digit(a.charAt(ia--), 16);
            int bb = (ib == -1) ? 0 : Character.digit(b.charAt(ib--), 16);
            int cc = (ic == -1) ? 0 : Character.digit(c.charAt(ic--), 16);

            for (int i = 1; i <= 8; i*=2) {
                if ((cc & i) == 0)  {
                    if ((aa & i) > 0) {
                        aa &= ~i;
                        count++;
                    }
                    if ((bb & i) > 0) {
                        bb &= ~i;
                        count++;
                    }
                }

                else {
                    if ((aa & i) == 0 && (bb & i) == 0) {
                        bb |= i;
                        count++;
                    }
                }
            }

            answer[0].insert(0, Character.toUpperCase(Character.forDigit(aa, 16)));
            answer[1].insert(0, Character.toUpperCase(Character.forDigit(bb, 16)));

            if (count > k) {
                System.out.println("-1");
                return;
            }
        }

        while (answer[0].charAt(0) == '0' && answer[1].charAt(0) == '0') {
            answer[0].deleteCharAt(0);
            answer[1].deleteCharAt(0);
        }


        int idx = 0;
        while (count < k && idx < answer[0].length()) {
            int aa = Character.digit(answer[0].charAt(idx), 16);
            int bb = Character.digit(answer[1].charAt(idx++), 16);
            boolean isAChanged = false;
            boolean isBChanged = false;

            if (aa == 0 && bb == 0) continue;

            for (int i = 8; i >= 1; i /= 2) {
                if ((aa & i) > 0) {
                    if ((bb & i) > 0) {
                        aa &= ~i;
                        count++;
                        isAChanged = true;
                    }
                    else {
                        if (k - count > 1) {
                            bb |= i;
                            aa &= ~i;
                            count += 2;
                            isAChanged = true;
                            isBChanged = true;
                        }
                    }
                }

                if (count >= k) break;
            }

            if (isAChanged)
                answer[0].setCharAt(idx - 1, Character.toUpperCase(Character.forDigit(aa, 16)));
            if (isBChanged)
                answer[1].setCharAt(idx - 1, Character.toUpperCase(Character.forDigit(bb, 16)));
        }

        String answerA = answer[0].toString().replaceFirst("0*", "");
        String answerB = answer[1].toString().replaceFirst("0*", "");

        if (answerA.equals(""))
            System.out.println(0);
        else
            System.out.println(answerA);

        if (answerB.equals(""))
            System.out.println(0);
        else
            System.out.println(answerB);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int q = Integer.parseInt(scanner.nextLine().trim());

        for (int qItr = 0; qItr < q; qItr++) {
            int k = Integer.parseInt(scanner.nextLine().trim());

            String a = scanner.nextLine();

            String b = scanner.nextLine();

            String c = scanner.nextLine();

            aOrB(k, a, b, c);
        }
    }
}
