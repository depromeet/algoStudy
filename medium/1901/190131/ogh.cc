#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> g(n + 1);

    for(int i = 0;i < edges.size();i++) {
        int v1 = edges[i][0];
        int v2 = edges[i][1];
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    vector<pair<int, int>> ret;
    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));
    bool chk[1010] = {0};
    chk[s] = true;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int cx = p.first;
        int dist = p.second;
        for(int i = 0 ;i < g[cx].size();i++) {
            int nx = g[cx][i];
            if (!chk[nx]) {
                chk[nx] = true;
                q.push(make_pair(nx, dist + 1));
                ret.push_back(make_pair(nx, dist + 1));
            }
        }
    }

    for (int i = 1;i <= n;i++) {
        if (!chk[i]) {
            ret.push_back(make_pair(i, -1));
        }
    }
    sort(ret.begin(), ret.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.first < b.first;
    });
    vector<int> _ret;
    for(int i = 0 ;i < ret.size();i++) {
        if (ret[i].second == -1) _ret.push_back(-1);
        else _ret.push_back(ret[i].second * 6);
    }
    return _ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
