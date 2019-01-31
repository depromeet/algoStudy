#include <bits/stdc++.h>

using namespace std;

// Complete the palindromeIndex function below.
int isPalindrome(string s) {
    for(int i = 0 ; i < s.size()/2;i++) {
        if (s[i] != s[s.size()-1-i]) {
            return i;
        }
    }
    return -1;
}
int palindromeIndex(string s) {
    int ret = isPalindrome(s);
    if (ret != -1) {
        int idx = isPalindrome(s.substr(0,ret) + s.substr(ret+1, s.size()-1-ret));
        if (idx != -1) {
            idx= isPalindrome(s.substr(0, s.size()-1-ret) + s.substr(s.size()-ret, ret));
            if (idx != -1) ret = -1;
            else ret = s.size()-1-ret;
        } 
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
