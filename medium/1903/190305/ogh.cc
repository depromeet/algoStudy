#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the equal function below.
int equal(vector<int> v) {
  sort(v.begin(), v.end());
  int dap = 0x7fffffff;
  for(int t = 0; t < 3;t++) {
      vector<int> arr = v;
      arr[0] -= t;
      int sum = 0;
      int dx[3]{5, 2, 1};
      for (int i = 1; i < arr.size(); i++)
      {
          arr[i] -= arr[0];
          for (int j = 0; j < 3; j++)
          {
              sum += arr[i] / dx[j];
              arr[i] %= dx[j];
          }
      }
      dap = min(dap, sum + (t ? 1 : 0));
  }
  return dap;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
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

    int result = equal(arr);
    cout << result << endl;

    fout << result << "\n";
  }

  fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

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

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
