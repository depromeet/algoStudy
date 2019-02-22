
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the serviceLane function below.
vector<int> serviceLane(int n, vector<vector<int>> cases, vector<int> width) {
    vector<int> ret;
    for(int i = 0;i < cases.size();i++) {
        int st = cases[i][0];
        int ed = cases[i][1];
        int mx = 4;
        for(int i = st; i <= ed;i++) {
            mx = min(mx, width[i]);
        }
        ret.push_back(mx);
    }


    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nt_temp;
    getline(cin, nt_temp);

    vector<string> nt = split_string(nt_temp);

    int n = stoi(nt[0]);

    int t = stoi(nt[1]);

    string width_temp_temp;
    getline(cin, width_temp_temp);

    vector<string> width_temp = split_string(width_temp_temp);

    vector<int> width(n);

    for (int i = 0; i < n; i++) {
        int width_item = stoi(width_temp[i]);

        width[i] = width_item;
    }

    vector<vector<int>> cases(t);
    for (int i = 0; i < t; i++) {
        cases[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> cases[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = serviceLane(n, cases, width);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
