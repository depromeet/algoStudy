#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.
vector<int> group;
vector<int> v[101010];
bool chk[101010] = {0};

int bfs(int root) {
    queue<int> q;
    q.push(root);
    chk[root] = true;

    int groupCount = 0;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        groupCount++;
        for(int i = 0 ;i < v[current].size();i++){
            if (chk[v[current][i]] == false) {
                chk[v[current][i]] =  true;
                q.push(v[current][i]);
            }
        }
    }
    return groupCount;
}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    for(int i = 0 ;i < astronaut.size();i++) {
        int first = astronaut[i][0];
        int second = astronaut[i][1];
        v[first].push_back(second);
        v[second].push_back(first);
    }
    for(int i = 0 ;i < n;i++) {
        if (chk[i] == false) {
            group.push_back(bfs(i));
        }
    }

    long long dap = 0;
    vector<long long > sum;
    sum.push_back(group[0]);
    for(int i = 1 ;i < group.size();i++) {
        sum.push_back(sum[i-1] + group[i]);
    }
    for(int i = 0 ;i < group.size();i++) {
        dap += group[i] * (sum[group.size()-1] - sum[i]);
    }
    return dap;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = journeyToMoon(n, astronaut);

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
