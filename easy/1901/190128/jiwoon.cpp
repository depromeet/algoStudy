#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    // count alphabets in string
    int alphabet[26] = {0,};
    for (int i = 0, n = s.length(); i < n; i++) {
        // count uppercases
        if (s[i] >= 65 && s[i] <= 90) {
            alphabet[s[i] - 65] += 1;
        }
        // count lowercases
        else if (s[i] >= 97 && s[i] <= 122) {
            alphabet[s[i] - 97] += 1;
        }
    }
    // check if pangrams or not
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == 0) return "not pangram";
    }
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
