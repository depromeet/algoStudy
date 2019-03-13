#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the fibonacciModified function below.
// 느려서 n = 20 통과 못함 
class BigInt {
    string s;

public:
    BigInt():s("") {}
    BigInt(string ss) : s (ss) {};
    BigInt (int n)  {
        stringstream ss;
        ss << n;
        ss >> s;
    }
  BigInt operator+(const BigInt &b) const
  {
      int prev = 0;
      int i = s.size() - 1;
      int j = b.size() - 1;
      string ret = "";
      for (;i >= 0 && j >= 0; i--, j--)
      {
          int temp = s[i] - '0' + b[j] - '0' + prev;
          ret += (temp % 10) + '0';
          prev = temp / 10;
      }
      for(; i >= 0; i--) {
          int temp = s[i] - '0' + prev;
          ret += (temp % 10) + '0';
          prev = temp / 10;
      }
      for(; j >= 0; j--) {
          int temp = b[j] - '0' + prev;
          ret += (temp % 10) + '0';
          prev = temp / 10;
      }
      while(prev) {
          ret += (prev % 10) + '0';
          prev /= 10;
      }
      reverse(ret.begin(), ret.end());
      return BigInt(ret);
  }
  BigInt operator*(const BigInt &b) const
  {
      BigInt ret;
      BigInt cache[10];
      for (int i = b.size() - 1; i >= 0; i--)
      {
          int prev = 0;
          string result = "";
          if (cache[b[i] - '0'].size() == 0) {
              for (int j = s.size() - 1; j >= 0; j--)
              {
                  int temp = (s[j] - '0') * (b[i] - '0') + prev;
                  result += (temp % 10) + '0';
                  prev = temp / 10;
              }
              while (prev)
              {
                  result += (prev % 10) + '0';
                  prev /= 10;
              }
              reverse(result.begin(), result.end());
              cache[b[i] - '0'] = result;
          } else {
              result = cache[b[i] - '0'].to_string();
          }
          result += string(b.size() - 1 - i, '0');
          ret = ret + BigInt(result);
      }
      return ret;
  }
  void operator=(const BigInt &b) {
      s = b.s;
  }
  void operator=(const int &n){
      stringstream ss;
      ss << n;
      ss >> s;
  }
  int operator[](int idx) const
  {
      return s[idx];
  }

  int size() const
  {
      return s.size();
  }
  friend ostream& operator<<(ostream &stream, const BigInt &v) {
      stream << v.s;
      return stream;
  }
  string to_string() const {
      return s;
  }
};

cpp_int fibonacciModified(int t1, int t2, int n) {
    cpp_int fib[22];
    fib[1] = t1;
    fib[2] = t2;
    for(int i= 3;i <= n ;i++) {
        fib[i] = fib[i-2] + fib[i-1] * fib[i-1];
        cout << i << " size : " << fib[i].size() << endl;
    }
    return fib[n];
}

int main()
{

  ofstream fout(getenv("OUTPUT_PATH"));

    string t1T2n_temp;
    getline(cin, t1T2n_temp);

    vector<string> t1T2n = split_string(t1T2n_temp);

    int t1 = stoi(t1T2n[0]);

    int t2 = stoi(t1T2n[1]);

    int n = stoi(t1T2n[2]);

    cpp_int result = fibonacciModified(t1, t2, n);
    
    cout << result << endl;
    fout << result << endl;

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
