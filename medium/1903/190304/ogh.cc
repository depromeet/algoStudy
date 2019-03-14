#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the cost function below.
int cost(vector<int> b) {
    int sum[100010][2]; // 1이거나 max 이거나 
    memset(sum, 0, sizeof(sum));

    for(int i = 1 ;i < b.size();i++) {
        sum[i][0] = max(sum[i-1][0], sum[i-1][1] + b[i-1] - 1);
        sum[i][1] = max(sum[i-1][0] + b[i] - 1, sum[i-1][1] + abs(b[i] - b[i-1]));
    }
    return max(sum[b.size()-1][0], sum[b.size()-1][1]);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string B_temp_temp;
        getline(cin, B_temp_temp);

        vector<string> B_temp = split_string(B_temp_temp);

        vector<int> B(n);

        for (int i = 0; i < n; i++) {
            int B_item = stoi(B_temp[i]);

            B[i] = B_item;
        }

        int result = cost(B);
        cout << result << endl;

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
