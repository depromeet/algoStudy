#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'clique' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */
double atMostEdges(long long n, long long r) {
    double ret = (n * n - (n % r) * ceil((double)n / r) * ceil((double)n/r));
    ret -= (r - (n % r)) * floor((double)n / r) * floor((double)n / r);
    ret /= 2.0;
    return ret;
}

int turanBinarySearch(int n, int m) {
    int rmin = 1;
    int rmax = n;
    int median = 1;
    while ( rmin <= rmax) {
        median = (rmin + rmax) / 2;
        double me = atMostEdges(n, median);
        // printf("rmin: %d, rmax: %d, median: %d, m: %d, me: %lf\n",
        //        rmin, rmax, median, m, me);
        if (m - me > 1e-9)
        {
            rmin = median + 1;
        }
        else
        {
            rmax = median - 1;
        }
    }
    return rmin;
}

int clique(int n, int m) {
    if (n == 2) return 2;
    if (m == 1) return 2;
    if (m == 2) return 2;
    return turanBinarySearch(n, m);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = clique(n, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}