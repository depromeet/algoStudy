#include <bits/stdc++.h>

using namespace std;

// Complete the counterGame function below.
string counterGame(long n) {
    int cnt = 0;
    while (n != 1) {
        cnt++;
        cout << log(n)/log(2) << endl;
        if (abs((double)n - pow((long long)2, (int)(log(n)/log(2)))) < 1e-9)  n /= 2;
        else {
            int nn = log (n) / log(2);
            n -= pow(2, nn);
        }
    }
    if (cnt == 0) return "Richard";
    if (cnt % 2 == 1) return "Louise";
    return "Richard";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);
        cout << result << endl;

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
