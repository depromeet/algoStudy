#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    /*
     * Write your code here.
     */
    // 짝수면 한쪽으로 끝나고, 홀 수면 양쪽으로 끝난다.
    int dap = p / 2;
    int reverseDap = (n - p) / 2;
    if (n % 2 == 0 && p %2 == 1) reverseDap++;
    if (dap > reverseDap) return reverseDap;
    return dap;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

cout << result << endl;
    fout << result << "\n";

    fout.close();

    return 0;
}
