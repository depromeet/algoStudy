#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the prims function below.
struct Cost{
    int node;
    int cost;
    Cost(int _node, int _cost) : node(_node), cost(_cost) {}
};

bool cmp(const Cost& a, const Cost& b) {
    return a.cost > b.cost;
}
vector<Cost> e[3010];
bool chk[3010];

int prims(int n, vector<vector<int>> edges, int start) {
    for(int i = 0 ;i < edges.size();i++) {
        e[edges[i][0]].push_back(Cost(edges[i][1], edges[i][2]));
        e[edges[i][1]].push_back(Cost(edges[i][0], edges[i][2]));
    }

    memset(chk,0,sizeof(chk));

    priority_queue<Cost, vector<Cost>, function<bool(Cost, Cost)>> pq(cmp);
    pq.push(Cost(start, 0));
    int cnt = 0;
    int ret = 0;

    while(cnt != n) {
        Cost c = pq.top();
        pq.pop();
        int idx = c.node;
        int cost = c.cost;
        if (!chk[idx]) {
            chk[idx] = true;
            ret += cost;
            printf("to %d is %d\n", idx, cost);
            cnt++;
            for (int i = 0; i < e[idx].size(); i++) {
                pq.push(Cost(e[idx][i].node, e[idx][i].cost));
            }
        }
    }

    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

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
