// N log N
// PriorityQueue는 nlog n이다.

import java.util.*;


public class Solution {

    // Complete the cutTheSticks function below.

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int numSticks = sc.nextInt();
        Queue<Integer> sticks = new PriorityQueue<>(numSticks);
        Queue<Integer> tmpSticks = new PriorityQueue<>();
        for (int i = 0; i < numSticks; i++) {
            int stick = sc.nextInt();
            sticks.add(stick);
        }
        while (sticks.peek() != null) {
            System.out.println(sticks.size());

            for(Integer stick : sticks) {
                int cut = stick - sticks.peek();
                if (cut > 0)
                    tmpSticks.add(cut);

            }

            sticks.clear();
            sticks.addAll(tmpSticks);
            tmpSticks.clear();
        }
    }
}
