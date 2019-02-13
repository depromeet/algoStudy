#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the storyOfATree function below.
 */
int gcd(int a, int b) {
    while(b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
void bfs(int begin, const vector<int> v[], vector<int>& par) {
    // 처음 한바퀴 돌려서 1 기준 트리 생성
    queue<int> q;
    q.push(begin);
    par[begin] = -1;
    while(!q.empty()) {
        int c = q.front();
        q.pop();
        for(int i = 0;i < v[c].size();i++) {
            int nxt = v[c][i];
            if (par[nxt] == 0) {
                par[nxt] = c;
                q.push(nxt);
            }
        }
    }
}
string storyOfATree(int n, vector<vector<int>> edges, int k, vector<vector<int>> guesses) {
    /*
     * Write your code here.
     */
    vector<int> v[n + 1];
    for(int i = 0 ;i < edges.size();i++){
        int a = edges[i][0];
        int b = edges[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> par(n + 100, 0);

    for(int i = 1;i <= n;i++) {
        if (par[i] == 0) {
            bfs(i, v, par);
        }
    }
    vector<set<int>> gp(n + 100);
    int correct = 0;
    int gtrue= 0;
    for(int i = 0 ;i < guesses.size();i++) {
        int u = guesses[i][0];
        int v = guesses[i][1];
        gp[v].insert(u);
        if (par[v] == u) {
            gtrue++;
        }
    }
    if (gtrue >= k) {
        correct++;
    }
    for(int i = 2; i <= n;i++) {
        if (gp[i].end() != gp[i].find(par[i])) {
            // 원래 추측이 맞았던 경우
            gtrue--;
        }
        par[i] = -1;
        vector<bool> chk(n + 100, false);
        chk[i] = true;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int c = q.front();
            q.pop();
            if (gp[c].find(par[c]) != gp[c].end()) {
                // 새로 생긴 추측이 맞는 경우
                gtrue++;
            }
            for(int j = 0;j < v[c].size();j++) {
                int nxt = v[c][j];
                if (chk[nxt] == false && par[nxt] != c) {
                    if (gp[nxt].find(par[nxt]) != gp[nxt].end()) {
                        // 원래 추측이 맞는 상태 였을 경우
                        gtrue--;
                    }
                    par[nxt] = c;
                    q.push(nxt);
                }
                chk[nxt] = true;
            }
        }
        if (gtrue >= k) {
            correct++;
        }
    }
    int g = gcd (correct, n);
    stringstream ss;
    ss << correct/g << "/" << n/g;
    cout << correct/g << "/" << n/g << endl;
    return ss.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> edges(n-1);
        for (int edges_row_itr = 0; edges_row_itr < n-1; edges_row_itr++) {
            edges[edges_row_itr].resize(2);

            for (int edges_column_itr = 0; edges_column_itr < 2; edges_column_itr++) {
                cin >> edges[edges_row_itr][edges_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string gk_temp;
        getline(cin, gk_temp);

        vector<string> gk = split_string(gk_temp);

        int g = stoi(gk[0]);

        int k = stoi(gk[1]);

        vector<vector<int>> guesses(g);
        for (int guesses_row_itr = 0; guesses_row_itr < g; guesses_row_itr++) {
            guesses[guesses_row_itr].resize(2);

            for (int guesses_column_itr = 0; guesses_column_itr < 2; guesses_column_itr++) {
                cin >> guesses[guesses_row_itr][guesses_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = storyOfATree(n, edges, k, guesses);

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
