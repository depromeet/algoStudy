#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the beautifulQuadruples function below.
 */
     int leftSum[3010][5000] = {0};
long long beautifulQuadruples(int a, int b, int c, int d) {
    /*
     * Write your code here.
     */
     long long ret = 0;
  vector<int> v;
  v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d);
  sort(v.begin(), v.end());
  for(int i = 1; i <= v[0];i++) {
    for(int j = i;j <= v[1];j++) {
      leftSum[j][(i^j)] ++;
    }
  }
  for(int i = 1;i <= 3000; i++) {
    for(int j = 0;j < 4949;j++) {
      leftSum[i][j] += leftSum[i-1][j];
    }
  }

  for (int i = 1; i <= v[2];i++) {
    for(int j = 0; j <= 4949; j++) {
      int last = (i^j); // 마지막 값은 자동 결정됨.
      if (last > v[3] || last < i) {
        // 마지막 원소가 범위안에 없을 경우 
        // j를 만들 수 없음 => 
        // 모든 경우를 다 더할 수 있다. 
        ret += (v[3] - i + 1) * leftSum[i][j];
      } else {
        // 마지막 원소가 범위안에 있을 경우
        // j를 만들 수 있는 1가지 경우가 있다. 
        // 그 외에는 다 j 가 안됨. 
        ret += (v[3] - i) * leftSum[i][j];
      }
    }
  }

  return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string abcd_temp;
    getline(cin, abcd_temp);

    vector<string> abcd = split_string(abcd_temp);

    int a = stoi(abcd[0]);

    int b = stoi(abcd[1]);

    int c = stoi(abcd[2]);

    int d = stoi(abcd[3]);

    long long result = beautifulQuadruples(a, b, c, d);

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
