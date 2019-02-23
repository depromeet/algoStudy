
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the substringDiff function below.
#define point pair<int, int>
#define mp make_pair
int substringDiff(int k_cost, string s1, string s2) {
    if (s1.size() > s2.size()) {
        swap(s1, s2);
    }
    bool is_cs[s1.size() + 1][s2.size() + 1] {};
    bool chk[s1.size() + 1][s2.size() + 1] {};
    vector<vector<point>> v; // cs 리스트 
    vector<point> vstart; // cs 스타팅 포인트 
    // 일단 lcs 찾음
    for(int i = 0 ;i < s1.size();i++) {
        for(int j = 0; j < s2.size();j++) {
            if (chk[i][j] == false) {
                vector<point> temp;
                int begin = -1;
                int k = 0;
                for( ; i + k < s1.size() && j + k <s2.size();k++) {
                    int ci = k + i;
                    int cj = k + j;
                    chk[ci][cj] = true;
                    if (s1[ci] == s2[cj]) {
                        is_cs[ci + 1][cj + 1] = true;
                        if (is_cs[ci][cj] == false) {
                            // cs 시작점 이면
                            begin = k;
                        }
                    } else if (is_cs[ci][cj]) {
                        // cs 끝점
                        temp.push_back(mp(begin, k-1));
                    }
                }
                if (begin != -1 &&
                    (temp.empty() || temp[temp.size() - 1].first != begin)) {
                    temp.push_back(mp(begin, k - 1));
                }
                vstart.push_back(mp(i,j));
                v.push_back(temp);
            } else {
                // n^2 맞추기 위한 최적화
                break;
            }
        }
    }
    int ret = 0;
    for(int i = 0 ;i < v.size();i++) {
        int gap[v[i].size() + 1] {};
        int start = 0;
        if (!v[i].empty()) {
            int len = v[i][0].second - v[i][0].first + 1;
            len += k_cost;
            len = min (len, (int)s1.size() - vstart[i].first);
            ret = max(ret, len);
        }
        for(int j = 1 ;j < v[i].size();j++) {
            // cs 두개 사이의 거리 재고 
            gap[j] = gap[j-1] + v[i][j].first - v[i][j-1].second - 1;
            int cost = gap[j] - gap[start];
            while (start < j && cost > k_cost) {
                cost -= (gap[start + 1] - gap[start]);
                start++;
            }
            // 현재 cs까지의 총 길이 + k를 계산 함. 
            long unsigned len = v[i][j].second - v[i][start].first + 1;
            len += (k_cost - cost);
            len = min(s1.size() - vstart[i].first, len);
            ret = max((long unsigned)ret, len);
        }
    }

    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string kS1S2_temp;
        getline(cin, kS1S2_temp);

        vector<string> kS1S2 = split_string(kS1S2_temp);

        int k = stoi(kS1S2[0]);

        string s1 = kS1S2[1];

        string s2 = kS1S2[2];

        int result = substringDiff(k, s1, s2);

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
