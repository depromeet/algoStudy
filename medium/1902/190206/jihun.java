static int lilysHomework(int[] arr) {
    int[] arr2 = Arrays.copyOf(arr, arr.length);
    int[] sortedArr = Arrays.copyOf(arr, arr.length);

    Arrays.sort(sortedArr);

    int answerA = 0, answerB = 0;
    int target;

    for (int i = 0; i < arr.length; i++) {
        if (sortedArr[i] != arr[i]) {
            for (target = i + 1; target < arr.length && arr[target] != sortedArr[i]; target++) ;
            swap(arr, i, target);
            answerA++;
        }
    }

    for (int i = 0; i < arr2.length; i++) {
        if (sortedArr[arr2.length - i - 1] != arr2[i]) {
            for (target = i + 1; target < arr2.length && arr2[target] != sortedArr[arr2.length - i - 1]; target++) ;
            swap(arr2, i, target);
            answerB++;
            if (answerB == answerA) return answerA;
        }
    }

    return answerB;
}

static int lilysHomeworkWithSelectionSort(int[] arr) {
    int [] arr2 = Arrays.copyOf(arr, arr.length);
    int min, minI, max, maxI;
    int minAnswer = 0, maxAnswer = 0;

    for (int i = 0; i < arr.length - 1; i++) {
        minI = i;
        min = arr[i];
        for (int j = i + 1; j < arr.length; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minI = j;
            }
        }

        if (i != minI) {
            swap(arr, i, minI);
            minAnswer++;
        }
    }

    for (int i = 0; i < arr2.length - 1; i++) {
        maxI = i;
        max = arr2[i];
        for (int j = i + 1; j < arr.length; j++) {
            if (arr2[j] > max) {
                max = arr2[j];
                maxI = j;
            }
        }

        if (i != maxI) {
            swap(arr2, i, maxI);
            maxAnswer++;

            if (minAnswer == maxAnswer) return minAnswer;
        }
    }

    return maxAnswer;
}

static void swap(int[] arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
