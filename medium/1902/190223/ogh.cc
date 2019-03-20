// https://www.hackerrank.com/challenges/strplay/problem

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the playWithWords function below.
 */
struct Palin {
    int begin;
    int end;
    int length;
    Palin(int _b, int _e, int _l): begin(_b), end(_e), length(_l){}
}
int max_length[3001][3001];
vector<vector<Palin>> v;
int max_product(const string &s, int left_pivot, int right_pivot) {
    if (!v[left_pivot].empty()) {

    } else if (!v[right_pivot].empty()) {

    } else {

    }
}

int playWithWords(string s) {
    /*
     * Write your code here.
     */
    v.resize(s.size());
    for(int i = 0;i < s.size();i++) {
        // 홀수 길이 palindrome 
        for(int j = i + 1;j < s.size();j++) {
            max_product(s,i,j);
        }
    }
    sort(pal.begin(), pal.end(), greater<int>());
    return pal[0] * pal[1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = playWithWords(s);
    cout << result << endl;

    fout << result << "\n";

    fout.close();

    return 0;
}
