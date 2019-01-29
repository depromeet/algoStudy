#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    vector<int> sorted(arr);
    sort(sorted.begin(), sorted.end());
    vector<int> v;
    for(int i = 0 ;i < arr.size();i++) {
        if (arr[i] != sorted[i]) {
            v.push_back(i);
        }
    }
    if (v.size() == 0) {
        printf("yes\n");
    } else if (v.size() == 2) {
        printf("yes\n");
        printf("swap %d %d\n", v[0] + 1, v[1] + 1);
    } else {
        int premax = 0;
        int promin = 1000001;
        vector<pair<int, int>> vsub;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                if (i != 0)
                    premax = arr[i - 1];
                int end = i + 1;
                while (end < arr.size() - 1 && arr[end] > arr[end + 1])
                    end++;
                vsub.push_back(make_pair(i, end));
                i = end;
                promin = arr[end + 1];
            }
        }
        if (vsub.size() > 1) {
            printf("no\n");
        } else {
            int begin = vsub[0].first;
            int end = vsub[0].second;
            if (arr[end] >= premax && arr[begin] <= promin) {
                printf("yes\n");
                printf("reverse %d %d\n", begin + 1, end + 1);
            } else {
                printf("no\n");
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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
