static int jumpingOnClouds(int[] c) {
    int count = 0;
    int answer = 0;
    for (int i = 0; i < c.length - 1; i++) {
        if (c[i + 1] == 1) {
            answer += (count + 1) / 2;
            count = 0;
            answer++;
            i++;
        }

        else {
            count++;
        }
    }
    answer += (count + 1) / 2;

    return answer;
}
