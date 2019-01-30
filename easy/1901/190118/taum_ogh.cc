#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the taumBday function below.
long long taumBday(long long b, long long w, long long bc, long long wc, long long z) {
    if (bc < wc) {
        if (bc + z <= wc) {
            return b * bc + w * (bc + z);
        } else {
            return b * bc + w * wc;
        }
    } else if (bc == wc) {
        return b * bc + w * wc;
    } else {
        if (wc + z <= bc) {
            return w * wc + b * (wc + z);
        } else {
            return b * bc + w * wc;
        }
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string bw_temp;
        getline(cin, bw_temp);

        vector<string> bw = split_string(bw_temp);

        int b = stoi(bw[0]);

        int w = stoi(bw[1]);

        string bcWcz_temp;
        getline(cin, bcWcz_temp);

        vector<string> bcWcz = split_string(bcWcz_temp);

        int bc = stoi(bcWcz[0]);

        int wc = stoi(bcWcz[1]);

        int z = stoi(bcWcz[2]);

        long long result = taumBday(b, w, bc, wc, z);

        fout << result << "\n";
    }

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
