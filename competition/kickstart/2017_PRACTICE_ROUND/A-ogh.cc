#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void get_input(T& input) {
    string temp;
    getline(cin, temp);
    stringstream(temp) >> input;
}
int main(void){
    int t;
    get_input(t);
    for(int tt = 0 ;tt < t;tt++) {
        int n;
        get_input(n);
        cout << "Case #" << tt + 1 << ": ";
        vector<string> v;
        int mlen = 0;
        for(int i =0 ;i < n;i++) {
            string s;
            bool chk[32] {false};
            getline(cin, s);
            int cnt = 0;
            for(int j = 0 ;j < s.size();j++) {
                if (s[j] != ' ' && chk[s[j] - 'A'] == false) {
                    chk[s[j] - 'A'] = true;
                    cnt++;
                }
            }
            if (cnt > mlen) {
                mlen = cnt;
                v.resize(0);
                v.push_back(s);
            } else if (cnt == mlen) {
                v.push_back(s);
            }
        }
        sort(v.begin(), v.end());
        cout << v[0] << endl;
    }
    return 0;
}