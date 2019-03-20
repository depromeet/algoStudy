#include <bits/stdc++.h>

using namespace std;

// Complete the shortPalindrome function below.

long long mod = 1e9 + 7;
vector<long long> scount[32];
vector<long long> rev_scount[32];
vector<long long> last_index[32];
vector<long long> rev_sum[32][32];

long long shortPalindrome(string s) {
    if (s.size() < 4) return 0;
    for(int i= 0 ;i < 32;i++) {
        scount[i].resize(s.size() + 1, 0);
        rev_scount[i].resize(s.size() + 1, 0);
        last_index[i].resize(s.size(), -1);
        for(int j= 0 ;j < 32;j++) {
            rev_sum[i][j].resize(s.size(), 0);
        }
    }
    scount[s[0]-'a'][0] = 1;
    rev_scount[s[s.size()-1]-'a'][s.size()-1] = 1;
    for(int i = 1 ;i < s.size();i++) {
        int ridx = s.size() - 1 - i;
        for(int j = 0 ;j < 'z' -'a';j++) {
            scount[j][i] = scount[j][i-1];
            rev_scount[j][ridx] = rev_scount[j][ridx + 1];
            last_index[j][ridx] = last_index[j][ridx + 1];
        }
        scount[s[i]-'a'][i]++;
        rev_scount[s[ridx]-'a'][ridx]++;
        last_index[s[ridx]-'a'][ridx] = ridx;
    }
    for(int i = s.size() - 2;i >= 0;i--) {
        for(int j = 0 ;j < 32;j++) {
            for(int k = 0 ;k < 32;k++) {
                rev_sum[j][k][i] = rev_sum[j][k][i+1];
                if (j == (s[i] - 'a'))
                {
                    rev_sum[j][k][i] += rev_scount[k][i+1];
                    rev_sum[j][k][i] %= mod;
                }
            }
        }
    }
    long long sum = 0;
    for(int i = 1;i < s.size() - 2;i++) {
        int ridx = last_index[s[i]-'a'][i+1];
        if (ridx != -1) {
            for (int j = 0; j < 32; j++)
            {
                sum += ((scount[j][i - 1] * rev_sum[s[i]-'a'][j][ridx]) % mod);
                sum %= mod;
            }
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long long result = shortPalindrome(s);

cout << result << endl;
    fout << result << "\n";

    fout.close();

    return 0;
}
