#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    // initialize init_num for cycles and count
    long init_num = 3;
    long count = init_num + 1;

    // loop until seconds in equals given time t
    for (long i = 1; i <= t; i++) {
        // decrement
        count--;
        // if end of a cycle,
        if (count == 0) {
            // update initial number for new cycle
            init_num = init_num * 2;
            // reset count to new initial number
            count = init_num;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
