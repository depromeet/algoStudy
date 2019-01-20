#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    // iterate over all the numbers in the range from p to q (inclusively)
    bool k = false;
    for (long long i = p; i <= q; i++) {
        // split the squared number into left and right substrings
        int d1 = to_string(i).length();
        string str = to_string(i * i);
        int d2 = str.length();
        string left_str = ((d2 - d1) > 0)? str.substr(0, d2- d1): "0";
        string right_str = str.substr(d2 - d1, d1);
        // check if kaprekar Number and print if so
        int sum = stoi(left_str) + stoi(right_str);
        if (sum == i) {
            k = true;
            cout << i << " ";
        }
    }
    if (k == false) cout << "INVALID RANGE";
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
