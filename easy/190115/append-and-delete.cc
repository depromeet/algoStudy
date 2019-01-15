#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int i;
    for(i = 0;i < s.size() && i < t.size();i++) {
        if (s[i] != t[i]) break;
    }

    // minimum operations
    int gap = s.size() - i;// 삭제
    gap += t.size() - i; // 추가

    k -= gap;
    if (k < 0) return "No"; 

    if (i == 0) {
        return (k >= 0)? "Yes": "No";
    } else {
        if (k % 2 == 0) return "Yes";
        else if (k >= i * 2) return "Yes";
        else return "No";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
