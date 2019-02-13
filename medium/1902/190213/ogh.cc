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
void dfs(
    int current, int prev, vector<int> v[], vector<int> &par,
    vector<bool> &stacked, vector<set<int>> &gp,
    int k, int& gtrue, int &passed)
{
    stacked[current] = true;
    int temp = gtrue;
    // 원래 par[currnet] = prev; 였고
    // 지긍은 par[prev] = current;, par[current] = -1;
    if (gp[current].find(prev) != gp[current].end()) {
        // 원래 그래프가 정상 그래프 였으면
        gtrue--;
    } 
    if (gp[prev].find(current) != gp[prev].end()) {
        // 새로 생긴 그래프가 정상 그래프면
        gtrue++;
    }

    if (gtrue >= k) passed++;
    for(int i = 0 ;i < v[current].size();i++) {
        int next = v[current][i];
        if (stacked[next] == false) {
            dfs(next, current, v, par, stacked, gp, k, gtrue, passed);
        }
    }
    gtrue = temp;
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
    int passed = 0;
    int gtrue = 0;
    for(int i = 0 ;i < guesses.size();i++) {
        int u = guesses[i][0];
        int v = guesses[i][1];
        gp[v].insert(u);
        if (par[v] == u) {
            gtrue++;
        }
    }
    if (gtrue >= k) {
        passed++;
    }
    vector<bool> stacked(n + 100, false);
    stacked[1] = true;
    for(int j = 1 ;j <= n;j++) {
        for (int i = 0; i < v[j].size(); i++) {
            if (stacked[v[j][i]] == false) {
                dfs(v[j][i], 1, v, par, stacked, gp, k, gtrue, passed);
            }
        }
    }
    int prev_root = 1;
    int g = gcd (passed, n);
    stringstream ss;
    ss << passed/g << "/" << n/g;
    cout << passed/g << "/" << n/g << endl;
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
