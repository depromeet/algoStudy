#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the beautifulPath function below.
vector<int> cost[1010];

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    return cost[a.first][a.second] > cost[b.first][b.second];
}
vector<int> graph[1010][1010];
int beautifulPath(vector<vector<int>> edges, int A, int B) {
    for(int i = 0;i < edges.size();i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        int c = edges[i][2];
        graph[a][b].push_back(c);
        graph[b][a].push_back(c);
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, function<bool(pair<int,int>, pair<int,int>)>> pq(cmp);
    for(int i = 0;i < 1010;i++) {
        if (graph[A][i].size() != 0) {
            for(int j = 0;j < graph[A][i].size();j++) {
                cost[i].push_back(graph[A][i][j]);
                pq.push(make_pair(i,j));
            }
        }
    }
    while(!pq.empty()) {
        pair<int,int> node = pq.top();
        pq.pop();
        int num = node.first;
        int seq = node.second;
        if (num == B) break;
        for(int i = 0;i < 1010;i++) {
            // 가는 간선이 있다. 
            if (graph[num][i].size() != 0 ) {
                for(int j = 0;j < graph[num][i].size();j++) {
                    int penalty = (cost[num][seq] | graph[num][i][j]);
                    if (find(cost[i].begin(), cost[i].end(), penalty) == cost[i].end()) {
                        cost[i].push_back(penalty);
                        pq.push(make_pair(i, cost[i].size() - 1));
                    }
                }
            }
        }
    }
    if (cost[B].size() == 0) return -1;
    sort(cost[B].begin(), cost[B].end());
    return cost[B][0];
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

    string AB_temp;
    getline(cin, AB_temp);

    vector<string> AB = split_string(AB_temp);

    int A = stoi(AB[0]);

    int B = stoi(AB[1]);

    int result = beautifulPath(edges, A, B);

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
