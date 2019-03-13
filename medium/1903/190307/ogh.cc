#include <bits/stdc++.h>

using namespace std;

// Complete the substrings function below.
int substrings(string n) {
    long long sum = 0;
    long long mod = 1e9 + 7;
    long long multiply = 1;
    for(int i = 0;i < n.size();i++) {
        int idx = n.size() - 1 - i;
        long long temp = n[idx] - '0';
        temp *= multiply;
        temp %= mod;
        temp *= (n.size() - i) % mod;
        temp %= mod;
        sum = (sum + temp) % mod;
        multiply = multiply * 10 + 1;
        multiply %= mod;
    }
    return (int) sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

cout << result<< endl;;
    fout << result << "\n";

    fout.close();

    return 0;
}
