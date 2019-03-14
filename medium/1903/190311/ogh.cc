#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the fairCut function below.
 */
long long fairCut(int k, vector<int> arr) {
    /*
     * Write your code here.
     */
    sort(arr.begin(), arr.end(), greater<int>());
    vector<vector<int>> v(arr.size(), vector<int>(k + 1, 0));
    int numLi = 0;
    int maxLu = arr.size() - k;
    int numLu = 0;
    long long cost = 0;
    for(int i = 0 ;i < arr.size();i++) {
        long long if_Li = 3010;
        // Li (k) 에 속하느냐 
        if (numLi != k) {
            if_Li = (maxLu - 2 * numLu);
        }
        // Lu 에 속하느냐
        long long if_Lu = 3010;
        if (numLu != maxLu) {
            if_Lu = (k - 2 * numLi);
        }
        if (if_Li < if_Lu) {
            cost += if_Li * arr[i];
            numLi++;
        } else {
            cost += if_Lu * arr[i];
            numLu++;
        }
    }
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int arr_itr = 0; arr_itr < n; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    long long result = fairCut(k, arr);
    cout << result << endl;

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

