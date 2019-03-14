#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

using Long = unsigned long long;
 
struct XLong {
    static Long const F=100000000ULL;
    vector<Long> d;
    XLong()=default;
    XLong(vector<Long>&& i): d{move(i)} {}
    XLong(Long i): d{i} {}
 
    //make all array elements in range of 8 digits
    void inRange() {
        Long rem=0;
        for (Long& dp: d) {
            dp += rem;
            rem = dp/F;
            dp %= F;
        }
        while(d.back()==0)
            d.pop_back();
    }
    //plus
    XLong operator + (XLong const& r) const {
        size_t m= 1 + max(d.size(), r.d.size());
        XLong ret{vector<Long>(m, 0)};
        for(size_t i=0; i<d.size(); i++)
            ret.d[i] = d[i];
        for(size_t i=0; i<r.d.size(); i++)
            ret.d[i] += r.d[i];
        ret.inRange();
        return ret;
    }
    //multiply
    XLong operator * (XLong const& r) const {
        size_t m= 1 + 2*max(d.size(), r.d.size());
        XLong ret{vector<Long>(m, 0ULL)};
        for (size_t i=0; i<d.size(); i++) {
            for (size_t j=0; j<r.d.size(); j++) {
                int p=i+j;
                Long dp=d[i]*r.d[j];
                ret.d[p] += dp%F;
                ret.d[p+1] += dp/F;
            }
        }
        ret.inRange();
        return ret;
    }
    //output
    void print(ostream &stream) {
        char temp[1048576 / 2] {0};
        inRange();
        for (int i=d.size()-1; i>=0; i--) {
            if (i==d.size()-1)
                sprintf(temp + strlen(temp), "%lld", d[i]);
            else
                sprintf(temp + strlen(temp), "%08lld", d[i]);
        }
        stream << temp;
    }
};

XLong fibonacciModified(int t1, int t2, int n) {
    XLong fib[22];
    fib[1] = XLong((Long)t1);
    fib[2] = XLong((Long)t2);
    for(int i= 3;i <= n ;i++) {
        fib[i] = fib[i-2] + fib[i-1] * fib[i-1];
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

    XLong result = fibonacciModified(t1, t2, n);
    
    result.print(fout);
    result.print(cout);

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