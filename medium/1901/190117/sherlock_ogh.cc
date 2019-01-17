#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int arr[128] = {0};

    for(int i = 0 ;i < s.size();i++) {
        arr[s[i] - 'a']++;
    }
    vector<int> v;
    set<int> ss;
    for(int i = 0 ;i < 128;i++) {
        if (arr[i] != 0) {
            v.push_back(arr[i]);
            ss.insert(arr[i]);
        }
    }
    
    if (ss.size() > 2) {
        return "NO";
    }
    if (ss.size() == 1) {
        return "YES";
    }
    sort(v.begin(), v.end());
    int i = 1;
    while(i < v.size() && v[i] == v[i-1]) i++;
    int j = i + 1;
    while(j < v.size()) j++;
    if ((j - i) == 1) {
        if (v[i] - v[0] == 1) {
            return "YES";
        } else {
            return "NO";
        }
    } 
    if (i == 1 && v[0] == 1) {
        return "YES";
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
