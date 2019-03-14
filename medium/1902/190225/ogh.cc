#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr(3010, vector<int>(3010, -1));

// i 부터 j 까지 최장 길이 palindrome 계산 
int get_max_pal_len(int x, int y, string &s) {
    if(arr[x][y] != -1) return arr[x][y];
    if (x > y) return 0;
    if (x == y) {
        arr[x][y] = 1;
        return arr[x][y];
    }
    if (s[x] == s[y]) {
        arr[x][y] = 2 + get_max_pal_len(x + 1, y - 1, s);
    } else {
        arr[x][y] = get_max_pal_len(x + 1, y, s);
        arr[x][y] = max(arr[x][y], get_max_pal_len(x, y - 1, s));
    }
    return arr[x][y];
}

int playWithWords(string s) {
    for(int i = 0 ;i < s.size();i++) {
        for(int j = i ;j < s.size();j++) {
            if (arr[i][j] == -1) get_max_pal_len(i,j,s);
        }
    }
    int dap = 0;
    // 안겹치는 구간의 곱 계산 
    for(int i = 0 ;i < s.size();i++) {
        for(int j = i;j < s.size();j++) {
            dap = max(dap, arr[i][j] * arr[j + 1][s.size()-1]);
        }
    }
    cout << dap << endl;
    return dap;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = playWithWords(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
