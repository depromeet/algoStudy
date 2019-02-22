#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    bool digit = false;
    bool lower = false;
    bool upper = false;
    bool special = false;
    string s = "!@#$%^&*()-+";
    for(int i = 0 ;i < n;i++) {
        if (password[i] >= 'a' && password[i] <= 'z') lower = true;
        if (password[i] >= 'A' && password[i] <= 'Z') upper = true;
        if (password[i] >= '0' && password[i] <='9') digit = true;
        if (s.find(password[i]) != string::npos) special = true;
    }
    int ret = 0;
    if (!digit) ret ++;
    if (!lower) ret ++;
    if (!upper) ret ++;
    if (!special) ret ++;
    if (ret + n < 6) ret = 6 - n;
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
