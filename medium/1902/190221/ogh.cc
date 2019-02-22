#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the whatsNext function below.
 */
void whatsNext(vector<long long> arr) {
    /*
     * Write your code here.
     */
    vector<long long> ret;
    if (arr.size() == 1) {
        ret.resize(3);
        ret[0] = 1;
        ret[1] = 1;
        ret[2] = arr[0] - 1;
    } else if (arr.size() == 2) {
        ret.resize(3);
        ret[0] = 1;
        ret[1] = arr[1] + 1;
        ret[2] = arr[0] - 1;
    } else if (arr.size() % 2 == 1) {
        for(int i= 0 ;i < arr.size() - 2; i++) {
            ret.push_back(arr[i]);
        }
        int len = arr.size();
        long long zero = arr[len-2] -1;
        
        if (zero == 0) {
            ret[ret.size()-1]+=1;
            ret.push_back(1);
            ret.push_back(arr[len-1] - 1);
        } else {
            ret.push_back(zero);
            ret.push_back(1);
            ret.push_back(1);
            ret.push_back(arr[len-1] - 1);
        }
    } else if (arr.size() % 2 == 0) {
        for(int i= 0 ;i < arr.size() - 3; i++) {
            ret.push_back(arr[i]);
        }
        int len = arr.size();
        long long zero = arr[len-3] - 1;
        if (zero == 0) {
            ret[ret.size() - 1] += 1;
        } else {
            ret.push_back(zero);
            ret.push_back(1);
        }
        ret.push_back(arr[len-1] + 1);
        ret.push_back(arr[len - 2] -1);
    }
    int len = ret.size();
    if (ret[ret.size() -1 ] == 0)  len--;
    cout << len << endl;
    for(int i= 0;i < len;i++) {
        if (i) cout << " " ;
        cout << ret[i] ;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int arr_count;
        cin >> arr_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<long long> arr(arr_count);

        for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
            long long arr_item = stoll(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        whatsNext(arr);
    }

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
