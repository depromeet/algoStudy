#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the superDigit function below.
int superDigit(string n) {
    if (n.size() == 1) return n[0] - '0';
    int sum = 0;
    for (int i = 0; i < n.size(); i++)
    {
        sum += (n[i] - '0');
    }
    return superDigit(to_string(sum));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string temp;
    int k;
    long long sum = 0;
    cin >> temp;
    cin >> k;
    for(int i = 0 ;i < temp.size();i++ ) {
        sum += temp[i] - '0';
    }
    int result = superDigit(to_string(sum * k));

    fout << result << "\n";

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
