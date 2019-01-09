#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    int i;
    for (i = 0;;i++) {
        long double sum = pow((long double)2, i + 1) - 1;
        sum *= 3;
        if (sum >= t) break;
    }
    t -= (long) ((pow((long double)2, i) - 1) * 3);
    t = (long) (pow((long double)2 , i) * 3 - t);
    return t + 1;
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